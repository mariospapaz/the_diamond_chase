#include "./engine.h"
#include "./malph.h"
#include "./poter.h"
#include "./diamond.h"

Engine::Engine(const std::string& file_path): map_w(0), map_h(0), moves(0), d_will_mvin(0), game(true)
{   
    load_map(file_path);
    window = newwin(map_h, map_w, map_h/3, map_w - map_w/3 - 12);
    setup_credits();
    generate_map();
    d_will_mvin = rand() % map_w + map_h + 1;
    wrefresh(window);
}

Engine::~Engine()
{
    wborder(window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    werase(window);
    delwin(window);
    werase(credits_window);
    delwin(credits_window);
}

void Engine::generate_map()
{   
    for(int row = 0; row < map_data.size(); row++)
        for(int col = 0; col < map_data[row].length(); col++)
            ( map_data[row][col] == '*' ) ?  add_text(row, col, "█") : add_text(row, col, ".");
}

void Engine::setup_credits()
{   
    std::string credits = "@Μάριος Παπάζογλου ice21390179";
    std::string desc = "Πώς να παίξεις το παιχνίδι:\n - Μετακινήσου με τα βελάκια (← ↑ ↓ →)\n - Έξοδος με ESC\n - Ακινησία με SPACE";

    credits_window = newwin(7, credits.length() + 8, getmaxy(stdscr) - 8, getmaxx(stdscr)/2 - (credits.length() + 8)/3);
    mvwaddstr(credits_window, 1, 1, credits.c_str());
    mvwaddstr(credits_window, 2, 1, desc.c_str());
    
    wborder(credits_window, '|','|','-','-','+', '+', '+','+');
    wrefresh(credits_window);
}

void Engine::load_map(const std::string& path)
{  
    map_file.open(path);

    if(map_file.is_open())
    {
        std::string line;
        
        std::getline(map_file, line);
        map_data.push_back(line);
        map_w = line.length();

        while(std::getline(map_file, line))
        {
            map_data.push_back(line);

            if(map_w != line.length())
            {
                endwin();
                std::cout << "Η γραμμή " << map_h << " είναι λάθος. Παρακαλώ διορθώστε το." << std::endl;
                exit(1);
            }        
        }

        map_h = map_data.size();
        map_file.close();
    }
    else 
    {
        endwin();
        std::cout << "Αποτυχία φόρτωσης του χάρτη." << std::endl;
        exit(1);
    }
}

void Engine::add_text(int y, int x, const char* txt){ mvwaddstr(window, y, x, txt); }

void Engine::update()
{
    srand (time(NULL));

    std::unique_ptr<Poter> M(new Poter(map_data, window, map_h, map_w));
    std::unique_ptr<Malph> L(new Malph(map_data, window, map_h, map_w));
    std::unique_ptr<Diamond> G(new Diamond(map_data, window, map_h, map_w));
    L->make_path(G->get_y(), G->get_x());

    int ch; 
    while(((ch = getch()) != 27))
    {   
        switch (ch)
        {
          case KEY_UP: case KEY_DOWN: case KEY_LEFT: case KEY_RIGHT: case ' ':
            moves++;
            M->update(ch);
        
            L->update(G->get_y(), G->get_x());

            G->update();
            
            if(d_will_mvin == moves)
            {
                G.reset(new Diamond(map_data, window, map_h, map_w));
                d_will_mvin = rand() % (map_w + map_h + moves/2);
                moves = 0;
                L->make_path(G->get_y(), G->get_x());
            }

            if (M->get_x() == G->get_x() && M->get_y() == G->get_y() )
            {
                winner = "Νίκησε ο Μπάμπης!";
                game = false; 
            }

            if (L->get_x() == G->get_x() && L->get_y() == G->get_y() )
            {
                winner = "Νίκησε ο Λουκάς!";
                game = false; 
            }           
            break;
        }

        if(game == false)
            break;
    }

    // Τέλος παιχνιδιού
    wclear(window);
    box(window, 0, 0);
    if(winner != "")
    {
        add_text(getmaxy(window)/2 - 1, getmaxx(window)/2 - winner.length()/3 + 1, winner.c_str());
    }
    else 
    {
        // Τυχόν ο χρήστης κλείσει το πρόγραμμα και δεν υπάρχει νικητής.
        add_text(getmaxy(window)/2 - 1, getmaxx(window)/2 - 8, "Καλή συνέχεια!");
    }
    wrefresh(window);
    getch();
}

#include "./engine.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    if(argc != 2)
    {   
        std::cout << "Λάθος χρήση προγράμματος" << std::endl;

        if(argc == 1)
        {   
            std::cout << "Πρέπει να δώσετε το αρχείο του χάρτι." << std::endl;
        }

        return -1;
    }

    initscr();
    raw();	
    keypad(stdscr, true);
    curs_set(0);
    noecho();
    refresh();
    start_color();

    
    if(has_colors() == FALSE)
    {          
        endwin();
        std::cout << "Το τερματικό σας δεν υποστηρίζει χρώματα." << std::endl;
        exit(1);
    }
    use_default_colors();

    // Χρώματα
    init_pair(1, COLOR_YELLOW, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_CYAN, -1);
    init_pair(4, COLOR_MAGENTA, -1);

    Engine game(argv[1]);
    game.update();
    endwin();
    return 0;
}
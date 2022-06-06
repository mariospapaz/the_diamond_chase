#include "./malph.h"

Malph::Malph(std::vector<std::string> map, WINDOW* win, int my, int mx):
    Moving(map, win, GREEN_OUTFIT, "L", my, mx){}

Malph::~Malph(){}


void Malph::make_path(const int& dy, const int& dx)
{
    path.clear();

    for(int row = 0; row < map.size(); row++)
    {
        /*
            0: Πάνω
            1: Κάτω
            2: Αριστερά
            3: Δεξιά
        */

        path.push_back(std::vector<int>());
        for(int col = 0; col < map[0].length(); col++)
        {
            if(col > dx)
            {
                path[row].push_back(2);
            }
            else if (col == dx) {
                if(row > dy)
                {
                    path[row].push_back(0);
                }
                else
                {
                    path[row].push_back(1);
                }
            }
            else if (col < dx) {
                path[row].push_back(3);
            }
        }
    }
}

void Malph::movement() 
{
    
    switch(path[y][x])
    {
        case 0:
            move_up();
            break;

        case 1:
            move_down();
            break;
        case 2:
            move_left();
            break;

        case 3:
            move_right();
            break;
    }

    if(check_right() == false)
        move_down();
    
    if(check_left() == false)
        move_up();

    if(check_up() == false)
        move_left();

    if(check_down() == false)
        move_right();
}

void Malph::update()
{  
   movement();
   redraw_entity();
}

#include "./malph.h"
#include <curses.h>

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
            if(map[row][col] == '*')
                continue;

            if(row > dy) {
                path[row].push_back(0);
            } else if (row == dy) {
                if(col > dx) {
                    path[row].push_back(2);
                } else {
                    path[row].push_back(3);
                }
            } else if (row < dy) {
                path[row].push_back(1);
            }
        }
    }
}

void Malph::movement(const int& dy, const int& dx) 
{
    if(check_right() == false){
        (dy <= y) ? move_down() : move_up();
    } else if (check_left() == false){
        (dy <= y) ? move_down() : move_up();
    } else if (check_up() == false) {
        (dx <= x) ? move_left() : move_right();
    } else if (check_down() == false) {
        (dx <= x) ? move_left() : move_right();
    } else {
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
    }
}

void Malph::update(const int& dy, const int& dx)
{  
   movement(dy, dx);
   redraw_entity();

   mvwprintw(win, 1, 1, "(%d, %d)", x, dx);
}

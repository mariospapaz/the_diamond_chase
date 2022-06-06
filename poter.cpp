#include "./poter.h"
#include "./moving.h"

Poter::Poter(std::vector<std::string> map, WINDOW* win, int my, int mx):
    Moving(map, win, ORANGE_OUTFIT, "M", my, mx){}

Poter::~Poter() {}


void Poter::update(int ch) { 
    
    switch(ch)
        {
            case KEY_UP:
                move_up();
                break;

            case KEY_DOWN:
                move_down();
                break;

            case KEY_LEFT:
                move_left();
                break;

            case KEY_RIGHT:
                move_right();
                break;
        }

    redraw_entity(); 

}
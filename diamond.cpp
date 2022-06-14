#include "./diamond.h"

Diamond::Diamond(std::vector<std::string> map, WINDOW* win, int my, int mx):
    Entity(map, win, GEM_COLOR, "💎", my, mx) {}

Diamond::~Diamond() 
{ 
    mvwaddstr(win, y, x, "..");
    wrefresh(win);
}

void Diamond::update() { redraw_entity(); }

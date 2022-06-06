#include "./moving.h"

Moving::Moving(const std::vector<std::string>& map, WINDOW* win, const int& id, const std::string& icon, const int& my, const int& mx)
    :Entity(map, win, id, icon, my, mx) {}
    
Moving::~Moving(){}

bool Moving::footprint() 
{   
    if( (0 < y < map_y) && (0 < x < map_x) )
        mvwaddch(win, y, x, '.');
        return true;
    return false;
}

bool Moving::check_up(){ return map[y - 1][x] != '*'; }

bool Moving::check_down(){ return map[y + 1][x] != '*'; }

bool Moving::check_left(){ return map[y][x - 1] != '*'; }

bool Moving::check_right(){ return map[y][x + 1] != '*'; }

void Moving::move_up(){ (check_up() && footprint()) ? --y : false; }

void Moving::move_down(){ (check_down() && footprint()) ? ++y : false; }

void Moving::move_left(){ (check_left() && footprint()) ? --x : false; }

void Moving::move_right() { (check_right() && footprint()) ? ++x : false; }

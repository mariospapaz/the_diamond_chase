#include "./entities.h"

Entity::Entity(
    const std::vector<std::string>& map_data, 
    WINDOW* e_win,
    const int& e_id, 
    const std::string& e_icon,
    const int& my,
    const int& mx
    ): id(e_id), y(1), x(1), map_y(my), map_x(mx), icon(e_icon), win(e_win), map(map_data)
{
    s_rand_pos();
    redraw_entity();
}


void Entity::redraw_entity()
{
    wattron(win, COLOR_PAIR(id));
    mvwaddstr(win, y, x, icon.c_str());
    wattroff(win, COLOR_PAIR(id));
    wrefresh(win);
}


Entity::~Entity(){}

const int Entity::get_x(){return x;}
const int Entity::get_y(){return y;}

void Entity::s_rand_pos()
{
    int local_x = 0;
    int local_y = 0;
    do {
        local_x = rand() % map_x;
        local_y = rand() % map_y;
        if(  
            (local_x > 3) && (local_x < map_x - 3) &&
            (local_y > 3) && (local_y < map_y - 3) && 
            (map[local_y - 1][local_x - 1] != '*') && (map[local_y - 1][local_x] != '*') && (map[local_y - 1][local_x + 1] != '*') &&
            (map[local_y][local_x - 1] != '*') && (map[local_y][local_x] != '*') && (map[local_y][local_x + 1] != '*') &&
            (map[local_y + 1][local_x - 1] != '*') && (map[local_y + 1][local_x] != '*') && (map[local_y + 1][local_x + 1] != '*')
        )
            break;    
            
    } while (true);

    x = local_x;
    y = local_y;
}
#ifndef MOVING_H
#define MOVING_H
#include "./entities.h"

class Moving: public Entity 
{
    public:

        Moving(const std::vector<std::string>&, WINDOW*, const int&, const std::string&, const int&, const int&);
        
        virtual ~Moving();

        bool check_up(); 
        
        bool check_down(); 

        bool check_left();

        bool check_right();
        
        bool footprint();

        void move_up();
        
        void move_down();
        
        void move_left();

        void move_right();
};

#endif 

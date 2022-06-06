#ifndef DIAMOND_H
#define DIAMOND_H
#include "./entities.h"

class Diamond: public Entity 
{

    public:

        Diamond(std::vector<std::string>, WINDOW*, int, int);

        virtual ~Diamond();
        
        void update();

};

#endif
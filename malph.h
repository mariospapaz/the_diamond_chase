#ifndef MALPH_H
#define MALPH_H
#include "./moving.h"
#include "./entities.h"

class Malph: public Moving
{   
    private:
        std::vector< std::vector<int> > path;

    public:

        Malph(std::vector<std::string>, WINDOW*, int, int);

        virtual ~Malph();

        void update();

        void make_path(const int&, const int&);

        void movement();

};

#endif

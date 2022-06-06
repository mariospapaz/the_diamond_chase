#ifndef POTER_H
#define POTER_H
#include "./moving.h"


class Poter: public Moving
{
    public:
        Poter(std::vector<std::string>, WINDOW*, int, int);

        virtual ~Poter();

        void update(int);

};

#endif
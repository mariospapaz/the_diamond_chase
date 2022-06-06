#ifndef ENTITIES_H 
#define ENTITIES_H
    #include "./engine.h"
    #define ORANGE_OUTFIT 1
    #define GREEN_OUTFIT 2
    #define GEM_COLOR 3
    #define WALL_COLOR 4 
    class Entity
    {
        protected:
            std::vector<std::string> map;
            WINDOW* win;   
            int id;
            int y;
            int x;
            std::string icon;
            int map_y;
            int map_x;

        public:

            Entity(const std::vector<std::string>&, WINDOW*, const int&, const std::string&, const int&, const int&);

            virtual ~Entity();

            void redraw_entity();

            const int get_x();
            const int get_y();

            void s_rand_pos();
            
    };
#endif
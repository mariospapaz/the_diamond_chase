#ifndef ENGINE_H
#define ENGINE_H
    #include <ncurses.h>
    #include <iostream>
    #include <cstring>
    #include <string>
    #include <fstream>
    #include <vector>
    #include <stdlib.h>
    #include <memory>
    #include <time.h>
    #include <queue>

    class Engine 
    {
        private:
            WINDOW* window;
            WINDOW* credits_window;

            int map_h;
            int map_w;

            std::ifstream map_file;
            std::vector<std::string> map_data;

            std::string winner;

            int moves;
            int d_will_mvin;

            bool game;

        public:

            // Constructor
            Engine(const std::string&);

            // Destructor
            ~Engine();

            void generate_map();

            void load_map(const std::string&);

            void setup_credits();

            void add_text(int, int, const char*);   

            void update();
    };

#endif
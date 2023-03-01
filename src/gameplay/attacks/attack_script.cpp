


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    ofstream compile("attacks.cpp");

    // tells people their dumbasses for reading this file
    compile << "// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE\n";
    
    // places all of the includes al the start of the file (and yes you can just dogpile them all)
    compile << "#include \"attack.h\"\n";
    compile << "#include \"../../features/collide.h\"\n";
    compile << "#include <memory>\n";
    compile << "#include <iostream>\n";
    compile << "#include <chrono>\n";
    compile << "using std::unique_ptr;\n";
    compile << "using namespace std::chrono;\n";
    
    int o;
    string hand;

    // compiling the attack declarations
    ifstream script_images("script/images");
    string line;
    while(getline(script_images, line)) {
        
        // for declaring new attacks
        if (!line.find("new_attack")) {
            hand = "";
            compile << "unique_ptr<ATTACK>";
            for (int i = 0; line[i + 11]; i++) {
                o = i + 11;
                hand.push_back(line[i + 11]);
            }
            compile << hand;
            compile << "(new ATTACK());\n";
        }
    }

    script_images.close();
    
    // adds boilerplate
    compile << "static int delay=time(NULL);\n";
    compile << "static int64_t delay_millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();";
    compile << "static bool attack_init=true;\n";
    compile << "void attacks(SDL_Renderer *renderer, SDL_Window* window,int heart_x, int heart_y, int heart_width, int heart_height, int turn_cycle, bool & scout_turn,int & HEART_HP) {\n";

    compile << "if (attack_init) {\n";

    // compiles the image attacks
    ifstream script_init("script/init");
    
    while (getline(script_init, line)) {

        // for the image path the images made in images will do the images
        if (!line.find("declare_attack")) {
            for (int i = 0; line[i + 15] != ','; i++) {
                compile << line[i + 15];
                o = i;
            }
            o += 17;
            compile << "->init(renderer, ASSETPATH\"";
            
            for (int i = 1; line[i + o]; i++)
                compile << line[i + o];

            compile << "\");\n";
            line = "";
        }

        if (!line.find("init_x")) {
            hand = "";
            o = 6;
            for (int i = 0; line[i + 6] != ','; i++) {
                hand.push_back(line[i + 6]);
                o++;
            }
            o++;
            compile << hand << "->x = ";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }   

        if (!line.find("init_y")) {
            hand = "";
            o = 6;
            for (int i = 0; line[i + 6] != ','; i++) {
                hand.push_back(line[i + 6]);
                o++;
            }
            o++;
            compile << hand << "->y = ";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }

        if (!line.find("init_width")) {
            hand = "";
            o = 10;
            for (int i = 0; line[i + 10] != ','; i++) {
                hand.push_back(line[i + 10]);
                o++;
            }
            o++;
            compile << hand << "->width = ";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }

        if (!line.find("init_height")) {
            hand = "";
            o = 11;
            for (int i = 0; line[i + 11] != ','; i++) {
                hand.push_back(line[i + 11]);
                o++;
            }
            o++;
            compile << hand << "->height =";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }
    }

    script_init.close();


    compile << "attack_init = false;}\n";
    compile << "switch (turn_cycle) {\n";

    ifstream script_attack("script/attacks");

    while (getline(script_attack, line)) {

        if (!line.find("attack")) {
            compile << "case ";
            for (int i = 6; line[i]; i++)
                compile << line[i];
            compile << ":\n";
            compile << "if (scout_turn) {\n";
            line = "";
        }

        if (!line.find("end_attack")) {
            compile << "}\nbreak;\n";
            line = "";
        }
        
        if (!line.find("draw")) {
            hand = "";
            for (int i = 4; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand;
            compile << "->draw_attack(renderer, window);\n";
            line = "";
        }
        
        if (!line.find("for_second")) {
            compile << "if (time(NULL) - delay >=";
            o = 10;
            for (int i = 10; line[i] != ','; i++) {
                compile << line[i];
                o++;
            }
            o++;
            compile << "&& time(NULL) - delay<=";

            for (int i = o; line[i]; i++)
                compile << line[i];
            
            compile << "){\n";

            line = "";
        }

        if (!line.find("for_millisecond")) {
            compile << "if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - delay_millis >=";
            o = 15;
            for (int i = 15; line[i] != ','; i++) {
                compile << line[i];
                o++;
            }
            o++;
            compile << "&& std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - delay_millis<=";

            for (int i = o; line[i]; i++)
                compile << line[i];
            
            compile << "){\n";

            line = "";
        }

        if (!line.find("damage_heart")) {

            compile << "HEART_HP -=";
            
            for (int i = 12; line[i]; i++)
                compile << line[i];
            
            compile << ";\n";

            line = "";
        }

        if (!line.find("move_right")) {
            o = 11;
            for (int i = 10; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->x +=";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }
        
        if (!line.find("move_left")) {
            o = 10;
            for (int i = 9; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->x -=";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }

        if (!line.find("move_up")) {
            o = 8;
            for (int i = 7; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->y += ";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }
        if (!line.find("move_down")) {
            o = 10;
            for (int i = 9; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->y -= ";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
        }

        if (!line.find("touching_heart")) {
            hand = "";
            for (int i = 14; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << "if (touching(heart_x, heart_y, heart_width, heart_height," << 
                hand << "->x," << hand << "->y," <<
                hand << "->width," << hand << "->height)) {\n";
            line = "";
        }
        
        if (!line.find("not_touching_heart")) {
            hand = "";
            for (int i = 18; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << "if (!touching_heart(heart_x, heart_y," << 
                hand << "->x," << hand << "->y," <<
                hand << "width," << hand << "height)) {\n";
            line = "";
        }

        if (!line.find("end_turn")) {
            compile << "scout_turn = false;\n";
            line = "";
        }

        if (!line.find("end")) {
            compile << "}";
            line = "";
        }
    }
    

    script_attack.close();
    compile << "default:\ndelay=time(NULL); delay_millis=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); \nbreak;\n";

    // finishes
    compile << "}}";
    compile.close();

}


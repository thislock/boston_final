// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE
#include "attack.h"
#include "../../features/collide.h"
#include <memory>
#include <iostream>
#include <chrono>
using std::unique_ptr;
using namespace std::chrono;
unique_ptr<ATTACK>test1(new ATTACK());
unique_ptr<ATTACK>test2(new ATTACK());
unique_ptr<ATTACK>test3(new ATTACK());
unique_ptr<ATTACK>test4(new ATTACK());
unique_ptr<ATTACK>test5(new ATTACK());
static int delay=time(NULL);
static int64_t delay_millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();static bool attack_init=true;
void attacks(SDL_Renderer *renderer, SDL_Window* window,int heart_x, int heart_y, int heart_width, int heart_height, int turn_cycle, bool & scout_turn,int & HEART_HP) {
if (attack_init) {
test1->init(renderer, ASSETPATH"attacks/cleaver.bmp");
test2->init(renderer, ASSETPATH"attacks/cleaver.bmp");
test3->init(renderer, ASSETPATH"attacks/cleaver.bmp");
test4->init(renderer, ASSETPATH"attacks/cleaver.bmp");
test5->init(renderer, ASSETPATH"attacks/cleaver.bmp");
 test1->x =  0;
 test1->y =  -60;
 test1->width =  30;
 test1->height = 30;
 test2->x =  0;
 test2->y =  0;
 test2->width = 100;
 test2->height =100;
 test3->x =  0;
 test3->y =  0;
 test4->x =  0;
 test4->y =  0;
 test5->x =  0;
 test5->y =  0;
attack_init = false;}
switch (turn_cycle) {
case 1:
if (scout_turn) {
 test1->draw_attack(renderer, window);
if (time(NULL) - delay >= 1&& time(NULL) - delay<=4){
 test1->x += 1;
}if (touching(heart_x, heart_y, heart_width, heart_height, test1->x, test1->y, test1->width, test1->height)) {
HEART_HP -= 1;
}}
break;
default:
delay=time(NULL); delay_millis=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); 
break;
}}
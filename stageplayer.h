#include"global.h"
#include"stagetest.h"

void level1(){
int ch;
int exitgame;
int exitscreen = 0;
int exitoptions;


matricemap1();
ch = getch();
    switch(ch){
    case 'w': 
    pcy--;
    break;
    case 'a': 
    pcx--;
    break;
    case 's': 
    pcy++;
    break;
    case 'd': 
    pcx++;
    break;
    case 27: 
    clear();
    refresh();
    drawn_level1 = 1;
    break;
    }
}
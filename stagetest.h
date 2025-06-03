#include"global.h"

void matricemap1(){
clear();
    for(int y = 0; y < Y1; y++){
    for(int x = 0; x < X1; x++){
        if(x == 0 || y == 0 || x == X1 - 1 || y == Y1 - 1){
        mvaddch(y, x, '#');
        }
        else{
        mvaddch(y, x, '.');
        }
    }
    }
mvaddch(pcy, pcx, '&');

mvaddch(5,5,'@');
}
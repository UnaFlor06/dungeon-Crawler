#include"global.h"
#include"stagetest.h"

typedef struct{
int y, x;

}playerpos;

void player(){
playerpos player = {1,1};
int ch;
ch = getch();
    switch (ch){
    case 'w': player.x++ , player.y;
    case 'a': player.x, player.y++;
    case 's': ++player.x, player.y;
    case 'd': player.x, ++player.y;
    case 'W': player.x++ , player.y;
    case 'A': player.x, player.y++;
    case 'S': ++player.x, player.y;
    case 'D': player.x, ++player.y;
}
}
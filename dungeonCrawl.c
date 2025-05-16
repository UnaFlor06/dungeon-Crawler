#include"global.h"
#include"stagetest.h"  
#include"mensagensbobas.h"
#include"menu.h"

//Música tema (placeholder pelo momento)
void play_sound(const char *filename) {
char command[256];
snprintf(command, sizeof(command), "aplay -q \"%s\" &", filename); 
system(command);
}

//int main

int main(){

int selected;
int settingselect;
int newgame;
int loadgame;
int creditscreen;
int ch;
int geralmenu = 1;
int menu = 1;
int musica = 1;

if(musica == 1){
play_sound("placeholder.wav");
}

initscr();        
resizeterm(256, 240); //tamanho da tela do terminal externo (somente tesado no GNOME terminal)
cbreak();           
noecho();          
keypad(stdscr, TRUE); 


while(geralmenu == 1){

//Menu principal
draw_menu(selected);
while (menu == 1){
ch = getch();
    switch (ch){
    case KEY_UP:  
    selected = (selected - 1 + NUM_OPTIONS) % NUM_OPTIONS;
    break;
    case KEY_DOWN:  
    selected = (selected + 1) % NUM_OPTIONS;
    break;
    case 10:  
    clear();
    if(ch == 10 && selected == 0){
        menu = 5;
        break;
        }
        if(ch == 10 && selected == 1){
        menu = 3;
        break;
        }
        else if (ch == 10 && selected == 2){
        menu = 2;
        break;
        }
        else if (ch == 10 && selected == 3){
        menu = 6;
        break;
        }
        else if(ch == 10 && selected == 4){
            menu = 4;
            if(menu == 4){
            system("killall aplay");
            endwin();
            silly();
            exit(0);
            }
        break;
        }
    }
draw_menu(selected);
}

//Credits
draw_credits(creditscreen);
while(menu == 6){
ch = getch();
    switch(ch){
    case 10:
    clear();
        if(ch == 10){
        menu = 1;
        break;
        }
    }

draw_credits(creditscreen);
}



//Settings
draw_settings(settingselect);
while(menu == 2){
ch = getch();
    switch (ch){
    case KEY_UP:  
    settingselect = (settingselect - 1 + NUM_SETTINGS) % NUM_SETTINGS;
    break;
    case KEY_DOWN:  
    settingselect = (settingselect + 1) % NUM_SETTINGS;
    break;
    case 10:  
    clear();
        if(ch == 10 && settingselect == 3){
        menu = 1;
        break;
        }
    }
draw_settings(settingselect);
}

//new game
draw_new(newgame);
while(menu == 5){
ch = getch();
    switch (ch){
    case KEY_UP:  
    newgame = (newgame - 1 + NEW_GAME) % NEW_GAME;
    break;
    case KEY_DOWN:  
    newgame = (newgame + 1) % NEW_GAME;
    break;
    case 10:  
    clear();
        if(ch == 10 && newgame == 1){
        menu = 1;
        break;
        }
        if(ch == 10 && newgame == 0){
        clear();
        refresh;
        map();
        continue;
        }
    }
draw_new(newgame);
}

//load game
draw_load(loadgame);
while(menu == 3){
ch = getch();
    switch (ch){
    case KEY_UP:  
    loadgame = (loadgame - 1 + LOAD_GAME) % LOAD_GAME;
    break;
    case KEY_DOWN:  
    loadgame = (loadgame + 1) % LOAD_GAME;
    break;
    case 10:  
    clear();
        if(ch == 10 && loadgame == 3){
        menu = 1;
        break;
        }
    }
draw_load(loadgame);
}
}
exit(0);
}


#include"global.c"  

#define NUM_OPTIONS 5
#define NEW_GAME 2

int teste; 

const char *options[NUM_OPTIONS] = {
    "New Game", //0
    "Load Game (placeholder)", //1
    "Options", //2
    "Credits", //3
    "Exit", //4
};
#define NEW_GAME 2
    
    const char*new[NEW_GAME] = {
    "Sim", //0
    "Não", //1
};

void draw_menu(int selected) {
    clear();  //somente unix
    printw("===== dungeon Crawl =====\n\n");
    printw("                                                 _________ \n");
    printw("                                                |         |\n");
    printw("                                                |  _____  |\n");
    printw("                                                | |     | |\n");
    printw("                                                | |     | |\n");
    printw("                                                | |_____| |\n");
    printw("                                                |         |\n");
    printw("                                                |   ___   |\n");
    printw("                                                |  |   |  |\n");
    printw("                                                |  |   |  |\n");
    printw("                                                |  |___|  |\n");
    printw("                                                |_________|\n");

    for (int i = 0; i < NUM_OPTIONS; ++i) {
        if (i == selected) {
            attron(A_REVERSE);  
            printw("> %s <\n", options[i]);
            attroff(A_REVERSE);
        } else {
            printw("  %s\n", options[i]);
        }
    }

    refresh();  
}

int main() {
    int selected = 0;
    int ch;

    initscr();          
    cbreak();           
    noecho();          
    keypad(stdscr, TRUE); 

    draw_menu(selected);

    while (1) {
        ch = getch();

        switch (ch) {
            case KEY_UP:  
                selected = (selected - 1 + NUM_OPTIONS) % NUM_OPTIONS;
                break;
            case KEY_DOWN:  
                selected = (selected + 1) % NUM_OPTIONS;
                break;
            case 10:  
                clear();
                printw("Você escolheu: %s\n", options[selected]);
                if (selected == 4) {  
                    printw("Saindo do jogo...\n");
                    break;
                }
                if (selected == 0){
                    printw("Certeza que desejas iniciar um novo erro?\n");
                    refresh();
                    getch();
                    break;

                }
                if (selected != 0){
                printw("Pressione qualquer tecla para voltar ao menu...");
                refresh();
                getch();
                }
        }

        draw_menu(selected);

        if (ch == 10 && selected == 4)  
            break;
    }

    endwin();  

    return 0;
}

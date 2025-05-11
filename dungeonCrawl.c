#include"global.h"
#include"stagetest.h"  

#define NUM_OPTIONS 5
#define NEW_GAME 2

//Música tema (placeholder pelo momento)

void play_sound(const char *filename) {
char command[256];
snprintf(command, sizeof(command), "aplay -q \"%s\" &", filename); 
system(command);
}



const char*options[NUM_OPTIONS] = {
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
    }
else{
    printw("  %s\n", options[i]);
    }
}

refresh();  
}

int main(){
int selected = 1;
int ch;
int menu = 1;
int musica = 1;

if(musica == 1){
play_sound("placeholder.wav"); //Música tema de Metroid, ideia é compor uma trilha original atmosférica futuramente.
}

initscr();        
resizeterm(0, 0);
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
    printw("Você escolheu: %s\n", options[selected]); //Placeholder, fins de debug (mostrar se as constantes para opção estão funcionais).
    if (selected == 4) {  
        printw("Saindo do jogo...\n");
        break;
        }
    if (selected == 0 && ch == 10){
        printw("Certeza que desejas iniciar um novo erro?\n"); //Opção de confirmar escolha do jogador.
        getch();
        break;
        }
    if (selected != 0){
        printw("Pressione qualquer tecla para voltar ao menu..."); //Opção para voltar ao menu após escolha de opções.
        refresh();
        getch();
        break;
        }
    }
draw_menu(selected);

    if (ch == 10 && selected == 4){
    musica = 0;
        if(musica == 0){
        system("killall aplay");
        }
    endwin();
    printf("Alt F4sando...\n"); //Mensagem boba 1, futuramente declara-lás como variáveis para randomizar a mensagem de fechamento.
    exit (0);
    break;
    }
    else if(ch == 10 && selected == 0){
    clear();
    map(); 
    //Desenhar stagetest (ver stagetest.h)
    }
    }

// sempre iguale música a zero para não deixar ela tocar no fundo
musica == 0;
if(musica == 0){
system("killall aplay");
}
return 0;
}

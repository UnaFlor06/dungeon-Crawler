#include"global.h"
#include"stagetest.h"  
#include"mensagensbobas.h"

//Contantes
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

//titlescreen função
void draw_menu(int selected) {
clear();  //somente unix
printw("                                                     .::.                                 .~P5~\n");
printw("                                                  .:~!????7!^.                             7@@!\n");
printw("                                               :^!7???????????7~^.                     .~!~Y@@~           .          ....     ~!!!~    .::.   .:\n");
printw("                                           .^!7???????????????????7~:.                ?B&?B@@@~ ^B#!^BB! .JG5!B#5^ ^Y#YB#B!.~G@J!J@G~.?#P5#?::YBJ7#B?:\n");
printw("                                       .^!7???????????????????????????!~:.            G@# P@@@^ ~@@?~@@7   P@&?B@#.G@# G@@@^J@@?!J@@?^@@7~@@7 .#@B?&@P\n");
printw("                                   .:~7??????????????????????????????????7!^:         Y&&~B@@B7.~@@?~@@7   P@& P@#.7B&?#@@@^7#@5JJJ!.~@@?!@@7 .#@P &@P\n");
printw("                               .:~7????????????77!~^^:::::::^^~!7????????????7!^.      ^????7 7^.!BP5#7J7  Y#G.Y#G.:^^^^Y@@^ :????7. .^P55P~. .P#Y.G#Y\n");
printw("                          .:~!????????????7!^:.                 .:~7????????????7!^.              ...  .\n");
printw("                         :!7?????????????!:.                         .^7?????????????7!:\n");
printw("                        :??????????????~.                               :!????????JY5PGY\n");
printw("                        ^????????????!.                                   :7???JYPPGGGGP.\n");
printw("                        ^???????????^               ..:::::.               ^Y5PGGGGGGGG5.\n");
printw("                        ^??????????:             :~7????????7!^.       :~J5PGGGGGGGGGGG5.                                    ^@@@@7\n");
printw("                        ^?????????:            ^7???????????????!: .~?5GBBBGGGGBGBGGGGG5 .^^^^^^^^:      :^^^^      .^^^^.   ^@@@@7      JPPPPPPPP^   .^^^^. .^^^^\n");
printw("                       ^????????!           .!?????????????????YYYPGGGB&@@@BG&@@@&GGGGP^Y@@##@@@@5      Y@@@&.     ~@@@@!   ^@@@@7   .Y5&@G7??J@@G5! ^B#@@J:Y@@@@!:.\n");
printw("                        ^????????:           !??????????????JY5PGGGGGGGGGB@@@@@@@@@@@GP&@@@B..#@@@5..    Y@@@&. ..  ~@@@@!   ^@@@@7   :&@@@?    &@@@Y   :#@@@&###&@@7\n");
printw("                        ^???????7.          :???????????JY5PGGGGGGGGGGGGPB@@@@BGGGB@&GP&@@@B  #@@@@&B    Y@@@&:.P@J !@@@@!   ^@@@@7   :&@@@GJJJY@@@@Y   .#@@@5 ...B@!\n");
printw("                        ^???????7.          :???????JY5GGGGGGGGGGGGGGGGGPB@@@@BPGGGGGGG&@@@B  #@@@@@#    J@@@@##@@@#&@@@@!   ^@@@@7   :&@@@BYYYYYYY5!   .#@@@Y    ...\n");
printw("                        ^????????.          .7???Y5PGBBBBBBGGGGGGGGGGGGGPB@@@@BPGGGGGGG&@@@B  #@@@@@#.   .:?@@@@@@@@@@&~:.   ^@@@@7   .Y5&@P777777.     .#@@@Y\n");
printw("                        ^????????~           :YGGBBBBBBBBBBBBBBGGGPGGGGGPB@@@@BPGGGGGGGP^Y@@BB@@Y:Y@@BG:   !@@@@?:P@@@&.     .^~&@#B?    JPPPPPPPP^     .#@@@Y\n");
printw("                        ^?????????.           :YBBBBBBBBBBBBBBBBG7.:!J5GGGBBBBGGGGGGGGG5 .~~!!~~. .~~!!.   .~~~~. :~~~~         ^~~!^                    ^^^~:\n");
printw("                        ^?????????7             ^?5GBBBBBBBBBGY!.     .^!J5GGPGGGGGGGGG5.\n");
printw("                        ^?????????YY:              :~!7???7!^.            .^5GGGGGGGGGG5.\n");
printw("                        ^?????J5PGBBG!                                    :JBBGGGGGGGGG5.\n");
printw("                        :JJYPGBBBBBBBB5~                                .7GBBBBBBBGGGGG5\n");
printw("                         7PBBBBBBBBBBBBB57:                           ^JGBBBBBBBBBBBBG5^\n");
printw("                          .^7YPBBBBBBBBBBBGY7^.                   :~?PBBBBBBBBBBBGPJ~:\n");
printw("                              .^7YGBBBBBBBBBBBP5?7~^:......::^!7J5GBBBBBBBBBBBPJ!:\n");
printw("                                  .~?5GBBBBBBBBBBBBBGGGPPPGGGBBBBBBBBBBBBBPY7^.\n");
printw("                                      :~J5GBBBBBBBBBBBBBBBBBBBBBBBBBBBGY7^.\n");
printw("                                          :!JPBBBBBBBBBBBBBBBBBBBBG5?~.\n");
printw("                                            .^7YPBBBBBBBBBBBBG5J~:\n");
printw("                                                .^7YGBBBBBPJ!:\n");
printw("                                                    .~77!^\n");

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
resizeterm(256, 240); //tamanho da tela do terminal externo (somente tesado no GNOME terminal)
cbreak();           
noecho();          
keypad(stdscr, TRUE); 

draw_menu(selected);

//Condicional do menu
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
    silly();
    exit (0);
    break;
    }
    else if(ch == 10 && selected == 0){
    clear();
    map(); //Stagetest
    }
}

// sempre iguale música a zero para não deixar ela tocar no fundo após o término do programa.
musica == 0;
if(musica == 0){
system("killall aplay");
}
return 0;
}

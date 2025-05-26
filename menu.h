#include"global.h"

//Constantes 
const char*options[NUM_OPTIONS] = {
"New Game", //0
"Load Game (placeholder)", //1
"Options", //2
"Credits", //3
"Exit", //4
};
const char*settings[NUM_SETTINGS] = {
"Volume", //0
"Colour", //1
"Keybinds", //2
"Back", //3
};
const char*load[LOAD_GAME] = { 
"Slot 1", //0
"Slot 2", //1
"Slot 3", //2
"Back", //3
};
const char*new[NEW_GAME] = { 
"YES", //0
"NO", //1
};
const char*fin[EXIT_GAME] = { 
"YES", //0
"NO", //1
};


//Função new game
void draw_new(int newgame){
clear(); //somente unix
for (int i = 0; i < NEW_GAME; ++i) {
    if (i == newgame) {
    attron(A_REVERSE);  
    printw("> %s <\n", new[i]);
    attroff(A_REVERSE);
    }
else{
    printw("  %s\n", new[i]);
    }
    refresh;
}
}

//Função load game
void draw_load(int loadgame){
clear(); //somente unix
for (int i = 0; i < LOAD_GAME; ++i) {
    if (i == loadgame) {
    attron(A_REVERSE);  
    printw("> %s <\n", load[i]);
    attroff(A_REVERSE);
    }
else{
    printw("  %s\n", load[i]);
    }
    refresh;
}
}

//Função settings menu
void draw_settings(int settingselect){
clear(); //somente unix
for (int i = 0; i < NUM_SETTINGS; ++i) {
    if (i == settingselect) {
    attron(A_REVERSE);  
    printw("> %s <\n", settings[i]);
    attroff(A_REVERSE);
    }
else{
    printw("  %s\n", settings[i]);
    }
    refresh;
}
}

//Função credits
void draw_credits(int creditscreen){
clear();
printw("Antônio Guilherme Benigno Milhomem\n");
printw("Amanda Kelen Santos Azevedo\n");
printw("\nPress Return/Enter\n");
refresh();
}

//Função exit
void draw_exit(int exitgame){
clear(); //somente unix
for (int i = 0; i < EXIT_GAME; ++i) {
    if (i == exitgame) {
    attron(A_REVERSE);  
    printw("> %s <\n", fin[i]);
    attroff(A_REVERSE);
    }
else{
    printw("  %s\n", fin[i]);
    }
    refresh;
}
}

//Função menu principal
void draw_menu(int selected) {
clear();  //somente unix
printw("                                                     .::.                                 .~P5~\n");
printw("                                                  .:~!????7!^.                             7@@!           JG                                   BJ\n");
printw("                                               :^!7???????????7~^.                     .~!~Y@@~           JG5          ....     ~!!!~    .::.  BJ7\n");
printw("                                           .^!7???????????????????7~:.                ?B&?B@@@~ ^B#!^BB! .JG5!B#5^ ^Y#YB#B!.~G@J!J@G~.?#P5#?::YBJ7#B?:\n");
printw("                                       .^!7???????????????????????????!~:.            G@# P@@@^ ~@@?~@@7   P@& B@#.G@# G@@@^J@@?!J@@?^@@7~@@7 .#@B?&@P\n");
printw("                                   .:~7??????????????????????????????????7!^:         Y&&~B@@B7.~@@?~@@7   P@& P@#.7B&?#@@@^7#@5JJJ!.~@@?!@@7 .#@P &@P\n");
printw("                               .:~7????????????77!~^^:::::::^^~!7????????????7!^.      ^????7 7^.!BP5#7J7  Y#G.Y#G.:^^^^Y@@^ :????7. .^P55P~. .P#Y.G#Y\n");
printw("                          .:~!????????????7!^:.                 .:~7????????????7!^.              ...  .                Y@@¨\n");
printw("                         :!7?????????????!:.                         .^7?????????????7!:                               Y@/\n");
printw("                        :??????????????~.                               :!????????JY5PGY                               Y@\n");
printw("                        ^????????????!.                                   :7???JYPPGGGGP.                             Y@/\n");
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
    refresh();
} 
}

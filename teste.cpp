#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// === IMPLEMENTAÇÃO DE kbhit() ===
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);           // pega config atual
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // desliga modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // aplica nova config
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);   // pega flags atuais do stdin
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // modo não-bloqueante

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // volta configuração original
    fcntl(STDIN_FILENO, F_SETFL, oldf);       // volta flags antigas

    if (ch != EOF) {
        ungetc(ch, stdin);  // devolve caractere pro buffer
        return 1;
    }

    return 0;
}

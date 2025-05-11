dungeon Crawl (com C maísuculo) é um jogo simples em C feito como trabalho de programação no Centro Universitário Do Pará. O foco do trabalho é praticar o conteúudo de programação trabalhado em aula.

//Segundo Commit:
Implementação inicial do menu principal com a biblioteca ncurses. Primeira iteração de um mapa renderizado com matrizes.
"Stagetest" pelo momento segue sem uso, já que seu propósito será, de alguma forma, ser inicializado após o usuário apertar "New Game". Ao apertar esta opção, o objetivo será trazer o usuário a outro menu de seleção (perguntar se ele deseja continuar), após a opção sim ser tomada, a variável new game será alterada e o jogo ou começará ou voltará ao menu.
Impelementação da base de um sistema de links (global.c; dungeonCrawl.c) com o propósito de organizar melhor o código. Futuramente alterar o código para depender de strctures e revizar os códigos feitos com IA (menu principal para revisão futura).


//Terceiro Commit:
Implementação de links com headers (.h), stagetest agora funciona como uma função e pode ser acessado (mas não de modo funcional) através do menu principal. O código do menu principal também foi alterado parcialmente para ter melhor funcionalidade com a funcionalidade "New Game". Esta opção agora funciona de modo verossímil à de "Exit", isso é, tomar essa opção remove o usuário do ciclo de repetição do menu principal, consequentemente, removendo-o da função "draw_menu".
Também foi adicionado um texto bobo na hora de sair do jogo (futuramente pensando em rolar um com uma grande quantidade de números para escolher uma entre várias mensagens bobinhas).

//Quarto commit:
Para o quarto commit, não há mudanças significativas ao código, apenas uma alteração para a capacidade de playback de arquivos .wav e um novo arquivo de texto para servir como splashscreen. A música placeholder é o tema de título do Metroid original de NES, acho que serve para dar direcionamento para a composição musical futura do jogo (sim, pretendo fazer música original pra isso aqui).

dungeon Crawl (com C maísuculo) é um jogo simples em C feito como trabalho de programação no Centro Universitário Do Pará. O foco do trabalho é praticar o conteúudo de programação trabalhado em aula.

//Obs: O jogo foi feito em um computador Linux, utilizando de comandos de sistema e bibliotecas do sistema operacional Linux, não existe planejamento de suporte multiplataforma para sistemas como Windows ou MacOS.
/
O jogo foi desenvolvido com PCs de arquitetura x86 em mente, não garanto compatibilidade com dispositivos de arquitetura ARM (dispositivos com Apple Silicon ou processadores snapdragon).

//Segundo Commit:
Implementação inicial do menu principal com a biblioteca ncurses. Primeira iteração de um mapa renderizado com matrizes.
/
"Stagetest" pelo momento segue sem uso, já que seu propósito será, de alguma forma, ser inicializado após o usuário apertar "New Game". Ao apertar esta opção, o objetivo será trazer o usuário a outro menu de seleção (perguntar se ele deseja continuar), após a opção "sim" ser tomada, a variável new game será alterada e o jogo ou começará ou voltará ao menu.
/
Impelementação da base de um sistema de links (global.c; dungeonCrawl.c) com o propósito de organizar melhor o código. Futuramente alterar o código para depender de strctures e revizar os códigos feitos com IA (menu principal para revisão futura).


//Terceiro Commit:
Implementação de links com headers (.h), stagetest agora funciona como uma função e pode ser acessado (mas não de modo funcional) através do menu principal. O código do menu principal também foi alterado parcialmente para ter melhor funcionalidade com o "New Game". Esta opção agora funciona de modo verossímil à de "Exit", isso é, tomar essa opção remove o usuário do ciclo de repetição do menu principal, consequentemente, removendo-o da função "draw_menu".
/
Também foi adicionado um texto bobo na hora de sair do jogo (futuramente pensando em rolar um dado com uma grande quantidade de números para escolher uma entre várias mensagens bobinhas).

//Quarto commit:
Para o quarto commit, não há mudanças significativas ao código, apenas uma alteração para a capacidade de playback de arquivos .wav e um novo arquivo de texto para servir como splashscreen. A música placeholder é o tema de título do Metroid original de NES, acho que serve para dar direcionamento para a composição musical futura do jogo (sim, pretendo fazer música original pra isso aqui).

//Quinto commit:
Apenas terminei a splashscreen.

//Sexto commit:
Até agora, o commit mais importante. Foram implementados uma nova splashscreen no menu principal, ainda precisa de refinamentos, centralização e talvez um pouo mais de apelo visual. A splashscreen (ou titlescreen, esses termos serão utilizados como sinônimos) depende da incialização do ncurses e é printada junto com a função "drawn_menu" (a mesma das opções do menu principal), diferente das opções do menu ou do stagetest, ela é um simples printw atrelado à uma função, logo não depende de constantes, vetores ou matrizes, portanto para edita-lá basta "desenhar" diretamente no printw.
/
O tamanho do terminal foi resolvido através da função "resizeterm" do ncurses, consequentemente stagetest finalmente é desenhado apropriadamente, entretanto terá que ser reajustado para caber na tela. A decisão final foi de dar o tamanho de 256 linhas por 240 colunas, essa escolha foi feita por ser o que considero ser uma área suficiente para monstrar diversos elementos em tela (principalmente os mais detalhados) sem ser uma área impossível de ser trabalhada (como o originalmente pensado de 640 por 480). A ideia é simular um framebuffer de 256x240 (o mesmo das versões NTSC do NES), creio eu que seja o suficiente.
/
Por último, um novo header (mensagensbobas.h) com a função "silly" foi criado para servir como uma forma de gerar pequenas mensagens bobinhas ao finalizar o jogo. A ideia veio de dois jogos em específico, Fallout e Terraria. Em Fallout, ao finalizar o jogo existe a possibilidade de uma de várias splashscreen especiais serem mostradas na tela. Em Terraria, o nome do executável pode ser um de vários quando o jogo é iniciado. Posteriormente, se isso não tomar muito do meu tempo, pretendo fazer outro sistema que faz o mesmo, mas para pequenos textos discritivos no menu prinipal (ala Minecaft) ou descrições/dicas nas telas de transição do jogo (elas não são necessárias, mas são legais).

//Sétimo commit:
Submenu de opções funcional (função draw_settings). Menu principal agora em loop, possibilitando seu uso contínuo até que não seja mais requisitado. 
/
Adição da pasta "readme", serão armazenados alguns documentos visuais (concepts e GDD), este registro e instruções de compilação.
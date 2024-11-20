#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Personagem {
    char nome[50];
    char classe[20];
    int forca;
    int defesa;
    int vida;
};

struct Cenario {
    char nome[50];
    char descricao[200];
    struct Personagem inimigos[3];
    char historia[500];  
    char historia_completa[1000];  
};


void criarCenarios(struct Cenario cenarios[]) {
  
    strcpy(cenarios[0].nome, "Floresta Negra");
    strcpy(cenarios[0].descricao, "Dizem que a Floresta Negra é um local traiçoeiro, sua beleza obscura hipnotiza os aventureiros para que virem o banquete dos animais que ali vivem.\n");
    strcpy(cenarios[0].inimigos[0].nome, "Lobo Selvagem");
    cenarios[0].inimigos[0].vida = 30;
    cenarios[0].inimigos[0].forca = 10;
    cenarios[0].inimigos[0].defesa = 5;

    strcpy(cenarios[0].inimigos[1].nome, "Espectro da Floresta");
    cenarios[0].inimigos[1].vida = 35;
    cenarios[0].inimigos[1].forca = 12;
    cenarios[0].inimigos[1].defesa = 6;
    
    strcpy(cenarios[0].inimigos[2].nome, "Guardião da Luz");
    cenarios[0].inimigos[2].vida = 40;
    cenarios[0].inimigos[2].forca = 15;
    cenarios[0].inimigos[2].defesa = 4;

    strcpy(cenarios[0].historia, "Você entrou na Floresta Negra, onde a natureza parece viver em harmonia com os espíritos. Porém, logo apos entrar você se depara com um lobo selvagem que esta faminto, mesmo apos voce correr ele sente seu cheiro e o encontra, sua unica alternativa sera mata-lo.");
    strcpy(cenarios[0].historia_completa, "Apos derrotar o lobo, voce finalmente consegue chegar no coração da floresta, é um lugar lindo e cheio de vida, voce ate duvida se esta é realmente a floresta negra.\nMas logo voce volta a realidade ao encontrar um espectro de luz que o diz para nao avancar pois la é um territorio puro que ninguem poderia entrar.\nPorem voce com o objetivo de adquirir a Luz Divina, nao escuta as ordem e continua avancando.\n");


    strcpy(cenarios[1].nome, "Caverna Sombria");
    strcpy(cenarios[1].descricao, "Uma caverna úmida e escura, onde trolls espreitam.");
    strcpy(cenarios[1].inimigos[0].nome, "Troll das Sombras");
    cenarios[1].inimigos[0].vida = 50;
    cenarios[1].inimigos[0].forca = 8;
    cenarios[1].inimigos[0].defesa = 5;

    strcpy(cenarios[1].inimigos[1].nome, "Morcego Gigante");
    cenarios[1].inimigos[1].vida = 35;
    cenarios[1].inimigos[1].forca = 9;
    cenarios[1].inimigos[1].defesa = 6;
    
    strcpy(cenarios[1].inimigos[2].nome, "Rei Troll");
    cenarios[1].inimigos[2].vida = 40;
    cenarios[1].inimigos[2].forca = 11;
    cenarios[1].inimigos[2].defesa = 7;

    strcpy(cenarios[1].historia, "A Caverna Sombria é um local traiçoeiro, cheio de umidade e escuridão. Trolls de pele grossa espreitam a cada passo que você dá. O som dos morcegos gigantes ecoa pelos corredores da caverna.");
    strcpy(cenarios[1].historia_completa, "A Caverna Sombria é um local traiçoeiro, cheio de umidade e escuridão. Trolls de pele grossa espreitam a cada passo que você dá. O som dos morcegos gigantes ecoa pelos corredores da caverna.\n");


    strcpy(cenarios[2].nome, "Castelo do Dragão");
    strcpy(cenarios[2].descricao, "Um castelo antigo onde um dragão imponente guarda seus tesouros.");
    strcpy(cenarios[2].inimigos[0].nome, "Guarda Esqueleto");
    cenarios[2].inimigos[0].vida = 25;
    cenarios[2].inimigos[0].forca = 7;
    cenarios[2].inimigos[0].defesa = 3;

    strcpy(cenarios[2].inimigos[1].nome, "Dragão Ancião");
    cenarios[2].inimigos[1].vida = 30;
    cenarios[2].inimigos[1].forca = 8;
    cenarios[2].inimigos[1].defesa = 8;
    
    strcpy(cenarios[2].inimigos[2].nome, "Dragão Lendario");
    cenarios[1].inimigos[2].vida = 35;
    cenarios[1].inimigos[2].forca = 10;
    cenarios[1].inimigos[2].defesa = 9;
    
    strcpy(cenarios[2].historia, "Você chegou ao Castelo do Dragão, onde as paredes de pedra estão cobertas por musgos antigos. O som do fogo do dragão reverbera no ar enquanto ele guarda suas riquezas em um covil imponente.");
    strcpy(cenarios[2].historia_completa, "Você chegou ao Castelo do Dragão, onde as paredes de pedra estão cobertas por musgos antigos. O som do fogo do dragão reverbera no ar enquanto ele guarda suas riquezas em um covil imponente.\n");
}

void mostrarCenario(struct Cenario *cenario) {
    printf("\n=== %s ===\n", (*cenario).nome);
    printf("%s\n", (*cenario).descricao);
    printf("História: \n%s\n", (*cenario).historia);
}

void contarHistoria(struct Cenario *cenario, int inimigoIndex) {
    if (strcmp((*cenario).nome, "Floresta Negra") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Após derrotar o Lobo Selvagem, você percebe que a floresta parece respirar junto com você. Um vento gélido sopra, e um espectro surge, flutuando entre as árvores, ameaçando sua jornada.\n");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com o Espectro da Floresta derrotado, a densa névoa começa a se dissipar, revelando o verdadeiro coração da Floresta Negra: um altar antigo, repleto de runas brilhantes. Ao tocá-lo, uma luz divina envolve você, renovando suas forças. porem aparece o Guardião da Luz para o impedir.\n");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Apos a derrota do Guardião da Luz, voce finalmente encontra a Luz Divina e consegue livrar não so a floresta mas tbm todo o reino da escuridão que cercavam por milenios.\n");
    	}
    } else if (strcmp((*cenario).nome, "Caverna Sombria") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Você derruba o Troll das Sombras, mas sua queda ecoa pela caverna, alertando outros perigos. Um morcego gigante desce do teto com um grito ensurdecedor, pronto para atacar.\n");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Após derrotar o Morcego Gigante, você encontra um pequeno baú escondido entre as rochas. Dentro dele, há um mapa que revela uma passagem secreta que pode levá-lo diretamente ao tesouro perdido dos trolls.\n");
        }
    } else if (strcmp((*cenario).nome, "Castelo do Dragão") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Ao derrotar o Guarda Esqueleto, o chão do castelo treme, e um rugido aterrorizante ecoa pelos corredores. O Dragão Ancião está ciente da sua presença.\n");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com o Dragão Ancião vencido, você caminha pelo covil e encontra uma sala secreta repleta de ouro e artefatos mágicos. Entre eles, um amuleto brilha intensamente, prometendo grandes poderes a quem o usar.\n");
        }
    } else {
        strcat((*cenario).historia_completa, "História adicional não definida para este cenário.\n");
    }

    printf("\nHistória até agora:\n%s\n", (*cenario).historia_completa);
}

void combate(struct Personagem *jogador, struct Personagem *inimigo) {
    while ((*jogador).vida > 0 && (*inimigo).vida > 0) {
        int escolha;
        printf("\nEscolha sua ação:\n");
        printf("1. Atacar\n");
        printf("2. Defender\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) { 
            int dano = (*jogador).forca - (*inimigo).defesa;
            if (dano < 0) dano = 0; 
            (*inimigo).vida -= dano;
            printf("Você atacou %s causando %d de dano!\n", (*inimigo).nome, dano);
        } else if (escolha == 2) { 
            printf("Você se defendeu, reduzindo o próximo dano em 50%%!\n");
            (*jogador).defesa *= 2; 
        } else {
            printf("Ação inválida!\n");
            continue;
        }

        if ((*inimigo).vida > 0) {
            int danoInimigo = (*inimigo).forca - (*jogador).defesa;
            if (danoInimigo < 0) danoInimigo = 0; 
            (*jogador).vida -= danoInimigo;
            printf("%s atacou você causando %d de dano!\n", (*inimigo).nome, danoInimigo);
        }

        if (escolha == 2) {
            (*jogador).defesa /= 2;
        }

        printf("\nStatus Atual:\n");
        printf("Jogador: %d HP\n", (*jogador).vida);
        printf("%s: %d HP\n", (*inimigo).nome, (*inimigo).vida);
    }

    if ((*jogador).vida > 0) {
        printf("\nVocê derrotou %s!\n", (*inimigo).nome);
    } else {
        printf("\nVocê foi derrotado por %s...\n", (*inimigo).nome);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Cenario cenarios[3];
    criarCenarios(cenarios);

    struct Personagem personagens[5] = {
        {"Ragnar", "Bárbaro", 10, 5, 300},
        {"Eva", "Arqueira", 4, 3, 100},
        {"Seraphine", "Maga", 7, 4, 100},
        {"Steve", "Ladino", 3, 4, 100},
        {"Edmundo", "Guerreiro", 7, 7, 130}
    };

    printf("Escolha seu personagem:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%s) [Força=%d, Defesa=%d, Vida=%d] \n", i + 1, personagens[i].nome, personagens[i].classe, personagens[i].forca, personagens[i].defesa, personagens[i].vida);
    }

    int escolha;
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 5) {
        printf("Escolha inválida!\n");
        return 0;
    }

    struct Personagem jogador = personagens[escolha - 1];

    printf("Escolha o cenário:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, cenarios[i].nome);
    }

    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 3) {
        printf("Escolha inválida!\n");
        return 0;
    }

    struct Cenario cenarioEscolhido = cenarios[escolha - 1];
    mostrarCenario(&cenarioEscolhido);

    for (int i = 0; i < 3; i++) {
        printf("\n--- Encontro com %s ---\n", cenarioEscolhido.inimigos[i].nome);
        combate(&jogador, &cenarioEscolhido.inimigos[i]);

        if (jogador.vida <= 0) {
            printf("\nVocê morreu... Fim de jogo!\n");
            return 0;
        }

        contarHistoria(&cenarioEscolhido, i);
    }

    printf("\nParabéns! Você completou o cenário %s!\n", cenarioEscolhido.nome);

    return 0;
}
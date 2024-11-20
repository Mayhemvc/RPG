#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct Personagem inimigos[2];
    char historia[500];  
    char historia_completa[1000];  
};


void criarCenarios(struct Cenario cenarios[]) {
  
    strcpy(cenarios[0].nome, "Floresta Negra");
    strcpy(cenarios[0].descricao, "Nesta floresta muitos ja entraram, porem, poucos conseguiram sair. Ha uma lenda que nessa floresta habita um ser mitologico que caca exploradores.");
    strcpy(cenarios[0].inimigos[0].nome, "Lobo Selvagem");
    cenarios[0].inimigos[0].vida = 30;
    cenarios[0].inimigos[0].forca = 10;
    cenarios[0].inimigos[0].defesa = 5;

    strcpy(cenarios[0].inimigos[1].nome, "Espectro da Floresta");
    cenarios[0].inimigos[1].vida = 40;
    cenarios[0].inimigos[1].forca = 15;
    cenarios[0].inimigos[1].defesa = 8;

    strcpy(cenarios[0].historia, "Você entrou na Floresta Encantada, onde a natureza parece viver em harmonia com os espíritos. Porém, espreitam nas sombras criaturas selvagens dispostas a caçar qualquer intruso.");
    strcpy(cenarios[0].historia_completa, "Você entrou na Floresta Encantada, onde a natureza parece viver em harmonia com os espíritos. Porém, espreitam nas sombras criaturas selvagens dispostas a caçar qualquer intruso.\n");


    strcpy(cenarios[1].nome, "Caverna Sombria");
    strcpy(cenarios[1].descricao, "Uma caverna úmida e escura, onde trolls espreitam.");
    strcpy(cenarios[1].inimigos[0].nome, "Troll das Sombras");
    cenarios[1].inimigos[0].vida = 50;
    cenarios[1].inimigos[0].forca = 20;
    cenarios[1].inimigos[0].defesa = 10;

    strcpy(cenarios[1].inimigos[1].nome, "Morcego Gigante");
    cenarios[1].inimigos[1].vida = 35;
    cenarios[1].inimigos[1].forca = 12;
    cenarios[1].inimigos[1].defesa = 5;

    strcpy(cenarios[1].historia, "A Caverna Sombria é um local traiçoeiro, cheio de umidade e escuridão. Trolls de pele grossa espreitam a cada passo que você dá. O som dos morcegos gigantes ecoa pelos corredores da caverna.");
    strcpy(cenarios[1].historia_completa, "A Caverna Sombria é um local traiçoeiro, cheio de umidade e escuridão. Trolls de pele grossa espreitam a cada passo que você dá. O som dos morcegos gigantes ecoa pelos corredores da caverna.\n");


    strcpy(cenarios[2].nome, "Castelo do Dragão");
    strcpy(cenarios[2].descricao, "Um castelo antigo onde um dragão imponente guarda seus tesouros.");
    strcpy(cenarios[2].inimigos[0].nome, "Guarda Esqueleto");
    cenarios[2].inimigos[0].vida = 40;
    cenarios[2].inimigos[0].forca = 18;
    cenarios[2].inimigos[0].defesa = 8;

    strcpy(cenarios[2].inimigos[1].nome, "Dragão Ancião");
    cenarios[2].inimigos[1].vida = 120;
    cenarios[2].inimigos[1].forca = 50;
    cenarios[2].inimigos[1].defesa = 25;
3
    strcpy(cenarios[2].historia, "Você chegou ao Castelo do Dragão, onde as paredes de pedra estão cobertas por musgos antigos. O som do fogo do dragão reverbera no ar enquanto ele guarda suas riquezas em um covil imponente.");
    strcpy(cenarios[2].historia_completa, "Você chegou ao Castelo do Dragão, onde as paredes de pedra estão cobertas por musgos antigos. O som do fogo do dragão reverbera no ar enquanto ele guarda suas riquezas em um covil imponente.\n");
}

void mostrarCenario(struct Cenario *cenario) {
    printf("\n=== %s ===\n", (*cenario).nome);
    printf("%s\n", (*cenario).descricao);
    printf("História: \n%s\n", (*cenario).historia);
}

void contarHistoria(struct Cenario *cenario, int inimigoIndex) {
    if (inimigoIndex == 0) {
        strcat((*cenario).historia_completa, "Após vencer o Lobo Selvagem, você segue em frente, mais cauteloso, sabendo que o perigo ainda espreita...\n");
    } else if (inimigoIndex == 1) {
        strcat((*cenario).historia_completa, "Com o Espectro da Floresta derrotado, você sente que a floresta volta a respirar, mas o caminho é longo...\n");
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
    struct Cenario cenarios[3];
    criarCenarios(cenarios);

    struct Personagem personagens[5] = {
        {"Ragnar", "Bárbaro", 10, 5, 125},
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

    for (int i = 0; i < 2; i++) {
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

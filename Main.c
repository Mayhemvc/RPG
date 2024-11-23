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

char save[200];


void criarCenarios(struct Cenario cenarios[]) {
  
    strcpy(cenarios[0].nome, "Floresta Negra");
    strcpy(cenarios[0].descricao, "Uma floresta escura na qual ha boatos que nela se escondem criaturas e o segredo para o fim da escurid�o.\n");
    strcpy(cenarios[0].inimigos[0].nome, "Lobo Selvagem");
    cenarios[0].inimigos[0].vida = 30;
    cenarios[0].inimigos[0].forca = 10;
    cenarios[0].inimigos[0].defesa = 3;

    strcpy(cenarios[0].inimigos[1].nome, "Espectro da Floresta");
    cenarios[0].inimigos[1].vida = 35;
    cenarios[0].inimigos[1].forca = 12;
    cenarios[0].inimigos[1].defesa = 4;
    
    strcpy(cenarios[0].inimigos[2].nome, "Guardi�o da Luz");
    cenarios[0].inimigos[2].vida = 40;
    cenarios[0].inimigos[2].forca = 15;
    cenarios[0].inimigos[2].defesa = 5;

    strcpy(cenarios[0].historia, "Voce entrou na Floresta Negra, onde a natureza parece viver em harmonia com os espiritos. Por�m, logo apos entrar voc� se depara com um lobo selvagem que esta faminto, mesmo apos voce correr ele sente seu cheiro e o encontra, sua unica alternativa sera mata-lo.");
    strcpy(cenarios[0].historia_completa, " ");


    strcpy(cenarios[1].nome, "Caverna Sombria");
    strcpy(cenarios[1].descricao, "Uma caverna �mida e escura, onde trolls guardam um misterioso tesouro desconhecido pelos humanos.");
    strcpy(cenarios[1].inimigos[0].nome, "Troll Guerreiro");
    cenarios[1].inimigos[0].vida = 25;
    cenarios[1].inimigos[0].forca = 7;
    cenarios[1].inimigos[0].defesa = 3;

    strcpy(cenarios[1].inimigos[1].nome, "Morcego Gigante");
    cenarios[1].inimigos[1].vida = 35;
    cenarios[1].inimigos[1].forca = 8;
    cenarios[1].inimigos[1].defesa = 4;
    
    strcpy(cenarios[1].inimigos[2].nome, "Rei Troll");
    cenarios[1].inimigos[2].vida = 45;
    cenarios[1].inimigos[2].forca = 10;
    cenarios[1].inimigos[2].defesa = 5;

    strcpy(cenarios[1].historia, "Voce entra na Caverna Sombria em busca do tesouro prometido, ao andar por la voce escuta barulho do bater de asas de morcegos que ecoa por todos os lados, ao passar por um estreito caminho voce avista uma criatura tenebrosa que ao se levantar, revela ser um Troll, com tres vezes o seu tamanho ele parte para seu rumo em busca de sangue.");
    strcpy(cenarios[1].historia_completa, " ");


    strcpy(cenarios[2].nome, "Castelo do Drag�o");
    strcpy(cenarios[2].descricao, "Um castelo antigo onde um drag�o imponente guarda seus tesouros.");
    strcpy(cenarios[2].inimigos[0].nome, "Guarda Esqueleto");
    cenarios[2].inimigos[0].vida = 25;
    cenarios[2].inimigos[0].forca = 7;
    cenarios[2].inimigos[0].defesa = 3;

    strcpy(cenarios[2].inimigos[1].nome, "Jovem Drag�o");
    cenarios[2].inimigos[1].vida = 30;
    cenarios[2].inimigos[1].forca = 8;
    cenarios[2].inimigos[1].defesa = 4;
    
    strcpy(cenarios[2].inimigos[2].nome, "Drag�o Anci�o");
    cenarios[2].inimigos[2].vida = 35;
    cenarios[2].inimigos[2].forca = 10;
    cenarios[2].inimigos[2].defesa = 5;
    
    strcpy(cenarios[2].historia, "Apos ouvir historias sobre um tesouro que era guardado no Castelo do Drag�o, voce escuta sua ambi��o e vai ate la em busca deste terouso imensuravel, ao chegar no castelo voce � recepcionado por um Guarda Esqueleto que o ordena dar meia volta, porem voce nao o escuta e parte para cima. \n\n");
    strcpy(cenarios[2].historia_completa, " ");
}

void mostrarCenario(struct Cenario *cenario) {
    printf("\n=== %s ===\n", (*cenario).nome);
    printf("%s\n", (*cenario).descricao);
    printf("Hist�ria: \n%s\n", (*cenario).historia);
}

void contarHistoria(struct Cenario *cenario, int inimigoIndex, struct Personagem *jogador, char *save) {
    if (strcmp((*cenario).nome, "Floresta Negra") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Apos derrotar o lobo, voce finalmente consegue chegar no cora��o da floresta, � um lugar lindo e cheio de vida, voce ate duvida se esta � realmente a floresta negra. Mas logo voce volta a realidade ao encontrar um espectro de luz que o diz para nao avancar pois la � um territorio puro que ninguem poderia entrar. Porem voce com o objetivo de adquirir a Luz Divina, nao escuta as ordem e continua avancando.\n\n");
        	*save = printf("Concluiu 33%% da floresta negra");
		} else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com o Espectro da Floresta derrotado, a densa n�voa come�a a se dissipar, revelando o verdadeiro cora��o da Floresta Negra: um altar antigo, repleto de runas brilhantes. Ao toc�-lo, uma luz divina comeca en envolve-lo voc�, renovando suas for�as e aumentando 100 pontos de vida. porem aparece o Guardi�o da Luz para impedir.\n\n");
            jogador->vida += 100;
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Derrotando o Guardi�o da Luz, voce finalmente encontra a Luz Divina e consegue livrar n�o so a floresta mas tambem todo o reino da escurid�o que os cercavam por milenios.\n\n");
		}
    } else if (strcmp((*cenario).nome, "Caverna Sombria") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Com o Troll morto no ch�o voce segue o rumo para esse tesouro prometido e come�a a se questionar se ele realmente existe, mas toda sua luta com o Troll voce acaba despertando a furia de um Morcego Gigante que estava dormindo, irritado o morcego vai em sua dire��o e voces comecam a lutar\n\n");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Apos a vitoria contra o Morcego Gigante voce parte para o final da cavera aonde encontra o tesouro escondido dos Trolls, com ele voce acaba renovando suas forcas e se sente poderoso, ao virar para ir embora voce se depara com o Rei Troll que grita e ordena que devolva seu tesouro.\n\n");
        	jogador->vida += 100;
		} else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Foi uma batalha extremamente cansativa e dificil mas voce consegue derrotar o rei, sendo assim voce para para fora da caverna com todo o tesouro que os Trolss haviam conseguido guardar.\n\n");
        }
    } else if (strcmp((*cenario).nome, "Castelo do Drag�o") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Ao derrotar o Guarda Esqueleto, o ch�o do castelo treme, e um rugido aterrorizante ecoa pelos corredores. O pequeno grande Jovem Drag�o esta atras de voce e sem medo e piedade voce trava uma dolorosa batalha com ele at� que apenas um saia vivo.\n\n");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com o Jovem Drag�o vencido, voc� caminha pelo covil e encontra uma sala secreta repleta de ouro e artefatos m�gicos. Entre eles, um amuleto brilha intensamente, prometendo grandes poderes a quem o usar. Apos colocar o amuleto voce sente o ar ficando quente e uma presen�a chegando perto, voce descobre que � o Drag�o Anci�o enfurecido com a morte de seu primogenito.\n\n");
        	jogador->vida += 100;
		} else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Voce consegue derrotar o anci�o mas perde um bra�o na batalha, mesmo assim voce caminha ate o corpo do drag�o e aranca seu cora��o que vira seu mais novo trofeu de batalha.\n\n");
        }
    } else {
        strcat((*cenario).historia_completa, "Hist�ria adicional n�o definida para este cen�rio.\n");
    }

    printf("\nHist�ria at� agora:\n%s\n", (*cenario).historia_completa);
}

void combate(struct Personagem *jogador, struct Personagem *inimigo) {
    while ((*jogador).vida > 0 && (*inimigo).vida > 0) {
        int escolha;
        printf("\nEscolha sua a��o:\n");
        printf("1. Atacar\n");
        printf("2. Defender\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        
        

        if (escolha == 1) { 
            int dano = (*jogador).forca - (*inimigo).defesa;
            if (dano < 0) dano = 0; 
            (*inimigo).vida -= dano;
            printf("Voc� atacou %s causando %d de dano!\n", (*inimigo).nome, dano);
        } else if (escolha == 2) { 
            printf("Voc� se defendeu, reduzindo o pr�ximo dano em 50%%!\n");
            (*jogador).defesa *= 2; 
        } else {
            printf("A��o inv�lida!\n");
            continue;
        }

        if ((*inimigo).vida > 0) {
            int danoInimigo = (*inimigo).forca - (*jogador).defesa;
            if (danoInimigo < 0) danoInimigo = 0; 
            (*jogador).vida -= danoInimigo;
            printf("%s atacou voc� causando %d de dano!\n", (*inimigo).nome, danoInimigo);
        }

        if (escolha == 2) {
            (*jogador).defesa /= 2;
        }

        printf("\nStatus Atual:\n");
        printf("Jogador: %d HP\n", (*jogador).vida);
        printf("%s: %d HP\n", (*inimigo).nome, (*inimigo).vida);
    }

    if ((*jogador).vida > 0) {
        printf("\nVoc� derrotou %s!\n", (*inimigo).nome);
    } else {
        printf("\nVoc� foi derrotado por %s...\n", (*inimigo).nome);
    }
}

int main() {
	FILE* fptr;
    setlocale(LC_ALL, "Portuguese");
    struct Cenario cenarios[3];
    criarCenarios(cenarios);
    
    fptr = fopen("pessoa.txt", "r");

	if (fptr == NULL) {
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}else{
	fread(&save, sizeof(save), 1, fptr);
	}
	fclose(fptr);

    struct Personagem personagens[5] = {
        {"Ragnar", "B�rbaro", 10, 5, 200},
        {"Eva", "Arqueira", 4, 3, 200},
        {"Seraphine", "Maga", 7, 4, 200},
        {"Steve", "Ladino", 3, 4, 200},
        {"Edmundo", "Guerreiro", 7, 7, 200}
    };

    printf("Escolha seu personagem:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%s) [For�a=%d, Defesa=%d, Vida=%d] \n", i + 1, personagens[i].nome, personagens[i].classe, personagens[i].forca, personagens[i].defesa, personagens[i].vida);
    }

    int escolha;
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 5) {
        printf("Escolha inv�lida!\n");
        return 0;
    }

    struct Personagem jogador = personagens[escolha - 1];

    printf("Escolha o cen�rio:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, cenarios[i].nome);
    }

    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 3) {
        printf("Escolha inv�lida!\n");
        return 0;
    }

    struct Cenario cenarioEscolhido = cenarios[escolha - 1];
    mostrarCenario(&cenarioEscolhido);

    for (int i = 0; i < 3; i++) {
        printf("\n--- Encontro com %s ---\n", cenarioEscolhido.inimigos[i].nome);
        combate(&jogador, &cenarioEscolhido.inimigos[i]);

        if (jogador.vida <= 0) {
            printf("\nVoc� morreu... Fim de jogo!\n");
            return 0;
        }

        contarHistoria(&cenarioEscolhido, i, &jogador, &save);
    }
	
	fptr = fopen("pessoa.txt", "w");
	if (fptr == NULL) {
		printf("Nenhum arquivo salvo");
		fclose(fptr);
		exit(1);	
	}
	else {
		save = fwrite(&save, sizeof(save), 1, fptr);
		fclose(fptr);
	}

    printf("\nParab�ns! Voc� completou o cen�rio %s!\n", cenarioEscolhido.nome);

    return 0;
}
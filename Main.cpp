#include <stdio.h>
#include <stdlib.h>


struct Personagem {
	char nome[50];
	char classe[20];
	int forca;
	int defesa;
	int agilidade;
	int vida; 
};

struct Cenario {
	char nome[50];
	char descricao[200];
};

struct jogador {
	int progresso;
	int personagem;
};

int menu(){
	int inicio;
	
	printf("Digite o que gostaria de fazer:\n1.Iniciar\n2.Carregar\n3.Sair.\n");
	scanf("%d", &inicio);
	
	switch (inicio){
		case 1:
			printf("\nIniciando o RPG...\n\n");
			break;
		case 2:
			printf("Carregando os dados salvos...\n\n");
			break;
		case 3: 
			printf("Saindo...\n\n");
		default:
			printf("Escolha invalida.\n");
			break;
	}
	return inicio;
	
}


int main() {

    struct Personagem p1 = {"Ragnar", "Barbaro", 8, 8, 3, 100};
    struct Personagem p2 = {"Eva", "Arqueiro", 4, 3, 9, 100};
    struct Personagem p3 = {"Seraphine", "Mago", 7, 4, 5, 100};
    struct Personagem p4 = {"Steve", "Ladino", 3, 4, 9, 100};
    struct Personagem p5 = {"Edmundo", "Guerreiro", 7, 7, 5, 100};
	struct Cenario c1 = {"Floresta_Negra", "Nesta floresta muitos ja entraram, porem, poucos conseguiram sair. Ha uma lenda que nessa floresta habita um ser mitologico que caca exploradores."};	
    struct Cenario c2 = {"Nome", "Descricao"};
    struct Cenario c3 = {"Nome", "Descricao"};
	
	int escolha = menu();
    int perso; 
    
	if (escolha==1){
		printf("Seja bem-vindo ao RPG Unaerp, Escolha dentre os 5 personagens pra seguir com sua aventura.\n\n");
		printf("1. O barbaro Ragnar.\n2. A arqueira Eva.\n3. A maga Seraphine.\n4. O Ladino Steve.\n5. O guerreiro Edmundo.\n\n");
		scanf("%d", &perso);	
	}
	
	else if(escolha==2){
	printf("Falta fazer.");
	}
	
	else if(escolha==3){
		return 0;
	}
	
	printf("Otima escolha, vamos inicar nossa aventura!\n\n");
	printf("Nossa primeira aventura sera na %s, %s", c1.nome, c1.descricao);
	
	
	
	
	return 0;
}
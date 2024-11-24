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
    char historia[4000];  
    char historia_completa[4000];  
};

char save[200] = "";


void criarCenarios(struct Cenario cenarios[]) {
  
    strcpy(cenarios[0].nome, "Floresta Negra");
    strcpy(cenarios[0].descricao, "Uma floresta escura na qual ha boatos que nela se escondem criaturas e o segredo para o fim da escurid o.\n");
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

	strcpy(cenarios[0].historia, "\nVoc� adentra a temida Floresta Negra, um lugar envolto em um v�u de cinzas e escurid�o. Cada passo ecoa no ch�o �mido, e o sil�ncio � quebrado apenas pelo sussurro do vento atrav�s das �rvores retorcidas. Aqui, nada parece natural: os animais t�m olhos que brilham com um instinto feroz, e as plantas possuem espinhos t�o afiados quanto l�minas. Nesse ambiente hostil, tudo precisou evoluir para sobreviver.\n\n Mal seus p�s cruzam a fronteira do bosque, um som de passos leves o alerta.\n\n Um lobo selvagem, magro e faminto, surge das sombras. Seus olhos est�o fixos em voc�, cheios de desespero e predador. Voc� tenta correr, mas ele segue seu rastro como se o pr�prio ar conspirasse a seu favor. Sem escolha, voc� empunha sua arma, sabendo que a luta ser� inevit�vel.\n");
    strcpy(cenarios[0].historia_completa, " ");


    strcpy(cenarios[1].nome, "Caverna Sombria");
    strcpy(cenarios[1].descricao, "Uma caverna  mida e escura, onde trolls guardam um misterioso tesouro desconhecido pelos humanos.");
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

    strcpy(cenarios[1].historia, "\nVoc� adentra a temida Caverna Sombria, um lugar envolto em penumbra e umidade, onde o ar � pesado e cada passo ecoa nas paredes irregulares. As sombras dan�am � luz tr�mula de sua tocha, e o som incessante do bater de asas de morcegos preenche o ambiente, criando uma melodia sombria e opressiva. Caminhando por um estreito e sinuoso corredor, seus olhos captam um movimento adiante. Uma figura colossal se ergue, revelando ser um Troll Guerreiro. Com quase tr�s vezes o seu tamanho, ele deixa escapar um rugido gutural e investe contra voc�, sedento por sangue.\n\n");
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
    
    strcpy(cenarios[2].historia, "\nHist�rias sobre um lend�rio tesouro guardado no Castelo do Drag�o ecoaram at� voc�, alimentando sua ambi��o. Dizem que riquezas imensur�veis e artefatos m�gicos repousam naquele lugar sombrio, mas tamb�m que nenhum aventureiro jamais retornou para confirm�-las. Ignorando os avisos, voc� re�ne sua coragem e parte para o castelo, determinado a reivindicar aquilo que muitos consideram inalcan��vel.\n\nAo chegar, voc� � recebido por uma figura sinistra: um Guarda Esqueleto, com olhos brilhando em um tom fantasmag�rico e uma armadura coberta de ferrugem. Ele ergue sua espada e vocifera:\n\n-D� meia-volta, intruso, ou pere�a aqui mesmo!\n\nSem hesitar, voc� ignora suas palavras e avan�a.\n\n");
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
            strcat((*cenario).historia_completa, "Ap�s uma batalha feroz, o lobo jaz no ch�o, e voc� se permite um instante de al�vio. Mas a floresta n�o d� tr�guas. Seguindo a trilha adiante, a escurid�o come�a a dar lugar a algo inesperado. Voc� chega ao cora��o da floresta, um lugar que desafia todas as expectativas. � um santu�rio de vida, onde flores cintilam em cores imposs�veis e a luz do sol rompe atrav�s da n�voa em raios dourados. Voc� mal acredita estar na mesma Floresta Negra.\n\nNo entanto, essa sensa��o de paz � interrompida por uma figura et�rea que se forma diante de voc�. Um espectro de luz, brilhando como uma chama dan�ante, ergue-se no centro da clareira. Ele fala com uma voz que ecoa como sinos distantes:\n\n-Pare. Este � um territ�rio sagrado. Somente os puros de cora��o podem avan�ar. Volte agora, ou pagar� o pre�o.\n\nMas voc� n�o veio at� aqui para desistir. Seu objetivo � claro: alcan�ar a Luz Divina, a �nica esperan�a de libertar o reino das trevas. Ignorando o aviso, voc� avan�a. O espectro hesita por um instante, como se lamentasse sua escolha, e ent�o investe contra voc� com toda a sua for�a.\n\n");
        	snprintf(save, 200, "Concluiu 33% da Floresta Negra");
		} else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Ap�s uma batalha �rdua, o espectro � derrotado, e a densa n�voa ao seu redor come�a a se dissipar. Diante de voc� surge o verdadeiro cora��o da Floresta Negra: um altar antigo, esculpido em pedra e coberto de runas que brilham como estrelas. O ar vibra com uma energia poderosa. Ao tocar o altar, uma luz c�lida e dourada o envolve, restaurando suas for�as e concedendo-lhe 100 pontos de vida.\n\nMas o desafio est� longe de terminar. De dentro da luz, uma figura colossal emerge. O Guardi�o da Luz, uma entidade ancestral feita de pura energia, ergue-se diante de voc�, empunhando uma l�mina de luz ofuscante. Sua voz � grave e imponente:\n\n-Somente os dignos podem portar a Luz Divina. Mostre-me sua verdadeira for�a.\n\n");
            jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66% da Floresta Negra");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Finalmente, com uma �ltima investida, voc� derrota o Guardi�o. Ele cai de joelhos, antes de se dissipar em part�culas de luz, como estrelas que retornam ao c�u.\n\nCom o Guardi�o vencido, a Luz Divina finalmente se revela completamente. Ela se funde a voc�, inundando seu ser com um poder indescrit�vel. Quando retorna ao mundo exterior, a Floresta Negra est� irreconhec�vel: o cinza foi substitu�do por verdes vibrantes, e o ar est� carregado de uma sensa��o de renova��o.\n\nGra�as � sua coragem, a escurid�o que assolava o reino por mil�nios foi finalmente dissipada. A Luz Divina, agora parte de voc�, garante que a paz e a prosperidade retornem � terra, e sua jornada torna-se uma lenda contada por gera��es.\n\n");
            snprintf(save, 200, "Concluiu 100% da Floresta Negra");
        }
    } else if (strcmp((*cenario).nome, "Caverna Sombria") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Depois de uma batalha brutal, o corpo gigantesco do troll cai ao ch�o com um estrondo que faz a caverna tremer. Com o monstro derrotado, voc� respira aliviado por um breve momento, mas sua jornada est� longe de terminar. Enquanto avan�a, um pensamento inquietante se instala: \n-ser� que esse tesouro realmente existe, ou � apenas uma lenda?\n\nA d�vida, no entanto, logo d� lugar ao perigo. O ru�do de sua luta despertou um Morcego Gigante, que surge das sombras. Suas asas enormes criam rajadas de vento que apagam sua tocha, mergulhando a caverna na escurid�o.\n\n");
            snprintf(save, 200, "Concluiu 33% da Caverna Sombria");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com seus sentidos agu�ados, voc� luta na penumbra, desferindo golpes certeiros at� que, finalmente, o morcego cai derrotado.\n\nExausto, mas determinado, voc� segue em dire��o ao cora��o da caverna. O ar parece mais denso, quase palp�vel, enquanto voc� avista um brilho � dist�ncia. Ap�s passar por uma abertura estreita, se depara com um sal�o repleto de riquezas inimagin�veis: ouro, joias e artefatos m�gicos acumulados ao longo dos s�culos pelos trolls. Ao tocar o tesouro, sente uma onda de energia percorrer seu corpo, restaurando 100 pontos de vida.\n\nNo entanto, sua euforia � interrompida por um rugido que faz a caverna inteira estremecer. O Rei Troll, colossal e coberto de armadura, surge de uma passagem oculta. Seus olhos flamejam de �dio ao avistar o tesouro em suas m�os.\n\n-Humano insignificante! Devolva o que pertence ao meu povo, ou enfrentar� minha f�ria!\n\nSem inten��o de recuar, voc� se prepara para a batalha mais desafiadora de sua vida.\n\n");
        	jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66% da Caverna Sombria");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "O embate � longo e cruel; cada golpe trocado deixa marcas profundas no ambiente ao redor. No fim, com um �ltimo esfor�o, voc� derrota o Rei Troll. Ele cai de joelhos antes de desmoronar, e a caverna finalmente silencia, exceto pelo som de seu cora��o ainda acelerado.\n\nCarregando o tesouro dos trolls, voc� deixa a caverna. O brilho do ouro em suas m�os � ofuscado apenas pela luz do sol que invade a entrada. Voc� respira fundo, sabendo que a jornada foi dura, mas valeu a pena. Sua vit�ria ser� lembrada como uma lenda, e o tesouro que conquistou marca o in�cio de uma nova era para sua vida de aventuras.\n\n");
            snprintf(save, 200, "Concluiu 100% da Caverna Sombria");
        }
    } else if (strcmp((*cenario).nome, "Castelo do Drag o") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "O confronto � �rduo, mas sua determina��o prevalece. Ap�s desferir o golpe final, o Guarda Esqueleto desmorona em uma pilha de ossos e poeira, liberando um grito que parece ecoar pelas profundezas do castelo.\n\nAntes que voc� possa recuperar o f�lego, o ch�o come�a a tremer violentamente. Um rugido avassalador ressoa pelos corredores, e, das sombras, emerge um Jovem Drag�o, com escamas reluzentes e olhos flamejantes. Ele � �gil e feroz, atacando com garras afiadas e jatos de fogo. A batalha que se segue � extenuante; cada movimento exige sua m�xima habilidade e estrat�gia.\n\n");
            snprintf(save, 200, "Concluiu 33% da Castelo do Drag o");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Finalmente, com um golpe certeiro, voc� derruba a criatura, que cai ao ch�o com um estrondo. Enquanto a poeira assenta, voc� explora o covil do drag�o e encontra uma sala escondida atr�s de uma parede secreta. L� dentro, � como se tivesse encontrado o para�so: montanhas de ouro e joias, armas m�gicas e pergaminhos antigos que brilham com um poder arcano. No centro do tesouro, um amuleto emana uma luz intensa, quase viva. Ao coloc�-lo, sente uma onda de energia percorrer seu corpo, curando feridas e aumentando sua vitalidade em 100 pontos de vida.\n\nMas o ar � sua volta muda. O calor se intensifica, e o ch�o treme novamente. Um rugido ainda mais profundo e amea�ador ecoa, anunciando a chegada de algo muito maior. Das profundezas do castelo, surge o Drag�o Anci�o, suas escamas negras como a noite, e seus olhos cheios de f�ria.\n\n-MISER�VEL! VOC� MATOU MEU FILHO! PREPARE-SE PARA PAGAR COM A SUA VIDA!\n\nO Drag�o Anci�o � implac�vel, sua for�a e sabedoria milenares o tornam um advers�rio quase invenc�vel. O combate � �pico, e a c�mara treme com cada golpe desferido. Chamas consomem tudo ao seu redor, e seus movimentos ficam cada vez mais lentos, mas voc� n�o desiste.\n\n");
        	jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66% da Castelo do Drag o");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Com um �ltimo esfor�o desesperado, desferindo um golpe que consome suas for�as, o Drag�o Anci�o cai, rugindo de dor, at� que seu corpo finalmente se torna im�vel.\n\nA vit�ria, por�m, vem com um custo alto: na batalha, voc� perde um bra�o, mas a dor � ofuscada pela gl�ria de sua conquista. Manchado de sangue e cinzas, voc� se aproxima do colossal corpo do drag�o e arranca seu cora��o, um trof�u pulsante que simboliza o �pice de sua jornada.\n\nEnquanto sai do castelo, carregando o amuleto e o cora��o do Drag�o Anci�o, voc� sente que o mundo � sua frente mudou. N�o � s� o ouro ou os artefatos que conquistou, mas a certeza de que agora � uma lenda viva, destinado a feitos ainda maiores.\n\n");
            snprintf(save, 200, "Concluiu 100% da Castelo do Drag o");
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

void salvarProgresso(char *save) {
    FILE *fptr = fopen("save.txt", "w");
    if (fptr == NULL) {
        printf("Erro ao salvar o progresso.\n");
        return;
    }
    fprintf(fptr, "%s", save);
    fclose(fptr);
    printf("Progresso salvo com sucesso.\n");
}

void carregarProgresso(char *save) {
    FILE *fptr = fopen("save.txt", "r");
    if (fptr == NULL) {
        printf("Nenhum progresso salvo encontrado.\n");
        return;
    }
    fgets(save, 200, fptr);
    fclose(fptr);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Cenario cenarios[3];
    criarCenarios(cenarios);

    printf("Bem-vindos ao RPG Saga dos Guardi�es\n\n");

    carregarProgresso(save);
    if (strlen(save) > 0) {
        printf("Progresso carregado: %s\n\n", save);
    }

    struct Personagem personagens[5] = {
        {"Ragnar", "B rbaro", 10, 5, 200},
        {"Eva", "Arqueira", 8, 5, 200},
        {"Seraphine", "Maga", 11, 4, 170},
        {"Steve", "Ladino", 9, 4, 180},
        {"Edmundo", "Guerreiro", 7, 7, 250}
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
	
	salvarProgresso(save);

    printf("\nParab�ns! Voc� completou o cen�rio %s!\n", cenarioEscolhido.nome);

    return 0;
}
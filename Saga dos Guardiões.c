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
    
    strcpy(cenarios[0].inimigos[2].nome, "Guardião da Luz");
    cenarios[0].inimigos[2].vida = 40;
    cenarios[0].inimigos[2].forca = 15;
    cenarios[0].inimigos[2].defesa = 5;

	strcpy(cenarios[0].historia, "\nVocê adentra a temida Floresta Negra, um lugar envolto em um véu de cinzas e escuridão. Cada passo ecoa no chão úmido, e o silêncio é quebrado apenas pelo sussurro do vento através das árvores retorcidas. Aqui, nada parece natural: os animais têm olhos que brilham com um instinto feroz, e as plantas possuem espinhos tão afiados quanto lâminas. Nesse ambiente hostil, tudo precisou evoluir para sobreviver.\n\n Mal seus pés cruzam a fronteira do bosque, um som de passos leves o alerta.\n\n Um lobo selvagem, magro e faminto, surge das sombras. Seus olhos estão fixos em você, cheios de desespero e predador. Você tenta correr, mas ele segue seu rastro como se o próprio ar conspirasse a seu favor. Sem escolha, você empunha sua arma, sabendo que a luta será inevitável.\n");
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

    strcpy(cenarios[1].historia, "\nVocê adentra a temida Caverna Sombria, um lugar envolto em penumbra e umidade, onde o ar é pesado e cada passo ecoa nas paredes irregulares. As sombras dançam à luz trêmula de sua tocha, e o som incessante do bater de asas de morcegos preenche o ambiente, criando uma melodia sombria e opressiva. Caminhando por um estreito e sinuoso corredor, seus olhos captam um movimento adiante. Uma figura colossal se ergue, revelando ser um Troll Guerreiro. Com quase três vezes o seu tamanho, ele deixa escapar um rugido gutural e investe contra você, sedento por sangue.\n\n");
    strcpy(cenarios[1].historia_completa, " ");


    strcpy(cenarios[2].nome, "Castelo do Dragão");
    strcpy(cenarios[2].descricao, "Um castelo antigo onde um dragão imponente guarda seus tesouros.");
    strcpy(cenarios[2].inimigos[0].nome, "Guarda Esqueleto");
    cenarios[2].inimigos[0].vida = 25;
    cenarios[2].inimigos[0].forca = 7;
    cenarios[2].inimigos[0].defesa = 3;

    strcpy(cenarios[2].inimigos[1].nome, "Jovem Dragão");
    cenarios[2].inimigos[1].vida = 30;
    cenarios[2].inimigos[1].forca = 8;
    cenarios[2].inimigos[1].defesa = 4;
    
    strcpy(cenarios[2].inimigos[2].nome, "Dragão Ancião");
    cenarios[2].inimigos[2].vida = 35;
    cenarios[2].inimigos[2].forca = 10;
    cenarios[2].inimigos[2].defesa = 5;
    
    strcpy(cenarios[2].historia, "\nHistórias sobre um lendário tesouro guardado no Castelo do Dragão ecoaram até você, alimentando sua ambição. Dizem que riquezas imensuráveis e artefatos mágicos repousam naquele lugar sombrio, mas também que nenhum aventureiro jamais retornou para confirmá-las. Ignorando os avisos, você reúne sua coragem e parte para o castelo, determinado a reivindicar aquilo que muitos consideram inalcançável.\n\nAo chegar, você é recebido por uma figura sinistra: um Guarda Esqueleto, com olhos brilhando em um tom fantasmagórico e uma armadura coberta de ferrugem. Ele ergue sua espada e vocifera:\n\n-Dê meia-volta, intruso, ou pereça aqui mesmo!\n\nSem hesitar, você ignora suas palavras e avança.\n\n");
    strcpy(cenarios[2].historia_completa, " ");
}

void mostrarCenario(struct Cenario *cenario) {
    printf("\n=== %s ===\n", (*cenario).nome);
    printf("%s\n", (*cenario).descricao);
    printf("História: \n%s\n", (*cenario).historia);
}

void contarHistoria(struct Cenario *cenario, int inimigoIndex, struct Personagem *jogador, char *save) {
    if (strcmp((*cenario).nome, "Floresta Negra") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Após uma batalha feroz, o lobo jaz no chão, e você se permite um instante de alívio. Mas a floresta não dá tréguas. Seguindo a trilha adiante, a escuridão começa a dar lugar a algo inesperado. Você chega ao coração da floresta, um lugar que desafia todas as expectativas. É um santuário de vida, onde flores cintilam em cores impossíveis e a luz do sol rompe através da névoa em raios dourados. Você mal acredita estar na mesma Floresta Negra.\n\nNo entanto, essa sensação de paz é interrompida por uma figura etérea que se forma diante de você. Um espectro de luz, brilhando como uma chama dançante, ergue-se no centro da clareira. Ele fala com uma voz que ecoa como sinos distantes:\n\n-Pare. Este é um território sagrado. Somente os puros de coração podem avançar. Volte agora, ou pagará o preço.\n\nMas você não veio até aqui para desistir. Seu objetivo é claro: alcançar a Luz Divina, a única esperança de libertar o reino das trevas. Ignorando o aviso, você avança. O espectro hesita por um instante, como se lamentasse sua escolha, e então investe contra você com toda a sua força.\n\n");
        	snprintf(save, 200, "Concluiu 33%% da Floresta Negra");
		} else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Após uma batalha árdua, o espectro é derrotado, e a densa névoa ao seu redor começa a se dissipar. Diante de você surge o verdadeiro coração da Floresta Negra: um altar antigo, esculpido em pedra e coberto de runas que brilham como estrelas. O ar vibra com uma energia poderosa. Ao tocar o altar, uma luz cálida e dourada o envolve, restaurando suas forças e concedendo-lhe 100 pontos de vida.\n\nMas o desafio está longe de terminar. De dentro da luz, uma figura colossal emerge. O Guardião da Luz, uma entidade ancestral feita de pura energia, ergue-se diante de você, empunhando uma lâmina de luz ofuscante. Sua voz é grave e imponente:\n\n-Somente os dignos podem portar a Luz Divina. Mostre-me sua verdadeira força.\n\n");
            jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66%% da Floresta Negra");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Finalmente, com uma última investida, você derrota o Guardião. Ele cai de joelhos, antes de se dissipar em partículas de luz, como estrelas que retornam ao céu.\n\nCom o Guardião vencido, a Luz Divina finalmente se revela completamente. Ela se funde a você, inundando seu ser com um poder indescritível. Quando retorna ao mundo exterior, a Floresta Negra está irreconhecível: o cinza foi substituído por verdes vibrantes, e o ar está carregado de uma sensação de renovação.\n\nGraças à sua coragem, a escuridão que assolava o reino por milênios foi finalmente dissipada. A Luz Divina, agora parte de você, garante que a paz e a prosperidade retornem à terra, e sua jornada torna-se uma lenda contada por gerações.\n\n");
            snprintf(save, 200, "Concluiu 100%% da Floresta Negra");
        }
    } else if (strcmp((*cenario).nome, "Caverna Sombria") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "Depois de uma batalha brutal, o corpo gigantesco do troll cai ao chão com um estrondo que faz a caverna tremer. Com o monstro derrotado, você respira aliviado por um breve momento, mas sua jornada está longe de terminar. Enquanto avança, um pensamento inquietante se instala: \n-será que esse tesouro realmente existe, ou é apenas uma lenda?\n\nA dúvida, no entanto, logo dá lugar ao perigo. O ruído de sua luta despertou um Morcego Gigante, que surge das sombras. Suas asas enormes criam rajadas de vento que apagam sua tocha, mergulhando a caverna na escuridão.\n\n");
            snprintf(save, 200, "Concluiu 33%% da Caverna Sombria");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Com seus sentidos aguçados, você luta na penumbra, desferindo golpes certeiros até que, finalmente, o morcego cai derrotado.\n\nExausto, mas determinado, você segue em direção ao coração da caverna. O ar parece mais denso, quase palpável, enquanto você avista um brilho à distância. Após passar por uma abertura estreita, se depara com um salão repleto de riquezas inimagináveis: ouro, joias e artefatos mágicos acumulados ao longo dos séculos pelos trolls. Ao tocar o tesouro, sente uma onda de energia percorrer seu corpo, restaurando 100 pontos de vida.\n\nNo entanto, sua euforia é interrompida por um rugido que faz a caverna inteira estremecer. O Rei Troll, colossal e coberto de armadura, surge de uma passagem oculta. Seus olhos flamejam de ódio ao avistar o tesouro em suas mãos.\n\n-Humano insignificante! Devolva o que pertence ao meu povo, ou enfrentará minha fúria!\n\nSem intenção de recuar, você se prepara para a batalha mais desafiadora de sua vida.\n\n");
        	jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66%% da Caverna Sombria");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "O embate é longo e cruel; cada golpe trocado deixa marcas profundas no ambiente ao redor. No fim, com um último esforço, você derrota o Rei Troll. Ele cai de joelhos antes de desmoronar, e a caverna finalmente silencia, exceto pelo som de seu coração ainda acelerado.\n\nCarregando o tesouro dos trolls, você deixa a caverna. O brilho do ouro em suas mãos é ofuscado apenas pela luz do sol que invade a entrada. Você respira fundo, sabendo que a jornada foi dura, mas valeu a pena. Sua vitória será lembrada como uma lenda, e o tesouro que conquistou marca o início de uma nova era para sua vida de aventuras.\n\n");
            snprintf(save, 200, "Concluiu 100%% da Caverna Sombria");
        }
    } else if (strcmp((*cenario).nome, "Castelo do Drag o") == 0) {
        if (inimigoIndex == 0) {
            strcat((*cenario).historia_completa, "O confronto é árduo, mas sua determinação prevalece. Após desferir o golpe final, o Guarda Esqueleto desmorona em uma pilha de ossos e poeira, liberando um grito que parece ecoar pelas profundezas do castelo.\n\nAntes que você possa recuperar o fôlego, o chão começa a tremer violentamente. Um rugido avassalador ressoa pelos corredores, e, das sombras, emerge um Jovem Dragão, com escamas reluzentes e olhos flamejantes. Ele é ágil e feroz, atacando com garras afiadas e jatos de fogo. A batalha que se segue é extenuante; cada movimento exige sua máxima habilidade e estratégia.\n\n");
            snprintf(save, 200, "Concluiu 33%% da Castelo do Dragão");
        } else if (inimigoIndex == 1) {
            strcat((*cenario).historia_completa, "Finalmente, com um golpe certeiro, você derruba a criatura, que cai ao chão com um estrondo. Enquanto a poeira assenta, você explora o covil do dragão e encontra uma sala escondida atrás de uma parede secreta. Lá dentro, é como se tivesse encontrado o paraíso: montanhas de ouro e joias, armas mágicas e pergaminhos antigos que brilham com um poder arcano. No centro do tesouro, um amuleto emana uma luz intensa, quase viva. Ao colocá-lo, sente uma onda de energia percorrer seu corpo, curando feridas e aumentando sua vitalidade em 100 pontos de vida.\n\nMas o ar à sua volta muda. O calor se intensifica, e o chão treme novamente. Um rugido ainda mais profundo e ameaçador ecoa, anunciando a chegada de algo muito maior. Das profundezas do castelo, surge o Dragão Ancião, suas escamas negras como a noite, e seus olhos cheios de fúria.\n\n-MISERÁVEL! VOCÊ MATOU MEU FILHO! PREPARE-SE PARA PAGAR COM A SUA VIDA!\n\nO Dragão Ancião é implacável, sua força e sabedoria milenares o tornam um adversário quase invencível. O combate é épico, e a câmara treme com cada golpe desferido. Chamas consomem tudo ao seu redor, e seus movimentos ficam cada vez mais lentos, mas você não desiste.\n\n");
        	jogador->vida += 100;
            snprintf(save, 200, "Concluiu 66%% da Castelo do Dragão");
        } else if (inimigoIndex == 2) {
            strcat((*cenario).historia_completa, "Com um último esforço desesperado, desferindo um golpe que consome suas forças, o Dragão Ancião cai, rugindo de dor, até que seu corpo finalmente se torna imóvel.\n\nA vitória, porém, vem com um custo alto: na batalha, você perde um braço, mas a dor é ofuscada pela glória de sua conquista. Manchado de sangue e cinzas, você se aproxima do colossal corpo do dragão e arranca seu coração, um troféu pulsante que simboliza o ápice de sua jornada.\n\nEnquanto sai do castelo, carregando o amuleto e o coração do Dragão Ancião, você sente que o mundo à sua frente mudou. Não é só o ouro ou os artefatos que conquistou, mas a certeza de que agora é uma lenda viva, destinado a feitos ainda maiores.\n\n");
            snprintf(save, 200, "Concluiu 100%% da Castelo do Dragão");
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

    printf("Bem-vindos ao RPG Saga dos Guardiões\n\n");

    carregarProgresso(save);
    if (strlen(save) > 0) {
        printf("Progresso carregado: %s\n\n", save);
    }

    struct Personagem personagens[5] = {
        {"Ragnar", "Bárbaro", 10, 5, 200},
        {"Eva", "Arqueira", 8, 5, 200},
        {"Seraphine", "Maga", 11, 4, 170},
        {"Steve", "Ladino", 9, 4, 180},
        {"Edmundo", "Guerreiro", 7, 7, 250}
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

        contarHistoria(&cenarioEscolhido, i, &jogador, &save);
    }
	
	salvarProgresso(save);

    printf("\nParabéns! Você completou o cenário %s!\n", cenarioEscolhido.nome);

    return 0;
}

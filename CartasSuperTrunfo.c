#include <stdio.h>

// Define struct para armazenar dados da carta
typedef struct {
    char estado;
    char codigo[4]; // ex: "A01"
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    // propriedades calculadas
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para ler uma carta
void lerCarta(Carta *carta, int num) {
    printf("Digite os dados da Carta %d:\n", num);
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf(" %3s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta->nome); // lê string com espaços
    getchar(); // limpar \n pendente
    printf("Populacao: ");
    scanf("%d", &carta->populacao);
    printf("Area (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta->pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // calcula propriedades derivadas
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->populacao > 0) ? (carta->pib * 1e9f / carta->populacao) : 0.0f;

    // super poder (soma simples)
    carta->super_poder = 
        carta->populacao + 
        carta->pib + 
        carta->area + 
        carta->pontos_turisticos + 
        carta->densidade + 
        carta->pib_per_capita;
}

// Função para exibir dados da carta
void exibirCarta(Carta carta, int num) {
    printf("\nCarta %d:\n", num);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhoes\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

// Função para comparar as cartas e mostrar o vencedor para cada atributo
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparacao das Cartas:\n");

    // Usando operador ternário para comparar e exibir resultados sem if
    printf("Populacao: Carta %s %s\n", 
        (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo,
        (c1.populacao == c2.populacao) ? "(Empate)" : "vence");

    printf("Area: Carta %s %s\n", 
        (c1.area > c2.area) ? c1.codigo : c2.codigo,
        (c1.area == c2.area) ? "(Empate)" : "vence");

    printf("PIB: Carta %s %s\n", 
        (c1.pib > c2.pib) ? c1.codigo : c2.codigo,
        (c1.pib == c2.pib) ? "(Empate)" : "vence");

    printf("Numero de Pontos Turisticos: Carta %s %s\n", 
        (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo,
        (c1.pontos_turisticos == c2.pontos_turisticos) ? "(Empate)" : "vence");

    // Densidade: vence quem tem menor valor
    printf("Densidade Populacional: Carta %s %s\n", 
        (c1.densidade < c2.densidade) ? c1.codigo : c2.codigo,
        (c1.densidade == c2.densidade) ? "(Empate)" : "vence");

    // PIB per capita: maior vence
    printf("PIB per Capita: Carta %s %s\n", 
        (c1.pib_per_capita > c2.pib_per_capita) ? c1.codigo : c2.codigo,
        (c1.pib_per_capita == c2.pib_per_capita) ? "(Empate)" : "vence");

    // Super Poder: maior vence
    printf("Super Poder: Carta %s %s\n", 
        (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo,
        (c1.super_poder == c2.super_poder) ? "(Empate)" : "vence");
}

int main() {
    Carta carta1, carta2;

    // Ler as duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparar cartas
    compararCartas(carta1, carta2);

    return 0;
}

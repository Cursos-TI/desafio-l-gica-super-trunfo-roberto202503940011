#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código implementa um sistema completo de comparação de cartas de cidades
// permitindo cadastro de duas cartas e comparação por atributos específicos

// Definição da estrutura para representar uma carta de cidade
typedef struct {
    char estado[50];              // Estado da cidade
    char codigo[10];              // Código da carta (ex: A01, B02)
    char nome[100];               // Nome da cidade
    int populacao;                // População da cidade
    float area;                   // Área em km²
    float pib;                    // PIB em bilhões
    int pontos_turisticos;        // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional calculada
    float pib_per_capita;        // PIB per capita calculado
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== CADASTRO DA CARTA %d ===\n", numero);
    
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);  // Lê string com espaços
    
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);  // Lê string com espaços
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcular densidade populacional e PIB per capita
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    
    if (carta->populacao > 0) {
        carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao; // Convertendo bilhões para valor unitário
    } else {
        carta->pib_per_capita = 0;
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta) {
    printf("\n--- DADOS DA CARTA ---\n");
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", carta->pib_per_capita);
}

// Função para comparar cartas por população
void compararPorPopulacao(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("Atributo escolhido: POPULAÇÃO\n\n");
    
    printf("Carta 1 - %s (%s): %d habitantes\n", 
           carta1->nome, carta1->estado, carta1->populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", 
           carta2->nome, carta2->estado, carta2->populacao);
    
    printf("\n--- RESULTADO ---\n");
    if (carta1->populacao > carta2->populacao) {
        printf("🏆 Carta 1 (%s) venceu!\n", carta1->nome);
        printf("Diferença: %d habitantes a mais\n", carta1->populacao - carta2->populacao);
    } else if (carta2->populacao > carta1->populacao) {
        printf("🏆 Carta 2 (%s) venceu!\n", carta2->nome);
        printf("Diferença: %d habitantes a mais\n", carta2->populacao - carta1->populacao);
    } else {
        printf("🤝 Empate! Ambas as cidades têm a mesma população.\n");
    }
}

// Função alternativa para comparar por densidade populacional
void compararPorDensidade(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("Atributo escolhido: DENSIDADE POPULACIONAL\n");
    printf("(Menor densidade vence - menos habitável/congestionada)\n\n");
    
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", 
           carta1->nome, carta1->estado, carta1->densidade_populacional);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", 
           carta2->nome, carta2->estado, carta2->densidade_populacional);
    
    printf("\n--- RESULTADO ---\n");
    if (carta1->densidade_populacional < carta2->densidade_populacional) {
        printf("🏆 Carta 1 (%s) venceu!\n", carta1->nome);
        printf("Menor densidade: %.2f hab/km² vs %.2f hab/km²\n", 
               carta1->densidade_populacional, carta2->densidade_populacional);
    } else if (carta2->densidade_populacional < carta1->densidade_populacional) {
        printf("🏆 Carta 2 (%s) venceu!\n", carta2->nome);
        printf("Menor densidade: %.2f hab/km² vs %.2f hab/km²\n", 
               carta2->densidade_populacional, carta1->densidade_populacional);
    } else {
        printf("🤝 Empate! Ambas as cidades têm a mesma densidade populacional.\n");
    }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das duas cidades
    Carta carta1, carta2;
    
    printf("======================================\n");
    printf("  SUPER TRUNFO - COMPARAÇÃO DE CARTAS\n");
    printf("======================================\n");
    printf("Sistema de comparação entre duas cartas de cidades\n");
    
    // Cadastro das Cartas
    // Solicita ao usuário os dados das duas cidades
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas cadastradas
    printf("\n======================================\n");
    printf("  CARTAS CADASTRADAS\n");
    printf("======================================\n");
    
    printf("\n🏙️  CARTA 1:");
    exibirCarta(&carta1);
    
    printf("\n🏙️  CARTA 2:");
    exibirCarta(&carta2);
    
    // Comparação de Cartas
    // Neste exemplo, vamos comparar por POPULAÇÃO
    // Para testar outros atributos, descomente a linha correspondente
    
    printf("\n======================================\n");
    printf("  COMPARAÇÃO\n");
    printf("======================================\n");
    
    // Escolha do atributo para comparação (definido no código)
    // Descomente apenas UMA das opções abaixo:
    
    compararPorPopulacao(&carta1, &carta2);      // Maior população vence
    // compararPorDensidade(&carta1, &carta2);     // Menor densidade vence
    
    /* Outras comparações possíveis (implementar se necessário):
     * - Por Área: maior área vence
     * - Por PIB: maior PIB vence  
     * - Por PIB per capita: maior PIB per capita vence
     * - Por Pontos Turísticos: mais pontos turísticos vence
     */
    
    printf("\n======================================\n");
    printf("  PROGRAMA FINALIZADO\n");
    printf("======================================\n");
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Tema 3 - Menu Interativo e Comparações Avançadas
// Este código implementa um sistema completo de comparação de cartas com menu interativo
// permitindo ao jogador escolher qual atributo será usado na comparação

// Definição da estrutura para representar uma carta de cidade/país
typedef struct {
    char estado[50];              // Estado da cidade
    char codigo[10];              // Código da carta (ex: A01, B02)
    char nome[100];               // Nome da cidade/país
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
    
    printf("Digite o estado/país: ");
    scanf(" %[^\n]", carta->estado);  // Lê string com espaços
    
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade/país: ");
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
    printf("Estado/País: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", carta->pib_per_capita);
}

// Função para exibir o menu de atributos
int exibirMenu() {
    int opcao;
    
    printf("\n======================================\n");
    printf("       MENU DE COMPARAÇÃO\n");
    printf("======================================\n");
    printf("Escolha o atributo para comparação:\n\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB (Produto Interno Bruto)\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per capita\n");
    printf("0. Sair do programa\n");
    printf("======================================\n");
    printf("Digite sua opção: ");
    
    scanf("%d", &opcao);
    return opcao;
}

// Função para comparar cartas por população
void compararPorPopulacao(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR POPULAÇÃO ===\n");
    
    printf("Carta 1 - %s (%s): %d habitantes\n", 
           carta1->nome, carta1->estado, carta1->populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", 
           carta2->nome, carta2->estado, carta2->populacao);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada para análise detalhada
    if (carta1->populacao > carta2->populacao) {
        int diferenca = carta1->populacao - carta2->populacao;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Diferença: %d habitantes a mais\n", diferenca);
        
        // Análise adicional aninhada
        if (diferenca > 1000000) {
            printf("💡 Análise: Diferença populacional muito significativa (>1M)\n");
        } else if (diferenca > 100000) {
            printf("💡 Análise: Diferença populacional considerável (>100K)\n");
        } else {
            printf("💡 Análise: Diferença populacional moderada\n");
        }
    } else if (carta2->populacao > carta1->populacao) {
        int diferenca = carta2->populacao - carta1->populacao;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Diferença: %d habitantes a mais\n", diferenca);
        
        // Análise adicional aninhada
        if (diferenca > 1000000) {
            printf("💡 Análise: Diferença populacional muito significativa (>1M)\n");
        } else if (diferenca > 100000) {
            printf("💡 Análise: Diferença populacional considerável (>100K)\n");
        } else {
            printf("💡 Análise: Diferença populacional moderada\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm a mesma população.\n");
    }
}

// Função para comparar cartas por área
void compararPorArea(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR ÁREA ===\n");
    
    printf("Carta 1 - %s (%s): %.2f km²\n", 
           carta1->nome, carta1->estado, carta1->area);
    printf("Carta 2 - %s (%s): %.2f km²\n", 
           carta2->nome, carta2->estado, carta2->area);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada
    if (carta1->area > carta2->area) {
        float diferenca = carta1->area - carta2->area;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Diferença: %.2f km² a mais\n", diferenca);
        
        // Análise aninhada por categoria de área
        if (carta1->area > 10000) {
            printf("💡 Análise: Área muito extensa (>10.000 km²)\n");
        } else if (carta1->area > 1000) {
            printf("💡 Análise: Área considerável (>1.000 km²)\n");
        } else {
            printf("💡 Análise: Área compacta\n");
        }
    } else if (carta2->area > carta1->area) {
        float diferenca = carta2->area - carta1->area;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Diferença: %.2f km² a mais\n", diferenca);
        
        // Análise aninhada por categoria de área
        if (carta2->area > 10000) {
            printf("💡 Análise: Área muito extensa (>10.000 km²)\n");
        } else if (carta2->area > 1000) {
            printf("💡 Análise: Área considerável (>1.000 km²)\n");
        } else {
            printf("💡 Análise: Área compacta\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm a mesma área.\n");
    }
}

// Função para comparar cartas por PIB
void compararPorPIB(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR PIB ===\n");
    
    printf("Carta 1 - %s (%s): R$ %.2f bilhões\n", 
           carta1->nome, carta1->estado, carta1->pib);
    printf("Carta 2 - %s (%s): R$ %.2f bilhões\n", 
           carta2->nome, carta2->estado, carta2->pib);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada
    if (carta1->pib > carta2->pib) {
        float diferenca = carta1->pib - carta2->pib;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Diferença: R$ %.2f bilhões a mais\n", diferenca);
        
        // Análise econômica aninhada
        if (carta1->pib > 500) {
            printf("💡 Análise: Economia de grande porte (>R$ 500bi)\n");
        } else if (carta1->pib > 100) {
            printf("💡 Análise: Economia robusta (>R$ 100bi)\n");
        } else {
            printf("💡 Análise: Economia em desenvolvimento\n");
        }
    } else if (carta2->pib > carta1->pib) {
        float diferenca = carta2->pib - carta1->pib;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Diferença: R$ %.2f bilhões a mais\n", diferenca);
        
        // Análise econômica aninhada
        if (carta2->pib > 500) {
            printf("💡 Análise: Economia de grande porte (>R$ 500bi)\n");
        } else if (carta2->pib > 100) {
            printf("💡 Análise: Economia robusta (>R$ 100bi)\n");
        } else {
            printf("💡 Análise: Economia em desenvolvimento\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm o mesmo PIB.\n");
    }
}

// Função para comparar cartas por pontos turísticos
void compararPorPontosTuristicos(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR PONTOS TURÍSTICOS ===\n");
    
    printf("Carta 1 - %s (%s): %d pontos turísticos\n", 
           carta1->nome, carta1->estado, carta1->pontos_turisticos);
    printf("Carta 2 - %s (%s): %d pontos turísticos\n", 
           carta2->nome, carta2->estado, carta2->pontos_turisticos);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada
    if (carta1->pontos_turisticos > carta2->pontos_turisticos) {
        int diferenca = carta1->pontos_turisticos - carta2->pontos_turisticos;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Diferença: %d pontos turísticos a mais\n", diferenca);
        
        // Análise turística aninhada
        if (carta1->pontos_turisticos > 200) {
            printf("💡 Análise: Destino turístico excepcional (>200 pontos)\n");
        } else if (carta1->pontos_turisticos > 100) {
            printf("💡 Análise: Destino turístico importante (>100 pontos)\n");
        } else if (carta1->pontos_turisticos > 50) {
            printf("💡 Análise: Bom potencial turístico (>50 pontos)\n");
        } else {
            printf("💡 Análise: Potencial turístico em desenvolvimento\n");
        }
    } else if (carta2->pontos_turisticos > carta1->pontos_turisticos) {
        int diferenca = carta2->pontos_turisticos - carta1->pontos_turisticos;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Diferença: %d pontos turísticos a mais\n", diferenca);
        
        // Análise turística aninhada
        if (carta2->pontos_turisticos > 200) {
            printf("💡 Análise: Destino turístico excepcional (>200 pontos)\n");
        } else if (carta2->pontos_turisticos > 100) {
            printf("💡 Análise: Destino turístico importante (>100 pontos)\n");
        } else if (carta2->pontos_turisticos > 50) {
            printf("💡 Análise: Bom potencial turístico (>50 pontos)\n");
        } else {
            printf("💡 Análise: Potencial turístico em desenvolvimento\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm o mesmo número de pontos turísticos.\n");
    }
}

// Função para comparar cartas por densidade populacional (REGRA ESPECIAL: menor valor vence)
void compararPorDensidade(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR DENSIDADE POPULACIONAL ===\n");
    printf("⚠️  REGRA ESPECIAL: Menor densidade vence (menos congestionada)\n\n");
    
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", 
           carta1->nome, carta1->estado, carta1->densidade_populacional);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", 
           carta2->nome, carta2->estado, carta2->densidade_populacional);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada (REGRA INVERSA)
    if (carta1->densidade_populacional < carta2->densidade_populacional) {
        float diferenca = carta2->densidade_populacional - carta1->densidade_populacional;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Vantagem: %.2f hab/km² a menos (menos congestionada)\n", diferenca);
        
        // Análise de densidade aninhada
        if (carta1->densidade_populacional < 100) {
            printf("💡 Análise: Densidade muito baixa - área bem espaçosa\n");
        } else if (carta1->densidade_populacional < 1000) {
            printf("💡 Análise: Densidade moderada - boa qualidade de vida\n");
        } else if (carta1->densidade_populacional < 5000) {
            printf("💡 Análise: Densidade alta - área urbanizada\n");
        } else {
            printf("💡 Análise: Densidade muito alta - metrópole congestionada\n");
        }
    } else if (carta2->densidade_populacional < carta1->densidade_populacional) {
        float diferenca = carta1->densidade_populacional - carta2->densidade_populacional;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Vantagem: %.2f hab/km² a menos (menos congestionada)\n", diferenca);
        
        // Análise de densidade aninhada
        if (carta2->densidade_populacional < 100) {
            printf("💡 Análise: Densidade muito baixa - área bem espaçosa\n");
        } else if (carta2->densidade_populacional < 1000) {
            printf("💡 Análise: Densidade moderada - boa qualidade de vida\n");
        } else if (carta2->densidade_populacional < 5000) {
            printf("💡 Análise: Densidade alta - área urbanizada\n");
        } else {
            printf("💡 Análise: Densidade muito alta - metrópole congestionada\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm a mesma densidade populacional.\n");
    }
}

// Função para comparar cartas por PIB per capita
void compararPorPIBPerCapita(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO POR PIB PER CAPITA ===\n");
    
    printf("Carta 1 - %s (%s): R$ %.2f per capita\n", 
           carta1->nome, carta1->estado, carta1->pib_per_capita);
    printf("Carta 2 - %s (%s): R$ %.2f per capita\n", 
           carta2->nome, carta2->estado, carta2->pib_per_capita);
    
    printf("\n--- RESULTADO ---\n");
    
    // Estrutura de decisão aninhada
    if (carta1->pib_per_capita > carta2->pib_per_capita) {
        float diferenca = carta1->pib_per_capita - carta2->pib_per_capita;
        printf("🏆 VENCEDORA: Carta 1 (%s)\n", carta1->nome);
        printf("📊 Diferença: R$ %.2f per capita a mais\n", diferenca);
        
        // Análise de renda aninhada
        if (carta1->pib_per_capita > 50000) {
            printf("💡 Análise: Renda per capita muito alta - padrão desenvolvido\n");
        } else if (carta1->pib_per_capita > 30000) {
            printf("💡 Análise: Renda per capita alta - boa qualidade de vida\n");
        } else if (carta1->pib_per_capita > 15000) {
            printf("💡 Análise: Renda per capita média - em desenvolvimento\n");
        } else {
            printf("💡 Análise: Renda per capita baixa - necessita investimentos\n");
        }
    } else if (carta2->pib_per_capita > carta1->pib_per_capita) {
        float diferenca = carta2->pib_per_capita - carta1->pib_per_capita;
        printf("🏆 VENCEDORA: Carta 2 (%s)\n", carta2->nome);
        printf("📊 Diferença: R$ %.2f per capita a mais\n", diferenca);
        
        // Análise de renda aninhada
        if (carta2->pib_per_capita > 50000) {
            printf("💡 Análise: Renda per capita muito alta - padrão desenvolvido\n");
        } else if (carta2->pib_per_capita > 30000) {
            printf("💡 Análise: Renda per capita alta - boa qualidade de vida\n");
        } else if (carta2->pib_per_capita > 15000) {
            printf("💡 Análise: Renda per capita média - em desenvolvimento\n");
        } else {
            printf("💡 Análise: Renda per capita baixa - necessita investimentos\n");
        }
    } else {
        printf("🤝 EMPATE! Ambas têm o mesmo PIB per capita.\n");
    }
}

// Função principal do sistema de comparação
void sistemaComparacao(const Carta *carta1, const Carta *carta2) {
    int opcao;
    int continuar = 1;
    
    while (continuar) {
        opcao = exibirMenu();
        
        // Estrutura switch para gerenciar as opções do menu
        switch (opcao) {
            case 1:
                compararPorPopulacao(carta1, carta2);
                break;
                
            case 2:
                compararPorArea(carta1, carta2);
                break;
                
            case 3:
                compararPorPIB(carta1, carta2);
                break;
                
            case 4:
                compararPorPontosTuristicos(carta1, carta2);
                break;
                
            case 5:
                compararPorDensidade(carta1, carta2);
                break;
                
            case 6:
                compararPorPIBPerCapita(carta1, carta2);
                break;
                
            case 0:
                printf("\n🎮 Obrigado por jogar Super Trunfo!\n");
                printf("   Saindo do programa...\n");
                continuar = 0;
                break;
                
            default:
                // Tratamento de opção inválida
                printf("\n❌ ERRO: Opção inválida!\n");
                printf("   Por favor, escolha uma opção entre 0 e 6.\n");
                break;
        }
        
        // Se não saiu do programa, pergunta se quer fazer nova comparação
        if (continuar && opcao >= 1 && opcao <= 6) {
            char resposta;
            printf("\n🔄 Deseja fazer outra comparação? (s/n): ");
            scanf(" %c", &resposta);
            resposta = tolower(resposta);
            
            if (resposta != 's') {
                printf("\n🎮 Obrigado por jogar Super Trunfo!\n");
                continuar = 0;
            }
        }
    }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das duas cidades
    Carta carta1, carta2;
    
    printf("==========================================\n");
    printf("    SUPER TRUNFO - MENU INTERATIVO\n");
    printf("==========================================\n");
    printf("Sistema avançado de comparação de cartas\n");
    printf("com menu interativo e análises detalhadas\n");
    
    // Cadastro das Cartas
    // Solicita ao usuário os dados das duas cidades/países
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas cadastradas
    printf("\n==========================================\n");
    printf("       CARTAS CADASTRADAS\n");
    printf("==========================================\n");
    
    printf("\n🎴 CARTA 1:");
    exibirCarta(&carta1);
    
    printf("\n🎴 CARTA 2:");
    exibirCarta(&carta2);
    
    // Iniciar sistema de comparação com menu interativo
    printf("\n==========================================\n");
    printf("       SISTEMA DE COMPARAÇÃO\n");
    printf("==========================================\n");
    printf("Agora você pode escolher qual atributo\n");
    printf("deseja usar para comparar as cartas!\n");
    
    sistemaComparacao(&carta1, &carta2);
    
    printf("\n==========================================\n");
    printf("         PROGRAMA FINALIZADO\n");
    printf("==========================================\n");
    
    return 0;
}

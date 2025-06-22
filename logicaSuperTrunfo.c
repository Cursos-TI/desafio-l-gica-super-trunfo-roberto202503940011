#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Tema 4 - DESAFIO FINAL - Comparação Avançada com Dois Atributos
// Este código implementa o sistema mais avançado de comparação de cartas
// permitindo escolha de dois atributos diferentes com menus dinâmicos

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

// Enumeração para identificar os atributos
typedef enum {
    ATRIBUTO_POPULACAO = 1,
    ATRIBUTO_AREA = 2,
    ATRIBUTO_PIB = 3,
    ATRIBUTO_PONTOS_TURISTICOS = 4,
    ATRIBUTO_DENSIDADE = 5,
    ATRIBUTO_PIB_PER_CAPITA = 6
} TipoAtributo;

// Estrutura para armazenar informações dos atributos selecionados
typedef struct {
    TipoAtributo tipo;
    char nome[50];
    float valor_carta1;
    float valor_carta2;
    int carta1_vence;  // 1 se carta1 vence, 0 se carta2 vence, -1 se empate
} ResultadoAtributo;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== CADASTRO DA CARTA %d ===\n", numero);
    
    printf("Digite o estado/país: ");
    scanf(" %[^\n]", carta->estado);
    
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade/país: ");
    scanf(" %[^\n]", carta->nome);
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcular densidade populacional e PIB per capita
    carta->densidade_populacional = (carta->area > 0) ? 
        (float)carta->populacao / carta->area : 0;
    
    carta->pib_per_capita = (carta->populacao > 0) ? 
        (carta->pib * 1000000000) / carta->populacao : 0;
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

// Função para exibir menu dinâmico de atributos
int exibirMenuAtributos(int atributo_excluido, int numero_escolha) {
    int opcao;
    
    printf("\n==========================================\n");
    printf("    ESCOLHA DO %s ATRIBUTO\n", (numero_escolha == 1) ? "PRIMEIRO" : "SEGUNDO");
    printf("==========================================\n");
    printf("Selecione um atributo para comparação:\n\n");
    
    // Menu dinâmico - exibe apenas opções disponíveis
    if (atributo_excluido != ATRIBUTO_POPULACAO) {
        printf("1. População\n");
    }
    if (atributo_excluido != ATRIBUTO_AREA) {
        printf("2. Área\n");
    }
    if (atributo_excluido != ATRIBUTO_PIB) {
        printf("3. PIB (Produto Interno Bruto)\n");
    }
    if (atributo_excluido != ATRIBUTO_PONTOS_TURISTICOS) {
        printf("4. Pontos Turísticos\n");
    }
    if (atributo_excluido != ATRIBUTO_DENSIDADE) {
        printf("5. Densidade Populacional ⚠️ (menor vence)\n");
    }
    if (atributo_excluido != ATRIBUTO_PIB_PER_CAPITA) {
        printf("6. PIB per capita\n");
    }
    
    printf("0. Voltar ao menu principal\n");
    printf("==========================================\n");
    
    // Mostrar qual atributo já foi escolhido
    if (numero_escolha == 2) {
        const char* nomes[] = {"", "População", "Área", "PIB", "Pontos Turísticos", 
                              "Densidade Populacional", "PIB per capita"};
        printf("✅ Primeiro atributo já escolhido: %s\n", nomes[atributo_excluido]);
    }
    
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para obter valor do atributo da carta
float obterValorAtributo(const Carta *carta, TipoAtributo tipo) {
    switch (tipo) {
        case ATRIBUTO_POPULACAO:
            return (float)carta->populacao;
        case ATRIBUTO_AREA:
            return carta->area;
        case ATRIBUTO_PIB:
            return carta->pib;
        case ATRIBUTO_PONTOS_TURISTICOS:
            return (float)carta->pontos_turisticos;
        case ATRIBUTO_DENSIDADE:
            return carta->densidade_populacional;
        case ATRIBUTO_PIB_PER_CAPITA:
            return carta->pib_per_capita;
        default:
            return 0.0;
    }
}

// Função para obter nome do atributo
const char* obterNomeAtributo(TipoAtributo tipo) {
    switch (tipo) {
        case ATRIBUTO_POPULACAO: return "População";
        case ATRIBUTO_AREA: return "Área";
        case ATRIBUTO_PIB: return "PIB";
        case ATRIBUTO_PONTOS_TURISTICOS: return "Pontos Turísticos";
        case ATRIBUTO_DENSIDADE: return "Densidade Populacional";
        case ATRIBUTO_PIB_PER_CAPITA: return "PIB per capita";
        default: return "Desconhecido";
    }
}

// Função para obter unidade do atributo
const char* obterUnidadeAtributo(TipoAtributo tipo) {
    switch (tipo) {
        case ATRIBUTO_POPULACAO: return "habitantes";
        case ATRIBUTO_AREA: return "km²";
        case ATRIBUTO_PIB: return "bilhões";
        case ATRIBUTO_PONTOS_TURISTICOS: return "pontos";
        case ATRIBUTO_DENSIDADE: return "hab/km²";
        case ATRIBUTO_PIB_PER_CAPITA: return "R$";
        default: return "";
    }
}

// Função para comparar um atributo específico
ResultadoAtributo compararAtributo(const Carta *carta1, const Carta *carta2, TipoAtributo tipo) {
    ResultadoAtributo resultado;
    resultado.tipo = tipo;
    strcpy(resultado.nome, obterNomeAtributo(tipo));
    resultado.valor_carta1 = obterValorAtributo(carta1, tipo);
    resultado.valor_carta2 = obterValorAtributo(carta2, tipo);
    
    // Lógica de comparação usando operador ternário
    if (tipo == ATRIBUTO_DENSIDADE) {
        // Para densidade, menor valor vence (regra especial)
        resultado.carta1_vence = (resultado.valor_carta1 < resultado.valor_carta2) ? 1 :
                                (resultado.valor_carta1 > resultado.valor_carta2) ? 0 : -1;
    } else {
        // Para outros atributos, maior valor vence
        resultado.carta1_vence = (resultado.valor_carta1 > resultado.valor_carta2) ? 1 :
                                (resultado.valor_carta1 < resultado.valor_carta2) ? 0 : -1;
    }
    
    return resultado;
}

// Função para exibir resultado detalhado de um atributo
void exibirResultadoAtributo(const Carta *carta1, const Carta *carta2, const ResultadoAtributo *resultado, int numero_atributo) {
    printf("\n--- ATRIBUTO %d: %s ---\n", numero_atributo, resultado->nome);
    
    // Usar operador ternário para formatação condicional
    const char* unidade = obterUnidadeAtributo(resultado->tipo);
    const char* formato = (resultado->tipo == ATRIBUTO_POPULACAO || resultado->tipo == ATRIBUTO_PONTOS_TURISTICOS) 
                         ? "%.0f" : "%.2f";
    
    printf("🎴 %s (%s): ", carta1->nome, carta1->estado);
    printf(formato, resultado->valor_carta1);
    printf(" %s\n", unidade);
    
    printf("🎴 %s (%s): ", carta2->nome, carta2->estado);
    printf(formato, resultado->valor_carta2);
    printf(" %s\n", unidade);
    
    // Exibir resultado usando operador ternário
    printf("📊 Resultado: ");
    printf(resultado->carta1_vence == 1 ? "🏆 %s vence!\n" :
           resultado->carta1_vence == 0 ? "🏆 %s vence!\n" : "🤝 Empate neste atributo!\n",
           resultado->carta1_vence == 1 ? carta1->nome : carta2->nome);
    
    // Análise adicional para densidade populacional
    if (resultado->tipo == ATRIBUTO_DENSIDADE && resultado->carta1_vence != -1) {
        printf("⚠️  Regra especial: menor densidade vence (menos congestionada)\n");
    }
}

// Função para calcular e exibir resultado final
void calcularResultadoFinal(const Carta *carta1, const Carta *carta2, 
                           const ResultadoAtributo *attr1, const ResultadoAtributo *attr2) {
    
    printf("\n==========================================\n");
    printf("           RESULTADO FINAL\n");
    printf("==========================================\n");
    
    // Calcular somas
    float soma_carta1 = attr1->valor_carta1 + attr2->valor_carta1;
    float soma_carta2 = attr1->valor_carta2 + attr2->valor_carta2;
    
    // Exibir somas
    printf("💰 SOMA DOS ATRIBUTOS:\n");
    printf("🎴 %s (%s): %.2f + %.2f = %.2f\n", 
           carta1->nome, carta1->estado, 
           attr1->valor_carta1, attr2->valor_carta1, soma_carta1);
    printf("🎴 %s (%s): %.2f + %.2f = %.2f\n", 
           carta2->nome, carta2->estado, 
           attr1->valor_carta2, attr2->valor_carta2, soma_carta2);
    
    printf("\n🏆 VENCEDOR FINAL: ");
    
    // Determinar vencedor usando operador ternário
    printf(soma_carta1 > soma_carta2 ? "%s! 🎉\n" :
           soma_carta1 < soma_carta2 ? "%s! 🎉\n" : "EMPATE TOTAL! 🤝\n",
           soma_carta1 > soma_carta2 ? carta1->nome : carta2->nome);
    
    // Exibir diferença se não houver empate
    if (soma_carta1 != soma_carta2) {
        float diferenca = (soma_carta1 > soma_carta2) ? 
                         (soma_carta1 - soma_carta2) : (soma_carta2 - soma_carta1);
        printf("📊 Diferença na soma: %.2f pontos\n", diferenca);
    }
    
    // Análise final usando operador ternário
    printf("\n💡 ANÁLISE: ");
    printf(soma_carta1 == soma_carta2 ? "Competição extremamente equilibrada!\n" :
           (soma_carta1 > soma_carta2 ? 
            (soma_carta1 - soma_carta2 > 1000 ? "Vitória dominante!\n" : 
             soma_carta1 - soma_carta2 > 100 ? "Vitória consistente!\n" : "Vitória apertada!\n") :
            (soma_carta2 - soma_carta1 > 1000 ? "Vitória dominante!\n" : 
             soma_carta2 - soma_carta1 > 100 ? "Vitória consistente!\n" : "Vitória apertada!\n")));
    
    // Estatísticas adicionais
    printf("\n📈 ESTATÍSTICAS DA RODADA:\n");
    printf("🥇 Vitórias por atributo - %s: %d | %s: %d | Empates: %d\n",
           carta1->nome, 
           (attr1->carta1_vence == 1 ? 1 : 0) + (attr2->carta1_vence == 1 ? 1 : 0),
           carta2->nome,
           (attr1->carta1_vence == 0 ? 1 : 0) + (attr2->carta1_vence == 0 ? 1 : 0),
           (attr1->carta1_vence == -1 ? 1 : 0) + (attr2->carta1_vence == -1 ? 1 : 0));
}

// Função principal para comparação avançada com dois atributos
void comparacaoAvancada(const Carta *carta1, const Carta *carta2) {
    int primeiro_atributo, segundo_atributo;
    int continuar = 1;
    
    while (continuar) {
        printf("\n==========================================\n");
        printf("      COMPARAÇÃO AVANÇADA - 2 ATRIBUTOS\n");
        printf("==========================================\n");
        printf("Você escolherá DOIS atributos diferentes\n");
        printf("para uma comparação mais completa!\n");
        
        // Escolha do primeiro atributo
        do {
            primeiro_atributo = exibirMenuAtributos(0, 1);  // 0 = nenhum excluído
            
            if (primeiro_atributo == 0) {
                printf("🔙 Voltando ao menu principal...\n");
                return;
            }
            
            // Validação usando operador ternário
            printf(primeiro_atributo >= 1 && primeiro_atributo <= 6 ? 
                   "✅ Primeiro atributo selecionado: %s\n" : 
                   "❌ Opção inválida! Tente novamente.\n",
                   (primeiro_atributo >= 1 && primeiro_atributo <= 6) ? 
                   obterNomeAtributo((TipoAtributo)primeiro_atributo) : "");
                   
        } while (primeiro_atributo < 1 || primeiro_atributo > 6);
        
        // Escolha do segundo atributo (menu dinâmico)
        do {
            segundo_atributo = exibirMenuAtributos(primeiro_atributo, 2);
            
            if (segundo_atributo == 0) {
                printf("🔙 Voltando para escolher o primeiro atributo...\n");
                break;
            }
            
            // Validação com operador ternário - impedir seleção do mesmo atributo
            if (segundo_atributo == primeiro_atributo) {
                printf("❌ ERRO: Você já escolheu este atributo!\n");
                printf("   Escolha um atributo diferente.\n");
                continue;
            }
            
            printf(segundo_atributo >= 1 && segundo_atributo <= 6 ? 
                   "✅ Segundo atributo selecionado: %s\n" : 
                   "❌ Opção inválida! Tente novamente.\n",
                   (segundo_atributo >= 1 && segundo_atributo <= 6) ? 
                   obterNomeAtributo((TipoAtributo)segundo_atributo) : "");
                   
        } while ((segundo_atributo < 1 || segundo_atributo > 6) && segundo_atributo != 0);
        
        // Se usuário escolheu voltar, reinicia o loop
        if (segundo_atributo == 0) continue;
        
        // Realizar comparações
        printf("\n==========================================\n");
        printf("           COMPARAÇÃO DETALHADA\n");
        printf("==========================================\n");
        
        ResultadoAtributo resultado1 = compararAtributo(carta1, carta2, (TipoAtributo)primeiro_atributo);
        ResultadoAtributo resultado2 = compararAtributo(carta1, carta2, (TipoAtributo)segundo_atributo);
        
        // Exibir resultados individuais
        exibirResultadoAtributo(carta1, carta2, &resultado1, 1);
        exibirResultadoAtributo(carta1, carta2, &resultado2, 2);
        
        // Calcular e exibir resultado final
        calcularResultadoFinal(carta1, carta2, &resultado1, &resultado2);
        
        // Pergunta se quer fazer nova comparação
        char resposta;
        printf("\n🔄 Deseja fazer outra comparação com 2 atributos? (s/n): ");
        scanf(" %c", &resposta);
        
        // Usar operador ternário para decisão
        continuar = (tolower(resposta) == 's') ? 1 : 0;
        
        printf(continuar ? "\n🎮 Iniciando nova comparação...\n" : 
               "\n🎮 Obrigado por jogar Super Trunfo Avançado!\n");
    }
}

// Função para exibir menu principal
int exibirMenuPrincipal() {
    int opcao;
    
    printf("\n==========================================\n");
    printf("      SUPER TRUNFO - MENU PRINCIPAL\n");
    printf("==========================================\n");
    printf("Escolha o modo de comparação:\n\n");
    printf("1. 🎯 Comparação Simples (1 atributo)\n");
    printf("2. 🚀 Comparação Avançada (2 atributos)\n");
    printf("3. 📊 Ver dados das cartas novamente\n");
    printf("0. 🚪 Sair do programa\n");
    printf("==========================================\n");
    printf("Digite sua opção: ");
    
    scanf("%d", &opcao);
    return opcao;
}

// Função simplificada para comparação com um atributo (modo clássico)
void comparacaoSimples(const Carta *carta1, const Carta *carta2) {
    int atributo;
    int continuar = 1;
    
    while (continuar) {
        atributo = exibirMenuAtributos(0, 1);  // Menu completo para um atributo
        
        if (atributo == 0) return;
        
        if (atributo >= 1 && atributo <= 6) {
            ResultadoAtributo resultado = compararAtributo(carta1, carta2, (TipoAtributo)atributo);
            
            printf("\n==========================================\n");
            printf("         COMPARAÇÃO SIMPLES\n");
            printf("==========================================\n");
            
            exibirResultadoAtributo(carta1, carta2, &resultado, 1);
            
            printf("\n🏆 RESULTADO FINAL: ");
            printf(resultado.carta1_vence == 1 ? "%s vence! 🎉\n" :
                   resultado.carta1_vence == 0 ? "%s vence! 🎉\n" : "Empate! 🤝\n",
                   resultado.carta1_vence == 1 ? carta1->nome : carta2->nome);
        } else {
            printf("❌ Opção inválida!\n");
            continue;
        }
        
        char resposta;
        printf("\n🔄 Deseja fazer outra comparação simples? (s/n): ");
        scanf(" %c", &resposta);
        continuar = (tolower(resposta) == 's') ? 1 : 0;
    }
}

int main() {
    Carta carta1, carta2;
    
    printf("==========================================\n");
    printf("   SUPER TRUNFO - DESAFIO FINAL\n");
    printf("==========================================\n");
    printf("Sistema completo com comparação avançada\n");
    printf("de dois atributos e menus dinâmicos!\n");
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas cadastradas
    printf("\n==========================================\n");
    printf("         CARTAS CADASTRADAS\n");
    printf("==========================================\n");
    
    printf("\n🎴 CARTA 1:");
    exibirCarta(&carta1);
    
    printf("\n🎴 CARTA 2:");
    exibirCarta(&carta2);
    
    // Sistema principal com menu
    int opcao;
    int continuar = 1;
    
    while (continuar) {
        opcao = exibirMenuPrincipal();
        
        switch (opcao) {
            case 1:
                printf("\n🎯 Iniciando comparação simples...\n");
                comparacaoSimples(&carta1, &carta2);
                break;
                
            case 2:
                printf("\n🚀 Iniciando comparação avançada...\n");
                comparacaoAvancada(&carta1, &carta2);
                break;
                
            case 3:
                printf("\n📊 Exibindo dados das cartas...\n");
                printf("\n🎴 CARTA 1:");
                exibirCarta(&carta1);
                printf("\n🎴 CARTA 2:");
                exibirCarta(&carta2);
                break;
                
            case 0:
                printf("\n🎮 Obrigado por jogar Super Trunfo!\n");
                printf("   Até a próxima! 👋\n");
                continuar = 0;
                break;
                
            default:
                printf("❌ Opção inválida! Escolha entre 0 e 3.\n");
                break;
        }
    }
    
    printf("\n==========================================\n");
    printf("         PROGRAMA FINALIZADO\n");
    printf("==========================================\n");
    
    return 0;
}

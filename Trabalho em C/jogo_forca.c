#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Função para desenhar o boneco baseado nas vidas restantes
void desenhaBoneco(int vidas) {
    switch (vidas) {
        case 6:
            printf("  +---+\n      |\n      |\n      |\n     ===\n");
            break;
        case 5:
            printf("  +---+\n  O   |\n      |\n      |\n     ===\n");
            break;
        case 4:
            printf("  +---+\n  O   |\n  |   |\n      |\n     ===\n");
            break;
        case 3:
            printf("  +---+\n  O   |\n /|   |\n      |\n     ===\n");
            break;
        case 2:
            printf("  +---+\n  O   |\n /|\\  |\n      |\n     ===\n");
            break;
        case 1:
            printf("  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n");
            break;
        case 0:
            printf("  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
            break;
    }
}
// Função principal
int main() {
    char *palavras[] = {"Curitiba", "Florianopolis", "Salvador", "Brasilia", "Recife", "Manaus", "Aracaju", "Palmas", "Goiania"};
    int numPalavras = sizeof(palavras) / sizeof(palavras[0]);

    // Sorteio da palavra secreta
    srand(time(NULL));
    char *palavraSecreta = palavras[rand() % numPalavras];
    int tamanhoPalavra = strlen(palavraSecreta);

    // Inicializa as variáveis do jogo
    char palavraAdivinhada[tamanhoPalavra];
    memset(palavraAdivinhada, '_', tamanhoPalavra); // Preenche com underscores
    palavraAdivinhada[tamanhoPalavra] = '\0';

    int vidas = 6;
    char letrasUsadas[26] = {0};
    int usadasIndex = 0;

    // Loop do jogo
    while (vidas > 0) {
        system("clear || cls"); // Limpa a tela (funciona no Windows e Linux)
        desenhaBoneco(vidas);

        printf("Palavra: %s\n", palavraAdivinhada);
        printf("Vidas restantes: %d\n", vidas);
        printf("Letras ja usadas: ");
        for (int i = 0; i < usadasIndex; i++) {
            printf("%c ", letrasUsadas[i]);
        }
        printf("\n");

        // Entrada do jogador
        printf("Digite uma letra: ");
        char letra;
        scanf(" %c", &letra);

        // Verifica se a letra já foi usada
        int jaUsada = 0;
        for (int i = 0; i < usadasIndex; i++) {
            if (letrasUsadas[i] == letra) {
                jaUsada = 1;
                break;
            }
        }
        if (jaUsada) {
            printf("Você ja usou essa letra. Tente outra.\n");
            continue;
        }

        // Adiciona a letra ao array de letras usadas
        letrasUsadas[usadasIndex++] = letra;

        // Verifica se a letra está na palavra
        int acertou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (tolower(palavraSecreta[i]) == tolower(letra)) {
                palavraAdivinhada[i] = palavraSecreta[i];
                acertou = 1;
            }
        }

        if (!acertou) {
            vidas--;
        }

        // Verifica se o jogador ganhou
        if (strcmp(palavraAdivinhada, palavraSecreta) == 0) {
            printf("Parabens! Voce acertou a palavra: %s\n", palavraSecreta);
            break;
        }
    }

    if (vidas == 0) {
        system("clear || cls");
        desenhaBoneco(vidas);
        printf("Que pena! Você perdeu. A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
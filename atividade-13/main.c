// Carlos Eduardo Gonzaga Romaniello de Souza - 19.1.4003

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define max_direction(x, y) (((x) > (y)) ? (0) : (1))

int LPS(char* s, char** m, int n){

    int j; // contador da coluna

    // iniciando a diagonal principal
    for (int i = 0; i < n; i++){
        m[i][i] = 1;
    }

    for (int l = 2; l <= n; l++){ // tamanho da subsequencia
        for (int i = 0; i < n-l+1; i++){ // percorrendo as linhas

            j = i + l - 1;

            if (s[i] == s[j] && l == 2){ // caso os caracteres das extremidades forem iguais e for a primeira iteracao, o tamanho do palindromo eh 2
                m[i][j] = 2;
            }
            else if (s[i] == s[j]){ // caso os caracteres das extremidades forem iguais e NAO for a primeira iteracao, o tamanho do palindromo eh o tamanho do maior palindromo dos caracetres internos mais 2 por causa dos caracteres das extremidades
                m[i][j] = m[i + 1][j-1] + 2;
            }
            else { // caso nao forem iguais, o tamanho eh igual ao tamanho da maior subsequencia que eh um palindromo nos caracteres internos
                m[i][j] = max(m[i][j - 1], m[i + 1][j]);
            }

        }
    }

    return m[0][n - 1];

}

void printLPS(char** m, char* s, int i, int j){
    if (i == j){ // caso os indices forem iguais printa o caractere e encerra a recursividade
        printf("%c", s[i]);
        return;
    }

    if (s[i] == s[j]){ // caso os caracteres da extremidade forem iguais printa o da extrema esquerda, chama a funcao recursivamente atualizando os indices, e imprime o caractere da extrea direita
        printf("%c", s[i]);
        printLPS(m, s, i + 1, j - 1);
        printf("%c", s[j]);
    }
    else { // caso contrario verifica qual subsequencia possui o maior palindromo e chama funcao recursivamente para essa subsequencia
        int x = max_direction(m[i][j - 1], m[i + 1][j]);

        if (x == 1){
            printLPS(m, s, i + 1, j);
        }
        else {
            printLPS(m, s, i, j - 1);
        }
    }
}

int main(int argc, char* argv[]){

    if (argc != 2){
        printf("Eh necessario mais argumentos para executar o programa!!!\n");
        exit(0);
    }

    // tamanho da maior subsequencia que eh um palindromo
    int maiorTamanho;

    int SIZE = strlen(argv[1]); // tamanho da string de entrada

    char** matriz = malloc(SIZE * sizeof(char*)); // matriz para armazenar os valores
    for (int i = 0; i < SIZE; i++){
        matriz[i] = malloc(SIZE * sizeof(char));
    }

    char* string = malloc(SIZE * sizeof(char)); // string passada como parametro
    strcpy(string, argv[1]);

    maiorTamanho = LPS(string, matriz, SIZE);
    printf("Tamanho LPS: %d\n", maiorTamanho);

    printf("LPS: ");
    printLPS(matriz, string, 0, SIZE - 1);
    printf("\n");


    for (int i = 0; i < SIZE; i++){
        free(matriz[i]);
    }
    free(matriz);
    free(string);

    return 0;
}
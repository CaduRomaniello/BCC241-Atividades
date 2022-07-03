/*

Carlos Eduardo Gonzaga Romaniello de Souza - 19.1.4003

 █████╗ ███╗   ██╗ █████╗ ██╗     ██╗███████╗███████╗    ██████╗ ███████╗                      
██╔══██╗████╗  ██║██╔══██╗██║     ██║██╔════╝██╔════╝    ██╔══██╗██╔════╝                      
███████║██╔██╗ ██║███████║██║     ██║███████╗█████╗      ██║  ██║█████╗                        
██╔══██║██║╚██╗██║██╔══██║██║     ██║╚════██║██╔══╝      ██║  ██║██╔══╝                        
██║  ██║██║ ╚████║██║  ██║███████╗██║███████║███████╗    ██████╔╝███████╗                      
╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝╚══════╝    ╚═════╝ ╚══════╝                      
                                                                                               
 ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗     ███████╗██╗  ██╗██╗██████╗  █████╗ ██████╗ ███████╗
██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║     ██╔════╝╚██╗██╔╝██║██╔══██╗██╔══██╗██╔══██╗██╔════╝
██║     ██║   ██║██╔████╔██║██████╔╝██║     █████╗   ╚███╔╝ ██║██║  ██║███████║██║  ██║█████╗  
██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝   ██╔██╗ ██║██║  ██║██╔══██║██║  ██║██╔══╝  
╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ███████╗███████╗██╔╝ ██╗██║██████╔╝██║  ██║██████╔╝███████╗
 ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚══════╝

- A análise de complexidade será feita sobre a funcao 'potenciacao' visto que é nela que ocorre a recursividade.
- Primeiramente foi realizada a analise sobre cada linha da funcao 'potenciacao' e das funcoes que ela invoca. As análises estão feitas em cada uma das linhas no próprio código em forma de comentário
- Com isso temos a função T(n) = T(n/2) + 19
- Pela relação de recorrência temos que T(n) = T(n/(2^k)) + 19k
- O caso base irá ocorrer quando n/(2^k) = 1
- ln(n) = k * ln(2) -> k = ln(n)
- Substituindo k por ln(n) em T(n) temos que T(n) = T(1) + 19 * ln(n)
- T(n) = O(1) + O(ln(n)), portanto T(n) = O(ln(n))

*/

#include <stdio.h>

void multiplicacao(int M1[2][2], int M2[2][2]) {          // 8 no total
    int x = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];    // 1
    int y = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];    // 1
    int z = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];    // 1
    int w = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];    // 1
    M1[0][0] = x;                                         // 1
    M1[0][1] = y;                                         // 1
    M1[1][0] = z;                                         // 1
    M1[1][1] = w;                                         // 1
}

void potenciacao(int matriz[2][2], int n) {
    if ( n == 0 || n == 1){                               // 1
        return;
    }
    potenciacao(matriz, n / 2);                           // T(n/2)
    multiplicacao(matriz, matriz);                        // 8
    if (n % 2 != 0){                                      // 1
        int matrizAux[2][2] = {{1, 1}, {1, 0}};           // 1
        multiplicacao(matriz, matrizAux);                 // 8
    }
}

int fibonacci(int n) {
    int matriz[2][2] = {{1, 1}, {1, 0}};
    if (n == 0){
        return 0;
    }
    potenciacao(matriz, n - 1);
    return matriz[0][0];
}

int main() {
    int n;
    printf("Digite a posição do termo desejado: ");
    scanf("%d", &n);
    printf("Termo na posição %d: %d\n", n, fibonacci(n));
    
    return 0;
}
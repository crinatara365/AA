#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char* argv[]) {
    FILE* in;
    in = fopen(argv[1], "r");
    if(in == NULL) return 0;
    char* input = malloc(10);
    /* se citesc primele 3 linii din fisierul de input */
    int clique, nodes, edges;
    fscanf(in, "%d", &clique);
    fscanf(in, "%d", &nodes);
    fscanf(in, "%d", &edges);

    char matrix[nodes+1][nodes+1];
    int a, b;  
    /* se initializeaza matricea de adiacenta cu 0 */
    for(int i = 1; i <= nodes; i++) {
        for(int j = 1; j <= nodes; j++)
            matrix[i][j] = 0;
    }  
    /* se inlocuieste cu 1 fiecare pozitie corespunzatoare unei muchii */   
    for(int i = 1; i <= edges; i++) {
        fscanf(in, "%d %d", &a, &b);
        matrix[a][b] = 1;
        /* completam si pozitia simetrica tocmai pentru cazul testului 1 (categoria 2) de care spuneam si in readme */
        matrix[b][a] = 1;
    }

    /* conditie 1: daca avem o clica, fiecare nod poate sa fie al i-lea nod din clica */
    for(int i = 1; i <= clique; i++) {
        printf("(");
        for(int v = 1; v <= nodes; v++) {
            printf("x%d%d", i, v);
            if(v == nodes)
                printf(")");
            else
                printf(" V ");
        }  
        printf(" ^ ");
    }

    /* conditie 2: un nod nu poate fi si al i-lea si al j-lea nod din clica) */
    for(int v = 1; v <= nodes; v++)
        for(int i = 1; i <= clique-1; i++) 
            for(int j = i+1; j <= clique; j++) {
                    printf("(~x%d%d V ~x%d%d)", i, v, j, v);
                    printf(" ^ ");    
                }

    /* conditie 3: daca (v,u) este non-edge */
    for(int i = 1; i <= clique-1; i++)
        for(int j = i+1;  j <= clique; j++)
            for(int v = 1; v <= nodes; v++) 
                for(int u = 1; u <= nodes; u++) 
                    if(matrix[u][v] == 0) {
                        /* atunci doar unul din nodurile v si u poate fi in clica */
                        printf("(~x%d%d V ~x%d%d)", i, u, j, v);
                        if(v == nodes && u == nodes && i == clique-1 && j == clique)
                            return 0;
                        else
                            printf(" ^ ");
                    }
     
    return 0;
}
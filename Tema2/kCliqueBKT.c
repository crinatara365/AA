#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int check_if_clique(int contor, int aux[], int nodes, char matrix[][nodes]) {
    int auxiliar = 0, lenght1 = 0, lenght2 = 1;
    int i, j;

    /* luam fiecare nod cu fiecare nod si verificam pozitia din matricea de adiacenta */
    while(lenght1 < contor) {
        i = aux[lenght1];
        while(lenght2 <= contor) {
            j = aux[lenght2];
            if(matrix[i][j] != 'X') auxiliar++;    
            lenght2++;
        }
        lenght1++;
        lenght2 = lenght1+1;
    }
    /* daca auxiliar!=0 inseamna ca exista cel putin o pereche de noduri care nu sunt legate de o muchie, deci nu avem clica */
    if(auxiliar == 0) 
         return 0;
     return 1;
}

int* find_clique(int store[], int dimension, int nodes, char matrix[][nodes]) {
    int aux[100], auxiliar; 
    int dim = dimension;
    int cliques[MAX] = {0};
    int contor = 0, contor1 = 0;
   
    for(int i = 0; i < MAX; i = i + dimension - 1) {
        if(store[i] != 0) {
            auxiliar = i;
            while(dim > 1) {
                /* se copiaza in aux nodurile din store in functie de dimensiunea pe care o avem de atins */
                aux[contor] = store[auxiliar];
                contor++;
                auxiliar++; 
                dim--;
            }

            /* acum luam la rand toate nodurile si verificam daca formeaza o clica cu nodurile pe care le avem deja in aux */
            for(int j = 1; j <= nodes; j++) {
                aux[contor] = j;
                /* daca formeaza clica */
                if(check_if_clique(contor,aux,nodes,matrix) == 0) {
                    /* adaugam continutul lui aux in clique */
                    for(int k=0; k<=contor; k++) { //parcurg aux ca sa-l pun in cliques
                        cliques[contor1] = aux[k];
                        contor1++;
                    }
                }
            }
            /* resetam contor pentru a refolosi vectorul aux */
            contor = 0;

            /* resetam dimensiunea data pentru a copia urmatoarele elemente din store in aux */
            dim = dimension;
        }
        else
            break;
    }

    /* clique este un vector plin de zerouri la inceput, deci i-l atribuim lui store si il returnam
       ceea ce inseamna ca in store dupa apelul acestei functii avem ori zerouri, ceea ce inseamna ca 
       nu exista o clica de dimensiune data, ori o alaturare de noduri ce reprezinta clica */
    store = cliques;
    return store;        
}

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

    /* se completeaza matricea de adiacenta */
    char matrix[nodes][nodes];
    int a, b;       
    for(int i = 1; i <= edges; i++) {
        fscanf(in, "%d %d", &a, &b);
        matrix[a][b] = 'X';
    }

    /* cream un vector store plin de zerouri in care o sa pastram clicile */
    int store[MAX] = {0};
    int contor = 0, dimension = 2;
    int* p;

    /* punem in store toate clicile de dimensiune 1 (adica toate nodurile) */
    for(int i = 1; i <= nodes; i++) {
        store[contor] = i;
        contor++;
    }

    /* apelam functia find_clique pana cand dimension == clique */
    while(dimension <= clique) {
        p = find_clique(store, dimension, nodes, matrix);
        for(int i = 0; i < MAX; i++)
            store[i] = p[i];    
        dimension++;
    }

    /* la sfarsit, avem in store fie clica/clicile de dimensiune clique, fie doar zerouri,
       deci e suficient sa verificam prima pozitie a vectorului pentru a sti ce sa afisam */
    if(store[0] == 0) printf("False");
    else printf("True");

    return 0;
}
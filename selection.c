#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Declaracao de variaveis
*/
double rm = RAND_MAX;

void fill_random(int list[],int n){
    for (int i = 0; i < n; i++){
        list[i] = rand()/rm * n * 2;
        }
    }

void print_array(int list[], int n){


    for (int i = 0; i < n; i++){
        printf("%d ",list[i]);
        }
    printf("\n");
    }

int main(int argc, char **argv)
{

    //abrir o arquivo    
    FILE *arq;
    arq = fopen("t_selection","a");
    
    //analisar o argumento quando houver
    int N = 10;
    if (argv[1] != NULL){
        N = atoi(argv[1]);
        printf("%i\n",N);
        }

    //iniciar o seed
    int seed = time(NULL);
    srand(seed);

    //iniciar a array com alocacao dinamica
    int* not_sorted = malloc(N * sizeof(int));

    fill_random(not_sorted,N);
    
    print_array(not_sorted,N);

    //_______________________________________________________
    int time1 = time(NULL);

    int aux;
    for (int i = 0; i < N-1; i++){

        int idx_menor = i; 

        for (int j = i+1; j < N; j ++){
            //se o anterior for maior troca de lugar
            if (not_sorted[idx_menor] > not_sorted[j]){
                idx_menor = j;
                }
        }

        if (idx_menor != i){
            // trocar as posicoes
            aux = not_sorted[i];
            not_sorted[i] = not_sorted[idx_menor];
            not_sorted[idx_menor] = aux;           
            }
        
        
    }
    //__________________________________________
    
    int time2 = time(NULL)-time1;
    
    fprintf(arq,"%i\t%i\n",N,time2);
    fclose(arq);
    
    print_array(not_sorted,N);
    return 0;

}

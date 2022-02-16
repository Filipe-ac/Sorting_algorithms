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
    arq = fopen("t_inserction","a");
    
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
    for (int i = 1; i < N; i++){
        int atual = not_sorted[i]; //separar
        int j = i-1;
        while (j >= 0 && not_sorted[j] > atual) 
        {
            //enquanto o da esquerda (j) for menor do que o atual,passar para frente
            not_sorted[j+1] = not_sorted[j];
            j = j-1;//posicao certa do atual vai para a esquerda
        
        }
        not_sorted[j+1] = atual;

        /* antigo
        for (int j = i-1; j >= 0; j --){
            //se o anterior for maior troca de lugar

            
            if (not_sorted[j] > atual){
                aux = not_sorted[j];
                not_sorted[j] = atual;
                not_sorted[j+1] = aux; 
                }
           
        }
        */
        
    }
    //__________________________________________
    
    int time2 = time(NULL)-time1;
    
    fprintf(arq,"%i\t%i\n",N,time2);
    fclose(arq);
    
    print_array(not_sorted,N);
    return 0;

}




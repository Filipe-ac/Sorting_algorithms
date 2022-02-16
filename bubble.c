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
    arq = fopen("t_bubble","a");
    
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
    for (int i = 0; i < N; i++){
        int atual = not_sorted[0]; // valor a ser comparado
        int is_sorted = 0; //testar se ja esta arrumada
        for (int j = 1; j < N-i; j ++){
            //se o anterior for maior troca de lugar
            if (atual > not_sorted[j]){
                aux = not_sorted[j];
                not_sorted[j-1] = aux;
                not_sorted[j] = atual; 
                is_sorted = 1;
                }
            else{
                //atualizar o maior valor 
                atual = not_sorted[j];
                }
               
            //printf("%d,%d\n\n",i,j); 
        
        }
        //print_array(not_sorted,N);
        if (is_sorted == 0){
            break;
            }
        
    }
    //__________________________________________
    
    int time2 = time(NULL)-time1;
    
    fprintf(arq,"%i\t%i\n",N,time2);
    fclose(arq);
    
    print_array(not_sorted,N);
    return 0;

}

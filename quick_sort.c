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


int quicksort(int arr[],int inicio,int fim){
    
    //printf("%i,%i\n",inicio,pivot_idx);
    int i = inicio;
    int j = fim - 1;
    int pivot_idx;
    pivot_idx = (fim + inicio)/2;
    int pivo = arr[pivot_idx];
    //printf("%i,%i\n",i,j);
    while (i <= j){//rodar ate checar todo o lado esquerdo e direito do pivot
        
        while (arr[i] < pivo && i < fim)
            {//esquerda esta ok
            
            i = i+1;           
            } //fim do while      
        while (arr[j] > pivo && j > inicio)
            {//direita ok
            
            j = j-1;
            }// fim do while
        
        /*se i ainda nao cruzou j, entao o lado direito e menor do que o pivot,
            e o lado esquerdo maior. Trocar os lados e atualizar i e j*/
        if (i <= j)

            {
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;   
            i = i + 1;
            j = j - 1;
            }
        }
    //se j for menor do que o inicio, arrumar agora a lista da esquera
    if (j > inicio){
        quicksort(arr,inicio,j+1);//j e antes do ultimo pivot. Acrescentar 1 pela definicao da funcao
        }
    //se i < fim, arrumar lista da direita
    if (i < fim){
        quicksort(arr,i,fim);//i e a posicao depois do ultimo pivot
        }
    }// fim da funcao


int main(int argc, char **argv){


    //abrir o arquivo    
    FILE *arq;
    arq = fopen("t_quick","a");
    
    //analisar o argumento quando houver
    int N = 10;
    if (argv[1] != NULL){
        N = atoi(argv[1]);
        }

    //iniciar o seed
    int seed = time(NULL);
    srand(seed);

    //iniciar a array com alocacao dinamica
    int* not_sorted = malloc(N * sizeof(int));

    fill_random(not_sorted,N);
    
    
    //print_array(not_sorted,N);


    //_______________________________________________________
    
    int time1 = time(NULL);


    //int arr[8] = {7,2,1,8,6,3,5,4};

    quicksort(not_sorted,0,N);



    int time2 = time(NULL)-time1;
    //__________________________________________
    
    
    
    fprintf(arq,"%i\t%i\n",N,time2);
    fclose(arq);

    print_array(not_sorted,N);
    
    return 0;

}

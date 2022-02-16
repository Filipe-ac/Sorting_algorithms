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


void merge(int arr1[],int inicio, int meio, int fim){

    //copiar a array
    //int arr_aux [fim];//colocar alocacao dinamica

    int* arr_aux = malloc(fim* sizeof(int));//com alocacao dinamica

    for (int i = inicio; i < fim; i ++){
        arr_aux[i] = arr1[i];
        }
    
    
    int i = inicio; int j = meio; int k = inicio;
    int n1 = meio; //fim da primeira parte
    int n2 = fim; //fim da segunda parte

    
    //ir alocando as listas
    while (i < n1 && j < n2){
        if (arr_aux[i] <= arr_aux[j]){
            arr1[k] = arr_aux[i];
            i = i+1;
            }           
        else{
            arr1[k] = arr_aux[j];
            j = j+1;
            }
        k = k+1;
        }//fim do while

    // completar com a lista que sobrou
    while (i < n1){
        
        arr1[k] = arr_aux[i];
        k = k+1;
        i = i+1;
        }

    while (j < n2){

        arr1[k] = arr_aux[j];
        k = k+1;
        j = j+1;
        }
    }

int merge_sort(int arr[], int inicio,int fim){

    int meio = inicio + (fim - inicio)/2;
    //condicao de parada da funcao recursiva (inicio == meio) quando chegou no ultimo elemento
    if (inicio != meio){
        merge_sort(arr,inicio,meio);
        merge_sort(arr,meio,fim);
        merge(arr,inicio,meio,fim);
        }  

    }


int main(int argc, char **argv){


    //abrir o arquivo    
    FILE *arq;
    arq = fopen("t_merge","a");
    
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
    
    
    print_array(not_sorted,N);


    //_______________________________________________________
    
    int time1 = time(NULL);
    merge_sort(not_sorted,0,N);
    int time2 = time(NULL)-time1;
    //__________________________________________
    
    
    
    fprintf(arq,"%d\t%i\n",N,time2);
    fclose(arq);
    print_array(not_sorted,N);
    //print_array(not_sorted,N);
    
    return 0;

}

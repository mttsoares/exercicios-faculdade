#include <stdio.h>
#include <stdlib.h>

// int arr[tamanho]
int* criaArray(int tamanho) {
    int* arr = (int*)malloc(sizeof(int)*tamanho);
    for(int i = 0; i < tamanho; i++){
        int b = rand()%100;
        arr[i] = b;
    }
    return arr;
}

void mostrarArray (int* array, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("(%d)\n", array[i]);
    }
}
//As funcoes acima foram criadas durante as aulas de IAA

//Funcao merge para ordenar e juntar os arrays em um array ordenado
void merge(int* array, int* esquerda, int tamanhoEsq, int* direita, int tamanhoDir){
    int i = 0, j = 0, k = 0; //Inicializa as variaveis para verificacao no loop
    while(i < tamanhoEsq && j < tamanhoDir){
        if(esquerda[i] <= direita[j]){ //Se o elemento a esquerda for o menor ou igual ao da direita, implementa-lo no array
            array[k] = esquerda[i];
            i++;
        } else { // Se o elemento a esquerda for maior, implementa o elemento da direita no array
            array[k] = direita[j];
            j++;
        }
        k++;
    }
    
    /*Os loops a seguir garantem a implementacao de elementos restantes do array, que nao foram 
    incluidos na verificacao anterior, ja que ela compara um subarray ao outro, e quando o primeiro
    acaba, ele sai do loop.*/
    
    while(i < tamanhoEsq){ 
        array[k] = esquerda[i];
        i++;
        k++;
    }
    while(j < tamanhoDir){
        array[k] = direita[j];
        j++;
        k++;
    }
}

int* mergeSort(int* array, int tamanho){
    if(tamanho < 2){ return array; } //Se o array possui tamanho um, nao precisamos dividi-lo
    
    //Divisao do array em dois
    int meio = tamanho/2;
    int* esquerda = (int*)malloc(sizeof(int)* meio);
    int* direita = (int*)malloc(sizeof(int)* (tamanho - meio));
    
    for(int i = 0; i < meio; i++){  //Preenche o array com os elementos anteriores ao do meio
        esquerda[i] = array[i];
    }
    for(int i = meio; i < tamanho; i++){ //Preenche o array com os elementos posteriores ao do meio (inclusive o meio)
        direita[i - meio] = array[i]; 
    }
    
    //Realiza o mergeSort ate que nao seja mais possivel dividir o array
    esquerda = mergeSort(esquerda, meio); 
    direita = mergeSort(direita, tamanho - meio);
    
    //Chama a funcao merge
    merge(array, esquerda, meio, direita, (tamanho-meio));
    //Liberacao da memoria
    free(esquerda);
    free(direita);
    
    return array;
}


int main(){
    int c=10;
    int* a = criaArray(c);
    printf("Array a ordenar:\n");
    mostrarArray(a, c);
    
    printf("\nArray ordenado:\n");
    mergeSort(a, c);
    mostrarArray(a, c);
    
    free(a);
    
    return 0;
}
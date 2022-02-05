#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int dado;
    struct noh *proximo;
    struct noh *anterior;
}*tipoLista;


//Essa e a questao 2 da lista
//Faça um programa em C que concatene duas listas, dando origem a uma única lista
//com uma ponteiro “Terc” apontando seu primeiro elemento.

tipoLista criarNoh(int valor){
    tipoLista novoNoh = (tipoLista) malloc(sizeof(tipoLista));
    if (novoNoh == NULL){
        printf("\n erro para criar noh\n");
        return NULL;
    }
    else{
        novoNoh->dado = valor;
        novoNoh->proximo = NULL;
        novoNoh->anterior = NULL;
        return novoNoh;
    }
    
}

tipoLista inserirEsquerda(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);
    if (lista == NULL){
        return novoNoh;
    }
    else{
        lista->anterior = novoNoh;
        novoNoh->proximo = lista;
        return novoNoh;
    }
    
}

tipoLista inserirDireita(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);

    if (lista == NULL){
        return novoNoh;
    }
    else{
        tipoLista listaAux = lista;

        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
        }
        
        listaAux->proximo = novoNoh;
        novoNoh->anterior = listaAux;
   //?     
        return lista;
    }
}

tipoLista removerEsquerda(tipoLista lista){
    tipoLista listaAux = lista;
    
    if (lista == NULL){
        return lista;
    }

    else if (listaAux->proximo == NULL){
        free(listaAux);
        listaAux = NULL;
    }

    else{

        lista = listaAux->proximo; 
        free(listaAux);
        listaAux = NULL;
        return lista;
    }
    
}

tipoLista removerDireita(tipoLista lista){
    tipoLista listaAux = lista;
    tipoLista listaAux2;

    if (lista == NULL){
        printf("\nvazia\n");
    }
    else{
        

        if (listaAux->proximo == NULL){
           free(listaAux);
           listaAux = NULL;
        }
        else{
            while (listaAux->proximo != NULL){
                listaAux = listaAux->proximo;
            }

            listaAux2 = listaAux;
            listaAux->anterior->proximo = NULL;
            listaAux2->anterior = NULL;
            free(listaAux2);
            listaAux2 = NULL;

            return lista;


        }
        

    }
    return listaAux;
    

}
tipoLista excluirMeio(int valor, tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("Lista vazia");
    }
    else if (lista->anterior == NULL && lista->proximo == NULL){
        free(lista);
        lista = NULL;
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->proximo != NULL && listaAux->anterior != NULL){
                    listaAux2 = listaAux->anterior;
                    listaAux = listaAux->proximo;
                    listaAux2->proximo = listaAux;
                    listaAux->anterior = listaAux2;
                }
                else if (listaAux->proximo != NULL && listaAux->anterior == NULL){
                    printf("\nRemove esquerda\n");
                    
                    listaAux = listaAux->proximo;
                    listaAux->anterior = NULL;
                    return listaAux;            
                }
                else if (listaAux->proximo == NULL && listaAux->anterior != NULL){
                    printf("\nRemove direita\n");
                    
                    listaAux2 = listaAux;
                    listaAux->anterior->proximo = NULL;
                    listaAux2->anterior = NULL;
                    free(listaAux2);
                    listaAux2 = NULL;

                    return lista;
                    
                }
                
            }
            
            listaAux = listaAux->proximo;
            
        }
        return lista;
        free(listaAux2);
        listaAux2 = NULL;
        free(listaAux);
        listaAux = NULL;
        
    }

}




void pesquisar(int valor, tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("Lista vazia");
    }
    else{

        tipoLista listaAux = lista;
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                flag++;
            }
            
            listaAux = listaAux->proximo;
            
        }


    }
    printf("Esse valor foi encontrado %d vezes", flag);

}

void exibir(tipoLista lista){
    int contador=0;
    printf("\n----------Lista atual--------\n");
    if (lista == NULL){
        printf("\nVazia\n");
    }
    else{
        tipoLista listaAux = lista;
        tipoLista listaAux2 = NULL;
        while (listaAux != NULL){
            printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
            contador++;
        }
    
     
        
    }
    printf("\n-----------------------------------\n");
    
}


tipoLista concatenar(tipoLista lista, tipoLista lista2){
    tipoLista listaAux = lista;
    tipoLista listaAux2;

    if (lista == NULL && lista2 == NULL){
        printf("\n vazias \n");
    }
    else if (lista != NULL && lista2 == NULL){
        return lista;
    }
    else if (lista == NULL && lista2 != NULL){
        return lista2;
    }
    
    else{
        
            while (listaAux->proximo != NULL){
                listaAux = listaAux->proximo;
            }
            listaAux->proximo = lista2;
            lista2->anterior = listaAux;

            return lista;

    }
    return listaAux;
    

}


int main(){
    int op = 11;
    int valor = 0;
    tipoLista lista = NULL;
    tipoLista lista2 = NULL;


    while (op != 0){
        
        printf("\n 1- inserir esquerda lista 1 \n");
        printf("\n 2- inserir direita lista 1 \n");
        printf("\n 11- inserir esquerda lista 2 \n");
        printf("\n 22- inserir direita lista 2 \n");
        printf("\n 33- concatenar \n");
       
        printf("\n 0- sair \n");
        printf("Digite: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            printf("\n Lista 1 \n");
            exibir(lista);
            printf("\n Lista 2 \n");
            exibir(lista2);
            break;
        case 2:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            exibir(lista);
            printf("\n Lista 2 \n");
            exibir(lista2);
            break;
        case 11:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista2 = inserirEsquerda(valor, lista2);
            exibir(lista);
            printf("\n Lista 2 \n");
            exibir(lista2);
            break;
        case 22:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista2 = inserirDireita(valor, lista2);
            exibir(lista);
            printf("\n Lista 2 \n");
            exibir(lista2);
            break;
        case 33:
            printf("Concatenar \n");
            lista = concatenar(lista, lista2);
            printf("\nLista concatenada:\n");
            exibir(lista);
    
            break;
        
        

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}
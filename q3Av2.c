#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int dado;
    struct noh *proximo;
    struct noh *anterior;
}*tipoLista;


tipoLista excluirMeio(int valor, tipoLista lista);
tipoLista inserirDirk(int valor, tipoLista lista, int valor_novo);
tipoLista inserirEsquerda(int valor, tipoLista lista);
tipoLista criarNoh(int valor);
tipoLista inserirDireita(int valor, tipoLista lista);


int tamanho(tipoLista lista){
        int tamanho=0;
        tipoLista listaAux = lista;
        if (lista != NULL){
            while (listaAux != NULL){
                listaAux = listaAux->proximo;
                tamanho++;
            }
            return tamanho;
        }
        else{
            return 0;
        }
     
}

int maiorLista(tipoLista lista){
        int maior;
        tipoLista listaAux = lista;
        maior = lista->dado;

        //Descobrir maior da lista
        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
            if (listaAux->dado >= maior){
                maior = listaAux->dado;
            }
            
        }
    return maior;

}

int menorLista(tipoLista lista){
        int menor;
        tipoLista listaAux = lista;
        menor = lista->dado;

        //Descobrir menor da lista
        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
            if (listaAux->dado <= menor){
                menor = listaAux->dado;
            }
            
        }
    return menor;

}



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
        return lista;
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
        while (listaAux != NULL){
            printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
        }
        
    }
    printf("\n-----------------------------------\n");
    
}

tipoLista inverter(tipoLista lista){
    int contador=0;
    printf("\n----------Lista atual--------\n");
    if (lista == NULL || lista->proximo == NULL){
        printf("\nVazia ou so com um elemento\n");
        return lista;
    }
    else{
        tipoLista listaAux = lista;
        tipoLista listaAux2  = lista->proximo;
        
        //printf("\n %d l1 \n", listaAux->dado);
        //printf("\n %d l2 \n", listaAux2->dado);
        //printf("\n ---------------------- \n");

       //listaAux->proximo = listaAux->anterior;
       //listaAux->anterior = listaAux2;

       //listaAux = listaAux->anterior;

       //listaAux->proximo = listaAux->anterior;
       //listaAux->anterior = NULL;

       while (listaAux2->proximo != NULL){

           listaAux->proximo = listaAux->anterior;
           listaAux->anterior = listaAux2;

            
            listaAux2  = listaAux2->proximo;
            
           listaAux = listaAux->anterior;
           printf("\n %d------------------ L2 \n", listaAux2->dado);
       }
            
            listaAux->proximo = listaAux->anterior;
            listaAux->anterior = NULL;
            listaAux2->proximo = listaAux;
            listaAux2->anterior = NULL;
            printf("\n %d------------------ L2 \n", listaAux2->dado);

        //printf("\n %d------------------ l2 \n", listaAux2->dado);

        //printf("\n %d------------------ l2 \n", listaAux2->dado);
        //printf("\n %d l2 \n", listaAux2->dado);
        printf("\n ---------------------- \n");


        return listaAux2;
    }
    
   
 
}

int main(){
    int op = 11;
    int valor = 0;
    tipoLista lista = NULL;


    while (op != 0){
        exibir(lista);
        printf("\n %d tamanho \n", tamanho(lista));
        printf("\n 1- inserir esquerda \n");
        printf("\n 2- inserir direita \n");
        printf("\n 3- remover esquerda \n");
        printf("\n 4- remover direita \n");
        printf("\n 5 - inverter \n");
        printf("\n 0- sair \n");
        printf("Digite: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            break;
        case 2:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            printf("Remover esquerda \n");
            lista = removerEsquerda(lista);
    
            break;
        case 4:
            printf("Remover direita \n");
            lista = removerDireita(lista);
    
            break;
        case 5:
            printf("Inverter \n");
            lista = inverter(lista);
    
            break;

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}
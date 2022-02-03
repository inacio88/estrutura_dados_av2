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


tipoLista inserirEsqk(int valor, tipoLista lista, int valor_novo){
    
    if (lista == NULL){
        printf("Lista vazia");
        lista = inserirEsquerda(valor_novo, lista);
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        tipoLista novoNoh;
        novoNoh = criarNoh(valor_novo);
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->anterior == NULL){
                    lista = inserirEsquerda(valor_novo, lista);
                    return lista;
                }

                listaAux2 = listaAux;
                listaAux2 = listaAux2->anterior;

                listaAux2->proximo = novoNoh;
                novoNoh->anterior = listaAux2;
                novoNoh->proximo = listaAux;
                listaAux->anterior = novoNoh;

                return lista;

            }
            
            listaAux = listaAux->proximo;
            
        }
        free(listaAux);
        listaAux = NULL;
        free(listaAux2);
        listaAux2 = NULL;

    }
 

}


tipoLista inserirDirk(int valor, tipoLista lista, int valor_novo){
    
    if (lista == NULL){
        printf("Lista vazia");
        lista = inserirEsquerda(valor_novo, lista);
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        tipoLista novoNoh;
        novoNoh = criarNoh(valor_novo);
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->proximo == NULL){
                    lista = inserirDireita(valor_novo, lista);
                    return lista;
                }

                listaAux2 = listaAux->proximo;
                listaAux->proximo = novoNoh;
                novoNoh->anterior = listaAux;
                novoNoh->proximo = listaAux2;
                listaAux2->anterior = novoNoh;
                return lista;

            }
            
            listaAux = listaAux->proximo;
            
        }
        free(listaAux);
        listaAux = NULL;
        free(listaAux2);
        listaAux2 = NULL;

    }
 

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

tipoLista excluirMenor(tipoLista lista){
    int flag = 0;
    int valor;
    valor = menorLista(lista);
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
tipoLista search(tipoLista l, int x){
    tipoLista laux = l;
    if (l == NULL){
        printf("\nVazia\n");
        return l;
    }
    else{
        while (laux != NULL){
            if (laux->dado == x){
                printf("valor %d encontrado \n", laux->dado);
                return l;
            }
            laux = laux->proximo;
            
        }
        printf("valor %d não foi encontrado \n", x);
        free(laux);
        laux = NULL;
        return laux;

        
    }
    
}

tipoLista searchinsert(tipoLista l, int x){
    tipoLista laux = l;
    int flag = 0;
    int menor;
    
    if (l == NULL){
        printf("\nVazia\n");
        return l;
    }
    while (laux->proximo != NULL){
        laux = laux->proximo;
        if (laux->dado == x){
            flag = 1; //significa que o valor foi encontrado
        }
        
    }
    if (flag == 1){
        printf("\n o valor %d foi encontrado \n", x);
        return l;
    }
    else{
        menor = menorLista(l);
        l = inserirDirk(menor, l, x);
        return l;
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
        printf("\n 5 - search(l,x) \n");
        printf("\n 6 - searchinsert(tipoLista l, int x)\n");
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
            printf("search: \n");
            scanf("%d", &valor);
            search(lista, valor);
            break;
        
        case 6:
            printf("searchinsert: \n");
            scanf("%d", &valor);
            lista = searchinsert(lista, valor);
            break;

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}
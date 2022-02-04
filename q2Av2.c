#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tema{
    char nome[80];
    char descricao[400];
    struct tema *proximo;
    struct tema *anterior;
}*tipoLista;

//Seja uma lista encadeada cujos registros possuam informação do tipo inteiro. Escreva
//um programa que ordena a lista em ordem crescente em relação à informação.


tipoLista excluirMeio(char nome[80], tipoLista lista);
tipoLista inserirDirk(int valor, tipoLista lista, int valor_novo);
tipoLista inserirEsquerda(char nome[80], char descricao[400], tipoLista lista);
tipoLista inserirDireita(char nome[80], char descricao[400], tipoLista lista);
tipoLista criarNoh(char nome[80], char descricao[400]);
tipoLista excluirMenor(tipoLista lista);

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





tipoLista criarNoh(char nome[80], char descricao[400]){
    tipoLista novoNoh = (tipoLista) malloc(sizeof(tipoLista));
    if (novoNoh == NULL){
        printf("\n erro para criar noh\n");
        return NULL;
    }
    else{
        strcpy(novoNoh->nome, nome);
        strcpy(novoNoh->descricao, descricao);
        novoNoh->proximo = NULL;
        novoNoh->anterior = NULL;
        return novoNoh;
    }
    
}

tipoLista inserirEsquerda(char nome[80], char descricao[400], tipoLista lista){
    tipoLista novoNoh = criarNoh(nome, descricao);
    if (lista == NULL){
        return novoNoh;
    }
    else{
        lista->anterior = novoNoh;
        novoNoh->proximo = lista;
        return novoNoh;
    }
    
}

tipoLista inserirDireita(char nome[80], char descricao[400], tipoLista lista){
    tipoLista novoNoh = criarNoh(nome, descricao);

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

tipoLista excluirMeio(char nome[80], tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("\nLista vazia\n");
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
            
            
            if ((strcmp(nome, listaAux->nome)) == 0){
                    printf("\n ENTROUU 1 \n");
                    listaAux2 = listaAux->anterior;
                    listaAux2->proximo = listaAux->proximo;
                    listaAux = listaAux->proximo;
                    listaAux->anterior = listaAux2;
                    
                    printf("\n ENTROUU 2 \n");
                    return lista;
            }
            
            listaAux = listaAux->proximo;
            
        }
        free(listaAux);
        listaAux = NULL;
        free(listaAux2);
        listaAux2 = NULL;
        return lista;
        
    }

}



void pesquisar(char nome[80], tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("Lista vazia");
    }
    else{

        tipoLista listaAux = lista;
        while (listaAux != NULL){
            
            
            if ((strcmp(nome, listaAux->nome) == 0)){
                printf("\n nome: %s \n descricao: %s \n", listaAux->nome, listaAux->descricao);
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
            printf("[%s] ", listaAux->nome);
            listaAux = listaAux->proximo;
        }
        
    }
    printf("\n-----------------------------------\n");
    
}

tipoLista proximo(tipoLista lista){
    if (lista == NULL){
        printf("VAzia");
        return lista;
    }
    else{
        if (lista->proximo != NULL){
            lista = lista->proximo;
            printf("\n --> %s <-- \n", lista->nome);
            return lista;
        }
        else{
            printf("\nJa esta no final\n");
            return lista;
        }
        
        
    }
    
    
}

tipoLista anterior(tipoLista lista){
    if (lista == NULL){
        printf("VAzia");
        return lista;
    }
    else{
        if (lista->anterior != NULL){
            lista = lista->anterior;
            printf("\n --> %s <-- \n", lista->nome);
            return lista;
        }
        else{
            printf("\nJa esta no inicio\n");
            return lista;
        }
        
    }
    
}

int main(){
    int op = 11;
    char nome[80];
    char descricao[400];
    tipoLista lista = NULL;
    tipoLista listaMovel = NULL;


    while (op != 0){
        exibir(lista);
        printf("\n %d tamanho \n", tamanho(lista));
        printf("\n 1- inserir tema esquerda \n");
        printf("\n 2- inserir tema direita \n");
        printf("\n 3- ir para frente \n");
        printf("\n 4- ir para tras \n");
        printf("\n 5- exibir lista \n");
        printf("\n 6- pesquisar \n");
        printf("\n 7- excluir meio \n");
        printf("\n 8- Organizar \n");
        printf("\n 0- sair \n");
        printf("Digite: ");
        scanf("%d", &op);
        getchar();
        switch (op){
        case 1:
            printf("Nome: \n");
            scanf("%[^\n]", nome);
            getchar();
            printf("Descricao: \n");
            scanf("%[^\n]", descricao);
            lista = inserirEsquerda(nome, descricao, lista);
            break;
        case 2:
            printf("Nome: \n");
            scanf("%[^\n]", nome);
            getchar();
            printf("Descricao: \n");
            scanf("%[^\n]", descricao);
            lista = inserirDireita(nome, descricao, lista);
            break;
        case 3:
            printf("\n Mover para frente \n");
            lista = proximo(lista);
            break;
        case 4:
            printf("\n Mover para tras \n");
            lista = anterior(lista);
            break;    
        case 5:
            printf("Exibir \n");
            exibir(lista);
            break;
        case 6:
            printf("Pequisar: \n");
            printf("Nome: \n");
            scanf("%[^\n]", nome);
            getchar();
            pesquisar(nome, lista);
            break;
        case 7:
            printf("Excluir no meio: \n");
            printf("Nome: \n");
            getchar();
            scanf("%[^\n]", nome);
            lista =  excluirMeio(nome, lista);
            break;
       

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}
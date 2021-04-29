#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
}Lista;

Lista *inicializa(void);
Lista *inserir_inicio(Lista *lst, int valor);
void imprime_lista(Lista *lst);
Lista *busca(Lista *lst, int valor);
Lista *retira_elemento(Lista *lst, int valor);
void libera_lista(Lista *lst);


int main()
{
    Lista *lst;
    lst = inicializa();
    lst = inserir_inicio(lst, 1);
    lst = inserir_inicio(lst, 4);
    lst = inserir_inicio(lst, 6);
    lst = inserir_inicio(lst, 8);

    imprime_lista(lst);

    lst = busca(lst, 6);
    lst = busca(lst, 8);


    lst = retira_elemento(lst, 4);
    imprime_lista(lst);

    lst = retira_elemento(lst, 6);
    imprime_lista(lst);


    lst = inserir_inicio(lst, 7);
    lst = inserir_inicio(lst, 11);
    imprime_lista(lst);

    lst = busca(lst, 7);
    lst = busca(lst, 12);
    imprime_lista(lst);

    lst = inserir_inicio(lst, 20);
    imprime_lista(lst);

    lst = retira_elemento(lst, 7);
    imprime_lista(lst);

    libera_lista(lst);

    return 0;
}

//CRIAÇÃO DA LISTA
//RETORNA UMA LISTA VAZIA, COM O PONTEIRO APONTANDO PARA NULL
Lista *inicializa(void){
    return NULL;
}

//INSERE UM ELEMENTO NO INICIO DA LISTA
Lista *inserir_inicio(Lista *lst, int valor){
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->num = valor;
    novo->prox = lst;
    return novo;
}
//IMPRIME A LISTA
void imprime_lista(Lista *lst){
    printf("\n\n");
    Lista *p;
    for(p=lst;p != NULL; p=p->prox){
        printf("%d\n", p->num);
    }
}

//FAZ A BUSCA DE UM ELEMENTO NA LISTA
Lista *busca(Lista *lst, int valor){
    Lista *p;
    for(p = lst;p != NULL; p = p->prox){
        if(p->num == valor){
            printf("\nElemento %d encontrado\n", valor);
        }
    }

    return lst;
}

//RETIRA O ELEMENTO INFORMADO DA LISTA
Lista *retira_elemento(Lista *lst, int valor){
    Lista *ant = NULL;
    Lista *p = lst;

    while(p != NULL && p->num != valor){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        printf("\n\nO elemento informado nao foi encontrado na lista. O numero %d nao esta na lista. Logo, nao pode ser removido.\n", valor);
        return lst;
    }

    if(ant == NULL){
        lst = p->prox;
        printf("\n\nO elemento informado foi removido.\n");
        printf("O numero %d foi removido da lista.\n", valor);

    }
    else{
        ant->prox = p->prox;
        printf("\n\nO elemento informado foi removido.\n");
        printf("O numero %d foi removido da lista.\n", valor);
    }

    free(p);
    return lst;

}

//LIBERA TODOS OS ELEMENTOS DA LISTA

void libera_lista(Lista *lst){
    Lista *p = lst;
    Lista *t;
    while(p != NULL){
        t = p->prox;
        free(p);
        p=t;
    }
}

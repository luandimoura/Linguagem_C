#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
}Lista;

Lista *cria_lista(int valor);
Lista *insere_ordenado(Lista *lst, int valor);
void imprime(Lista *lst);
void contagem_elementos(Lista *lst);

int main()
{
    Lista *lst;
    lst = insere_ordenado(lst, 9);
    lst = insere_ordenado(lst, 5);
    lst = insere_ordenado(lst, 4);
    lst = insere_ordenado(lst, 11);

   imprime(lst);
   contagem_elementos(lst);


    return 0;
}

Lista *cria_lista(int valor){
    Lista *lst = (Lista *) malloc(sizeof(Lista));
    lst->num = valor;
    return lst;
}

Lista *insere_ordenado(Lista *lst, int valor){
    Lista *novo = cria_lista(valor);
    Lista *ant = NULL;
    Lista *p = lst;

    while(p != NULL && p->num < valor){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){
        novo->prox = lst;
        lst = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;

}

void imprime(Lista *lst){
    printf("\n");
    Lista *p;
    for(p=lst;p != NULL; p=p->prox){
        printf("%d\n", p->num);
    }
}

void contagem_elementos(Lista *lst){
    int cont = 0;
    Lista *p;
    for(p=lst; p != NULL;p = p->prox){
        cont++;
    }

    printf("\nA quantidade de elementos da lista e: %d\n", cont);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
    struct lista *ant;
}Lista;

Lista *cria_lista(void);
Lista *insere_elementos(Lista *lst, int valor);
void imprime(Lista *lst);
void libera(Lista *lst);


int main()
{
    int x;
    Lista *lst;
    lst = cria_lista();
    printf("Informe o valor inteiro: \n");
    scanf("%d", &x);
    lst = insere_elementos(lst, x);

    printf("Continue inserindo elementos, caso queira sair digite 1.\n");
    scanf("%d", &x);

    while(x != 1){
    lst = insere_elementos(lst, x);

    scanf("%d", &x);
    }

    imprime(lst);

    return 0;
}

Lista *cria_lista(void){
    return NULL;
}

Lista *insere_elementos(Lista *lst, int valor){
    Lista *novo =(Lista*) malloc(sizeof(Lista));
    novo->num = valor;

    if(lst == NULL){//LISTA VAZIA
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    //BUSCA A POSIÇÃO A SER INSERIDA
    Lista *p = lst;
    while(p != NULL && p->num < valor){
        p = p->prox;
    }

    if(p->num < valor){//INSERE DEPOIS
        novo->prox = p->prox;
        novo->ant = p;
        p->prox = novo;
        return lst;
    }
    else{//INSERE ANTES
        novo->prox = p;
        novo->ant =p->ant;
        p->ant = novo;

        if(novo->ant == NULL){
            return novo;
        }else{
            novo->ant->prox = novo;
            return lst;
        }
    }
}

void imprime(Lista *lst){
    Lista *p;
    for(p=lst; p!= NULL; p= p->prox){
        printf("%d\n", p->num);
    }
}

void libera(Lista *lst){
    Lista *p= lst;
    Lista *t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p=t;
    }

}



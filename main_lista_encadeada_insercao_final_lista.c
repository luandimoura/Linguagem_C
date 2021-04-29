#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
}Lista;


int main()
{
    Lista *list_inicio;
    Lista *list_prox;

    list_inicio =(Lista *) malloc(sizeof(Lista));
    list_prox = list_inicio;

    printf("Informe um valor inteiro para inserir na lista: \n");
    scanf("%d", &list_prox->num);

    printf("Caso queira parar de inserir elementos, digite 1\n");

    int valor;
    scanf("%d", &valor);

    while(valor != 1){

        list_prox->prox =(Lista*) malloc(sizeof(Lista));
        list_prox = list_prox->prox;
        list_prox->num = valor;

        scanf("%d", &valor);

    }

    list_prox->prox = NULL;

    printf("Lista de elementos\n");
    list_prox = list_inicio;
    while(list_prox != NULL){
        printf("%d\n", list_prox->num);
        list_prox = list_prox->prox;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define INICIO 0
#define MAXTAM 100

typedef struct{
    int chave;
}TItem;

typedef struct{
    TItem item[MAXTAM];
    int primeiro, ultimo;
}TLista;

void inicia_Lista(TLista *pLista);
int lista_Vazia(TLista *pLista);
int inserir_elemento(TLista *pLista, TItem x);
int remove_elemento(TLista *pLista, int p, TItem *px);
void imprimir_Lista(TLista *pLista);

int main()
{
    TLista lista;
    inicia_Lista(&lista);
    printf("VAZIA : %s\n", lista_Vazia(&lista) == 1 ? "SIM":"NAO");

    TItem item1, item2;
    item1.chave = 10;
    inserir_elemento(&lista, item1);
    item2.chave = 20;
    inserir_elemento(&lista, item2);

    imprimir_Lista(&lista);
    printf("VAZIA : %s\n", lista_Vazia(&lista) == 1 ? "SIM":"NAO");

    TItem item_removido;
    remove_elemento(&lista, 1, &item_removido);
    printf("Item removido: %d\n", item_removido.chave);
    imprimir_Lista(&lista);

    return 0;
}

void inicia_Lista(TLista *pLista){
    pLista->primeiro = INICIO;
    pLista->ultimo = pLista->primeiro;
}

int lista_Vazia(TLista *pLista){
    return pLista->ultimo == pLista->primeiro;
}

int inserir_elemento(TLista *pLista, TItem x){
    if(pLista->ultimo == MAXTAM)
        return 0; //LISTA CHEIA
    pLista->item[pLista->ultimo++] = x;
    return 1;
}

int remove_elemento(TLista *pLista, int p, TItem *px){
    if(lista_Vazia(pLista) || p >= pLista->ultimo)
        return 0;

    *px = pLista->item[p];
    int cont;
    for(cont = p+1; cont <= pLista->ultimo; cont++)
        pLista->item[cont - 1] = pLista->item[cont];
    pLista->ultimo--;
    return 1;
}

void imprimir_Lista(TLista *pLista){
    int i;
    printf("Itens da lista: \n");
    for(i = pLista->primeiro; i < pLista->ultimo; i++)
        printf("%d\n", pLista->item[i].chave);
}

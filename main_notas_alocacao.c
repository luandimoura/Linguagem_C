#include <stdio.h>
#include <stdlib.h>

void insere();

int main()
{
    insere();

    int opcao;
    printf("Deseja inserir mais um aluno? (1-SIM Outro-NAO\n");
    scanf("%d", &opcao);

    while(opcao == 1){
        insere();
        printf("Deseja inserir mais um aluno? (1-SIM Outro-NAO\n");
        scanf("%d", &opcao);
    }

    return 0;
}

void insere(){
    int i, quantidade;
    float *pnotas;
    float soma=0.0, media;

    printf("Informe a quantidade de notas que deseja inserir: ");
    scanf("%d", &quantidade);

    pnotas = (float *) malloc(sizeof(float) * quantidade);

    if(pnotas != NULL){
        for(i=0;i<quantidade; i++){
            scanf("%f", &pnotas[i]);
            soma +=pnotas[i];
        }
    }
    printf("As notas sao: \n");
    for(i=0; i<quantidade; i++){
        printf("%.2f\n", pnotas[i]);
    }
    media = soma/(float)quantidade;
    printf("A media e: %.2f\n", media);

}

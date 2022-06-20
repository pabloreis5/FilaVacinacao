#include <stdio.h>
#include <stdlib.h>

/*
ALUNO: Pablo Batista de Andrade Reis
MATRÍCULA: 20.1.8106
*/

typedef struct TPaciente{
    char nome[50];
    int idade;
    int grupo;
}TItem;

typedef struct Celula{
    TItem item;
    struct Celula* prox;
}TCelula;

typedef struct TFila{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
}TFila;

void FFVazia(TFila *fila);
int FVazia(TFila *fila);
int Enfileira(TFila *fila, TItem *item);
int Desenfileira(TFila *fila, TItem *item);




int main(){
    int opcao=1, cod, vacinas, vacinados=0;
    TFila f;
    TItem info;

    FFVazia(&f);
    printf("Quantidade disponivel de vacinas: ");
    scanf("%d", &vacinas);

    while(opcao == 1){
        printf("> Digite '1' para vacinar o proximo da fila OU '2' para inserir alguem na fila: ");
        scanf("%d", &cod);
        switch(cod){
            case(1):
                if(FVazia(&f)){
                    printf("\nA fila esta vazia...");
                    break;
                }else{
                    printf("\nMais um vacinado!");
                    Desenfileira(&f, &f.frente->item);
                    vacinados++;
                    vacinas--;
                    break;
                }


            case(2):
                if(vacinas == f.tamanho){
                    printf("\nLimite de vacinas ja atingindo...");
                    break;
                }else{
                    printf("\nQual nome do paciente: ");
                    fflush(stdin);
                    fgets(info.nome, 50, stdin);

                    printf("\nQual a idade do paciente: ");
                    scanf("%d", &info.idade);

                    printf("\n[0]- Nenhum deles | [1]- Idoso | [2]- Profissional da saude | \nPertence a algum grupo? Digite a opcao: ");
                    scanf("%d", &info.grupo);

                    Enfileira(&f, &info);
                    break;
                }

            default:
                printf("Opção inválida!");
                break;

        }

        printf("\n\n> DIGITE '1' PARA CONTINUAR OU '2' PARA ENCERRAR O PROGRAMA: ");
        scanf("%d", &opcao);
    }


    printf("\n\n**VACINACAO FINALIZADA**");
    printf("\n\t>TOTAL DE VACINADOS: %d", vacinados);
    printf("\n\t>VACINAS EM ESTOQUE: %d", vacinas);



    return 0;
}



void FFVazia(TFila *fila){
    fila->frente = (TCelula*) malloc(sizeof(TCelula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
    fila->tamanho=0;
}

int FVazia(TFila *fila){
    return (fila->frente == fila->tras);
}

int Enfileira(TFila *fila, TItem *item){
    TCelula *pNovo;
    pNovo = (TCelula*) malloc(sizeof(TCelula));
    if(pNovo == NULL){
        return 0;
    }
    fila->tras->prox = pNovo;
    fila->tras = pNovo;
    pNovo->item = *item;
    pNovo->prox = NULL;
    fila->tamanho++;
    return 1;
}

int Desenfileira(TFila *fila, TItem *item){
    TCelula *pAux;
    if(FVazia(fila)){
        return 0;
    }
    pAux = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free(pAux);
    fila->tamanho--;
    return 1;
}

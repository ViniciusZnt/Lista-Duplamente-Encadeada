#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int n;
    struct lista* anter;
    struct lista* prox;
} LISTA;

LISTA* inicio = NULL;
LISTA* fim = NULL;
LISTA* l;
LISTA* aux;

void entrada();
void listadupla(int num);
void mostrarLista();
void liberarLista();
void acharLista();
LISTA* avancar(LISTA* atual);
LISTA* voltar(LISTA* atual);


int main(void) {
    entrada();
    liberarLista(); // Libera a memória antes de encerrar o programa
    return 0;
}

void entrada() {
    int op, entrada;
    do {
        printf("Digite uma opção:\n");
        printf("0 - Sair\n");
        printf("1 - Inscrever numero na lista\n");
        printf("2 - Achar elemento da lista e navegar\n");
        printf("3 - Liberar Lista\n");
        printf("4 - Mostrar lista\n");
        scanf("%d", &op);
        if (op == 1) {
            printf("Digite o numero a ser adicionado: ");
            scanf("%d", &entrada);
            fflush(stdin);
            listadupla(entrada);
        } else if (op == 2){
        	acharLista();
		} else if (op ==3){
			liberarLista();
		} else if (op == 4){
            mostrarLista();
        }
    } while (op != 0);
}

void listadupla(int num) {
    l = (LISTA*) malloc(sizeof(LISTA));
    if (l == NULL) {
        printf("Erro de alocação de memoria.\n");
        exit(1); 
    }
    l->n = num;
    if (inicio == NULL) {
        inicio = l;
        fim = l;
        aux = l;
        l->prox = NULL;
        l->anter = NULL;
    } else {
        l->prox = inicio;
        l->anter = NULL;
        inicio->anter = l;
        inicio = l;
    }
}

void mostrarLista() {
    LISTA* atual = inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->n);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarLista() {
    LISTA* atual = inicio;
    while (atual != NULL) {
        LISTA* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void acharLista() {
    int op2, ele;

    printf("Qual elemento da sequencia deseja? ");
    scanf("%i", &ele);
    LISTA* atual = inicio;
    for (int i = 0; i <= ele; i++) {
        if (i == ele) {
            do {
                printf("O elemento %i eh %i\n", i, atual->n);
                printf("Avancar elemento: Teclar 1\n"
                       "Voltar elemento: Teclar 2\n"
                       "Sair: Teclar 0\n");
                scanf("%i", &op2);
                switch (op2) {
                    case 1:
                        atual = avancar(atual);
                        break;
                    case 2:
                        atual = voltar(atual);
                        break;
                    default:
                        printf("Fora das opçoes\n");
                        break;
                }
            } while (op2 != 0);
        }
        atual = avancar(atual);
    }
}


LISTA* avancar(LISTA* atual) {
    if (atual != NULL) {
        return atual->prox;
    }
    return NULL;  
}


LISTA* voltar(LISTA* atual) {
    if (atual != NULL) {
        return atual->anter;
    }
    return NULL;
}

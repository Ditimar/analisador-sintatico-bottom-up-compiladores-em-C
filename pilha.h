/* Estrutura do Nó */

struct Node{
    int topo;
    struct Node *prox;
};

typedef struct Node node;

int tam;

/* Inicia a Pilha */
void inicia(node *PILHA) {
    PILHA->prox = NULL;
    tam=0;
}

/* Verifica se a pilha esta vazia */
int vazia(node *PILHA) {
    if(PILHA->prox == NULL)
        return 1;
    else
        return 0;
}

/* Exibe a pilha */
void exibe(node *PILHA) {
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = PILHA->prox;
    printf("PILHA:");
    while( tmp != NULL){
        printf("%d ", tmp->topo);
        tmp = tmp->prox;
    }
}

/* Incrementa um valor no topo da pilha */
void push(node *PILHA, int estado) {
    node *novo=(node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        novo->topo = estado;
    }

    novo->prox = NULL;

    if(vazia(PILHA))
        PILHA->prox=novo;
    else{
        novo->prox = PILHA->prox;
        PILHA->prox = novo;
    }
    tam++;
}

/* Remove o topo da pilha */
void pop(node *PILHA) {
    if(PILHA->prox == NULL)
        printf("PILHA ja vazia\n\n");
    else{
        node *tmp = PILHA->prox;
        PILHA->prox = tmp->prox;
        free(tmp);
        tam--;
    }
}

//Retorna o topo da pilha
int top(node *PILHA){
    return PILHA->prox->topo;
}

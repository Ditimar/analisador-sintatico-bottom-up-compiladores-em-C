int verificador = 0;

void valorAcao(int a[12][6]){
    int i, j;
    int b[12][6]={{5,  0,  0, 4,  0,  0},
                  {0,  6,  0, 0,  0, 100},
                  {0, -2,  7, 0, -2, -2},
                  {0, -4, -4, 0, -4, -4},
                  {5,  0,  0, 4,  0,  0},
                  {0, -6, -6, 0, -6, -6},
                  {5,  0,  0, 4,  0,  0},
                  {5,  0,  0, 4,  0,  0},
                  {0,  6,  0, 0, 11,  0},
                  {0, -1,  7, 0, -1, -1},
                  {0, -3, -3, 0, -3, -3},
                  {0, -5, -5, 0, -5, -5}};

    for(i = 0; i < 12; i++)
        for(j = 0; j < 6; j++)
            a[i][j] = b[i][j];
    if(verificador){
        printf("-----------------------------------\n");
        printf("Matriz Acao: \n");
        for(i = 0; i < 12; i++)
            printf("%2d %5d %5d %5d %5d %5d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
    }
}

void valorGramatica(int a[7]){
    int i;
    char gramatica[7]={0, 3, 1, 3, 1, 3, 1};

    for(i = 0; i < 7; i++)
        a[i] = gramatica[i];

    if(verificador){
        printf("-----------------------------------\n");
        printf("Gramatica:\n");
        for(i = 1; i < 7; i++)
            printf("%d\n", a[i]);
    }
}

void valorDesvio(int a[12][3]){
    int i, j;
    int desvio[12][3]={{1, 2, 3},
                       {0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0},
                       {8, 2, 3},
                       {0, 0, 0},
                       {0, 9, 3},
                       {0, 0, 10},
                       {0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};


    for(i = 0; i < 12; i++)
        for(j = 0; j < 3; j++)
            a[i][j] = desvio[i][j];

    if(verificador){
        printf("-----------------------------------\n");
        printf("Matriz Desvio:\n");
        for(i = 0; i < 12; i++)
            printf("%2d %4d %4d\n", desvio[i][0],desvio[i][1],desvio[i][2]);
        printf("-----------------------------------\n");
    }
}

int convert(char exp){
    switch(exp){
        case 'N':
            return 0;
        case '+':
            return 1;
        case '*':
            return 2;
        case '(':
            return 3;
        case ')':
            return 4;
        case '$':
            return 5;
        default:
            printf("\n\nSimbolo desconhecido!\n\n");
            exit(1);
    }
}


/* Remove espaços da expressao */
void remove_esp(char str[]) {
    int i, j = 0, tam = strlen(str);

    for(i=0; i<tam; i++)
        if(str[i] != ' ')
            str[j++] = str[i];

    str[j] = '\0';
}

void changeA2N(char expressao[]){
    int i = 0;

    while(expressao[i]){
        if(expressao[i] >= '0' && expressao[i] <= '9')
            expressao[i] ='N';
        i++;
    }
}

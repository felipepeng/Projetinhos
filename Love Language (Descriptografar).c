#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char keyword[MAX_LEN];
char phrase[MAX_LEN];
char continuar;


void decrypt(char *text, const char *keyword) {
    int text_len = strlen(text);
    int keyword_len = strlen(keyword);
    int i;

    for (i = 0; i < text_len; i++) {
        int keyword_index = i % keyword_len;
        int shift = keyword[keyword_index] - 'a';
        
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (((text[i] - 'a' - shift) + 26) % 26) + 'a';
        }
    }
}

void quebra_linha(){
    // Remover a quebra de linha inserida pelo fgets, se houver
    size_t len = strlen(phrase);
    if (phrase[len - 1] == '\n') {
        phrase[len - 1] = '\0';
    }
}

void inserir_dados(){
    printf("Digite a chave: ");
    scanf("%s", keyword);

    printf("Digite a frase: ");
    getchar(); // Limpa o buffer
    fgets(phrase, MAX_LEN, stdin);
    quebra_linha(); // Remover a quebra de linha inserida pelo fgets, se houver
}

int main() {
    while(!(continuar=='n' || continuar=='N')){

        printf("=================L O V E  L A N G U A G E=================\n");
        inserir_dados();
        

        printf("\n");
        printf("----------------------------------------------------------\n");


        decrypt(phrase, keyword);
        printf("Resultado: %s\n", phrase);


        printf("\n\nUsar o Programa de novo? (S/N)  ");
        scanf("%c", &continuar);
        fflush(stdin);

        while(!(continuar=='s' || continuar=='S' || continuar=='n' || continuar=='N')){
            printf("Escolha invalida! (S/N)  ");
            scanf("%c", &continuar);
            fflush(stdin);
        }
        if(continuar=='s' || continuar=='S'){
            system("cls");
        }

    }
    return 0;
}

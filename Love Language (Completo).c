#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char keyword[MAX_LEN];
char phrase[MAX_LEN];
int tela=0;
char fechar='s';

void encrypt(char *text, const char *keyword) {
    int text_len = strlen(text);
    int keyword_len = strlen(keyword);
    int i;

    for (i = 0; i < text_len; i++) {
        int keyword_index = i % keyword_len;
        int shift = keyword[keyword_index] - 'a';
        
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

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

    while(fechar=='s' || fechar=='S'){
        printf("=================L O V E  L A N G U A G E=================\n");
        printf("1- Encriptografar \n2- Desencriptografar\n");
        printf("\nSelecione (1-2): ");
        scanf("%d", &tela);

        if(tela==1){ // Encriptografar
            system("cls");
            printf("=================E N C R I P T=================\n");
            //printf("_E N C R I P T_\n\n");
            inserir_dados();

            printf("\n");
            printf("-----------------------------------------------\n");

            encrypt(phrase, keyword);
            printf("Frase criptografada: %s\n", phrase);
        }
        else if(tela==2){ // Desencriptografar
            system("cls");
            printf("=================D E S E N C R I P T=================\n");
            //printf("D E S E N C R I P T\n");
            inserir_dados();

            printf("\n");
            printf("-----------------------------------------------------\n");

            decrypt(phrase, keyword);
            printf("Frase descriptografada: %s\n", phrase);
        }

        printf("\n\nUsar o Programa de novo? (S/N)  ");
        scanf("%c", &fechar);
        fflush(stdin);

        while(!(fechar=='s' || fechar=='S' || fechar=='n' || fechar=='N')){
            printf("Escolha invalida! (S/N)  ");
            scanf("%c", &fechar);
            fflush(stdin);
        }
        if(fechar=='s' || fechar=='S'){
            system("cls");
        }
    }

    return 0;
}

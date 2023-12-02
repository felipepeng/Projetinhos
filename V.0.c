#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Variáveis Globais
int n;
char key[25], frase[1000];
int i, soma=0;
//============================================================================================
void inserir_dados(){
    printf("======L O V E  L A N G U A G E======\n");
    printf("Digite a Chave: ");
    gets(key);

    /* if(strcmp(key, "lemon pie")==0){
        printf("B A T A T A");
    } */

    printf("Digite a Frase Criptografada:\n- ");
    gets(frase);
}
//--------------------------------------------------------------------------------------------
void chave(int qntKey){
    int asci;
    //Palavra Chave
    for(i=0; i<qntKey; i++){
        asci=key[i];
        soma+=asci;
    }
    soma=soma/qntKey;

    while(soma>25){
        soma=(soma)-25;
    }

    printf("Soma Chave: %d\n", soma);
}
//--------------------------------------------------------------------------------------------
void criptografar(){
    printf("============================================================================");
    int qntFrase=strlen(frase), fraseInt;
    
    printf("\nFrase Criptografada: \n");


    for(i=0; i<qntFrase; i++){
        //Frase Criptografada
        fraseInt=frase[i]+soma;

        if(fraseInt>122){
            fraseInt=97+i;
        }
        
        /*if(frase[i]==32){
            fraseInt=97+i;
        } */
        

        //Printar Frase Criptograda
        //printf("%c", fraseInt);
        printf("- %d\n", fraseInt);
    }
}// Criptografar
//--------------------------------------------------------------------------------------------
void descriptografar(){
    int qntFrase=strlen(frase), fraseInt;

    printf("\nFrase Descriptografada: \n");

    for(i=0; i<qntFrase; i++){

        //Frase Descriptografada
        fraseInt=frase[i]-soma;

        if(fraseInt<97){
            fraseInt=122-i;
        }

        //Printar Frase Descriptografada
        printf("%c", fraseInt);
        //printf("- %d\n", fraseInt);
    }
} //Descriptografar
//--------------------------------------------------------------------------------------------
void descriptografarGPT(){
    int qntFrase = strlen(frase);

    printf("\nFrase Descriptografada: \n");

    for(i = 0; i < qntFrase; i++){
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            int offset = key[i % strlen(key)] - 'a';
            char decrypted = 'a' + ((frase[i] - 'a' - offset + 26) % 26);
            printf("%c", decrypted);
        } else {
            printf("%c", frase[i]); // Mantém caracteres que não são letras inalterados
        }
    }
    printf("\n");
}
//============================================================================================
int main(){
    inserir_dados();
    chave(strlen(key));
    criptografar();
    printf("\n\n");
    descriptografar();
    

}
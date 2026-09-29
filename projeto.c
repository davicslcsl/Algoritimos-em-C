#include <stdio.h>
#include <stdbool.h>

int main() {
    int vetor[10];
    int  fun,e, i, temp,quantidade;
    
    quantidade = 0;
    fun = 0;
 while(fun != 5){ 
    char resp = 's';
    printf("\n1 - Criar");
    printf("\n2 - Encotrar");
    printf("\n3 - Trocar");
    printf("\n4 - Apagar");
    printf("\n5 - Sair");
    printf("\ndigite o numero para realizar a acao: ");
    scanf(" %i", &fun);
    //Criar
    if (fun == 1) {
    while (resp == 's' || resp =='S')
    {
        if (quantidade <10 ){
        printf("digite o numero a ser preenchido na posicao %i : ", quantidade);
        scanf(" %d",&vetor[quantidade]);
        quantidade+=1;
     while(1)
     {
         printf("\ndeseja preencher outra? (s/n): ");
        scanf(" %c", &resp);
         if (resp == 's' || resp =='S'){
            printf("\n");
            break;
         }
         if (resp == 'n' || resp =='N'){
            printf("\n");
            break;
         }
         else {
            printf("digitacao invalida, escreva novamente\n\n");
         }
     }
        }
         if (quantidade >= 10 ){
            printf("A quantidade limite de elementos foi atingida\n\n");
            resp = 'n';
        }
    }
    }

    //Encontrar
    if (fun == 2) {
     while (resp == 's' || resp =='S')
    {
        temp =0;
        printf("digite o elemento que voce deseja encontrar: ");
        scanf(" %i",&e);
        printf("\n");
        for (i=0; i < quantidade+1; i++ ){
            if (vetor[i] == e){
                printf("o valor %i foi encontrado na posicao %i \n",  e, i);
                temp+=1;
                
            }
        }
        if (temp ==0){
            printf("elemento nao encontrado\n");
        }
        printf("\ndeseja encontrar outro? (s/n): ");
        scanf(" %c", &resp);
        if (resp == 's' || resp =='S'){
            printf("\n");
        }
        else if (resp == 'n' || resp =='N'){
            printf("\n");
        }
        else {
            resp = 's';
            printf("digitacao invalida, escreva novamente\n\n");
        }
    }
    }
    //Trocar
    if (fun == 3) {
     while (resp == 's' || resp =='S')
    {
        temp =0;
        printf("digite a posiçao do elemento que voce deseja trocar:(0 a %i) ", quantidade);
        scanf(" %i",&e);
        for (i=0; i< quantidade+1; i++ ){
            if (i == e){
                printf("o valor %i foi encontrado na posicao %i ",  vetor[e], i);
                printf("deseja troca-lo por qual valor: ");
                scanf(" %d",&vetor[i]);
                temp+=1;
            }
        }
        if (temp ==0){
            printf("elemento nao encontrado");
        }
        printf("deseja trocar outro? (s/n): ");
        scanf(" %c", &resp);
        if (resp == 's' || resp =='S'){
            printf("\n");
        }
        else if (resp == 'n' || resp =='N'){
            printf("\n");
        }
        else {
            resp = 's';
            printf("digitacao invalida, escreva novamente\n\n");
        }
    }
    }
    //Apagar
    if (fun == 4) {
    char resp2 ='s';
    resp = 's';
     while (resp == 's' || resp =='S')
    {
        temp =0;
        while (resp2 == 's' || resp2 =='S'){
        printf("voce deseja apagar o ultimo elemento? (s/n): ");
        scanf(" %c", &resp2);
        if (resp2 == 's' || resp2 =='S'){
            vetor[quantidade] = 0;
            quantidade -=1;
            printf("o ultimo elemento foi apagado");
        }
        else if (resp2 == 'n' || resp2 =='N'){
            printf("\n");
        }
        else {
            resp2 = 's';
            printf("digitacao invalida, escreva novamente\n\n");
        }
        }
        
        if (temp ==0){
            printf("vetor vazio");
        }
        printf("deseja apagar novamente? (s/n): ");
        scanf(" %c", &resp);
        if (resp == 's' || resp =='S'){
            printf("\n");
        }
        else if (resp == 'n' || resp =='N'){
            printf("\n");
        }
        else {
            resp = 's';
            printf("digitacao invalida, escreva novamente\n\n");
        }
    }
    }
 
}
    // sair
    if (fun == 5) {
        printf("\nate mais...");
    }
return 0;
}    

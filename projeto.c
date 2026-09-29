#include <stdio.h>


int main() {
    int quartos[10];
    int  e, i, temp,quantidade;
    char resp = 's';
    quantidade = 0;
 while(1){
    int fun;
    printf("======== Hotel ========");
    printf("\n1 - Realizar hospedagem");
    printf("\n2 - Consultar quartos");
    printf("\n3 - Alterar hospedagem");
    printf("\n4 - encerrar hospedagem");
    printf("\n5 - Sair");
    printf("\ndigite o numero para realizar a acao: ");
    scanf(" %i", &fun);
    //Criar
    if (fun == 1) {
    while (resp == 's' || resp =='S')
    {
        if (quantidade <10 ){
        printf("digite o numero a ser preenchido na posicao %i : ", quantidade);
        scanf(" %d",&quartos[quantidade]);
        quantidade+=1;
        
        printf("\ndeseja preencher outra? (s/n): ");
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
        else{
            printf("A quantidade limite de elementos foi atingida\n\n");
            resp = 'n';
        }
    }

    //Encontrar
    if (fun == 2) {
    resp = 's';
     while (resp == 's' || resp =='S')
    {
        temp =0;
        printf("digite o elemento que voce deseja encontrar:  ");
        scanf(" %i",&e);
        for (i=0; i < quantidade+1; i++ ){
            if (quartos[i] == e){
                printf("o valor %i foi encontrado na posicao %i ",  e, i+1);
                temp+=1;
                
            }
        }
        if (temp ==0){
            printf("elemento nao encontrado");
        }
        printf("deseja encontrar outro? (s/n): ");
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
    resp = 's';
     while (resp == 's' || resp =='S')
    {
        temp =0;
        printf("digite a posiçao do elemento que voce deseja trocar:(0 a %i) ", quantidade);
        scanf(" %i",&e);
        for (i=0; i< quantidade+1; i++ ){
            if (i == e){
                printf("o valor %i foi encontrado na posicao %i ",  quartos[e], i);
                printf("deseja troca-lo por qual valor: ");
                scanf(" %d",&quartos[i]);
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
            for (i=10; i> 0; i--){
                if(quartos[i] != 0){
                    quartos[i] =0;
                    i = -1;
                    temp=1;
                    printf("elemnto apagado \n");
                }
            }
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
            printf("quartos vazio");
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
    // sair
    if (fun == 5) {}
 }
   return 0;
}
}    

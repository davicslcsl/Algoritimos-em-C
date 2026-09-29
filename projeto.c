#include <stdio.h>
#include <stdbool.h>

int main() {
    int quartos[10];
    int  fun,numero,e, i,diaria, temp,quantidade;
    
    quantidade = 0;
    fun = 0;
 while(fun != 5){ 
    char resp = 's';

    printf("\n======== Hotel ========\n");
    printf("1 - Realizar hospedagem\n");
    printf("2 - Consultar quartos\n");
    printf("3 - Alterar hospedagem\n");
    printf("4 - Encerrar hospedagem\n");
    printf("5 - Sair\n");
    printf("Digite o numero para realizar a acao: ");
    scanf(" %i", &fun);
    //Criar
   if (fun == 1) {
            resp = 's';

            while (resp == 's' || resp == 'S') {

                printf("\nDigite o numero do quarto (1 a 10): ");

                if (scanf("%d", &numero) == 1) {
                    if (numero >= 1 && numero <= 10) {
                        if (quartos[numero - 1] == 0) {
                            printf("Digite a quantidade de diarias: ");
                            if (scanf("%d", &diaria) == 1) {
                                if (diaria > 0) {
                                    quartos[numero - 1] = diaria;
                                    printf("Hospedagem realizada com sucesso\n");
                                }
                                else {
                                    printf("A quantidade de diarias deve ser maior que 0.\n");
                                }
                            }
                            else {
                                printf("Quantidade de diarias invalida.\n");
                            }
                        }
                        else {
                            printf("Esse quarto ja esta ocupado.\n");
                        }
                    }
                    else {
                        printf("Quarto inexistente.\n");
                    }
                }
                else {
                    printf("Digite um numero inteiro.\n");
                }

                printf("Deseja realizar outra hospedagem? (s/n): ");
                scanf(" %c", &resp);

                if (resp == 's' || resp == 'S') {
                    printf("\n");
                }
                else if (resp == 'n' || resp == 'N') {
                    printf("\n");
                }
                else {
                    printf("Digitacao invalida.\n");
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
            if (quartos[i] == e){
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
            quartos[quantidade] = 0;
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
 
}
    // sair
    if (fun == 5) {
        printf("\nate mais...");
    }
return 0;
}    

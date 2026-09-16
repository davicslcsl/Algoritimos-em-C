#include <stdio.h>

int main()
{
    char resposta = 'S';
    int vezes = -1;
    int n, i;
 // Estrutura principal do codigo
  while (resposta=='S' || resposta=='s') { 
    vezes = vezes + 1;
    float notatotal=0;
    float media[vezes+1];
    char medial[vezes+1];
    while (1) {
     printf("quantas notas você vai calcular na %iª media? max(10): ", vezes+1);
     scanf(" %i", &n);
     if (n>0 && n<=10) {
      break;
     }
     else{
         printf("Quantidade invalida, digite novamente...\n");
     }
    }
    float notas[n];
    
    // Leitor de notas
    for (int i=0; i<n; i++) {
     printf("qual a %iª nota, entre 0 e 10: ", i+1);
     scanf(" %f", &notas[i]);
     if (0>notas[i] || notas[i]>10) {
         i = i-1;
         printf("nota invalida digite novamente\n\n");
     }
    }
    
    // Calculo da media
     for (int i=0; i<n; i++) {
     notatotal = notatotal+notas[i];
    }
    media[vezes]= notatotal/n;
    
    // Condiçao de nota em letra
    if (media[vezes] >= 9) {
     medial[vezes] = 'A';
    } 
    else if (media[vezes] >= 8) {
     medial[vezes] = 'B';
    } 
    else if (media[vezes] >= 7) {
     medial[vezes] = 'C';
    } 
    else if (media[vezes] >= 6) {
     medial[vezes] = 'D';
    } 
    else if (media[vezes] < 6) {
     medial[vezes] = 'E';
    } 
    
    // demonstraçao de nota e media
     if (n != 0){
     printf("\nA %iª média é %.2f \n", vezes+1, media[vezes]);
     printf("Nota: %c\n\n" ,medial[vezes]);
     }
     
    // condiçao de parada
     int temp = 0;
     while (temp==0) {
      printf("deseja calcular mais uma média? (S/N): ");
      scanf(" %c", &resposta);
        if (resposta == 'S' || resposta=='s'){
         printf("Mais uma rodada entao...\n\n");
         temp=1;
        }
         else if (resposta == 'N' || resposta=='n'){
          printf("Foi bom enquanto durou, ate mais...\n\n");
          printf("Voce calculou a media %i vezes, aqui estao as medias e notas de cada uma:\n", vezes+1);
          for (int i=0; i<=vezes; i++){
           printf("%iª média e nota: %.2f | %c \n", i+1, media[i], medial[i]); 
          }
          temp=1;
         } 
          else {
           printf("Digitaçao invalida escreva novamente.\n\n");
          } 
     }
  }
    printf("Agora é sério, até nunca mais ...");
    
    return 0;
}

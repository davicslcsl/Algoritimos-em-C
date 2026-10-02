#include <stdio.h>
#include <stdbool.h>

int main() {
	int quartos[10];
	int  opcao , numero, encontra, i ,diaria , temp,quantidade;
	quantidade = 0;
	opcao = 0;
	for (i = 0; i < 10; i++) {
		quartos[i] = 0;
	}
	while(opcao != 5) {
		char resp = 's';

		printf("\n======== Hotel ========\n");
		printf("1 - Realizar hospedagem\n");
		printf("2 - Consultar quartos\n");
		printf("3 - Alterar hospedagem\n");
		printf("4 - Encerrar hospedagem\n");
		printf("5 - Sair\n");
		printf("Digite o numero para realizar a ação: ");
		scanf(" %i", &opcao);
		//Criar
		if (opcao == 1) {
			resp = 's';

			while (resp == 's' || resp == 'S') {

				printf("\nDigite o numero do quarto (1 a 10): ");

				if (scanf(" %d", &numero) == 1) {
					if (numero >= 1 && numero <= 10) {
						if (quartos[numero - 1] == 0) {
							printf("Digite a quantidade de diarias: ");
							if (scanf(" %d", &diaria) == 1) {
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

		//Consultar
		if (opcao == 2) {
			int op;
			int encontrou = 0;

			printf("\n--- Consultar quartos ---\n");
			printf("1 - Exibir todos os quartos\n");
			printf("2 - Exibir somente quartos vazios\n");
			printf("3 - Exibir somente quartos ocupados\n");
			printf("Escolha: ");
			scanf(" %d", &op);
			printf("\n");

			if (op == 1) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] > 0) {
						printf("Quarto %2d: OCUPADO (%d diaria(s))\n", i + 1, quartos[i]);
					}
					else {
						printf("Quarto %2d: vazio\n", i + 1);
					}
				}
			}
			else if (op == 2) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] == 0) {
						printf("Quarto %2d: vazio\n", i + 1);
						encontrou = 1;
					}
				}
				if (!encontrou) {
					printf("Nao ha quartos vazios.\n");
				}
			}
			else if (op == 3) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] > 0) {
						printf("Quarto %2d: OCUPADO (%d diaria(s))\n", i + 1, quartos[i]);
						encontrou = 1;
					}
				}
				if (!encontrou) {
					printf("Nao ha quartos ocupados.\n");
				}
			}
			else {
				printf("Opcao invalida.\n");
			}
		}

		//Trocar
		if (opcao == 3) {
			resp = 'N';
			for (i = 0; i < 10; i++) {
				if (quartos[i] != 0) {
					resp = 's';
					i = 10;
				}
			}
			if (resp == 'N') {
				printf("\nTodos os quartos estÃ£o desocupados");
			}
			while (resp == 's' || resp =='S')
			{
				temp = 0;
				printf("digite o quarto que deseja alterar a diaria, (1 a 10): ");
				scanf(" %i",&encontra);
				for (i=0; i< 10; i++ ) {
					if (i == encontra-1) {
						if (quartos[i] > 0) {
							printf("o quarto %i estÃ¡ reservado com %i diarias \n",  encontra, quartos[i]);
							printf("gostaria de trocar para quantas?: ");
							if (scanf(" %d", &diaria) == 1) {
								if (diaria > 0) {
									quartos[i] = diaria;
									printf("troca realizada com sucesso\n");
									printf("Agora o quarto %i estÃ¡ reservado com %i diarias \n", encontra, quartos[i]);
								}
								else {
									printf("A quantidade de diarias deve ser maior que 0.\n");
								}
							}
							else {
								printf("Quantidade de diarias invalida.\n");
							}
							temp+=1;
						}
						else {
							printf("O quarto estÃ¡ desocupado.\n");
							temp+=1;
						}
					}
				}
				if (temp == 0) {
					printf("quarto inexistente, a apenas 10 quartos.\n");
				}
				printf("\nDeseja alterar outra hospedagem? (s/n): ");
				scanf(" %c", &resp);
				if (resp == 's' || resp =='S') {
					printf("\n");
				}
				else if (resp == 'n' || resp =='N') {
					printf("\n");
				}
				else {
					resp = 's';
					printf("digitacao invalida, escreva novamente\n\n");
				}
			}
		}
		//Apagar
		if (opcao == 4) {
			char resp2 ='s';
			resp = 'N';
			for (i = 0; i < 10; i++) {
				if (quartos[i] != 0) {
					resp = 's';
					i = 10;
				}
			}
			if (resp == 'N') {
				printf("\nTodos os quartos estÃ£o desocupados");
			}
			while (resp == 's' || resp =='S')
			{
				temp =0;
				printf("Qual quarto deseja encerrar a hospedagem, (1 a 10): ");
				scanf(" %i",&encontra);
				for (i=0; i< 10; i++ ) {
					if (i == encontra-1) {
						if (quartos[i] > 0) {
							printf("O quarto %i estÃ¡ reservado com %i diarias \n",  encontra, quartos[i]);
							printf("Gostaria de encerrar esta hospedagem?: ");
							scanf(" %c", &resp2);
							if (resp2 == 'S' || resp2 == 's') {
								quartos[i] = 0;
								printf("Foi encerrado a hospedagem do quarto %i \n", encontra);
								temp+=1;
							}
							else if (resp2 == 'N' || resp2 == 'n') {
								printf("Foi cancelado o encerramento da hospedagem\n");
								temp+=1;
							}
							else {
								printf("Digitacao invalida...\n\n");
								temp+=1;
							}

						}
						else {
							printf("O quarto estÃ¡ desocupado.\n");
							temp+=1;
						}
					}
				}

				if (temp ==0) {
					printf("quarto inexistente, a apenas 10 quartos.\n");
				}
				printf("\ndeseja apagar outra hospedagem? (s/n): ");
				scanf(" %c", &resp);
				if (resp == 's' || resp =='S') {
					printf("\n");
				}
				else if (resp == 'n' || resp =='N') {
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
	if (opcao == 5) {
		printf("\nAte mais...");
	}
	return 0;
}

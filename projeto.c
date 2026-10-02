#include <stdio.h>

int main() {
	int quartos[10];
	int opcao, numero, encontra, i, diaria, temp;
	opcao = 0;
	for (i = 0; i < 10; i++) {
		quartos[i] = 0;
	}
	while (opcao != 5) {
		char resp = 's';
		char lixo;

		printf("\n======== Hotel ========\n");
		printf("1 - Realizar hospedagem\n");
		printf("2 - Consultar quartos\n");
		printf("3 - Alterar hospedagem\n");
		printf("4 - Encerrar hospedagem\n");
		printf("5 - Sair\n");
		printf("Digite o número para realizar a ação: ");
		if (scanf("%d", &opcao) != 1) {
			lixo = 'a';
			while (lixo != '\n') {
				scanf("%c", &lixo);
			}
			printf("\nDigite um número de 1 a 5.\n");
			opcao = 0;
		}

		//Criar
		if (opcao == 1) {
			resp = 's';

			while (resp == 's' || resp == 'S') {

				printf("\nDigite o número do quarto (1 a 10): ");

				if (scanf("%d", &numero) == 1) {
					if (numero >= 1 && numero <= 10) {
						if (quartos[numero - 1] == 0) {
							printf("Digite a quantidade de diárias: ");
							if (scanf("%d", &diaria) == 1) {
								if (diaria > 0) {
									quartos[numero - 1] = diaria;
									printf("Hospedagem realizada com sucesso\n");
								}
								else {
									printf("A quantidade de diárias deve ser maior que 0.\n");
								}
							}
							else {
								lixo = 'a';
								while (lixo != '\n') {
									scanf("%c", &lixo);
								}
								printf("Quantidade de diárias inválida.\n");
							}
						}
						else {
							printf("Esse quarto já está ocupado.\n");
						}
					}
					else {
						printf("Quarto inexistente.\n");
					}
				}
				else {
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					printf("Digite um número inteiro.\n");
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
					printf("Digitação inválida.\n");
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
			if (scanf("%d", &op) != 1) {
				lixo = 'a';
				while (lixo != '\n') {
					scanf("%c", &lixo);
				}
				op = 0;
			}
			printf("\n");

			if (op == 1) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] > 0) {
						printf("Quarto %d: OCUPADO (%d diária(s))\n", i + 1, quartos[i]);
					}
					else {
						printf("Quarto %d: vazio\n", i + 1);
					}
				}
			}
			else if (op == 2) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] == 0) {
						printf("Quarto %d: vazio\n", i + 1);
						encontrou = 1;
					}
				}
				if (encontrou == 0) {
					printf("Não há quartos vazios.\n");
				}
			}
			else if (op == 3) {
				for (i = 0; i < 10; i++) {
					if (quartos[i] > 0) {
						printf("Quarto %d: OCUPADO (%d diária(s))\n", i + 1, quartos[i]);
						encontrou = 1;
					}
				}
				if (encontrou == 0) {
					printf("Não há quartos ocupados.\n");
				}
			}
			else {
				printf("Opção inválida.\n");
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
				printf("\nTodos os quartos estão desocupados\n");
			}
			while (resp == 's' || resp == 'S')
			{
				temp = 0;
				printf("digite o quarto que deseja alterar a diária, (1 a 10): ");
				if (scanf("%d", &encontra) != 1) {
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					encontra = 0;
				}
				for (i = 0; i < 10; i++) {
					if (i == encontra - 1) {
						if (quartos[i] > 0) {
							printf("o quarto %d está reservado com %d diárias \n", encontra, quartos[i]);
							printf("gostaria de trocar para quantas?: ");
							if (scanf("%d", &diaria) == 1) {
								if (diaria > 0) {
									quartos[i] = diaria;
									printf("troca realizada com sucesso\n");
									printf("Agora o quarto %d está reservado com %d diárias \n", encontra, quartos[i]);
								}
								else {
									printf("A quantidade de diárias deve ser maior que 0.\n");
								}
							}
							else {
								lixo = 'a';
								while (lixo != '\n') {
									scanf("%c", &lixo);
								}
								printf("Quantidade de diárias inválida.\n");
							}
							temp += 1;
						}
						else {
							printf("O quarto está desocupado.\n");
							temp += 1;
						}
					}
				}
				if (temp == 0) {
					printf("quarto inexistente, há apenas 10 quartos.\n");
				}
				printf("\nDeseja alterar outra hospedagem? (s/n): ");
				scanf(" %c", &resp);
				if (resp == 's' || resp == 'S') {
					printf("\n");
				}
				else if (resp == 'n' || resp == 'N') {
					printf("\n");
				}
				else {
					resp = 's';
					printf("digitação inválida, escreva novamente\n\n");
				}
			}
		}

		//Apagar
		if (opcao == 4) {
			char resp2 = 's';
			resp = 'N';
			for (i = 0; i < 10; i++) {
				if (quartos[i] != 0) {
					resp = 's';
					i = 10;
				}
			}
			if (resp == 'N') {
				printf("\nTodos os quartos estão desocupados\n");
			}
			while (resp == 's' || resp == 'S')
			{
				temp = 0;
				printf("Qual quarto deseja encerrar a hospedagem, (1 a 10): ");
				if (scanf("%d", &encontra) != 1) {
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					encontra = 0;
				}
				for (i = 0; i < 10; i++) {
					if (i == encontra - 1) {
						if (quartos[i] > 0) {
							printf("O quarto %d está reservado com %d diárias \n", encontra, quartos[i]);
							printf("Gostaria de encerrar esta hospedagem? (s/n): ");
							scanf(" %c", &resp2);
							if (resp2 == 'S' || resp2 == 's') {
								quartos[i] = 0;
								printf("Foi encerrada a hospedagem do quarto %d \n", encontra);
								temp += 1;
							}
							else if (resp2 == 'N' || resp2 == 'n') {
								printf("Foi cancelado o encerramento da hospedagem\n");
								temp += 1;
							}
							else {
								printf("Digitação inválida...\n\n");
								temp += 1;
							}

						}
						else {
							printf("O quarto está desocupado.\n");
							temp += 1;
						}
					}
				}

				if (temp == 0) {
					printf("quarto inexistente, há apenas 10 quartos.\n");
				}
				printf("\ndeseja apagar outra hospedagem? (s/n): ");
				scanf(" %c", &resp);
				if (resp == 's' || resp == 'S') {
					printf("\n");
				}
				else if (resp == 'n' || resp == 'N') {
					printf("\n");
				}
				else {
					resp = 's';
					printf("digitação inválida, escreva novamente\n\n");
				}
			}
		}

	}
	// sair
	if (opcao == 5) {
		printf("\nAté mais...");
	}
	return 0;
}

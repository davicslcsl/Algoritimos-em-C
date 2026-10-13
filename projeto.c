#include <stdio.h>


int main() {
	float despesas[10];
	int quantidade;     
	int opcao;
	int encontra;
	int i;
	int leu;
	float numero;

	quantidade = 0;
	opcao = 0;
  //Garante que o programa continue a ser executado até que o usuário digite 5
	while (opcao != 5) {
		char resp = 's';
		char lixo;

    //Menu
		printf("\n======== Despesas ========\n");
		printf("1 - Registrar despesas\n");
		printf("2 - Consultar despesas\n");
		printf("3 - Alterar despesas\n");
		printf("4 - Deletar despesas\n");
		printf("5 - Sair\n");
		printf("Digite o número para realizar a ação: ");

		leu = scanf("%d", &opcao);
		// descarta o que sobrou no teclado até o Enter
		lixo = 'a';
		while (lixo != '\n') {
			scanf("%c", &lixo);
		}

		if (leu != 1 || opcao < 1 || opcao > 5) {
			printf("\nDigite uma opção válida (1 a 5)!\n");
			opcao = 0;
		}

		// Registrar despesas (Create)
		if (opcao == 1) {
			resp = 's';
        // Verifica se o vetor está cheio
			if (quantidade >= 10) {
				printf("\nLimite de 10 despesas atingido!\n");
				resp = 'n';
			}

			while (resp == 's' || resp == 'S') {
				printf("\nDigite o valor da despesa %d: ", quantidade + 1);
				leu = scanf("%f", &numero);
				lixo = 'a';
				while (lixo != '\n') {
					scanf("%c", &lixo);
				}

				if (leu == 1) {
					// zero é um valor válido, só não aceita negativo
					if (numero >= 0) {
						despesas[quantidade] = numero;
						quantidade += 1;
						printf("Despesa registrada com sucesso!\n");
					}
					else {
						printf("A despesa não pode ser negativa!\n");
					}
				}
				else {
					printf("Digite um número válido!\n");
				}

				if (quantidade >= 10) {
					printf("\nLimite de 10 despesas atingido!\n");
					resp = 'n';
				}
				else {
					printf("Deseja registrar outra despesa? (s/n): ");
					scanf(" %c", &resp);
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}

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
		}

		//Consultar quartos (ler)
		if (opcao == 2) {
			int op;

			if (quantidade == 0) {
				printf("\nNão há despesas registradas.\n");
			}
			else {
				printf("\n=== Consultar despesas ===\n");
				printf("1 - Exibir todas as despesas\n");
				printf("2 - Exibir total e média\n");
				printf("3 - Exibir maior e menor despesa\n");
				printf("Escolha: ");
				leu = scanf("%d", &op);
				lixo = 'a';
				while (lixo != '\n') {
					scanf("%c", &lixo);
				}
				if (leu != 1) {
					op = 0;
				}
				printf("\n");

				if (op == 1) {
					for (i = 0; i < quantidade; i++) {
						printf("Despesa %d: R$ %.2f\n", i + 1, despesas[i]);
					}
					printf("\nPosições livres: %d\n", 10 - quantidade);
				}
				else if (op == 2) {
					float total = 0;

					for (i = 0; i < quantidade; i++) {
						total += despesas[i];
					}
					printf("Total: R$ %.2f\n", total);
					printf("Média: R$ %.2f\n", total / quantidade);
				}
				else if (op == 3) {
					float maior = despesas[0];
					float menor = despesas[0];
					int posMaior = 0;
					int posMenor = 0;

					for (i = 1; i < quantidade; i++) {
						if (despesas[i] > maior) {
							maior = despesas[i];
							posMaior = i;
						}
						if (despesas[i] < menor) {
							menor = despesas[i];
							posMenor = i;
						}
					}
					printf("Maior despesa: %d (R$ %.2f)\n", posMaior + 1, maior);
					printf("Menor despesa: %d (R$ %.2f)\n", posMenor + 1, menor);
				}
				else {
					printf("Opção inválida.\n");
				}
			}
		}

		//Alterar hospedagem(update)
		if (opcao == 3) {
			resp = 's';

			if (quantidade == 0) {
				printf("\nNão há despesas registradas.\n");
				resp = 'n';
			}

			while (resp == 's' || resp == 'S') {
				printf("\n=== Alterar despesas ===\n");
				for (i = 0; i < quantidade; i++) {
					printf("Despesa %d: R$ %.2f\n", i + 1, despesas[i]);
				}

				printf("\nQual despesa deseja alterar (1 a %d): ", quantidade);
				leu = scanf("%d", &encontra);
				lixo = 'a';
				while (lixo != '\n') {
					scanf("%c", &lixo);
				}
				if (leu != 1) {
					encontra = 0;
				}

				if (encontra >= 1 && encontra <= quantidade) {
					printf("A despesa %d vale R$ %.2f.\n", encontra, despesas[encontra - 1]);
					printf("Digite o novo valor: ");
					leu = scanf("%f", &numero);
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}

					if (leu == 1) {
						if (numero >= 0) {
							despesas[encontra - 1] = numero;
							printf("Despesa alterada com sucesso!\n");
							printf("Agora a despesa %d vale R$ %.2f.\n", encontra, despesas[encontra - 1]);
						}
						else {
							printf("A despesa não pode ser negativa!\n");
						}
					}
					else {
						printf("Valor inválido.\n");
					}
				}
				else {
					printf("Despesa não encontrada, existem %d despesa(s).\n", quantidade);
				}

				resp = 'x';
				while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N') {
					printf("\nDeseja alterar outra despesa? (s/n): ");
					scanf(" %c", &resp);
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					if (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N') {
						printf("Digitação inválida, escreva novamente.\n");
					}
				}
			}
		}

		//deletar despesa(delete)
		if (opcao == 4) {
			resp = 's';

			if (quantidade == 0) {
				printf("\nNão há despesas registradas.\n");
				resp = 'n';
			}

			while (resp == 's' || resp == 'S') {
				int sub;
				char resp2 = 'x';

				printf("\n=== Deletar despesas ===\n");
				printf("1 - Deletar uma despesa\n");
				printf("2 - Deletar todas as despesas\n");
				printf("Escolha: ");
				leu = scanf("%d", &sub);
				lixo = 'a';
				while (lixo != '\n') {
					scanf("%c", &lixo);
				}
				if (leu != 1) {
					sub = 0;
				}
				printf("\n");

				if (sub == 1) {
					for (i = 0; i < quantidade; i++) {
						printf("Despesa %d: R$ %.2f\n", i + 1, despesas[i]);
					}

					printf("\nQual despesa deseja deletar (1 a %d): ", quantidade);
					leu = scanf("%d", &encontra);
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					if (leu != 1) {
						encontra = 0;
					}

					if (encontra >= 1 && encontra <= quantidade) {
						printf("\nDespesa %d: R$ %.2f\n", encontra, despesas[encontra - 1]);

						while (resp2 != 's' && resp2 != 'S' && resp2 != 'n' && resp2 != 'N') {
							printf("Deseja deletar esta despesa? (s/n): ");
							scanf(" %c", &resp2);
							lixo = 'a';
							while (lixo != '\n') {
								scanf("%c", &lixo);
							}

							if (resp2 == 's' || resp2 == 'S') {
								// puxa as despesas seguintes para trás, mantendo o vetor em ordem
								for (i = encontra - 1; i < quantidade - 1; i++) {
									despesas[i] = despesas[i + 1];
								}
								despesas[quantidade - 1] = 0;
								quantidade -= 1;
								printf("Despesa deletada com sucesso!\n");
							}
							else if (resp2 == 'n' || resp2 == 'N') {
								printf("Foi cancelada a exclusão da despesa.\n");
							}
							else {
								printf("Digitação inválida, digite novamente...\n\n");
							}
						}
					}
					else {
						printf("Despesa não encontrada, existem %d despesa(s).\n", quantidade);
					}
				}

				else if (sub == 2) {
					while (resp2 != 's' && resp2 != 'S' && resp2 != 'n' && resp2 != 'N') {
						printf("Deseja realmente deletar TODAS as despesas? (s/n): ");
						scanf(" %c", &resp2);
						lixo = 'a';
						while (lixo != '\n') {
							scanf("%c", &lixo);
						}

						if (resp2 == 's' || resp2 == 'S') {
							for (i = 0; i < quantidade; i++) {
								despesas[i] = 0;
							}
							quantidade = 0;
							printf("Todas as despesas foram deletadas.\n");
						}
						else if (resp2 == 'n' || resp2 == 'N') {
							printf("Operação cancelada.\n");
						}
						else {
							printf("Digitação inválida, digite novamente...\n\n");
						}
					}
				}

				else {
					printf("Opção inválida.\n");
				}

				if (quantidade == 0) {
					resp = 'n';
				}
				else {
					resp = 'x';
					while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N') {
						printf("\nDeseja deletar outra despesa? (s/n): ");
						scanf(" %c", &resp);
						lixo = 'a';
						while (lixo != '\n') {
							scanf("%c", &lixo);
						}
						if (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N') {
							printf("Digitação inválida, escreva novamente.\n");
						}
					}
				}
			}
		}

	}

	   	//Sair(encerrar o programa)
    //Quando opcao recebe 5, a condição do while deixa de ser verdadeira e o programa chega até aqui.
	if (opcao == 5) {
		printf("\nAté mais...");
	}
	return 0;
}

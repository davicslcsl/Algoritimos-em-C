#include <stdio.h>

int main() {
	int despesas[10];
	int opcao, encontra, i, diaria;
    float numero, temp;
    int quantidade;
    quantidade = 0;
	opcao = 0;
	//Garante que o programa continue a ser executado até que o usuário digite 5
	while (opcao != 5) {
		//Variável usada para respostas de sim ou não
		char resp = 's';
		//Variável auxiliar usada para limpar caracteres inválidos
        //que ficaram no buffer de entrada após um scanf falhar.
		char lixo;
		//Menu
		printf("\n======== Hotel ========\n");
		printf("1 - Registrar despesas\n");
		printf("2 - Consultar despesas\n");
		printf("3 - Alterar despesas\n");
		printf("4 - Deletar despesas\n");
		printf("5 - Sair\n");
		printf("Digite o número para realizar a ação: ");
		//scanf retorna 1 quando consegue ler corretamente um inteiro.
        //Se o usuário digitar uma letra ou outro valor inválido, o retorno será diferente de 1.
		if (scanf("%d", &opcao) != 1) {
			// Limpa tudo que ficou na entrada até encontrar o ENTER (\n).
			lixo = 'a';
			while (lixo != '\n') {
				scanf("%c", &lixo);
			}
			// Força uma opção inválida para que o programa
            // apresente a mensagem de erro.
			opcao = 0;
		}
		// Verifica se a opção está dentro das opções do menu.
		if (opcao <= 0 || opcao > 5){
		    printf("\nDigite uma opção válida!");
		}

		// Registrar despesas (Create)
if (opcao == 1) {
    resp = 's';

    while (resp == 's' || resp == 'S') {

        // Verifica se o vetor está cheio
        if (quantidade >= 10) {
            printf("\nLimite de 10 despesas atingido!\n");
            break;
        }

        printf("\nDigite o valor da despesa %i: ", quantidade + 1);

        // Verifica se foi digitado um número válido
        if (scanf("%f", &numero) == 1) {

            // Não permite valores negativos
            if (numero >= 0) {
                despesas[quantidade] = numero;
                quantidade += 1;
                printf("Despesa registrada com sucesso!\n");
            }
            else {
                printf("A despesa não pode ser negativa!\n");
                continue;
            }
        }
        else {
            lixo = 'a';
            while (lixo != '\n') {
                scanf("%c", &lixo);
            }

            printf("Digite um número válido!\n");
            continue;
        }

        // Verifica se ainda existe espaço no vetor
        if (quantidade >= 10) {
            printf("\nLimite de 10 despesas atingido!\n");
            break;
        }

        printf("Deseja registrar outra despesa (s/n): ");
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

		//Consultar quartos (ler)
		if (opcao == 2) {
            //Opção do submenu de consulta.
            int op;
            //Variável utilizada para saber se o quarto pesquisado foi encontrado.
            int encontrou = 0;
            printf("\n=== Consultar quartos ===\n");
            printf("1 - Exibir todos os quartos\n");
            printf("2 - Exibir somente quartos vazios\n");
            printf("3 - Exibir somente quartos ocupados\n");
            printf("Escolha: ");
            // Valida a entrada do submenu.
            if (scanf("%d", &op) != 1) {
                lixo = 'a';
                while (lixo != '\n') {
                    scanf("%c", &lixo);
                }
                op = 0;
            }
            printf("\n");
            //Mostrar todos os quartos
            if (op == 1) {
                for (i = 0; i < 10; i++) {

                    //Valor maior que 0 significa ocupado.
                    if (quartos[i] > 0) {

                        printf(
                            "Quarto %d: OCUPADO (%d diária(s))\n",
                            i + 1,
                            quartos[i]
                        );
                    }
                    else {
                        printf("Quarto %d: vazio\n", i + 1);
                    }
                }
            }
            //Mostrar quartos vazios
            else if (op == 2) {
                for (i = 0; i < 10; i++) {

                    if (quartos[i] == 0) {

                        printf("Quarto %d: vazio\n", i + 1);
                        // Marca que pelo menos um quarto vazio foi encontrado.
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Não há quartos vazios.\n");
                }
            }
            // Mostrar quartos ocupados
            else if (op == 3) {
                for (i = 0; i < 10; i++) {
                    if (quartos[i] > 0) {
                        printf(
                            "Quarto %d: OCUPADO (%d diária(s))\n",
                            i + 1,
                            quartos[i]
                        );
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
        //Alterar hospedagem(update)
        if (opcao == 3) {
            int sub;
            printf("\n=== Alterar hospedagem ===\n");
            printf("1 - Alterar quantidade de diárias\n");
            printf("2 - Mudar hóspede de quarto\n");
            printf("Escolha: ");

            // Valida a entrada do submenu.
            if (scanf("%d", &sub) != 1) {
                lixo = 'a';
                while (lixo != '\n') {
                    scanf("%c", &lixo);
                }
                sub = 0;
            }
            printf("\n");
            //Alterar quantidade de diárias
            if (sub == 1) {
                // Inicialmente considera que não existe nenhuma hospedagem cadastrada.
                resp = 'N';

                // Procura pelo menos um quarto ocupado.
                for (i = 0; i < 10; i++) {
                    if (quartos[i] != 0) {
                        resp = 's';
                        // Força o encerramento do for, pois já encontramos um quarto ocupado.
                        i = 10;
                    }
                }
                if (resp == 'N') {
                    printf("Todos os quartos estão desocupados\n");
                }
                //Permite alterar várias hospedagens.
                while (resp == 's' || resp == 'S') {
                    //temp será usado para saber se o número de quarto informado existe.
                    temp = 0;
                    printf("digite o quarto que deseja alterar a diária, (1 a 10): ");
                    if (scanf("%d", &encontra) != 1) {
                        lixo = 'a';
                        while (lixo != '\n') {
                            scanf("%c", &lixo);
                        }
                        encontra = 0;
                    }
                    //Procura o quarto informado no vetor.
                    for (i = 0; i < 10; i++) {
                        if (i == encontra - 1) {
                            // Verifica se esse quarto está ocupado.
                            if (quartos[i] > 0) {
                                printf("o quarto %d está reservado com %d diárias \n", encontra, quartos[i]);
                                printf("gostaria de trocar para quantas?: ");
                                if (scanf("%d", &diaria) == 1) {
                                    if (diaria > 0) {
                                        // Atualiza a quantidade de diárias.
                                        quartos[i] = diaria;
                                        printf("troca realizada com sucesso\n");
                                        printf("Agora o quarto %d está reservado com %d diárias \n", encontra, quartos[i] );
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
                                    printf(
                                        "Quantidade de diárias inválida.\n"
                                    );
                                }

                                // Indica que o quarto informado existe.
                                temp += 1;
                            }
                            else {
                                printf("O quarto está desocupado.\n");
                                //O quarto existe, apesar de estar vazio.
                                temp += 1;
                            }
                        }
                    }
                    //Se temp continuar 0, nenhum índice do vetor correspondeu ao quarto digitado.
                    if (temp == 0) {
                        printf(
                            "quarto inexistente, há apenas 10 quartos.\n"
                        );
                    }
                    printf(
                        "\nDeseja alterar outra hospedagem? (s/n): "
                    );
                    scanf(" %c", &resp);
                    if (resp == 's' || resp == 'S') {
                        printf("\n");
                    }
                    else if (resp == 'n' || resp == 'N') {
                        printf("\n");
                    }
                    else {
                        //Mantém o laço para pedir novamente.
                        resp = 's';
                        printf("digitação inválida, escreva novamente\n\n");
                    }
                }
            }
           //Mudar hospedagem
            else if (sub == 2) {
                int origem, destino;
                // Quantidades usadas para verificar se a operação de troca é possível.
                int ocupados = 0;
                int vazios = 0;
                // Conta quantos quartos estão ocupados e vazios.
                for (i = 0; i < 10; i++) {
                    if (quartos[i] > 0) {
                        ocupados += 1;
                    }
                    else {
                        vazios += 1;
                    }
                }
                //Não existe hóspede para mudar.
                if (ocupados == 0) {
                    printf("Todos os quartos estão desocupados\n");
                }
                //Existe hóspede, mas nenhum quarto disponível.
                else if (vazios == 0) {
                    printf(
                        "Não há quartos vazios para receber o hóspede.\n"
                    );
                }
                else {
                    printf("Digite o quarto atual do hóspede (1 a 10): ");
                    if (scanf("%d", &origem) != 1) {
                        lixo = 'a';
                        while (lixo != '\n') {
                            scanf("%c", &lixo);
                        }
                        origem = 0;
                    }
                    //Verifica se o quarto de origem existe.
                    if (origem < 1 || origem > 10) {
                        printf("Quarto inexistente, há apenas 10 quartos.\n");
                    }
                    //Verifica se há alguém hospedado na origem.
                    else if (quartos[origem - 1] == 0) {
                        printf("O quarto %d está desocupado.\n",origem);
                    }
                    else {
                        printf("O quarto %d está reservado com %d diária(s).\n",origem,quartos[origem - 1]);
                        printf("Digite o novo quarto (1 a 10): ");
                        if (scanf("%d", &destino) != 1) {
                            lixo = 'a';
                            while (lixo != '\n') {
                                scanf("%c", &lixo);
                            }
                            destino = 0;
                        }
                        //Verifica se o quarto de destino existe.
                        if (destino < 1 || destino > 10) {
                            printf("Quarto inexistente, há apenas 10 quartos.\n");
                        }
                        //Não há sentido mudar para o mesmo quarto.
                        else if (destino == origem) {
                            printf("O hóspede já está nesse quarto.\n");
                        }

                        //O destino precisa estar vazio.
                        else if (quartos[destino - 1] != 0) {
                            printf("O quarto %d já está ocupado.\n",destino);
                        }
                        else {
                            //Copia a quantidade de diárias do quarto antigo para o novo.
                            quartos[destino - 1] =
                                quartos[origem - 1];
                            //Libera o quarto antigo.
                            quartos[origem - 1] = 0;
                            printf(
                                "Hóspede mudou do quarto %d para o quarto %d (%d diária(s)).\n",
                                origem,
                                destino,
                                quartos[destino - 1]
                            );
                        }
                    }
                }
            }
            else {
                printf("Opção inválida.\n");
            }
        }
       //Encerrar despesa(deletar)
		if (opcao == 4) {
			resp = 'S';
			if (quantidade = 0) {
				printf("Nao ha despesas registradas.\n");
				resp = 'N';
			}
			while (resp == 's' || resp == 'S') {
				int sub;
				printf("\n=== Deletar despesas ===\n");
				printf("1 - Deletar uma despesa\n");
				printf("2 - Deletar todas as despesas\n");
				printf("Escolha: ");
				if (scanf("%d", &sub) != 1) {
					lixo = 'a';
					while (lixo != '\n') {
						scanf("%c", &lixo);
					}
					sub = 0;
				}
				printf("\n");
				//Encerrar uma despesa
				if (sub == 1) {
					//resp2 será usada para confirmar especificamente o encerramento do quarto escolhido.
					char resp2 = 'S';
					for (i = 0; i < quantidade; i++) {
						printf("despesa %dª: (%.2f $)\n", i + 1, despesas[i]);
					}
					printf("Qual despesa deseja deletar:");
					if (scanf("%d", &encontra) != 1) {
						lixo = 'a';
						while (lixo != '\n') {
							scanf("%c", &lixo);
						}
						encontra = 0;
					}
					if (encontra > 0 && encontra =< quantidade) {
						printf("\ndespesa %dª: (%.2f reais)\n", encontra, despesas[encontra-1]);

						while (1) {
							printf("Gostaria de encerrar esta hospedagem? (s/n): " );
							scanf(" %c", &resp2);
							// Confirma o encerramento.
							if (resp2 == 'S' || resp2 == 's') {
								if (encontra < quantidade) {
									int dif;
									dif = quantidade - encontra;
									int vetortemp[quantidade - encontra];
									for (i = 0 ; i < dif; i++) {
										vetortemp[i] = despesas[i+encontra];
									}
									for (i = encontra-1; i < quantidade-1; i++) {
										despesas[i] = vetortemp[i-encontra+1];
									}
									despesas[quantidade-1] = 0;
									quantidade -= 1;
									printf("Despesa excluida com sucesso!\n");
								}
								else {
									despesas[quantidade-1] = 0;
									quantidade -= 1;
									printf("Despesa excluida com sucesso!\n");
								}
								break;
							}
							else if ( resp2 == 'N' || resp2 == 'n') {
								printf("Foi cancelado o deletamento da despesa\n");
								break;
							}
							else {
								printf("Digitação inválida, digite novamente...\n\n");
							}
						}
					}
					else () {
						printf("Despesa nao encotrada, so existe %i despesas", quantidade);
					}
				}
				
				
				//Encerrar todas as hospedagens
				else if (sub == 2) {
					char resp2 = 'S';
					printf("Deseja realmente encerrar TODAS as hospedagens? (s/n): ");
					scanf(" %c", &resp2);
					while(1) {
						// Usuário confirma
						if (resp2 == 's' || resp2 == 'S') {
							for (i = 0; i < quantidade; i++) {
								despesas[i] = 0;
							}
							quantidade = 0;
							printf("Todas as hospedagens foram encerradas.\n");
							break;
						}
						//Usuário cancela.
						else if (resp == 'n' || resp == 'N') {
							printf("Operação cancelada.\n");
							break;
						}
						else {
							printf("Digitação inválida, digite novamente...\n");
						}
					}
				}
				while (quantidade > 0) {
					printf("\ndeseja apagar outra hospedagem? (s/n): ");
					scanf(" %c", &resp);
					if (resp == 's' || resp == 'S') {
						printf("\n");
						break;
					}
					else if (resp == 'n' || resp == 'N') {
						printf("\n");
						break;
					}
					else {
						//Mantém o laço e permite digitar novamente.
						printf("digitação inválida, escreva novamente\n\n");
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

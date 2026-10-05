# Sistema de Gerenciamento de Hotel

Sistema de gerenciamento de hotel feito em C para praticar o uso de **vetores** e as operações de um CRUD.

O programa trabalha com 10 quartos e permite realizar, consultar, alterar e encerrar hospedagens pelo terminal.

## Funcionalidades

| Opção | Ação | O que faz |
|-------|------|-----------|
| 1 | Realizar hospedagem | Cadastra uma hospedagem informando o quarto e a quantidade de diárias |
| 2 | Consultar quartos | Exibe todos os quartos, somente os vazios ou somente os ocupados |
| 3 | Alterar hospedagem | Altera a quantidade de diárias ou muda o hóspede para outro quarto |
| 4 | Encerrar hospedagem | Encerra a hospedagem de um quarto ou de todos de uma vez |
| 5 | Sair | Encerra o programa |

As opções 2, 3 e 4 abrem um submenu para escolher a ação desejada.

## Exemplo de uso

```text
======== Hotel ========
1 - Realizar hospedagem
2 - Consultar quartos
3 - Alterar hospedagem
4 - Encerrar hospedagem
5 - Sair
Digite o número para realizar a ação: 2

=== Consultar quartos ===
1 - Exibir todos os quartos
2 - Exibir somente quartos vazios
3 - Exibir somente quartos ocupados
Escolha: 3

Quarto 1: OCUPADO (3 diária(s))
Quarto 3: OCUPADO (5 diária(s))
```

## Como funciona

O programa utiliza um vetor com 10 posições:

```c
int quartos[10];
```

Cada posição representa um quarto, e o valor guardado é a quantidade de diárias. O valor `0` indica que o quarto está vazio.

```text
quartos[0] → Quarto 1
quartos[1] → Quarto 2
quartos[2] → Quarto 3
...
quartos[9] → Quarto 10
```

Por exemplo, com o Quarto 1 ocupado por 3 diárias e o Quarto 3 por 5 diárias, o vetor fica:

```text
[3] [0] [5] [0] [0] [0] [0] [0] [0] [0]
```

## CRUD

O projeto segue as operações básicas de um CRUD:

* **Create:** realizar uma hospedagem
* **Read:** consultar os quartos
* **Update:** alterar diárias ou mudar de quarto
* **Delete:** encerrar uma ou todas as hospedagens

## Validações

O programa trata as entradas inválidas mais comuns:

* letras digitadas onde se espera um número
* quartos fora do intervalo de 1 a 10
* quantidade de diárias menor ou igual a 0
* tentativa de hospedar em um quarto já ocupado
* tentativa de alterar ou encerrar um quarto vazio
* mudança de quarto para um quarto ocupado ou para o mesmo quarto
* confirmação antes de encerrar hospedagens

## Conceitos utilizados

* Vetores
* Estruturas de repetição (`for` e `while`)
* Estruturas condicionais (`if`, `else if` e `else`)
* Entrada e saída com `scanf` e `printf`
* Validação de entrada


## Integrantes

* Guilherme Brahuna Serejo ([Guilherme-Serejo](https://github.com/Guilherme-Serejo))
* Davi Christian Santos Lima ([davicslcsl](https://github.com/davicslcsl))
* João Emanuel de Aliano Ribeiro ([Murdockkl](https://github.com/Murdockkl))

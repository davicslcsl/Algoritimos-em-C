# Sistema de Gerenciamento de Hotel

Sistema de gerenciamento de despesas de um hotel feito em C para praticar o uso de **vetores** e as operações de um CRUD.

O programa trabalha com 10 espaços para despesas e permite registrar, consultar, alterar e deletar despesas pelo terminal.

## Funcionalidades

| Opção | Ação | O que faz |
|-------|------|-----------|
| 1 | Registrar despesas | Cadastra uma hospedagem informando o quarto e a quantidade de diárias |
| 2 | Consultar despesas | Exibe todos os quartos, somente os vazios ou somente os ocupados |
| 3 | Alterar despesas   | Altera a quantidade de diárias ou muda o hóspede para outro quarto |
| 4 | deletar despesas   | Encerra a hospedagem de um quarto ou de todos de uma vez |
| 5 | Sair | Encerra o programa |

As opções 2, 3 e 4 abrem um submenu para escolher a ação desejada.

## Exemplo de uso

```text
======== Hotel ========
1 - Registrar despesas
2 - Consultar despesas
3 - Alterar despesas
4 - deletar despesas
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

O programa utiliza um vetor com 10 posições para armazenar os valores das despesas:

float despesas[10];

Cada posição do vetor representa uma despesa, e o valor armazenado corresponde ao seu custo em reais.

Além disso, foi utilizada a variável quantidade, responsável por contabilizar o número de despesas cadastradas. Essa variável facilita as operações do CRUD, pois permite identificar a próxima posição disponível e controlar a quantidade de elementos armazenados.

despesas[0] → valor da primeira despesa
despesas[1] → valor da segunda despesa
despesas[2] → valor da terceira despesa
...
despesas[9] → valor da décima despesa

Por exemplo, supondo que sejam registradas três despesas nos valores de R$ 10,00, R$ 20,00 e R$ 30,00, o vetor ficaria representado da seguinte forma:

[10.00] [20.00] [30.00] [—] [—] [—] [—] [—] [—] [—]

quantidade = 3

Nesse exemplo, as três primeiras posições estão ocupadas, enquanto as sete restantes ainda não possuem despesas cadastradas. O símbolo — representa uma posição não utilizada, e não necessariamente um valor igual a zero.

A próxima despesa será registrada na posição despesas[3], mantendo o preenchimento sequencial do vetor, sem espaços vazios entre os elementos cadastrados.
## CRUD

O projeto segue as operações básicas de um CRUD:

* **Create:** registrar uma despesa
* **Read:** consultar as despesas
* **Update:** alterar o valor das despesas
* **Delete:** deletar uma despesa

## Validações

O programa trata as entradas inválidas mais comuns:

* letras digitadas onde se espera um número
* despesas fora do intervalo de 1 a 10
* valor da despesa menor ou igual a 0
* tentativa de alterar ou dele uma despesa não registrada
* confirmação antes de deletar despesas 

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

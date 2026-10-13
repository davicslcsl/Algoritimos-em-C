# Sistema de Gerenciamento de Despesas

Sistema de controle de despesas feito em C para praticar o uso de **vetores** e as operações de um **CRUD**.

O programa trabalha com até **10 despesas** e permite registrar, consultar, alterar e deletar valores pelo terminal.

## Funcionalidades

| Opção | Ação | O que faz |
|-------|------|-----------|
| 1 | Registrar despesas | Cadastra uma ou mais despesas informando o valor em reais |
| 2 | Consultar despesas | Exibe todas as despesas, o total e a média, ou a maior e a menor despesa |
| 3 | Alterar despesas | Muda o valor de uma despesa já cadastrada |
| 4 | Deletar despesas | Remove uma despesa específica ou todas de uma vez |
| 5 | Sair | Encerra o programa |

As opções 2 e 4 abrem um submenu para escolher a ação desejada. As opções 1, 3 e 4 perguntam se o usuário quer repetir a operação antes de voltar ao menu principal.

### Submenu de consulta (opção 2)

| Opção | O que exibe |
|-------|-------------|
| 1 | Todas as despesas e a quantidade de posições livres |
| 2 | Total gasto e média das despesas |
| 3 | Maior e menor despesa, com a posição de cada uma |

### Submenu de exclusão (opção 4)

| Opção | O que faz |
|-------|-----------|
| 1 | Deleta uma despesa escolhida (com confirmação) |
| 2 | Deleta todas as despesas (com confirmação) |

## Exemplo de uso

```text
======== Despesas ========
1 - Registrar despesas
2 - Consultar despesas
3 - Alterar despesas
4 - Deletar despesas
5 - Sair
Digite o número para realizar a ação: 2

=== Consultar despesas ===
1 - Exibir todas as despesas
2 - Exibir total e média
3 - Exibir maior e menor despesa
Escolha: 2

Total: R$ 60.00
Média: R$ 20.00
```

## Como funciona

O programa utiliza um vetor de 10 posições para armazenar os valores das despesas:

```c
float despesas[10];
```

Cada posição do vetor guarda o valor de uma despesa, em reais. Além do vetor, a variável `quantidade` controla quantas despesas estão cadastradas. Ela indica a próxima posição livre e delimita até onde os laços `for` devem percorrer o vetor.

```text
despesas[0] → valor da primeira despesa
despesas[1] → valor da segunda despesa
despesas[2] → valor da terceira despesa
...
despesas[9] → valor da décima despesa
```

Por exemplo, ao registrar três despesas de R$ 10,00, R$ 20,00 e R$ 30,00, o vetor fica assim:

```text
[10.00] [20.00] [30.00] [—] [—] [—] [—] [—] [—] [—]

quantidade = 3
```

As três primeiras posições estão ocupadas e as sete restantes estão livres. O símbolo `—` representa uma posição não utilizada, e não necessariamente um valor igual a zero. A próxima despesa será gravada em `despesas[3]`, mantendo o vetor sempre preenchido de forma sequencial, sem espaços vazios entre os elementos.

### Exclusão sem deixar buracos

Ao deletar uma despesa do meio do vetor, as despesas seguintes são deslocadas uma posição para trás e `quantidade` é decrementada. Assim, o vetor continua organizado e as despesas são renumeradas automaticamente.

```text
Antes:   [10.00] [20.00] [30.00]   quantidade = 3
Deletar a despesa 2
Depois:  [10.00] [30.00] [—]       quantidade = 2
```

## CRUD

* **Create:** registrar uma despesa
* **Read:** consultar as despesas (lista, total, média, maior e menor)
* **Update:** alterar o valor de uma despesa
* **Delete:** deletar uma despesa ou todas

## Validações

O programa trata as entradas inválidas mais comuns:

* opção de menu fora do intervalo de 1 a 5
* letras digitadas onde se espera um número
* valor de despesa negativo (o valor `0` é aceito)
* limite de 10 despesas atingido ao registrar
* tentativa de alterar ou deletar uma despesa que não existe
* resposta diferente de `s` ou `n` nas perguntas de confirmação
* confirmação antes de deletar uma ou todas as despesas
* limpeza do buffer do teclado após cada leitura, evitando que sobras da digitação atrapalhem a próxima entrada


## Integrantes

* Guilherme Brahuna Serejo ([Guilherme-Serejo](https://github.com/Guilherme-Serejo))
* Davi Christian Santos Lima ([davicslcsl](https://github.com/davicslcsl))
* João Emanuel de Aliano Ribeiro ([Murdockkl](https://github.com/Murdockkl))

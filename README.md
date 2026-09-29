# Sistema de Gerenciamento de Hotel

Sistema de gerenciamento de hotel feito em C para praticar o uso de **vetores** e as operações de um CRUD.

O programa trabalha com 10 quartos e permite realizar, consultar, alterar e encerrar hospedagens.

## Funcionalidades

O sistema possui as seguintes opções:

* **1 - Realizar hospedagem**
* **2 - Consultar quartos**
* **3 - Alterar hospedagem**
* **4 - Encerrar hospedagem**
* **5 - Sair**

## Como funciona

O programa utiliza um vetor com 10 posições:

```c
int quartos[10];
```

Cada posição representa um quarto.

```text
quartos[0] → Quarto 1
quartos[1] → Quarto 2
quartos[2] → Quarto 3
...
quartos[9] → Quarto 10
```

A quantidade de diárias fica armazenada na posição correspondente ao quarto.

Por exemplo:

```text
Quarto 1 → 3 diárias
Quarto 2 → disponível
Quarto 3 → 5 diárias
```

No vetor:

```text
[3] [0] [5] [0] [0] [0] [0] [0] [0] [0]
```

O valor `0` representa um quarto que está disponível.

## CRUD

O projeto foi feito seguindo as operações básicas de um CRUD:

* **Create:** realizar uma hospedagem
* **Read:** consultar informações
* **Update:** alterar uma hospedagem
* **Delete:** encerrar uma hospedagem

## Tecnologias

* C
* GCC
* Vetores
* Terminal

## Como executar

Para compilar usando o GCC:

```bash
gcc hotel.c -o hotel
```

Depois:

```bash
./hotel
```

No Windows, pode ser executado como:

```bash
hotel.exe
```

## Observação

Os dados ficam armazenados somente enquanto o programa está aberto. Como o sistema utiliza apenas um vetor, as informações são perdidas quando o programa é encerrado.

## Integrantes

* Guilherme Brahuna Serejo (Guilherme-Serejo)
* Davi Christian Santos Lima (davicslcsl)
* João Emanuel de Aliano Ribeiro (Murdockkl)

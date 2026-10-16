# Controle de Atividades Físicas (C)

Projeto acadêmico desenvolvido para a disciplina **Algoritmos e Pensamento Computacional**. Aplicação de terminal escrita em C para registrar treinos e consultar a duração das atividades, com estimativa didática de calorias gastas.

## Funcionalidades

- Menu interativo que se repete até a opção de saída.
- Registro de até 100 atividades com nome e duração em minutos.
- Consulta dos registros da sessão.
- Estimativa didática de calorias: `minutos × 5 kcal`.
- Validação de entradas não numéricas, tempos inválidos e opções não reconhecidas.
- Resumo ao encerrar.

> **Atenção:** O fator de 5 kcal/min serve apenas para ilustrar o cálculo no exercício. O gasto energético real depende do exercício, da intensidade e de características individuais.

## Como executar

É necessário um compilador C (GCC, Clang ou equivalente).

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o atividades
./atividades
```

No Windows, execute `atividades.exe` após compilar.

## Exemplo

```text
===== MENU PRINCIPAL =====
1 - Registrar atividade fisica
2 - Consultar atividades
3 - Calcular calorias gastas
0 - Sair
Escolha uma opcao: 3
Minutos de treino para estimar calorias: 30
Calorias estimadas: 150.00 kcal
```

## Conceitos praticados

`printf`, `scanf`, tipos de dados, vetores, `do-while`, `switch`, `if/else`, `for`, tratamento de entradas e funções.

## Limitações

Os dados ficam apenas na memória durante a execução do programa; não há banco de dados ou gravação em arquivo. O total de calorias soma apenas os cálculos realizados pela opção 3.

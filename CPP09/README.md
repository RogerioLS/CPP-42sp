#### CPP09 - Resumo, Conceitos, Propósitos e Perguntas Respondidas

📌 CPP09 - ex00: Bitcoin Exchange

📌 Propósito do Exercício

O objetivo do exercício é criar um programa que calcula o valor de uma quantidade de Bitcoin em uma data específica, com base em uma base de dados (`data.csv`) que contém as taxas de câmbio históricas do Bitcoin. O programa deve:

1. Carregar a base de dados (`data.csv`) para obter as taxas de câmbio.
2. Ler um arquivo de entrada (`input.csv`) contendo datas e valores de Bitcoin.
3. Validar os dados do arquivo de entrada.
4. Calcular o valor correspondente multiplicando a quantidade de Bitcoin pela taxa de câmbio da data especificada.
5. Tratar erros como:
    - Datas inválidas.
    - Valores fora do intervalo permitido.
    - Linhas malformadas no arquivo de entrada.

📂 Estrutura do Projeto

Arquivos Principais
1. BitcoinExchange.hpp:
    - Declaração da classe BitcoinExchange.
    - Responsável por carregar e armazenar as taxas de câmbio, validar dados e buscar a taxa de câmbio para uma data específica.
2. BitcoinExchange.cpp:
    - Implementação da classe BitcoinExchange.
    - Contém a lógica para carregar o arquivo `data.csv`, validar datas e taxas, e buscar a taxa de câmbio.

3. main.cpp:
    - Função principal do programa.
    - Lê o arquivo de entrada (input.csv), valida os dados e calcula os valores de Bitcoin usando a classe BitcoinExchange.

📌 Passo a Passo do Funcionamento
1️⃣ Carregar a Base de Dados (`data.csv`)
- O método loadDatabase da classe BitcoinExchange é responsável por carregar as taxas de câmbio do arquivo `data.csv`.
- Ele armazena as taxas em um std::map<std::string, double>, onde:
    - A chave (std::string) é a data no formato YYYY-MM-DD.
    - O valor (double) é a taxa de câmbio correspondente.
    - Exemplo de Dados no std::map:
    ```cpp
    {
    "2010-01-01": 0.003,
    "2011-09-14": 6.2,
    "2013-04-12": 120.5,
    "2020-06-26": 9300.0,
    "2022-03-30": 47000.0
    }
    ```

2️⃣ Ler o Arquivo de Entrada (input.csv)
- O arquivo de entrada contém linhas no formato:
  ```cpp
  date | value
  2010-01-01 | 100
  2011-09-14 | 50
  ```
- O programa lê cada linha, separa a data e o valor, e valida os dados.

3️⃣ Validar os Dados
- Datas:
    - O método validateDate verifica se a data está no formato YYYY-MM-DD e se é válida (ex.: 2025-02-30 não é válida).
- Valores:
    - O valor deve ser um número positivo entre 0 e 1000.

4️⃣ Buscar a Taxa de Câmbio
- O método getExchangeRate busca a taxa de câmbio correspondente à data no std::map.
- Se a data não existir no std::map, ele usa a data mais próxima anterior.
- Se nenhuma data anterior existir, retorna 0.

5️⃣ Calcular o Valor
- O programa multiplica o valor de Bitcoin pelo valor da taxa de câmbio
  ```cpp
  resultado = value * exchange_rate;
  ```

6️⃣ Exibir o Resultado
- O programa exibe o resultado no formato:
  ```cpp
  date => value = resultado
  ```

📌 Código Explicado

`BitcoinExchange.hpp`
- Declaração da classe BitcoinExchange.
- Contém os métodos:
    - loadDatabase: Carrega as taxas de câmbio do arquivo data.csv.
    - getExchangeRate: Retorna a taxa de câmbio para uma data específica.
    - validateDate: Valida o formato da data.
    - validateRate: Valida a taxa de câmbio.

`BitcoinExchange.cpp`
- Implementação dos métodos da classe BitcoinExchange:
    - loadDatabase:
        - Lê o arquivo data.csv e armazena as taxas no std::map.
        - Ignora linhas malformadas.
    - getExchangeRate:
        - Busca a taxa de câmbio para uma data específica.
        - Usa a data mais próxima anterior, se necessário.
    - validateDate:
        - Verifica se a data está no formato correto e é válida.
    - validateRate:
        - Verifica se a taxa de câmbio é válida (não negativa).

`main.cpp`
- Função principal do programa:
    - Lê o arquivo de entrada (input.csv).
    - Valida as datas e valores.
    - Usa a classe BitcoinExchange para calcular os valores de Bitcoin.
    - Exibe os resultados ou mensagens de erro.

📌 Exemplo de Funcionamento
Arquivo data.csv
```cpp
date,exchange_rate
2010-01-01,0.003
2011-09-14,6.2
2013-04-12,120.5
2020-06-26,9300.0
2022-03-30,47000.0
```
Arquivo input.csv
```cpp
date | value
2010-01-01 | 100
2011-09-14 | 50
2013-04-12 | 1.5
2020-06-26 | 0.1
2022-03-30 | 2
```
Saída Esperada
```cpp
2010-01-01 => 100 = 0.3
2011-09-14 => 50 = 310
2013-04-12 => 1.5 = 180.75
2020-06-26 => 0.1 = 930
2022-03-30 => 2 = 94000
```
📌 Tratamento de Erros
1. Arquivo data.csv Não Encontrado:
    - Mensagem: Could not open file: data.csv.
2. Linha Malformada no data.csv:
    - Mensagem: `Error: bad input => <linha>`.
3. Data Inválida no input.csv:
    - Mensagem: `Error: invalid date format => <data>`.
4. Valor Fora do Intervalo no input.csv:
    - Mensagem: Error: too large a number (se > 1000).
    - Mensagem: Error: not a positive number. (se < 0).
5. Linha Malformada no input.csv:
    - Mensagem: `Error: bad input => <linha>`.

📌 Argumentação para Escolha de Containers
1️⃣ Por que usar std::map no `ex00` (BitcoinExchange)?
Propósito do Exercício
No `ex00`, o objetivo é armazenar e buscar taxas de câmbio de Bitcoin associadas a datas específicas. Isso exige um container que:
- Armazene pares chave-valor (data e taxa de câmbio).
- Permita buscas eficientes por uma data específica ou pela data mais próxima anterior.
- Mantenha os dados ordenados por data.

Por que `std::map` é a melhor escolha?
1. Armazenamento de Pares Chave-Valor:
    - O ``std::map`` é ideal para armazenar pares chave-valor, onde a chave é a data (std::string) e o valor é a taxa de câmbio (double).
2. Ordenação Automática:
    - O `std::map` mantém os elementos ordenados pela chave (data), o que é essencial para buscar a data mais próxima anterior.
3. Busca Eficiente:
    - O `std::map` permite buscas rápidas com complexidade O(log n), o que é eficiente para encontrar uma data específica ou a data mais próxima anterior.
4. Evita Duplicatas:
    - O `std::map` não permite chaves duplicadas, garantindo que cada data tenha apenas uma taxa de câmbio associada.

Exemplo de Uso no Código
No método `getExchangeRate`, o `std::map` é usado para buscar a taxa de câmbio correspondente a uma data ou a data mais próxima anterior:
```cpp
auto it = exchangeRates.lower_bound(date);
if (it == exchangeRates.end() || it->first != date) {
    --it; // Busca a data mais próxima anterior
}
return it->second;
```

Conclusão
O `std::map` foi escolhido porque:
- Ele é eficiente para armazenar e buscar pares chave-valor.
- Ele mantém os dados ordenados automaticamente.
- Ele permite buscas rápidas por chaves específicas ou próximas.

❓ Perguntas Possíveis na Avaliação
1️⃣ Sobre o Propósito do Exercício
Por que usamos `std::map` para armazenar as taxas de câmbio?
- Porque ele permite armazenar os dados de forma ordenada por chave (data) e realizar buscas eficientes, como encontrar a data mais próxima anterior.

Como o programa lida com datas que não estão no data.csv?
- Ele usa a data mais próxima anterior no `std::map`. Se nenhuma data anterior existir, retorna 0.

2️⃣ Sobre a Implementação
Como o programa valida as datas?
- O método validateDate verifica se a data está no formato YYYY-MM-DD e se é válida (ex.: 2025-02-30 não é válida).

Como o programa valida os valores de Bitcoin?
- O programa verifica se o valor é um número positivo e está no intervalo permitido (0 a 1000).

O que acontece se o arquivo data.csv não for encontrado?
- O programa exibe a mensagem de erro Could not open file: data.csv e encerra a execução.

3️⃣ Sobre Tratamento de Erros
Quais erros o programa trata?
- Arquivo data.csv não encontrado.
- Linhas malformadas no data.csv ou input.csv.
- Datas inválidas no input.csv.
- Valores fora do intervalo permitido no input.csv.

Como o programa lida com linhas malformadas no data.csv?
- O programa ignora linhas malformadas e exibe uma mensagem de erro no formato `Error: bad input => <linha>.`

4️⃣ Sobre o Funcionamento
Como o programa calcula o valor de Bitcoin?
- Ele multiplica a quantidade de Bitcoin pelo valor da taxa de câmbio correspondente à data especificada.

O que acontece se o arquivo input.csv contiver uma data inválida?
- O programa exibe a mensagem de erro `Error: invalid date format => <data>`.

> [!NOTE]
> 🚀 Resumo Final
> Este exercício ensina a manipular arquivos, usar containers da STL (std::map), validar dados e tratar erros. Ele demonstra como implementar um programa robusto para cálculos financeiros simples, utilizando dados históricos.

---

📌 CPP09 - ex01: Reverse Polish Notation (RPN)
🚀 Propósito do Exercício
O objetivo deste exercício é implementar um programa que avalia expressões matemáticas na notação polonesa reversa (RPN - Reverse Polish Notation). O programa deve:

1. Receber uma expressão RPN como argumento.
2. Processar a expressão e calcular o resultado.
3. Exibir o resultado no terminal.
4. Tratar erros e exibir mensagens apropriadas no caso de entradas inválidas

📌 Regras e Restrições

1. Nome do Programa:
- O programa deve ser chamado RPN.
2. Entrada:
- O programa recebe uma expressão RPN como argumento.
- Os números na expressão serão sempre menores que 10.
- Não é necessário lidar com parênteses ou números decimais.
3. Operações Suportadas:
- /+/ (adição)
- /-/ (subtração)
- /*/ (multiplicação)
- / (divisão)
4. Saída:
- O resultado da expressão deve ser exibido no stdout.
- Em caso de erro, uma mensagem deve ser exibida no stderr.
5. Uso de Containers:
- É obrigatório usar pelo menos um container da STL para validar o exercício.
- O container usado no exercício anterior (std::map) não pode ser reutilizado aqui.
6. Erros:
- O programa deve exibir Error no stderr para entradas inválidas.
7. Compilação:
- O código deve ser compilado com as flags -Wall -Wextra -Werror -std=c++98.

📌 O Que Este Exercício Ensina?
- Manipulação de Containers da STL:
    - Uso de containers como std::stack para gerenciar a avaliação da expressão RPN.
- Processamento de Strings:
    - Dividir e interpretar a expressão RPN fornecida como argumento.
- Validação de Entradas:
    - Garantir que a expressão é válida antes de processá-la.
- Implementação de Algoritmos Matemáticos:
    - Avaliar expressões matemáticas usando a lógica da notação polonesa reversa.

📌 O Que é Notação Polonesa Reversa (RPN)?
A notação polonesa reversa é uma forma de escrever expressões matemáticas onde os operadores vêm depois dos operandos. Por exemplo:

- Expressão Infixa: `(8 * 9) - 9 - 9 - 9 - 4 + 1`
- Expressão RPN: `8 9 * 9 - 9 - 9 - 4 - 1 +`

Como Funciona?
1. Leia a expressão da esquerda para a direita.
2. Use uma pilha (std::stack) para armazenar os operandos.
3. Quando encontrar um operador:
    - Retire os dois últimos operandos da pilha.
    - Aplique o operador.
    - Coloque o resultado de volta na pilha.
4. No final, o resultado estará no topo da pilha.

📂 Estrutura do Projeto
Arquivos Necessários

1. `RPN.hpp:`
    - Declaração da classe RPN.
    - Contém os métodos para processar e avaliar a expressão RPN.
2. `RPN.cpp:`
    - Implementação da classe RPN.
    - Contém a lógica para validar e calcular a expressão.
3. `main.cpp:`
    - Função principal do programa.
    - Lê o argumento da linha de comando e usa a classe RPN para avaliar a expressão.
4. `Makefile:`
    - Compila o programa com as regras obrigatórias.

📌 Planejamento da Implementação
1️⃣ Classe RPN

Atributos:
- Um container (std::stack<int>) para armazenar os operandos durante a avaliação.

Métodos:
1. `RPN():`
    - Construtor padrão.
2. `~RPN():`
    - Destrutor.
3. `int evaluate(const std::string &expression):`
    - Recebe a expressão RPN como string.
    - Valida e avalia a expressão.
    - Retorna o resultado ou lança uma exceção em caso de erro.
4. `bool isOperator(char c):`
    - Verifica se o caractere é um operador válido (+, -, *, /).
5. `void applyOperator(char op):`
    - Aplica o operador nos dois últimos operandos da pilha.

2️⃣ Função Principal (main.cpp)
1. Lê o argumento da linha de comando.
2. Valida se o argumento foi fornecido.
3. Usa a classe RPN para avaliar a expressão.
4. Exibe o resultado ou uma mensagem de erro.

📌 Argumentação para Escolha de Containers
1️⃣ Por que usar `std::stack` no ex01 (RPN)?
Propósito do Exercício
No ex01, o objetivo é avaliar expressões matemáticas na notação polonesa reversa (RPN). Isso exige um container que:
- Permita armazenar operandos temporários.
- Siga a lógica de último a entrar, primeiro a sair (LIFO - Last In, First Out).
- Seja simples e eficiente para empilhar e desempilhar elementos.

Por que `std::stack` é a melhor escolha?
1. Lógica LIFO:
    - A notação polonesa reversa (RPN) exige que os operandos sejam processados na ordem inversa em que foram empilhados. O `std::stack` implementa exatamente essa lógica.
2. Operações Simples e Eficientes:
    - O `std::stack` fornece métodos simples para:
        - Empilhar (push) operandos.
        - Desempilhar (pop) operandos.
        - Acessar o topo (top) da pilha.
    - Todas essas operações têm complexidade O(1).
3. Foco na Pilha:
    - O `std::stack` é projetado especificamente para o uso como pilha, o que torna o código mais legível e intuitivo.
4. Evita Acesso Indevido:
    - O `std::stack` não permite acesso direto aos elementos intermediários, o que reduz o risco de manipulações incorretas.

Exemplo de Uso no Código
No método `applyOperator`, o `std::stack` é usado para retirar os dois últimos operandos, aplicar o operador e empilhar o resultado:
```cpp
int b = operands.top();
operands.pop();
int a = operands.top();
operands.pop();

switch (op) {
    case '+': operands.push(a + b); break;
    case '-': operands.push(a - b); break;
    case '*': operands.push(a * b); break;
    case '/':
        if (b == 0) throw std::runtime_error("Error: division by zero");
        operands.push(a / b);
        break;
}
```

Conclusão
O `std::stack` foi escolhido porque:
- Ele implementa a lógica LIFO necessária para avaliar expressões RPN.
- Ele é eficiente e fácil de usar para operações de empilhar e desempilhar.
- Ele reduz a complexidade do código, tornando-o mais legível e seguro.

> [!NOTE]
> 📌 Resumo Final
> Agora a classe RPN está em conformidade com a Forma Ortodoxa Canônica. Isso garante que a classe seja robusta e funcione corretamente em cenários que envolvam cópias ou atribuições.

---



![](https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/Ford-janson.gif/250px-Ford-janson.gif)
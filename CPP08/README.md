#### CPP08 - Resumo, Conceitos, Propósitos e Perguntas Respondidas
📌 CPP08 - ex00: Easy Find

Neste exercício, implementamos um template de função chamado easyfind, que busca a primeira ocorrência de um valor inteiro em um container de inteiros. Caso o valor não seja encontrado, a função pode lançar uma exceção ou retornar um valor de erro.

🚀 O Que Este Exercício Ensina?

🔹 Propósito

- Introduzir o uso de templates de função com containers da STL.
- Demonstrar como usar iteradores para percorrer containers.
- Praticar o uso de exceções para lidar com erros de busca.

🔹 Lições Importantes

✅ Templates de Funções
- Permitem criar funções genéricas que funcionam com diferentes tipos de containers.
- Evitam duplicação de código ao implementar a mesma lógica para diferentes containers.

✅ Iteradores
- São usados para percorrer os elementos de um container.
- Iteradores permitem acessar elementos de containers de forma genérica, sem depender de índices.

✅ Exceções
- A função pode lançar uma exceção caso o valor não seja encontrado no container.
- Isso permite que o programa lide com erros de forma estruturada.

🔹O que são containers?

Containers são estruturas de dados genéricas fornecidas pela STL (Standard Template Library) do C++. Eles são usados para armazenar e organizar coleções de elementos, como números, strings ou objetos. Cada tipo de container tem características específicas que o tornam adequado para diferentes cenários.

Containers Sequenciais:
- Armazenam elementos em uma sequência linear.
- A ordem dos elementos é mantida.
- Exemplos:
  - `std::vector:` Um array dinâmico que pode crescer ou diminuir de tamanho.
  - `std::list:` Uma lista duplamente encadeada.
  - `std::deque:` Um array dinâmico que permite inserções e remoções eficientes em ambas as extremidades.

📂 Declaração e Implementação

Arquivos Necessários:
📌 `easyfind.hpp` - Contém a implementação do template de função `easyfind`.
📌 `main.cpp` - Testes para verificar a funcionalidade da função `easyfind`.
📌 `Makefile` - Facilita a compilação.

📌 Explicação Detalhada das Operações

1️⃣ Template de Função easyfind
- A função easyfind é definida como:
  ```cpp
  template <typename T>
  typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
  }
  ```
- Parâmetros:
    - `T &container`: Um container de inteiros (ex.: `std::vector<int>`, `std::list<int>`).
    - `int value`: O valor a ser buscado no container.

- Funcionamento:
    - Usa a função std::find da biblioteca <algorithm> para buscar o valor no container.
    - Se o valor for encontrado, retorna o iterador correspondente.
    - Se o valor não for encontrado, lança uma exceção std::runtime_error.

2️⃣ Uso de Iteradores
- Iteradores são usados para percorrer os elementos do container.
- A função `std::find` retorna um iterador para o elemento encontrado ou `container.end()` se o elemento não for encontrado.

3️⃣ Exceções
- A função lança uma exceção caso o valor não seja encontrado.
- Isso permite que o programa lide com o erro de forma estruturada.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para criar uma função genérica que funcione com diferentes tipos de containers.

✅ Por que usamos iteradores em vez de índices?
- Nem todos os containers da STL suportam acesso por índice (ex.: std::list).
- Iteradores permitem acessar elementos de forma genérica.

✅ O que acontece se o valor não for encontrado no container?
- A função lança uma exceção std::runtime_error com a mensagem "Value not found in container".

✅ Por que usamos std::find em vez de implementar a busca manualmente?
- std::find é uma função padrão da STL, otimizada e fácil de usar.

✅ Como testar a função easyfind com diferentes containers?
- Crie containers como std::vector<int> e std::list<int> e passe-os para a função easyfind com valores existentes e inexistentes.

✅ Por que a função retorna um iterador?
- Retornar um iterador permite que o chamador acesse diretamente o elemento encontrado no container.

<details> 
<summary>✅ Checklist de Correção do Ex00 - Função Template (easyfind)</summary>

Função easyfind
✅ Template: A função easyfind deve ser implementada como um template.\
✅ Uso de STL Algorithms: A função deve usar algoritmos da STL, como std::find. Implementações manuais de busca com iteradores não são permitidas.\
✅ Parâmetros:
 - O primeiro parâmetro deve ser um container (ex.: std::vector<int>, std::list<int>).
 - O segundo parâmetro deve ser um inteiro (int), que será o valor a ser buscado.
✅ Retorno:
 - A função deve retornar um iterador para o elemento encontrado.
 - Caso o valor não seja encontrado, a função deve lançar uma exceção ou retornar um valor de erro.

Testes no main.cpp
✅ O arquivo main.cpp deve conter testes suficientes para provar que o programa funciona como esperado.\
✅ Testar com diferentes containers da STL, como:
 - std::vector<int>
 - std::list<int>
✅ Testar com valores existentes e inexistentes no container.\
✅ Garantir que a exceção seja lançada corretamente quando o valor não for encontrado.

Uso de STL\
✅ A função deve usar algoritmos da STL (como std::find) para realizar a busca.\
❌ Implementações manuais de busca com iteradores não são permitidas.

Ortodox Canonical Form\
✅ Todas as classes não relacionadas à interface (se houver) devem estar na Orthodox Canonical Form.
Isso significa que as classes devem ter:
 - Construtor padrão.
 - Construtor de cópia.
 - Operador de atribuição.
 - Destrutor.

Makefile\
✅ O Makefile deve compilar o programa com as flags -Wall -Wextra -Werror e -std=c++98.\
✅ O programa deve compilar sem erros ou avisos.

</details>

> [!NOTE]
> 🚀 Resumo Final
> Este exercício ensina a usar templates para criar funções genéricas e eficientes em C++. Implementamos a função `easyfind`, que busca a primeira ocorrência de um valor inteiro em um container de inteiros, explorando o uso de iteradores e exceções. Isso é essencial para evitar código repetitivo e tornar o código mais flexível e reutilizável.

---

📌 CPP08 - ex01: Span

Neste exercício, implementamos a classe Span, que armazena uma coleção de números inteiros e calcula a menor e a maior diferença entre eles. A classe utiliza containers da STL, iteradores e algoritmos padrão para manipular os números de forma eficiente.

📂 Declaração e Implementação

Arquivos Necessários:\
📌 `Span.hpp:` Declaração da classe Span.
📌 `Span.tpp:` Implementação do método template addRange.
📌 `Span.cpp:` Implementação dos métodos não-template da classe Span.
📌 `main.cpp:` Testes para verificar a funcionalidade da classe.
📌 `Makefile:` Facilita a compilação do programa.

📌 Explicação Detalhada das Operações

1️⃣ Classe Span

A classe `Span` armazena números inteiros em um container `(std::vector)` e fornece métodos para calcular a menor e a maior diferença entre os números armazenados.

2️⃣ Métodos Implementados

`addNumber(int number):`
- Adiciona um único número ao container.
- Lança uma exceção std::overflow_error se o número de elementos exceder o limite definido no construtor.

`addRange(Iterator begin, Iterator end):`
- Adiciona múltiplos números ao container usando um intervalo de iteradores.
- Lança uma exceção std::overflow_error se o intervalo exceder a capacidade restante do container.

`shortestSpan():`
- Calcula e retorna a menor diferença entre dois números no container.
- Lança uma exceção std::logic_error se houver menos de dois números armazenados.

`longestSpan():`
- Calcula e retorna a maior diferença entre dois números no container.
- Lança uma exceção std::logic_error se houver menos de dois números armazenados.

3️⃣ Uso de Templates
- O método addRange é implementado como um template para aceitar qualquer tipo de iterador.
- A implementação do template está no arquivo Span.tpp, que é incluído no final do arquivo Span.hpp.

4️⃣ Uso de STL
`std::vector:`
- Usado para armazenar os números.
`std::sort:`
- Usado para ordenar os números ao calcular o menor span.
`std::min_element` e `std::max_element:`
- Usados para encontrar os valores mínimo e máximo ao calcular o maior span.
`std::distance:`
- Usado para calcular o tamanho de um intervalo de iteradores.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos std::vector para armazenar os números?
- O std::vector é eficiente para armazenar e acessar elementos sequenciais, além de permitir inserções dinâmicas.

✅ Por que o método addRange é um template?
- Para permitir que ele aceite qualquer tipo de iterador, tornando-o genérico e reutilizável.

✅ O que acontece se tentarmos calcular o span com menos de dois números?
- Uma exceção std::logic_error é lançada, pois não é possível calcular spans com menos de dois números.

✅ Como o método shortestSpan funciona?
- Ele ordena os números e calcula a menor diferença entre números consecutivos.

✅ Como o método longestSpan funciona?
- Ele encontra o menor e o maior número no container e calcula a diferença entre eles.

✅ Por que usamos std::distance no método addRange?
- Para calcular o número de elementos no intervalo de iteradores fornecido.

<details> 
<summary>✅ Checklist de Correção do Ex01 - Span </summary>

Vamos revisar os arquivos fornecidos para garantir que o exercício atenda aos critérios de correção. Aqui está o checklist detalhado:

✅ Checklist de Correção

1️⃣ Função main
- Critério: Deve conter testes suficientes para provar que o programa funciona como esperado.
- Verificação:
  - O arquivo main.cpp contém testes para:
    - Adicionar números usando addNumber.
    - Calcular o menor (shortestSpan) e o maior (longestSpan) span.
    - Adicionar números em massa usando addRange.
    - Testar com 10.000 números.
  - Conclusão: ✅ Os testes são suficientes e cobrem os casos esperados.

2️⃣ Classe e Funções-Membro
- Critério: A classe deve cumprir as restrições do enunciado e usar algoritmos da STL para encontrar os resultados.
- Verificação:
  - A classe Span está implementada no arquivo Span.hpp e segue as restrições do enunciado:
    - Atributos:
      - _size: Define o número máximo de elementos.
      - _numbers: Um std::vector<int> para armazenar os números.
    - Funções-membro:
      - addNumber: Adiciona um único número ao container.
        - Lança uma exceção se o número de elementos exceder _size.
      - addRange: Adiciona múltiplos números usando iteradores.
        - Implementado como um template no arquivo Span.tpp.
        - Usa std::distance e std::vector::insert.
      - shortestSpan:
        - Ordena os números com std::sort.
        - Calcula a menor diferença entre números consecutivos.
        - Não depende apenas dos dois menores números, como exigido.
      - longestSpan:
        - Usa std::min_element e std::max_element para encontrar os valores mínimo e máximo.
        - Calcula a diferença entre eles.
- Conclusão: ✅ A classe e as funções-membro atendem aos requisitos e usam algoritmos da STL.

3️⃣ Forma Ortodoxa Canônica
- Critério: Todas as classes não relacionadas à interface devem estar na Orthodox Canonical Form.
- Verificação:
  - A classe Span implementa:
    - Construtor padrão.
    - Construtor parametrizado.
    - Construtor de cópia.
    - Operador de atribuição.
    - Destrutor.
  - Conclusão: ✅ A classe está na Orthodox Canonical Form.

4️⃣ Função addNumber Melhorada
- Critério: Deve haver uma maneira mais prática de adicionar números do que chamar addNumber repetidamente.
- Verificação:
  - A função addRange permite adicionar múltiplos números de uma só vez usando iteradores.
  - Testada no main.cpp com 10.000 números.
  - Conclusão: ✅ A função addRange melhora a adição de números de forma prática.

5️⃣ Uso de STL
- Critério: As funções-membro devem usar algoritmos da STL sempre que possível.
- Verificação:
  - shortestSpan:
    - Usa std::sort para ordenar os números.
    - Calcula a menor diferença entre números consecutivos.
  - longestSpan:
    - Usa std::min_element e std::max_element para encontrar os valores mínimo e máximo.
  - addRange:
    - Usa std::distance para calcular o tamanho do intervalo.
    - Usa std::vector::insert para adicionar os números.
- Conclusão: ✅ Os algoritmos da STL são usados de forma eficiente.

6️⃣ Makefile
- Critério: O Makefile deve compilar o programa com as flags -Wall -Wextra -Werror e -std=c++98.
- Verificação:
  - O Makefile compila os arquivos corretamente com as flags exigidas.
  - O programa compila sem erros ou avisos.
  - Conclusão: ✅ O Makefile está correto.

</details>

> [!NOTE]
> 🚀 Resumo Final
> Este exercício ensina como criar uma classe que utiliza containers da STL, iteradores e algoritmos padrão para manipular coleções de números inteiros. A classe Span é eficiente, genérica e fácil de usar, demonstrando o poder da STL em C++. Se precisar de mais ajuda, é só perguntar! 😊

---

📌 CPP08 - ex02: MutantStack

Neste exercício, implementamos a classe `MutantStack`, que é baseada no container `std::stack` da STL. O objetivo é tornar o `std::stack` iterável, adicionando suporte a iteradores, enquanto preservamos todas as funcionalidades originais do `std::stack`.

📂 Declaração e Implementação\
Arquivos Necessários:

📌 `MutantStack.hpp:` Declaração e implementação da classe MutantStack.
📌 `main.cpp:` Testes para verificar a funcionalidade da classe.
📌 `Makefile:` Facilita a compilação do programa.

📌 Explicação Detalhada das Operações
1️⃣ Classe MutantStack
- A classe MutantStack é baseada no `std::stack` e adiciona suporte a iteradores, permitindo que o container seja percorrido como outros containers da STL.

2️⃣ Métodos Implementados
- Construtores e Destrutor:
  - Construtor padrão, construtor de cópia, operador de atribuição e destrutor são implementados para seguir a Orthodox Canonical Form.
- Iteradores:
  - begin(): Retorna um iterador para o início da pilha.
  - end(): Retorna um iterador para o final da pilha.
- Métodos Herdados do `std::stack`:
  - Todos os métodos originais do `std::stack` (como push, pop, top, size) são preservados.

3️⃣ Uso de Templates
- A classe MutantStack é implementada como um template para permitir que funcione com diferentes tipos de dados.

4️⃣ Testes
- O arquivo main.cpp contém testes para:
  - Adicionar e remover elementos da pilha.
  - Iterar sobre os elementos usando os iteradores begin() e end().
  - Comparar a saída com outros containers iteráveis, como std::list.

<details> 
<summary>✅ Checklist de Correção do Ex02 - Mutated Abomination </summary>

Vamos revisar os arquivos fornecidos para garantir que o exercício atenda aos critérios de correção. Aqui está o checklist detalhado:

✅ Checklist de Correção

1️⃣ Função main()
- Critério: Deve conter testes suficientes para provar que o programa funciona como esperado.
- Verificação:
  - O arquivo main.cpp contém:
    - Testes para adicionar e remover elementos da pilha.
    - Testes para iterar sobre os elementos usando os iteradores begin() e end().
    - Testes adicionais que vão além do exemplo fornecido no enunciado.
  - Conclusão: ✅ Os testes são suficientes e cobrem os casos esperados.

2️⃣ Classe MutantStack
- Critério: Deve herdar de std::stack e oferecer todos os seus métodos, além de suporte a iteradores.
- Verificação:
  - A classe MutantStack está implementada no arquivo MutantStack.hpp e:
    - Herda de std::stack.
    - Preserva todos os métodos originais do std::stack (como push, pop, top, size).
    - Adiciona suporte a iteradores (begin() e end()).
    - Implementada como um template para funcionar com diferentes tipos de dados.
  - Conclusão: ✅ A classe atende aos requisitos e adiciona suporte a iteradores.

3️⃣ Forma Ortodoxa Canônica
- Critério: Todas as classes não relacionadas à interface devem estar na Orthodox Canonical Form.
- Verificação:
  - A classe MutantStack implementa:
    - Construtor padrão.
    - Construtor de cópia.
    - Operador de atribuição.
    - Destrutor.
  - Conclusão: ✅ A classe está na Orthodox Canonical Form.

4️⃣ Iteradores
- Critério: Deve ser possível realizar as operações mostradas no exemplo do enunciado usando iteradores.
- Verificação:
  - A classe MutantStack implementa os métodos:
    - begin(): Retorna um iterador para o início da pilha.
    - end(): Retorna um iterador para o final da pilha.
  - O arquivo main.cpp contém testes que:
    - Iteram sobre os elementos da pilha usando begin() e end().
    - Realizam operações como incremento (++) e decremento (--) nos iteradores.
  - Conclusão: ✅ Os iteradores estão implementados corretamente e funcionam como esperado.

5️⃣ Testes Adicionais
- Critério: Deve haver pelo menos uma função main() com mais testes do que os fornecidos no exemplo do enunciado.
- Verificação:
  - O arquivo main.cpp contém:
    - Testes para o construtor de cópia e o operador de atribuição.
    - Testes para comparar a funcionalidade da MutantStack com outros containers iteráveis (std::list, std::deque, std::vector).
  - Conclusão: ✅ Os testes adicionais estão presentes e cobrem diferentes cenários.

</details>

> [!NOTE]
> 🚀 Resumo Final
> Este exercício ensina como estender um container da STL (std::stack) para adicionar funcionalidades ausentes, como suporte a iteradores. A classe MutantStack é eficiente, genérica e fácil de usar, demonstrando como aproveitar a flexibilidade da STL em C++. Se precisar de mais ajuda, é só perguntar! 😊

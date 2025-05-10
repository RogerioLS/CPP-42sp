### CPP07 - Resumo, Conceitos, Propósitos e Perguntas Respondidas

📌 CPP07 - ex00:  Start with a few functions

Neste exercício, implementamos templates de funções para operações genéricas com diferentes tipos de dados. Especificamente, criamos as funções:
- swap → Troca os valores de dois argumentos.
- min → Retorna o menor entre dois valores (se forem iguais, retorna o segundo).
- max → Retorna o maior entre dois valores (se forem iguais, retorna o segundo).


Todas essas funções devem ser implementadas como templates, permitindo que sejam usadas com qualquer tipo de dado que suporte operadores de comparação.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Introduzir o conceito de templates em C++.
- Escrever funções que podem operar com múltiplos tipos de dados.
- Praticar a comparação de valores genéricos de forma segura e reutilizável.

🔹 Lições Importantes

✅ Templates de Funções
- Permitem criar funções genéricas que funcionam para diversos tipos de dados.
- Evitam código repetitivo ao escrever a mesma lógica para int, float, double, etc.
- São definidos usando template `<typename T>` antes da função.

✅ Uso de Operadores de Comparação
- min e max utilizam os operadores < e >.
- Isso significa que só funcionam com tipos que suportam essas operações.

✅ Passagem por Referência
- A função swap recebe os argumentos por referência (T&), permitindo modificar os valores originais.

📂 Declaração e Implementação

Arquivos Necessários:\
📌 `whatever.hpp` - Contém a implementação dos templates.
📌 `main.cpp` - Testes para verificar as funções implementadas.
📌 `Makefile` - Facilita a compilação.



📌 Explicação Detalhada das Operações:\
1️⃣ Templates em C++
- template <typename T> define um modelo genérico.
- A função pode ser usada com qualquer tipo (int, double, std::string, etc.).
- O compilador gera a versão correta conforme o tipo usado no código.

2️⃣ Função swap
- Troca os valores entre a e b sem criar cópias desnecessárias.
- Usa passagem por referência (T&) para modificar os valores originais.

3️⃣ Função min
- Usa operador < para comparar os valores.
- Retorna o menor dos dois argumentos, ou o segundo se forem iguais.

4️⃣ Função max
- Usa operador > para comparar os valores.
- Retorna o maior dos dois argumentos, ou o segundo se forem iguais.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para escrever código genérico e reutilizável, funcionando com vários tipos de dados.

✅ Por que a função swap usa passagem por referência (T&)?
- Para modificar os valores originais sem criar cópias desnecessárias.

✅ Por que min e max retornam o segundo valor em caso de empate?
- Para garantir que o retorno seja consistente em caso de igualdade.

✅ Por que as funções min e max recebem argumentos const T&?
- Para evitar cópias desnecessárias e garantir que os valores não sejam modificados.

✅ O que acontece se tentarmos usar min ou max com um tipo que não suporta < ou >?
- O código não compilará, pois os operadores são necessários para a comparação.

<details> 
<summary>✅ Checklist de Correção do Ex00 - Funções Template (swap, min, max)</summary>
🔹 Estrutura e Implementação

✅ Makefile
- O código compila corretamente com as flags adequadas: -Wall -Wextra -Werror.

As funções swap(), min() e max() estão implementadas corretamente como templates.

✅ Função swap()
- A função swap(T &a, T &b) troca corretamente os valores das variáveis passadas como referência.
- troca de valores é feita sem usar variáveis globais ou bibliotecas externas.

✅ Função min()
- A f📌 CPP07 - ex00:  Start with a few functions

Neste exercício, implementamos templates de funções para operações genéricas com diferentes tipos de dados. Especificamente, criamos as funções:
- swap → Troca os valores de dois argumentos.
- min → Retorna o menor entre dois valores (se forem iguais, retorna o segundo).
- max → Retorna o maior entre dois valores (se forem iguais, retorna o segundo).

Todas essas funções devem ser implementadas como templates, permitindo que sejam usadas com qualquer…car os valores originais sem criar cópias desnecessárias.

✅ Por que min e max retornam o segundo valor em caso de empate?
- Para garantir que o retorno seja consistente em caso de igualdade.

✅ Por que as funções min e max recebem argumentos const T&?
- Para evitar cópias desnecessárias e garantir que os valores não sejam modificados.

✅ O que acontece se tentarmos usar min ou max com um tipo que não suporta < ou >?
- O código não compilará, pois os operadores são necessários para a comparação.unção min(T const &a, T const &b) retorna corretamente o menor dos dois valores.
- O operador de comparação < é usado corretamente para definir o menor valor.

✅ Função max()
- A função max(T const &a, T const &b) retorna corretamente o maior dos dois valores.
- O operador de comparação > é utilizado de maneira correta.

✅ Teste com Tipos Simples (int, float, double, char)
- As funções funcionam corretamente com tipos escalares como int, float, double, e char.

✅ Teste com Tipos Complexos (classe Awesome)
- As funções devem ser compatíveis com tipos personalizados, como a classe Awesome.
- Os operadores de comparação (==, !=, >, <, >=, <=) foram sobrecarregados corretamente.
- A sobrecarga do operador de saída operator<< permite a correta exibição dos valores.

✅ Saída Esperada para o Código Fornecido
A execução do código abaixo:

```cpp
Awesome a(2), b(4);
swap(a, b);
std::cout << a << " " << b << std::endl;
std::cout << max(a, b) << std::endl;
std::cout << min(a, b) << std::endl;
```
Deve imprimir:
```cpp
4 2  
4  
2
```

❓ Perguntas Possíveis na Avaliação

✅ Por que usar templates para essas funções?
- Templates permitem que as funções funcionem com diferentes tipos de dados, sem precisar reescrevê-las para cada tipo.

✅ Por que precisamos sobrecarregar os operadores na classe Awesome?
- Para que as funções swap(), min() e max() possam comparar objetos Awesome, os operadores de comparação precisam estar definidos.

✅ O que acontece se tentarmos usar min() ou max() com um tipo que não tem operadores de comparação?
- O código falhará na compilação, pois os operadores < e > são obrigatórios para essas funções.

✅ A função swap() poderia ser implementada sem usar templates?
- Sim, mas teríamos que criar versões separadas para cada tipo (int, float, char, etc.), o que resultaria em código redundante.

✅ Por que swap() recebe os argumentos por referência (T &a, T &b)?
- Para modificar diretamente os valores das variáveis passadas sem criar cópias desnecessárias.

✅ Qual é o propósito do const em min() e max()?
- Ele garante que os valores passados não sejam modificados dentro da função.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício ensina a usar templates para criar funções genéricas e eficientes em C++.
> Implementamos swap, min e max, explorando passagem por referência e operadores de comparação.
> Isso é essencial para evitar código repetitivo e tornar o código mais flexível e reutilizável.

---

📌 CPP07 - ex01: Iter

Neste exercício, implementamos um template de função chamado iter, que permite aplicar uma função a cada elemento de um array de forma genérica. A função iter é projetada para funcionar com qualquer tipo de array e qualquer função que possa ser aplicada aos elementos do array.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Introduzir o conceito de templates de função que aceitam múltiplos parâmetros genéricos.
- Demonstrar como aplicar funções a elementos de um array de forma genérica e eficiente.
- Praticar o uso de templates para criar código reutilizável e flexível.

🔹 Lições Importantes

✅ Templates de Funções
- Permitem criar funções genéricas que funcionam para diversos tipos de dados.
- Evitam código repetitivo ao escrever a mesma lógica para diferentes tipos de arrays.
- São definidos usando template `<typename T>` antes da função.

✅ Iteração sobre Arrays
- A função iter percorre cada elemento do array e aplica uma função a ele.
- Usa um loop for para iterar sobre os elementos do array.

✅ Funções como Parâmetros
- A função iter aceita uma função como parâmetro, permitindo que qualquer lógica seja aplicada aos elementos do array.
- Isso inclui funções normais e funções templates.

📂 Declaração e Implementação

Arquivos Necessários:
📌 `iter.hpp` - Contém a implementação do template de função iter.
📌 `main.cpp` - Testes para verificar a funcionalidade da função iter.
📌 `Makefile` - Facilita a compilação.

📌 Explicação Detalhada das Operações:

1️⃣ Template de Função iter
- A função iter é definida como:
Parâmetros:
  ```cpp
  template <typename T, typename Func>
  void iter(T *array, size_t length, Func function) {
        for (size_t i = 0; i < length; i++)
            function(array[i]);
    }   
  ```
- T *array: Um ponteiro para o array.
- size_t length: O tamanho do array.
- Func function: Uma função que será aplicada a cada elemento do array.
- Funcionamento:
    - A função percorre o array usando um loop for.
    - Para cada elemento, chama a função passada como parâmetro, aplicando-a ao elemento atual.

2️⃣ Funções Auxiliares
- Função printElement:
    - Imprime um elemento do array.
    - Exemplo:
    ```cpp
    template <typename T>
    void printElement(T element) {
        std::cout << element << std::endl;
    }
    ```
- Função increment:
    - Incrementa o valor de um elemento do array (apenas para tipos numéricos).
    - Exemplo:
    ```cpp
    void increment(int &element) {
        element++;
    }
    ```
3️⃣ Testes no main.cpp
- Testa a função iter com diferentes tipos de arrays (int e char).
- Aplica funções como printElement e increment aos elementos do array.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para criar uma função genérica que funcione com qualquer tipo de array e qualquer função aplicável aos elementos.

✅ Por que a função iter aceita uma função como parâmetro?
- Para permitir que diferentes operações sejam aplicadas aos elementos do array, tornando o código mais flexível.

✅ Como a função iter garante que funcione com diferentes tipos de dados?
- O uso de template <typename T> permite que a função seja instanciada para qualquer tipo de dado.

✅ O que acontece se a função passada para iter não for compatível com os elementos do array?
- O código não compilará, pois o tipo da função deve ser compatível com o tipo dos elementos do array.

✅ Por que usamos size_t para o comprimento do array?
- size_t é um tipo sem sinal projetado para representar tamanhos e índices de arrays, garantindo portabilidade e evitando valores negativos.

✅ Como testar a função iter com diferentes tipos de dados?
- Crie arrays de diferentes tipos (int, char, float, etc.) e passe funções compatíveis para iter.

<details> 
<summary>✅ Checklist de Correção do Ex01 - Função Template (iter)</summary>

🔹 **Estrutura e Implementação**

✅ **Makefile**  
- O código compila corretamente com as flags adequadas: `-Wall -Wextra -Werror`.  
- Exemplo de comando para compilar:  
  ```bash
  g++ -Wall -Wextra -Werror -std=c++98 sources/main.cpp -o ex01

✅ Função iter
- A função iter está implementada corretamente como um template.
- Aceita três parâmetros:
    - Um ponteiro para o array.
    - O tamanho do array (size_t).
    - Uma função que será aplicada a cada elemento do array.
- A função percorre o array usando um loop for e aplica a função passada como parâmetro a cada elemento.

✅ Compatibilidade com Diferentes Tipos
- A função iter funciona com arrays de diferentes tipos (int, char, float, etc.).
- Funciona com funções normais e funções templates passadas como parâmetro.

✅ Funções Auxiliares
- Funções auxiliares como print e increment estão implementadas corretamente para testar a funcionalidade de iter.

🔹 Testes no main.cpp

✅ Teste com Tipos Simples
- O código testa a função iter com arrays de tipos simples, como int e char.
- Exemplo de saída esperada para um array de inteiros:
  ```cpp
  Array original: 1 2 3 4 5
  Array increment: 2 3 4 5 6
  ```

✅ Teste com Tipos Personalizados (Classe Awesome)
- O código testa a função iter com a classe Awesome.
- A classe Awesome está implementada corretamente com:
    - Um construtor padrão que inicializa _n com 42.
    - Um método get() para acessar o valor de _n.
    - Um operador de saída (operator<<) para exibir o valor de _n.
- Exemplo de saída esperada para um array de objetos Awesome:
  ```cpp
    42
    42
    42
    42
    42
  ```
❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para criar uma função genérica que funcione com qualquer tipo de array e qualquer função aplicável aos elementos.

✅ Por que a função iter aceita uma função como parâmetro?
- Para permitir que diferentes operações sejam aplicadas aos elementos do array, tornando o código mais flexível.

✅ Como a função iter garante que funcione com diferentes tipos de dados?
- O uso de template <typename T> permite que a função seja instanciada para qualquer tipo de dado.

✅ O que acontece se a função passada para iter não for compatível com os elementos do array?
- O código não compilará, pois o tipo da função deve ser compatível com o tipo dos elementos do array.

✅ Por que usamos size_t para o comprimento do array?
- size_t é um tipo sem sinal projetado para representar tamanhos e índices de arrays, garantindo portabilidade e evitando valores negativos.

✅ Como testar a função iter com diferentes tipos de dados?
- Crie arrays de diferentes tipos (int, char, float, etc.) e passe funções compatíveis para iter.

✅ Por que a classe Awesome precisa de um operador de saída (operator<<)?
- Para permitir que os objetos da classe sejam exibidos corretamente no console usando std::cout.

✅ A função iter poderia ser implementada sem templates?
- Não de forma genérica. Sem templates, seria necessário criar versões separadas para cada tipo de array, o que resultaria em código redundante.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício ensina a usar templates para criar funções genéricas e eficientes em C++.
> Implementamos a função iter, que aplica uma função a cada elemento de um array, explorando o uso de templates e funções como parâmetros.
> Isso é essencial para evitar código repetitivo e tornar o código mais flexível e reutilizável.

---

📌 CPP07 - ex02: Array

Neste exercício, implementamos uma classe template chamada `Array`, que funciona como um array genérico capaz de armazenar elementos de qualquer tipo. A classe oferece funcionalidades como criação, cópia, atribuição, acesso por índice e verificação de tamanho, além de lançar exceções para acessos fora dos limites.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Introduzir o conceito de classes templates em C++.
- Demonstrar como criar uma classe genérica que pode armazenar elementos de qualquer tipo.
- Praticar a implementação de operadores e tratamento de exceções.

🔹 Lições Importantes

✅ Templates de Classe
- Permitem criar classes genéricas que funcionam para diversos tipos de dados.
- Evitam duplicação de código ao implementar a mesma lógica para diferentes tipos.

✅ Gerenciamento de Memória
- A classe utiliza new[] para alocar memória dinamicamente e delete[] para liberar a memória.
- Garante que não há acesso a memória não alocada.

✅ Operadores Sobrecarga
- O operador [] é sobrecarregado para permitir acesso aos elementos do array.
- O operador de atribuição (=) é implementado para copiar corretamente os dados de outro array.

✅ Tratamento de Exceções
- A classe lança uma exceção (std::out_of_range) ao tentar acessar um índice fora dos limites do array.

📂 Declaração e Implementação

Arquivos Necessários:
📌 `Array.hpp` - Contém a declaração da classe template Array.
📌 `Array.tpp` - Contém a implementação dos métodos da classe template Array.
📌 `main.cpp` - Testes para verificar a funcionalidade da classe Array.
📌 `Makefile` - Facilita a compilação.
 
❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para criar uma classe genérica que funcione com qualquer tipo de dado.

✅ Por que usamos new[] para alocar memória?
- Para garantir que a memória seja alocada dinamicamente e que o tamanho do array seja definido em tempo de execução.

✅ Como o operador de atribuição (=) garante que os dados sejam independentes?
- Ele aloca nova memória para o array e copia os dados do array original, garantindo que as alterações em um não afetem o outro.

✅ O que acontece se tentarmos acessar um índice fora dos limites do array?
- Uma exceção std::out_of_range é lançada, indicando que o índice é inválido.

✅ Por que o método size é const?
- Para garantir que ele não modifique o estado do objeto.

✅ Como testar a classe Array com diferentes tipos de dados?
- Crie instâncias da classe Array com diferentes tipos (int, float, std::string, etc.) e verifique se todas as operações funcionam corretamente.

<details> 
<summary>✅ Checklist de Correção do Ex02 - Classe Template (Array)</summary>

🔹 Estrutura e Implementação

✅ Makefile  
- O código compila corretamente com as flags adequadas: `-Wall -Wextra -Werror`.  
- Exemplo de comando para compilar:  
  ```bash
  g++ -Wall -Wextra -Werror -std=c++98 sources/main.cpp -o ex02

✅ Classe Template Array
- A classe Array está implementada corretamente como um template.
- Funciona com arrays de tipos simples (int, float, etc.) e tipos complexos (como classes personalizadas).

✅ Construtores
- Construtor Padrão: Cria um array vazio.
- Construtor Parametrizado: Cria um array com n elementos inicializados por padrão.
- Construtor de Cópia: Cria uma cópia de outro array, garantindo que os dados sejam independentes.

✅ Destrutor
- Libera a memória alocada dinamicamente com delete[].

✅ Operadores Sobrecarga
- Operador []: Permite acessar os elementos do array para leitura e escrita.
- Lança uma exceção (std::out_of_range) ao tentar acessar um índice fora dos limites.
- Operador de Atribuição (=): Copia os dados de outro array, garantindo que os dados sejam independentes.

✅ Método size
- Retorna o tamanho do array.
- É declarado como const para garantir que não modifique o estado do objeto.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos templates neste exercício?
- Para criar uma classe genérica que funcione com qualquer tipo de dado.

✅ Por que usamos new[] para alocar memória?
- Para garantir que a memória seja alocada dinamicamente e que o tamanho do array seja definido em tempo de execução.

✅ Como o operador de atribuição (=) garante que os dados sejam independentes?
- Ele aloca nova memória para o array e copia os dados do array original, garantindo que as alterações em um não afetem o outro.

✅ O que acontece se tentarmos acessar um índice fora dos limites do array?
- Uma exceção std::out_of_range é lançada, indicando que o índice é inválido.

✅ Por que o método size é const?
- Para garantir que ele não modifique o estado do objeto.

✅ Como testar a classe Array com diferentes tipos de dados?
- Crie instâncias da classe Array com diferentes tipos (int, float, std::string, etc.) e verifique se todas as operações funcionam corretamente.

✅ Por que o operador [] precisa lançar uma exceção para índices fora dos limites?
- Para evitar comportamento indefinido e garantir que o programa lide corretamente com erros de acesso.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício ensina a criar uma classe template genérica em C++, explorando conceitos como gerenciamento de memória, sobrecarga de operadores e tratamento de exceções.
> A classe Array é flexível, reutilizável e segura, garantindo que os dados sejam manipulados corretamente e que erros sejam tratados de forma adequada.

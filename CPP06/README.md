### CPP06 - Resumo, Conceitos, Propósitos e Perguntas Respondidas

📌 CPP06 - ex00: Conversion of Scalar Types

Neste exercício, implementamos a classe ScalarConverter, que converte uma string representando um literal em C++ para diferentes tipos escalares:
- char
- int
- float
- double

Além disso, lidamos com casos especiais como NaN e infinitos. Este exercício também reforça o uso correto de casts em C++.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Entender como converter diferentes tipos de dados em C++.
- Aprender sobre **type casting** (conversão de tipos).
- Implementar conversões de forma segura, evitando overflow e valores inválidos.
- Trabalhar com **pseudo-literais** como `nan`, `+inf`, `-inf`.

🔹 Lições Importantes

✅ Conversão entre Tipos
- Converte `std::string` para diferentes tipos escalares.
- Usa **casting explícito** para evitar perda de precisão e erros de conversão.

✅ Tipo de Casting em C++
- `static_cast` → Conversões seguras entre tipos conhecidos.
- `reinterpret_cast` → Conversões de ponteiros (não utilizado aqui).
- `const_cast` → Remove const de um tipo (não utilizado aqui).
- `dynamic_cast` → Conversão entre classes polimórficas (não aplicável neste exercício).

✅ Detecção de Tipo
- Determina se a entrada é um char, int, float ou double antes de converter.

✅ Lidando com Casos Especiais
- `nan` (`Not a Number`)
- `+inf` e `-inf` (valores infinitos)
- Valores que não podem ser representados corretamente em certos tipos.

📂 Declaração e Implementação

Arquivos Necessários

📌 `ScalarConverter.hpp` - Declaração da classe.

📌 `ScalarConverter.cpp` - Implementação dos métodos de conversão.

📌 `main.cpp` - Testes para verificar a conversão.


📌 Objetivo do Exercício

Criar a classe `ScalarConverter` com:

Atributos
- Nenhum, pois a classe não deve ser instanciada.
Métodos Públicos
```c++
class ScalarConverter {
public:
    static void convert(std::string input);
};
```
- convert(std::string input)
	- Detecta o tipo do input.
	- Converte para `char`, `int`, `float`, `double`.
	- Imprime os resultados ou mensagens de erro.

📌 Explicação Detalhada das Operações

1️⃣ Conversão de Tipos
- char → int, float, double
- int → char, float, double
- float → char, int, double
- double → char, int, float

Exemplo de conversão:
```c++
int value = static_cast<int>(42.7);  // Trunca para 42
```
2️⃣ Detectando o Tipo do Input
- Se for um caractere entre aspas simples, trata como `char`.
- Se contiver apenas dígitos e sinal opcional, trata como `int`.
- Se terminar com **'f'**, trata como `float`.
- Se contiver **ponto decimal, mas sem 'f'**, trata como `double`.

3️⃣ Lidando com Pseudo-Literais
- nan, -inf, +inf são detectados separadamente.
- São válidos para float e double, mas não para char e int.

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos `static_cast` ao invés de `reinterpret_cast`?
- `static_cast` é seguro para conversões entre tipos numéricos, enquanto `reinterpret_cast` é usado para conversões de ponteiros.

✅ O que acontece se tentarmos converter `nan` para um `int`?
- `nan` não é representável como `int`, então devemos exibir `"impossible"`.

✅ Como detectamos que o input é um float ou double?
- Se termina em `'f'`, é `float`. Se tem ponto decimal e não `'f'`, é `double`.

✅ O que acontece ao converter um número grande para char?
- Se estiver fora da faixa de `char` (0-127 para ASCII), a conversão não será válida.

✅ Por que a classe `ScalarConverter` não tem atributos ou construtores?
- Como só precisamos de um método `convert`, a classe é feita apenas com métodos estáticos e não precisa ser instanciável.

<details> <summary>✅ Checklist de Correção do Ex00 - Conversão de Tipos Escalares</summary>

🔹 Estrutura e Implementação

✅ Makefile
- O código compila com as flags corretas: -Wall -Wextra -Werror.

✅ Classe ScalarConverter
- Existe uma classe ScalarConverter corretamente definida para realizar a conversão de tipos escalares.

✅ Método de Conversão
- O método convert() está corretamente implementado para receber uma string e realizar a conversão para os tipos char, int, float e double.

✅ Verificações de Entrada
- Verificações adequadas para entradas inválidas, como caracteres que não podem ser convertidos para um tipo numérico.
- A entrada é validada antes de tentar a conversão com o uso de strtod e strtof.

✅ Uso de static_cast
- O programa utiliza static_cast corretamente para converter entre os tipos numéricos (float, double, int, char).
- O uso de static_cast para conversões entre tipos está conforme esperado no exercício.

✅ Tratamento de Valores Especiais
- A conversão lida adequadamente com valores especiais como inff, inf, nanf, nan, +inff, -inff, etc.

✅ Impressão dos Resultados
- A saída para cada tipo (char, int, float, double) está correta.
- A mensagem "impossible" é impressa quando o valor não pode ser representado em um tipo específico.

✅ Exceções e Casos Especiais
- Para entradas inválidas, o código imprime "Invalid input" conforme solicitado.

❓ Perguntas Possíveis na Avaliação

✅ Por que a conversão para char é realizada com static_cast<char>(n)?
- O static_cast é usado para garantir que o valor numérico seja convertido de forma segura para o tipo char.

✅ Como o programa lida com números que não podem ser representados em certos tipos?
- O programa verifica se o número está fora dos limites dos tipos e imprime "impossible" para char, int, float ou double quando aplicável.

✅ Por que a verificação de entrada é importante antes da conversão?
- A verificação de entrada garante que não tentemos converter strings que não são números válidos, evitando erros e falhas de segmentação.

✅ O que acontece se tentarmos converter um valor não numérico?
- O programa imprimirá "Invalid input" se a string não puder ser convertida em um número válido.

✅ Por que o uso de static_cast é importante neste exercício?
- O static_cast garante que as conversões sejam realizadas de forma segura e explícita entre tipos, mantendo o controle do tipo de dados.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício nos ensina a realizar a conversão entre diferentes tipos escalares em C++, utilizando o `static_cast` de maneira segura e eficiente. Aprendemos a tratar valores especiais, como `inff` e `nan`, e a garantir que entradas inválidas sejam corretamente identificadas e tratadas. O uso de funções auxiliares para imprimir os valores convertidos e a validação prévia da entrada são essenciais para um comportamento robusto do programa. O exercício também reforça a importância de um design claro, utilizando conversões explícitas para evitar erros de tipo e oferecendo uma saída formatada corretamente.

---

📌 CPP06 - Ex01: Serialization

Neste exercício, implementamos a classe `Serializer`, que permite realizar a serialização e desserialização de um ponteiro para um objeto. A classe não pode ser instanciada, e seus métodos são estáticos. Os métodos principais são:
- `serialize(Data* ptr)` - Converte um ponteiro de um objeto `Data` para um valor do tipo `uintptr_t`.
- `deserialize(uintptr_t raw)` - Converte um valor do tipo `uintptr_t` de volta para um ponteiro de `Data`.

O exercício ensina como realizar a conversão entre ponteiros e inteiros, usando o tipo uintptr_t, de forma a garantir que a conversão possa ser feita com segurança e que o ponteiro seja recuperado corretamente após a desserialização.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Entender como serializar e desserializar objetos em C++.
- Aprender a usar o tipo uintptr_t para armazenar endereços de memória como inteiros.
- Garantir que a desserialização recupere o ponteiro original corretamente.

🔹 Lições Importantes

✅ Serialização de Ponteiros
- O método serialize() converte um ponteiro para uintptr_t e armazena o endereço de memória como um número inteiro.
- O método deserialize() converte o valor de volta para um ponteiro válido.

✅ Tipo uintptr_t
- `uintptr_t` é um tipo inteiro capaz de armazenar qualquer ponteiro, garantindo que a conversão de ponteiro para inteiro e vice-versa seja segura e precisa.

✅ Uso de Métodos Estáticos
- A classe `Serializer` não deve ser instanciada, e todos os métodos são estáticos.

📂 Declaração e Implementação

Arquivos Necessários:

📌 `Serializer.hpp `- Declaração da classe `Serializer`.

📌 `Serializer.cpp` - Implementação dos métodos de serialização e desserialização.

📌 `main.cpp` - Teste para verificar a serialização e desserialização.

📌 Objetivo do Exercício

Criar a classe `Serializer` com os seguintes métodos:

Métodos Públicos:
```c++
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
```
- serialize(Data ptr)*
	- Converte o ponteiro ptr para uintptr_t e retorna o valor serializado.
- deserialize(uintptr_t raw)
	- Converte o valor raw de volta para um ponteiro do tipo Data*.

📌 Explicação Detalhada das Operações

1️⃣ Serialização de Ponteiros
- `uintptr_t serialize(Data* ptr)` usa a conversão para armazenar o endereço de ptr como um inteiro.
- Exemplo de serialização:
  ```c++
  uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
  ```

2️⃣ Desserialização
- `Data* deserialize(uintptr_t raw)` usa a conversão de volta para o tipo de ponteiro original.
- Exemplo de desserialização:
  ```c++
  Data* ptr = reinterpret_cast<Data*>(raw);
  ```

3️⃣ Teste de Consistência
- Após a serialização e desserialização, o ponteiro original e o ponteiro recuperado devem ser iguais.
  ```c++
  assert(ptr == deserialize(serialize(ptr)));
  ```

❓ Perguntas Possíveis na Avaliação

✅ Por que usamos reinterpret_cast em vez de static_cast?
- O reinterpret_cast é usado aqui para converter entre ponteiros e inteiros de forma eficiente e sem restrições de tipo, já que estamos lidando com endereços de memória.

✅ Qual a vantagem de usar uintptr_t?
- uintptr_t é um tipo inteiro projetado para armazenar ponteiros, garantindo que a conversão entre ponteiros e inteiros seja segura e independente de plataforma.

✅ Como garantimos que a desserialização funciona corretamente?
- O teste compara o ponteiro original com o ponteiro recuperado após a serialização e desserialização, garantindo que os dois sejam iguais.

✅ É possível realizar serialização e desserialização com outros tipos de dados?
- Sim, mas é necessário garantir que o tipo usado seja compatível com o tipo uintptr_t, ou seja, um ponteiro.

<details> <summary>✅ Checklist de Correção do Ex01 - Serialization</summary>
🔹 Estrutura e Implementação

✅ Makefile
- O código compila com as flags corretas: -Wall -Wextra -Werror.

✅ Classe Serializer
- Existe uma classe Serializer corretamente definida para realizar a serialização e desserialização.

✅ Métodos Serialize e Deserialize
- O método serialize() utiliza reinterpret_cast corretamente para converter de Data* para uintptr_t.
O método deserialize() utiliza reinterpret_cast corretamente para converter de uintptr_t de volta para Data*.

✅ Uso do reinterpret_cast
- O reinterpret_cast é usado corretamente em ambos os métodos: de Data* para uintptr_t e de volta de uintptr_t para Data*, conforme solicitado.

✅ Estrutura Data
- A estrutura Data é definida corretamente e é utilizável após a desserialização, sem causar problemas de corrupção de dados.

✅ Tratamento de Memória
- A memória é manipulada corretamente e o código não apresenta vazamentos (sem uso de new para alocação de memória sem desalocação).

✅ Validação e Saída
- A serialização e desserialização funcionam corretamente e os resultados são apresentados de forma legível, com a verificação se os dados de Data após a desserialização são os mesmos que os originais.

✅ Compilação e Execução
- O programa compila sem erros, e a execução gera resultados válidos quando o código é testado.

❓ Perguntas Possíveis na Avaliação

✅ Por que o uso de reinterpret_cast?
- O reinterpret_cast é usado para realizar uma conversão entre ponteiros e inteiros (no caso, de Data* para uintptr_t), permitindo que a memória seja tratada como um número inteiro, o que é necessário para serialização.

✅ O que é uintptr_t e por que ele é usado aqui?
- uintptr_t é um tipo de dado inteiro sem sinal que pode armazenar um ponteiro. Ele é usado para converter o ponteiro Data* em um número inteiro, que pode ser manipulado como um valor bruto e depois convertido de volta para um ponteiro com o reinterpret_cast.

✅ Por que o Data ainda funciona após a desserialização?
- A desserialização é feita com reinterpret_cast de volta para Data*, o que resulta no ponteiro original para o objeto Data armazenado em memória, permitindo que ele seja acessado normalmente.

✅ Por que a classe Serializer é estática?
- A classe Serializer não precisa de instâncias para realizar as operações de serialização e desserialização, então seus métodos são declarados como static para serem chamados diretamente.

✅ A serialização e desserialização funcionam com qualquer tipo de dado?
- Não necessariamente. A serialização e desserialização funcionam para a estrutura Data como definida no exercício, mas o conceito pode ser estendido para outros tipos de dados, desde que o tipo de dado seja compatível com a conversão de ponteiros.
</details>

>[!NOTE]
>🚀 Resumo Final:
> `Este exercício nos ensina a serializar e desserializar objetos em C++ utilizando o tipo `uintptr_t`. A serialização converte um ponteiro em um valor inteiro, e a desserialização reconverte esse valor de volta para um ponteiro. A implementação segura dessas operações é essencial para manipulação de dados em memória, e o uso de métodos estáticos e do tipo `uintptr_t` torna o código eficiente e robusto.

---

📌 CPP06 - ex02: Identificação do Tipo Real

Neste exercício, implementamos um sistema para identificar o tipo real de um objeto dinâmico em C++, sem utilizar std::typeinfo. O objetivo é criar uma classe base polimórfica e três classes derivadas, além de funções que geram e identificam esses tipos corretamente.

🚀 O Que Este Exercício Ensina?

🔹 Propósito
- Compreender e utilizar casting dinâmico para identificar tipos reais de objetos.
- Implementar herança e polimorfismo em C++.
- Trabalhar com funções de identificação tanto por ponteiro quanto por referência.
- Manipular alocação dinâmica sem causar memory leaks.

🔹 Lições Importantes

✅ Uso de dynamic_cast
- Como typeid é proibido, usamos dynamic_cast para determinar o tipo real de um objeto polimórfico.

✅ Conversão Segura com dynamic_cast
- dynamic_cast tenta converter um ponteiro para um tipo derivado e retorna nullptr se a conversão falhar.
- No caso de referências, um bad_cast é lançado se a conversão for inválida.

✅ Geração Aleatória de Tipos
- A função generate() cria instâncias aleatórias de A, B ou C e retorna um ponteiro Base*.

✅ Identificação de Tipo
- Implementamos duas versões da função identify():
  - Uma que recebe um ponteiro e utiliza dynamic_cast para testar conversões.
  - Outra que recebe uma referência e usa dynamic_cast com try-catch.

📂 Declaração e Implementação

📌 Arquivos Necessários
- `Base.hpp` - Declaração da classe base.
- `Base.cpp` - Implementação da classe base.
- `A.hpp`, `B.hpp`, `C.hpp` - Declaração das classes derivadas.
- `A.cpp`, `B.cpp`, `C.cpp` - Implementação das classes derivadas.
- `main.cpp` - Testes e execução do programa.

📌 Explicação das Operações

1️⃣ Uso de dynamic_cast
- dynamic_cast<A*>(p): Tenta converter p para A*. Se falhar, retorna nullptr.
- dynamic_cast<A&>(p): Se a conversão falhar, lança uma exceção.

2️⃣ Evitando Memory Leaks
- Como generate() usa new, devemos chamar delete no final do programa.

3️⃣ Por Que dynamic_cast?
- Ele permite identificar classes derivadas em tempo de execução, essencial quando trabalhamos com herança e polimorfismo.

❓ Perguntas Possíveis na Avaliação

✅ Por que dynamic_cast é usado aqui?
- Porque precisamos identificar o tipo real de um objeto polimórfico.

✅ Por que usamos try-catch na versão por referência?
- Se a conversão falhar, dynamic_cast lança uma exceção, então capturamos isso para evitar um crash.

✅ Por que generate() usa std::rand()?
- Para criar instâncias aleatórias de A, B ou C, garantindo testes variados.

✅ Por que o destrutor da Base é virtual?
- Para permitir a destruição correta dos objetos derivados quando deletados via Base*.

✅ Como evitar memory leaks nesse exercício?
- Garantindo que qualquer objeto criado com new seja deletado no final do programa.

<details> <summary>✅ Checklist de Correção do Ex02 - Identify Real Type</summary>

🔹 Estrutura e Implementação

✅ Uso de dynamic_cast
- O código faz uso correto de dynamic_cast para identificar o tipo real da instância.

✅ Identificação via Ponteiro (Base*)
- A função identify(Base* p) utiliza dynamic_cast<A*>(p), dynamic_cast<B*>(p), e dynamic_cast<C*>(p).
- O código verifica corretamente se o retorno do dynamic_cast é NULL antes de imprimir o tipo correspondente.

✅ Identificação via Referência (Base&)
- A função identify(Base& p) utiliza dynamic_cast<A&>(p), dynamic_cast<B&>(p), e dynamic_cast<C&>(p).
- O código faz uso de try-catch para capturar std::bad_cast e evitar falhas de execução.

✅ Geração de Objetos Aleatórios
- A função generate() usa std::rand() e std::time(0) corretamente para criar uma instância aleatória de A, B ou C.

✅ Destrutor Virtual em Base
- O destrutor de Base é declarado como virtual, garantindo a deleção correta de objetos polimórficos.

✅ Memória e Gerenciamento
- O objeto alocado em generate() é corretamente desalocado com delete no main(), evitando vazamentos de memória.

✅ Compilação e Execução
- O código compila corretamente sem erros ou warnings.
- A execução identifica corretamente os tipos das instâncias geradas.

❓ Perguntas Possíveis na Avaliação

✅ O que dynamic_cast faz e por que é usado aqui?
- dynamic_cast verifica se um objeto polimórfico pode ser convertido para um tipo derivado com segurança. Se a conversão for inválida, retorna nullptr (para ponteiros) ou lança std::bad_cast (para referências).

✅ Por que precisamos de um destrutor virtual em Base?
- Para garantir que os destrutores das classes derivadas sejam chamados corretamente quando um objeto é deletado via ponteiro para Base.

✅ Por que identify(Base&) usa try-catch, mas identify(Base*) não?
- dynamic_cast retorna nullptr para ponteiros inválidos, permitindo uma verificação simples.
- Para referências, dynamic_cast lança std::bad_cast, então precisamos de um bloco try-catch para capturar a exceção.

✅ O que aconteceria se Base não tivesse um destrutor virtual?
- Se deletarmos um objeto Base* que aponta para uma instância de A, B ou C, apenas o destrutor de Base seria chamado, possivelmente causando vazamento de memória ou comportamento indefinido.

✅ Por que (void)dynamic_cast<A&>(p); é usado dentro do try-catch?
- (void) evita warnings de variável não utilizada, pois apenas verificamos a conversão sem armazenar o resultado.
</details>

> [!NOTE]
> 🚀 Resumo Final
> Este exercício ensina como usar conversões dinâmicas em C++ para identificar classes derivadas em tempo de execução. Ele reforça conceitos de polimorfismo, dynamic_cast, e alocação dinâmica segura, evitando memory leaks e garantindo um código robusto e eficiente.
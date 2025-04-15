### CPP02: Resumo, Conceitos, Propósitos e Perguntas Respondidas

Ex00: My First Class in Orthodox Canonical Form
O Que Este Exercício Quer Ensinar

Propósito:
- Este exercício introduz a Forma Canônica Ortodoxa em C++, cobrindo conceitos essenciais como construtores, destrutores e operadores de atribuição. Também explora números de ponto fixo, que são representações numéricas equilibradas entre precisão e desempenho.

Lições:
Forma Canônica Ortodoxa:
- Construtor padrão.
- Construtor de cópia.
- Operador de atribuição sobrecarregado.
- Destrutor.
Encapsulamento:
- Uso de membros privados para proteção de dados.
Funções estáticas e constantes:
- Variáveis e métodos que pertencem à classe, não à instância.
Fixed-Point Numbers:
- Manipulação numérica em baixa precisão para eficiência.

```c++
Objetivo
Criar uma classe Fixed que:
Atributos privados:
 - int _fixedPointValue: valor em ponto fixo.
 - static const int _fractionalBits = 8: número de bits fracionários.
Métodos públicos:
 - Construtor padrão (Fixed()).
 - Construtor de cópia (Fixed(const Fixed &)).
 - Operador de atribuição (Fixed &operator=(const Fixed &)).
 - Destrutor (~Fixed()).
 - int getRawBits() const: retorna o valor interno bruto.
 - void setRawBits(int const raw): define o valor interno bruto.
```

O que é a Forma Canônica Ortodoxa?
 - Um conjunto de regras que garante que classes C++ sejam consistentes e seguras:
   - Construtor padrão.
   - Construtor de cópia.
   - Operador de atribuição.
   - Destrutor.

Qual é o propósito de getRawBits e setRawBits?
 - Manipular o valor bruto interno `(_fixedPointValue)` enquanto mantém o encapsulamento.

Por que usamos static const int para _fractionalBits?
 - static: Todos os objetos compartilham o mesmo valor.
 - const: Garante que o valor nunca será alterado.

O que acontece ao atribuir um objeto a outro?
 - O operador de atribuição copia o valor bruto `(_fixedPointValue)` de um objeto para outro.

Como testar se tudo está correto?
 - Verifique se as mensagens de depuração aparecem na ordem correta e se os valores retornados por getRawBits estão consistentes.

---

Ex01: Towards a More Useful Fixed-Point Number Class
O Que Este Exercício Quer Ensinar

Propósito:
- Este exercício expande o exercício anterior ao adicionar funcionalidades mais práticas a classe Fixed. Ele ensina como adicionar diferentes construtores (para inteiros e flutuantes), métodos de conversão e como sobrecarregar operadores. O objetivo é tornar a classe Fixed mais útil e capaz de representar diferentes tipos de valores numéricos em ponto fixo.

Lições:
Construtores Específicos:
- Construtor para inteiros, que converte um valor inteiro para ponto fixo.
- Construtor para flutuantes, que converte um valor de ponto flutuante para ponto fixo.
Métodos de Conversão:
- Métodos `toFloat()` e `toInt()`, permitindo conversões fáceis entre ponto fixo, flutuante e inteiro.
Sobrecarga de Operadores:
- Sobrecarga do operador `<<` para permitir a exibição do valor de um ponto fixo como flutuante.
Como Funciona o Ponto Fixo:
- Ao manipular números em ponto fixo, você ganha controle total sobre a precisão e a faixa de valores, sem perder performance.

```c++
Objetivo
Criar uma classe Fixed com os seguintes componentes:
Atributos privados:
- int _fixedPointValue: Armazena o valor em ponto fixo.
- static const int _fractionalBits = 8: Define a quantidade de bits fracionários. É uma constante para todos os objetos da classe.
Métodos públicos:
- Construtor padrão (Fixed()): Inicializa o valor de ponto fixo para 0.
- Construtor de inteiro (Fixed(int)): Converte um valor inteiro para ponto fixo.
- Construtor de flutuante (Fixed(float)): Converte um valor flutuante para ponto fixo.
- Construtor de cópia (Fixed(const Fixed &)): Cria um novo objeto a partir de outro existente.
- Operador de atribuição (Fixed &operator=(const Fixed &)): Atribui o valor de um objeto Fixed a outro.
- Destrutor (~Fixed()): Libera os recursos quando o objeto é destruído.
- toFloat() const: Converte o valor de ponto fixo para um número de ponto flutuante.
- toInt() const: Converte o valor de ponto fixo para um número inteiro.
- getRawBits() const: Retorna o valor interno bruto do ponto fixo.
- setRawBits(int const raw): Define o valor interno bruto do ponto fixo.
- Sobrecarga do operador <<: Para exibir valores de ponto fixo como números flutuantes.
```

Explicação Detalhada das Operações
Para entender como essas operações funcionam no contexto de números de ponto fixo, vamos detalhar cada uma delas, explicando com exemplos e conceitos por trás.

1. Adicionar Construtores
`Construtor de Inteiros`
- Quando recebemos um valor inteiro, precisamos representá-lo no formato de ponto fixo.
- Para isso, deslocamos o valor para a esquerda (usando <<) em relação ao número de bits fracionários. Esse deslocamento simula a adição de casas decimais no formato binário.
Fórmula:
$$fixed_value = integer × (1 << fractional_bits)$$
Exemplo:
Se `integer = 5` e `fractional_bits = 8`:
$$fixed_value=5×(1<<8)=5×256=1280$$
- O número 5 agora é representado como 1280 em ponto fixo.

Construtor de Float
- Para valores flutuantes, também precisamos transformá-los em ponto fixo.
- Multiplicamos o valor pelo fator de deslocamento $(1<<fractional_bits)$, mas como valores flutuantes podem ter casas decimais, usamos roundf() para arredondar o resultado e garantir precisão.
Fórmula:
$$fixed_value=roundf(float×(1<<fractional_bits))$$
Exemplo:
Se `float = 5.75` e `fractional_bits = 8`:
$$fixed_value=roundf(5.75×256)=roundf(1472)=1472$$
- O número 5.75 agora é representado como 1472 em ponto fixo.

2. Adicionar Métodos de Conversão
`toFloat()`
- Este método converte o valor de ponto fixo de volta para ponto flutuante.
- Dividimos o valor bruto pelo fator de deslocamento $(1<<fractional_bits)$ para reverter o deslocamento binário.
Fórmula:
$$float\_value = \frac{fixed\_value}{(1 \ll fractional\_bits)}$$
Exemplo:
Se `fixed_value = 1472` e `fractional_bits = 8`:

$$float\_value = \frac{256}{1472} = 5.75$$

`toInt()`
- Para converter para um inteiro, basta realizar um deslocamento para a direita $(>>)
$ do valor bruto. Isso elimina os bits fracionários.
Fórmula:
$$int\_value=fixed\_value>>fractional\_bits$$
Exemplo:
Se `fixed_value = 1472` e `fractional_bits` = 8:
$$int\_value=1472>>8=5$$
- Os bits fracionários são descartados, e o valor inteiro correspondente é 5.

3. Sobrecarga do Operador <<
- O operador `<<` é sobrecarregado para facilitar a exibição de números de ponto fixo como ponto flutuante.
- Ele chama o método `toFloat()` internamente para converter o valor antes de imprimi-lo.

Por que os construtores de inteiros e flutuantes são necessários?
- Eles permitem que a classe Fixed represente não apenas zero, mas qualquer valor, seja inteiro ou flutuante, convertendo-o para o formato de ponto fixo.

Qual é o objetivo do método toFloat()?
- O método toFloat() converte o valor de ponto fixo para flutuante, permitindo usar o valor em cálculos de ponto flutuante.

Qual é a vantagem de usar 1 << fractional_bits para manipulação de números fixos?
- Usar deslocamento de bits é uma forma eficiente e rápida de lidar com números de ponto fixo, sem perder precisão e mantendo o desempenho.

O que acontece ao fazer uma conversão de ponto fixo para inteiro?
- O valor decimal (após a vírgula) é descartado, e o valor inteiro mais próximo é retornado.

- Por que a sobrecarga do operador << é útil?
A sobrecarga permite que o objeto Fixed seja impresso como um número flutuante, tornando a exibição mais intuitiva e acessível.

---

Ex02: Now We’re Talking
O Que Este Exercício Quer Ensinar
Propósito:
- Este exercício avança o entendimento sobre a manipulação de números de ponto fixo, adicionando operadores de comparação, operadores aritméticos e operadores de incremento/decremento. Também apresenta funções estáticas para determinar o menor e o maior número entre dois valores, consolidando a ideia de sobrecarga de operadores e métodos utilitários.

Lições:
Sobrecarga de Operadores:
- Comparação: >, <, >=, <=, ==, !=.
- Operadores Aritméticos: +, -, *, /.
- Incremento e Decremento: Pré-incremento (++var), pós-incremento (var++), pré-decremento (--var), pós-decremento (var--).

Funções Estáticas:
- Funções utilitárias min e max para comparar dois objetos Fixed, retornando o menor ou o maior deles. Ensina o uso de referências constantes e estáticas.

Ad-hoc Polimorfismo:
- Uso de operadores sobrecarregados para permitir múltiplos comportamentos (como soma, comparação, etc.) sem alterar a interface da classe.

Controle de Precisão:
Demonstra a manipulação eficiente de números de ponto fixo ao implementar cálculos aritméticos e conversões.

```c++
#### Objetivo:
Implementar uma classe `Fixed` que expanda a funcionalidade para incluir:
**Atributos Privados:**
- `int _fixedPointValue`: Representa o número em ponto fixo.
- `static const int _fractionalBits = 8`: Número de bits fracionários.

**Métodos Públicos:**
1. **Construtores:**
   - Padrão (inicializa com 0).
   - Inteiro (converte de inteiro para ponto fixo).
   - Flutuante (converte de float para ponto fixo).
   - Cópia (inicializa com base em outro objeto).

2. **Operadores Sobrecarga:**
   - Comparação: `>`, `<`, `>=`, `<=`, `==`, `!=`.
   - Aritméticos: `+`, `-`, `*`, `/`.
   - Incremento e Decremento: Pré e pós.

3. **Conversão:**
   - `toFloat()`: Converte de ponto fixo para ponto flutuante.
   - `toInt()`: Converte de ponto fixo para inteiro.

4. **Funções Utilitárias:**
   - `min` e `max`: Retorna o menor ou maior valor entre dois objetos `Fixed`.
   
5. **Manipulação do Valor Bruto:**
   - `getRawBits()`: Retorna o valor bruto.
   - `setRawBits(int const raw)`: Define o valor bruto.

6. **Operador de Saída:**
   - `<<`: Exibe um objeto `Fixed` no formato de ponto flutuante.
```

Explicação Detalhada

1. Sobrecarga de Operadores de Comparação
- Facilita a comparação de objetos Fixed como se fossem tipos primitivos.
Por exemplo, if (a > b) verifica qual objeto tem maior valor.
2. Sobrecarga de Operadores Aritméticos
- Permite usar operadores matemáticos como +, -, * e / diretamente entre objetos Fixed.
- Isso simplifica a manipulação de números de ponto fixo.
3. Operadores de Incremento e Decremento
- Pré-incremento (++var): Incrementa o valor antes de usá-lo.
- Pós-incremento (var++): Incrementa o valor após usá-lo.
4. Funções Estáticas min e max
- Retornam o menor ou o maior objeto entre dois valores.
- const Fixed &: Garante que objetos constantes possam ser comparados.
5. Cuidado com Divisão
- Divisão por zero é permitida e pode causar falhas. Este comportamento é aceitável para o exercício.

Por Que Sobrecarga de Operadores é Útil?
- Ela torna a classe mais intuitiva de usar, permitindo que objetos Fixed se comportem como tipos nativos.

Por Que Incremento e Decremento?
- Simulam operações aritméticas finas, importantes em cálculos precisos, como gráficos e física.

Por Que Funções min e max?
- São úteis para encontrar limites ou realizar cálculos de otimização entre múltiplos objetos.

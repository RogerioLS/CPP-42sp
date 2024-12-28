### CPP04: Resumo, Conceitos, Propósitos e Perguntas Respondidas

Ex00: Polymorphism

Neste exercício, exploramos polimorfismo em C++ ao implementar uma hierarquia de classes para representar animais. Também aprendemos a diferença entre chamadas polimórficas e não polimórficas usando classes base e derivadas.

O Que Este Exercício Quer Ensinar

Propósito:
- Entender polimorfismo de subtipo e como utilizá-lo para criar hierarquias de classes reutilizáveis.
- Diferenciar entre métodos virtuais e não virtuais.
- Compreender como o C++ manipula objetos derivativos e os resolve em tempo de execução.

Lições:
Herança:
- Dog e Cat herdam de Animal.
- WrongCat herda de WrongAnimal para ilustrar o comportamento sem polimorfismo.

Polimorfismo:
- Uso de métodos virtuais para permitir que classes derivadas redefinam o comportamento.

Métodos Virtuais:
- Permitem chamadas polimórficas, onde o método chamado depende do tipo dinâmico do objeto (não apenas do tipo estático).

Demonstração de Testes:
- Comparar chamadas de método com e sem polimorfismo.
Polimorfismo (Animal, Dog, Cat):
- Uso de métodos virtual permite que makeSound seja resolvido em tempo de execução.
- Métodos das classes derivadas (Dog, Cat) são chamados corretamente quando usados via ponteiros da classe base (Animal).
Sem Polimorfismo (WrongAnimal, WrongCat):
- Métodos não virtual resultam na chamada do método da classe base, mesmo que o objeto seja de uma classe derivada.

Declaração e Implementação
Arquivos Necessários
Animal.hpp - Declaração da classe base.
Animal.cpp - Implementação da classe base.
Dog.hpp e Dog.cpp - Classe derivada.
Cat.hpp e Cat.cpp - Outra classe derivada.
WrongAnimal.hpp, WrongAnimal.cpp, WrongCat.hpp, WrongCat.cpp - Classes para ilustrar comportamento não polimórfico.

```c++
Objetivo:
- Criar uma hierarquia de classes representando animais (Animal, Dog, Cat) para demonstrar polimorfismo.
Atributos:
- type (protected): Tipo do animal.
Métodos:
Construtores e Destrutores:
- Diferenciados para cada classe, com mensagens únicas.
- makeSound: Virtual, permite que classes derivadas sobrescrevam o comportamento.
- getType: Retorna o tipo do animal.
```

Perguntas Possíveis
Por que usamos virtual em makeSound?
- Para permitir que o método seja sobrescrito em classes derivadas e chamado polimorficamente.

O que é polimorfismo?
- Capacidade de chamar métodos de classes derivadas através de um ponteiro/referência da classe base.

Por que WrongCat não apresenta comportamento polimórfico?
- Porque não usamos virtual nos métodos de WrongAnimal.

O que acontece se esquecermos de declarar o destrutor como virtual em Animal?
- Pode causar undefined behavior ao deletar objetos derivados através de ponteiros da classe base.

Por que o WrongCat não usa o método makeSound da própria classe?
- Porque o método não é virtual na classe base WrongAnimal.

O que acontece ao omitir o destrutor virtual?
- Se você deletar um objeto derivado usando um ponteiro da classe base, apenas o destrutor da classe base será chamado, causando possíveis vazamentos de memória.

Qual a diferença prática entre WrongCat e Cat?
- WrongCat não possui polimorfismo, enquanto Cat usa métodos virtuais, permitindo chamadas dinâmicas corretas.

---

Ex01:  I don’t want to set the world on fire

O Que Este Exercício Quer Ensinar

Propósito: Este exercício visa aprofundar o entendimento sobre polimorfismo em C++ e os conceitos de gerenciamento de memória. Ensina como implementar herança complexa e como gerenciar adequadamente recursos alocados dinamicamente, como ponteiros.

Lições Aprendidas
Polimorfismo e Virtualização
Polimorfismo Dinâmico:
- Utilizando métodos virtuais (virtual) para permitir que as subclasses forneçam implementações específicas.
- Exemplo: A função makeSound() é sobrescrita nas classes Dog e Cat.

Destrutores Virtuais:
- Garante que o destrutor correto seja chamado para objetos alocados dinamicamente, mesmo quando acessados por um ponteiro para a classe base.

Encapsulamento e Herança
Atributos Protegidos:
- O atributo type da classe Animal é protegido, permitindo que as subclasses acessem diretamente, mas mantendo o encapsulamento para usuários externos.

Herança:
- A classe Dog e a classe Cat herdam da classe Animal e sobrescrevem comportamentos.

Gerenciamento de Recursos
Alocação Dinâmica:
- As classes Dog e Cat possuem um ponteiro para a classe Brain, que é criado com new.
Desalocação Segura:
- O destrutor das classes Dog e Cat chamam explicitamente delete para liberar a memória da instância de Brain.

Cópias Profundas (Deep Copy):
- Implementação de construtores de cópia e operadores de atribuição para evitar problemas de duplicação de ponteiros.

```c++
Objetivo do Exercício
Classes Implementadas:
Animal
- Classe base.
- Atributos:
   - std::string type.
Métodos:
- Animal(): Construtor padrão.
- ~Animal(): Destrutor virtual.
- Animal(const Animal &other): Construtor de cópia.
- Animal &operator=(const Animal &other): Operador de atribuição.
- virtual void makeSound() const: Sobrescrevível nas subclasses.
- std::string getType() const: Retorna o tipo do animal.

Dog e Cat
- Herdeiros de Animal.
- Sobrescrevem:
  - makeSound() para emitir sons específicos.

Brain
- Atributo privado das classes Dog e Cat.
- Contém:
  - std::string ideas[100]: Representa "ideias" do animal.
```
Dúvidas e Respostas Possíveis

Por que usar destrutores virtuais?
- Garante que o destrutor da subclasse seja chamado, evitando vazamento de memória.

O que é uma cópia profunda?
- Copia os dados apontados por ponteiros, criando novas instâncias, em vez de copiar apenas o endereço de memória.

Por que a classe Animal não tem Brain?
- Brain é específico para Dog e Cat. Manter a lógica na subclasse reduz a complexidade na classe base.

Por que usamos new Brain()?
- Para ilustrar a alocação dinâmica e permitir a prática de gerenciamento de memória.

Qual a diferença entre type ser protected e private?
- protected permite que classes derivadas acessem diretamente o atributo, enquanto private não.

---

Ex02: Abstract Class

Objetivo do Exercício
O propósito deste exercício é introduzir o conceito de classes abstratas em C++ e demonstrar como essas classes evitam que instâncias de uma classe base sejam criadas diretamente, enquanto continuam a servir como base para herança.

Implementação
O Que Deve Ser Alterado
Tornar a classe Animal abstrata.
- Para isso, declarar o método makeSound() como puro virtual.
  ```c++
  virtual void makeSound() const = 0;
  ```
- Um método puro virtual é declarado com = 0 e força que as subclasses implementem sua lógica.
- Opcionalmente, renomear a classe para AAnimal para destacar que é abstrata.
- Garantir que o restante do código funcione como antes.

Resumo
O Que Este Exercício Quer Ensinar:
Classes Abstratas:
- Classes que não podem ser instanciadas diretamente.
- Servem como base para herança, forçando subclasses a implementar métodos específicos.
Métodos Virtuais Puros:
- São declarados com = 0.
- Transformam a classe em abstrata e devem ser implementados nas subclasses.

Perguntas Comuns
Por que usar uma classe abstrata?
- Para evitar instanciar classes genéricas que não têm funcionalidade completa, como Animal, e garantir que subclasses implementem métodos específicos.

O que acontece se não implementarmos o método makeSound() na subclasse?
- A subclasse também será abstrata e não poderá ser instanciada.

Por que declarar makeSound() como = 0?
- Para forçar todas as subclasses a fornecerem sua própria implementação.

Ainda precisamos do destrutor virtual?
- Sim, o destrutor virtual garante que o destrutor correto da subclasse será chamado.

Qual é o impacto na herança de transformar Animal em uma classe abstrata?
- Apenas classes que implementam todos os métodos virtuais puros podem ser instanciadas.

---

### BONUS

`ex01:`
Por que o destrutor de Animal deve ser virtual?
- Para garantir que o destrutor da classe derivada seja chamado quando deletamos um objeto da classe derivada por meio de um ponteiro para a classe base.

O que acontece sem virtual?
- Apenas o destrutor da classe base será chamado, resultando em vazamentos de memória ou recursos não liberados na classe derivada.

Por que a destruição é realizada na ordem inversa da construção?
- Isso é necessário para garantir que os recursos sejam liberados na ordem inversa à sua alocação, evitando dependências de recursos já destruídos.

O que é um destrutor virtual puro?
- Um destrutor virtual puro (virtual ~Animal() = 0;) torna a classe abstrata, impedindo que instâncias da classe base sejam criadas diretamente.

`ex02:`
O que é uma Classe Abstrata?
- Uma classe abstrata é uma classe que não pode ser instanciada diretamente.
- Ela serve como uma base para outras classes derivadas.
- Contém funções virtuais puras, que obrigam as classes derivadas a implementá-las.

Por que Animal precisa ser abstrata?
- Racionalidade do Design: Um Animal genérico não faz som, mas classes derivadas como Dog ou Cat fazem.
- Forçar Implementação: Declarar makeSound como virtual pura força todas as classes derivadas de Animal a implementar sua própria versão de makeSound.

O que é uma função virtual pura?
- É uma função declarada em uma classe base com = 0, que obriga as classes derivadas a implementá-la:
    - virtual void makeSound() const = 0;

Por que a classe Animal é abstrata?
- Porque contém uma função virtual pura. Isso impede a criação de instâncias de Animal, forçando o uso de classes derivadas para implementar comportamentos específicos.

O que acontece ao tentar instanciar Animal?
- Um erro de compilação ocorre, indicando que Animal é abstrata:
    - cannot declare variable ‘test’ to be of abstract type ‘Animal’

Por que usamos classes abstratas?
- Forçar a implementação de métodos em classes derivadas.
Garantir que a classe base sirva apenas como uma interface ou ponto comum para herança.

Por que é necessário que as classes estejam na Forma Canônica Ortodoxa?
- Para garantir que a classe seja bem projetada, segura, e que cópias e atribuições funcionem corretamente, evitando problemas de gerenciamento de memória.

`Polimorfismo:`

O que é polimorfismo?
- O polimorfismo é um dos quatro pilares fundamentais da Programação Orientada a Objetos (POO). Ele permite que objetos de diferentes classes derivadas sejam tratados como objetos da classe base, enquanto ainda mantêm seus comportamentos específicos. Em outras palavras, o polimorfismo possibilita que um mesmo método se comporte de maneiras diferentes dependendo do objeto que o invoca.
- Polimorfismo permite que uma mesma função tenha comportamentos diferentes dependendo da classe que a implementa. No exercício, makeSound é polimórfico porque cada classe derivada (Dog, Cat) tem sua própria implementação.
- No exercício, o polimorfismo é exemplificado pelo uso de uma classe base abstrata (Animal) com uma função virtual pura (makeSound). A ideia é que cada classe derivada (Dog e Cat) implemente sua própria versão de makeSound. Isso permite que o mesmo código funcione para diferentes tipos de animais, desde que sejam derivados de Animal.

Como o polimorfismo é usado aqui?
- Animal é a classe base abstrata, e makeSound é uma função virtual pura. Ao chamar makeSound através de um ponteiro para Animal, o método específico da classe derivada é chamado.

Qual é a vantagem do polimorfismo?
- O código é mais flexível e extensível. Você pode adicionar novos tipos de animais sem alterar a lógica existente.

O que acontece se makeSound não for virtual?
- A versão de makeSound na classe base (Animal) será chamada, mesmo que o objeto seja uma instância de Dog ou Cat. Isso quebra o comportamento esperado.
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


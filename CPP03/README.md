
### CPP03: Resumo, Conceitos, Propósitos e Perguntas Respondidas

Ex00: Aaaaand... OPEN!
O Que Este Exercício Quer Ensinar

Propósito:
- Introduzir conceitos básicos de programação orientada a objetos em C++ com ênfase em encapsulamento, construtores personalizados e métodos para simular ações.
- Explorar a criação e manipulação de classes com atributos e comportamentos que simulam uma entidade interativa.

Lições:
Encapsulamento:
- Uso de atributos privados para proteger os dados internos do objeto.
- Manipulação de atributos através de métodos públicos.
Construtores e Destrutores:
- Inicialização de atributos com valores padrão ou personalizados.
- Destrutores exibem mensagens de depuração para verificar a ordem de destruição.
Simulação de Comportamento:
- Métodos como attack, takeDamage e beRepaired para representar ações do objeto.
- Mensagens de saída detalhadas para descrever o que acontece.
Controle de Recursos:
- Gestão de pontos de vida e energia com base nas ações realizadas.
Uso de Referências Constantes:
- Passagem eficiente de strings como parâmetro com const std::string&.

```c++
Objetivo
Criar uma classe ClapTrap que simula um personagem com os seguintes componentes:
Atributos Privados:
- `std::string name`: Nome do ClapTrap, passado no construtor.
- `int hitPoints`: Representa a saúde (inicializado com 10).
- `int energyPoints`: Representa os pontos de energia (inicializado com 10).
- `int attackDamage`: Representa o dano de ataque (inicializado com 0).

Métodos Públicos:
1. Construtores e Destrutores:
   - Construtor padrão.
   - Construtor com nome.
   - Construtor de cópia.
   - Destrutor.

2. Métodos de Ação:
   - `void attack(const std::string& target)`: Realiza um ataque no alvo especificado.
   - `void takeDamage(unsigned int amount)`: Reduz os pontos de vida com base no dano recebido.
   - `void beRepaired(unsigned int amount)`: Repara pontos de vida e consome energia.

Comportamentos Adicionais:
- `ClapTrap` não pode atacar ou reparar se não tiver energia ou pontos de vida.
- Todas as ações exibem mensagens de depuração para facilitar a avaliação do comportamento.
```

Perguntas sobre o Exercício
1. O que é encapsulamento, e como você utilizou isso na classe ClapTrap?
- Encapsulamento é o princípio da orientação a objetos que protege os dados de acesso indevido e os torna acessíveis apenas através de métodos controlados. Na classe ClapTrap, os atributos como name, hitPoints, energyPoints e attackDamage são privados, e a manipulação deles ocorre exclusivamente através de métodos públicos (attack, takeDamage, beRepaired).
2. Por que os atributos da classe são inicializados no construtor?
- O construtor é responsável por inicializar os atributos da classe ao criar um objeto. No caso do ClapTrap, os atributos como name, hitPoints, energyPoints e attackDamage são configurados no construtor para garantir que cada instância tenha valores iniciais bem definidos, conforme especificado no exercício.
3. O que significa const std::string& target no método attack?
- O const garante que o parâmetro target não será modificado dentro do método. O & indica que target é passado como referência, evitando a cópia desnecessária do valor, o que melhora o desempenho, especialmente para strings grandes.
4. Qual é a função do destrutor, e por que você implementou um?
- O destrutor é chamado automaticamente quando o objeto é destruído. Eu implementei um destrutor na classe ClapTrap para exibir uma mensagem de depuração, indicando que a instância foi destruída. Isso ajuda no rastreamento do ciclo de vida do objeto durante testes.
5. Por que o ClapTrap não pode atacar ou se reparar sem pontos de energia ou vida?
- Essa lógica foi implementada para refletir um comportamento realista. Se um ClapTrap estiver sem vida (hitPoints <= 0), ele não pode fazer nada. Da mesma forma, se não tiver energia (energyPoints <= 0), ele não consegue realizar ações como atacar ou se reparar, já que essas ações custam energia.

Perguntas sobre Implementação
6. Por que os atributos da classe são privados?
- A privacidade dos atributos impede que eles sejam acessados diretamente de fora da classe, protegendo a integridade dos dados. Todas as interações com os atributos são feitas através de métodos controlados, como attack, takeDamage e beRepaired.
7. Como o attack e o takeDamage funcionam?
O método attack reduz os hitPoints do alvo em um valor correspondente ao atributo attackDamage. Ele também consome 1 ponto de energia.
O método takeDamage reduz os hitPoints do ClapTrap em um valor passado como parâmetro (amount), respeitando os limites (não permite vida negativa).
8. Qual é a ordem de execução do construtor e do destrutor?
- O construtor é chamado quando o objeto é criado, e o destrutor é chamado automaticamente quando o objeto sai de escopo ou é explicitamente destruído.
9. O que acontece se dois objetos ClapTrap interagirem?
- Um ClapTrap pode atacar outro se ambos tiverem vida e energia suficientes. O ClapTrap atacante usa o método attack, e o alvo usa takeDamage para reduzir sua vida.
10. Por que não implementamos getters e setters nesse exercício?
- Não implementamos getters e setters porque o enunciado não exige e todos os atributos podem ser manipulados internamente pelos métodos fornecidos (attack, takeDamage, beRepaired).

Perguntas Conceituais
11. O que é um método público e privado, e como você decidiu quais usar?
- Métodos públicos podem ser acessados fora da classe, enquanto métodos privados só podem ser usados dentro dela. Eu tornei attack, takeDamage e beRepaired públicos porque eles representam ações que podem ser realizadas fora da classe. Os atributos da classe são privados para garantir encapsulamento.
12. O que é sobrecarga de métodos, e você a utilizou aqui?
- Sobrecarga de métodos permite criar várias versões de um método com o mesmo nome, mas assinaturas diferentes. Não utilizei sobrecarga neste exercício porque cada método tem um propósito específico.
13. Por que você adicionou mensagens de depuração nos construtores e no destrutor?
- As mensagens de depuração ajudam a entender o ciclo de vida dos objetos durante a execução do programa. Isso é especialmente útil para rastrear a criação e destruição de instâncias em testes.
14. O que acontece se energyPoints ou hitPoints forem negativos?
- Eu implementei verificações nos métodos para impedir ações se energyPoints ou hitPoints forem zero ou menos. Dessa forma, o comportamento do ClapTrap é previsível e consistente.
15. Como você testou a classe ClapTrap?
- Criei vários objetos ClapTrap com diferentes nomes. Testei os métodos attack, takeDamage e beRepaired em diferentes cenários, incluindo casos limite (energia zero, vida zero, etc.).

Perguntas sobre Design
16. Como você garantiria que a classe é extensível no futuro?
- Se a classe precisasse de mais funcionalidades no futuro, poderia-se adicionar novos métodos públicos ou atributos privados, mantendo o encapsulamento. Também seria possível herdar de ClapTrap para criar classes mais especializadas.
17. Como você adicionaria um limite máximo de hitPoints?
- Poderia-se adicionar um novo atributo privado, como maxHitPoints, e ajustar o método beRepaired para não exceder esse limite ao curar o ClapTrap.

---

Ex01: Serena, my love!
O Que Este Exercício Quer Ensinar

Propósito:
- Este exercício introduz o conceito de herança em C++, onde uma classe derivada (ScavTrap) reutiliza e estende as funcionalidades de uma classe base (ClapTrap). A herança permite reutilizar código, adicionar especializações e criar relações hierárquicas entre classes.

Lições:
Herança:
- A classe derivada (ScavTrap) herda atributos e métodos da classe base (ClapTrap).
- ScavTrap redefine o comportamento do método attack() e adiciona uma nova funcionalidade (guardGate()).
Chaining de Construtores e Destrutores:
- O construtor da classe derivada chama automaticamente o construtor da classe base.
- A ordem de destruição é oposta: a classe derivada é destruída antes da base.
Modificadores de Acesso:
- protected: Permite que atributos/métodos da classe base sejam acessados diretamente pela classe derivada, mas ainda protegidos de acesso externo.
Polimorfismo:
- Embora não explorado diretamente aqui, este exercício prepara o terreno para métodos virtual e sobrecarga de funções em classes derivadas.

```c++
Objetivo
Criar uma nova classe ScavTrap com:
Atributos Herdados:
- Name, hitPoints, energyPoints e attackDamage, inicializados com:
- hitPoints = 100
- energyPoints = 50
- attackDamage = 20
Métodos Herdados e Modificados:
- Construtores e destrutor personalizados que exibem mensagens específicas.
- Método attack() redefinido para mensagens específicas.
Método Exclusivo:
- void guardGate(): Ativa o modo Gate Keeper.
```

Possíveis Perguntas
O que é herança?
- É a capacidade de uma classe derivada reutilizar e estender a funcionalidade de uma classe base.
Por que usamos protected nos atributos?
- Para permitir que classes derivadas acessem diretamente os atributos enquanto ainda protegemos esses dados de acesso externo.
Qual é a ordem de execução de construtores e destrutores?
- O construtor da classe base é executado primeiro, seguido pelo da classe derivada.
Durante a destruição, a ordem é inversa: a classe derivada é destruída primeiro.
O que é void guardGate()?
- É um método exclusivo de ScavTrap, que ativa o modo Gate Keeper, indicando uma habilidade especial.
Por que redefinimos o método attack()?
- Para personalizar o comportamento de ataque do ScavTrap, exibindo uma mensagem diferente da classe base.

**BONUS**

Porque nao estamos utilizando o metodo ortodoxo com copei do construtor e operador de atribuicao para a class ScavTrap?

Neste caso, não precisamos implementar explicitamente o método de cópia (copy constructor) e o operador de atribuição (assignment operator) para a classe ScavTrap:

1. O Papel da Classe Base (ClapTrap)
A classe ClapTrap já está implementada em conformidade com a Forma Canônica Ortodoxa:
- Construtor padrão.
- Construtor de cópia.
- Operador de atribuição.
- Destrutor.
A classe derivada ScavTrap herda esses métodos. Assim, a implementação padrão gerada pelo compilador para o construtor de cópia e operador de atribuição na classe ScavTrap simplesmente delegará esses comportamentos para os membros herdados de ClapTrap.
2. Delegação Automática do Comportamento
Se você não declarar explicitamente o construtor de cópia ou o operador de atribuição na classe derivada (ScavTrap):
- O construtor de cópia gerado pelo compilador copiará os membros herdados diretamente utilizando o comportamento da classe base (ClapTrap).
- O mesmo vale para o operador de atribuição gerado pelo compilador.
No nosso caso, como ScavTrap não possui novos membros exclusivos (apenas utiliza os atributos herdados de ClapTrap), a implementação gerada pelo compilador é suficiente.
3. Quando Deveríamos Implementar?
Você precisaria implementar explicitamente o construtor de cópia e operador de atribuição na classe derivada (ScavTrap) nos seguintes casos:
Se ScavTrap possuir atributos exclusivos.
- Se ScavTrap tivesse atributos adicionais, o construtor de cópia gerado pelo compilador não saberia como copiar esses novos atributos corretamente.
Se ClapTrap não implementasse corretamente sua Forma Canônica Ortodoxa.
- Caso a classe base (ClapTrap) não implementasse o construtor de cópia ou operador de atribuição corretamente, o comportamento na classe derivada poderia ser problemático.
Se precisarmos de uma lógica personalizada.
- Em casos onde queremos modificar ou personalizar como os atributos herdados ou adicionados são copiados.
4. Por Que Não Implementar Sem Necessidade?
Implementar explicitamente algo que o compilador já faz bem:
- Introduz complexidade desnecessária.
- Torna o código mais difícil de manter.
- Viola o princípio **"You Ain't Gonna Need It" (YAGNI)**: Não implemente funcionalidades que você não precisa agora.
5. Conclusão no Contexto de ScavTrap
A classe ScavTrap:

Não possui novos atributos.
Herda corretamente os atributos e comportamentos da classe base ClapTrap.
Assim, o comportamento padrão gerado pelo compilador é suficiente para gerenciar o construtor de cópia e operador de atribuição.
Se, no futuro, ScavTrap precisasse de atributos exclusivos ou lógica adicional, poderíamos revisitar a implementação e adicionar explicitamente esses métodos.

Espero que isso esclareça! 🚀
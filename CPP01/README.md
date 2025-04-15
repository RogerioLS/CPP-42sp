### CPP01: Resumo, Conceitos, Propósitos e Perguntas Respondidas

O Que Cada Exercício Quer Ensinar

Exercício 00 - BraiiiiiiinnnzzzZ
Propósito: Introdução à alocação dinâmica e estática, encapsulamento, e construtores/destrutores.
Lições:
- Diferença entre alocar na stack e na heap.
- Importância de desalocar memória na heap.
- Uso de métodos para encapsular a lógica de construção e destruição.

```c++
Objetivo:
Criar uma classe Zombie com:
- Um atributo name.
- Um método announce() que exibe uma mensagem personalizada.
- Métodos auxiliares newZombie() e randomChump() para criar zumbis.

Detalhes Técnicos:

Alocação de Memória:
- newZombie(): Aloca na heap. Requer desalocação manual (delete).
- randomChump(): Aloca na stack. É automaticamente desalocado.

Destrutores:
- O destrutor da classe imprime uma mensagem indicando a destruição de um zumbi.

Encapsulamento:
- O atributo name é privado, garantindo que somente métodos internos possam acessá-lo.
```

Por que usamos new e delete no newZombie?
- new aloca memória na heap, permitindo que o objeto exista fora do escopo da função. delete é necessário para liberar essa memória.

O que acontece se esquecer de usar delete?
- Resulta em vazamento de memória (memory leak).

Qual a diferença entre alocação na heap e na stack?
- Heap é gerenciada manualmente e dura até ser liberada explicitamente. Stack é automática e é desalocada ao sair do escopo.

---

Exercício 01 - Moar brainz!

Propósito: Alocação dinâmica em massa, uso de arrays dinâmicos e desalocação correta.
Lições:
- Manipulação eficiente de arrays na heap.
- Criar objetos dinamicamente em blocos.

```c++
Objetivo:
Implementar a função zombieHorde(int N, std::string name):
- Cria um array de N zumbis com o mesmo nome.
- Cada zumbi deve poder anunciar-se usando announce().

Detalhes Técnicos
Alocação Dinâmica:
- Usamos new Zombie[N] para criar o array dinâmico.
delete[] é usado para desalocar a memória.

Construtores:
- O nome do zumbi é configurado no construtor.

Gestão de Memória:
- Sempre certifique-se de desalocar a memória após o uso.
```

Por que usamos new Zombie[N]?
- Para alocar múltiplos objetos consecutivos na heap de maneira eficiente.

Como evitamos vazamentos de memória?
- Usando delete[ ] para liberar o array alocado dinamicamente.

Qual o impacto de não liberar a memória alocada?
- O programa pode consumir cada vez mais memória, resultando em queda de desempenho ou falhas.

---

Exercício 02 - HI THIS IS BRAIN

Propósito: Entendimento de ponteiros e referências em C++.
Lições:
- Diferença entre ponteiros e referências.
- Manipulação de endereços de memória.
- Uso básico de referências como aliases para variáveis.

```c++
Objetivo:
Explorar referências e ponteiros:
- Criar uma string inicializada.
- Usar um ponteiro (stringPTR) e uma referência (stringREF) para acessar a string.

Detalhes Técnicos:
Diferença entre Ponteiros e Referências:
- Um ponteiro pode ser reatribuído para apontar para outro endereço.
- Uma referência é um alias fixo para a variável original.

Impressões:
- Exibir endereços de memória e valores associados à string.
```

Por que a referência (stringREF) não pode ser reatribuída?
- Referências são aliases fixos, vinculados à variável original na criação.

Qual a diferença entre ponteiros e referências?
- Ponteiros armazenam endereços e podem ser reatribuídos. Referências são constantes e representam diretamente a variável.

Como imprimir o endereço de uma variável?
- Usando o operador &, por exemplo, &string.

---

Exercício 03 - Unnecessary Violence

Propósito: Diferença entre composição por ponteiros e referências, e como isso afeta o design.
Lições:
- Referências são usadas para garantir a existência de um objeto.
- Ponteiros oferecem mais flexibilidade, permitindo que o objeto seja opcional.

```c++
Objetivo:
Criar classes Weapon, HumanA e HumanB para simular ataques com armas:
- HumanA sempre possui uma arma, inicializada no construtor.
- HumanB pode ou não estar armado, usando ponteiros para armas.

Detalhes Técnicos:
Composição:
- HumanA usa uma referência para sua arma, garantindo que ela sempre esteja armada.
- HumanB usa um ponteiro, permitindo que ele esteja desarmado.

Encapsulamento:
- Atributo privado type em Weapon, acessado via getType() e modificado por setType().

Diferença entre Ponteiros e Referências:
- Demonstração clara de cenários onde cada um é mais apropriado.
```
Por que HumanA usa referência e HumanB usa ponteiro?
- HumanA sempre tem uma arma, garantindo sua existência. HumanB pode estar desarmado, justificando o uso de ponteiro.

O que acontece se HumanB atacar sem arma?
- Um comportamento indefinido pode ocorrer se não tratarmos esse caso. Devemos verificar se o ponteiro é nullptr.

Como o setType afeta os objetos?
- Modifica o tipo da arma, afetando todos os objetos que compartilham essa instância.

---

Exercício 04 - Sed is for losers

Propósito: Manipulação de strings e arquivos usando C++.
Lições:
- Uso de manipuladores de arquivos (ifstream, ofstream).
- Métodos de manipulação de strings como find e substr.
- Importância de tratar erros ao lidar com arquivos.

```c++
Objetivo:
Criar um programa que substitui todas as ocorrências de uma string (s1) por outra (s2) em um arquivo, salvando o resultado em <filename>.replace:

Detalhes Técnicos:
Manipulação de Arquivos:
- std::ifstream para leitura.
- std::ofstream para escrita.

Manipulação de Strings:
- Uso de métodos como find() e substr() para localizar e substituir substrings.

Tratamento de Erros:
- Verificação de falhas ao abrir arquivos ou entradas inválidas.
```

Qual o impacto de não tratar erros ao abrir arquivos?
- O programa pode falhar silenciosamente ou produzir resultados incorretos.

Por que std::string::replace é proibido?
- Para forçar o uso de métodos básicos de manipulação de strings, como find e substr.

Como substituímos s1 por s2 em uma string?
- Usando find para localizar s1 e substr para reconstruir a string.

---

Exercício 05 - Harl 2.0

Propósito: Uso de ponteiros para métodos e encapsulamento avançado.
Lições:
- Mapear strings para métodos usando arrays de ponteiros.
- Reduzir complexidade de controle de fluxo (if/else ou switch).

```c++
Objetivo:
Criar a classe Harl, que gera mensagens de log com níveis (DEBUG, INFO, WARNING, ERROR), usando ponteiros para métodos membros.

Detalhes Técnicos:
Ponteiros para Métodos:
- Um array de ponteiros para métodos é usado para mapear os níveis de log.

Encapsulamento:
- Métodos de log privados são acessados por um método público (complain).

Eficácia:
- Evitamos um grande bloco de if/else ou switch ao mapear níveis diretamente para métodos.
```

Como funcionam os ponteiros para métodos?
- São usados para armazenar endereços de métodos da classe. Podem ser chamados através de uma instância usando (*this.*methodPtr)().

Por que não usamos if/else neste exercício?
- Para evitar repetição de código e melhorar a eficiência.

Qual a vantagem de usar arrays de ponteiros para métodos?
- Mapear diretamente uma string para um método, eliminando a necessidade de várias verificações condicionais.

---

Exercício 06 - Harl filter

Propósito: Introdução ao switch statement e filtros dinâmicos.
Lições:
- Implementar filtros de mensagens com base em níveis.
- Usar switch para melhorar clareza e eficiência.

```c++
Objetivo:
Expandir o exercício anterior para filtrar mensagens de log a partir de um nível especificado, usando um switch.

Detalhes Técnicos:
Switch Statement:
- Implementado para selecionar o nível de log inicial.

Filtros Dinâmicos:
- Mensagens de níveis mais altos também são exibidas.

Tratamento de Entradas Inválidas:
- Exibição de uma mensagem genérica para níveis desconhecidos.
```

Por que usamos switch em vez de if/else?
- switch é mais eficiente e legível quando há múltiplas condições baseadas em valores fixos.

Como lidamos com entradas inválidas?
- Um caso padrão (default) é usado para tratar valores inesperados.

Por que exibimos mensagens acima do nível especificado?
- Para imitar um sistema de log real, onde mensagens mais críticas também são exibidas.


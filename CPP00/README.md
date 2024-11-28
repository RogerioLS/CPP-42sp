## Objetivo do CPP 00

### Metas de Aprendizado

#### **Fundamentos da Programação Orientada a Objetos (POO)**
A POO é um paradigma de programação que organiza o código em **objetos**, cada um contendo **atributos** (dados) e **métodos** (funções que manipulam os dados). Esse modelo facilita a manutenção, reutilização e escalabilidade do código.

#### **Compreender a diferença entre**:
- **Atributos públicos e privados**:  
  - **Públicos** (`public`): Podem ser acessados diretamente de fora da classe.  
  - **Privados** (`private`): Somente acessíveis dentro da própria classe, garantindo maior controle sobre os dados.

- **Métodos e funções membros**:  
  - **Métodos**: Funções que pertencem a uma classe e geralmente manipulam seus atributos.  
  - **Funções membros**: Outro termo para métodos, destacando que eles fazem parte da classe.

#### **Trabalhar com `std::string`**
A classe `std::string` da biblioteca padrão C++ fornece uma maneira segura e eficiente de manipular cadeias de caracteres, evitando os problemas associados a strings C (`char*`), como gerenciamento de memória manual e vulnerabilidades de buffer overflow.

#### **Adotar boas práticas**
- **Inicialização de variáveis**: Sempre inicialize variáveis antes de usá-las para evitar comportamentos indefinidos.  
- **Lidar com escopo**: Entender onde e por quanto tempo variáveis existem para evitar conflitos e melhorar a legibilidade.

---

### Tópicos-Chave

#### **Classes e Objetos**
- **Classes**: São a base da POO. Definem um modelo que descreve as características (atributos) e comportamentos (métodos) de um objeto.
- **Objetos**: São instâncias de classes. Cada objeto tem seus próprios valores para os atributos definidos pela classe.

#### **Encapsulamento**
Encapsulamento é o princípio que protege os dados dentro de uma classe:
- **`public`**: Permite acesso de qualquer lugar.
- **`private`**: Restringe o acesso somente aos métodos da própria classe.
- **`protected`**: Permite acesso dentro da classe e de suas subclasses (herança).

O encapsulamento melhora a segurança e a integridade dos dados.

#### **Namespace**
Namespaces ajudam a organizar o código e evitar conflitos de nomes:
- **`std`** é o namespace padrão do C++, onde estão funções e classes como `std::cout`, `std::cin` e `std::string`.  
- Usar namespaces permite que diferentes partes do código tenham variáveis ou funções com o mesmo nome, desde que estejam em namespaces distintos.

#### **Atribuições básicas com strings**
O `std::string` permite manipular strings facilmente:
- **Atribuição**: `std::string s = "Hello";`
- **Concatenação**: `s += " World";`
- **Acesso a caracteres**: `char c = s[0];`
Essas operações são seguras e abstratas, reduzindo a complexidade do código e prevenindo erros comuns.

---
**ex00**:

### CPP05: Resumo, Conceitos, Propósitos e Perguntas Respondidas

Ex00: Mommy, when I grow up, I want to be a bureaucrat!

Neste exercício, implementamos a classe Bureaucrat, que representa um funcionário público com um nome imutável e um grau numérico de 1 a 150. Aprendemos a lançar exceções personalizadas quando o grau está fora dos limites, a sobrecarga do operador de inserção (`<<`), e a manipulação de exceções com `try-catch`.

📌 O Que Este Exercício Quer Ensinar
Propósito:
Introdução a exceções em C++, criando classes de erro personalizadas.
Uso de métodos públicos de manipulação de dados privados.
Implementação de operadores sobrecarregados, como <<, para formatar saídas.

Lições:
✅ Encapsulamento
- O nome do Bureaucrat é const e só pode ser definido no construtor.
- O grau é privado e acessado por meio de getters.

✅ Exceções Personalizadas
- Bureaucrat::GradeTooHighException → Lançada se o grau for menor que 1.
- Bureaucrat::GradeTooLowException → Lançada se o grau for maior que 150.

✅ Sobrecarga do Operador <<
- Permite imprimir um Bureaucrat diretamente no std::cout, exibindo seu nome e grau.

✅ Tratamento de Erros com try-catch
- Ao criar ou modificar um Bureaucrat, capturamos exceções para evitar que o programa falhe.


📂 Declaração e Implementação
Arquivos Necessários
📌 Bureaucrat.hpp - Declaração da classe e suas exceções.
📌 Bureaucrat.cpp - Implementação dos métodos e operadores.
📌 main.cpp - Testes para verificar o funcionamento correto da classe.

```c++
// 📌 Objetivo: Criar uma classe Bureaucrat com:
// Atributos:
// - std::string const name: Nome fixo e imutável do burocrata.  
// - int grade: Grau do burocrata, variando de 1 (maior) a 150 (menor).  
// Métodos:
// - Bureaucrat(std::string name, int grade): Construtor que inicializa o nome e o grau.  
// - ~Bureaucrat(): Destrutor padrão.  
// - getName(): Retorna o nome do burocrata.  
// - getGrade(): Retorna o grau do burocrata.  
// - incrementGrade(): Reduz o grau (1 é o mais alto).  
// - decrementGrade(): Aumenta o grau (150 é o mais baixo).  
// - Sobrecarga do operador << para exibir o Bureaucrat.  
```

❓ Perguntas Possíveis
✅ Por que usamos const no nome do Bureaucrat?
- Para garantir que o nome não possa ser alterado após a criação do objeto.

✅ O que acontece se tentarmos criar um Bureaucrat com um grau inválido?
- O programa lança uma exceção (GradeTooHighException ou GradeTooLowException).

✅ Como funciona o try-catch neste exercício?
- Permite capturar e tratar exceções ao instanciar Bureaucrats, evitando falhas no programa.

✅ Por que sobrecarregamos o operador <<?
- Para imprimir a representação textual do Bureaucrat diretamente no std::cout.

✅ O que aconteceria se não tratássemos as exceções corretamente?
- O programa poderia falhar e encerrar abruptamente, sem chance de recuperação.

✅ Podemos declarar operator<< fora da classe sem friend?
- Sim, mas precisaríamos de métodos getName() e getGrade(), pois friend permite acesso direto aos atributos privados.

<details>
<summary>✅ Checklist de Correção do Ex00 - Mommy, when I grow up, I want to be a bureaucrat!</summary>

🔹 Estrutura e Implementação
✅ Makefile
- O código deve compilar com os flags corretos: -Wall -Wextra -Werror.

✅ Classe Bureaucrat
- Existe uma classe Bureaucrat corretamente definida.

✅ Atributos
- O nome (name) é const e não pode ser alterado depois da criação.
- O grau (grade) varia entre 1 e 150 (1 é o mais alto, 150 o mais baixo).

✅ Exceções
- São lançadas exceções se tentarmos criar um Bureaucrat com um grau fora do intervalo permitido:
- GradeTooHighException para valores menores que 1.
- GradeTooLowException para valores maiores que 150.

✅ Métodos de Acesso (Getters)
- Métodos getName() e getGrade() estão implementados corretamente.

✅ Incremento e Decremento de Grau
- incrementGrade(): Reduz o valor do grau (exemplo: 3 → 2).
- decrementGrade(): Aumenta o valor do grau (exemplo: 3 → 4).
- Ambos os métodos lançam exceções se o grau ultrapassar os limites.

✅ Herança de std::exception
- As exceções devem herdar de std::exception, permitindo serem capturadas com catch (std::exception &e).

✅ Sobrecarga do Operador <<
- O operador << foi sobrecarregado corretamente para exibir as informações do Bureaucrat no formato:

```c++
<name>, bureaucrat grade <grade>.
```

---

❓ Perguntas Possíveis na Avaliação
✅ Por que o nome do Bureaucrat é const?
- Para garantir que o nome não seja alterado após a criação do objeto.

✅ O que acontece se tentarmos criar um Bureaucrat com um grau inválido?
- O programa lança uma exceção (GradeTooHighException ou GradeTooLowException).

✅ Por que usamos try-catch nesse exercício?
- Para evitar crashes inesperados, permitindo tratar erros e continuar a execução do programa.

✅ Como funciona a herança de exceções?
- GradeTooHighException e GradeTooLowException herdam de std::exception, tornando-as padronizadas e fáceis de capturar.

✅ Por que sobrecarregamos o operador <<?
- Para facilitar a exibição de um Bureaucrat sem precisar chamar métodos getName() e getGrade() manualmente.

✅ É possível declarar a sobrecarga do operador << fora da classe Bureaucrat?
- Sim, mas precisaríamos usar métodos getName() e getGrade(), pois friend permite acesso direto aos atributos privados.

</details>


> [!NOTE]
> 🚀 Resumo Final:
> Este exercício nos ensina a criar classes robustas em C++, garantindo que valores inválidos não sejam aceitos e que a saída do programa seja formatada corretamente. O uso de exceções personalizadas e a sobreposição de operadores são conceitos fundamentais para projetos mais complexos.

---

Ex01: Form up, maggots!

Neste exercício, expandimos a burocracia do módulo anterior, introduzindo a classe Form. Um formulário tem um nome imutável, um status de assinatura (bool isSigned), e requisitos de grau para assinatura e execução. Aprendemos a integrar classes com relacionamento forte, aplicar exceções ao validar permissões e sobrecarregar operadores.

📌 O Que Este Exercício Quer Ensinar
Propósito:
✅ Aplicar exceções para verificar permissões de acesso.
✅ Criar relações entre classes (Bureaucrat interagindo com Form).
✅ Aplicar encapsulamento e boas práticas de design OO.
✅ Utilizar a sobrecarga de operadores para formatação de saída.

📖 Lições Aprendidas
✅ Encapsulamento & Atributos Constantes
- O nome do formulário é const, garantindo que nunca será alterado após a criação.
- Os requisitos de grau (gradeToSign e gradeToExecute) também são const.

✅ Exceções Personalizadas
- `Form::GradeTooHighException` → Lançada se o grau exigido for menor que 1.
- `Form::GradeTooLowException` → Lançada se o grau exigido for maior que 150.
- `Form::beSigned(Bureaucrat &b)` → Se o Bureaucrat não tiver um grau suficiente para assinar, a exceção `GradeTooLowException` será lançada.

✅ Integração Entre Classes
- `Bureaucrat::signForm(Form &f)` → O Bureaucrat tenta assinar um formulário.
    - Se bem-sucedido: `"Bureaucrat X signed Form Y"`
    - Se falhar: `"Bureaucrat X couldn't sign Form Y because <motivo>"``

✅ Sobrecarga do Operador `<<`
- Permite exibir os dados do formulário no `std::cout` de forma formatada:
  ```c++
  std::cout << myForm << std::endl;
  ```
  Exemplo de saída esperada:
  ```yaml
  Form XYZ: Signed: No, Required grade to sign: 50, Required grade to execute: 25.
  ```

📂 Declaração e Implementação
Arquivos Necessários:
📌 `Form.hpp` - Declaração da classe Form.
📌 `Form.cpp` - Implementação da classe Form.
📌 `Bureaucrat.hpp/.cpp` - Atualização para incluir signForm().
📌 `main.cpp` - Testes unitários.

```c++
// 📌 Objetivo: Criar uma classe Form com:
// Atributos privados:
// - std::string const name: Nome fixo do formulário.
// - bool isSigned: Indica se foi assinado.
// - int const gradeToSign: Grau necessário para assinar.
// - int const gradeToExecute: Grau necessário para executar.
// Métodos:
// - Form(std::string name, int gradeToSign, int gradeToExecute); // Construtor
// - ~Form(); // Destrutor
// - getName(), getGradeToSign(), getGradeToExecute(), isSigned();
// - void beSigned(const Bureaucrat &b); // Permite assinatura se o Bureaucrat tiver permissão
// - Sobrecarga do operador << para exibir informações do Form
```

❓ Perguntas Possíveis
✅ O que acontece se tentarmos criar um Form com um grau inválido?
- O programa lançará uma exceção (GradeTooHighException ou GradeTooLowException).

✅ O Bureaucrat pode modificar diretamente um Form?
- Não, ele precisa chamar beSigned(), que valida se o grau dele é suficiente.

✅ Por que Form usa atributos const para nome e graus?
- Para garantir que esses valores nunca sejam alterados após a construção do objeto.

✅ Como signForm() e beSigned() interagem?
- signForm() chama beSigned(), que pode lançar uma exceção se o Bureaucrat não tiver um grau suficiente.

✅ O que acontece se um Bureaucrat de grau 100 tentar assinar um Form que requer grau 50?
- Uma exceção GradeTooLowException será lançada.

✅ Podemos declarar operator<< fora da classe sem friend?
- Sim, desde que usemos métodos getName(), getGradeToSign() e getGradeToExecute(), pois friend permite acesso direto a atributos privados.

<details> <summary>✅ Checklist de Correção do Ex01 - Form up, maggots!</summary>

🔹 Estrutura e Implementação

✅ Makefile
- O código deve compilar corretamente com os flags adequados: -Wall -Wextra -Werror.

✅ Classe Form
- A classe Form está implementada corretamente.
- Atributos privados:
    - std::string const name → Nome do formulário, constante e imutável.
    - bool isSigned → Indica se o formulário está assinado. Inicia como false.
    - int const gradeToSign → Grau mínimo necessário para assinar o formulário.
    - int const gradeToExecute → Grau mínimo necessário para executar o formulário.

✅ Validação dos Valores de Grau
- Os valores de gradeToSign e gradeToExecute seguem as mesmas regras do Bureaucrat:
    - 1 é o mais alto, 150 é o mais baixo.
    - Se um grau estiver fora do intervalo permitido, são lançadas exceções:
      - Form::GradeTooHighException se o grau for menor que 1.
      - Form::GradeTooLowException se o grau for maior que 150.

✅ Métodos de Acesso (Getters)
- Métodos implementados corretamente para acessar os atributos privados:
    - getName()
    - getGradeToSign()
    - getGradeToExecute()
    - isFormSigned()

✅ Função beSigned()
- Assina o formulário se o Bureaucrat tiver um grau suficientemente alto (grade ≤ gradeToSign).
- Lança Form::GradeTooLowException caso contrário.

✅ Método signForm() no Bureaucrat
- Implementado conforme especificação:
    - Se a assinatura for bem-sucedida:
      ```c++
      <bureaucrat> signed <form>
      ```

    - Caso contrário, imprime uma mensagem informando o erro:
      ```c++
      <bureaucrat> couldn’t sign <form> because <reason>.
      ```

✅ Sobrecarga do Operador <<
- O operador << foi sobrecarregado corretamente para exibir as informações do formulário no formato:
  ```c++
  <form name>, Form status: <signed/not signed>, Required grade to sign: <grade>, Required grade to execute: <grade>
  ```

---

❓ Possíveis Perguntas na Avaliação
✅ Por que os atributos name, gradeToSign e gradeToExecute são const?
- Porque esses valores nunca devem mudar após a criação do objeto.

✅ O que acontece se tentarmos criar um Form com um grau inválido?
- Uma exceção será lançada (GradeTooHighException ou GradeTooLowException).

✅ Por que usamos Bureaucrat::signForm() ao invés de permitir que Bureaucrat acesse diretamente beSigned()?
- Para encapsular a lógica e fornecer um mecanismo de feedback ao usuário.

✅ Por que beSigned() verifica se o formulário já foi assinado?
- Para evitar que o formulário seja assinado mais de uma vez.

✅ Qual a diferença entre beSigned() e signForm()?
- beSigned() é um método da Form, enquanto signForm() é um método da Bureaucrat que tenta assinar uma Form.

✅ Por que usamos exceções em beSigned()?
- Para garantir que o programa trate corretamente erros de permissão e não permita ações inválidas.

✅ Como funciona a sobrecarga do operador << para Form?
- Permite exibir informações sobre o formulário diretamente no std::cout, sem necessidade de chamar métodos individualmente.

✅ O que aconteceria se beSigned() não verificasse o grau do Bureaucrat?
- Qualquer Bureaucrat, independentemente do seu grau, poderia assinar um formulário, violando as regras do sistema.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício reforça o encapsulamento, exceções personalizadas e interação entre classes, preparando o terreno para sistemas mais complexos de hierarquia de permissões e validação de ações.

---

Ex01: FNo, you need form 28B, not 28C...

Neste exercício, estendemos a hierarquia de `Form` tornando-a uma *classe abstrata* (``AForm``) e criamos *três novos tipos de formulários concretos*. Também adicionamos a capacidade de *executar ações reais*, verificando permissões e lançando exceções adequadas.

📌 O Que Este Exercício Quer Ensinar
Propósito:
✅ Introduzir *classes abstratas* (`AForm`).
✅ Explorar *herança e polimorfismo*.
✅ Implementar *exceções ao validar permissões de execução*.
✅ Criar diferentes *formulários que realizam ações específicas*.

📖 Lições Aprendidas
✅ Classe Abstrata (`AForm`)
- `AForm` substitui `Form`, impedindo que objetos da classe base sejam instanciados diretamente.
- Adicionamos o método virtual puro `execute(Bureaucrat const &executor) const = 0;`, garantindo que cada formulário concreto implemente sua própria ação.


✅ Novas Classes Concretas de Formulário

Criamos três classes derivadas que herdam de AForm, cada uma com um propósito diferente:

1️⃣ ShrubberyCreationForm
- Grau necessário: 145 (para assinar), 137 (para executar).
- Ação: Cria um arquivo <target>_shrubbery e imprime árvores ASCII nele.🌲

2️⃣ RobotomyRequestForm
- Grau necessário: 72 (para assinar), 45 (para executar).
- Ação: Simula um procedimento de robotização no target. O sucesso ocorre 50% das vezes, caso contrário, falha. 🤖

3️⃣ PresidentialPardonForm
- Grau necessário: 25 (para assinar), 5 (para executar).
- Ação: Informa que o target foi perdoado por Zaphod Beeblebrox. 📜

✅ Controle de Execução e Exceções
- O formulário só pode ser executado se estiver assinado e se o Bureaucrat tiver grau suficiente.
- Caso contrário, lança exceções:
    - `AForm::GradeTooLowException` → Se o grau do `Bureaucrat` for muito baixo.
    - `AForm::FormNotSignedException` → Se o formulário ainda **não foi assinado**.

✅ Novo Método no Bureaucrat
- `executeForm(AForm const &form):`
  - Se a execução for bem-sucedida, imprime:
    ```c++
    <bureaucrat> executed <form>
    ```
  - Caso contrário, imprime uma mensagem informando o erro.

📂 Declaração e Implementação
Arquivos Necessários:
📌 `AForm.hpp` / `AForm.cpp` → Definição e implementação da classe abstrata.
📌 `ShrubberyCreationForm.hpp` / `.cpp` → Formulário que cria árvores.
📌 `RobotomyRequestForm.hpp` / `.cpp` → Formulário que executa uma cirurgia robótica.
📌 `PresidentialPardonForm.hpp` / `.cpp` → Formulário que concede perdão presidencial.
📌 `Bureaucrat.hpp` / `.cpp` → Atualização para incluir executeForm(AForm const &form).
📌 `main`.cpp` → Testes completos para validar comportamento e exceções.

```c++
// 📌 Objetivo: Criar um sistema de formulários executáveis com validação de permissões
Atributos:
- std::string const name: Nome do formulário.
- bool isSigned: Indica se o formulário foi assinado.
- int const gradeToSign: Grau necessário para assinar.
- int const gradeToExecute: Grau necessário para executar.
Métodos:
- beSigned(Bureaucrat const &b): Assina o formulário.
- execute(Bureaucrat const &executor) const = 0; (virtual puro)
- Implementações específicas para cada formulário:
  - ShrubberyCreationForm: Cria um arquivo com árvores ASCII.
  - RobotomyRequestForm: Tem 50% de chance de sucesso ao "robotizar" o alvo.
  - PresidentialPardonForm: Concede perdão presidencial.
- Bureaucrat:
  - executeForm(AForm const &form): Tenta executar o formulário.
```

❓ Perguntas Possíveis

✅ Por que transformamos `Form` em uma classe abstrata `AForm`?
- Para garantir que **não seja instanciada diretamente**, pois apenas os formulários concretos devem ser criados.

✅ O que significa `execute(Bureaucrat const &executor) const = 0;`?
- Indica que `execute` é virtual puro, forçando as subclasses a implementarem suas próprias versões.

✅ O que acontece se um `Bureaucrat` tentar executar um formulário sem permissão?
- Será lançada uma exceção `GradeTooLowException`.

✅ E se um formulário não estiver assinado e for executado?
- Lançará `FormNotSignedException`, impedindo a execução.

✅ Como funciona `executeForm(AForm const &form)` no `Bureaucrat`?
- Tenta executar o formulário, capturando possíveis exceções e imprimindo mensagens apropriadas.

✅ Por que `RobotomyRequestForm` tem 50% de chance de sucesso?
- Para simular um processo falho, utilizando `rand()` para determinar aleatoriamente o resultado.

✅ Por que `ShrubberyCreationForm` escreve um arquivo?
- Para demonstrar que formulários podem executar ações no sistema, como criar relatórios ou logs.

✅ Como podemos testar se as exceções estão funcionando corretamente?
- Criando `Bureaucrats` com diferentes níveis e tentando assinar/executar formulários com permissões insuficientes.

<details> <summary>✅ Checklist de Correção do Ex02 - </summary>

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício reforça conceitos essenciais de **herança, polimorfismo e exceções** em C++.
> Implementamos **três tipos de formulários**, adicionamos verificações rigorosas de permissão e criamos um **mecanismo robusto de execução** no `Bureaucrat`.
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
- O código deve compilar com os flags corretos: -Wall -Wextra -Werror.

✅ Classe Form
- Existe uma classe Form corretamente definida.

✅ Atributos
- O nome (name) é const e não pode ser alterado depois da criação.
- O grau requerido para assinar a forma é const e fica entre 1 (mais alto) e 150 (mais baixo).
- O grau requerido para executar a forma também é const e fica entre 1 (mais alto) e 150 (mais baixo).
- A variável signed (que indica se a forma foi assinada ou não) é bool e inicialmente é false.

✅ Métodos de Acesso (Getters)
- O método getName() deve retornar o nome da forma.
- O método getIsSigned() deve retornar se a forma foi assinada.
- O método getGradeToSign() deve retornar o grau necessário para assinar a forma.
- O método getGradeToExecute() deve retornar o grau necessário para executar a forma.

✅ Sobrecarga do Operador <<
- O operador << deve ser sobrecarregado corretamente para exibir as informações da Form no formato:
```c++
Form <name>, required grade to sign <signGrade>, required grade to execute <execGrade>, signed: <true/false>.
```

✅ Método beSigned()
- O método beSigned() deve verificar se o Bureaucrat tem o grau necessário para assinar a Form e, em caso positivo, alterar o estado de signed para true.
- Deve lançar uma exceção GradeTooLowException se o Bureaucrat não tiver o grau necessário para assinar a Form.

✅ Método signForm()
- O método signForm() da classe Bureaucrat deve chamar o método beSigned() da Form para tentar assinar a forma.
- Se o Bureaucrat não tiver o grau necessário para assinar, deve lançar uma exceção GradeTooLowException.

---

❓ Perguntas Possíveis na Avaliação 

✅ Por que o nome da forma é const?
- Para garantir que o nome da forma não seja alterado após a criação do objeto, mantendo a integridade da forma.

✅ O que acontece se tentarmos assinar uma forma sem ter o grau necessário?
- O programa lança uma exceção GradeTooLowException.

✅ Qual a finalidade do método beSigned()?
- O método verifica se o Bureaucrat tem o grau necessário para assinar a forma e, se possível, altera o estado da forma para assinada.

✅ Por que usamos exceções no código?
- As exceções permitem lidar com erros de forma controlada, evitando falhas inesperadas no programa e possibilitando tratamento adequado dos erros, como o grau inválido.

✅ Como sobrecarregamos o operador <<?
- O operador << é sobrecarregado para permitir a exibição das informações da Form de forma legível, sem necessidade de chamar os métodos de acesso manualmente.

✅ É possível declarar a sobrecarga do operador << fora da classe Form?
- Sim, desde que a classe Form seja declarada como friend da função sobrecarregada ou seja usada a forma de implementação fora da classe com métodos de acesso público.

</details>

> [!NOTE]
> 🚀 Resumo Final:
> Este exercício reforça o encapsulamento, exceções personalizadas e interação entre classes, preparando o terreno para sistemas mais complexos de hierarquia de permissões e validação de ações.
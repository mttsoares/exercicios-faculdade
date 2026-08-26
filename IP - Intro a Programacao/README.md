# EXERCÍCIOS PROGRAMA (EPs)

**`Atividades avaliativas de Introdução à Programação`**

---
#### Aqui você encontra dois exercícios programa propostos na disciplina de Introdução à Programação. O foco destes exercícios é avaliar os conhecimentos em lógica de programação, além de verificar outras questões como indentação de código, explicação das funcionalidades do programa (via comentários) e a funcionalidade do exercício seguindo o proposto pelo enunciado.<br>
---

## EP 1 - Implementação de Funções Lógicas e Matemáticas

No primeiro EP, o objetivo foi implementar seis funções em linguagem C conforme as especificações do enunciado:
* **Assinaturas:** Todas as funções foram implementadas exatamente com as assinaturas fornecidas no arquivo base.
* **Estruturas básicas:** Utilização exclusiva de laços (`for`, `while`), condicionais (`if`, `else`) e conceitos fundamentais de C.
* **Bibliotecas:** Restrito apenas à biblioteca padrão `<stdio.h>`.

---

### Funções Implementadas

#### 1. Cálculo de Fatorial (`fatorial`)
Calcula o fatorial ($n!$) de um número inteiro não negativo $n$.
* **Retorno (`double`):** Retorna o valor de $n!$ (considerando $0! = 1$).
* **Tratamento de erro:** Retorna `-1.0` caso $n$ seja negativo.

#### 2. Cálculo de Potência (`potencia`)
Calcula a potência ($\text{base}^{\text{exp}}$) para expoentes inteiros não negativos.
* **Retorno (`long`):** O resultado da potenciação (com $\text{base}^0 = 1$ para qualquer base diferente de zero).
* **Tratamento de erro:** Retorna `-1` se o expoente for negativo ou se a base e o expoente forem ambos iguais a zero.

#### 3. Aproximação do Número de Euler (`aproximarEuler`)
Calcula uma aproximação do número de Euler ($e$) utilizando a somatória dos primeiros $k$ termos da série:
$$e \approx \sum_{i=0}^{k-1} \frac{1}{i!}$$
* **Integração:** Reutiliza a função `fatorial` previamente implementada.
* **Retorno (`double`):** O valor aproximado de $e$.
* **Tratamento de erro:** Retorna `-1.0` caso $k < 1$.

#### 4. Pedra, Papel e Tesoura - Rodada (`verificarVitoriaRodada`)
Determina o vencedor de uma rodada individual entre dois jogadores (`PEDRA = 0`, `PAPEL = 1`, `TESOURA = 2`).
* **Regras:** Pedra vence tesoura, tesoura vence papel e papel vence pedra.
* **Retorno (`int`):** 
  * `0` em caso de empate
  * `1` se o Jogador 1 vencer
  * `2` se o Jogador 2 vencer

#### 5. Pedra, Papel e Tesoura - Melhor de Três (`melhorDeTres`)
Determina o vencedor final de uma disputa de 3 rodadas utilizando a função `verificarVitoriaRodada`.
* **Retorno (`int`):** 
  * `1` se o Jogador 1 vencer mais rodadas
  * `2` se o Jogador 2 vencer mais rodadas
  * `0` se houver empate no número de vitórias

#### 6. Verificação de Número Narcisista (`ehNarcisista`)
Verifica se um número inteiro positivo é **narcisista** (quando a soma de seus dígitos elevados à quantidade total de dígitos resulta no próprio número, ex: $153 = 1^3 + 5^3 + 3^3$).
* **Lógica:** Conta o número de dígitos, calcula a soma das potências de cada dígito e compara com o número original.
* **Retorno (`int`):** Retorna `1` (verdadeiro) se for narcisista ou `0` (falso) caso contrário.

---

## EP 2 - Sistema de Gestão Acadêmica (Estruturas e Alocação)

No segundo EP, o objetivo foi desenvolver um sistema simplificado de gestão universitária (controle de cursos, turmas, alunos e históricos escolares) em linguagem C. O exercício explora o uso avançado de **Estruturas (`struct`)**, **Ponteiros**, **Alocação Dinâmica de Memória (`malloc`)** e **manipulação de Históricos Acadêmicos**.

---

### Estruturas de Dados Utilizadas

* **`TURMA`:** Representa uma oferta de disciplina, contendo código, nome, número total de vagas, arranjo dinâmico de NUSP dos alunos matriculados, dia da semana e período (Manhã, Tarde ou Noite).
* **`DESEMPENHO`:** Registra a situação de um aluno em uma turma específica, armazenando a nota (0 a 100), frequência (0 a 100) e o status (`'M'` para Matriculado, `'A'` para Aprovado ou `'R'` para Reprovado).
* **`ALUNO`:** Armazena o nome, NUSP, o histórico escolar (arranjo de `DESEMPENHO`), quantidade de turmas já cursadas e o status geral no curso (`'M'` para Matriculado, `'F'` para Formado ou `'J'` para Jubilado).
* **`CURSO`:** Gerencia o conjunto de alunos inscritos e turmas oferecidas.

---

### Funções Implementadas

#### 1. Cadastro no Curso (`adicionarAlunoAoCurso` / `adicionarTurmaAoCurso`)
* **`adicionarAlunoAoCurso`:** Insere a referência de um novo aluno no curso, evitando duplicatas com base no número USP e respeitando o limite máximo do curso (`MAX_ALUNOS_CURSO`).
* **`adicionarTurmaAoCurso`:** Cadastra uma nova turma no curso, garantindo que o mesmo ponteiro de turma não seja duplicado e respeitando o limite máximo (`MAX_TURMAS_CURSO`).

#### 2. Matrícula em Turmas (`matricularAlunoEmTurma`)
Gerencia a inclusão de um aluno em uma turma específica, realizando uma série de validações complexas:
* Atualiza o status geral do aluno antes da tentativa de matrícula.
* **Validações de bloqueio:** Retorna falso se a turma estiver cheia, se o aluno não estiver ativo (`status != 'M'`), se ultrapassar o limite de disciplinas no histórico ou se o aluno já estiver aprovado ou matriculado na mesma disciplina.
* **Verificação de Choque de Horário:** Impede que o aluno se matricule em turmas diferentes no mesmo dia e período.

#### 3. Lançamento de Desempenho (`cadastrarNota`)
Registra a nota e a frequência de um aluno em uma disciplina onde ele esteja atualmente matriculado (`status == 'M'`).
* **Critério de Aprovação:** O status do desempenho é atualizado para `'A'` (Aprovado) caso a nota seja $\ge 50$ e a frequência seja $\ge 70$; caso contrário, é atualizado para `'R'` (Reprovado).

#### 4. Atualização de Situação Acadêmica (`atualizarStatusAluno`)
Avalia o histórico do aluno e atualiza o seu status geral:
* **`'F'` (Formado):** Alcançado caso o número de aprovações seja maior ou igual a `DISCIPLINAS_NECESSARIAS`.
* **`'J'` (Jubilado):** Ocorre quando a quantidade máxima restante de turmas possíveis no histórico (`MAX_TURMAS` menos reprovações) não é suficiente para atingir as disciplinas necessárias para a formatura.
* **`'M'` (Matriculado):** Mantido caso nenhuma das situações acima seja atingida.

#### 5. Estatística de Desempenho (`retornarModaDasNotasDeAluno`)
Calcula a **moda** das notas obtidas pelo aluno em todas as turmas concluídas (status `'A'` ou `'R'`).
* As notas (0 a 100) são convertidas para a escala de 0 a 10 via divisão inteira (`nota / 10`).
* Em caso de empate entre duas frequências máximas de notas, a função retorna o valor de nota mais alto.

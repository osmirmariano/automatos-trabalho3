# teoriaComputacaoAutomatos-TR3

Implementar computacionalmente, em linguagem acordada com o professor, um programa que, a partir de um Autômato Finito Determinístico (AFD) fornecido pelo usuário, seja capaz aceitar ou rejeitar palavras da linguagem projetada do AFD.

Para tanto, o programa deve permitir a entrada dos cinco elementos que compõem o AFD:

* Σ conjunto finito de símbolos de entrada (alfabeto).

* Q conjunto de estados possíveis do autômato o qual é finito.

* δ função programa ou função de transição δ. Se q é um estado e a é um símbolo de entrada, então δ(q,a) é o estado p.

* q0 estado inicial tal que q0 é elemento de Q. 

* F conjunto de estados finais tal que F está contido em Q.

Adicionalmente, o programa deve conter um campo de ENTRADA ou FITA. Nesse campo o usuário digitará uma palavra. O programa então deverá verificar se a palavra pertence ou não à Linguagem Regular do AFD fornecido pelo usuário. Para isso você deverá usar a função de transição estendida, do mesmo modo que implementado no trabalho 2. No trabalho 2 a função de transição δ do AFD estava declarada diretamente no código-fonte. Neste trabalho a função será fornecida pelo usuário.

Para auxiliá-lo na implementação, considere usar três funções:

* retornaLinha(q) = recebe um estado q ∈ Q e retorna a posição de q no conjunto (vetor) Q. Essa posição corresponde à linha do estado q na tabela de transição;

* retornaColuna(a) = recebe um símbolo a ∈ Σ e retorna a posição de a no conjunto (vetor) Σ (alfabeto). Essa posição corresponde à coluna do símbolo a na tabela de transição;

* funcaoDeTransicao(q,a) = recebe um estado q ∈ Q e um símbolo a ∈ Σ. Esta função faz chamada às funções retornaLinha(q) e retornaColuna(a) para descobrir a célula da tabela de transições que armazena o estado a ser retornado pela função

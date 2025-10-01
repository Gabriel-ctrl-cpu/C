/*O que é uma lista estática? Quais são as principais vantagens e desvantagens da lista estática 
em comparação com a lista dinâmica? Explique o que acontece se tentarmos inserir mais elementos 
do que a capacidade máxima de uma lista estática.


Uma lista estática é uma estrutura de dados que armazena elementos em um bloco de memória contíguo e fixo, 
geralmente implementada como um array com tamanho definido no momento da criação. Ou seja, a capacidade da 
lista é limitada e não pode crescer ou diminuir durante a execução do programa.



Principais vantagens

Simplicidade: Implementação mais simples, pois o tamanho é fixo e conhecido.
Acesso rápido: O acesso a qualquer elemento é feito em tempo constante (O(1)) porque a posição é 
calculada diretamente pelo índice.
Menor overhead: Não há necessidade de gerenciar ponteiros ou alocação dinâmica de memória, 
o que pode economizar recursos e evitar fragmentação.



Principais desvantagens

Capacidade fixa: A lista não pode crescer além do tamanho definido, o que pode causar problemas 
se precisar armazenar mais elementos do que o previsto.
Desperdício de memória: Se a lista não estiver completamente cheia, a memória reservada
fica ociosa, o que pode ser ineficiente.
Menos flexível: Difícil de redimensionar em tempo de execução.


Se você tentar inserir um elemento além da capacidade da lista estática, ocorrerá um erro 
(geralmente chamado de overflow). Isso pode causar:
Falha do programa, caso não haja tratamento de erro adequado.
Sobrescrita de memória adjacente, levando a comportamento imprevisível e falhas de segurança (em linguagens que não fazem checagem automática de limites, como C).
Exceções ou erros em linguagens que fazem verificação de limites, como Java ou Python.
*/
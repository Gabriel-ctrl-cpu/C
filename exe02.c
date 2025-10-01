/*Cite três critérios que podem ser usados para escolher a estrutura de dados mais 
adequada para um problema. Considere listas, pilhas e filas. 


1. Tipo de acesso aos dados

Lista: Permite acesso a qualquer elemento em posições arbitrárias (acesso sequencial ou por índice).

Pilha: Acesso restrito ao último elemento inserido (LIFO - Last In, First Out).

Fila: Acesso restrito ao primeiro elemento inserido (FIFO - First In, First Out).

Se você precisa acessar dados em ordem sequencial ou aleatória, uma lista pode ser melhor. Se precisa trabalhar com última entrada primeiro, 
pilha é ideal. Para processar na ordem de chegada, fila é a escolha certa.



2. Operações frequentes no problema

Lista: Inserção, remoção ou busca em qualquer posição.

Pilha: Inserção e remoção sempre no topo.

Fila: Inserção no final e remoção no início.

Se o problema exige manipulação em ambas as extremidades, a fila ou pilha funcionam melhor, pois são mais eficientes para essas operações específicas.



3. Regras de processamento dos dados

Lista: Sem regras rígidas, pode armazenar elementos em qualquer ordem.

Pilha: Segue a regra LIFO, útil para desfazer ações (undo), análise de expressões, etc.

Fila: Segue a regra FIFO, usada em processamento de tarefas em ordem de chegada, filas de atendimento, etc.

Portanto, a regra de negócio (como os dados devem ser processados) orienta a escolha da estrutura.*/
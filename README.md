# BIS(G²) - Trabalho 3 / 3
Disciplina: Teoria dos Grafos     
Docente: Dr. Felipe Francisco     
Discente: Ivanicio Junior     
Matricula: 17202004      

### Descrição
Implementar um algoritmo baseado em métodos de coloração de Grafos, para obter soluções parciais ou completas para o Puzzle Sudoku, em diferentes níveis de jogatina. A solução deve modelar, classificar e decidir quais vértices deve colorir por meio de modelos de algoritmos heurísticos. Não há algoritmo conhecido na literatura que seja eficiente e capaz de encontrar o número cromático ótimo de um grafo, logo, o problema de coloração de grafos é NP-Completo. Uma vez que o problema da determinação do número cromático é classificado como NP-completo, qualquer algoritmo exato empregado em sua resolução terá complexidade exponencial, desta maneira, torna-se importante a utilização de técnicas heurísticas para solução aproximada desse problema em tempo polinomial.  

### Algoritmo utilizado: Welsh e Powell
O algoritmo de Welsh e Powell é um algoritmo guloso, visto que determina a cor do vértice ݆j após os ݆j-1 vértices terem sido coloridos, tendo sempre como propósito minimizar o número de cores necessárias.

### Informações adicionais
  - Projeto para o trabalho final da disciplina de Teoria dos Grafos do curso de Ciência da Computação da URSA - Faculdade RSá;
  - Prazo de entrega: 15/12/2018;
  - Equipe: Eu e Deus;

### Referências literárias
- https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/vertex-coloring.html
- https://en.wikipedia.org/wiki/Graph_coloring
- https://www.researchgate.net/publication/260517476_TECNICAS_DE_COLORACAO_DE_GRAFOS_APLICADAS_A_RESOLUCAO_DE_QUEBRA-CABECAS_DO_TIPO_SUDOKU
- http://www.din.uem.br/sbpo/sbpo2016/pdf/156677.pdf
- https://www.polymtl.ca/pub/sites/lagrapheur/docs/en/documents/NotesChap7.pdf
- http://www.decom.ufop.br/menotti/paa111/files/PCC104-111-ars-11.1-MarceloFerreiraRego.pdf

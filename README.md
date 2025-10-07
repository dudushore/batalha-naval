# batalha-naval
# Batalha Naval com Habilidades Especiais em Área de Efeito

## Descrição do Projeto

O programa implementa um sistema de habilidades especiais com diferentes áreas de efeito, demonstrando a manipulação de matrizes, lógica condicional e a sobreposição de padrões em um tabuleiro 2D utilizando a linguagem C.

## Funcionalidades Implementadas

O programa possui as seguintes funcionalidades, cumprindo todos os requisitos do desafio:

* **Tabuleiro de Jogo:** Um tabuleiro padrão de 10x10 onde o jogo acontece, representando a água e os navios posicionados.

* **Geração Dinâmica de Habilidades:** Três matrizes de habilidade são criadas dinamicamente usando loops aninhados e lógica condicional para formar suas geometrias únicas:
    * **Habilidade em Cruz:** Afeta uma linha e uma coluna inteira a partir de um ponto central.
    * **Habilidade em Cone:** Afeta uma área triangular que se expande para baixo a partir de um ponto de origem.
    * **Habilidade em Octaedro:** Afeta uma área em formato de losango (ou diamante) a partir de um ponto central.

* **Sistema de Sobreposição (Overlay):** Uma função foi desenvolvida para sobrepor qualquer matriz de habilidade no tabuleiro principal em coordenadas de origem específicas. A lógica inclui:
    * Cálculo preciso da área de efeito no tabuleiro.
    * Marcação das posições afetadas com um valor visual distinto.
    * Validação para que a área de efeito não ultrapasse os limites do tabuleiro.

* **Visualização Clara:** O tabuleiro é exibido no console com caracteres distintos para cada elemento, facilitando a visualização e a compreensão do estado do jogo:
    * `.` para Água
    * `N` para Navio
    * `*` para Área de Efeito da Habilidade

## Tecnologias Utilizadas

* **Linguagem:** C
* **Compilador:** GCC (MinGW-w64 via MSYS2)

## Como Compilar e Executar

Para compilar e executar o projeto, é necessário ter o compilador GCC instalado e configurado corretamente no PATH do sistema.

1.  **Navegue até a pasta do projeto**
    Abra um terminal e use o comando `cd` para navegar até o diretório onde o arquivo `batalha_naval_habilidades.c` se encontra.

2.  **Compile o código-fonte**
    Execute o seguinte comando no terminal:
    ```bash
    gcc batalha_naval_habilidades.c -o batalha_naval.exe
    ```

3.  **Execute o programa**
    Após a compilação bem-sucedida, execute o arquivo gerado:
    ```bash
    .\batalha_naval.exe
    ```
    O programa exibirá o tabuleiro inicial e, em seguida, o estado do tabuleiro após a aplicação de cada uma das três habilidades em locais pré-definidos.

## Autor

* **Nome:** Eduardo Costa

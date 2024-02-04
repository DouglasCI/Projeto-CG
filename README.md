# **Projeto Final** - Computação Gráfica
> ### ***Instruções de compilação***
> 1. Dentro do diretório *Projeto*, crie um novo diretório chamado *build*;
> 2. No interior do diretório *build* abra um terminal e insira os comandos abaixo;
>    ```
>    cmake ../
>    ```
>    ```
>    make
>    ```
> 3. Para executar o programa, use o comando abaixo, ajustando o caminho relativo do arquivo executável.
>    ```
>    ./src/main
>    ```

> ### ***Documentação***
> A documentação completa e detalhada do código está em ***Documentation.html***.

> ## - ***Implementação***
> Foi reutilizado todo o código implementado durante o curso. A versão do código usada foi a da [Atividade06](https://github.com/DouglasCI/Computacao-Grafica/tree/main/Atividade06).
> 
> A única mudança feita dessa versão para a deste projeto foi a adição de métodos *move*, que servem para mover os objetos da cena. Esse método recebe um vetor da direção do movimento desejado por parâmetro e adiciona o valor dele aos pontos pertinentes ao objeto. Por exemplo, para uma esfera, ele adiciona o vetor de movimento ao seu centro, já para um objeto com faces triangulares, ele adiciona esse valor a cada vértice de cada triângulo.
> 
> No arquivo *main.cpp* no diretório *src*, temos a parte da instanciação dos objetos no mundo e da animação desses objetos. O único método utilizado para a animação foi o *move*. 
> 
> Além disso, foram utilizadas equações da Cinemática para simular um movimento mais realístico dos objetos.

> ## - ***Objetos***
> A cena em questão é composta por um cubo grande com material difuso advindo do arquivo *big_cube.obj* que será nosso chão. E, também, há um cubo menor metálico gerado a partir do arquivo *small_cube.obj* que fica em cima do cubo maior. Ambos esses arquivos estão no diretório *input*.
>
> Por fim, em cima do chão, existem duas esferas: uma metálica e outra feita de material dielétrico. Ambas são do mesmo tamanho e estão alinhadas junto com o cubo menor.

> ## - ***Animação***
> A animação consiste na esfera metálica em movimento retilíneo uniforme em direção à esfera de vidro. Assim que as duas esferas se chocam, a de metal move-se na direção oposta desaceleradamente, enquanto a de vidro anda com velocidade constante em direção ao cubo pequeno. Quando ela se choca com o cubo, ele permanece parado, porém a esfera de vidro se afasta na direção oposta com velocidade decrescente. Ademais, a camera se desloca para cima durante toda a cena.
>
> A animação possui 9fps e 5 segundos de duração, totalizando 45 frames, e está em resolução 480x270. Todos os frames estão no diretório *images* e o vídeo resultante se chama *ProjetoCG.mp4*.

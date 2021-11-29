# Matemática e Lógica: Que questões são essas?

São questões mais raras do que as de estruturas de dados e
algoritmos mais conhecidos, pois são questões "quebra-cabeça".

No caso de entrevistas, estas questões poderão ser resolvidas
através da lógica ou do conhecimento de fundamentos da 
matemática ou da computação.

Não se assuste se cair um destes problemas na sua 
entrevista. O entrevistador não espera que você saiba
a resposta imediatamente. Apenas verbalize sua linha de
raciocíneo para mostrar ao entrevistador como você aborda
o problema.

Em diversas situações, o problema que você receber terá
padrões. Eles podem te guiar para uma solução, anote 
eles.

## Números Primos

- Todo número positivo pode ser decomposto em um produto de 
números primos
- Suponha x e y tal que y divide x, ou seja `x % y == 0`. 
Por tanto, todos os fatores primos de x também são fatores 
de y.

### Checar se é primo

Como você faria para checar se um número é primo? 
Qual a complexidade disso?

<details>

<summary>Veja a resposta!</summary>  

Você pode pensar em testar todos os números, um por um, 
mas podemos reduzir a complexidade para O(\sqrt{N})
se lembrarmos que o maior divisível de um número N é
menor ou igual a \sqrt{N}. Veja a prova [aqui](https://qastack.com.br/programming/5811151/why-do-we-check-up-to-the-square-root-of-a-prime-number-to-determine-if-it-is-pr).

Código: [eh_primo.cpp](eh_primo.cpp)

Para saber porque não usei sqrt:
- [Why Math Functions in C++ Are So Slow?](https://hackernoon.com/why-math-functions-in-c-are-so-slow-nxz3155)
</details>

Após compreender a resolução anterior
você pode tentar soluções verdadeiramente
eficientes explicadas [nesta página da Geeksforgeeks](https://www.geeksforgeeks.org/prime-numbers/) e [nesta página da Wikipedia](https://en.wikipedia.org/wiki/Primality_test).

Mas não se preocupe, a solução apresentada é o
suficiente para entrevistas. Se quiser mostrar domínio em
matemática, primeiro se preocupe em aprender o básico 
requisitado e depois avance para tópicos mais avançados!

### Gerar uma lista de primos

Reflita sobre como você geraria uma lista de primos.

<details>

<summary>Veja a resposta!</summary>

Você pode pensar em usar o algoritmo anterior para testar
cada número, mas essa solução seria muito custosa.

Uma solução mais eficiente é o algoritmo de Erastotenes,
com complexidade O(N log N).

<img src="crivo_animado.gif">

Código: [crivo.cpp](crivo.cpp)

Veja a explicação sobre a complexidade [aqui](https://noic.com.br/materiais-informatica/curso/math-03/).

</details>

### Veja dois problemas interessantes:

1. [Ajude Riemman](https://neps.academy/br/exercise/288)  
[Solução](Ajude_Riemman.cpp)

2. [Primos Menores do que Dada Magnitude](https://neps.academy/br/exercise/295)  
[Solução](Primos_Menores_Que_N.cpp)

## Probabilidade

Lembretes:
- P(A∩B) = P(B|A) * P(A)
- P(A∪B) = P(A) + P(B) - P(A∩B)
- **Independência:** Um ocorrer não implica nada sobre a 
ocorrência do outro: P(A∩B) = P(A) * P(B), isso porque 
P(B|A) = P(B)
- **Mutualmente Excludente:** Se um acontece, o outro 
não pode acontecer: P(A∪B) = P(A) + P(B), pois P(A∩B) = 
0.

## Problemas

1. Você possui 9 bolas. 8 são do mesmo peso e 1 é mais
pesada. Você tem uma balança que diz qual lado é mais
pesado. Encontre a bola mais pesada com 2 usos da balança

<details>

<summary>Veja a resposta!</summary>

Separe as bolas em 3 conjuntos de 3 bolas. Meça dois
conjuntos. Assim, você saberá em qual conjunto está a
bola mais pesada.
Divida este conjunto em 3 novos conjuntos de uma bola e
meça novamente. Assim encontramos a bola.

</details>

2. You  have 20 bottles of pills. 19 bottles have 1.0
gram pills, but one has pills of weight 1.1 grams. Given 
a scale that provides an exact measurement, how would 
you find the heavy bottle? You  can  only use the scale  
once. 

[Solução](bottles.cpp)

3. You  have a basketball hoop and someone says  that you can  play one of two games. 
Game 1: You  get one shot to make the hoop. 
Game 2: You  get three shots and you have to make two of three shots. 
If p  is  the probability of making a particular shot, for which values of p should  you  pick one game 
or the other?

<details>

<summary>Veja a resposta!</summary>

Probabilidade de ganhar:
- Game 1: p
- Game 2: p * p * p + p * p * (1-p) + p * (1-p) * p + (1-p) * p * p = 3*(1-p)*p² + p^3 = 3p² - 2p³

Qual a probabilidade de P(G_1) > P(G_2)?
   p > 3p² - 2p³  
   (2p - 1)(p - 1) > 0

Como:
   Temos que (2p -1) e (p - 1) são ambos termos 
   negativos, já que p teria que ser maior do que 100%
   para que p - 1 fosse positivo.  

Portanto:
   2p - 1 < 0
   2p < 1
   p < 0.5

Sendo assim, se p ∈ {0, 0.5, 1}, então tanto faz se é 
jogado o Game 1 ou Game 2. Se 0 < p < 0.5, então o melhor
é jogar o Game 1. Se 0.5 < p < 1, então é mais vantajoso
o Game 2.

[Solução](Game.cpp)
</details>

4. There is  an  8x8  chessboard  in which two diagonally opposite corners have been cut off. 
You  are  given 31  dominos, and a single domino can  cover exactly two squares.  Can  you use  the 31 
dominos to cover the entire board? 

<details>

<summary>Veja a resposta!</summary>

8*8 = 64
64 - 2 = 62.

Cada peça ocupa 2 espaços. `31 * 2 == 62`. Há espaço para
todas as peças.

Padrão: Cada peça deita-se, necessariamente, sob uma peça
branca e outra preta. Há 32 peças pretas e 30 brancas, ou
30 pretas e 32 brancas, pois retiramos as pontas 
diagonalmente opostas. Logo, não podemos posicionar as 31
peças no tabuleiro!

</details>

5. Ants on a Triangle: There are three ants on different vertices of a triangle. What is the probability of 
collision (between any two or all  of them) if they start walking on the sides of the triangle? Assume 
that each ant randomly picks a direction, with either direction being equally likely to be chosen, and 
that they walk at the same speed.

<details>

<summary>Veja a resposta!</summary>

Vamos simplificar dizendo que a formiga pode andar em
sentido horario ou anti-horário.

Caso em que ninguem colide: Ou todas vão no sentido
horário, ou todas vão sentido anti-horário.
    (1/2)³ + (1/2)³

Como a probabilidade de alguem colidir, é igual a 100
menos a probabilidade de não colidir, a chance de colidir
é:
    p = 1 - (1/2)³ + (1/2)³ = 1 - (1/2)² = 0.75

</details>

6. Similarly, find the probability of collision with n ants on an  n-vertex polygon.

<details>

<summary>Veja a resposta!</summary>

Precisamos que todas as n formigas, escolham o mesmo 
sentido, horário ou anti-horário
    (1/2)^n + (1/2)^n

Ou seja, a probabilidade de colisão é:
    p = 1 - (1/2)^(n-1)

</details>

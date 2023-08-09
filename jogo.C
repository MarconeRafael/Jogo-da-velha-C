#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printfDoJogo(int **jogo)
{
  printf("\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (jogo[i][j] == 'X')
      {
        printf("X ");
      }
      else if (jogo[i][j] == 'O')
      {
        printf("O ");
      }
      else
      {
        printf("%d ", jogo[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

int logica(int **jogo, int caracter)
{
  for (int i = 0; i < 3; i++)
  {
    if (jogo[i][0] == caracter && jogo[i][1] == caracter &&
        jogo[i][2] == caracter)
    {
      /* Nessa condi��o � feito a verifica��o horizontral (linha), se cada
       * posi��o � igual a 'X'. O "i" varia de 0 a 2 (sendo a linha) e a coluna
       * fica fixa sendo 0, 1, 2 para cada repeti��o */

      return 1; // Retorna 1 em caso de vit�ria do usu�rio
    }
    if (jogo[0][i] == caracter && jogo[1][i] == caracter &&
        jogo[2][i] == caracter)
    {
      /* Nessa outra condi��o � feito a verifica��o vertical(coluna) se cada
       * posi��o � igual a 'X'. O "i" varia de 0 a 2 (sendo a coluna) e a linha
       * fica fixa sendo 0, 1, 2 para cada repeti��o */

      return 1; // Retorna 1 em caso de vit�ria do usu�rio
    }
  }

  /*J� essas duas condi��es � para as duas diagonais: */
  if (jogo[0][0] == caracter && jogo[1][1] == caracter &&
      jogo[2][2] == caracter)
  {
    return 1; // Retorna 1 em caso de vit�ria do usu�rio
  }
  if (jogo[0][2] == caracter && jogo[1][1] == caracter &&
      jogo[2][0] == caracter)
  {
    return 1; // Retorna 1 em caso de vit�ria do usu�rio
  }

  return 0;
}

void Computador(int **jogo)
{
  int linha, coluna;
  do
  {
    linha = rand() % 3;  // Valor aleat�rio de linha entre 0 e 2
    coluna = rand() % 3; // Valor aleat�rio de coluna entre 0 e 2

  } while (jogo[linha][coluna] == 'X' ||
           jogo[linha][coluna] ==
               'O'); // A repeti��o continua at� ter uma posi��o em que n�o
                     // tenha o valor 'X' ou 'O' ocupada.

  jogo[linha][coluna] = 'O'; // Adiciona 'O' em uma posi��o v�lida
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int **jogo; // Declara um ponteiro para ponteiros de inteiros

  jogo = malloc(3 * sizeof(int *)); // alocando espa�o para um array de 3 ponteiros de inteiros e atribuindo esse endere�o ao ponteiro jogo

  for (int i = 0; i < 3; i++)
  { // percorrer cada posi��o dos 3 ponteiros, e pra cada posi��o ser� alocado um espa�o para um inteiro.
    jogo[i] = malloc(3 * sizeof(int));
  }

  /*    Matriz Alocada:
         int* -> 1 2 3
         int* -> 4 5 6
         int* -> 7 8 9
 */

  int valores[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Atribuindo os inteiros do array valores na matriz alocada:
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i == 0 && j == 0)
      {
        jogo[0][0] = valores[0];
      }
      else if (i == 0 && j == 1)
      {
        jogo[0][1] = valores[1];
      }
      else if (i == 0 && j == 2)
      {
        jogo[0][2] = valores[2];
      }
      else if (i == 1 && j == 0)
      {
        jogo[1][0] = valores[3];
      }
      else if (i == 1 && j == 1)
      {
        jogo[1][1] = valores[4];
      }
      else if (i == 1 && j == 2)
      {
        jogo[1][2] = valores[5];
      }
      else if (i == 2 && j == 0)
      {
        jogo[2][0] = valores[6];
      }
      else if (i == 2 && j == 1)
      {
        jogo[2][1] = valores[7];
      }
      else if (i == 2 && j == 2)
      {
        jogo[2][2] = valores[8];
      }
    }
  }

  int local;

  int retornoDoPc = 0;
  int retornoDoUsuario = 0;
  int jogada = 0;

  srand(time(NULL)); // Gerador de n�meros aleat�rios para a jogada do computador

  printf("------> Jogo da Velha <------ \n");
  printfDoJogo(jogo);

  do
  {

    printf("Agora � a sua vez, digite a posi��o para X: ");
    scanf("%i", &local);

    while (local < 1 || local > 9)
    {
      printf("Essa posi��o n�o existe no Jogo, tente de novo: ");
      scanf("%i", &local);
    }

    int linha, coluna, iniciarComZero;
    iniciarComZero = local - 1; // 0 � 8.
    /*
      0 1 2
      3 4 5
      6 7 8
    */
    // primeirra linha
    if (iniciarComZero == 0)
    {
      linha = 0;
      coluna = 0;
    }
    else if (iniciarComZero == 1)
    {
      linha = 0;
      coluna = 1;
    }
    else if (iniciarComZero == 2)
    {
      linha = 0;
      coluna = 2;
    }
    // segunda linha
    else if (iniciarComZero == 3)
    {
      linha = 1;
      coluna = 0;
    }
    else if (iniciarComZero == 4)
    {
      linha = 1;
      coluna = 1;
    }
    else if (iniciarComZero == 5)
    {
      linha = 1;
      coluna = 2;
    }
    // terceira linha
    else if (iniciarComZero == 6)
    {
      linha = 2;
      coluna = 0;
    }
    else if (iniciarComZero == 7)
    {
      linha = 2;
      coluna = 1;
    }
    else if (iniciarComZero == 8)
    {
      linha = 2;
      coluna = 2;
    }

    int *ptr = &jogo[linha][coluna];

    if (*ptr == 'X' || *ptr == 'O')
    {
      printf("Essa posi��o j� est� ocupada.\n");
      continue;
    }

    *ptr = 'X';

    retornoDoUsuario = logica(jogo, *ptr);
    printfDoJogo(jogo);

    if (retornoDoUsuario == 1)
    {
      printf("Voc� venceu! Parab�ns!\n");
      break;
    }

    jogada++;

    if (jogada == 9)
    {
      printf("Deu empate!\n");
      break;
    }

    printf(">> A Jogada do PC <<\n");

    Computador(jogo);
    retornoDoPc = logica(jogo, 'O');
    printfDoJogo(jogo);

    if (retornoDoPc == 1)
    {
      printf("O computador venceu!\n");
      break;
    }

    jogada++;

  } while (jogada < 9);

  // Liberar a mem�ria alocada
  for (int i = 0; i < 3; i++)
  {
    free(jogo[i]);
  }
  free(jogo);

  return 0;
}

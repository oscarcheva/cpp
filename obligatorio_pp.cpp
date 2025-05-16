#include <stdio.h>
#include <cstdlib>
#include <ctime>

void generarCopas(char &copa1, char &copa2, char &copa3, int valor)
{
    if (valor == 1)
    {
        copa1 = '.';
        copa2 = '0';
        copa3 = '0';
    }
    else if (valor == 2)
    {
        copa1 = '0';
        copa2 = '.';
        copa3 = '0';
    }
    else
    {
        copa1 = '0';
        copa2 = '0';
        copa3 = '.';
    }
}

void jugar(char &copa1, char &copa2, char &copa3, int valor)
{

    generarCopas(copa1, copa2, copa3, valor);
}

void estafar(char &copa1, char &copa2, char &copa3, int seleccion, int valor)
{

    if (seleccion == 3)
        valor = 1;
    else
        valor += 1;
    generarCopas(copa1, copa2, copa3, valor);
}

void modificarSaldo(int &saldo, int &apuesta, bool gano)
{
    if (gano)
        saldo += apuesta;
    else
        saldo -= apuesta;

    printf("Saldo: %d", saldo);
}

bool verificarResultado(char copa)
{
    if (copa == '.')
        return true;

    return false;
}

int main()
{

    const int MAX_MONTO = 1000;
    const int MIN_APUESTA = 50;
    int saldo;
    int apuesta;
    int seleccion;
    char copa1;
    char copa2;
    char copa3;
    bool acierto = false;
    int ganadas = 0;
    int valorAleatorio;

    printf("Bienvenido/a, a continuación comenzaremos a jugar.\nPara cada jugada debes indicar con un '1', '2', o '3', en qué copa se encuentra la bola.\nRecuerda que también puedes optar por retirarte indicándolo con un '4'. \nAhora dime, cuanto dinero tienes disponible? \n");

    scanf("%d", &saldo);

    if (saldo < MIN_APUESTA || MAX_MONTO > 1000)
        printf("El saldo inicial debe ser igual o mayor a 50 y menor o igual a 1000");
    else
    {
        printf("\nO O O");
        printf("\n1 2 3 \n");
        printf("\nCopa?: ");

        scanf("%d", &seleccion);

        while (seleccion != 4 && saldo > MIN_APUESTA)
        {
            valorAleatorio = rand() % 3 + 1;

            apuesta = 0;
            while (apuesta < MIN_APUESTA || apuesta > saldo)
            {
                printf("Apuesta?: ");
                scanf("%d", &apuesta);
                if (apuesta < MIN_APUESTA)
                    printf("Para jugar hay que pagar amigo \n");

                else if (apuesta > saldo)
                    printf("No puedes apostar mas de tu saldo \n");
            }

            if (ganadas == 2)
            {
                acierto = false;
                estafar(copa1, copa2, copa3, seleccion, valorAleatorio);
            }
            else
            {

                jugar(copa1, copa2, copa3, valorAleatorio);

                switch (seleccion)
                {
                case 1:
                    acierto = verificarResultado(copa1);
                    break;
                case 2:
                    acierto = verificarResultado(copa2);
                    break;
                case 3:
                    acierto = verificarResultado(copa3);
                    break;
                }
            }

            printf("\n %c %c %c \n", copa1, copa2, copa3);

            if (acierto)
            {
                printf("\nHa acertado ");
                ganadas++;
            }
            else
            {
                printf("\nNo ha acertado ");
                ganadas = 0;
            }

            modificarSaldo(saldo, apuesta, acierto);

            printf("\n");

            if (saldo < MIN_APUESTA)
                printf("Para jugar hay que pagar amigo \n");
            else
            {
                printf("\nO O O");
                printf("\n1 2 3 \n");
                printf("\nCopa?: ");

                scanf("%d", &seleccion);
            }
        }

        printf("Nos vemos a la proxima");
    }
}

#include <stdio.h>
#include <cstdlib>
#include <ctime>

void jugar(char &copa1, char &copa2, char &copa3)
{
    int valorAleatorio = rand() % 3 + 1;

    generarCopas(copa1, copa2, copa3, valorAleatorio);
}

void modificarSaldo(int &saldo, int &apuesta, bool gano)
{
    if (gano)
        saldo += apuesta;
    else
        saldo -= apuesta;
}

bool verificarResultado(char copa)
{
    if (copa == '.')
        return true;

    return false;
}

bool estafar(char &copa1, char &copa2, char &copa3, int seleccion)
{

    if (seleccion == 3)
        seleccion = 1;
    else
        seleccion += 1;
    generarCopas(copa1, copa2, copa3, seleccion);
}

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

int main()
{

    const int MAX_MONTO = 1000;
    const int MIN_APUESTA = 50;
    int saldo = 0;
    int apuesta = 0;
    int seleccion = 0;
    char copa1;
    char copa2;
    char copa3;
    bool acierto = false;
    int ganadas = 0;

    printf("Bienvenido/a, a continuación comenzaremos a jugar.\nPara cada jugada debes indicar con un '1', '2', o '3', en qué copa se encuentra la bola.\nRecuerda que también puedes optar por retirarte indicándolo con un '4'. \nAhora dime, cuanto dinero tienes disponible? \n");

    scanf("%d", &saldo);

    if (saldo < MIN_APUESTA || MAX_MONTO > 1000)
        printf("El saldo inicial debe ser igual o mayor a 50 y menor o igual a 1000");
    else
    {
        printf("O O O \n");
        printf("1 2 3 \n");
        printf("Copa?: ");

        scanf("%d", &seleccion);

        while (seleccion != 4)
        {

            printf("Apuesta?: ");
            scanf("%d", &apuesta);

            while(apuesta< MIN_APUESTA && apuesta>saldo)

{            if (apuesta < MIN_APUESTA)
                printf("Para jugar hay que pagar amigo \n");

            else if (apuesta > saldo)
                printf("No puedes apostar mas de tu saldo \n");}

            else
            {
                if (ganadas == 2)
                {
                    acierto = false;
                    estafar(copa1, copa2, copa3, seleccion);
                }
                else
                {
                    jugar(copa1, copa2, copa3);

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

                printf("\n %c %c %c", copa1, copa2, copa3);

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

                printf("Saldo: %d", saldo);

                printf("\n");

                printf("O O O \n");
                printf("1 2 3 \n");
                printf("Copa?: \n");
                scanf("%d", &seleccion);
            }
        }
        printf("Nos vemos a la proxima");
    }
}

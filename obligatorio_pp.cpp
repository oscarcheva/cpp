#include <stdio.h>
#include <cstdlib>
#include <ctime>

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
    bool seguirJugando = true;

    printf("Bienvenido/a, a continuación comenzaremos a jugar \n. Para cada jugada debes indicar con un '1', '2', o '3', en qué copa se encuentra la bola. Recuerda que también puedes optar por retirarte indicándolo con un '4' \n. Ahora dime, cuanto dinero tienes disponible? \n");

    scanf("%d", &saldo);
    if (saldo < MIN_APUESTA || MAX_MONTO > 1000)
        printf("El saldo inicial debe ser igual o mayor a 50 y menor o igual a 1000");
    else
    {
        printf("O O O \n 1 2 3 \n Copa?: ");
        scanf("%d", &seleccion);

        printf("\n Apuesta?: ");
        scanf("%d", &apuesta);

        if (apuesta < MIN_APUESTA || apuesta > saldo)
            printf("La apuesta debe estar comprendida entre %d y %d", MIN_APUESTA, saldo);
        else
        {
            while (seguirJugando)
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
            if (acierto)
                printf("\n Ha acertado ");
            else
                printf("\n No ha acertado ");
            
            printf("\n %c %c %c \n Saldo: %d ",copa1,copa2,copa3,saldo);
            


        }
    }
    return 0;
}

void jugar(char copa1, char copa2, char copa3)
{
    srand(time(NULL));

    int valorAleatorio = rand() % 2;

    if (valorAleatorio == 0)
    {
        copa1 = '0';
        valorAleatorio = rand() % 2;
        if (valorAleatorio == 0)
        {
            copa2 = '0';
            copa3 = '.';
        }
        else
        {
            copa2 = '.';
            copa3 = '0';
        }
    }
    else
    {
        copa1 = '.';
        copa2 = '0';
        copa3 = '0';
    }
}

int modificarSaldo(int saldo, int apuesta, bool gano)
{
    if (gano)
        return saldo += apuesta;
    return saldo -= apuesta
}

bool verificarResultado(char copa)
{
    if (copa == '.')
        return true;

    return false;
}
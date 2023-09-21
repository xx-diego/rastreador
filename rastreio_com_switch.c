#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main()

{
    int veiculo;
    char placa[9];
    int i;
    int num_barras = 10;

    printf("Selecione um dos veiculos pre-cadastrados:\n");
    printf("1 - Fiat Uno Way\n");
    printf("2 - Fiat Palio Atractive\n");
    printf("3 - Fiat Strada Adventure\n");
    printf("4 - Volkswagen Gol G5\n");
    printf("5 - Volkswagen Voyage G5\n");
    printf("6 - Honda XRE 300\n");
    printf("7 - Honda CG FAN 160\n");
    printf("8 - Honda CB Twister 250\n");
    printf(" \n");
    scanf("%d", &veiculo);

    sleep(1);

    for (i = 0; i < 110; i += 10)
    {
        printf("[");
        for (int j = 0; j < num_barras; j++)
        {
            if (j < i / 10)
            {
                printf("=");
            }
            else
            {
                printf(" ");
            }
        }
        printf("] %d%%", i);
        fflush(stdout);
        usleep(100000);
        printf("\r");
    }

    printf("\nCarregamento concluido!\n");

    switch (veiculo)
    {
    case 1:
        printf("Veiculo Fiat Uno Way foi localizado.\n");
        break;
    case 2:
        printf("Veiculo Fiat Palio Atractive foi localizado.\n");
        break;
    case 3:
        printf("Veiculo Fiat Strada Adventure foi localizado.\n");
        break;
    case 4:
        printf("Veiculo Volkswagen Gol G5 foi localizado.\n");
        break;
    case 5:
        printf("Veiculo Volkswagen Voyage G5 foi localizado.\n");
        break;
    case 6:
        printf("Veiculo Honda XRE 300 foi localizado.\n");
        break;
    case 7:
        printf("Veiculo Honda CG FAN 160 foi localizado.\n");
        break;
    case 8:
        printf("Veiculo Honda CB Twister 250 foi localizado.\n");
        break;
    default:
        printf("Opcao invalida.\n");
        return 1;
    }

    while (1)
    {
        printf("Insira a placa do veiculo:\n");
        scanf("%s", placa);

        if ((strlen(placa) == 7 || strlen(placa) == 8) &&
            (isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
             (isdigit(placa[3]) || isalpha(placa[3])) &&
             (isdigit(placa[4]) || isalpha(placa[4])) &&
             isdigit(placa[5]) &&
             isdigit(placa[6])) &&
            (strlen(placa) == 7 || (strlen(placa) == 8 && placa[7] == '-')))
        {
            printf("Placa no formato correto. Irei localizar o mesmo no Maps. Carregando as informacoes:\n");
            sleep(1);

            for (i = 0; i < 110; i += 10)
            {
                printf("[");
                for (int j = 0; j < num_barras; j++)
                {
                    if (j < i / 10)
                    {
                        printf("=");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("] %d%%", i);
                fflush(stdout);
                usleep(200000);
                printf("\r");
            }

            printf("\n Abrindo mapa \n");

                        sleep(2);

            int opcao = rand() % 8;
            char urls[8][200] = {
            "https://maps.app.goo.gl/J3kJQPtH1tiudXPf6",
            "https://maps.app.goo.gl/51G47rLSqDK8V5pN7",
            "https://maps.app.goo.gl/doTLVhD8kAScrqFg6",
            "https://maps.app.goo.gl/6j9sstbYR2k1KCWE8",
            "https://maps.app.goo.gl/NJfndQ8Xhn6iYvfj7",
            "https://maps.app.goo.gl/DyvGwLBVMGjf6ovf7",
            "https://maps.app.goo.gl/tXurdYrpamjzaw4W9",
            "https://maps.app.goo.gl/LGT3VSQRubYGzzen8",
        };

        if (opcao >= 0 && opcao < 8)
        {
            char command[255];
            sprintf(command, "start %s", urls[opcao]);
            system(command);
            break;
        }else{
            printf("Placa incorreta. Verifique se esta no formato ABC1234 ou ABC1A23. Tente novamente.\n");
        }
    }
}
}
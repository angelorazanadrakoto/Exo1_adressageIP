#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "exo1_ip.h"

int main()
{
    debug_ip();
    return 0;
}
/*--------------------------------------------------------------------------------*/
void debug_ip()
{
    number n1;
    int i, j, k, l;
    char IP[32];
    n1.nb=-1 , n1.nb2 = -1 , n1.nb3 = -1 , n1.nb4 = -1;
    do
    {
        printf("IP: ");
        scanf("%s",IP);
        sscanf(IP , "%d.%d.%d.%d", &n1.nb, &n1.nb2, &n1.nb3, &n1.nb4);
    }
    while(n1.nb ==-1 || n1.nb2 == -1  ||n1.nb3 == -1  || n1.nb4 == -1);
    if(n1.nb2>255 || n1.nb3>255 || n1.nb4>255)
    {
        printf("\t______________________________\n");
        printf("\t|ADRESSE IP NON VALIDE!!!|\n");
        printf("\t------------------------------\n");
        exit(1);
    }
    calcule_binaire(n1);
    IPclass(n1);
    condition_msqr_reseau(n1);
    msqr_broadcast(n1);
    nombre_machine(n1);
}
/*--------------------------------------------------------------------------------*/
void calcule_binaire(number n1)
{
    int i, j, k, l;
// Calcul en binaire
    for(i=0 ; n1.nb>0 ; i++)
    {
        n1.bin[i]=n1.nb%2;
        n1.nb=n1.nb/2;
    }
    for(j=0 ; n1.nb2>0 ; j++)
    {
        n1.bin2[j]=n1.nb2%2;
        n1.nb2=n1.nb2/2;
    }
    for(k=0 ; n1.nb3>0 ; k++)
    {
        n1.bin3[k]=n1.nb3%2;
        n1.nb3=n1.nb3/2;
    }
    for(l=0 ; n1.nb4>0 ; l++)
    {
        n1.bin4[l]=n1.nb4%2;
        n1.nb4=n1.nb4/2;
    }
// Affichage du binaire
    printf("\t_______________________________\n");
    printf("\tAFFICHAGE EN BINAIRE !!!\n\t");
    for(i=i-1 ; i>=0 ; i--)
    {
        printf("%d", n1.bin[i]);
    }
    printf(".");
    for(j=j-1 ; j>=0 ; j--)
    {
        printf("%d", n1.bin2[j]);
    }
    printf(".");
    for(k=k-1 ; k>=0 ; k--)
    {
        printf("%d", n1.bin3[k]);
    }
    printf(".");
    for(l=l-1 ; l>=0 ; l--)
    {
        printf("%d", n1.bin4[l]);
    }
    printf("\n\t-------------------------------\n");
}
/*--------------------------------------------------------------------------------*/
void IPclass(number n1)
{
    if(n1.nb>=0 && n1.nb<128)
    {
        printf("\t_______________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE A|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=128 && n1.nb<192)
    {
        printf("\t_______________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE B|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=192 && n1.nb<224)
    {
        printf("\t_______________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE C|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=224 && n1.nb<240)
    {
        printf("\t_______________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE D|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=240 && n1.nb<256)
    {
        printf("\t______________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE E|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t------------------------------\n");
    }
    else if(n1.nb>255)
    {
        printf("\t______________________________\n");
        printf("\t|ADRESSE IP NON VALIDE!!!|\n");
        printf("\t------------------------------\n");
        exit(1);
    }
}
/*--------------------------------------------------------------------------------*/
void condition_msqr_reseau(number n1)
{
    int part1=255, part2=0;
    if(n1.nb>=0 && n1.nb<128)
    {
        printf("\t_______________________________\n");
        printf("\t\tMASQUE SOUS-RESEAU DE CLASSE A\n");
        printf("\t\t|%d.%d.%d.%d|\n", part1, part2, part2, part2);
        printf("\t-------------------------------\n");
        printf("\t_______________________________\n");
        printf("\tADRESSE RESEAU: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, part2, part2, part2);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=128 && n1.nb<192)
    {
        printf("\t_______________________________\n");
        printf("\tMASQUE SOUS-RESEAU DE CLASSE B\n");
        printf("\t|%d.%d.%d.%d|\n", part1, part1, part2, part2);
        printf("\t-------------------------------\n");
        printf("\t_______________________________\n");
        printf("\tADRESSE RESEAU: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, n1.nb2, part2, part2);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=192 && n1.nb<224)
    {
        printf("\t_______________________________\n");
        printf("\tMASQUE SOUS-RESEAU DE CLASSE C\n");
        printf("\t|%d.%d.%d.%d|\n", part1, part1, part1, part2);
        printf("\t-------------------------------\n");
        printf("\t_______________________________\n");
        printf("\tADRESSE RESEAU: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, n1.nb2, n1.nb3, part2);
        printf("\t-------------------------------\n");
    }
}
void msqr_broadcast(number n1)
{
    int part1=255, part2=0;
    if(n1.nb>=0 && n1.nb<128)
    {
        printf("\t_______________________________\n");
        printf("\tADRESSE DE BROADCAST: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, part1, part1, part1);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=128 && n1.nb<192)
    {
        printf("\t_______________________________\n");
        printf("\tADRESSE DE BROADCAST: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, n1.nb2, part1, part1);
        printf("\t-------------------------------\n");
    }
    else if(n1.nb>=192 && n1.nb<224)
    {
        printf("\t_______________________________\n");
        printf("\tADRESSE DE BROADCAST: \n");
        printf("\t\t|%d.%d.%d.%d|\n", n1.nb, n1.nb2, n1.nb3, part1);
        printf("\t-------------------------------\n");
    }
}
void nombre_machine(number n1)
{
    int l;
    int nb_bit=0;
    int nb;
    int nb_machine;
    char mimi[20];
    for(l=0 ; n1.nb4>0 ; l++)
    {
        n1.bin4[l]=n1.nb4%2;
        n1.nb4=n1.nb4/2;
    }
    for(l=l-1 ; l>=0 ; l--)
    {
        nb=n1.bin4[l];
        do
        {
            n1.bin4[l]=n1.bin4[l]/10;
            nb_bit++;
        }
        while(n1.bin4[l]!=0);
    }
    //printf("\nle nombre de bit: %d\n", nb_bit);
    nb_machine=pow(2, nb_bit)-2;
    printf("\t_______________________________\n");
    printf("\t\t|NOMBRE DE MACHINE: %d|\n", nb_machine);
    printf("\t-------------------------------\n");
}
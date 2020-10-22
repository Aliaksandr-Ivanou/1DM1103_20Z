#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argv[1]==NULL)
        printf("Nie podano ani jednej liczby.\n");
    else
    {   
    float a1;
    a1=atof(argv[1]);
    printf("[%s] Kwadrat: %f\n",argv[0],a1*a1);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float v;
    float a1;
    float a2;
    a1=atof(argv[1]);
    a2=atof(argv[2]);
    v=a1+a2;
    if(argv[1]=="dodaj")
    {
        v=a1+a2;
    }
    if(argv[1]=="mnoz")
    {
        v=a1*a2;
    }
    else
    {
        printf("error!");
        exit("-1");
    }
    printf("%f\n",v);
}
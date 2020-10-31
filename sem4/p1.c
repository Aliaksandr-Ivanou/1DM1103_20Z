#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char napis[255];
    strncpy(napis, argv[1], 254);
    printf("%s (%ld)\n", napis, strlen(napis));

    return 0;
}
#include "zwolniej.h"

 void zwolniej(mat * mac)
 {
    free(mac->c);
    free(mac->r);
    free(mac->tab);
    free(mac);
 }
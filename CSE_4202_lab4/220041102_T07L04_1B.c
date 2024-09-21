#include <stdio.h>
#include <stdlib.h>

int main() {
    char bulb[9];
    scanf("%s",bulb);
    printf("%c",strtol(bulb,NULL,2));

    return 0;
}

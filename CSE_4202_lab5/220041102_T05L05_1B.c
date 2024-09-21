#include <stdio.h>

size_t StrToNum(const char *str){
    size_t xnp=5381;
    char c;
    while (c=*str++)xnp=xnp*33+c;
    
    return xnp;
}


int main(){
    char srt[10000];
    size_t number_str;
    scanf("%[^\n]s", srt);
    number_str = StrToNum(srt);
    printf("%lu", number_str);

    return 0;
}
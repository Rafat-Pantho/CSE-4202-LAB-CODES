#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int ui;

void swap(char *a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    char s[1025];
    scanf("%s",s);
    for(ui i=0;i<strlen(s)-1;i++){
        for(ui j=i+1;j<strlen(s);j++){
            if( ( isupper(s[i]) && isupper(s[j]) ) || (islower(s[i]) && islower(s[j]) ) ){
                if (s[i]>s[j]) swap(&s[i],&s[j]);
            }
        }
    }
    printf("%s",s);
}
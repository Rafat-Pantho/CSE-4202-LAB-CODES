#include <stdio.h>
#include <string.h>

int main(){
    char str1[9];
    char c;
    int n;

    scanf("%s", str1);
    getchar();
    scanf("%c %d", &c, &n);

    n=n%8;

    if(c=='L'){
        for (int i=n; i<8;i++)printf("%c", str1[i]);
        for (int i=0; i<n;i++)printf("%c", str1[i]);
        printf("\n");
    }

    if(c=='R'){
        for (int i=8-n; i<8;i++)printf("%c", str1[i]);
        for (int i=0; i<8-n;i++)printf("%c", str1[i]);
        printf("\n");
    }

    return 0;
}
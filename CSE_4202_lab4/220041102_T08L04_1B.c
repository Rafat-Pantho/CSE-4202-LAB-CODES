#include <stdio.h>
#include <string.h>

int main() {
    int n, count = 0;
    char pattern[4];

    scanf("%d %s", &n, pattern);

    for (int i = 0; i < n; i++) {
        char a,b,c;
        scanf(" %c%c%c", &a,&b,&c);
        if (pattern[0]==a && pattern[1]==b && pattern[2]==c)count++;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("%d\n", count);

    return 0;
}

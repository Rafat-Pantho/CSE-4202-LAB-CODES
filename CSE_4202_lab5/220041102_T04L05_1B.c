#include <stdio.h>

int main(){
    char str[10000],delimiter;
    int count=0;int i=0;
    scanf("%[^\n]s", str);
    getchar();
    scanf("%c", &delimiter);

    for(;str[i]!='\0';){

        if(str[i]==delimiter){
            printf("\n");
            while(str[i]==delimiter)i++;
            count++;
        }
        else{
            printf("%c",str[i]);
            i++;
        }
    }
    if(str[i]=='\0' && str[i-1]==delimiter) printf("%d",count);
    else printf("\n%d",count+1);

    return 0;
}
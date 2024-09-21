#include <stdio.h>
#include <string.h>

int main(){
    char str1[1025],str2[1025];
    scanf("%s %s",str1,str2);

    int i1=0,j1=0,k1=0;

    for(int i=0;str1[i]!='\0';i++){
        for(int j=0;str2[j]!='\0';j++){
            if(str1[i]==str2[j]){
                int k=0;
                for(;str1[i+k]!='\0'&& str2[j+k]!='\n'&& str1[i+k]==str2[j+k];k++);
                printf("\n");
                if (k>k1){
                    k1=k;
                    i1=i;
                    j1=j;
                }
                break;
            }
        }
    }

    for(int i=i1;i<i1+k1;i++)printf("%c",str1[i]);
    printf("\n");
    printf("%d %d",k1,i1);

    return 0;
}
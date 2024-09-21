#include <stdio.h>
#include <string.h>

void xorCrypt(char * str, char key){
    for (int i=0;str[i]!='\0';i++){
        str[i] = str[i] ^ key;
    }
}

int main() {
    char string_to_work[512],key;
    printf("Enter a Sentence: ");
    scanf("%[^\n]",string_to_work);
    printf("Enter a key: ");
    scanf(" %c",&key);
    xorCrypt(string_to_work,key);
    printf("\nEncrypted:  %s",string_to_work);
    xorCrypt(string_to_work,key);
    printf("\nDecrypted:  %s",string_to_work);

    return 0;
}

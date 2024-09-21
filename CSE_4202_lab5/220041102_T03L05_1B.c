#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPasswordStrong(const char *password){
    int length = strlen(password);
    int uppers=0,lowers=0,symbols=0,digits=0;
    for (int i=0;i< length;i++){
        if(isupper(password[i]))uppers=1;
        if(islower(password[i]))lowers=1;
        if(isdigit(password[i]))digits=1;
        if(password[i]=='!'||password[i]=='?'||password[i]=='$'||password[i]=='_')symbols=1;
        if(tolower(password[i])=='p'&&i+7<length){
            if(tolower(password[i+1])=='a' && tolower(password[i+2])=='s' && tolower(password[i+3])=='s' && tolower(password[i+4])=='w' && tolower(password[i+5])=='o' && tolower(password[i+6])=='r' && tolower(password[i+7])=='d'){
                return false;
            }
        }
    }
    return (uppers && lowers && symbols && digits)? true:false;
}

int main(){
    char str[10000];
    scanf("%[^\n]s", str);
    if(isPasswordStrong(str)) printf("Stronk\n");
    else printf("Bonk\n");

    return 0;
}
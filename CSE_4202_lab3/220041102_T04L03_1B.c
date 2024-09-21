#include <stdio.h>

int main(){
    int n,k, perticipants_can_perform=0;
    scanf("%d%d",&n,&k);
    int array1[n];
    for(int i=0;i<n;)scanf("%d",&array1[i++]);

    for(int i =0; i<n; i++){
        if(5-array1[i]>=k)perticipants_can_perform++;
    }

    printf("%d",perticipants_can_perform/3);

    return 0;
}
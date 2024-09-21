#include <stdio.h>

void swap(int *a1, int *a2){
    *a1=*a1^*a2;
    *a2=*a1^*a2;
    *a1=*a1^*a2;
}

int main(){
    int q1,q2;
    scanf("%d %d",&q1, &q2);
    swap(&q1,&q2);
    printf("%d %d",q1,q2);
    return 0;
}
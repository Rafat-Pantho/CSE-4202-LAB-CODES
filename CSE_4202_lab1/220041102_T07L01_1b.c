#include <stdio.h>

unsigned int round_of_pow2(unsigned int n){
    if(n==0) return 1;
    int count =0;
    n--;
    while(n>0){
        n>>=1;
        count++;
    }
    return 1<<count;
}

int absulate_value(int n){
    int temp = n >>31;
    return (temp+n)^temp;
}

unsigned int swap_adj_bits(unsigned int n){
    return ((n& 0xAAAAAAAA)>>1) | ((n& 0x55555555)<<1);
}

int logicalNot(int n){
    return (n >0||n<0 )? 0:1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int operation_no,num;
        scanf("%d %d",&operation_no,&num);
        switch (operation_no){
        case 1:
            printf("%u\n",round_of_pow2(num));
            break;
        case 2:
            printf("%d\n",absulate_value(num));
            break;
        case 3:
            printf("%u\n",swap_adj_bits(num));
            break;
        case 4:
            printf("%d\n",logicalNot(num));
            break;
        }
    }
    return 0;
}
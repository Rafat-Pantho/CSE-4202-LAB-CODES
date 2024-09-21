#include <stdio.h>
#include <stdlib.h>

#define initial_limit  1000
#define wh    while (1)


typedef long long int ll;
typedef unsigned int ui;

typedef struct dga{
    ui current_length;
    ui current_elem_num;
    ll *arr_dga;
}dga;

void array_INIT (dga **arr_ptr){
    dga *contegious = (dga*)malloc(sizeof(dga));
    contegious->current_length= initial_limit;
    contegious->current_elem_num = 0;
    contegious-> arr_dga= (ll*)malloc(sizeof(ll)*initial_limit);
    *arr_ptr = contegious;
}

void dynamicing (dga *container, ll elem){
    if(container->current_length== container->current_elem_num){
        ll *temp = container->arr_dga;
        container->current_length*=3;
        container->arr_dga= realloc(container->arr_dga,container->current_length*sizeof(ll));
        container->arr_dga=temp;
    }
    container->arr_dga[container->current_elem_num]=elem;
    container->current_elem_num++;
}

int main (){
    ll s;
    ll sum =-1;
    dga *arr_i;
    array_INIT(&arr_i);
    scanf("%lld",&s);

    wh{
        ll elem;
        scanf("%lld",&elem);
        if (elem<0) break;
        dynamicing(arr_i,elem);
    }

    ll i=0,j=0;
    for(;i<arr_i->current_elem_num;i++){
        sum = 0;
        for(j=i;arr_i->current_elem_num;j++){
            sum+=arr_i->arr_dga[j];
            if (sum==s)break;
            if (sum>s)break;
        }
        if (sum==s)break;
    }

    if(sum==s)printf("%lld %lld\n",i,j);
    else printf("-1\n");
    return 0;
}
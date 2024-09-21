#include <stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *array_to_be_sorted, int len_of_array){
    for(int i=0;i<len_of_array-1;i++){
        for(int j=i+1;j<len_of_array;j++){
            if(array_to_be_sorted[i]>=array_to_be_sorted[j])swap(&array_to_be_sorted[i],&array_to_be_sorted[j]);
        }
    }
}

int main(){
    int n,m, max_sum=0,min_sum=0;
    scanf("%d%d",&n,&m);
    int array1[n];
    for(int i=0;i<n;)scanf("%d",&array1[i++]);

    bubblesort(array1, n);

    for (int i =0; i<n-m;i++){
        min_sum+=array1[i];
        max_sum+=array1[n-i-1];
    }

    printf("%d\n",max_sum-min_sum);

    return 0;
}
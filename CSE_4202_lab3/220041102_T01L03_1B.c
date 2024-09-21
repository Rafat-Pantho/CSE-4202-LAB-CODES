#include <stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int  is_sorted(int *array_checking, int len_of_array){
    for(int i=0;i<len_of_array-1;i++){
        if(array_checking[i]>array_checking[i+1])return 0;
    }
    return 1;
}


void bubblesort(int *array_to_be_sorted, int len_of_array){
    for(int i=0;i<len_of_array-1;i++){
        for(int j=i+1;j<len_of_array;j++){
            if(array_to_be_sorted[i]>=array_to_be_sorted[j])swap(&array_to_be_sorted[i],&array_to_be_sorted[j]);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int array1[n];
    for(int i=0;i<n;)scanf("%d",&array1[i++]);

    if (is_sorted(array1,n))printf("Yes\n");
    else{
        printf("No\n");
        bubblesort(array1,n);
        for(int i=0;i<n;)printf("%d ",array1[i++]);
    }

    return 0;
}
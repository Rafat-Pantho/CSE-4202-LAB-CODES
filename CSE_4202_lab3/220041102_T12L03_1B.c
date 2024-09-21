#include <stdio.h>
#include <stdlib.h>
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
    int n;
    scanf("%d",&n);
    int array1[n],array2[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array1[i]);
        array2[i]=array1[i];
    }

    bubblesort(array1,n);
    
    int max_change=-1,changing_num=-1;

    for(int i=0;i<n;i++){
        for (int j=n-1;j>-1;j--){
            if(array1[i]==array2[j]){
                if(abs(j-i)>max_change){
                    max_change=abs(j-i);
                    changing_num=array2[j];
                }
            }
        }
    }

    printf("Max Change Amount: %d\nValue: %d\n",max_change,changing_num);

    return 0;
}
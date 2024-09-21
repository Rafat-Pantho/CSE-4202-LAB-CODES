#include <stdio.h>

void swaping(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSorting (int *arr1,int len_array){
    for (int i=0;i<len_array;i++){
        for(int j=i+1;j<len_array;j++){
            if (arr1[i]>arr1[j])swaping(&arr1[i],&arr1[j]);
        }
    }
}

int linear_search(int *arr1,int target, int len_array){
    for (int i=0;i<len_array;i++){
        if(arr1[i]==target) return i;
    }
    return -1;
}

int bin_search(int *arr, int target, int start, int end){
    if(start>end) return -1;
    int mid=(start+end)/2;
    if(arr[mid]==target) return mid;
    else if (arr[mid]>target) return bin_search(arr,target,start,mid-1);
    else if (arr[mid]<target) return bin_search(arr,target,mid+1,end);
}

int main(){
    int arr_len, target_num;
    scanf("%d %d", &arr_len, &target_num);
    int arr1[arr_len];
    for (int i=0;i<arr_len;)scanf("%d",&arr1[i++]);
    bubbleSorting(arr1, arr_len);
    if (linear_search(arr1, target_num, arr_len)!=-1) printf("Found\n");
    else printf("Not Found\n");
    if (bin_search(arr1,target_num,0,arr_len)!=-1) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
#include <stdio.h>

void swaping_float(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

void swaping_int(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSorting (int *arr1, float *arr2,int len_array){
    for (int i=0;i<len_array;i++){
        for(int j=i+1;j<len_array;j++){
            if (arr2[i]>arr2[j]){
                swaping_float(&arr2[i],&arr2[j]);
                swaping_int(&arr1[i],&arr1[j]);
            }
        }
    }
}

int lowerbound(float *arr,int n,float target){
    int left =0,right = n-1,index=-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]>=target){
            index=mid;
            right=mid-1;
        }
        else left = mid+1;
    }
    return index;
}

int higherbound(float *arr,int n,float target){
    int left =0,right = n-1,index=-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]<=target){
            index=mid;
            left=mid+1;
        }
        else right = mid-1;
    }
    return index;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    float arr2[n],lcgpa,hcgpa;

    for(int i=0;i<n;i++)scanf("%d %f",&arr[i],&arr2[i]);
    bubbleSorting(arr,arr2,n);

    scanf("%f %f",&lcgpa,&hcgpa);

    int low=lowerbound(arr2,n,lcgpa),high=higherbound(arr2,n,hcgpa);
    if(low!=-1&&high!=-1){
        for(;low<=high;low++)printf("%d %g\n",arr[low],arr2[low]);
    }

    return 0;
}
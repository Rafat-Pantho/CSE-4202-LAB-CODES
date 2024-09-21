#include<stdio.h>
#include<string.h>
#include<math.h>

float squatring(float a){
    return a*a;
}

void swap_float(float *a, float *b){
    float temp = *a;
    *a=*b;
    *b=temp;
}

void string_swap(char *a, char *b){
    char temp[1000];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

void bubblesort_cities(char cities[][1000], float distance[][3], int len){
    for(int i= 0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(distance[i][2]>distance[j][2]){
                swap_float(&distance[i][0],&distance[j][0]);
                swap_float(&distance[i][1],&distance[j][1]);
                swap_float(&distance[i][2],&distance[j][2]);
                string_swap(cities[i],cities[j]);
            }
        }
    }
}

int searching_cities(float distance[][3], int len, float target_distance){
    int low =0,high=len-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(distance[mid][2]==target_distance) return mid;
        else if(distance[mid][2]<target_distance) low=mid+1;
        else high = mid-1;
    }
    return low+1;
}

int main(){
    int n;scanf("%d",&n);
    char city_name[n][1000];
    float x_and_y[n][3];
    for (int i=0;i<n;i++){
        scanf("%s %f%f",city_name[i],&x_and_y[i][0],&x_and_y[i][1]);
        x_and_y[i][2]=sqrt(squatring(x_and_y[0][0]-x_and_y[i][0])+squatring(x_and_y[0][1]-x_and_y[i][1]));
    }
    bubblesort_cities(city_name,x_and_y,n);
    int target_distance;scanf("%d",&target_distance);
    int index = searching_cities(x_and_y,n,target_distance);
    printf("%s %g\n",city_name[index],x_and_y[index][2]);

    return 0;
}
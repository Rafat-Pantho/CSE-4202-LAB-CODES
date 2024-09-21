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

int main(){
    int n;scanf("%d",&n);
    char city_name[n][1000];
    float x_and_y[n][3];
    for (int i=0;i<n;i++){
        scanf("%s %f%f",city_name[i],&x_and_y[i][0],&x_and_y[i][1]);
        x_and_y[i][2]=sqrt(squatring(x_and_y[0][0]-x_and_y[i][0])+squatring(x_and_y[0][1]-x_and_y[i][1]));
    }
    bubblesort_cities(city_name,x_and_y,n);
    for(int i=0;i<n;i++)printf("%s %g\n",city_name[i],x_and_y[i][2]);

    return 0;
}
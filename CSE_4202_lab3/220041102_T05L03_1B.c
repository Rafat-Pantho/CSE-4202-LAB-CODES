#include <stdio.h>
#include <string.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void exchange_string(char *a, char *b){
    char temp[100];
    strcpy(temp, a);
    strcpy(a,b);
    strcpy(b,temp);
}

void bubble_sort(char array_names_to_be[][100], int array_marks[][4], int num_of_students){
    for(int i=0;i<num_of_students-1;i++){
        for(int j =i+1;j<num_of_students;j++){
            if (array_marks[i][3] < array_marks[j][3] ||
                (array_marks[i][3] == array_marks[j][3] && array_marks[i][2] < array_marks[j][2]) ||
                (array_marks[i][3] == array_marks[j][3] && array_marks[i][2] == array_marks[j][2] && array_marks[i][0] < array_marks[j][0]) ||
                (array_marks[i][3] == array_marks[j][3] && array_marks[i][2] == array_marks[j][2] && array_marks[i][0] == array_marks[j][0] && array_marks[i][1] < array_marks[j][1])){
                swap(&array_marks[i][0], &array_marks[j][0]);
                swap(&array_marks[i][1], &array_marks[j][1]);
                swap(&array_marks[i][2], &array_marks[j][2]);
                swap(&array_marks[i][3], &array_marks[j][3]);
                exchange_string(array_names_to_be[i], array_names_to_be[j]);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char array_name[n][100];
    int num_array[n][4];
    for(int i=0;i<n;i++){
        scanf("%s %d%d%d",&array_name[i],&num_array[i][0],&num_array[i][1],&num_array[i][2]);
        num_array[i][3]=num_array[i][0]+num_array[i][1]+num_array[i][2];
    }

    bubble_sort(array_name,num_array,n);
    for(int i=0;i<n;i++)printf("%d %s\n",i+1,array_name[i]);

    return 0;
}
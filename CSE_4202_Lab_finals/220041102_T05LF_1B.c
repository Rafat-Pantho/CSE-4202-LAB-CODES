#include <stdio.h>

float highest_sum( float a, float b, float c, float d){
    float sum_1 = a+b+c;
    float sum_2 = a+c+d;
    float sum_3 = b+c+d;
    float sum_4 = a+b+d;
    if (sum_1 < sum_2) sum_1 =sum_2;
    if (sum_1 < sum_3) sum_1 =sum_3;
    if (sum_1 < sum_4) sum_1 =sum_4;
    return sum_1;
}

int main(){
    FILE *inputFile = fopen("marksheet.csv","rb");
    FILE *outputFIle = fopen("gradesheet.csv","wb");

    char studentName[201][16]
    float marks[200][8];
    char grade[201];

    while(!feof(inputFile)){
        fscanf(inputFile,"%s,%f,%f,%f,%f,%f,%f,%f/n",studentName[i],marks[i][0],marks[i][1],marks[i][2],marks[i][3],marks[i][4],marks[i][5],marks[i][6]);
    }
    fclose(inputFile);

    for(int i=0;i<200;i++){
        marks[i][7]=marks[i][0]/10+float(marks[i][1]+marks[i][2]+marks[i][3]+marks[i][4])/3+marks[i][5]/3+marks[i][6]/3;

        if(marks[i][7]>=80) grade[i]='A';
        else if(marks[i][7]>=70) grade[i]='B';
        else if(marks[i][7]>=60) grade[i]='C';
        else if(marks[i][7]>=50) grade[i]='D';
        else grade [i]='F';
    }



    return 0;
}
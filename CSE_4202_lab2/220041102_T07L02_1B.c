#include <stdio.h>
#include <string.h>

int binarySearchFirstT(char happening_of_alarm[], int low, int high) {
    int pos =-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (happening_of_alarm[mid] == 'T') {
            pos=mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return pos;
}

int main() {
    int time_total;
    scanf("%d", &time_total);
    char happening_of_alarm[(time_total / 10) + 2];
    

    for (int i = 0; i < (time_total / 10) + 1;)scanf(" %c", &happening_of_alarm[i++]);
    happening_of_alarm[(time_total / 10) + 1] = '\0';

    int index = binarySearchFirstT(happening_of_alarm, 0, (time_total / 10) + 1);

    if (index <= (time_total / 10)&& index!=-1) printf("Alarm turned on after %d minutes.\n", index*10);
    else printf("The alarm never turned on.\n");

    return 0;
}

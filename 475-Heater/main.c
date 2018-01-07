#include<stdio.h>
#include <stdlib.h>
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    unsigned int *dis_arr = malloc(housesSize * sizeof(unsigned int));
    int i = 0, j = 0;
    
    while (i < housesSize) {
        unsigned int min_dis = 0xffffffff;
        while (heaters[j] <= houses[i]) {
            j++;
        }
        min_dis = min(min_dis, abs(heaters[j] - houses[i]));
        if (j) min_dis = min(min_dis, abs(heaters[j-1] - houses[i]));
        dis_arr[i++] = min_dis;
    }
    int max_dis = dis_arr[0];
    for (i = 1; i< housesSize; ++i) {
        max_dis = max(max_dis, dis_arr[i]);
    }
    
    return max_dis;
}
int main(void) {
    int  houses[8] = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    int heaters[10] = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    int res = findRadius(houses, 4, heaters, 2);
    printf("%d\n", res); 
    return 0;
}

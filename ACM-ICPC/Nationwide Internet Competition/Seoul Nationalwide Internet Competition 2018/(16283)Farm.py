#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a; //양이 먹는 사료 양
int b; //염소가 먹는 사료 양
int n; //양과 염소의 개수
int w; //어제 소비한 사료 양
int sheep;
int i,j;
int goat;
int flag = 0;

int main(){
    scanf("%d %d %d %d", &a, &b, &n, &w);

    for(i = 1; i<n;i++){
        j = n - i;
        //printf("Sheep : %d, Goat : %d\n", i, j);

        if(w == i * a + j * b) {
            sheep = i;
            goat = j;
            flag ++;
        }
    }
    if (flag == 1) printf("%d %d\n", sheep, goat);
    else printf("-1");

}

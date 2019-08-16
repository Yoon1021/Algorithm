#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int k; //숫자 개수
int row = 0; //행(가로)
int col = 0; //열(세로)
int lotto[1000];
int flag[1000];
int fuck[1000][1000];
int i;
int j;
int z;
int length;
int temp;
int a;



int combination(int n, int r) {
    if (n == r) {
        for (i = 0; i < n; i++)
            flag[i] = 1;
        for (i = 0; i < length; i++)
            if (flag[i] == 1) {
                fuck[col][row] = lotto[i];
                row++;
            }

        for (i = 0; i < n; i++)
            flag[i] = 0;
        col ++;
        row = 0;
        return 0;
    }
    if(r==1){
        for(i=0;i<n;i++){
            flag[i] = 1;
            for(j=0;j<length;j++){
                if( flag[j] == 1 ) {
                    fuck[col][row] = lotto[j];
                    row++;
                }
            }
            flag[i] = 0;
            col ++;
            row = 0;
        }
        return 0;
    }

    flag[n - 1] = 1;
    combination(n - 1, r - 1);
    flag[n - 1] = 0;
    combination(n - 1, r);
}

void swap(int a){
    for(i=0;i<7;i++){
        temp = fuck[a][i];
        fuck[a][i] = fuck[a+1][i];
        fuck[a+1][i] = temp;
    }
}

void sort(){

    for (i = 0; i < 15; i++) {
        for (j = 0; j < col-1; j++) {
            //printf("%d %d \n", i, j);

            z = 0;

            while(fuck[j][z] == fuck[j+1][z]) {
                //printf("A\n");
                z++;
                if (z == 5) break;
                if (fuck[j][z] > fuck[j+1][z]){
                    a = j;
                    swap(a);
                    //printf("Swap Here %d %d \n", j, z);
                }

            }

            if(fuck[j][z] > fuck[j+1][z]){
                a = j;
                swap(a);
                //printf("Swap Here %d %d \n", j, z);

            }
        }
    }
}

int main()
{
    while (1) {



        scanf("%d", &k);
        if (k == 0) break;

        for (i = 0; i < k; i++)
            scanf("%d", &lotto[i]);



        length = k;


        row = 0;
        col = 0;

        combination(k, 6);

        sort();

        for (i = 0; i < col; i++) {
            for (j = 0; j < 6; j++) {
                printf("%d ", fuck[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#define N (6)                                       //集合の数

int max=0;
int sum=0;

void Print(int *array){
    for(int i=0;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void search(int *array, int size){
    int i, j, k;
    int work[N];                                    //作業用配列

    if(size==0){                                    //残りの数字がない場合
        if(sum>max){                                //最大が更新される場合
            max=sum;
        }
        sum=0;
    }else{                                          //残りの数字がある場合
        for(i=0;i<size;i++){                        //順番に調べていく
            sum+=array[i];

            k=0;
            for(j=0;j<size;j++){
                if(j!=i-1 && j!=i && j!=i+1){       //隣合わない条件で最大を見つける
                    work[k++]=array[j];
                }
            }
            search(work, k);                        //再帰
        }
    }
}

int main(void){
    int array[]={3,5,7,6,2,4};                      //集合を代入

    Print(array);

    search(array, N);

    printf("隣合わないように最大合計値を探索\n\n");

    printf("max=%d\n", max);

    return 0;
}
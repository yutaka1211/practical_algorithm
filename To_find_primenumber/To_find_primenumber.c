#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N (100)                                     //計算したい素数の数
#define M (100)                                     //表示したい素数の数

int main(void){
    int *sieve;
    int prime[N]={0};
    int i, j, index, number;

    sieve=(int *)malloc(sizeof(int)*N);             //N個のint型配列を作成

    for(i=0;i<N;i++){                               //N個の配列全てに1を格納
        sieve[i]=1;
    }

    sieve[0]=0;
    sieve[1]=0;                                     //0と1は素数ではないので0を代入

    for(i=2;i<sqrt(N);i++){                         //√Nまでの数を適応
        for(j=pow(i, 2);j<N;j+=i){                  //iの倍数は素数にならないので0を代入
             sieve[j]=0;
        }
    }

    index=0;
    for(i=2;i<N;i++){
        if(sieve[i]==1){ prime[index++]=i; }
    }

    printf("何番目の素数が欲しいですか？\n");
    scanf("%d", &number);

    printf("\n%d番目の素数は%d\n", number, prime[number-1]);

    free(sieve);

    return 0;
}
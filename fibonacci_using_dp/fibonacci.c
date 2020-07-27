#include <stdio.h>

int memo[10000]={0};

int fib(int n){
    if(n<=1){ return n;}
    if(memo[n]!=0){ return memo[n]; }

    return memo[n]=fib(n-1)+fib(n-2);
}

int main(void){
    int number;

    printf("何番目のフィボナッチ数が出力しますか？\n");
    scanf("%d", &number);

    printf("%d番目のフィボナッチ数は%dです\n", number, fib(number));

    return 0;
}
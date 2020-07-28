#include <stdio.h>

int count=0;

void Hanoi(int n, char *from, char *to, char *work){                        //fromが元ある場所、toが移動したい場所、workが3本目の場所

    if(n>=1){
        Hanoi(n-1, from, work, to);                                         //n-1本の円盤を3本目の場所に移動
        printf("%dを%sから%sへ\n", n, from, to);                             //移動の報告
        count++;
        Hanoi(n-1, work, to, from);                                         //n-1本の円盤を3本目の場所から、移動したい場所へ移動
    }
}

int main(void){

    int number;

    printf("何枚の円盤を想定していますか？\n");
    scanf("%d", &number);
    Hanoi(number, "A", "B", "C");

    printf("\n%d手かかります。\n", count);

    return 0;
}
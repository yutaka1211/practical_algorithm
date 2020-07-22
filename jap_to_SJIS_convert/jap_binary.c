#include <stdio.h>
#define N (1000)

void Jap_binary(int x, int *y){
    int a=0;
    int i, j;
    int array[N];                   //2進数を入れる箱

    while(x>0){
        array[a++]=(x%2);
        x/=2;
    }
    for(j=8-a;j>0;j--){ printf("0"); }
    for(i=a-1;i>=0;i--){
        printf("%d", array[i]);
        (*y)--;
    }
}

int main(void){

    int count1=0;                   //文字数を数える
    int count2;
    char jap[21];

    printf("20文字以下の日本語を入力\n");
    gets(jap);

    for(int i=0;jap[i]!='\0';i++){ count1++; }

    for(int i=0;i<count1;i++){
        count2=16;
        for(int j=0;j<2;j++){ Jap_binary(jap[i+j], &count2); }
        printf(" ");
    }

    return 0;
}
/*Windows開発プロンプトで可能*/
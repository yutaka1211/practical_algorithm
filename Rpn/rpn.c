#include <stdio.h>
#define N (100)

int top=0;                                      //現在のデータ格納場所について添字

/*プッシュ*/
void Push(int x, char *array){
    if(top==N){ printf("Overflow\n"); }         //添字が格納可能数と等しくなった場合
    else { array[top]=x; }                      //そうでなければ、スタックに数字を代入

    top+=1;                                     //添字を変更
}

/*ポップ*/
int Pop(char *array){
    if(top==-1){
        printf("Underflow\n");
        return 0;                               //添字が0以下となった場合
    }
    else {                                      //それ以外
        top-=1;                                 //添字を変更
        return array[top];                      //スタックに数字を代入
    }
}

int Rpn(char *equ){
    int i;
    int x, y;
    for(i=0;i<7;i++){                           //7文字入力
        if('0'<=*(equ+i) && *(equ+i)<='9'){ Push(*(equ+i)-48, equ); }
        else{
            y=Pop(equ);                         //ポップして格納
            x=Pop(equ);                         //ポップして格納
            switch(*(equ+i)){                   //次の演算子を判断
                case '+':
                    Push(x+y, equ);
                    break;
                case '-':
                    Push(x-y, equ);
                    break;
                case '*':
                    Push(x*y, equ);
                    break;
            }
        }
    }
    return Pop(equ);                            //最後の答えを出力
}

int main(void){

    char array[N];

    printf("input the number\n");
    for(int i=0;i<7;i++){
        scanf(" %c", &array[i]);                //文字入力
    }

    printf("output is %d\n", Rpn(array));       //文字出力

    return 0;
}
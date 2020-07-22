#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF (1000000000)
#define N (3)       //当てる桁数

int PC_array[N];    //PC側の4桁の値
int My_array[N];    //自分の4桁の値

/*EAT数、つまり数字と位置が合っている数を返す*/
int Eat_check(int *array, int *array_check){
    int sum=0;

    for(int i=0;i<N;i++){
        if(array[i]==array_check[i]){
            sum++;
            array_check[i]=INF;
        }
    }
    return sum;
}

/*BITE数、つまり位置は違うが数字は合っている数を返す*/
int Bite_check(int *array, int *array_check){
    int sum=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(array_check[i]==array[j]){ sum++; }
        }
    }
    return sum;
}


int main(void){
    int temp;           //重複無い4桁の生成に使用
    int sum=0;          //何回目の検索か示す為に使用
    int Eat;            //Eat数を格納
    int Bite;           //Bite数を格納
    int check_PC[N];    //PC側検索の4桁を格納
    int check_me[N];    //自分を検索される4桁を格納

    srand((unsigned)time(NULL));

    /*重複が無いようにな桁をPCが決める*/
    for(int i=0;i<N;i++){
        temp=rand()%10;
        int j=0;
        do{
            if(PC_array[j]==temp){
                temp=rand()%10;
            }else{ j++; };
        }while(j<i);

        PC_array[i]=temp;
    }

    printf("set your %d number\n", N);
    for(int i=0;i<N;i++){ scanf("%d", &My_array[i]); }     //自分の4桁決める

    do{
        /*自分のターン*/
        Eat=0;
        Bite=0;

        printf("\ninput check %d number:\n", N);            //PCの4桁を当てる
        for(int i=0;i<N;i++){ scanf("%d", &check_PC[i]); }

        printf("\nMy answer(%d): ", sum);                   //4桁の確認
        for(int i=0;i<N;i++){ printf("%d ", check_PC[i]); }
        printf("\n");

        Eat = Eat_check(PC_array, check_PC);                //Eat数のチェック
        Bite = Bite_check(PC_array, check_PC);              //Bite数のチェック

        printf("%d EAT\n", Eat);
        printf("%d BITE\n", Bite);
        if(Eat==N){                                         //もし4Eatなら勝ち
            printf("You Win\n");
            break;
        }


        printf("\n-------------------\n");

        /*PCのターン*/
        Eat=0;
        Bite=0;

        srand((unsigned)time(NULL));
        /*無作為なN桁の生成*/
        for(int i=0;i<N;i++){
            temp=rand()%10;
            int j=0;
            do{
                if(check_me[j]==temp){
                    temp=rand()%10;
                }else{ j++; }
            }while(j<i);
            check_me[i]=temp;
        }

        printf("PC answer(%d): ", sum++);                   //4桁の確認
        for(int i=0;i<N;i++){ printf("%d ", check_me[i]); }
        printf("\n");

        Eat = Eat_check(My_array, check_me);                //Eat数のチェック
        Bite = Bite_check(My_array, check_me);              //Bite数のチェック

        printf("%d EAT\n", Eat);
        printf("%d BITE\n", Bite);
        if(Eat==N){                                         //もし4Eatなら負け
            printf("You Lose\n");
            break;
        }
    }while(1);

    return 0;
}
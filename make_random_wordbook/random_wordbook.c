#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (602)                                                                     //英単語の行数
#define M (15)                                                                      //csvファイルの行数
#define L (2)                                                                       //csvファイルの列数

int main(void){
    int i, j, x;
    int k=0;
    int n=0;
    int add;
    FILE *fp1, *fp2, *fp3;
    char words[N][20];                                                              //英単語をいれる配列
    char tango[N][20];                                                              //日本語をいれる配列
    int a[N];
    int temp[N];

    fp1=fopen("example_word.txt", "r");                                             //英語と日本が書かれたファイルを開く
    if(fp1==NULL){                                                                  //ファイルがない場合
        printf("This file is not found.\n");
        return 0;
    }else{                                                                          //ファイルがある場合
        i=0;
        while(fscanf(fp1, "%s %s", words[i], tango[i])!=EOF){ i++; }                //単語ファイルから1行ずつ読み込む
    }
    fclose(fp1);

    fp2=fopen("word_qus.csv", "w");                                                 //問題のcsvファイルを作成
    fp3=fopen("word_ans.csv", "w");                                                 //解答のcsvファイルを作成

    srand((unsigned)time(NULL));                                                    //乱数作成
    for(i=0;i<M;i++){                                                               //M個、英単語をランダムに選択
        x=rand()%N;
        a[i]=x;
        temp[i]=x;
    }
    for(i=0;i<M;i++){
        add=0;
        for(j=0;j<i;j++){
            if(temp[j]!=a[i]){ add++; }                                             //英単語が既出でないか確認
        }
        if(add==j){                                                                 //英単語が既出でない場合
            fprintf(fp2, ",%d %s,", a[i]+1, words[a[i]]);                           //ファイルに出力
            fprintf(fp3, ",%d %s,", a[i]+1, tango[a[i]]);
            k++;
            if(k%L==0){                                                             //L列に表示するため
                fprintf(fp2, "\n\n");
                fprintf(fp3, "\n\n");
            }
        }
    }

    fclose(fp2);
    fclose(fp3);

    return 0;
}

//example_word.txtに「英単語　日本語」とする
//無作為に任意の英単語と日本語をcsvファイルとして出力
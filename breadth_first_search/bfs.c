#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int row, column;

char map[100][100];                                             //マップの大きさ
int reached[100][100];                                          //探索済かを判断する
int qx[2500], qy[2500];
int step[100][100];                                             //経路を格納
int head=0;
int tail=1;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void Bfs(int x, int y, int a, int b, char *map){
    int ax=a;
    int ay=b;
    int quex[2500]={0};
    int quey[2500]={0};
    int i, j, k, z;
    FILE *fp;

    reached[x][y]=1;                                            //初期値を1に格納
    qx[0]=x;                                                    //探索地点のx座標をキューに格納
    qy[0]=y;                                                    //探索地点のy座標をキューに格納
    step[x][y]=0;                                               //スタートからの最短手数を格納

    while(head!=tail){                                          //キューが正しく動作する場合
        int dequeu_x=qx[head];                                   //検索地点のx座標をデキュー
        int dequeu_y=qy[head];                                   //検索地点のy座標をデキュー
        head++;

        for(i=0;i<4;i++){
            int nx=dequeu_x+dx[i];                               //上下左右を移動
            int ny=dequeu_y+dy[i];
            if((nx>=0)&&(ny<column)){                            //移動した先が迷路の中であれば実行
                if((reached[nx][ny]==0)&&(map[nx][ny]=='.')){    //通路かつ検索していない場所である場合
                    reached[nx][ny]=1;                           //検索済として1を格納
                    qx[tail]=nx;                                 //移動先をエンキュー
                    qy[tail]=ny;
                    ax=nx;                                       //ゴール一歩手前の場所を格納
                    ay=ny;
                    step[nx][ny]=step[dequeu_x][dequeu_y]+1;     //最短経路を更新
                    tail++;                                      //キューの場所を更新
                }
            }
        }
    }
    quex[0]=ax;                                                 //ゴール一歩手前の場所を格納
    quey[0]=ay;
    j=1;

    while(step[ax][ay]>1){                                      //最短手数が1以上である場合
        for(i=0;i<4;i++){                                       //上下左右を確認
            int px=ax+dx[i];
            int py=ay+dy[i];
            if(step[px][py]==(step[ax][ay]-1)){                 //前後左右に最短手数-1の値がある場合
                ax=px;                                          //上下左右の適した場所を格納
                ay=py;
                quex[j]=ax;
                quey[j]=ay;
                j++;
            }
            if(step[ax][ay]==1){ break; }                       //スタート一歩先であれば終了
        }
    }

    /*ファイル操作*/
    fp=fopen(map, "w");
    fprintf(fp, "%d %d\n", y, x);
    for(k=(j-1);k>=0;k--){
        fprintf(fp, "%d %d\n", b, a);
        fclose(fp);
    }
}

int main(int argc, int *argv[]){
    FILE *fp;
    int i, j;
    int row_start, column_start;
    int row_goal, column_goal;

    if(argc!=3){
        printf("Usage: %s [target txt file] [outputfile] \n", argv[0]);
        return -1;
    }
    fp=fopen(argv[1], "r");
    if(fp==NULL){
        printf("cannot open %s\n", argv[1]);
        return -1;
    }
    fscanf(fp, "%d %d", &row, &column);
    i=0;
    while(fscanf(fp, "%s", &map[i])!=EOF){ i++; }
    fclose(fp);

    for(i=0;i<column;i++){
        for(j=0;j<row;j++){
            if(map[i][j]=='G'){
                column_goal=j;
                row_goal=i;
            }
        }
    }

    Bfs(column_start, row_start, column_goal, row_goal, argv[2]);

    return 0;
}
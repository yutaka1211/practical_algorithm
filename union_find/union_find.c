#include <stdio.h>
#define N_MAX (1000)                    //従業員の数

int p[N_MAX];

/*所属するトップの番号を返す*/
int Find(int x){
    if(p[x]==x){ return x; }            //自分がトップである場合
    else { return p[x]=Find(p[x]); }    //自分の上司が存在する場合
}


void Same(int x, int y){
    int n=Find(x);
    int m=Find(y);

    if(n==m){ printf("%d & %d are in the same organization.\n", x, y); }
    else { printf("%d & %d are in the different organization.\n", x, y); }
}

int main(void){
    FILE *fp;
    int n, i, j, sv;
    fp=fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    for(i=0;i<n;i++){ p[i]=i; }         //自分の番号を配列に格納
    while(fscanf(fp, "%d %d", &i, &j)!=EOF){ p[i]=sv; }

    fclose(fp);

    fp=fopen("pair.txt", "r");
    while(fscanf(fp, "%d %d", &i, &j)!=EOF){ Same(i, j); }
    return 0;
}

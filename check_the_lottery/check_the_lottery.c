#include <stdio.h>
#define MAXN (100)

void Swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Print(int *a){
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Sort(int a[], int b[], int t, int w){
    int tmp, i, j;
    for(i=t+1;i<=w;i++){
        for(j=t;j<=w-i;j++){
            if(a[j]>a[j+1]){
                Swap(&a[j], &a[j+1]);
                Swap(&b[j], &b[j+1]);
            }
        }
    }
}

int Search(int a[], int x, int n){
    int t, w, m;
    t=0;
    w=n-1;
    do{
        m=(t+w)/2;
        if(x<a[m]){ w=m-1; }
        else { t=m+1; }
    }while(t<=w);
    if(w>=0 && x==a[w]) { return w; }
    else { return -1; }
}

int main(void){
    int n, i, k;
    FILE *fp;
    int win[MAXN], grade[MAXN], lot;
    fp=fopen("win.txt", "r");
    fscanf(fp, "%d", &n);
    for(i=0;i<n;i++){ fscanf(fp, "%d %d", &win[i], &grade[i]); }
    fclose(fp);

    Sort(win, grade, 0, n-1);

    fp=fopen("lots.txt", "r");
    while(fscanf(fp, "%d", &lot)!=EOF){
        if((k=Search(win, lot, n
        ))!=-1){
            printf("winning number: %4d, grade: %d\n", lot, grade[k]);
        }
    }
    fclose(fp);
    return 0;
}
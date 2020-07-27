#include <stdio.h>
#include <stdlib.h>

int front=0;
int rear=0;

/*箱に格納*/
void Insert(int A[], int size, int d){
    int p, left, right, m, i;
    if(rear>size-1){
        printf("overflow ;\n");
    }

    p=-1;
    if(front==rear){ p=front; }
    else{
        left=front;
        right=rear-1;

        /*二分探索によって入れる場所を探す*/
        while(left<right){
            m=(left+right)/2;
            if(A[m]==d){
                p=m+1;
                break;
            }
            if(d<A[m]){
                right=m-1;
            }else{
                left=m+1;
            }
        }
        if(p==-1){                              //箱に値が入っている場合
            if(A[left]>d){
                p=left;
            }else{
                p=left+1;
            }
        }
    }
    i=rear;
    while(i>p){                                 //値を格納するために、他の値をずらす
        A[i]=A[i-1];
        i--;
    }
    A[p]=d;                                     //箱に値を格納
    rear++;
}

/*箱から消去*/
int Delete(int A[]){
    int x;
    if(front==rear){
        printf("Underflow\n");
    }
    x=A[front];
    front++;
    return x;
}

int main(void){
    int i;
    int A[20];
    int size=20;

    int a1[5]={ 10, 5, 20, 6 ,13};
    printf("a1: ");
    for(i=0;i<5;i++){
        printf("%3d ", a1[i]);
    }printf("\n");


    int a2[5]={2, 5, 18, 7, 5};
    printf("a2: ");
    for(i=0;i<5;i++){
        printf("%3d ", a2[i]);
    }printf("\n");

    for(i=0;i<5;i++) Insert(A, size, a1[i]);
    printf("\na1を箱に格納し、箱から昇順に3つ取り出す\n");
    for(i=0;i<3;i++) printf("%d ", Delete(A)); printf("\n");

    for(i=0;i<5;i++) Insert(A, size, a2[i]);
    printf("\na2を箱に格納し、箱から昇順に7つ取り出す\n");
    for(i=0;i<7;i++) printf("%d ", Delete(A)); printf("\n");

    return 0;
}
#include<stdio.h>

typedef int (*binaryOP)(int,int);

int sum(int a,int b){
    return a+b;
}

int diff(int a,int b){
    return a-b;
}

int main(){
    binaryOP fncarr[2];
    fncarr[0]=sum;
    fncarr[1]=diff;
    int a=2;
    int b=3;
    for(int i=0;i<2;i++){
        printf("result of function number %d is :%d\n",i+1,fncarr[i](a,b));
    }
    return 0;
}
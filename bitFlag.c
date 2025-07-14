#include<stdio.h>


typedef enum{
    FLAG_A=(1<<0),
    FLAG_B=(1<<1),
    FLAG_C=(1<<2)
} t_flag;

int demoFunc(int a,t_flag flag){
    // unset a flag
    // flag=(flag & ~FLAG_C);
    int result=a;
    if(flag & FLAG_A){
        result=result+a;
    }
    if(flag & FLAG_B){
        result=result*a;
    }
    if(flag & FLAG_C){
        result=result*result;
    }
    return result;
}

int main(){
    int a=3;
    // single flag
    printf("addition with itself: %d\n",demoFunc(a,FLAG_A));
    // 2 flags
    printf("addition with itself followed by multiplication: %d",demoFunc(a,FLAG_A | FLAG_B));
    return 0;
}
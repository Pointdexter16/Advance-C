#include <stdio.h>
#include <stdarg.h>

int sum_all(int count,...){
    va_list ap;
    va_start(ap,count);
    int sum=0;
    for(int i=0;i<count;i++){
        int x=va_arg(ap, int);
        sum+=x;
    }
    va_end(ap);
    return sum;
}

int sum_all_new(int first,...){
    va_list ap;
    va_start(ap,first);
    int sum=first;
    int val;
    while((val=va_arg(ap,int))!=-1){ //this could be any number to terminate
        sum+=val;
    }
    return sum;
}

int main() {
    printf("%d\n",sum_all_new(1,2,3,4,-1));
    printf("%d",sum_all(3,2,3,4));
    return 0;
}
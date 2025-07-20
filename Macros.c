#include <stdio.h>

#define SUM_ALL(start,end){          \
    for(int i=(start);i<(end)+1;i++) \
        sum+=i; \
    printf("SUM:%d",sum);  \
} //to deal with redefinition of sum by making a scope

int main() {
    int sum=0;
    SUM_ALL(1, 4);
    return 0;
}
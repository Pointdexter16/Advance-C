#include<stdio.h>

enum foo{
    foo_a,
    foo_b,
    foo_c
};

static const int a[]={[foo_a]=1,
                      [foo_c]=2,
                      [foo_b]=3};

int main(){
    printf("%d",a[foo_c]);
    return 0;
}
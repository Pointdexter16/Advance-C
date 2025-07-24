#include <stdio.h>

struct vector{
    int x;
    int y;
};

int scalar_sum(int scalar,struct vector v){
    return scalar*v.x+scalar*v.y;
}

int sum_array(int a[],int len){
    int s=0;
    for(int i=0;i<len;i++){
        s+=a[i];
    }
    return s;
}

int main() {
    // struct vector v; //conventional way
    // v.x=2;
    // v.y=3;
    printf("%d\n",scalar_sum(4,(struct vector){2,3})); //you can directly pass the struct to same space and embed it
    printf("%d",sum_array((int []){1,2,3},3)); //you can directly pass the struct to same space and embed it
    int *xs=(int []){3,4,5}; //this also works
    return 0;
}
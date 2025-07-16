#include<stdio.h>
#include<stdint.h>

int memSet(void *d, char c, size_t n){
    unsigned int iterations=n/sizeof(char);
    for(int i=0;i<iterations;i++){
        *((char *)d+i)=c;
    }
    return 1;
}

int memCopy(void *d,void *scr,size_t n){
    unsigned int iterations=n/sizeof(char);
    for(int i=0;i<iterations;i++){
        *((char *)d+i)=*((char *)scr+i);
    }
    return 1;
}

int main(){
    float b[7]={43.3,12.45,53.35,53.53,31.23,34.67,2.3};
    float k[7];
    printf("%f %f\n",b[4],k[4]);
    memCopy(k,b,sizeof(b));
    printf("%f %f\n",b[4],k[4]);
    return 0;
}
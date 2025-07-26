#include <stdio.h>
// micro example
#define SUM_ALL(start,end){          \
    for(int i=(start);i<(end)+1;i++) \
        sum+=i; \
    printf("SUM:%d",sum);  \
} //to deal with redefinition of sum by making a scope


// micro stringify example

#define Sum(x,y) printf("%s + %s = %d",#x,#y,(x)+(y));

// micro tokenize and generic function generation example

#define varGen(var) new_##var

#define genericMultiplier(type) \
    type multi_##type(type x,type y){ \
        return x*y;                 \
    }

genericMultiplier(int);
genericMultiplier(float);
genericMultiplier(long);

int main() {
    int sum=0;
    SUM_ALL(1, 4);
    printf("\n");
    Sum(1, 4);
    printf("\n");
    int varGen(Del) = 23;
    printf("%d",new_Del);
    printf("\n");
    printf("%d\n",multi_int(2,3));
    printf("%f\n",multi_float(2.43,3.345));
    printf("%ld\n",multi_long(2L,3L));
    return 0;
}
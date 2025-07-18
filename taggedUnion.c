#include<stdio.h>
#include<stdbool.h>

enum tag{
    TAG_BOOL,
    TAG_INT,
    TAG_FLOAT
};

struct dynamic{
    enum tag Tag;
    union {
        bool b;
        int i;
        float f;
    };  //In gcc this works with out explicitly typing the name of the union so instead of (struct dynamic instance).value.i 
};      //you can directly write (struct dynamic instance).i 

int main(){
    struct dynamic d;
    d.Tag=TAG_BOOL;
    d.b=true;
    d.Tag=TAG_INT;
    d.i=34;
    d.Tag=TAG_FLOAT;
    d.f=34.43;
    switch(d.Tag){
        case TAG_BOOL: printf("bool: %d",d.b);break;
        case TAG_INT: printf("int: %d",d.i);break;
        case TAG_FLOAT: printf("float: %f",d.f);break;
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char *literal="My name is demolator";
    char *s=strdup(literal);
    char arr[]="Hello there";
    //literal[0]=4; won't work as literal is pointing to a 
    //read only memory which is not mutable 
    //but strdup allocates a memory on heap which is mutable
    s[0]='4';
    printf("%s\n",s);
    printf("%s",arr);
    return 0;
}
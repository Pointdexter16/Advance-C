#include<stdio.h>
#include <sys/fcntl.h>
#include<unistd.h>
#include<fcntl.h>

// Wrote to a file in binary format, then read it using bit-fields — a practical demo.
// This is just for demonstration purposes, because this will not always work,
// as padding depends on the compiler when using bit-fields.
// It will work if you use the same struct to write to and read from the file stream,
// since the padding will match.
// But the approach here is different — the data is written individually as [int][char],
// and it just happens to work in this example.
struct demo{
    int ffield: 32;
    char sfield : 8;   
};
int main(){
    int a=1;
    char b='A';
    // int A;
    // char B;
    int fd = open("data.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd==-1){
        perror("failed to open the file");
        return 1;
    }
    write(fd,&a,sizeof a);
    close(fd);
    fd = open("data.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
    if(fd==-1){
        perror("failed to open the file");
        return 1;
    }
    write(fd,&b,sizeof b);
    close(fd);
    fd = open("data.txt",O_RDONLY);
    if(fd==-1){
        perror("failed to read the file");
        return 1;
    }
    // read(fd,&A,sizeof(int));
    // read(fd,&B,sizeof(char));
    // read(fd,&C,sizeof(double));
    // printf("%d\n",A);
    // printf("%c\n",B);
    //* using struct with bit field to get the whole thing as a chuck
    struct demo d;
    read(fd,&d,sizeof d);
    printf("%d\n",d.ffield);
    printf("%c\n",d.sfield);
    return 0;
}
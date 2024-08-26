#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

# define BUFFER_SIZE 30

int main(){
int fd=open("./test.txt",O_RDWR);

if(fd ==-1){

    printf("FAILED TO OPEN !!");
    exit(0);
}

int n;
char buffer[BUFFER_SIZE];

printf("Reading first 10 characters from file :\n");
n=read(fd,buffer,10);
write(1,buffer,n);
printf("\n");

printf("Skipping 5 characters from current position in the file :\n");
lseek(fd,5,SEEK_CUR);
n=read(fd,buffer,10);
write(1,buffer,n);
printf("\n");

printf("Going to 5th last character in the file :\n");
lseek(fd,-5,SEEK_END);
n=read(fd,buffer,5);
write(1,buffer,n);
printf("\n");

printf("Going to the 3rd character in the file :\n");
lseek(fd,3,SEEK_SET);
n=read(fd,buffer,5);
write(1,buffer,n);
printf("\n");

return 0;
}
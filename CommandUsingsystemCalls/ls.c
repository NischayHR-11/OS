#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char *argv[]){

    if(argc<2){

        printf("directory is Not Enetered!1!\n");
        exit(0);
    }

    DIR *dir= opendir(argv[1]);

    if(dir==NULL){

        printf("CANNOT OPEN DIRECTORY !!\n");
        exit(0);
    }

    struct dirent *direntry;

    while((direntry=readdir(dir))!=NULL){

        printf("%s\n",direntry->d_name);
    }
}
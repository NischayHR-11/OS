#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){

    FILE *f1,*f2;

    if(argc<3){

        printf("INSUFFICIENT ARGUMENTS !!\n");
        exit(0);
    }

    f1=fopen(argv[1],"a");
    f2=fopen(argv[2],"r");

    if(f2==NULL){

        printf("CANNOT OPEN FILE !!\n");
        exit(0);
    }

    char ch;
    
    while((ch=fgetc(f2))!=EOF){

        fprintf(f1,"%c",ch);
    }

    fclose(f1);
    fclose(f2);
}
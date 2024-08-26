#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char file[100],pattern[100],temp[200];

    printf("ENTER THE FILE NAME : \n");
    scanf("%s",file);
    printf("ENTER THE PATTER : \n");
    scanf("%s",pattern);

    FILE *f1=fopen(file,"r");

    if(f1==NULL){

        printf("CANNOT OPEN FILE \n");
        exit(0);
    }

    while((fgets(temp,sizeof(temp),f1))){

        if(strstr(temp,pattern)!=NULL){
            printf("%s",temp);
        }
    }

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void filecopy(FILE *ifp,FILE *ofp){
    int c;
    while ((c=fgetc(ifp))!=EOF){fputc(c,ofp);}
}

int main(int argc,char *argv[]){
    FILE *ifp,*ofp;
    char *name =argv[0];
    if(argc==1){
        printf("put in the name of the file you want to copy!\n"); 
    }
        if((ifp=fopen(*++argv,"r+"))==NULL){
            printf("Emmmmm, can't open input file:%s\n",*argv);
        }else if((ofp=fopen(*++argv,"w+"))==NULL){
            printf("Emmmmm, can't open output file:%s\n",*argv+1);
        }else {

            filecopy(ifp,ofp);
            fclose(ifp);fclose(ofp);
        }
    return 0;
}

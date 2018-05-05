#include<stdio.h>
void strcpy(char *in,char *out){
	for(int i=0;in[i-1]!='\0';i++){
		out[i]=in[i];
	}
}
int strcmp(char *one,char *two){
	int tig1=1,tig2=1;
	for(int i=0;tig1||tig2;i++){
		if(one[i]>two[i]){
			return 1;
		}else if(two[i]>one[i]){
			return -1;
		}
	}
	return 0;
}

int main(){
	return 0;
}

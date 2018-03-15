#include<stdio.h>

int main(){
	int row,cal;
	for(row=1;row<10;row++){
	for(cal=1;cal<10;cal++){
		printf("%d*%d=%d\t",row,cal,row*cal);
	}	printf("\n");	}
	return 0;
}

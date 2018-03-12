#include<stdio.h>
int main(){
	int score[5];
	int i=0,j;
	for(i=0;i<5;i++){
		scanf("%d",&score[i]);
	}
	for(i=0;i<5;i++){
		j=score[i];
		if(j>100||j<0){printf("Error\n");}
		else if(j>89){printf("A\n");}
		else if(j>79){printf("B\n");}
		else if(j>69){printf("C\n");}
		else if(j>59){printf("D\n");}
		else if(j>=0){printf("F\n");}
		else{printf("Error\n");}
	}
	return 0;
}

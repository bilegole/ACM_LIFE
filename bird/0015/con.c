#include<stdio.h>

char* dicide(int score){
	return (score>90)?"A":(
	(score>80)?"B":(
	(score>70)?"C":(
	(score>60)?"D":(
	"E"))));
}

int main(){
	int i;
	for(i=100;i>50;i-=3){
		printf("%d is %s\n",i,dicide(i));
	}
	return 0;
}
	

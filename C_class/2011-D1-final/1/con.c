#include<stdio.h>
#include<math.h>

int main(){
	int one,two;
	scanf("%d %d",&one,&two);
	if(one-two>=0){
		printf("%d %d\n",(int)sqrt(one+two),one-two);
	}else{
		printf("%d %d\n",-two-one,one-two);
	}
	return 0;
}

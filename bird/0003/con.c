#include<stdio.h>
#include<math.h>

int asqrt(int x){
	int i=0;
	while(i*i<=x){
		i++;
	}	return (i-1);
}

int mulx(int num,int x){
	int reg=(int)asqrt(num+x);
	if(reg*reg==(num+x)){return 1;}
	else {return 0;}
}

int main(){
	int i;
	for(i=-1000;i<1000;i++){
		//printf("is testing %d\n",i);
		if(mulx(i,100)&&mulx(i,268)){
			printf("The number is %d\n",i);
			//break;
		}
	}
	return 0;
}
	

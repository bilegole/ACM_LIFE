#include<stdio.h>

int main(){
	int x,y,z,num[3];
	int co,ra,di,po;
	scanf("%d %d %d",&num[0],&num[1],&num[2]);
	for(co=2;co>0;co--){
		for(di=0;di<co;di++){
			if(num[2-di]<num[1-di]){
				x=num[2-di];
				num[2-di]=num[1-di];
				num[1-di]=x;
			}
		}
	}
	printf("%d %d %d",num[0],num[1],num[2]);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Test{
	int stat[2];//type times
	struct Pro *pro;
	int cen;
};	

struct Pro{
	int num[3];
	int in;
};

int main(){
	int a,b;
	printf("type?times?\n");
	scanf("%d %d",&a,&b);
	struct Test *test=(struct Test*)calloc(1,sizeof(struct Test));
	test->stat[0]=a;
	test->stat[1]=b;
	test->cen=0;
	test->pro=(struct Pro*)calloc(test->stat[1],sizeof(struct Pro));
	for(int i=0;i<test->stat[1];i++){
		test->pro[i].num[0]=rand()%100;
		printf("%d\t",test->pro[i].num[0]);
		test->pro[i].num[1]=rand()%100;
		printf("%d\n",test->pro[i].num[1]);
		if(test->stat[0]==0){
			test->pro[i].num[2]=test->pro[i].num[0]+test->pro[i].num[1];
		}else if(test->stat[0]==1){
			test->pro[i].num[2]=test->pro[i].num[0]-test->pro[i].num[1];
		}else if(test->stat[0]==2){
			test->pro[i].num[2]=test->pro[i].num[0]*test->pro[i].num[1];
		}	
		int in;
		scanf("%d",&in);
		if(in==test->pro[i].num[2]){test->cen++;}
	}
	printf("You get %d points\n",test->cen);
	return 0;
}

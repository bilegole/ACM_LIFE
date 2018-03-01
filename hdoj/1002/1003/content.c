#include<stdio.h>
#include<string.h>

void turn(char *line){
	int i, j ,n ,m ;
	int len=strlen(line);
	char mid;
	for(i=0;i<len/2;i++){
		mid = line[i];
		line[i]=line[len-1-i];
		line[len-1-i]=mid;
	}
}

void sum(char *one ,char *two ,char*result){
	char ones[1001]={0},twos[1001]={0};
	memcpy(ones,one,strlen(one));
	memcpy(twos,two,strlen(two));
	turn(ones);turn(twos);
	int i,j,n,m,plus=0;
	for(i=0;(ones[i]||twos[i]||plus);i++){
		ones[i]=((ones[i]=='\0')?'0':ones[i]);
		twos[i]=((twos[i]=='\0')?'0':twos[i]);
		result[i]=ones[i]-'0'+twos[i]+plus;
		if(result[i]>'9'){
			result[i]-=10;
			plus=1;
		}else{plus=0;}
	}
	turn(result);
}

int main(){
	char one[1001]={0},two[1001]={0};
	char res[1000]={0};
	int times,i,j,n,m;
	scanf("%d",&times);
	for(i=0;i<times;i++){
		scanf("%s %s",one,two);
		sum(one,two,res);
		printf("Case %d:\n%s + %s = %s\n\n",i+1,one,two,res);
	}
	return 0;
}	

#include<stdio.h>

int main(){
	int hun,ten,one;
	for(hun=0;hun<10;hun++){
	for(ten=0;ten<10;ten++){
	for(one=0;one<10;one++){
		if((hun*100+ten*10+one)==(hun*hun*hun+ten*ten*ten+one*one*one)){
			printf("%d%d%d is a flower number;\n",hun,ten,one);
		}
	}}}
	return 0;
}

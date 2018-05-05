#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define num 10
struct MP3{
	struct Music *musics;
	int stat[4];//0:播放与否	1：音量		2：曲目id		3：电源
};

struct Music{
	char Title[10];
	int Duration;
	char artist[10];
};

void but(int bu,struct MP3 *mp3){	//0-开关	1-播放	2-停止	3-快进	4-快退	5-音量调节	6-显示歌曲属性
	switch(bu){
		case 0:
			if(mp3->stat[3]==0){
				mp3->stat[3]=1;
				printf("power on\n,waiting for cmd...\n");
			}else{
				mp3->stat[3]=0;
				printf("power off\n");
			}
			break;
		case 1:
			if(mp3->stat[3]==0){printf("........\n");break;}
			if(mp3->stat[0]==0){
				mp3->stat[0]=1;
				printf("Start playing:\nTitle: %s\nDuration: %d\nArtist: %s\n",mp3->musics[mp3->stat[2]].Title,mp3->musics[mp3->stat[2]].Duration,mp3->musics[mp3->stat[2]].artist);
			}else{
				printf("Is playing\n");
			}
			break;
		case 2:
			if(mp3->stat[3]==0){printf("........\n");break;}
			if(mp3->stat[0]==1){
				printf("Stop!");
				mp3->stat[0]=0;
			}else{
				printf("Isn't playing...\n");
			}
			break;
		case 3:
			if(mp3->stat[3]==0){printf("........\n");break;}
			mp3->stat[2]+=1;
			printf("Next:\nTitle: %s\nDuration: %d\nArtist: %s\n",mp3->musics[mp3->stat[2]].Title,mp3->musics[mp3->stat[2]].Duration,mp3->musics[mp3->stat[2]].artist);
			break;
		case 4:
			if(mp3->stat[3]==0){printf("........\n");break;}
			mp3->stat[2]-=1;
			printf("Last:\nTitle: %s\nDuration: %d\nArtist: %s\n",mp3->musics[mp3->stat[2]].Title,mp3->musics[mp3->stat[2]].Duration,mp3->musics[mp3->stat[2]].artist);
			break;
		case 5:
			if(mp3->stat[3]==0){printf("........\n");break;}
			if(mp3->stat[1]<90){
				mp3->stat[1]+=10;
			}else {mp3->stat[1]=0;}
			printf("Now the voice is %d\n",mp3->stat[1]);
			break;
		case 6:
			if(mp3->stat[3]==0){printf("........\n");break;}
			printf("Title: %s\nDuration: %d\nArtist: %s\n",mp3->musics[mp3->stat[2]].Title,mp3->musics[mp3->stat[2]].Duration,mp3->musics[mp3->stat[2]].artist);
			break;
		default:
			printf("you are pushing a button which doesn't exist!\n");
	}
}

int main(){
	struct MP3 *mp3=(struct MP3*)calloc(1,sizeof(struct MP3));
	mp3->musics=(struct Music*)calloc(num,sizeof(struct Music));
	mp3->stat[1]=50;
	mp3->stat[0]=0;
	mp3->stat[3]=0;
	int cmd;
	while(1){
		scanf("%d",&cmd);
		but(cmd,mp3);
	}
	return 0;	
}
	

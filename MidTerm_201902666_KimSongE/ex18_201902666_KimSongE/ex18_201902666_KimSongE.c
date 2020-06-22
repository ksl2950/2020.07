/*
프로그램명 : ex18_201902666_KimSongE
설명: 주어진 곡들을 보고 자신의 플레이리스트에 최대 5개까지 곡을 추가하는 프로그램 
작성일시 : 2020/05/31
작성자 :컴퓨터융합학부 201902666 김송이
*/

#include <stdio.h>//표준 입출력 라이브러리 
#define MAX 5 //최대 5개의 곡을 등록가능하므로 최대 곡 수를 매크로상수로 정의
#define STR_SIZE 20 //곡 제목, 아티스트 이름, 장르의 문자열 최대 크기를 매크로 상수로 정의

//곡에 대한 정보를 멤버로 구성하는 구조체 song
typedef struct song {
	char title[STR_SIZE];//곡 제목
	char artist[STR_SIZE];//아티스트 이름
	char genre[STR_SIZE];//곡 장르
	int playingTime;//곡 재생 시간 

}SONG;//구조체변수 SONG

int main(void) {
	//SONG 구조체 배열 arr[] 에 곡정보를 저장하고 있다.
	//왼쪽에서부터 곡제목,아티스트이름,곡 장르,곡재생시간 순으로 초기화 
	SONG arr[] = { { "thank u, next","Ariana Grande","pop",208 },
					{"Attention","Charile Puth","pop",211},
					{"별 보러 가자","박보검","balad",316},
					{"How Long","Charile Puth","pop",198},
					{"봄날","방탄소년단","hip-hop",274},
					{"아낙네","MINO","hip-hop",241},
					{"unlucky","아이유","rock-metal",232}
	}; // 총 7개의 곡정보를 가지고 있음

	int size = sizeof(arr) / sizeof(arr[0]);//구조체 배열의 크기를 size에 저장
	int songNum;//플레이리스트에 추가할 곡번호를 저장할 변수
	SONG* playList[MAX] = { NULL };//SONG 구조체 포인터 playList를 NULL로 초기화
	int count = 0;//플레이리스트에 들어있는 곡 개수를 세줄 변수
	int total = 0;//플레이리스트에 저장된 전체 곡 재생시간을 저장할 변수
	

		printf("   제목              아티스트          장르       재생시간\n");//출력할 모든 정보의 타이틀 출력
		for (int i = 0; i < size; i++) {//for문을 arr배열크기만큼 돌린다. 
			printf("%d: %-15s %-19s %-12s %-10d\n",
				i+1,arr[i].title, arr[i].artist, arr[i].genre, arr[i].playingTime);
		} //배열에 들어있는 전체 곡정보 출력 
		printf("============================================================\n");//경계선 출력 
		//do while문을 이용하여 적어도 한번은 반복문안의코드가 실행될수 있도록함 
		do {
			printf("플레이리스트에 추가할 곡 번호?");//추가할 곡번호를 입력하라는 메시지 출력
			scanf_s("%d", &songNum);//곡 번호 입력받음
			if (songNum > size||songNum==0) {//위의 곡정보의 번호가 아닌  잘못된 번호를 입력받은 경우
				printf("잘못된 곡 번호입니다\n"); //잘못된 곡번호라는 메시지 출력
				continue;//다시 do의 맨 처음으로 이동 
			}
			playList[count] = &arr[songNum - 1];//배열의 인덱스는 0부터 시작이므로 입력받은번호-1의 배열주소를 playList에 저장
			count++;//playList에 곡이 추가되었으므로 count 증가 
			printf("<<플레이리스트>>\n");//플레이리스트 출력함을 알리는 출력
			for (int i = 0; i < count; i++) {//플레이리스트 사이즈만큼 for문 돌림
				printf("%-20s %-20s %-15s %-10d\n",
					playList[i]->title, playList[i]->artist, playList[i]->genre, playList[i]->playingTime);
				total += playList[i]->playingTime;//전체 재생시간을 세어주기위해 for문 한번 돌때마다 해당 곡 재생시간 total에 추가
			}//playList에 저장된 곡 정보주소를 이용하여 저장된 곡 정보 전부 출력
			printf("총 재생시간 : %d초\n",total);//total에 저장된 총 곡 재생시간 출력
			total = 0;//total 다시 0으로 초기화
			if (playList[MAX - 1] != NULL) { //playList에 5개의 곡이 다 찬경우
				printf("<<<5곡을 전부 등록하여 프로그램을 종료합니다>>>");//프로그램 종료메시지 출력
			}
		} while (playList[MAX - 1]== NULL); //곡이 추가되는 playList의 마지막 4인덱스에 값이 채워지면 반복문 종료 
	
	return 0;
}
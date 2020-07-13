/*
프로그램명 : ex17_201902666_KimSongE
설명: 입력받은 노래 제목을 최대 20개 저장하고 관리하는 프로그램
작성일시 : 2020/05/22
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include <stdio.h>//표준 입출력 라이브러리
const char* menu[] = { "종료","추가","수정","목록" };//읽기전용 포인터로 메뉴 포인터배열만듬 
char song[20][40];//입력받은 노래목록을 저장할 2차원배열 
char search[64];//찾고자 하는노래를 저장할 배열 

int main(void) {
	int menuSize = sizeof(menu) / sizeof(menu[0]);//16/4=4 (메뉴 크기)
	int row = sizeof(song) / sizeof(song[0]);//800/40=20 (행 크기)
	int num;//입력받을 메뉴번호
	int count = 0;//노래목록 배열의 인덱스 

	while (1) {//반복문
		printf("[");//메뉴 출력의 시작
		for (int i = 0; i < menuSize; i++) {//메뉴크기만큼 반복문을 돌린다
			printf("%d.%s ", i, menu[i]);//메뉴를 차례로 전부 출력
		}
		printf("] 선택? ");//메뉴 출력의 끝
		scanf_s("%d", &num);//메뉴번호 입력받는다
		
		if (num == 0){//0 입력받을 시 
			break;//프로그램 종료
		}
		else if (num == 1) {//메뉴번호1 입력받을 시
			if (count == row) {//count가 20이 되면
				printf("더이상 받을 수 없습니다.\n");//더이상 받을 수 없다는 메시지 출력
				continue;//while문의 시작부분으로 
			}
			printf("노래 제목?(최대40글자) ");//노래제목입력하라는 메시지 출력
			scanf_s(" %[^\n]s", song[count],40);//노래제목 입력받음 
			printf("\n");//줄바꿈
			count++;//인덱스 이동 
	    }
		else if (num == 2) {//메뉴번호2 입력받을 시
			int flag = 0;//노래가 목록에 없을 경우를 위해 만든 플래그
			printf("찾을 노래 제목? ");//찾을 노래제목 입력하라는 메시지 출력
			scanf_s(" %[^\n]s", search, 40);//노래제목 입력받음 
			
			for (int i = 0; i < menuSize; i++) {//메뉴사이즈만큼 for문 돌림			
				if (strcmp(search, song[i]) == 0) { // 배열원소가 입력받은 search와 같을 경우
					printf("수정할 제목? ");//수정할 제목 입력하라는 메시지 출력
					scanf_s(" %[^\n]s", song[i], 40);//수정할 제목 입력받음
					printf("\n");//줄바꿈
					flag = 1;//flag 1로 변경
					break;//for문 빠져나옴
				}
			}
			if (flag == 0) {//for문을 다돌고도 flag가 0인경우
				printf("목록에 없습니다.\n\n");//찾고자 하는 노래가 없다는 메시지 출력 
			}
		}
		else if (num == 3) {//메뉴번호3 입력받을 시
			printf("<<노래목록>>\n");//노래목록 표시메시지 출력

			for (int i = 0; i < row; i++) {//최대 20개까지 받을 수 있으므로 row만큼 돌림 
				if (strlen(song[i])==0) {//더 입력된 노래가 없을 시
					printf("\n");//줄바꿈 한번 하고 
					break;//for문 빠져나온다
				}
				printf(" %s\n",song[i]);//차례로 노래목록 출력 
			}
		}

		else {//메뉴번호가 1,2,3 중에 없을 시
			printf("번호가 잘못 입력되었습니다\n\n");//번호가 잘못되었다는 메시지 출력 
		}
	}
	return 0;
}
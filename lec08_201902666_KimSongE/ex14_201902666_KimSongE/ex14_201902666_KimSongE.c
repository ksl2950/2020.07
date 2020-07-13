/*
프로그램명 : ex14_201902666_KimSongE
설명: 사용자로부터 아이디를 입력받아 유효한 아이디인지 검사하는 프로그램
작성일시 : 2020/05/22
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include<stdio.h>//표준 입출력 라이브러리

int main(void) {
	char ID[64];//문자열 ID
	while (1) {
	printf("ID를 입력해주세요('!'입력시 종료): ");//ID 입력하라는 메시지 출력
	scanf_s("%s", ID, sizeof(ID));//ID입력받음 
	if (strcmp(ID, "!") == 0) { //느낌표 입력했을 경우
		break;//프로그램 종료
	}
	if (strlen(ID) < 8) {//ID가 8자 미만인경우
		printf("ID는 8자 이상이어야 합니다.\n");//8자이상이어야 한다는 메시지 출력
		continue;//다시 while문 처음으로 돌아가 ID입력받음 
	}
	if (!isalpha(ID[0])) {//ID가 숫자로 시작하는 경우
		printf("ID는 영문자로 시작해야합니다.\n");//영문자로 시작해야한다는 메시지 출력
		continue;//다시 while문 처음으로 돌아가 ID입력받음 
	}
	printf("%s는 사용할 수 있는 ID입니다.\n",ID);//위의 조건이 다 아닐 경우 사용할 수 있는 ID임

}
	return 0;
}
/*
프로그램명 : ex10_201902666_KimSongE
설명: 오름차순으로 정렬되어 있는 문자열 배열에서 영화제목을 이진탐색을 이용해 
	검색하여 해당 영화 제목을 수정하는 프로그램
작성일시 : 2020/06/23
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include <stdio.h> // 표준 입출력 라이브러리 
#include <stdlib.h> //bsearch 함수를 포함하는 라이브러리 
#define ROW 5 //저장되어 있는 영화 제목 개수
#define COL 30 //영화 제목 최대 길이 

int compare(const void* a, const void* b); //bsearch 함수에서 이용할 함수 선언
void print_movies(const char arr[][COL]);//영화 제목 출력 함수 선언 

int main(void) {
	
	//영화 제목을 2차원 문자 배열을 통해 저장 
	//최대 ROW개의 영화제목과 COL만큼의 제목길이를 가짐 
	char movies[ROW][COL] = {
		//정렬된 문자 배열이어야 이진 탐색을 할 수 있음 
		//알파벳 순으로 정렬 
		"Ant-Man",
		"Avengers",
		"Bohemian Rhapsody",
		"Falling In Love",
		"Inside Out"
	};
	char searchMovie[COL];//영화 제목을 검색할 떄 입력받을 문자열 
	char modified[COL];//영화 제목을 수정할 때 입력받을 문자열 

	print_movies(movies);//영화제목 출력하는 함수 호출 
	printf("=================\n\n");//보기 좋도록 나눈 경계선
	printf("원하는 영화 제목을 입력하세요:");//영화 제목 입력하라는 메시지 출력
	scanf_s(" %[^\n]s", searchMovie, COL);//영화제목 입력받음 
	//bsearch함수를 이용하여 입력받은 영화제목 탐색 
	//매개변수는 왼쪽에서부터 
	//찾을 값의 주소,탐색 대상이 되는 배열, 총 배열 원소 개수, 배열 한개의 길이,비교를 수행할 함수의 포인터  
	//순이다.
	char* found = bsearch(searchMovie, movies, ROW, COL, compare);//found 포인터에 찾은 값의 주소 저장 

	if (found != NULL) { // 탐색할 원소를 찾은 경우 
		printf("수정할 제목을 입력하세요:");//수정할 제목을 입력하라는 메시지 출력
		scanf_s(" %[^\n]s", modified, COL);//수정할 제목을 입력받음 
		int index = (found - movies)/COL; //found주소에서 movie주소를 빼주고 COL로 나눠주면 탐색한 원소의 인덱스를 구할 수 있다
		strcpy(movies[index], modified);//해당 인덱스의 문자열을 입력받은 영화제목으로 바꿔준다. 
		print_movies(movies);//수정된 영화목록 출력 
	}
	else {//탐색할 원소를 찾지 못한 경우
		printf("해당 영화제목을 찾지 못하였습니다.\n\n");//해당 영화제목을 찾지 못했다는 메시지 출력
	}

}
//영화 제목 목록을 전부 출력하는 함수 
void print_movies(const char arr[][COL]) { 
	printf("\n=== 영화 목록 ===\n");//영화목록 출력 표시 
	for (int i = 0; i < ROW; i++) {//ROW 만큼 for문 돌림 
		printf(" %s\n", arr[i]);//해당 인덱스의 문자열(영화제목) 출력
	}
}

//문자열을 비교하는 함수
//표준 c라이브러리의 bsearch에 의해 호출되는 콜백 함수 
int compare(const void* a, const void* b) {
	//a와 b는 char 주소이므로 const char* 형으로 변환해서 사용한다.
	const char* p1 = (const int*)a; //const int 포인터 a의 주소를 가리킴 
	const char* p2 = (const int*)b;//const int 포인터 b의 주소를 가리킴 
	
	return strcmp(p1, p2);//문자열을 비교해야 하므로 strcmp함수를 이용 
}


/*
프로그램명 : ex14_201902666_KimSongE
설명: 동적으로 할당된 2차원 배열에 대하여 같은 행의 모든 원소의 합계를 크기가 row인 배열에 구하고 
	  같은 열의 모든 원소의 합계를 크기가 column인 배열에 구하여 출력하는 프로그램
작성일시 : 2020/06/23
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include <stdio.h>//표준 입출력 라이브러리 
#include <time.h>//시간 관련 함수 모아놓은 라이브러리 
#include <stdlib.h>//난수 생성,동적 메모리 관련 함수 포함하는 라이브러리 

int main(void) {
	srand(time(NULL));//난수 발생 초기화 

	int row, col;//입력받은 row와 col 값을 저장할 변수 
	
	int* sumOfRow = NULL;//동적 메모리의 주소를 저장할 포인터 (행 크기)
	int* sumOfCol = NULL;//동적 메모리의 주소를 저장할 포인터 (열 크기) 

	printf("배열의 행 크기를 입력하세요: ");//행 크기를 입력하라는 메시지 출력 
	scanf_s("%d", &row);//행 크기 row 입력받음 
	printf("배열의 열 크기를 입력하세요: ");//열 크기를 입력하라는 메시지 출력 
	scanf_s("%d", &col);//열 크기 col 입력받음 

	for (int i = 0; i < col; i++) {// 만든 2차원 배열 크기에 맞는 경계선을 만들기 위한 for문 
		printf("-----");//경계선 출력 
	}
	printf("\n");//줄 바꿈 
	sumOfRow = (int*)malloc(sizeof(int) * row);// malloc 함수이용하여 동적 메모리 할당 (row크기의 int 배열) 
	sumOfCol = (int*)malloc(sizeof(int) * col);// malloc 함수이용하여 동적 메모리 할당 (col크기의 int 배열)
	//행 사이즈 생성 
	int **randomArray = malloc(sizeof(int*) * row);//이중 포인터에 int 포인터크기xrow 만큼의 동적 메모리 할당 

	for (int i = 0; i < row; i++) {
		//행 개수만큼 for문을 돌려,
		//int 크기 x col 만큼의 동적 메모리를 할당한다.
		randomArray[i] = (int*)malloc(sizeof(int) * col ); //해당 행 인덱스의 열(col크기만큼) 생성 
	}
	
	for (int i = 0; i < row; i++) { //바깥 반복문:row 크기만큼 돌림 (i번째 행)
		int rowSum = 0;//row 행의 원소의 합을 저장할 변수 (for문 한번 돌면 다시 0으로 초기화) 
		for(int j=0; j< col; j++){ //안쪽 반복문: col 크기만큼 돌림 (j번째 열) 
			randomArray[i][j] = rand() % 10;//0~9사이의 임의의 정수를 원소로 대입 
			printf(" %-4d", randomArray[i][j]);//배열 원소 출력 
			rowSum += randomArray[i][j];//i행의 j열 원소를 하나씩 rowSum에 더함 
		}
		sumOfRow[i] = rowSum;//i행의 원소를 전부 더한 합인 rowSum을 sumOfRow의 i번째 원소로 대입 
		printf("==> %d", sumOfRow[i]);//비깥 for문을 한번 돌때마다 i번째 행의 맨 오른쪽에  sumOfRow의 원소를 출력
		printf("\n");//행이 바뀌기 때문에 줄바꿈 
	}

	//sumOfCol에 원소를 채워주기 위해 for문 돌림
	for (int i = 0; i < col; i++) {//바깥 반복문:col 크기만큼 돌림   
		int colSum = 0;//randomArray의 i번째 열의 원소를 전부 더해줄 변수 (for문 한번 돌면 다시 0으로 초기화)
		for (int j = 0; j < row; j++) {//안쪽 반복문:row 크기만큼 돌림  
			colSum += randomArray[j][i];//i번째 열의 모든 행을 colSum에 더함 
		}
		sumOfCol[i] = colSum;//i번째 열의 원소를 전부 더한 합인 colSum을 sumOfCol의 i번째 원소로 대입 
	}

	for (int i = 0; i < col; i++) {// 만든 2차원 배열 크기에 맞는 경계선을 만들기 위한 for문 
		printf("-----");//경계선 출력 
	}

	printf("\n");//줄 바꿈 
	for (int i = 0; i < col; i++) {// for문을 col만큼 돌림  
		printf(" %-4d", sumOfCol[i]);// randomArray의 각 i열 아랫줄에 sumOfCol 원소 출력 
	}
	//사용이 끝났기 때문에 동적메모리 해제 
	free(randomArray);//randomArray포인터가 가리키는 동적메모리 해제 
	free(sumOfRow);//sumOfRow 포인터가 가리키는 동적메모리 해제  
	free(sumOfCol);//sumOfCol 포인터가 가리키는 동적메모리 해제  

	//메모리 해제 후 포인터를 널 포인터로 만든다 
	randomArray = NULL;//randomArray 포인터를 널 포인터로 만든다. 
	sumOfRow = NULL;//sumOfRow 포인터를 널 포인터로 만든다. 
	sumOfCol = NULL;//sumOfCol 포인터를 널 포인터로 만든다. 
}
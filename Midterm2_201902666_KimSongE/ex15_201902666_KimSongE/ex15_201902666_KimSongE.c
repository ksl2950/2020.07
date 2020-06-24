/*
프로그램명 : ex15_201902666_KimSongE
설명: 크기가 2인 배열을 동적 메모리에 할당한 다음, 사용자로부터 입력받은 값을
	  배열의 크기만큼 원소를 추가하고 그 이후 extend_Array함수를 호출해서 배열 크기를
	  2배씩 늘리면서 사용자가 -1을 입력할 떄까지 배열의 원소를 계속 추가하는 프로그램
작성일시 : 2020/06/23
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include <stdio.h> //표준 입출력 라이브러리
#include <stdlib.h> //동적 할당 관련 함수 가진 라이브러리 

void extended_array(int** arr, int* arraySize);// 배열의 크기를 늘려줄 함수인 extended_array 선언 

int main(void) {
	int arraySize = 2;//만들어줄 배열의 원래 크기를 size에 저장 
	int element = 0;//배열에 추가할 원소가 저장될 변수 
	int* array = (int*)malloc(sizeof(int) * arraySize);// malloc 함수이용하여 동적 메모리 할당 (arraySize크기의 int 배열)
	int i = 0;//배열에 저장된 원소의 개수를 세어줄 변수 
	int sum = 0;//배열에 들어간 원소의 합을 저장할 변수 

	printf("배열에 추가할 원소?");//배열에 추가할 원소를 입력하라는 메시지 출력 
	for (i = 0; i < arraySize; i++) {//-1이 입력될 때까지 for문을 벗어날 수 없다. 
		scanf_s(" %d", &element);//배열 원소를 element로 입력받음 
		if (element == -1) {//element가 -1일 경우 
			break;//for문을 빠져나온다 (더이상 원소를 입력할 수 없음)
		}
		if (i == arraySize - 1) {//입력된 원소의 개수가 해당 배열의 크기만큼 찼을 때 
			extended_array(&array, &arraySize);//배열의 크기를 2배늘려주기 위해 함수 호출
			// array 포인터의 주소와 배열크기 size의 주소를 인자로 보낸다. 
		}
		array[i] = element;//입력받은 원소를 배열에 저장 
	}
	printf("\n============================================\n");//경계선 출력 
	printf("배열의 최대 크기: %d", arraySize);//배열의 최대크기를 출력(배열의 사이즈)  
	printf(", 현재 저장된 원소 수:%d\n", i);//배열에 현재 저장된 원소의 개수를 출력 
	printf("배열: ");//배열 출력 
	for (int j = 0; j < i; j++) {//배열에 현재 저장된 원소의 개수만큼 for문 돌림 
		sum += array[j];//배열안의 원소들을 sum에 전부 더해준다.
		printf("%d ", array[j]);//배열 전부 for문 돌면서 출력 
	}
	printf("\n");// 줄 바꿈 
	printf("배열의 합계: %d", sum);// 배열 합계(sum) 출력

	free(array);//array포인터가 가리키는 동적메모리 해제 
	array = NULL;//array 포인터를 NULL 포인터로 만든다
}

//배열의 크기를 늘려줄 함수 
void extended_array(int** arr, int* size) { 
	//arr은 array포인터의 주소를 가리킴 
	//size는 arraySize의 주소를 가리킴  
	int extendedSize = (*size) * 2; //size를 역참조하여 2배 곱한 것을 extendedSize로 한다. 
	int* newArray = (int*)malloc(sizeof(int) * extendedSize);// malloc 함수이용하여 동적 메모리 할당 (extendedSize크기의 int 배열)
	for (int i = 0; i < *size; i++) { // size를 역참조하여 arraySize크기만큼 for문을 돌림 
		newArray[i] = (*arr)[i];//arr를 역참조하여 array배열의 원소를 newArray에 넣어준다. 
	}
	*size = extendedSize;//size를 역참조하여 ArraySize를 extendedSize 값으로 바꿔준다. 
	*arr = newArray; //arr를 역참조하여 array에 newArray를 대입한다.(사이즈가 2배 늘어난 배열이 된다.)  
}
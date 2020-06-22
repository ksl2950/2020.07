/*
프로그램명 : Grade_201902666_KimSongE
설명: 최대 10개의 교과목과 최대 100명의 학생의 성적 정보를 가지고,
메뉴번호에 따라 특정학생,모든학생, 교과목별 성적정보를 확인할 수 있는 프로그램 
작성일시 : 2020/05/31
작성자 :컴퓨터융합학부 201902666 김송이
*/
#include <stdio.h>
#define LENGTH 20 //입력받을 때 크기를 매크로 상수 LENGTH로 정의 

//학생의 정보를 멤버로 구성하는 구조체 Student
typedef struct student{

	char studentName[10];//학생이름 
	int koreanScore;//국어점수 
	int mathScore;//수학점수
	int englishScore;//영어점수
	int sum;//점수 합계
	int average;//특정 과목의 평균
	char grade;//등급
	
}STUDENT;//student에 대한 구조체 변수 STUDENT

//특정 과목에 대한 학생 정보와 점수를 멤버로 가지는 구조체 subject
typedef struct subject {
	int max;//특정과목의 최대점수
	int min;//특정과목의 최소점수
	char firstStudent[10];//1등 학생이름
	int firstStudentScore;//1등 학생점수

}SUBJECT;//subject에 대한 구조체 변수 SUBJECT

void show_studentInfo(const STUDENT*p); //학생 정보를 출력하는 메소드 
char show_Grade(STUDENT* p);//학생의 등급을 리턴하는 메소드
void show_Korean(int arr[], const STUDENT* p,int index);//국어 과목 학생의 정보를 출력하는 메소드 
void show_Math(int arr[], const STUDENT* p,int index);//수학 과목 학생의 정보를 출력하는 메소드 
void show_English(int arr[], const STUDENT* p,int index); // 영어 과목 학생의 정보를 출력하는 메소드 
int show_Max(int arr[], int size);// 배열의 최댓값을 가진 인덱스 리턴하는 메소드 
int show_Min(int arr[], int size); //배열의 최솟값을 가진 인덱스 리턴하는 메소드 

int main(void) {

	int menuNum;//메뉴번호를 입력받을 변수 
	int listSize = 0;//STUDENT 구조체 배열 list의 크기를 세줄 변수 
	char name[10];//검색할 학생의 이름을 입력받을 변수 
	int searchIndex;//검색해서 찾은 학생의 인덱스를 받을 변수 
	char subject[10];//검색할 과목을 입력받을 변수
	int arr[] = { 0 };//list의 최대,최소점수를 구할때 사용하기위해 만든 배열 
	int flag = 0;//검색한 학생의 이름 찾았는지 여부를 판단할 변수 

	STUDENT list[100] = { 0 };//100만큼의 크기를 가진 STUDENT 구조체 배열 list 
	SUBJECT korean = { 0 };//SUBJECT 구조체 변수(국어과목의 정보 저장) 
	SUBJECT math = { 0 };//SUBJECT 구조체 변수(수학과목의 정보 저장)
	SUBJECT english = { 0 };//SUBJECT 구조체 변수(영어과목의 정보 저장)

	char answer;//프로그램 종료여부에 대한 입력을 받을 변수 

	while (1) {
		printf("===============성적관리프로그램================\n");//프로그램 출력표시 
		printf("[메뉴] 1.학생 추가 2.학생 검색 3.과목별 점수 4.전체 리스트 5.종료: ");//메뉴번호 전체 출력 
		scanf_s("%d", &menuNum);//메뉴번호 입력받음 

		switch (menuNum) {//switch-case문을 이용해 입력받은 메뉴번호에 따라 조건을 나눈다. 
		case 1:	//메뉴번호가 1일 경우(학생추가) 
			if (listSize == 100) {//list의 사이즈가 100일경우 
				printf("리스트가 꽉 차 더이상 등록할 수 없습니다.\n");//더이상 등록할 수 없다는 메시지 출력 
				break;//switch-case문 빠져나옴 
			}
			printf("학생이름?");//추가할 학생이름 입력하라는 메시지 출력 
			scanf_s(" %s", &list[listSize].studentName,LENGTH);//학생이름을 listSize인덱스의 구조체배열 멤버 studentName에 입력받음 
			printf("국어점수?");//국어 점수 입력하라는 메시지 출력 
			scanf_s(" %d", &list[listSize].koreanScore,LENGTH);//국어점수를 listSize인덱스의 구조체배열 멤버 koreanScore에 입력받음 
			printf("수학점수?");//수학 점수 입력하라는 메시지 출력
			scanf_s(" %d", &list[listSize].mathScore, LENGTH);//수학점수를 listSize인덱스의 구조체배열 멤버 mathScore에 입력받음  
			printf("영어점수?");//영어 점수 입력받으라는 메시지 출력 
			scanf_s(" %d", &list[listSize].englishScore,LENGTH);//영어점수를 listSize인덱스의 구조체배열 멤버 englishScore에 입력받음 

			//구조체 배열 특정 인덱스를 가진 list의 sum값에 위에서 입력받은 전체 과목 점수를 더한 값을 대입해줌 
			list[listSize].sum = list[listSize].koreanScore + list[listSize].mathScore + list[listSize].englishScore;
			//구조체 배열 특정 인덱스를 가진 list의 average값에 sum/3값을 대입해줌 
			list[listSize].average = list[listSize].sum / 3;
			//구조체 배열 특정 인덱스를 가진 list의 grade값에 show_Grade함수를 통해 구한 등급을 대입 
			list[listSize].grade = show_Grade(&list[listSize]);
			listSize++;//학생을 추가했으므로 listSize 증가 
			break;//switch-case문 빠져나옴 
	
		case 2://메뉴번호가 2일 경우(학생 검색)
			
			printf("검색할 학생이름을 입력해주세요: ");//검색할 학생의 이름을 입력하라는 메시지 출력 
			scanf_s(" %s", name, LENGTH);//LENGTH사이즈크기를 최대로 하는 학생의 이름을 입력받음 
			for (int i = 0; i < listSize; i++) { //listSize크기만큼 for문을 돌림 
				if (strcmp(name, list[i].studentName) == 0) {//입력받은 학생의 이름과 list에 같은 값이 있는지 list의 인덱스를 처음부터 확인하며 같은지 확인 
					searchIndex = i;//같으면 searchIndex 값에 i를 대입 
					flag = 1;//검색한 학생을 찾았으므로 flag를 1로 바꾼다.
					break;//for문 빠져나옴 
				}
			}
			if (flag == 0) { //for문을 빠져나왔지만 flag 0인 경우는 검색한 학생을 찾지 못한것 
				printf("입력한 이름의 학생은 존재하지 않습니다.\n");//검색한 학생을 찾지 못했다는 메시지 출력 
				break;//switch-case문 빠져나옴 
			}
			//검색한 학생을 찾았을 경우
			show_studentInfo(&list[searchIndex]);//검색한 학생의 정보를 출력하는 메소드 호출
			break;//switch-case문 빠져나옴 

		case 3://메뉴번호가 3일 경우(과목별 점수) 
			if (listSize == 0) {//list의 크기가 아직 0인경우
				printf("등록된 학생의 정보가 없습니다\n");//등록된 학생의 정보가 없다는 메시지 출력 
			}
			
				printf("검색할 과목을 입력해주세요(국어/수학/영어): ");//검색할 과목 입력하라는 메시지 출력
				scanf_s("%s", subject, LENGTH);//검색할 과목 입력받음 
				if (strcmp(subject, "국어") == 0) {//검색한 과목이름이 국어일 경우
					printf("학생이름   성적\n");//학생이름과 성적 출력 
					
					for (int j = 0; j < listSize; j++) {//list의 크기만큼 for문을 돌림 
						show_Korean(arr,&list[j],j); //list크기만큼 해당 메소드 호출(학생의 이름과 국어과목 점수 출력)
					}		

					int max = show_Max(arr, listSize);// 특정과목 최대 점수의 인덱스값을 max에 대입
					int min = show_Min(arr, listSize);// 특정과목 최소 점수의 인덱스값을 min에 대입

					//1등학생,최고점수,1등학생점수,최저점수값 대입 
					strcpy(korean.firstStudent, list[max].studentName);//max인덱스의 list 학생이름을 SUBJECT구조체 변수 korean의 firstStudent로 복사 
					korean.max=list[max].koreanScore;//max인덱스의 list 국어점수를 SUBJECT구조체 변수 korean의 max로 복사
					korean.firstStudentScore=list[max].koreanScore;//max인덱스의 list 국어점수를 SUBJECT구조체 변수 korean의 firstStudentScore로 복사
					korean.min= list[min].koreanScore;//min인덱스의 list 국어점수를 SUBJECT구조체 변수 korean의 min로 복사

					printf("최대 점수: %d\n", korean.max);//최대 점수 출력
					printf("최소 점수: %d\n", korean.min); //최소 점수 출력 
					printf("1등 학생 이름: %s 점수: %d \n", korean.firstStudent, korean.firstStudentScore);//1등 학생이름과 점수 출력 
					break;
				}
				else if (strcmp(subject, "수학") == 0) {//검색한 과목이 수학일 경우 
					printf("학생이름   성적\n");//학생이름과 성적 출력 
				
					for (int j = 0; j < listSize; j++) {//list의 크기만큼 for문을 돌림 
						show_Math(arr,&list[j],j);//list크기만큼 해당 메소드 호출(학생의 이름과 수학과목 점수 출력)
					}	
					
					int max = show_Max(arr, listSize);// 특정과목 최대 점수의 인덱스값을 max에 대입
					int min = show_Min(arr, listSize);// 특정과목 최소 점수의 인덱스값을 min에 대입

					strcpy(math.firstStudent, list[max].studentName);//max인덱스의 list 학생이름을 SUBJECT구조체 변수 math의 firstStudent로 복사 
					math.max= list[max].mathScore;//max인덱스의 list 수학점수를 SUBJECT구조체 변수 math의 max로 복사
					math.firstStudentScore=list[max].mathScore;//max인덱스의 list 수학점수를 SUBJECT구조체 변수 math의 firstStudentScore로 복사
					math.min=list[min].mathScore;//min인덱스의 list 영어점수를 SUBJECT구조체 변수 english의 min로 복사

					printf("최대 점수: %d\n", math.max);//최대 점수 출력 
					printf("최소 점수: %d\n", math.min);//최소 점수 출력 
					printf("1등 학생 이름: %s 점수: %d \n", math.firstStudent, math.firstStudentScore);//1등 학생이름과 점수 출력 
					break;
				}
				else if (strcmp(subject, "영어") == 0) {//검색한 과목이 영어일 경우 
					printf("학생이름   성적\n");//학생이름과 성적 출력 
					
					for (int j = 0; j < listSize; j++) {//list의 크기만큼 for문을 돌림
						show_English(arr,&list[j],j);//list크기만큼 해당 메소드 호출(학생의 이름과 영어과목 점수 출력)
					}
					int max = show_Max(arr, listSize);// 특정과목 최대 점수의 인덱스값을 max에 대입
					int min = show_Min(arr, listSize);// 특정과목 최소 점수의 인덱스값을 min에 대입

					strcpy(english.firstStudent, list[max].studentName);//max인덱스의 list 학생이름을 SUBJECT구조체 변수 english의 firstStudent로 복사 
					english.max=list[max].englishScore;//max인덱스의 list 영어점수를 SUBJECT구조체 변수 english의 max로 복사
					english.firstStudentScore=list[max].englishScore;//max인덱스의 list 영어점수를 SUBJECT구조체 변수 english의 firstStudentScore로 복사
					english.min= list[min].englishScore;//min인덱스의 list 영어점수를 SUBJECT구조체 변수 english의 min로 복사
					
					printf("최대 점수: %d\n",english.max);//최대 점수 출력 
					printf("최소 점수: %d\n",english.min );//최소 점수 출력 
					printf("1등 학생 이름: %s 점수: %d \n", english.firstStudent, english.firstStudentScore);//1등 학생이름과 점수 출력 
				}
				else {//검색한 과목이 국어,수학,영어가 아닐 경우 
					printf("등록되어 있지 않은 과목입니다 \n");//과목이 잘못되었다는 메시지 출력 
					
				}
			
			break;//switch-case문 빠져나옴
		case 4://메뉴번호가 4일경우(리스트 전체 출력)
			printf("<<<전체 학생의 정보를 출력합니다>>>\n");//전체 학생의 정보 출력 
			printf("이름         국어       수학       영어        합계      평균       등급\n");//각각 표시할 것들 출력 
			for (int i = 0; i < listSize; i++) {//list 크기만큼 for문 돌림 
				printf("%-13s %-10d %-10d %-10d %-10d %-10d %-10c\n",
					list[i].studentName, list[i].koreanScore, list[i].mathScore, list[i].englishScore, list[i].sum, list[i].average, list[i].grade);
				//STUDENT 구조체 배열list의 멤버에 접근하여 인덱스 0부터 리스트 끝까지 학생의 정보를 전부 출력 
			}
			break;//switch-case문 빠져나옴
		case 5:	//메뉴번호가 5일경우(프로그램 종료)	
			printf("프로그램을 종료하시겠습니까?(y/n): ");//그래도 한번 더물어보기 위해 출력 
			scanf_s(" %c", &answer);//y또는 n 입력받음 
			if (answer == 'y') {//'y' 입력시 종료, 아닐시 계속 프로그램 실행 
				exit();//프로그램 종료한다는 뜻 
			}
			break;//switch-case문 빠져나옴 
		default: //1~5 외에 다른 숫자를 입력했을 경우 
			printf("잘못된 메뉴번호입니다\n");//잘못된 메뉴번호라는 메시지 출력
			
		}
	};
	return 0; 
}

//읽기 전용 구조체 포인터를 매개변수로 받아  학생 정보 출력 
void show_studentInfo(const STUDENT*p) {
	printf("이름         국어       수학       영어       합계       평균      등급\n");//출력할 내용 표시 
	printf("%-13s %-10d %-10d %-10d %-10d %-10d %-10c\n",
		p->studentName,p->koreanScore,p->mathScore,p->englishScore,p->sum,p->average,p->grade);
	//포인터 p가 가리키는 STUDENT 변수의 멤버들 전부 출력 
}
//입력받은 구조체 포인터를 이용하여 특정 STUDENT 변수의 등급 구한다.
char show_Grade(STUDENT* p) {
	if (p->average >= 90) {//포인터 p가 가리키는 average값이 90 이상일 경우 
		p->grade = 'A';//포인터 p가 가리키는 grade값 A 대입 
	}
	else if (p->average >= 80 && p->average < 90) {//포인터 p가 가리키는 average값이 80 이상 90 미만일 경우 
		p->grade = 'B';//포인터 p가 가리키는 grade값 B 대입 
	}
	else if (p->average >= 70 && p->average < 80) {//포인터 p가 가리키는 average값이 70 이상 80 미만일 경우
		p->grade = 'C';//포인터 p가 가리키는 grade값 C 대입 
	}
	else if (p->average >= 60 && p->average < 70) {//포인터 p가 가리키는 average값이 60 이상 70 미만일 경우
		p->grade = 'D';//포인터 p가 가리키는 grade값 D 대입 
	}
	else {// //포인터 p가 가리키는 average값이 60 미만일 경우
		p->grade = 'F';//포인터 p가 가리키는 grade값 F 대입 
	}
	return p->grade;//포인터 p가 가리키는 grade값 리턴 
}
//국어과목의 학생이름과 점수 출력하는 함수
void show_Korean(int arr[], STUDENT* p,int index) {

	int* Array = arr;//포인터를 Array가 arr의 주소 가리킴
	printf("%-11s %d\n", p->studentName, p->koreanScore);//인자로 받은 구조체포인터가 가리키는 학생이름과 국어점수 출력
	Array[index] = p->koreanScore;//arr에 해당 점수를 넣어줌 
	
}
//수학과목의 학생이름과 점수 출력하는 함수
void show_Math(int arr[], STUDENT* p,int index) {

	int* Array = arr;//포인터를 Array가 arr의 주소 가리킴
	printf("%-11s %d\n", p->studentName, p->mathScore);//인자로 받은 구조체포인터가 가리키는 학생이름과 수학점수 출력
	Array[index] = p->mathScore;//arr에 해당 점수를 넣어줌 
	
}
//영어과목의 학생이름과 점수 출력하는 함수
void show_English(int arr[], STUDENT* p,int index) {

	int* Array = arr;//포인터를 Array가 arr의 주소 가리킴
	printf("%-11s %d\n", p->studentName, p->englishScore);//인자로 받은 구조체포인터가 가리키는 학생이름과 영어점수 출력	
	Array[index] = p->englishScore;//arr에 해당 점수를 넣어줌
}

//매개변수로 받은 배열의 최댓값을 가진 인덱스를 구하는 함수 
int show_Max(int arr[],int size) {
	int max = 0;//배열의 최대값을 가진 인덱스를 저장할 변수 
	for (int i = 1; i < size; i++) {//1부터 배열끝까지 for문을 돌림
		if (arr[max] < arr[i]) {//max인덱스의 배열값보다 해당 i인덱스의 배열값이 큰 경우
			max = i ;//그때의 i가 max가 됨
		}
	}
	return max;//최대값을 가진 인덱스 max를 반환
}

//매개변수로 받은 배열의 최솟값을 가진 인덱스를 구하는 함수
int show_Min(int arr[],int size) {
	int min = 0;//배열의 최솟값을 가진 인덱스를 저장할 변수 
	for (int i = 1; i < size; i++) {//1부터 배열끝까지 for문을 돌림
		if (arr[min] > arr[i]) {//min인덱스의 배열값보다 해당 i인덱스의 배열값이 더 작은 경우
			min = i;//그때의 i가 min가 됨
		}
	}
	return min;//최솟값을 가진 인덱스 min를 반환
}
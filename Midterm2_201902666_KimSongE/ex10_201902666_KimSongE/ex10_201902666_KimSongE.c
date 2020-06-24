/*
���α׷��� : ex10_201902666_KimSongE
����: ������������ ���ĵǾ� �ִ� ���ڿ� �迭���� ��ȭ������ ����Ž���� �̿��� 
	�˻��Ͽ� �ش� ��ȭ ������ �����ϴ� ���α׷�
�ۼ��Ͻ� : 2020/06/23
�ۼ��� :��ǻ�������к� 201902666 �����
*/
#include <stdio.h> // ǥ�� ����� ���̺귯�� 
#include <stdlib.h> //bsearch �Լ��� �����ϴ� ���̺귯�� 
#define ROW 5 //����Ǿ� �ִ� ��ȭ ���� ����
#define COL 30 //��ȭ ���� �ִ� ���� 

int compare(const void* a, const void* b); //bsearch �Լ����� �̿��� �Լ� ����
void print_movies(const char arr[][COL]);//��ȭ ���� ��� �Լ� ���� 

int main(void) {
	
	//��ȭ ������ 2���� ���� �迭�� ���� ���� 
	//�ִ� ROW���� ��ȭ����� COL��ŭ�� ������̸� ���� 
	char movies[ROW][COL] = {
		//���ĵ� ���� �迭�̾�� ���� Ž���� �� �� ���� 
		//���ĺ� ������ ���� 
		"Ant-Man",
		"Avengers",
		"Bohemian Rhapsody",
		"Falling In Love",
		"Inside Out"
	};
	char searchMovie[COL];//��ȭ ������ �˻��� �� �Է¹��� ���ڿ� 
	char modified[COL];//��ȭ ������ ������ �� �Է¹��� ���ڿ� 

	print_movies(movies);//��ȭ���� ����ϴ� �Լ� ȣ�� 
	printf("=================\n\n");//���� ������ ���� ��輱
	printf("���ϴ� ��ȭ ������ �Է��ϼ���:");//��ȭ ���� �Է��϶�� �޽��� ���
	scanf_s(" %[^\n]s", searchMovie, COL);//��ȭ���� �Է¹��� 
	//bsearch�Լ��� �̿��Ͽ� �Է¹��� ��ȭ���� Ž�� 
	//�Ű������� ���ʿ������� 
	//ã�� ���� �ּ�,Ž�� ����� �Ǵ� �迭, �� �迭 ���� ����, �迭 �Ѱ��� ����,�񱳸� ������ �Լ��� ������  
	//���̴�.
	char* found = bsearch(searchMovie, movies, ROW, COL, compare);//found �����Ϳ� ã�� ���� �ּ� ���� 

	if (found != NULL) { // Ž���� ���Ҹ� ã�� ��� 
		printf("������ ������ �Է��ϼ���:");//������ ������ �Է��϶�� �޽��� ���
		scanf_s(" %[^\n]s", modified, COL);//������ ������ �Է¹��� 
		int index = (found - movies)/COL; //found�ּҿ��� movie�ּҸ� ���ְ� COL�� �����ָ� Ž���� ������ �ε����� ���� �� �ִ�
		strcpy(movies[index], modified);//�ش� �ε����� ���ڿ��� �Է¹��� ��ȭ�������� �ٲ��ش�. 
		print_movies(movies);//������ ��ȭ��� ��� 
	}
	else {//Ž���� ���Ҹ� ã�� ���� ���
		printf("�ش� ��ȭ������ ã�� ���Ͽ����ϴ�.\n\n");//�ش� ��ȭ������ ã�� ���ߴٴ� �޽��� ���
	}

}
//��ȭ ���� ����� ���� ����ϴ� �Լ� 
void print_movies(const char arr[][COL]) { 
	printf("\n=== ��ȭ ��� ===\n");//��ȭ��� ��� ǥ�� 
	for (int i = 0; i < ROW; i++) {//ROW ��ŭ for�� ���� 
		printf(" %s\n", arr[i]);//�ش� �ε����� ���ڿ�(��ȭ����) ���
	}
}

//���ڿ��� ���ϴ� �Լ�
//ǥ�� c���̺귯���� bsearch�� ���� ȣ��Ǵ� �ݹ� �Լ� 
int compare(const void* a, const void* b) {
	//a�� b�� char �ּ��̹Ƿ� const char* ������ ��ȯ�ؼ� ����Ѵ�.
	const char* p1 = (const int*)a; //const int ������ a�� �ּҸ� ����Ŵ 
	const char* p2 = (const int*)b;//const int ������ b�� �ּҸ� ����Ŵ 
	
	return strcmp(p1, p2);//���ڿ��� ���ؾ� �ϹǷ� strcmp�Լ��� �̿� 
}


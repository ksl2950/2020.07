/*
���α׷��� : ex14_201902666_KimSongE
����: �������� �Ҵ�� 2���� �迭�� ���Ͽ� ���� ���� ��� ������ �հ踦 ũ�Ⱑ row�� �迭�� ���ϰ� 
	  ���� ���� ��� ������ �հ踦 ũ�Ⱑ column�� �迭�� ���Ͽ� ����ϴ� ���α׷�
�ۼ��Ͻ� : 2020/06/23
�ۼ��� :��ǻ�������к� 201902666 �����
*/
#include <stdio.h>//ǥ�� ����� ���̺귯�� 
#include <time.h>//�ð� ���� �Լ� ��Ƴ��� ���̺귯�� 
#include <stdlib.h>//���� ����,���� �޸� ���� �Լ� �����ϴ� ���̺귯�� 

int main(void) {
	srand(time(NULL));//���� �߻� �ʱ�ȭ 

	int row, col;//�Է¹��� row�� col ���� ������ ���� 
	
	int* sumOfRow = NULL;//���� �޸��� �ּҸ� ������ ������ (�� ũ��)
	int* sumOfCol = NULL;//���� �޸��� �ּҸ� ������ ������ (�� ũ��) 

	printf("�迭�� �� ũ�⸦ �Է��ϼ���: ");//�� ũ�⸦ �Է��϶�� �޽��� ��� 
	scanf_s("%d", &row);//�� ũ�� row �Է¹��� 
	printf("�迭�� �� ũ�⸦ �Է��ϼ���: ");//�� ũ�⸦ �Է��϶�� �޽��� ��� 
	scanf_s("%d", &col);//�� ũ�� col �Է¹��� 

	for (int i = 0; i < col; i++) {// ���� 2���� �迭 ũ�⿡ �´� ��輱�� ����� ���� for�� 
		printf("-----");//��輱 ��� 
	}
	printf("\n");//�� �ٲ� 
	sumOfRow = (int*)malloc(sizeof(int) * row);// malloc �Լ��̿��Ͽ� ���� �޸� �Ҵ� (rowũ���� int �迭) 
	sumOfCol = (int*)malloc(sizeof(int) * col);// malloc �Լ��̿��Ͽ� ���� �޸� �Ҵ� (colũ���� int �迭)
	//�� ������ ���� 
	int **randomArray = malloc(sizeof(int*) * row);//���� �����Ϳ� int ������ũ��xrow ��ŭ�� ���� �޸� �Ҵ� 

	for (int i = 0; i < row; i++) {
		//�� ������ŭ for���� ����,
		//int ũ�� x col ��ŭ�� ���� �޸𸮸� �Ҵ��Ѵ�.
		randomArray[i] = (int*)malloc(sizeof(int) * col ); //�ش� �� �ε����� ��(colũ�⸸ŭ) ���� 
	}
	
	for (int i = 0; i < row; i++) { //�ٱ� �ݺ���:row ũ�⸸ŭ ���� (i��° ��)
		int rowSum = 0;//row ���� ������ ���� ������ ���� (for�� �ѹ� ���� �ٽ� 0���� �ʱ�ȭ) 
		for(int j=0; j< col; j++){ //���� �ݺ���: col ũ�⸸ŭ ���� (j��° ��) 
			randomArray[i][j] = rand() % 10;//0~9������ ������ ������ ���ҷ� ���� 
			printf(" %-4d", randomArray[i][j]);//�迭 ���� ��� 
			rowSum += randomArray[i][j];//i���� j�� ���Ҹ� �ϳ��� rowSum�� ���� 
		}
		sumOfRow[i] = rowSum;//i���� ���Ҹ� ���� ���� ���� rowSum�� sumOfRow�� i��° ���ҷ� ���� 
		printf("==> %d", sumOfRow[i]);//��� for���� �ѹ� �������� i��° ���� �� �����ʿ�  sumOfRow�� ���Ҹ� ���
		printf("\n");//���� �ٲ�� ������ �ٹٲ� 
	}

	//sumOfCol�� ���Ҹ� ä���ֱ� ���� for�� ����
	for (int i = 0; i < col; i++) {//�ٱ� �ݺ���:col ũ�⸸ŭ ����   
		int colSum = 0;//randomArray�� i��° ���� ���Ҹ� ���� ������ ���� (for�� �ѹ� ���� �ٽ� 0���� �ʱ�ȭ)
		for (int j = 0; j < row; j++) {//���� �ݺ���:row ũ�⸸ŭ ����  
			colSum += randomArray[j][i];//i��° ���� ��� ���� colSum�� ���� 
		}
		sumOfCol[i] = colSum;//i��° ���� ���Ҹ� ���� ���� ���� colSum�� sumOfCol�� i��° ���ҷ� ���� 
	}

	for (int i = 0; i < col; i++) {// ���� 2���� �迭 ũ�⿡ �´� ��輱�� ����� ���� for�� 
		printf("-----");//��輱 ��� 
	}

	printf("\n");//�� �ٲ� 
	for (int i = 0; i < col; i++) {// for���� col��ŭ ����  
		printf(" %-4d", sumOfCol[i]);// randomArray�� �� i�� �Ʒ��ٿ� sumOfCol ���� ��� 
	}
	//����� ������ ������ �����޸� ���� 
	free(randomArray);//randomArray�����Ͱ� ����Ű�� �����޸� ���� 
	free(sumOfRow);//sumOfRow �����Ͱ� ����Ű�� �����޸� ����  
	free(sumOfCol);//sumOfCol �����Ͱ� ����Ű�� �����޸� ����  

	//�޸� ���� �� �����͸� �� �����ͷ� ����� 
	randomArray = NULL;//randomArray �����͸� �� �����ͷ� �����. 
	sumOfRow = NULL;//sumOfRow �����͸� �� �����ͷ� �����. 
	sumOfCol = NULL;//sumOfCol �����͸� �� �����ͷ� �����. 
}
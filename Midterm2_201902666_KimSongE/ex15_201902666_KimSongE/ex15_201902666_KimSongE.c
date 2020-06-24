/*
���α׷��� : ex15_201902666_KimSongE
����: ũ�Ⱑ 2�� �迭�� ���� �޸𸮿� �Ҵ��� ����, ����ڷκ��� �Է¹��� ����
	  �迭�� ũ�⸸ŭ ���Ҹ� �߰��ϰ� �� ���� extend_Array�Լ��� ȣ���ؼ� �迭 ũ�⸦
	  2�辿 �ø��鼭 ����ڰ� -1�� �Է��� ������ �迭�� ���Ҹ� ��� �߰��ϴ� ���α׷�
�ۼ��Ͻ� : 2020/06/23
�ۼ��� :��ǻ�������к� 201902666 �����
*/
#include <stdio.h> //ǥ�� ����� ���̺귯��
#include <stdlib.h> //���� �Ҵ� ���� �Լ� ���� ���̺귯�� 

void extended_array(int** arr, int* arraySize);// �迭�� ũ�⸦ �÷��� �Լ��� extended_array ���� 

int main(void) {
	int arraySize = 2;//������� �迭�� ���� ũ�⸦ size�� ���� 
	int element = 0;//�迭�� �߰��� ���Ұ� ����� ���� 
	int* array = (int*)malloc(sizeof(int) * arraySize);// malloc �Լ��̿��Ͽ� ���� �޸� �Ҵ� (arraySizeũ���� int �迭)
	int i = 0;//�迭�� ����� ������ ������ ������ ���� 
	int sum = 0;//�迭�� �� ������ ���� ������ ���� 

	printf("�迭�� �߰��� ����?");//�迭�� �߰��� ���Ҹ� �Է��϶�� �޽��� ��� 
	for (i = 0; i < arraySize; i++) {//-1�� �Էµ� ������ for���� ��� �� ����. 
		scanf_s(" %d", &element);//�迭 ���Ҹ� element�� �Է¹��� 
		if (element == -1) {//element�� -1�� ��� 
			break;//for���� �������´� (���̻� ���Ҹ� �Է��� �� ����)
		}
		if (i == arraySize - 1) {//�Էµ� ������ ������ �ش� �迭�� ũ�⸸ŭ á�� �� 
			extended_array(&array, &arraySize);//�迭�� ũ�⸦ 2��÷��ֱ� ���� �Լ� ȣ��
			// array �������� �ּҿ� �迭ũ�� size�� �ּҸ� ���ڷ� ������. 
		}
		array[i] = element;//�Է¹��� ���Ҹ� �迭�� ���� 
	}
	printf("\n============================================\n");//��輱 ��� 
	printf("�迭�� �ִ� ũ��: %d", arraySize);//�迭�� �ִ�ũ�⸦ ���(�迭�� ������)  
	printf(", ���� ����� ���� ��:%d\n", i);//�迭�� ���� ����� ������ ������ ��� 
	printf("�迭: ");//�迭 ��� 
	for (int j = 0; j < i; j++) {//�迭�� ���� ����� ������ ������ŭ for�� ���� 
		sum += array[j];//�迭���� ���ҵ��� sum�� ���� �����ش�.
		printf("%d ", array[j]);//�迭 ���� for�� ���鼭 ��� 
	}
	printf("\n");// �� �ٲ� 
	printf("�迭�� �հ�: %d", sum);// �迭 �հ�(sum) ���

	free(array);//array�����Ͱ� ����Ű�� �����޸� ���� 
	array = NULL;//array �����͸� NULL �����ͷ� �����
}

//�迭�� ũ�⸦ �÷��� �Լ� 
void extended_array(int** arr, int* size) { 
	//arr�� array�������� �ּҸ� ����Ŵ 
	//size�� arraySize�� �ּҸ� ����Ŵ  
	int extendedSize = (*size) * 2; //size�� �������Ͽ� 2�� ���� ���� extendedSize�� �Ѵ�. 
	int* newArray = (int*)malloc(sizeof(int) * extendedSize);// malloc �Լ��̿��Ͽ� ���� �޸� �Ҵ� (extendedSizeũ���� int �迭)
	for (int i = 0; i < *size; i++) { // size�� �������Ͽ� arraySizeũ�⸸ŭ for���� ���� 
		newArray[i] = (*arr)[i];//arr�� �������Ͽ� array�迭�� ���Ҹ� newArray�� �־��ش�. 
	}
	*size = extendedSize;//size�� �������Ͽ� ArraySize�� extendedSize ������ �ٲ��ش�. 
	*arr = newArray; //arr�� �������Ͽ� array�� newArray�� �����Ѵ�.(����� 2�� �þ �迭�� �ȴ�.)  
}
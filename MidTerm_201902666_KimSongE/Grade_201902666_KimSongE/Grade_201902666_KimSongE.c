/*
���α׷��� : Grade_201902666_KimSongE
����: �ִ� 10���� ������� �ִ� 100���� �л��� ���� ������ ������,
�޴���ȣ�� ���� Ư���л�,����л�, ������ ���������� Ȯ���� �� �ִ� ���α׷� 
�ۼ��Ͻ� : 2020/05/31
�ۼ��� :��ǻ�������к� 201902666 �����
*/
#include <stdio.h>
#define LENGTH 20 //�Է¹��� �� ũ�⸦ ��ũ�� ��� LENGTH�� ���� 

//�л��� ������ ����� �����ϴ� ����ü Student
typedef struct student{

	char studentName[10];//�л��̸� 
	int koreanScore;//�������� 
	int mathScore;//��������
	int englishScore;//��������
	int sum;//���� �հ�
	int average;//Ư�� ������ ���
	char grade;//���
	
}STUDENT;//student�� ���� ����ü ���� STUDENT

//Ư�� ���� ���� �л� ������ ������ ����� ������ ����ü subject
typedef struct subject {
	int max;//Ư�������� �ִ�����
	int min;//Ư�������� �ּ�����
	char firstStudent[10];//1�� �л��̸�
	int firstStudentScore;//1�� �л�����

}SUBJECT;//subject�� ���� ����ü ���� SUBJECT

void show_studentInfo(const STUDENT*p); //�л� ������ ����ϴ� �޼ҵ� 
char show_Grade(STUDENT* p);//�л��� ����� �����ϴ� �޼ҵ�
void show_Korean(int arr[], const STUDENT* p,int index);//���� ���� �л��� ������ ����ϴ� �޼ҵ� 
void show_Math(int arr[], const STUDENT* p,int index);//���� ���� �л��� ������ ����ϴ� �޼ҵ� 
void show_English(int arr[], const STUDENT* p,int index); // ���� ���� �л��� ������ ����ϴ� �޼ҵ� 
int show_Max(int arr[], int size);// �迭�� �ִ��� ���� �ε��� �����ϴ� �޼ҵ� 
int show_Min(int arr[], int size); //�迭�� �ּڰ��� ���� �ε��� �����ϴ� �޼ҵ� 

int main(void) {

	int menuNum;//�޴���ȣ�� �Է¹��� ���� 
	int listSize = 0;//STUDENT ����ü �迭 list�� ũ�⸦ ���� ���� 
	char name[10];//�˻��� �л��� �̸��� �Է¹��� ���� 
	int searchIndex;//�˻��ؼ� ã�� �л��� �ε����� ���� ���� 
	char subject[10];//�˻��� ������ �Է¹��� ����
	int arr[] = { 0 };//list�� �ִ�,�ּ������� ���Ҷ� ����ϱ����� ���� �迭 
	int flag = 0;//�˻��� �л��� �̸� ã�Ҵ��� ���θ� �Ǵ��� ���� 

	STUDENT list[100] = { 0 };//100��ŭ�� ũ�⸦ ���� STUDENT ����ü �迭 list 
	SUBJECT korean = { 0 };//SUBJECT ����ü ����(��������� ���� ����) 
	SUBJECT math = { 0 };//SUBJECT ����ü ����(���а����� ���� ����)
	SUBJECT english = { 0 };//SUBJECT ����ü ����(��������� ���� ����)

	char answer;//���α׷� ���Ῡ�ο� ���� �Է��� ���� ���� 

	while (1) {
		printf("===============�����������α׷�================\n");//���α׷� ���ǥ�� 
		printf("[�޴�] 1.�л� �߰� 2.�л� �˻� 3.���� ���� 4.��ü ����Ʈ 5.����: ");//�޴���ȣ ��ü ��� 
		scanf_s("%d", &menuNum);//�޴���ȣ �Է¹��� 

		switch (menuNum) {//switch-case���� �̿��� �Է¹��� �޴���ȣ�� ���� ������ ������. 
		case 1:	//�޴���ȣ�� 1�� ���(�л��߰�) 
			if (listSize == 100) {//list�� ����� 100�ϰ�� 
				printf("����Ʈ�� �� �� ���̻� ����� �� �����ϴ�.\n");//���̻� ����� �� ���ٴ� �޽��� ��� 
				break;//switch-case�� �������� 
			}
			printf("�л��̸�?");//�߰��� �л��̸� �Է��϶�� �޽��� ��� 
			scanf_s(" %s", &list[listSize].studentName,LENGTH);//�л��̸��� listSize�ε����� ����ü�迭 ��� studentName�� �Է¹��� 
			printf("��������?");//���� ���� �Է��϶�� �޽��� ��� 
			scanf_s(" %d", &list[listSize].koreanScore,LENGTH);//���������� listSize�ε����� ����ü�迭 ��� koreanScore�� �Է¹��� 
			printf("��������?");//���� ���� �Է��϶�� �޽��� ���
			scanf_s(" %d", &list[listSize].mathScore, LENGTH);//���������� listSize�ε����� ����ü�迭 ��� mathScore�� �Է¹���  
			printf("��������?");//���� ���� �Է¹������ �޽��� ��� 
			scanf_s(" %d", &list[listSize].englishScore,LENGTH);//���������� listSize�ε����� ����ü�迭 ��� englishScore�� �Է¹��� 

			//����ü �迭 Ư�� �ε����� ���� list�� sum���� ������ �Է¹��� ��ü ���� ������ ���� ���� �������� 
			list[listSize].sum = list[listSize].koreanScore + list[listSize].mathScore + list[listSize].englishScore;
			//����ü �迭 Ư�� �ε����� ���� list�� average���� sum/3���� �������� 
			list[listSize].average = list[listSize].sum / 3;
			//����ü �迭 Ư�� �ε����� ���� list�� grade���� show_Grade�Լ��� ���� ���� ����� ���� 
			list[listSize].grade = show_Grade(&list[listSize]);
			listSize++;//�л��� �߰������Ƿ� listSize ���� 
			break;//switch-case�� �������� 
	
		case 2://�޴���ȣ�� 2�� ���(�л� �˻�)
			
			printf("�˻��� �л��̸��� �Է����ּ���: ");//�˻��� �л��� �̸��� �Է��϶�� �޽��� ��� 
			scanf_s(" %s", name, LENGTH);//LENGTH������ũ�⸦ �ִ�� �ϴ� �л��� �̸��� �Է¹��� 
			for (int i = 0; i < listSize; i++) { //listSizeũ�⸸ŭ for���� ���� 
				if (strcmp(name, list[i].studentName) == 0) {//�Է¹��� �л��� �̸��� list�� ���� ���� �ִ��� list�� �ε����� ó������ Ȯ���ϸ� ������ Ȯ�� 
					searchIndex = i;//������ searchIndex ���� i�� ���� 
					flag = 1;//�˻��� �л��� ã�����Ƿ� flag�� 1�� �ٲ۴�.
					break;//for�� �������� 
				}
			}
			if (flag == 0) { //for���� ������������ flag 0�� ���� �˻��� �л��� ã�� ���Ѱ� 
				printf("�Է��� �̸��� �л��� �������� �ʽ��ϴ�.\n");//�˻��� �л��� ã�� ���ߴٴ� �޽��� ��� 
				break;//switch-case�� �������� 
			}
			//�˻��� �л��� ã���� ���
			show_studentInfo(&list[searchIndex]);//�˻��� �л��� ������ ����ϴ� �޼ҵ� ȣ��
			break;//switch-case�� �������� 

		case 3://�޴���ȣ�� 3�� ���(���� ����) 
			if (listSize == 0) {//list�� ũ�Ⱑ ���� 0�ΰ��
				printf("��ϵ� �л��� ������ �����ϴ�\n");//��ϵ� �л��� ������ ���ٴ� �޽��� ��� 
			}
			
				printf("�˻��� ������ �Է����ּ���(����/����/����): ");//�˻��� ���� �Է��϶�� �޽��� ���
				scanf_s("%s", subject, LENGTH);//�˻��� ���� �Է¹��� 
				if (strcmp(subject, "����") == 0) {//�˻��� �����̸��� ������ ���
					printf("�л��̸�   ����\n");//�л��̸��� ���� ��� 
					
					for (int j = 0; j < listSize; j++) {//list�� ũ�⸸ŭ for���� ���� 
						show_Korean(arr,&list[j],j); //listũ�⸸ŭ �ش� �޼ҵ� ȣ��(�л��� �̸��� ������� ���� ���)
					}		

					int max = show_Max(arr, listSize);// Ư������ �ִ� ������ �ε������� max�� ����
					int min = show_Min(arr, listSize);// Ư������ �ּ� ������ �ε������� min�� ����

					//1���л�,�ְ�����,1���л�����,���������� ���� 
					strcpy(korean.firstStudent, list[max].studentName);//max�ε����� list �л��̸��� SUBJECT����ü ���� korean�� firstStudent�� ���� 
					korean.max=list[max].koreanScore;//max�ε����� list ���������� SUBJECT����ü ���� korean�� max�� ����
					korean.firstStudentScore=list[max].koreanScore;//max�ε����� list ���������� SUBJECT����ü ���� korean�� firstStudentScore�� ����
					korean.min= list[min].koreanScore;//min�ε����� list ���������� SUBJECT����ü ���� korean�� min�� ����

					printf("�ִ� ����: %d\n", korean.max);//�ִ� ���� ���
					printf("�ּ� ����: %d\n", korean.min); //�ּ� ���� ��� 
					printf("1�� �л� �̸�: %s ����: %d \n", korean.firstStudent, korean.firstStudentScore);//1�� �л��̸��� ���� ��� 
					break;
				}
				else if (strcmp(subject, "����") == 0) {//�˻��� ������ ������ ��� 
					printf("�л��̸�   ����\n");//�л��̸��� ���� ��� 
				
					for (int j = 0; j < listSize; j++) {//list�� ũ�⸸ŭ for���� ���� 
						show_Math(arr,&list[j],j);//listũ�⸸ŭ �ش� �޼ҵ� ȣ��(�л��� �̸��� ���а��� ���� ���)
					}	
					
					int max = show_Max(arr, listSize);// Ư������ �ִ� ������ �ε������� max�� ����
					int min = show_Min(arr, listSize);// Ư������ �ּ� ������ �ε������� min�� ����

					strcpy(math.firstStudent, list[max].studentName);//max�ε����� list �л��̸��� SUBJECT����ü ���� math�� firstStudent�� ���� 
					math.max= list[max].mathScore;//max�ε����� list ���������� SUBJECT����ü ���� math�� max�� ����
					math.firstStudentScore=list[max].mathScore;//max�ε����� list ���������� SUBJECT����ü ���� math�� firstStudentScore�� ����
					math.min=list[min].mathScore;//min�ε����� list ���������� SUBJECT����ü ���� english�� min�� ����

					printf("�ִ� ����: %d\n", math.max);//�ִ� ���� ��� 
					printf("�ּ� ����: %d\n", math.min);//�ּ� ���� ��� 
					printf("1�� �л� �̸�: %s ����: %d \n", math.firstStudent, math.firstStudentScore);//1�� �л��̸��� ���� ��� 
					break;
				}
				else if (strcmp(subject, "����") == 0) {//�˻��� ������ ������ ��� 
					printf("�л��̸�   ����\n");//�л��̸��� ���� ��� 
					
					for (int j = 0; j < listSize; j++) {//list�� ũ�⸸ŭ for���� ����
						show_English(arr,&list[j],j);//listũ�⸸ŭ �ش� �޼ҵ� ȣ��(�л��� �̸��� ������� ���� ���)
					}
					int max = show_Max(arr, listSize);// Ư������ �ִ� ������ �ε������� max�� ����
					int min = show_Min(arr, listSize);// Ư������ �ּ� ������ �ε������� min�� ����

					strcpy(english.firstStudent, list[max].studentName);//max�ε����� list �л��̸��� SUBJECT����ü ���� english�� firstStudent�� ���� 
					english.max=list[max].englishScore;//max�ε����� list ���������� SUBJECT����ü ���� english�� max�� ����
					english.firstStudentScore=list[max].englishScore;//max�ε����� list ���������� SUBJECT����ü ���� english�� firstStudentScore�� ����
					english.min= list[min].englishScore;//min�ε����� list ���������� SUBJECT����ü ���� english�� min�� ����
					
					printf("�ִ� ����: %d\n",english.max);//�ִ� ���� ��� 
					printf("�ּ� ����: %d\n",english.min );//�ּ� ���� ��� 
					printf("1�� �л� �̸�: %s ����: %d \n", english.firstStudent, english.firstStudentScore);//1�� �л��̸��� ���� ��� 
				}
				else {//�˻��� ������ ����,����,��� �ƴ� ��� 
					printf("��ϵǾ� ���� ���� �����Դϴ� \n");//������ �߸��Ǿ��ٴ� �޽��� ��� 
					
				}
			
			break;//switch-case�� ��������
		case 4://�޴���ȣ�� 4�ϰ��(����Ʈ ��ü ���)
			printf("<<<��ü �л��� ������ ����մϴ�>>>\n");//��ü �л��� ���� ��� 
			printf("�̸�         ����       ����       ����        �հ�      ���       ���\n");//���� ǥ���� �͵� ��� 
			for (int i = 0; i < listSize; i++) {//list ũ�⸸ŭ for�� ���� 
				printf("%-13s %-10d %-10d %-10d %-10d %-10d %-10c\n",
					list[i].studentName, list[i].koreanScore, list[i].mathScore, list[i].englishScore, list[i].sum, list[i].average, list[i].grade);
				//STUDENT ����ü �迭list�� ����� �����Ͽ� �ε��� 0���� ����Ʈ ������ �л��� ������ ���� ��� 
			}
			break;//switch-case�� ��������
		case 5:	//�޴���ȣ�� 5�ϰ��(���α׷� ����)	
			printf("���α׷��� �����Ͻðڽ��ϱ�?(y/n): ");//�׷��� �ѹ� ������� ���� ��� 
			scanf_s(" %c", &answer);//y�Ǵ� n �Է¹��� 
			if (answer == 'y') {//'y' �Է½� ����, �ƴҽ� ��� ���α׷� ���� 
				exit();//���α׷� �����Ѵٴ� �� 
			}
			break;//switch-case�� �������� 
		default: //1~5 �ܿ� �ٸ� ���ڸ� �Է����� ��� 
			printf("�߸��� �޴���ȣ�Դϴ�\n");//�߸��� �޴���ȣ��� �޽��� ���
			
		}
	};
	return 0; 
}

//�б� ���� ����ü �����͸� �Ű������� �޾�  �л� ���� ��� 
void show_studentInfo(const STUDENT*p) {
	printf("�̸�         ����       ����       ����       �հ�       ���      ���\n");//����� ���� ǥ�� 
	printf("%-13s %-10d %-10d %-10d %-10d %-10d %-10c\n",
		p->studentName,p->koreanScore,p->mathScore,p->englishScore,p->sum,p->average,p->grade);
	//������ p�� ����Ű�� STUDENT ������ ����� ���� ��� 
}
//�Է¹��� ����ü �����͸� �̿��Ͽ� Ư�� STUDENT ������ ��� ���Ѵ�.
char show_Grade(STUDENT* p) {
	if (p->average >= 90) {//������ p�� ����Ű�� average���� 90 �̻��� ��� 
		p->grade = 'A';//������ p�� ����Ű�� grade�� A ���� 
	}
	else if (p->average >= 80 && p->average < 90) {//������ p�� ����Ű�� average���� 80 �̻� 90 �̸��� ��� 
		p->grade = 'B';//������ p�� ����Ű�� grade�� B ���� 
	}
	else if (p->average >= 70 && p->average < 80) {//������ p�� ����Ű�� average���� 70 �̻� 80 �̸��� ���
		p->grade = 'C';//������ p�� ����Ű�� grade�� C ���� 
	}
	else if (p->average >= 60 && p->average < 70) {//������ p�� ����Ű�� average���� 60 �̻� 70 �̸��� ���
		p->grade = 'D';//������ p�� ����Ű�� grade�� D ���� 
	}
	else {// //������ p�� ����Ű�� average���� 60 �̸��� ���
		p->grade = 'F';//������ p�� ����Ű�� grade�� F ���� 
	}
	return p->grade;//������ p�� ����Ű�� grade�� ���� 
}
//��������� �л��̸��� ���� ����ϴ� �Լ�
void show_Korean(int arr[], STUDENT* p,int index) {

	int* Array = arr;//�����͸� Array�� arr�� �ּ� ����Ŵ
	printf("%-11s %d\n", p->studentName, p->koreanScore);//���ڷ� ���� ����ü�����Ͱ� ����Ű�� �л��̸��� �������� ���
	Array[index] = p->koreanScore;//arr�� �ش� ������ �־��� 
	
}
//���а����� �л��̸��� ���� ����ϴ� �Լ�
void show_Math(int arr[], STUDENT* p,int index) {

	int* Array = arr;//�����͸� Array�� arr�� �ּ� ����Ŵ
	printf("%-11s %d\n", p->studentName, p->mathScore);//���ڷ� ���� ����ü�����Ͱ� ����Ű�� �л��̸��� �������� ���
	Array[index] = p->mathScore;//arr�� �ش� ������ �־��� 
	
}
//��������� �л��̸��� ���� ����ϴ� �Լ�
void show_English(int arr[], STUDENT* p,int index) {

	int* Array = arr;//�����͸� Array�� arr�� �ּ� ����Ŵ
	printf("%-11s %d\n", p->studentName, p->englishScore);//���ڷ� ���� ����ü�����Ͱ� ����Ű�� �л��̸��� �������� ���	
	Array[index] = p->englishScore;//arr�� �ش� ������ �־���
}

//�Ű������� ���� �迭�� �ִ��� ���� �ε����� ���ϴ� �Լ� 
int show_Max(int arr[],int size) {
	int max = 0;//�迭�� �ִ밪�� ���� �ε����� ������ ���� 
	for (int i = 1; i < size; i++) {//1���� �迭������ for���� ����
		if (arr[max] < arr[i]) {//max�ε����� �迭������ �ش� i�ε����� �迭���� ū ���
			max = i ;//�׶��� i�� max�� ��
		}
	}
	return max;//�ִ밪�� ���� �ε��� max�� ��ȯ
}

//�Ű������� ���� �迭�� �ּڰ��� ���� �ε����� ���ϴ� �Լ�
int show_Min(int arr[],int size) {
	int min = 0;//�迭�� �ּڰ��� ���� �ε����� ������ ���� 
	for (int i = 1; i < size; i++) {//1���� �迭������ for���� ����
		if (arr[min] > arr[i]) {//min�ε����� �迭������ �ش� i�ε����� �迭���� �� ���� ���
			min = i;//�׶��� i�� min�� ��
		}
	}
	return min;//�ּڰ��� ���� �ε��� min�� ��ȯ
}
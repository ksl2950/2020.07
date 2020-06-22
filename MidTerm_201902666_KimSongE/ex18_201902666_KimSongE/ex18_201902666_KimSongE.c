/*
���α׷��� : ex18_201902666_KimSongE
����: �־��� ����� ���� �ڽ��� �÷��̸���Ʈ�� �ִ� 5������ ���� �߰��ϴ� ���α׷� 
�ۼ��Ͻ� : 2020/05/31
�ۼ��� :��ǻ�������к� 201902666 �����
*/

#include <stdio.h>//ǥ�� ����� ���̺귯�� 
#define MAX 5 //�ִ� 5���� ���� ��ϰ����ϹǷ� �ִ� �� ���� ��ũ�λ���� ����
#define STR_SIZE 20 //�� ����, ��Ƽ��Ʈ �̸�, �帣�� ���ڿ� �ִ� ũ�⸦ ��ũ�� ����� ����

//� ���� ������ ����� �����ϴ� ����ü song
typedef struct song {
	char title[STR_SIZE];//�� ����
	char artist[STR_SIZE];//��Ƽ��Ʈ �̸�
	char genre[STR_SIZE];//�� �帣
	int playingTime;//�� ��� �ð� 

}SONG;//����ü���� SONG

int main(void) {
	//SONG ����ü �迭 arr[] �� �������� �����ϰ� �ִ�.
	//���ʿ������� ������,��Ƽ��Ʈ�̸�,�� �帣,������ð� ������ �ʱ�ȭ 
	SONG arr[] = { { "thank u, next","Ariana Grande","pop",208 },
					{"Attention","Charile Puth","pop",211},
					{"�� ���� ����","�ں���","balad",316},
					{"How Long","Charile Puth","pop",198},
					{"����","��ź�ҳ��","hip-hop",274},
					{"�Ƴ���","MINO","hip-hop",241},
					{"unlucky","������","rock-metal",232}
	}; // �� 7���� �������� ������ ����

	int size = sizeof(arr) / sizeof(arr[0]);//����ü �迭�� ũ�⸦ size�� ����
	int songNum;//�÷��̸���Ʈ�� �߰��� ���ȣ�� ������ ����
	SONG* playList[MAX] = { NULL };//SONG ����ü ������ playList�� NULL�� �ʱ�ȭ
	int count = 0;//�÷��̸���Ʈ�� ����ִ� �� ������ ���� ����
	int total = 0;//�÷��̸���Ʈ�� ����� ��ü �� ����ð��� ������ ����
	

		printf("   ����              ��Ƽ��Ʈ          �帣       ����ð�\n");//����� ��� ������ Ÿ��Ʋ ���
		for (int i = 0; i < size; i++) {//for���� arr�迭ũ�⸸ŭ ������. 
			printf("%d: %-15s %-19s %-12s %-10d\n",
				i+1,arr[i].title, arr[i].artist, arr[i].genre, arr[i].playingTime);
		} //�迭�� ����ִ� ��ü ������ ��� 
		printf("============================================================\n");//��輱 ��� 
		//do while���� �̿��Ͽ� ��� �ѹ��� �ݺ��������ڵ尡 ����ɼ� �ֵ����� 
		do {
			printf("�÷��̸���Ʈ�� �߰��� �� ��ȣ?");//�߰��� ���ȣ�� �Է��϶�� �޽��� ���
			scanf_s("%d", &songNum);//�� ��ȣ �Է¹���
			if (songNum > size||songNum==0) {//���� �������� ��ȣ�� �ƴ�  �߸��� ��ȣ�� �Է¹��� ���
				printf("�߸��� �� ��ȣ�Դϴ�\n"); //�߸��� ���ȣ��� �޽��� ���
				continue;//�ٽ� do�� �� ó������ �̵� 
			}
			playList[count] = &arr[songNum - 1];//�迭�� �ε����� 0���� �����̹Ƿ� �Է¹�����ȣ-1�� �迭�ּҸ� playList�� ����
			count++;//playList�� ���� �߰��Ǿ����Ƿ� count ���� 
			printf("<<�÷��̸���Ʈ>>\n");//�÷��̸���Ʈ ������� �˸��� ���
			for (int i = 0; i < count; i++) {//�÷��̸���Ʈ �����ŭ for�� ����
				printf("%-20s %-20s %-15s %-10d\n",
					playList[i]->title, playList[i]->artist, playList[i]->genre, playList[i]->playingTime);
				total += playList[i]->playingTime;//��ü ����ð��� �����ֱ����� for�� �ѹ� �������� �ش� �� ����ð� total�� �߰�
			}//playList�� ����� �� �����ּҸ� �̿��Ͽ� ����� �� ���� ���� ���
			printf("�� ����ð� : %d��\n",total);//total�� ����� �� �� ����ð� ���
			total = 0;//total �ٽ� 0���� �ʱ�ȭ
			if (playList[MAX - 1] != NULL) { //playList�� 5���� ���� �� �����
				printf("<<<5���� ���� ����Ͽ� ���α׷��� �����մϴ�>>>");//���α׷� ����޽��� ���
			}
		} while (playList[MAX - 1]== NULL); //���� �߰��Ǵ� playList�� ������ 4�ε����� ���� ä������ �ݺ��� ���� 
	
	return 0;
}
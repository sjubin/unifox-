#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <conio.h>

#include <windows.h>

#define word 30 // �ܾ� ����

#define lenght 30 // �ܾ� ����



char ran2[word][lenght] = {

"love","school","hat","important","natural",

"soccer","alive","control","perfect","happy",

"setting","exercise","angel","different","challenge",

"unifox","provide","injure","infect","better",

"sound","game","banana","eye","climb",

"negative","friend","especially","excited","ocean",


};




int i;//�ݺ��� i

int same = 0, temp = 0;//��ȯ�� ����

int life_time = 10;//���� ��ȸ 10��

char some[27];//�����ϳ�

char ran[lenght] = "";//�ܾ� ���� ������ ����

char fil[lenght] = "";//�ܾ� ������ �˷���

char answer;// ��밡�� �Է��� ���ĺ�



void Print();//�Լ�



int main() {

	srand(time(NULL));                                  // �ð����� �����Լ�

	strcpy(ran, ran2[rand() % word]);                         // rand�� �迭�� ����� �� �� �ϳ��� �������� �����´�.

	for (i = 0; i < strlen(ran); i++)
		fil[i] = '_';                                         // �������� ������ �ܾ� ���̸�ŭ _ �� ���

	while (1) {                                        //�ݺ��� ������

		while (1) {        //�ݺ��� ������

			system("cls"); // ������ �Է��ߴ� �۾��� ������

			printf("life_time : %d\n", life_time);//���� ���� ����

			Print();

			printf("�Է��ߴ� ���ĺ� : ");

			for (i = 0; i < strlen(some); i++)
				printf("%c ", some[i]);

			puts("");//���ڿ� ���

			printf("���ĺ� �Է� : ", life_time);

			fflush(stdin);// �Է� ���� �ȿ� �����ϴ� �����͸� ���� ��� �����մϴ�.

			scanf("%c", &answer);// ������� ���ĺ� �Է¹ޱ�

			for (i = 0, temp = 0; i < strlen(some); i++)
				if (some[i] == answer) // ���� �Է��� ���ڿ� ������ �Է��� ���ڰ� ���ٸ�
					temp = 1; //temp�� 1�� ����

			if (temp == 1) //����
			{
				printf("�Է��ߴ� ���ĺ��Դϴ�.\n");
				getch();
			}
			else if (answer >= 48 && answer <= 57)
			{
				printf("��ȣ�� �ƴմϴ�.");
				getch();
			}

			else
			{
				some[strlen(some)] = answer;

				break;

			}

		}


		for (i = 0, temp = 0; i < strlen(ran); i++) {

			if (ran[i] == answer && fil[i] != answer) {

				fil[i] = answer;

				same++;
				temp++;

			}

		}

		if (temp == 0)

			life_time--;

		if (same == strlen(ran)) // �ܾ �����

			break;

		if (life_time == 0) //���� ����� �� ��ٸ�
		{
			puts("Game Over"); //Game Over �ֱ�
			printf("������ %s�Դϴ�.\n", ran); // �������� ���� �ܾ ����

			return 0;

		}

	}

	system("cls");

	Print();

	printf("�����Դϴ�!!\n");



	return 0;

}



void Print() // ����Ʈ �Լ�
{

	printf("��");

	for (i = 0; i < strlen(ran); i++)
		printf("����");//���ڼ��� �°� ������ �ø���.

	printf("��\n");

	printf("��");

	for (i = 0; i < strlen(ran); i++) {

		printf("%c ", fil[i]); //66�ٿ� �ִ� �� ��ŭ ���

	}

	printf("��\n");

	printf("��");

	for (i = 0; i < strlen(ran); i++)
		printf("����");//���ڼ��� �°� ������ �ø���.

	printf("��\n");

}


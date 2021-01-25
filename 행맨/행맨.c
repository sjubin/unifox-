#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <conio.h>

#include <windows.h>

#define word 30 // 단어 갯수

#define lenght 30 // 단어 길이



char ran2[word][lenght] = {

"love","school","hat","important","natural",

"soccer","alive","control","perfect","happy",

"setting","exercise","angel","different","challenge",

"unifox","provide","injure","infect","better",

"sound","game","banana","eye","climb",

"negative","friend","especially","excited","ocean",


};




int i;//반복문 i

int same = 0, temp = 0;//변환할 값과

int life_time = 10;//생명 기회 10번

char some[27];//문자하나

char ran[lenght] = "";//단어 선택 랜덤한 길이

char fil[lenght] = "";//단어 갯수를 알려줌

char answer;// 사용가자 입력한 알파벳



void Print();//함수



int main() {

	srand(time(NULL));                                  // 시간마다 랜덤함수

	strcpy(ran, ran2[rand() % word]);                         // rand에 배열에 저장된 값 중 하나를 랜덤으로 가져온다.

	for (i = 0; i < strlen(ran); i++)
		fil[i] = '_';                                         // 랜덤으로 선택한 단어 길이만큼 _ 를 출력

	while (1) {                                        //반복문 돌리기

		while (1) {        //반복문 돌리기

			system("cls"); // 그전에 입력했던 작업을 지워줌

			printf("life_time : %d\n", life_time);//생명 남은 갯수

			Print();

			printf("입력했던 알파벳 : ");

			for (i = 0; i < strlen(some); i++)
				printf("%c ", some[i]);

			puts("");//문자열 출력

			printf("알파벳 입력 : ", life_time);

			fflush(stdin);// 입력 버퍼 안에 존재하는 데이터를 비우는 즉시 삭제합니다.

			scanf("%c", &answer);// 사용자의 알파벳 입력받기

			for (i = 0, temp = 0; i < strlen(some); i++)
				if (some[i] == answer) // 현재 입력한 문자와 저번에 입력한 문자가 같다면
					temp = 1; //temp에 1을 저장

			if (temp == 1) //만약
			{
				printf("입력했던 알파벳입니다.\n");
				getch();
			}
			else if (answer >= 48 && answer <= 57)
			{
				printf("기호가 아닙니다.");
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

		if (same == strlen(ran)) // 단어를 맞출시

			break;

		if (life_time == 0) //만약 목숨을 다 썼다면
		{
			puts("Game Over"); //Game Over 넣기
			printf("정답은 %s입니다.\n", ran); // 랜덤으로 정한 단어를 공개

			return 0;

		}

	}

	system("cls");

	Print();

	printf("정답입니다!!\n");



	return 0;

}



void Print() // 프린트 함수
{

	printf("┏");

	for (i = 0; i < strlen(ran); i++)
		printf("━━");//글자수에 맞게 ━━을 늘린다.

	printf("┓\n");

	printf("┃");

	for (i = 0; i < strlen(ran); i++) {

		printf("%c ", fil[i]); //66줄에 있는 것 만큼 출력

	}

	printf("┃\n");

	printf("┗");

	for (i = 0; i < strlen(ran); i++)
		printf("━━");//글자수에 맞게 ━━을 늘린다.

	printf("┛\n");

}


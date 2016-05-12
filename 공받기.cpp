#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Screen.c"
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)

enum ControlKeys
{
	SPACE = 32,
	LEFT = 75,
	RIGHT = 77
};

typedef struct _GOAL
{
	int gMoveX, gMoveY;
	int gLength; //����� ���� 
	int gLineX[9]; //����� ���ν� ��ǥ 
	int gDistance; // ��� �̵��Ÿ� 
	clock_t MoveTime;
	clock_t OldTime;
} GOAL;


typedef struct _Ball
{
	int ReadyB; // 1 = �غ�, 0 = �� 
	int bMoveX, bMoveY; //�� �̵� ��ǥ
	clock_t MoveTime; // �̵��� �ɸ� �ð�
	clock_t OldTime; // ���� �̵��ð� 
} BALL;

typedef struct _Player
{
	int CenterX, CenterY; //X, Y ��ǥ ���� 
	int MoveX, MoveY; // X, Y ��ǥ �̵� 
	int X, Y; // X, Y ���� ��� ��ǥ �� 
	int Index; // �߽���ǥ�� �ε��� 
} PLAYER;

typedef struct _Position
{
	int X, Y; // X, Y ���� ��ǥ 
} Position;

GOAL Goal;
BALL Ball;
PLAYER Player;
char strPlayer[] = { "|__��__|" }; //ĳ����
int Length; // ���ΰ� ĳ���� ����
int BallCount = 0;
// �ʱ�ȭ
void Init() {

	Player.CenterX = 3; //���ΰ� X �߽� ��ǥ
	Player.CenterY = 0; //���ΰ� Y �߽� ��ǥ 
	Player.MoveX = 20; // ���ΰ� �̵� ����ǥ �ʱ�ȭ
	Player.Y = Player.MoveY = 22; // ���ΰ� �̵� Y��ǥ �ʱ�ȭ
	Player.X = Player.MoveX - Player.CenterX; //���ΰ� ĳ���� ��� ��ǥ
	Length = strlen(strPlayer); //���ΰ� ��ü ����

	Ball.ReadyB = 1;
	Ball.bMoveX = Player.MoveX;
	Ball.bMoveY = Player.MoveY - 1;
	Ball.MoveTime = 100;

	int gLength, i;

	Goal.gMoveX = 20;
	Goal.gMoveY = 2;
<<<<<<< HEAD:슛골인/공받기.cpp
	Goal.gLength = 3; // ��� ���� = gLength * 2 + 1 
=======
	Goal.gLength = 2;
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
	Goal.MoveTime = 100;
	Goal.OldTime = clock();
	Goal.gDistance = 1;
	gLength = Goal.gLength * 2 + 1;
	for (i = 0; i < gLength; i++) {
		Goal.gLineX[i] = Goal.gMoveX + 2 * (i + 1);
	}
}
// ������ ����
void Update()
{
	clock_t CurTime = clock();
	int gLength = Goal.gLength * 2 + 1;
	int i;
<<<<<<< HEAD:슛골인/공받기.cpp



	if ((CurTime - Goal.OldTime) > Goal.MoveTime)
=======
	int BallCount = 0;
	
	if(Ball.ReadyB == 0) {//�̵����� ���
		if ((CurTime - Ball.OldTime) > Ball.MoveTime)
	 		{
			 if(Ball.bMoveY - 1 > 0){
	 			Ball.bMoveY--;
	 			Ball.OldTime = CurTime;
		 	}else{
			 	Ball.ReadyB = 1;
			 	Ball.bMoveX = Player.MoveX;
			 	Ball.bMoveY = Player.MoveY - 1;
			  }
             }
		}else{
		Ball.bMoveX = Player.MoveX;
	}
	
	if((CurTime - Goal.OldTime) > Goal.MoveTime)
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
	{
		Goal.OldTime = CurTime;
		if (Goal.gMoveX + Goal.gDistance >= 0 && ((Goal.gLineX[gLength - 1] + 3) + Goal.gDistance) <= 79)
		{
			Goal.gMoveX += Goal.gDistance;
			for (i = 0; i < gLength; i++)
			{
				Goal.gLineX[i] = Goal.gMoveX + 2 * (i + 1);
			}
		}
		else {
			Goal.gDistance = Goal.gDistance * (-1); // ����ٲٱ� 
		}
	}

	if (Ball.ReadyB == 0) //���̵��� 
	{
		if ((CurTime - Ball.OldTime) > Ball.MoveTime) {
			if (Ball.bMoveY - 1 > 0) {
				Ball.bMoveY--;
				Ball.OldTime = CurTime;

				//����Ƕ��ΰ� �浹 
<<<<<<< HEAD:슛골인/공받기.cpp
				if (Ball.bMoveX >= Goal.gLineX[0] && Ball.bMoveX + 1 <= Goal.gLineX[gLength - 1]) {
					if (Ball.bMoveY <= Goal.gMoveY) {//�� �ʱ�ȭ 
=======
				if(Ball.bMoveX >= Goal.gLineX[0] && Ball.bMoveX + 1 <= Goal.gLineX[gLength - 1]){
					if(Ball.bMoveY <= Goal.gMoveY) //�� �ʱ�ȭ 
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
						Ball.ReadyB = 1;
						Ball.bMoveY = Player.MoveY - 1;
<<<<<<< HEAD:슛골인/공받기.cpp
						BallCount++; //����
					}
					//��� �浹 
				}
				else if ((Ball.bMoveX >= Goal.gLineX[0] - 2 && Ball.bMoveX <= Goal.gLineX[0] - 1) || (Ball.bMoveX + 1 >= Goal.gLineX[0] - 2) && (Ball.bMoveX + 1 <= Goal.gLineX[0] - 1) || (Ball.bMoveX >= Goal.gLineX[gLength - 1]) + 2 && (Ball.bMoveX <= Goal.gLineX[gLength - 1] + 3) || (Ball.bMoveX + 1 >= Goal.gLineX[gLength - 1]) + 2 && (Ball.bMoveX + 1 <= Goal.gLineX[gLength - 1] + 3)) {
					if (Ball.bMoveY <= Goal.gMoveY) {
						Ball.ReadyB = 1;
=======
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
						Ball.bMoveX = Player.MoveX;
						BallCount++; //����
						printf("����!");
					}
<<<<<<< HEAD:슛골인/공받기.cpp
				}
			}
			else {
				Ball.ReadyB = 1;
				Ball.bMoveX = Player.MoveX;
				Ball.bMoveY = Player.MoveY - 1;
			}
		}
	}
	else {
		Ball.bMoveX = Player.MoveX;
	}
}
=======
					//��� �浹 
			}else if((Ball.bMoveX >= Goal.gLineX[0] - 2 && Ball.bMoveX <= Goal.gLineX[0] - 1) || (Ball.bMoveX + 1 >= Goal.gLineX[0] - 2) && (Ball.bMoveX + 1 <= Goal.gLineX[0] - 1) || (Ball.bMoveX >= Goal.gLineX[gLength - 1]) + 2 && (Ball.bMoveX <= Goal.gLineX[gLength - 1] + 3) || (Ball.bMoveX + 1 >= Goal.gLineX[gLength - 1]) + 2 && (Ball.bMoveX + 1 <= Goal.gLineX[gLength - 1] + 3)){
				if(Ball.bMoveY <= Goal.gMoveY){
					Ball.ReadyB = 1;
					Ball.bMoveX = Player.MoveX;
					Ball.bMoveY = Player.MoveY - 1;
				}
			}else {
				Ball.ReadyB = 1;
				Ball.bMoveX = Player.MoveX;
				Ball.bMoveY = Player.MoveY - 1;
			}
				
		}
	}else{
		Ball.bMoveX = Player.MoveX;
	}
 } 


>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
// ���
void Render()
{
	char string[100] = { 0 };
	ScreenClear();
	int gLength, i;
	// ��� ����

	// �¿쿡 ���� ���� (Ŭ����) 

	if (Player.X < 0)
		ScreenPrint(0, Player.MoveY, &strPlayer[Player.X * (-1)]);
	else if (Player.MoveX + (Length - Player.MoveX + Player.CenterX + 1) > 79)
	{
<<<<<<< HEAD:슛골인/공받기.cpp
		strncat(string, strPlayer, Length - ((Player.MoveX + Player.CenterX + 1) - 79));
		ScreenPrint(Player.X, Player.Y, string);
	}
	else {
		ScreenPrint(Player.X, Player.Y, strPlayer);
	}

	ScreenPrint(Ball.bMoveX, Ball.bMoveY, "��");
	sprintf(string, "���ΰ� �̵���ǥ : %d, %d              �� �� : %d               �ʱ�ȭ : R ��ư ", Player.MoveX, Player.Y, BallCount);
=======
		strncat_s(string, strPlayer, Length - ((Player.MoveX + Player.CenterX + 1) - 79));	
	 	ScreenPrint(Player.X, Player.Y, string);
	 }else{
		ScreenPrint(Player.X, Player.Y, strPlayer);
	}
	
	ScreenPrint(Ball.bMoveX, Ball.bMoveY, "��");
	sprintf_s(string, "���ΰ� �̵���ǥ : %d, %d", Player.MoveX, Player.Y);
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
	ScreenPrint(0, 0, string);


	//��� ��� 

	ScreenPrint(Goal.gMoveX, Goal.gMoveY, "��");
	gLength = Goal.gLength * 2 + 1;

	for (i = 0; i < gLength; i++)
		ScreenPrint(Goal.gLineX[i], Goal.gMoveY, "��");

	ScreenPrint(Goal.gLineX[gLength - 1] + 2, Goal.gMoveY, "��");

	//��� ��
<<<<<<< HEAD:슛골인/공받기.cpp


	ScreenFlipping();
}

//����

void Release()
{
}


int main(void) {
	int Key, Remain;
=======
    		
	
	ScreenFlipping(); 
 }
 
    //����
 
 void Release()
 {
  }
  
  
int main (void){

	int Key, Remain;
	clock_t CurTime, OldTime;
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp

	ScreenInit();
	Init(); // �ʱ�ȭ

	while (1) //���ѹݺ� 
	{
		if (_kbhit())
		{
			Key = _getch();
			if (Key == 'q')
				break;
			switch (Key)
			{
<<<<<<< HEAD:슛골인/공받기.cpp
			case LEFT:
				if (Player.MoveX > 0) {
					Player.MoveX--;
					Remain = Length - (Player.CenterX + 1); // �������� = ��ü ���� - (�߽���ǥ + 1)
					if (Player.MoveX + Remain > 79 || Player.MoveX - Player.CenterX < 0)
						Player.MoveX--;
					Player.X = Player.MoveX - Player.CenterX;
				}
				break;
			case RIGHT:
				if (Player.MoveX + 1 < 79) {
					Player.MoveX++;
					Remain = Length - (Player.CenterX + 1);
					if (Player.MoveX + Remain >79 || Player.MoveX - Player.CenterX < 0)
=======
				case LEFT :
					if(Player.MoveX > 0){
					Player.MoveX--; 
					Remain =  Length - (Player.CenterX); // �������� = ��ü ���� - (�߽���ǥ + 1)
					if(Player.MoveX + Remain > 79 || Player.MoveX - Player.CenterX - 1 < 0)
						Player.MoveX--;
					Player.X = Player.MoveX - Player.CenterX;
					}
					break;
				case RIGHT :
					if(Player.MoveX + 1< 79){
					Player.MoveX++;
					Remain = Length - (Player.CenterX);
					if(Player.MoveX + Remain >79 || Player.MoveX - Player.CenterX < 0)
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp
						Player.MoveX++;
					Player.X = Player.MoveX - Player.CenterX;
				}
				break;
			case SPACE:
				if (Ball.ReadyB)
				{
					Ball.bMoveX = Player.MoveX;
					Ball.bMoveY = Player.MoveY - 1;
					Ball.OldTime = clock();
					Ball.ReadyB = 0;
				}
				break;
			case 'r':
				if (BallCount != 0)
				{
					BallCount = 0;
					Ball.ReadyB = 1;
					Ball.bMoveX = Player.MoveX;
					Ball.bMoveY = Player.MoveY - 1;
				}
				break;
			}
		}

		Update();//������ ���� 
		Render(); //ȭ�� ��� 
<<<<<<< HEAD:슛골인/공받기.cpp

	}

	Release();
	ScreenRelease();
	return 0;
}
=======
		
		OldTime = clock();

		while (1)
		{
			CurTime = clock();
			if (CurTime - OldTime > 20)
			{
				OldTime = CurTime;
				break;
			}
		}//���ð�
	 } 
	 
	 Release();
	 ScreenRelease();
	 return 0;
}
>>>>>>> 8db8968ed5b14923f3f4ff070dcb587be84b5187:공받기.cpp

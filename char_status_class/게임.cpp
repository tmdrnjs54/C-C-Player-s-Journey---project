#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int choise;

void main()
{
home:
	system("cls");
	printf_s("�� �Դϴ�\n\n");
	printf("1. ���ڱ� \n\n2. ��Ա�\n\n9. �̵��ϱ�\n\n");
	scanf_s("%d", &choise);
	switch (choise)
	{
	case(1) :
		system("cls");
		system("PAUSE");
		goto home;
	case(2) :
		system("cls");
		system("PAUSE");
		goto home;
	case(9) :
		system("cls");
		printf("���� �̵��Ͻðٽ��ϱ�?\n\n");
		printf("1. �б�\n\n2. ���ư���\n ");
		scanf_s("%d", &choise);
		switch (choise)
		{
		case(1) :
			printf("�б��� ������... \n");
			system("PAUSE");
			goto school;
		case(2) :
			goto home;
		}
	}

school:
	system("cls");
	printf_s("�б��Դϴ�\n\n");
	printf("1. ���氡��\n\n2. ���絿����\n\n3. ����4ȣ������\n\n4. ������ ����\n\n5. �ƶ�Ȧ\n\n9. �̵��ϱ�");
	scanf_s("%d", &choise);
	switch (choise)
	{
	case(1) :
		printf(" ������ ����");
		system("PAUSE");
		goto club;
	case(2) :
		printf("���絿�� ����");
		system("PAUSE");
		goto classroom;
	}

club:
	printf_s("���Ƹ����Դϴ�\n\n");
	printf("1. ��Ÿġ��\n\n2. �밡�� ���\n\n3. �ڱ�\n\n4. �ݶ�Ա�\n\n8. �б��ϱ�\n\n");
	scanf_s("%d", &choise);
	switch (choise)
	{
	case(1) :
		goto club;
	case(2) :
		goto club;
	case(3) :
		goto club;
	case(4) :
		goto club;
	case(8) :
		goto school;
	}
classroom:
	printf_s("�����Դϴ�\n\n");
}
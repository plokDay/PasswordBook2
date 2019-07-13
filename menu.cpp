#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ctrl.h"


void MenuP()
{
	char cOp = 0;	//用户操作数
	int nOver = 1;	//判定是否退出程序

	while (nOver)
	{
		printf("欢迎使用密码本\n");
		printf("1.Add\n2.Delete\n3.Alert\n4.Find\n5.ShowAll\n6.Quit\n");
		scanf_s("%c", &cOp, 1);
		switch (cOp)
		{
		case '1':AddP(); break;
		case '2':DeleteP(); break;
		case '3':AlertP(); break;
		case '4':
		{
			FindP();
			system("pause");
		}break;
		case '5':ShowAll(); break;
		case '6':nOver = 0; break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		getchar();
		system("cls");
	}
	
}
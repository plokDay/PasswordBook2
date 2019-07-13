#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"
#include "EncryIO.h"


void ShowAll()
{
	InitP();
	printf("共%d条记录\n------------------------------------------\n", gCount);
	for (int i = 0; i < gCount; i++)
	{
		printf("第%d条记录：\n-------------------------------------------\n", i + 1);
		printf("站点名：%s\n用户名：%s\n密  码：%s\n备  注：%s\n", gPb[i].cWeb, gPb[i].cUser, gPb[i].cPwd, gPb[i].cNote);
		printf("-------------------------------------------\n");
	}


	system("pause");
}
void AddP()
{
	InitP();
	printf("请输入目标站点、用户名、密码、备注信息\n");
	if (gCount>gMax)
	{
		pPWDBOOK pNew = (pPWDBOOK)malloc((gCount +1) * sizeof(PWDBOOK));
		memcpy(pNew, gPb, gCount * sizeof(PWDBOOK));
		free(gPb);
		gPb = pNew;
	}
	scanf_s("%s %s %s %s", gPb[gCount].cWeb, CHM, gPb[gCount].cUser, CHM, gPb[gCount].cPwd, CHM, gPb[gCount].cNote, CHM);
	gCount++;
	SaveP();
	printf("添加成功\n");
}
int FindP()
{
	InitP();
	printf("请输入站点名：\n");
	char cKey[CHM];//关键字
	scanf_s("%s", cKey, CHM);
	int nFd = -1;
	for (int i = 0; i < gCount; i++)
	{
		if (!strcmp(cKey, gPb[i].cWeb))
		{
			nFd = i;
			break;
		}
	}
	if (nFd == -1)
		printf("没有找到\n");
	else
	{
		printf("第%d条符合：\n", nFd + 1);
		printf("-------------------------------------------\n");
		printf("站点名：%s\n用户名：%s\n密  码：%s\n备  注：%s\n", gPb[nFd].cWeb, gPb[nFd].cUser, gPb[nFd].cPwd, gPb[nFd].cNote);
	}
	return nFd;
}
void DeleteP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("无法删除\n");
	else
	{
		for (int i = nIdx; i < gCount - 1; i++)
		{
			strcpy_s(gPb[i].cWeb, CHM, gPb[i + 1].cWeb);
			strcpy_s(gPb[i].cUser, CHM, gPb[i + 1].cUser);
			strcpy_s(gPb[i].cPwd, CHM, gPb[i + 1].cPwd);
			strcpy_s(gPb[i].cNote, CHM, gPb[i + 1].cNote);
		}
		gCount--;

		SaveP();
		printf("删除成功\n");
	}
	system("pause");
}
void AlertP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("无法删除\n");
	else
	{
		printf("-------------------------------------------\n");
		printf("请输入新的用户名、密码、备注\n");
		scanf_s("%s %s %s", gPb[nIdx].cUser, CHM, gPb[nIdx].cPwd, CHM, gPb[nIdx].cNote, CHM);
		SaveP();
		printf("修改成功\n");
	}
	system("pause");
}
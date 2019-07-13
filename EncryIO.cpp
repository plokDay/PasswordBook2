#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "EncryIO.h"
//采用异或加密，每个字符都异或ENC
//将文件中的内容读出到内存并解密
void InitP()
{
	FILE *pFile = nullptr;

	//1.打开
	if (fopen_s(&pFile, "pwd.txt", "ab+"))	//rb+既能读也能写，用w会被覆盖，用r不能从0开始加
		printf("打开文件失败\n");
	//读取并解密
	fseek(pFile, 0, SEEK_END);
	gCount = ftell(pFile) / 200;
	fseek(pFile, 0, SEEK_SET);
	if (gCount>gMax)
	{
		gPb = (pPWDBOOK)malloc(gCount * sizeof(PWDBOOK));
		memset(gPb, 0, gCount * sizeof(PWDBOOK));
		for (int i = 0; i < gCount; i++)
		{
			fread(gPb[i].cWeb, CHM, 1, pFile);
			fread(gPb[i].cUser, CHM, 1, pFile);
			fread(gPb[i].cPwd, CHM, 1, pFile);
			fread(gPb[i].cNote, CHM, 1, pFile);
			for (int j = 0; j < CHM;j++)
			{
				gPb[i].cWeb[j] ^= ENC;
				gPb[i].cUser[j] ^= ENC;
				gPb[i].cPwd[j] ^= ENC;
				gPb[i].cNote[j] ^= ENC;
			}
		}
	}
	else
	{
		gPb = (pPWDBOOK)malloc(gMax * sizeof(PWDBOOK));
		memset(gPb, 0, gMax * sizeof(PWDBOOK));
	}
	
	//3.关闭
	fclose(pFile);
}
//将内存中的数据加密并写入文件
void SaveP()
{
	FILE *pFile = nullptr;
	//1.打开
	if (fopen_s(&pFile, "pwd.txt", "wb+"))
		printf("失败\n");
	//2.加密写入
	for (int i = 0; i < gCount; i++)
	{
		for (int j = 0; j < CHM;j++)
		{
			gPb[i].cWeb[j] ^= ENC;
			gPb[i].cUser[j] ^= ENC;
			gPb[i].cPwd[j] ^= ENC;
			gPb[i].cNote[j] ^= ENC;
		}
		fwrite(gPb[i].cWeb, CHM, 1, pFile);
		fwrite(gPb[i].cUser, CHM, 1, pFile);
		fwrite(gPb[i].cPwd, CHM, 1, pFile);
		fwrite(gPb[i].cNote, CHM, 1, pFile);
	}
	//3.关闭
	fclose(pFile);
}
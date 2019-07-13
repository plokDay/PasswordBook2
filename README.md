# PasswordBook2
use struct and pointer to storage data, and assign memory dynamically    
when you have a struct to add, you malloc another more memory to copy the next one's all data, and then you change the pointer.  like this:  
```
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
```

#pragma once
#define CHM 50	//规定每一项最多填写50个字符
#define ENC 8	//异或加密密匙  

typedef struct _PWDBOOK {
	char cWeb[CHM];	//站点名
	char cUser[CHM];//用户名
	char cPwd[CHM];//密码
	char cNote[CHM];//备注
}PWDBOOK,*pPWDBOOK;

extern int gCount;//当前有多少条记录
extern int gMax;//最大容量
extern pPWDBOOK gPb;//结构体指针

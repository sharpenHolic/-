#pragma once
#include<iostream>
using namespace std;
//人物抽象基类
//因为每个人都需要  姓名和密码

class Identity
{
public:
	//操作菜单
	virtual void optMenu() = 0;

	//注销登陆
	virtual void logout() = 0;

	//打印信息
	//virtual void printInfo(Identity& item) {}
	
public:
	//登陆姓名
	string	mName;
	//登陆密码
	string	mPwd;
};
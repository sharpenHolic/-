#pragma once
#include<iostream>
using namespace std;
//����������
//��Ϊÿ���˶���Ҫ  ����������

class Identity
{
public:
	//�����˵�
	virtual void optMenu() = 0;

	//ע����½
	virtual void logout() = 0;

	//��ӡ��Ϣ
	//virtual void printInfo(Identity& item) {}
	
public:
	//��½����
	string	mName;
	//��½����
	string	mPwd;
};
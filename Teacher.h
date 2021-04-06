#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "orderFile.h"
//* ��ʦ���幦��
//* �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
//* ���ԤԼ-- - ��ѧ����ԤԼ�������
//* ע����¼-- - �˳���¼
class Teacher : public Identity
{
public:
	Teacher();

	//��ʦ��Ҫ���룺ְ���š���������¼����
	Teacher(int id, string name, string pwd);

	~Teacher();
public:
	//�˵�����
	virtual void optMenu();

	//* �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void tShowAllAppointment();

	//* ���ԤԼ-- - ��ѧ����ԤԼ�������
	void tValidAppointment();

	//* ע����¼-- - �˳���¼
	virtual void logout();

public:
	//��ʦְ����
	long tNum;
};
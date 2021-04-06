#pragma once
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
#include <string>
#include <iostream>
using namespace std;
//* ѧ�����幦��
//* ����ԤԼ-- - ԤԼ����
//* �鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
//* �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
//* ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
//* ע����¼-- - �˳���¼
class Student : public Identity
{
public:
	Student();

	//�вι���(ѧ�š�����������)
	Student(int id, string name, string pwd);

	~Student();
public:
	//ѡ�����
	virtual void optMenu();

	//����ԤԼ
	void sAppointment();

	//�鿴�����ԤԼ--�鿴�Լ���ԤԼ״̬
	void sShowApointment();

	//�鿴����ԤԼ
	void sShowAllApppiontment();

	//ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
	void sCancelAppointment();

	//ע����½
	virtual void logout();

	//��������
	vector<ComputerRoom> vCom;
public:
	int	sNum;	//ѧ��	
};
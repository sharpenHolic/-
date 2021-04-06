#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "globalFile.h"
#include "Identity.h"
#include "Teacher.h"
#include "Student.h"
#include "computerRoom.h"

//* ����Ա���幦��
//* ����˺�-- - ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
//* �鿴�˺�-- - ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
//* �鿴����-- - �鿴���л�������Ϣ
//* ���ԤԼ-- - �������ԤԼ��¼
//* ע����¼-- - �˳���¼

class Manager : public Identity
{
public:
	//����
	Manager();

	//�вι���(ѧ�š�����������)
	Manager(string name, string pwd);
	
	//����
	~Manager();
public:
	//�����˵�
	virtual void optMenu();

	//* ����˺�-- - ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
	void mAddPerson();

	//* �鿴�˺�-- - ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
	void mShowPerson();

	//* �鿴����-- - �鿴���л�������Ϣ
	void mShowRoom();

	//* ���ԤԼ-- - �������ԤԼ��¼
	void mDeleteAppointment();

	//* ע����¼-- - �˳���¼
	virtual void logout();

	//��ʼ������
	void initVector();

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);

	//��ȡ������Ϣ
	void getComputerRoomInfo();


	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
public:
	//�麯����д
	//virtual void printInfo(Identity& item);




private:
	//void printStudent(Student& s);
	//void printTeacher(Teacher& t);
};



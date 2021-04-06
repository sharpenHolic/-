#pragma once
#include <iostream>
#include "Menu.h"
#include "globalFile.h"
#include "Identity.h"
#include "Teacher.h"
#include "Student.h"
#include "Manager.h"
#include "computerRoom.h"
#include <fstream>
#include <string>
using namespace std;

class Menu
{
public:
	Menu();

	~Menu();
public:
	//���˵�
	void showSelectMenu();

	//ѡ����ݺ���Ҫ�����Ӳ˵�
	void LoginIn(string fileName, int type);

	//����Ա�˵�
	void managerMenu(Identity* manager);

	//ѧ���˵�
	void studentMenu(Identity* student);

	//��ʦ�˵�
	void TeacherMenu(Identity* teacher);
};
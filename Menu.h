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
	//主菜单
	void showSelectMenu();

	//选择身份后需要进入子菜单
	void LoginIn(string fileName, int type);

	//管理员菜单
	void managerMenu(Identity* manager);

	//学生菜单
	void studentMenu(Identity* student);

	//教师菜单
	void TeacherMenu(Identity* teacher);
};
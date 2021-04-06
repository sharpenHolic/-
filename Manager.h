#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "globalFile.h"
#include "Identity.h"
#include "Teacher.h"
#include "Student.h"
#include "computerRoom.h"

//* 管理员具体功能
//* 添加账号-- - 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
//* 查看账号-- - 可以选择查看学生或教师的全部信息
//* 查看机房-- - 查看所有机房的信息
//* 清空预约-- - 清空所有预约记录
//* 注销登录-- - 退出登录

class Manager : public Identity
{
public:
	//构造
	Manager();

	//有参构造(学号、姓名、密码)
	Manager(string name, string pwd);
	
	//析构
	~Manager();
public:
	//操作菜单
	virtual void optMenu();

	//* 添加账号-- - 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
	void mAddPerson();

	//* 查看账号-- - 可以选择查看学生或教师的全部信息
	void mShowPerson();

	//* 查看机房-- - 查看所有机房的信息
	void mShowRoom();

	//* 清空预约-- - 清空所有预约记录
	void mDeleteAppointment();

	//* 注销登录-- - 退出登录
	virtual void logout();

	//初始化容器
	void initVector();

	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);

	//获取机房信息
	void getComputerRoomInfo();


	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
public:
	//虚函数重写
	//virtual void printInfo(Identity& item);




private:
	//void printStudent(Student& s);
	//void printTeacher(Teacher& t);
};



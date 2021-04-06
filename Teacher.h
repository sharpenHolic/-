#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "orderFile.h"
//* 教师具体功能
//* 查看所有预约-- - 查看全部预约信息以及预约状态
//* 审核预约-- - 对学生的预约进行审核
//* 注销登录-- - 退出登录
class Teacher : public Identity
{
public:
	Teacher();

	//老师需要输入：职工号、姓名、登录密码
	Teacher(int id, string name, string pwd);

	~Teacher();
public:
	//菜单界面
	virtual void optMenu();

	//* 查看所有预约-- - 查看全部预约信息以及预约状态
	void tShowAllAppointment();

	//* 审核预约-- - 对学生的预约进行审核
	void tValidAppointment();

	//* 注销登录-- - 退出登录
	virtual void logout();

public:
	//教师职工号
	long tNum;
};
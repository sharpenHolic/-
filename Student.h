#pragma once
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
#include <string>
#include <iostream>
using namespace std;
//* 学生具体功能
//* 申请预约-- - 预约机房
//* 查看自身的预约-- - 查看自己的预约状态
//* 查看所有预约-- - 查看全部预约信息以及预约状态
//* 取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
//* 注销登录-- - 退出登录
class Student : public Identity
{
public:
	Student();

	//有参构造(学号、姓名、密码)
	Student(int id, string name, string pwd);

	~Student();
public:
	//选择界面
	virtual void optMenu();

	//申请预约
	void sAppointment();

	//查看自身的预约--查看自己的预约状态
	void sShowApointment();

	//查看所有预约
	void sShowAllApppiontment();

	//取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
	void sCancelAppointment();

	//注销登陆
	virtual void logout();

	//机房容器
	vector<ComputerRoom> vCom;
public:
	int	sNum;	//学号	
};
#include "Teacher.h"
Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	//初始化属性
	this->tNum = id;
	this->mName = name;
	this->mPwd = pwd;
}

Teacher::~Teacher()
{

}

void Teacher::optMenu()
{
	cout << "欢迎教师：" << this->mName << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Teacher::tShowAllAppointment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.oSize; i++)
	{
		cout << i + 1 << "、 ";

		cout << "预约日期： 周" << of.oOrderData[i]["日期"];
		cout << " 时段：" << (of.oOrderData[i]["时间段"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.oOrderData[i]["学号"];
		cout << " 姓名：" << of.oOrderData[i]["学生姓名"];
		cout << " 机房：" << of.oOrderData[i]["机房号"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.oOrderData[i]["预约信息"] == "1")
		{
			status += "审核中";
		}
		else if (of.oOrderData[i]["预约信息"] == "2")
		{
			status += "预约成功";
		}
		else if (of.oOrderData[i]["预约信息"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::tValidAppointment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.oSize; i++)
	{
		if (of.oOrderData[i]["预约信息"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、 ";
			cout << "预约日期： 周" << of.oOrderData[i]["日期"];
			cout << " 时段：" << (of.oOrderData[i]["时间段"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.oOrderData[i]["机房号"];
			string status = " 状态： ";  // 0取消的预约   1 审核中   2 已预约  -1 预约失败
			if (of.oOrderData[i]["预约信息"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.oOrderData[v[select - 1]]["预约信息"] = "2";
				}
				else
				{
					of.oOrderData[v[select - 1]]["预约信息"] = "-1";
				}
				of.oUpdateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::logout()
{

}


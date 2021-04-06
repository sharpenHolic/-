#include "Menu.h"


Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::showSelectMenu()
{
	//* 首先进入登录界面，可选登录身份有：
	//* 学生代表
	//* 老师
	//* 管理员
	//* 退出
	while (true)
	{
		int choose;
		cout << "-------------------------------------------------" << endl;
		cout << "-\t\t --1. 学生代表--\t\t-" << endl;
		cout << "-\t\t --2. 老    师--\t\t-" << endl;
		cout << "-\t\t --3. 管 理 员--\t\t-" << endl;
		cout << "-\t\t --0. 退    出--\t\t-" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "请输入您的身份：";
		cin >> choose;

		switch (choose)
		{
		case 1:	//学生身份
		{

			LoginIn(STUDENT_FILE, 1);
			break;
		}
		case 2:	//老师身份
		{
			LoginIn(TEACHER_FILE, 2);
			break;
		}
		case 3: //管理员身份
		{
			//登陆成功
			LoginIn(MANAGER_FILE, 3);
			break;
		}
		case 0:	//退出
		{
			cout << "欢迎下一次使用本系统" << endl;
			system("pause");
			return;
			break;
		}
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Menu::LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;
	
	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		//char bufName[128];
		//char bufPwd[128];
		//std::locale chs("chs");
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);	//关注下哪个位置释放的
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		//教师登录验证
		int			fId;
		string		fName;
		string		fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

void Menu::managerMenu(Identity* manager)
{
	while (true)
	{
		//管理员菜单
		manager->optMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->mAddPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->mShowPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			man->mShowRoom();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->mDeleteAppointment();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Menu::studentMenu(Identity* student)
{
	while (true)
	{
		//学生菜单
		student->optMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->sAppointment();
		}
		else if (select == 2) //查看自身预约
		{
			stu->sShowApointment();
		}
		else if (select == 3) //查看所有预约
		{
			stu->sShowAllApppiontment();
		}
		else if (select == 4) //取消预约
		{
			stu->sCancelAppointment();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Menu::TeacherMenu(Identity* teacher)
{
	while (true)
	{
		//教师菜单
		teacher->optMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->tShowAllAppointment();
		}
		else if (select == 2)
		{
			//审核预约
			tea->tValidAppointment();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


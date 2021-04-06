#include "Menu.h"


Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::showSelectMenu()
{
	//* ���Ƚ����¼���棬��ѡ��¼����У�
	//* ѧ������
	//* ��ʦ
	//* ����Ա
	//* �˳�
	while (true)
	{
		int choose;
		cout << "-------------------------------------------------" << endl;
		cout << "-\t\t --1. ѧ������--\t\t-" << endl;
		cout << "-\t\t --2. ��    ʦ--\t\t-" << endl;
		cout << "-\t\t --3. �� �� Ա--\t\t-" << endl;
		cout << "-\t\t --0. ��    ��--\t\t-" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "������������ݣ�";
		cin >> choose;

		switch (choose)
		{
		case 1:	//ѧ�����
		{

			LoginIn(STUDENT_FILE, 1);
			break;
		}
		case 2:	//��ʦ���
		{
			LoginIn(TEACHER_FILE, 2);
			break;
		}
		case 3: //����Ա���
		{
			//��½�ɹ�
			LoginIn(MANAGER_FILE, 3);
			break;
		}
		case 0:	//�˳�
		{
			cout << "��ӭ��һ��ʹ�ñ�ϵͳ" << endl;
			system("pause");
			return;
			break;
		}
		default:
			cout << "��������������ѡ��" << endl;
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

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;
	
	if (type == 1)	//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//ѧ����¼��֤
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
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);	//��ע���ĸ�λ���ͷŵ�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		//��ʦ��¼��֤
		int			fId;
		string		fName;
		string		fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
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
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

void Menu::managerMenu(Identity* manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->optMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->mAddPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->mShowPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			man->mShowRoom();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->mDeleteAppointment();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
		//ѧ���˵�
		student->optMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->sAppointment();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->sShowApointment();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->sShowAllApppiontment();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->sCancelAppointment();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
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
		//��ʦ�˵�
		teacher->optMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->tShowAllAppointment();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->tValidAppointment();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


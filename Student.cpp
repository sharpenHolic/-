#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	//��ʼ������  ѧ�š�����������
	this->sNum = id;
	this->mName = name;
	this->mPwd = pwd;

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.mComId && ifs >> c.mMaxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}

Student::~Student()
{

}

void Student::optMenu()
{
	cout << "��ӭѧ������" << this->mName << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::sAppointment()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	//ԤԼ����
	int date = 0;
	//����ԤԼ��ʱ���
	int interval = 0;
	//������
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].mMaxNum << endl;
	cout << "2�Ż���������" << vCom[1].mMaxNum << endl;
	cout << "3�Ż���������" << vCom[2].mMaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "����:" << date << " ";
	ofs << "ʱ���:" << interval << " ";
	ofs << "ѧ��:" << this->sNum << " ";
	ofs << "ѧ������:" << this->mName << " ";
	ofs << "������:" << room << " ";
	ofs << "ԤԼ��Ϣ:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::sShowAllApppiontment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.oSize; i++)
	{
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << of.oOrderData[i]["����"];
		cout << " ʱ�Σ�" << (of.oOrderData[i]["ʱ���"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.oOrderData[i]["ѧ��"];
		cout << " ������" << of.oOrderData[i]["ѧ������"];
		cout << " ������" << of.oOrderData[i]["������"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.oOrderData[i]["ԤԼ��Ϣ"] == "1")
		{
			status += "�����";
		}
		else if (of.oOrderData[i]["ԤԼ��Ϣ"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.oOrderData[i]["ԤԼ��Ϣ"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}


void Student::sCancelAppointment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.oSize; i++)
	{
		if (atoi(of.oOrderData[i]["ѧ��"].c_str()) == this->sNum)
		{
			if (of.oOrderData[i]["ԤԼ��Ϣ"] == "1" || of.oOrderData[i]["ԤԼ��Ϣ"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.oOrderData[i]["����"];
				cout << " ʱ�Σ�" << (of.oOrderData[i]["ʱ���"] == "1" ? "����" : "����");
				cout << " ������" << of.oOrderData[i]["������"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.oOrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.oOrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;

			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;
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
				//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
				of.oOrderData[v[select - 1]]["ԤԼ��Ϣ"] = "0";
				of.oUpdateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

void Student::logout()
{

}

void Student::sShowApointment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.oSize; i++)
	{
		if (atoi(of.oOrderData[i]["ѧ��"].c_str()) == this->sNum)
		{
			cout << "ԤԼ���ڣ� ��" << of.oOrderData[i]["����"];
			cout << " ʱ��Σ�" << (of.oOrderData[i]["ʱ���"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.oOrderData[i]["������"];
			string status = " ԤԼ��Ϣ�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.oOrderData[i]["ԤԼ��Ϣ"] == "1")
			{
				status += "�����";
			}
			else if (of.oOrderData[i]["ԤԼ��Ϣ"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.oOrderData[i]["ԤԼ��Ϣ"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
}

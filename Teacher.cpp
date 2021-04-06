#include "Teacher.h"
Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	//��ʼ������
	this->tNum = id;
	this->mName = name;
	this->mPwd = pwd;
}

Teacher::~Teacher()
{

}

void Teacher::optMenu()
{
	cout << "��ӭ��ʦ��" << this->mName << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Teacher::tShowAllAppointment()
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

void Teacher::tValidAppointment()
{
	OrderFile of;
	if (of.oSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.oSize; i++)
	{
		if (of.oOrderData[i]["ԤԼ��Ϣ"] == "1")
		{
			v.push_back(i);
			cout << ++index << "�� ";
			cout << "ԤԼ���ڣ� ��" << of.oOrderData[i]["����"];
			cout << " ʱ�Σ�" << (of.oOrderData[i]["ʱ���"] == "1" ? "����" : "����");
			cout << " ������" << of.oOrderData[i]["������"];
			string status = " ״̬�� ";  // 0ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
			if (of.oOrderData[i]["ԤԼ��Ϣ"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼,0������" << endl;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.oOrderData[v[select - 1]]["ԤԼ��Ϣ"] = "2";
				}
				else
				{
					of.oOrderData[v[select - 1]]["ԤԼ��Ϣ"] = "-1";
				}
				of.oUpdateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::logout()
{

}


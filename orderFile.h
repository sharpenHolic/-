#pragma once
#include "globalFile.h"
#include <map>

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void oUpdateOrder();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> oOrderData;

	//ԤԼ��¼����
	int oSize;
};
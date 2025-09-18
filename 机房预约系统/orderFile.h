#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "globalFile.h"

using namespace std;

class OrderFile {
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������  key��ʾ����  value��ʾ�����¼��ֵ�Ե���Ϣ
	map<int, map<string, string>> m_orderData;
};

#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Manager :public Identity {
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����  �鹹��д
	virtual void operMenu();

	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴��������Ϣ
	void showComputer();
	//������е�ԤԼ��¼
	void cleanFile();
};

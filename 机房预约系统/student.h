#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Student :public Identity {
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���  ������ѧ�š�����������
	Student(int id, string name, string pwd);
	//�˵�����  ��д����
	virtual void operMenu() = 0;

	//����ԤԼ
	void applyOrder();
	//�鿴�����ԤԼ
	void showMyOrder();
	//�鿴���е�ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();

	//����  ѧ��ѧ��
	int m_Id; 
};

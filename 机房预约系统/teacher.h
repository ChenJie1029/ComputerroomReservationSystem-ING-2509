#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Identity.h"
#include "orderFile.h"

using namespace std;

class Teacher :public Identity {
public:
	//���캯��
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����  ��д
	virtual void operMenu();

	//�鿴����ѧ����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void valiOrder();

	//ְ����
	int m_EmpId;
};

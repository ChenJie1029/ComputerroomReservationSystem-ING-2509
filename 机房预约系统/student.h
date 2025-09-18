#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "computerRoom.h"
#include "Identity.h"
#include "globalFile.h"

using namespace std;

class Student :public Identity {
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���  ������ѧ�š�����������
	Student(int id, string name, string pwd);
	//�˵�����  ��д����
	virtual void operMenu();

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

	//��������
	vector<ComputerRoom> vCom;
};

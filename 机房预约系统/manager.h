#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"

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

	//��ʼ������
	void initVector();

	//����Ƿ��ظ�
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;
};

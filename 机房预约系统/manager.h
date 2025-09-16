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
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//菜单界面  虚构重写
	virtual void operMenu();

	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房的信息
	void showComputer();
	//清空所有的预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测是否重复
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;
};

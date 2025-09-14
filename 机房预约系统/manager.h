#pragma once
#include<iostream>
#include "Identity.h"

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
};

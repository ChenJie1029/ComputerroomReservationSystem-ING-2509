#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Teacher :public Identity {
public:
	//构造函数
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面  重写
	virtual void operMenu();

	//查看所有学生的预约
	void showAllOrder();
	//审核预约
	void valiOrder();

	//职工号
	int m_EmpId;
};

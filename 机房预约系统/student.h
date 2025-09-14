#pragma once
#include<iostream>
#include "Identity.h"

using namespace std;

class Student :public Identity {
public:
	//默认构造
	Student();
	//有参构造  参数：学号、姓名，密码
	Student(int id, string name, string pwd);
	//菜单界面  重写父类
	virtual void operMenu() = 0;

	//申请预约
	void applyOrder();
	//查看自身的预约
	void showMyOrder();
	//查看所有的预约
	void showAllOrder();
	//取消预约
	void cancelOrder();

	//属性  学生学号
	int m_Id; 
};

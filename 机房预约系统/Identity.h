#pragma once
#include<iostream>
#include<string>

using namespace std;

//身份的抽象基类 
class Identity {
public:
	//操作菜单  纯虚函数 子类必须重写父类纯虚函数
	virtual void operMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};

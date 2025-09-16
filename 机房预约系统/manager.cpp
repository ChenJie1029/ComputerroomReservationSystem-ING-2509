#include "manager.h"

//默认构造
Manager::Manager() {

}
//有参构造
Manager::Manager(string name, string pwd) {//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//菜单界面  虚构重写
void Manager::operMenu() {
	cout << "欢迎管理员:" << this->m_Name << "登录" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作：" << endl;
}

//添加账号
void Manager::addPerson() {

}
//查看账号
void Manager::showPerson() {

}
//查看机房的信息
void Manager::showComputer() {

}
//清空所有的预约记录
void Manager::cleanFile() {

}
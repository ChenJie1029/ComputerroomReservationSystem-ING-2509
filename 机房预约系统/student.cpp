#include "student.h"

//默认构造
Student::Student() {

}
//有参构造  参数：学号、姓名，密码
Student::Student(int id, string name, string pwd) {
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//菜单界面  重写父类
void Student::operMenu() {
	cout << "欢迎学生代表：" << this->m_Name << "登录" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登录" << endl;
}

//申请预约
void Student::applyOrder() {

}
//查看自身的预约
void Student::showMyOrder() {

}
//查看所有的预约
void Student::showAllOrder() {

}
//取消预约
void Student::cancelOrder() {

}

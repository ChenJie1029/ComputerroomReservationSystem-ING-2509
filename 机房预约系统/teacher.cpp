#include "teacher.h"

//构造函数
Teacher::Teacher() {

}
//有参构造
Teacher::Teacher(int empId, string name, string pwd) {
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//菜单界面  重写
void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作" << endl;
}

//查看所有学生的预约
void Teacher::showAllOrder() {

}
//审核预约
void Teacher::valiOrder() {

}
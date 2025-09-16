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
	cout << "请输入你要添加的账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;

	string fileName;//操作文件名
	string tip;//提示id号

	ofstream ofs;//文件操作对象

	int select = 0;
	cin >> select;

	if (select == 1) {
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
	}

	ofs.open(fileName, ios::out | ios::app);//利用追加的方式写文件
	
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;

	cout << "姓名：" << endl;
	cin >> name;

	cout << "密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
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
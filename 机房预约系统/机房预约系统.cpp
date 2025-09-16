#include<iostream>
#include<string>
#include<fstream>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		//调用管理员的子菜单
		manager->operMenu();
		//将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户的选择
		cin >> select;

		if (select == 1) {//添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			//注销
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能  参数1：操作文件名、参数2：操作身份的类型
void LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	//ofstream ofs("student.txt");
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {//学生身份
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {//老师身份
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {//学生身份验证
		int fId;//从文件中读取的ID号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			cout << fId << " " << fName << " " << fPwd << endl;
			//与用户信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单

				return;
			}
		}
	}
	else if (type == 2) {//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单

				return;
			}
		}
	}
	else if (type == 3) {//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "登录失败" << endl;
	system("pause");
	system("cls");
}

int main() {
	int select = 0;
	while (1) {
		cout << "====================机房预约系统====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "1.学生代表" << endl;
		cout << "2.教师" << endl;
		cout << "3.管理员" << endl;
		cout << "0.退出" << endl;
		cout << "请输入您的选择：" << endl;

		cin >> select;

		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}
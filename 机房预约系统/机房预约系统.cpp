#include<iostream>
#include<string>
#include "Identity.h"
#include "globalFile.h"

using namespace std;

//登录功能  参数1：操作文件名、参数2：操作身份的类型
void LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
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

	}
	else if (type == 2) {//教师身份验证

	}
	else if (type == 3) {//管理员身份验证

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
			LoginIn(STRUNCATE, 1);
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
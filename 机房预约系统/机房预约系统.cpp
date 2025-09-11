#include<iostream>

using namespace std;

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
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
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
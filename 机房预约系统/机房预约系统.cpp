#include<iostream>

using namespace std;

int main() {
	int select = 0;
	while (1) {
		cout << "====================����ԤԼϵͳ====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "1.ѧ������" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cout << "0.�˳�" << endl;
		cout << "����������ѡ��" << endl;

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
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}
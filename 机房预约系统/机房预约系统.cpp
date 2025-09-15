#include<iostream>
#include<string>
#include "Identity.h"
#include "globalFile.h"

using namespace std;

//��¼����  ����1�������ļ���������2��������ݵ�����
void LoginIn(string fileName, int type) {
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {//ѧ�����
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {//��ʦ���
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1) {//ѧ�������֤

	}
	else if (type == 2) {//��ʦ�����֤

	}
	else if (type == 3) {//����Ա�����֤

	}

	cout << "��¼ʧ��" << endl;
	system("pause");
	system("cls");
}

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
		case 1://ѧ�����
			LoginIn(STRUNCATE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
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
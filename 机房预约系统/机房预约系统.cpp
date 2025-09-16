#include<iostream>
#include<string>
#include<fstream>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager) {
	while (true) {
		//���ù���Ա���Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;

		if (select == 1) {//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			//ע��
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����  ����1�������ļ���������2��������ݵ�����
void LoginIn(string fileName, int type) {
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	//ofstream ofs("student.txt");
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
		int fId;//���ļ��ж�ȡ��ID��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			cout << fId << " " << fName << " " << fPwd << endl;
			//���û���Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if (type == 2) {//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if (type == 3) {//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
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
			LoginIn(STUDENT_FILE, 1);
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
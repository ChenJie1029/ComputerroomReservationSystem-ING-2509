#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager() {

}
//�вι���
Manager::Manager(string name, string pwd) {//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//�˵�����  �鹹��д
void Manager::operMenu() {
	cout << "��ӭ����Ա:" << this->m_Name << "��¼" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}

//����˺�
void Manager::addPerson() {
	cout << "��������Ҫ��ӵ��˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.��ӽ�ʦ" << endl;

	string fileName;//�����ļ���
	string tip;//��ʾid��

	ofstream ofs;//�ļ���������

	int select = 0;
	cin >> select;

	if (select == 1) {
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
	}

	ofs.open(fileName, ios::out | ios::app);//����׷�ӵķ�ʽд�ļ�
	
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;

	cout << "������" << endl;
	cin >> name;

	cout << "���룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
 }
//�鿴�˺�
void Manager::showPerson() {

}
//�鿴��������Ϣ
void Manager::showComputer() {

}
//������е�ԤԼ��¼
void Manager::cleanFile() {

}
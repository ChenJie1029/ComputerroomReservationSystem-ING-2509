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
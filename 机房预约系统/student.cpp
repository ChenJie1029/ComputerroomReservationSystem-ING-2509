#include "student.h"

//Ĭ�Ϲ���
Student::Student() {

}
//�вι���  ������ѧ�š�����������
Student::Student(int id, string name, string pwd) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//�˵�����  ��д����
void Student::operMenu() {
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
}

//����ԤԼ
void Student::applyOrder() {

}
//�鿴�����ԤԼ
void Student::showMyOrder() {

}
//�鿴���е�ԤԼ
void Student::showAllOrder() {

}
//ȡ��ԤԼ
void Student::cancelOrder() {

}

#include "teacher.h"

//���캯��
Teacher::Teacher() {

}
//�вι���
Teacher::Teacher(int empId, string name, string pwd) {
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//�˵�����  ��д
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}

//�鿴����ѧ����ԤԼ
void Teacher::showAllOrder() {

}
//���ԤԼ
void Teacher::valiOrder() {

}
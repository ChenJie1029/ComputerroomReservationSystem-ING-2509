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
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "��";
		cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
		cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" �� "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "������" << of.m_orderData[i]["stuName"];
		cout << "������ţ�" << of.m_orderData[i]["roomId"];
		string status = "״̬��";
		//1.�����  2.��ԤԼ  -1.ԤԼʧ��  0.ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else {
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void Teacher::valiOrder() {

}
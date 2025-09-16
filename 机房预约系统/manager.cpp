#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager() {

}
//�вι���
Manager::Manager(string name, string pwd) {//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ���ѧ���ͽ�ʦ��Ϣ
	this->initVector();
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
	string errorTip;//�ظ�������ʾ

	ofstream ofs;//�ļ���������

	int select = 0;
	cin >> select;

	if (select == 1) {
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errorTip = "ְ�����ظ�������������";
	}

	ofs.open(fileName, ios::out | ios::app);//����׷�ӵķ�ʽд�ļ�
	
	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (1) {
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}

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

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	this->initVector();
 }

void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1.�鿴���е�ѧ��" << endl;
	cout << "2.�鿴���е���ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}
//�鿴��������Ϣ
void Manager::showComputer() {

}
//������е�ԤԼ��¼
void Manager::cleanFile() {

}

//��ʼ������
void Manager::initVector() {
	//ȷ��������յ�״̬
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ  ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	//��ȡѧ����Ϣ
	Student s;//��ʱStudent����s
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {//��ȡ�ļ��е���Ϣ����ʱ����s
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����Ƿ��ظ�
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return 1;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return 1;
			}
		}
	}

	return 0;
}
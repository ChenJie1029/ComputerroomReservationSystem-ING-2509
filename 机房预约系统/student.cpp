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

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		//����ȡ����Ϣ���뵽������
		vCom.push_back(com);
	}

	ifs.close();
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
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (1) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "������������������" < endl;
	}

	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "�Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}

	while (1) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}
//�鿴�����ԤԼ
void Student::showMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		//string תΪ int
		//string ���� .c_str()תΪ const char*
		//���� atoi(const char *) ת int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {//�ҵ�����ԤԼ
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬��";
			//1.�����  2.��ԤԼ  -1.ԤԼʧ��  0.ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "ԤԼʧ��"��
			}
			else {
				status += "ȡ��ԤԼ";
			}
		}
	}

	system("pause");
	system("cls");
}
//�鿴���е�ԤԼ
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "������" << of.m_orderData[i]["stuName"];
		cout << "������ţ�" << of.m_orderData[i]["roomId"];
		string status = " ״̬��";
		//1.�����  2.��ԤԼ  -1.ԤԼʧ��  0.ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else {
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}
//ȡ��ԤԼ
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼�ǿ���ȡ���ģ�������Ҫȡ���ļ�¼" << endl;
	vector<int> v;//�������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//���ж�������ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			//��ɸѡ״̬ ����л���ԤԼ�ɹ�
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "" << endl;
 			}
		}
	}
}

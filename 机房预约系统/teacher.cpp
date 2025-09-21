#include "teacher.h"

//构造函数
Teacher::Teacher() {

}
//有参构造
Teacher::Teacher(int empId, string name, string pwd) {
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//菜单界面  重写
void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作" << endl;
}

//查看所有学生的预约
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "、";
		cout << "预约日期: 周" << of.m_orderData[i]["date"];
		cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ？ "上午" : "下午");
		cout << "学号：" << of.m_orderData[i]["stuId"];
		cout << "姓名：" << of.m_orderData[i]["stuName"];
		cout << "机房编号：" << of.m_orderData[i]["roomId"];
		string status = "状态：";
		//1.审核中  2.已预约  -1.预约失败  0.取消预约
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "预约失败，审核未通过";
		}
		else {
			status += "预约已经取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//审核预约
void Teacher::valiOrder() {

}
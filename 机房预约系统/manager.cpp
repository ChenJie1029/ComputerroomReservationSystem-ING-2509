#include "manager.h"

//默认构造
Manager::Manager() {

}
//有参构造
Manager::Manager(string name, string pwd) {//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器 获取到所有文件中学生和教师信息
	this->initVector();
}
//菜单界面  虚构重写
void Manager::operMenu() {
	cout << "欢迎管理员:" << this->m_Name << "登录" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作：" << endl;
}

//添加账号
void Manager::addPerson() {
	cout << "请输入你要添加的账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;

	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//重复错误提示

	ofstream ofs;//文件操作对象

	int select = 0;
	cin >> select;

	if (select == 1) {
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);//利用追加的方式写文件
	
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

	cout << "姓名：" << endl;
	cin >> name;

	cout << "密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器接口，重新获取文件中的数据
	this->initVector();
 }
//查看账号
void Manager::showPerson() {

}
//查看机房的信息
void Manager::showComputer() {

}
//清空所有的预约记录
void Manager::cleanFile() {

}

//初始化容器
void Manager::initVector() {
	//确保容器清空的状态
	vStu.clear();
	vTea.clear();
	//读取信息  学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}

	//读取学生信息
	Student s;//临时Student对象s
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {//读取文件中的信息到临时对象s
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();
}

//检测是否重复
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
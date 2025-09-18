#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "globalFile.h"

using namespace std;

class OrderFile {
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器  key表示条数  value表示具体记录键值对的信息
	map<int, map<string, string>> m_orderData;
};

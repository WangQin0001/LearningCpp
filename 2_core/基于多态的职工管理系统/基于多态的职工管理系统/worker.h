#pragma once
#include <iostream>
using namespace std;

#include <string>

class Worker {
public:
	//显示个人信息
	virtual void showInfo()=0;
	//获取岗位名
	virtual string getDeptName()=0;

public:
	int m_id;
	string m_name;
	int m_deptId;
};
#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Boss::showInfo() {
	cout << "老板编号：" << m_id
		<< "\t 老板姓名：  " << m_name
		<< "\t岗位：  " << m_deptId
		<< "\t 岗位职责：统筹管理整个公司" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}
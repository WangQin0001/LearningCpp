#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Manager::showInfo() {
	cout << "经理编号：" << m_id
		<< "\t 经理姓名：  " << m_name
		<< "\t岗位：  " << m_deptId
		<< "\t 岗位职责：完成老总交给的任务，并且将任务分配给员工" << endl;
}

string Manager::getDeptName() {
	return string ("经理");
}
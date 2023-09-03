#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Employee::showInfo() {
	cout << "员工编号：" << m_id
		<< "\t 员工姓名：  " << m_name
		<< "\t岗位：  " << m_deptId
		<<"\t 岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
	return string("员工");
}
#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Employee::showInfo() {
	cout << "Ա����ţ�" << m_id
		<< "\t Ա��������  " << m_name
		<< "\t��λ��  " << m_deptId
		<<"\t ��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}
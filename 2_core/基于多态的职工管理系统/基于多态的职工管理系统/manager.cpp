#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Manager::showInfo() {
	cout << "�����ţ�" << m_id
		<< "\t ����������  " << m_name
		<< "\t��λ��  " << m_deptId
		<< "\t ��λְ��������ܽ��������񣬲��ҽ���������Ա��" << endl;
}

string Manager::getDeptName() {
	return string ("����");
}
#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Boss::showInfo() {
	cout << "�ϰ��ţ�" << m_id
		<< "\t �ϰ�������  " << m_name
		<< "\t��λ��  " << m_deptId
		<< "\t ��λְ��ͳ�����������˾" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}
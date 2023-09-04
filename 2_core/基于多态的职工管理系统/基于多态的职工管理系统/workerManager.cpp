#include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//1���ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_fileIsEmpty = true;//�ļ���Ϊ��
		this->m_workerNum = 0;//��ʼ������
		this->m_workerArry = NULL;//��ʼ������
		ifs.close();
		return;
	}

	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;//��ȡһ���ַ�
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_fileIsEmpty = true;//�ļ���Ϊ��
		this->m_workerNum = 0;//��ʼ������
		this->m_workerArry = NULL;//��ʼ������
		ifs.close();
		return;
	}

	//3���ļ����������ݲ�Ϊ��
	int num = this->get_WorkerNum();
	cout << "�ļ�����" << num << "��Ա��" << endl;
	this->m_workerNum = num;

	this->m_workerArry = new Worker *[num];//��ʼ��Ա������
	this->init_Worker();
	//���Դ��룺
	for (int i = 0; i < num; i++) {
		cout << "Ա����ţ�" << this->m_workerArry[i]->m_id
			<< "������" << this->m_workerArry[i]->m_name
			<< "���ű��" << this->m_workerArry[i]->m_deptId << endl;
	}

}

void WorkerManager::addWorker() {
	int addNum = 0;//����Ա���ĸ���


	cout << "����������Ա���ĸ���" << endl;
	cin >> addNum;
	if (addNum != 0) {

		//�����¿ռ��С
		int newSize = this->m_workerNum + addNum;
		//�����¿ռ�
		Worker ** newSpace = new Worker* [newSize];
		//��ԭ�ռ�������Ƶ��¿ռ�
		if (this->m_workerArry != NULL) {
			for (int i = 0; i < m_workerNum; i++) {
				newSpace[i] = this->m_workerArry[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dIdSlect;

			cout << "����������Ա�����" << endl;
			cin >> id;

			cout << "����������Ա������" << endl;
			cin >> name;

			cout << "��ѡ������Ա���Ĳ���" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dIdSlect;

			Worker* worker = NULL;
			switch (dIdSlect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��worker�����¿ռ�
			newSpace[this->m_workerNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_workerArry;
		//���¿ռ���Ϣ
		this->m_workerArry = newSpace;
		this->m_workerNum = newSize;
		//���ļ���Ϊ�ǿ�
		this->m_fileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����Ա����" << endl;
		this->saveWorker();
	}
	else {
		cout << "��������Ϊ0" << endl;
	}

	system("pause");
	system("cls");

}

void WorkerManager::saveWorker() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_workerNum; i++) {
		ofs << this->m_workerArry[i]->m_id << "  "
			<< this->m_workerArry[i]->m_name << "  "
			<< this->m_workerArry[i]->m_deptId << "  " << endl;
	}
	ofs.close();
}

int WorkerManager::get_WorkerNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {//һ��һ�еض��ļ�
		num++;
	}
	return num;
}

void WorkerManager::init_Worker() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;//ÿ������
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else if(dId == 3) {
			worker = new Boss(id, name, dId);
		}
		this->m_workerArry[index] = worker;
		index++;
	}
}

WorkerManager::~WorkerManager() {
	//�ֶ��ͷŶ������ٵĿռ�
	if (this->m_workerArry != NULL) {
		delete[]this->m_workerArry;
		this->m_workerArry = NULL;
	}
}
//չʾ�˵�
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//0.�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�
}
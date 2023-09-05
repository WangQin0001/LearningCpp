#include "workerManager.h"

//���캯��
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
	//for (int i = 0; i < num; i++) {
	//	cout << "Ա����ţ�" << this->m_workerArry[i]->m_id
	//		<< "������" << this->m_workerArry[i]->m_name
	//		<< "���ű��" << this->m_workerArry[i]->m_deptId << endl;
	//}

}

//1�����Ա��
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
			int dIdSelect;

			cout << "����������Ա�����" << endl;
			cin >> id;
			bool flag = this->idNotExist(id);
			while (!flag)//��id������Ϊfalse����id�Ѵ���ʱ����ѭ���������Ǹ�С�����^-^/
			{
				cin >> id;
				flag = this->idNotExist(id);
			}

			cout << "����������Ա������" << endl;
			cin >> name;

			cout << "��ѡ������Ա���Ĳ���" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dIdSelect;

			Worker* worker = NULL;
			switch (dIdSelect)
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

//1.1������Ա��
void WorkerManager::saveWorker() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_workerNum; i++) {
		ofs << this->m_workerArry[i]->m_id << " "
			<< this->m_workerArry[i]->m_name << " "
			<< this->m_workerArry[i]->m_deptId << " " << endl;
	}
	ofs.close();
}

//1.2����ȡԱ������
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

//1.3����ʼ��Ա��
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
// 1.4���ж�Ա��id�Ƿ��ظ�
bool WorkerManager::idNotExist(int id) {
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_id == id) {
			cout << "�������Ա����ź�ϵͳid�ظ����������µı�ţ�" << endl;
			return false;
		}
	}
	return true;
}

//2��չʾԱ��
void WorkerManager::show_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else {
		for (int i = 0; i < this->m_workerNum; i++) {
			this->m_workerArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//3��ɾ��ְ��
void WorkerManager::delet_Worker() {
	if (this->m_fileIsEmpty != true) {//���ж��ļ��Ƿ�Ϊ��
		cout << "������Ҫɾ��Ա����id:" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {//������ڸ�Ա��
			for (int i = index; i < this->m_workerNum; i++) {
				//����ǰ��
				this->m_workerArry[i] = this->m_workerArry[i + 1];
			}
			this->m_workerNum--;//������Ա������
			this->saveWorker();//���仯�������ļ���
			cout << "�ѳɹ�ɾ�����Ϊ" << id << "��Ա��" << endl;
		}
		else {
			cout << "�������Ա��id�����ڣ�" << endl;
		}
	}
	else {
		cout << "ɾ��ʧ�ܣ�ְ���ļ�Ϊ�ջ򲻴��ڣ�" << endl;
	}
	system("pause");
	system("cls");
}
//3.1����id�ж��Ƿ����ĳԱ��,�����ڷ��ظ�Ա����id
int WorkerManager::isExist(int id) {
	int index = -1;//�ж��Ƿ���ڵı�־
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}

//4���޸�Ա��
void WorkerManager::mod_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else {
		cout << "������Ԥ�޸�Ա���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			//��ʽ��ʼ�޸Ĳ�����
			delete this->m_workerArry[ret];//�Ƚ�ԭ����������ͬλ�õ�����ɾ��

			int newId;
			string newName;
			int newDIdSelect;
			cout << "�����µ�Ա�����" << endl;
			cin >> newId;

			cout << "����������" << endl;
			cin >> newName;

			cout << "ѡ���¸�λ" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newDIdSelect;

			Worker* worker = NULL;//��ǰ��������ָ��
			switch (newDIdSelect)
			{
			case 1://case����һ��Ҫ�ӿո񣡣�������
				worker = new Employee(newId, newName, newDIdSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, newDIdSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, newDIdSelect);
				break;
			default:
				break;
			}
			this->m_workerArry[ret] = worker;
			this->saveWorker();
			cout << "�ɹ��޸ı��Ϊ" << newDIdSelect << "��Ա��" << endl;

		}
		else {
			cout << "�ñ�ŵ�Ա�������ڣ�" << endl;
		}
		system("pause");
		system("cls");
	}
}

//5������Ա��
void WorkerManager::find_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
	}
	else {
		cout << "��ѡ���ѯ��ʽ��" << endl;
		cout << "1����id����" << endl;
		cout << "2������������" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cout << "������Ա�����" << endl;
			int id;
			cin >> id;
			this->find_WorkerById(id);
		}
		else if (select == 2) {
			cout << "������Ա������" << endl;
			string name;
			cin >> name;
			this->find_WorkerByName(name);
		}
		else {
			cout << "��������!" << endl;
		}
	}
	system("pause");
	system("cls");
}
// 5.1������Ų���
void WorkerManager::find_WorkerById(int id) {
	int ret = isExist(id);
	if (ret != -1) {
		cout << "�鵽���Ϊ" << id << "���˵���Ϣ���£�" << endl;
		this->m_workerArry[ret]->showInfo();
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
}
// 5.2������������
void WorkerManager::find_WorkerByName(string name) {
	bool flag = false;//Ĭ��û�ҵ�
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_name == name) {
			cout << "�鵽���Ϊ" << this->m_workerArry[i]->m_id << "���˵���Ϣ���£�" << endl;
			this->m_workerArry[i]->showInfo();
			flag = true;
		}
	}
	if (!flag) {
		cout << "���޴��ˣ�" << endl;
	}
}

//��������
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
#include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//1、文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_fileIsEmpty = true;//文件置为空
		this->m_workerNum = 0;//初始化人数
		this->m_workerArry = NULL;//初始化数组
		ifs.close();
		return;
	}

	//2、文件存在，数据为空
	char ch;
	ifs >> ch;//读取一个字符
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_fileIsEmpty = true;//文件置为空
		this->m_workerNum = 0;//初始化人数
		this->m_workerArry = NULL;//初始化数组
		ifs.close();
		return;
	}

	//3、文件存在且数据不为空
	int num = this->get_WorkerNum();
	cout << "文件中有" << num << "个员工" << endl;
	this->m_workerNum = num;

	this->m_workerArry = new Worker *[num];//初始化员工数组
	this->init_Worker();
	//测试代码：
	for (int i = 0; i < num; i++) {
		cout << "员工编号：" << this->m_workerArry[i]->m_id
			<< "姓名：" << this->m_workerArry[i]->m_name
			<< "部门编号" << this->m_workerArry[i]->m_deptId << endl;
	}

}

void WorkerManager::addWorker() {
	int addNum = 0;//新增员工的个数


	cout << "请输入新增员工的个数" << endl;
	cin >> addNum;
	if (addNum != 0) {

		//计算新空间大小
		int newSize = this->m_workerNum + addNum;
		//开辟新空间
		Worker ** newSpace = new Worker* [newSize];
		//将原空间的内容移到新空间
		if (this->m_workerArry != NULL) {
			for (int i = 0; i < m_workerNum; i++) {
				newSpace[i] = this->m_workerArry[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dIdSlect;

			cout << "请输入新增员工编号" << endl;
			cin >> id;

			cout << "请输入新增员工姓名" << endl;
			cin >> name;

			cout << "请选择新增员工的部门" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将worker存入新空间
			newSpace[this->m_workerNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_workerArry;
		//更新空间信息
		this->m_workerArry = newSpace;
		this->m_workerNum = newSize;
		//将文件置为非空
		this->m_fileIsEmpty = false;
		cout << "成功添加" << addNum << "名新员工！" << endl;
		this->saveWorker();
	}
	else {
		cout << "新增个数为0" << endl;
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
	while (ifs >> id && ifs >> name && ifs >> dId) {//一行一行地读文件
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
	int index = 0;//每行索引
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
	//手动释放堆区开辟的空间
	if (this->m_workerArry != NULL) {
		delete[]this->m_workerArry;
		this->m_workerArry = NULL;
	}
}
//展示菜单
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//0.退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出
}
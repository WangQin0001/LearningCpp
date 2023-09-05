#include "workerManager.h"

//构造函数
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
	//for (int i = 0; i < num; i++) {
	//	cout << "员工编号：" << this->m_workerArry[i]->m_id
	//		<< "姓名：" << this->m_workerArry[i]->m_name
	//		<< "部门编号" << this->m_workerArry[i]->m_deptId << endl;
	//}

}

//1、添加员工
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
			int dIdSelect;

			cout << "请输入新增员工编号" << endl;
			cin >> id;
			bool flag = this->idNotExist(id);
			while (!flag)//当id不存在为false，即id已存在时进入循环。我真是个小机灵鬼^-^/
			{
				cin >> id;
				flag = this->idNotExist(id);
			}

			cout << "请输入新增员工姓名" << endl;
			cin >> name;

			cout << "请选择新增员工的部门" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

//1.1、保存员工
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

//1.2、获取员工数量
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

//1.3、初始化员工
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
// 1.4、判断员工id是否重复
bool WorkerManager::idNotExist(int id) {
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_id == id) {
			cout << "您输入的员工编号和系统id重复，请输入新的编号！" << endl;
			return false;
		}
	}
	return true;
}

//2、展示员工
void WorkerManager::show_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		for (int i = 0; i < this->m_workerNum; i++) {
			this->m_workerArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//3、删除职工
void WorkerManager::delet_Worker() {
	if (this->m_fileIsEmpty != true) {//先判断文件是否为空
		cout << "请输入要删除员工的id:" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {//如果存在该员工
			for (int i = index; i < this->m_workerNum; i++) {
				//数组前移
				this->m_workerArry[i] = this->m_workerArry[i + 1];
			}
			this->m_workerNum--;//更新现员工人数
			this->saveWorker();//将变化保存在文件中
			cout << "已成功删除编号为" << id << "的员工" << endl;
		}
		else {
			cout << "您输入的员工id不存在！" << endl;
		}
	}
	else {
		cout << "删除失败，职工文件为空或不存在！" << endl;
	}
	system("pause");
	system("cls");
}
//3.1、按id判断是否存在某员工,若存在返回该员工的id
int WorkerManager::isExist(int id) {
	int index = -1;//判断是否存在的标志
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}

//4、修改员工
void WorkerManager::mod_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		cout << "请输入预修改员工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			//正式开始修改操作：
			delete this->m_workerArry[ret];//先将原来数组中相同位置的数据删除

			int newId;
			string newName;
			int newDIdSelect;
			cout << "输入新的员工编号" << endl;
			cin >> newId;

			cout << "输入新姓名" << endl;
			cin >> newName;

			cout << "选择新岗位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newDIdSelect;

			Worker* worker = NULL;//提前声明父类指针
			switch (newDIdSelect)
			{
			case 1://case后面一定要加空格！！！！！
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
			cout << "成功修改编号为" << newDIdSelect << "的员工" << endl;

		}
		else {
			cout << "该编号的员工不存在！" << endl;
		}
		system("pause");
		system("cls");
	}
}

//5、查找员工
void WorkerManager::find_Worker() {
	if (this->m_fileIsEmpty) {
		cout << "文件为空或不存在！" << endl;
	}
	else {
		cout << "请选择查询方式：" << endl;
		cout << "1、按id查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cout << "请输入员工编号" << endl;
			int id;
			cin >> id;
			this->find_WorkerById(id);
		}
		else if (select == 2) {
			cout << "请输入员工姓名" << endl;
			string name;
			cin >> name;
			this->find_WorkerByName(name);
		}
		else {
			cout << "输入有误!" << endl;
		}
	}
	system("pause");
	system("cls");
}
// 5.1、按编号查找
void WorkerManager::find_WorkerById(int id) {
	int ret = isExist(id);
	if (ret != -1) {
		cout << "查到编号为" << id << "的人的信息如下：" << endl;
		this->m_workerArry[ret]->showInfo();
	}
	else {
		cout << "查无此人！" << endl;
	}
}
// 5.2、按姓名查找
void WorkerManager::find_WorkerByName(string name) {
	bool flag = false;//默认没找到
	for (int i = 0; i < this->m_workerNum; i++) {
		if (this->m_workerArry[i]->m_name == name) {
			cout << "查到编号为" << this->m_workerArry[i]->m_id << "的人的信息如下：" << endl;
			this->m_workerArry[i]->showInfo();
			flag = true;
		}
	}
	if (!flag) {
		cout << "查无此人！" << endl;
	}
}

//析构函数
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
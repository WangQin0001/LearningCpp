#include <iostream>
using namespace std;

#include "WorkerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//测试多态
//void test() {
//	Worker* worker = NULL;//创建父类的指针
//
//	worker = new Employee(001, "仓鼠员工", 1);//父类指针指向子类对象，构成使用多态的条件
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(002, "仓鼠经理", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(003, "仓鼠老板", 3);
//	worker->showInfo();
//	delete worker;
//
//}

int main() {
	
	//test();//测试多态


	WorkerManager wm;

	int choice = 0;//用户输入的选择

	while (true) {
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.addWorker();
			break;
		case 2://显示职工
			wm.show_Worker();
			break;
		case 3://删除职工
			wm.delet_Worker();
			break;
		case 4://修改职工
			wm.mod_Worker();
			break;
		case 5://查找职工
			wm.find_Worker();
			break;
		case 6://按编号排序
			wm.sort_Worker();
			break;
		case 7://清空
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
		system("cls");
	}


	system("pause");
	return 0;
}
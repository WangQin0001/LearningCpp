#include <iostream>
using namespace std;

#include "WorkerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//���Զ�̬
//void test() {
//	Worker* worker = NULL;//���������ָ��
//
//	worker = new Employee(001, "����Ա��", 1);//����ָ��ָ��������󣬹���ʹ�ö�̬������
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(002, "������", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(003, "�����ϰ�", 3);
//	worker->showInfo();
//	delete worker;
//
//}

int main() {
	
	//test();//���Զ�̬


	WorkerManager wm;

	int choice = 0;//�û������ѡ��

	while (true) {
		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.addWorker();
			break;
		case 2://��ʾְ��
			wm.show_Worker();
			break;
		case 3://ɾ��ְ��
			wm.delet_Worker();
			break;
		case 4://�޸�ְ��
			wm.mod_Worker();
			break;
		case 5://����ְ��
			wm.find_Worker();
			break;
		case 6://���������
			wm.sort_Worker();
			break;
		case 7://���
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
/*ע���
* 1.ͷ�ļ��е�ÿһ����������Դ�ļ��ж��������ʵ�֣�����ʵ��Ϊ��ҲҪд

*/

#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;//ʹ�ñ�׼�������ռ�

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "workerFile.txt"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void showMenu();

	//0.�˳�ϵͳ
	void exitSystem();

	//1�����Ա��
	void addWorker();
	// 1.1������Ա��
	void saveWorker();
	// 1.2����ȡԱ������
	int get_WorkerNum();
	// 1.3����ʼ��Ա��
	void init_Worker();
	// 1.4���ж�Ա��id�Ƿ��ظ�
	bool idNotExist(int id);

	//2��չʾԱ��
	void show_Worker();

	//3��ɾ��Ա��
	void delet_Worker();
	// 3.1���ж��Ƿ����ĳԱ��
	int isExist(int id);

	//4���޸�Ա��
	void mod_Worker();

	//5������Ա��
	void find_Worker();
	// 5.1������Ų���
	void find_WorkerById(int id);
	// 5.2������������
	void find_WorkerByName(string name);

	//6������
	void sort_Worker();

	//7������ļ�
	void clean_File();
	//��������
	~WorkerManager();

public:
	//����뽫���в�ͬ�����Ա�������뵽һ�������У����Խ�����Ա����ָ��ά����һ���������Ϊ������ֻ��ͬʱ�洢һ���������ͣ���ָ��������������ͬ��
	//������ڳ�����ά������������ȵ����飬���Խ����鴴����������������Worker** ��ָ��ά��
	Worker ** m_workerArry; //��worker�Ķ���ָ��ά������������ݣ���Ϊ���鿪���ڶ���������������Ϊworker��ָ�����ͣ�����Ҫ��worker�Ķ���ָ�������
	int m_workerNum;
	bool m_fileIsEmpty;
};
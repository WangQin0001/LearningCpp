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

	//0.�Ƴ�ϵͳ
	void exitSystem();

	//1�����Ա��
	void addWorker();
	void saveWorker();
	int get_WorkerNum();
	void init_Worker();

	//��������
	~WorkerManager();

public:
	//����뽫���в�ͬ�����Ա�������뵽һ�������У����Խ�����Ա����ָ��ά����һ���������Ϊ������ֻ��ͬʱ�洢һ���������ͣ���ָ��������������ͬ��
	//������ڳ�����ά������������ȵ����飬���Խ����鴴����������������Worker** ��ָ��ά��
	Worker ** m_workerArry; //��worker�Ķ���ָ��ά������������ݣ���Ϊ���鿪���ڶ���������������Ϊworker��ָ�����ͣ�����Ҫ��worker�Ķ���ָ�������
	int m_workerNum;
	bool m_fileIsEmpty;
};
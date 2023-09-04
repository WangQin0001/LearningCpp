/*注意点
* 1.头文件中的每一个函数，在源文件中都必须添加实现，就算实现为空也要写

*/

#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;//使用标准的命名空间

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "workerFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void showMenu();

	//0.推出系统
	void exitSystem();

	//1、添加员工
	void addWorker();
	void saveWorker();
	int get_WorkerNum();
	void init_Worker();

	//析构函数
	~WorkerManager();

public:
	//如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里，因为数组中只能同时存储一种数据类型，而指针数据类型是相同的
	//如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker** 的指针维护
	Worker ** m_workerArry; //用worker的二级指针维护数据里的数据，因为数组开辟在堆区并且数据类型为worker的指针类型，所以要用worker的二级指针接收它
	int m_workerNum;
	bool m_fileIsEmpty;
};
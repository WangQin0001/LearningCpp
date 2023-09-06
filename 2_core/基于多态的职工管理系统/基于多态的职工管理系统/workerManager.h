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

	//0.退出系统
	void exitSystem();

	//1、添加员工
	void addWorker();
	// 1.1、保存员工
	void saveWorker();
	// 1.2、获取员工数量
	int get_WorkerNum();
	// 1.3、初始化员工
	void init_Worker();
	// 1.4、判断员工id是否重复
	bool idNotExist(int id);

	//2、展示员工
	void show_Worker();

	//3、删除员工
	void delet_Worker();
	// 3.1、判断是否存在某员工
	int isExist(int id);

	//4、修改员工
	void mod_Worker();

	//5、查找员工
	void find_Worker();
	// 5.1、按编号查找
	void find_WorkerById(int id);
	// 5.2、按姓名查找
	void find_WorkerByName(string name);

	//6、排序
	void sort_Worker();

	//7、清空文件
	void clean_File();
	//析构函数
	~WorkerManager();

public:
	//如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里，因为数组中只能同时存储一种数据类型，而指针数据类型是相同的
	//如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker** 的指针维护
	Worker ** m_workerArry; //用worker的二级指针维护数据里的数据，因为数组开辟在堆区并且数据类型为worker的指针类型，所以要用worker的二级指针接收它
	int m_workerNum;
	bool m_fileIsEmpty;
};
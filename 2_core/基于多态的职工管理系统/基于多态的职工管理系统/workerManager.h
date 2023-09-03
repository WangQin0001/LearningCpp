/*注意点
* 1.头文件中的每一个函数，在源文件中都必须添加实现，就算实现为空也要写

*/

#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;//使用标准的命名空间

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void showMenu();

	//0.推出系统
	void exitSystem();

	//析构函数
	~WorkerManager();
};
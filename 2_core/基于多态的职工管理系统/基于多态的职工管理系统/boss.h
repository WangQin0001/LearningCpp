#pragma onece
#include <iostream>
using namespace std;

#include <string>

#include "worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名
	virtual string getDeptName();
};

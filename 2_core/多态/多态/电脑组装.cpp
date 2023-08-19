/*
23年8月19日晚
学完了多态，实现了电脑组装
*/

#include <iostream>
using namespace std;

class cpu {
public://这里要加public，不然在computer中无法访问，因为类中的成员变量默认为私有的
	virtual void caculate() = 0;
};
class gpu {
public:
	virtual void show() = 0;
};
class memory {
public:
	virtual void storage() = 0;
};

class computer {
public:
	computer(cpu*cpu,gpu*gpu,memory*memory) {
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}
	void work() {
		m_cpu->caculate();
		m_gpu->show();
		m_memory->storage();
	}

	~computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL) {
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_memory != NULL) {
			delete m_memory;
			m_memory = NULL;
		}
	}
private:
	cpu* m_cpu;
	gpu* m_gpu;
	memory* m_memory;
	
};

//intel的零件
class intelCpu :public cpu {
public:
	virtual void caculate() {
		cout << "intel的cpu在计算" << endl;
	}
};
class intelGpu :public gpu {
public:
	void show() {
		cout << "intel的gpu在显示" << endl;
	}
};
class intelMemory :public memory {
public:
	void storage() {
		cout << "intel的memory在存储" << endl;
	}
};

//lenovo的零件
class lenovoCpu :public cpu {
public:
	virtual void caculate() {
		cout << "lenovo的cpu在计算" << endl;
	}
};
class lenovoGpu :public gpu {
public:
	void show() {
		cout << "lenovo的gpu在显示" << endl;
	}
};
class lenovoMemory :public memory {
public:
	void storage() {
		cout << "lenovo的memory在存储" << endl;
	}
};

void test03() {
	//创建第一台电脑
	cout << "--------------------第一台电脑----------------------------" << endl;
	cpu* cpu1 = new intelCpu;//这里的数据在computer的析构函数中释放
	gpu* gpu1 = new lenovoGpu;
	memory* memory1 = new intelMemory;
	computer* computer1 = new computer(cpu1,gpu1,memory1);
	computer1->work();
	delete computer1;//堆区的数据访问结束一定要释放

	cout << "--------------------第二台电脑----------------------------" << endl;
	//创建第二台电脑
	computer* computer2 = new computer(new lenovoCpu,new intelGpu,new lenovoMemory);
	computer2->work();
	delete computer2;
}

int main() {
	test03();
	system("pause");
	return 0;
}
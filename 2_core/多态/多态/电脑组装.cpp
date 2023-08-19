/*
23��8��19����
ѧ���˶�̬��ʵ���˵�����װ
*/

#include <iostream>
using namespace std;

class cpu {
public://����Ҫ��public����Ȼ��computer���޷����ʣ���Ϊ���еĳ�Ա����Ĭ��Ϊ˽�е�
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

//intel�����
class intelCpu :public cpu {
public:
	virtual void caculate() {
		cout << "intel��cpu�ڼ���" << endl;
	}
};
class intelGpu :public gpu {
public:
	void show() {
		cout << "intel��gpu����ʾ" << endl;
	}
};
class intelMemory :public memory {
public:
	void storage() {
		cout << "intel��memory�ڴ洢" << endl;
	}
};

//lenovo�����
class lenovoCpu :public cpu {
public:
	virtual void caculate() {
		cout << "lenovo��cpu�ڼ���" << endl;
	}
};
class lenovoGpu :public gpu {
public:
	void show() {
		cout << "lenovo��gpu����ʾ" << endl;
	}
};
class lenovoMemory :public memory {
public:
	void storage() {
		cout << "lenovo��memory�ڴ洢" << endl;
	}
};

void test03() {
	//������һ̨����
	cout << "--------------------��һ̨����----------------------------" << endl;
	cpu* cpu1 = new intelCpu;//�����������computer�������������ͷ�
	gpu* gpu1 = new lenovoGpu;
	memory* memory1 = new intelMemory;
	computer* computer1 = new computer(cpu1,gpu1,memory1);
	computer1->work();
	delete computer1;//���������ݷ��ʽ���һ��Ҫ�ͷ�

	cout << "--------------------�ڶ�̨����----------------------------" << endl;
	//�����ڶ�̨����
	computer* computer2 = new computer(new lenovoCpu,new intelGpu,new lenovoMemory);
	computer2->work();
	delete computer2;
}

int main() {
	test03();
	system("pause");
	return 0;
}
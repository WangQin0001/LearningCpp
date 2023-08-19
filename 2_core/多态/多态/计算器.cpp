/*
23年8月19日
用多态的方法实现两位整数的计算器，对比传统方法实现计算器的优略
*/

//#include <iostream>
//using namespace std;
//
//class AbstractCaculator {
//public:
//	virtual int getResult() {//虚函数
//		return 0;
//	}
//public:
//	int a;
//	int b;
//};
//
//class addCaculator :public AbstractCaculator {
//	int getResult() {//多态的产生条件：子类重写父类虚函数
//		return a + b;
//	}
//};
//
//class delCaculator :public AbstractCaculator {
//	int getResult() {
//		return a - b;
//	}
//};
//
//
//class mulCaculator :public AbstractCaculator {
//	int getResult() {
//		return a * b;
//	}
//};
//
//
//void test01() {
//	AbstractCaculator* abc;//父类指针
//
//	abc = new addCaculator;//多态的使用条件：父类指针指向子类对象
//	abc->a = 10;
//	abc->b = 10;
//	cout << abc->a << "+" <<abc->b << "=" << abc->getResult() << endl;
//	delete abc;//在堆区开辟的空间要程序员主动释放
//
//	abc = new delCaculator;
//	abc->a = 100;
//	abc->b = 10;
//	cout << abc->a << "-" << abc->b << "=" << abc->getResult() << endl;
//	delete abc;
//
//	abc = new mulCaculator;
//	abc->a = 10;
//	abc->b = 10;
//	cout << abc->a << "*" << abc->b << "=" << abc->getResult() << endl;
//	delete abc;
//}
//
//int main() {
//	test01();
//	return 0;
//}
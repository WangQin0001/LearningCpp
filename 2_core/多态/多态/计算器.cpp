/*
23��8��19��
�ö�̬�ķ���ʵ����λ�����ļ��������Աȴ�ͳ����ʵ�ּ�����������
*/

//#include <iostream>
//using namespace std;
//
//class AbstractCaculator {
//public:
//	virtual int getResult() {//�麯��
//		return 0;
//	}
//public:
//	int a;
//	int b;
//};
//
//class addCaculator :public AbstractCaculator {
//	int getResult() {//��̬�Ĳ���������������д�����麯��
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
//	AbstractCaculator* abc;//����ָ��
//
//	abc = new addCaculator;//��̬��ʹ������������ָ��ָ���������
//	abc->a = 10;
//	abc->b = 10;
//	cout << abc->a << "+" <<abc->b << "=" << abc->getResult() << endl;
//	delete abc;//�ڶ������ٵĿռ�Ҫ����Ա�����ͷ�
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
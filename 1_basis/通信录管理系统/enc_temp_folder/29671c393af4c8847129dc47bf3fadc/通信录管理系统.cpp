#include <iostream>
using namespace std;
#include <string>

#define MAX 1000 //定义宏常量的时候不用在末尾添加；
//联系人结构体
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

 
//通信录结构体
struct Addressbook
{
	struct Person personArray[MAX];//Person结构体类型的数组
	int size;
};

void addPerson(Addressbook * ads) {//指针接收地址
	if (ads->size == MAX) {
		cout << "超出通信录最多人数" << endl;
		return;
	}

	//姓名
	cout << "Please enter name:" << endl;
	string addName;
	cin >> addName;
	ads->personArray[ads->size].name = addName;
	//性别
	while (true) {
		cout << "Please enter sex:" << endl;
		cout << "1--male       2--female" << endl;
		int addSex = 0;
		cin >> addSex;
		ads->personArray[ads->size].sex = addSex;
		if (addSex == 1 || addSex == 2) {
			break;
		}
	}
	//年龄
	cout << "Please enter age:" << endl;
	int addAge;
	cin >> addAge;
	ads->personArray[ads->size].age = addAge;
	//电话
	cout << "Please enter phone number:" << endl;
	string addPhone;
	cin >> addPhone;
	ads->personArray[ads->size].phone = addPhone;
	//地址
	cout << "Please enter address:" << endl;
	string addAddress;
	cin >> addAddress;
	ads->personArray[ads->size].address = addAddress;
}

void showContacts(Addressbook ads) {
	for (int i = 0; i <= ads.size; i++) {
		cout << "name:" + ads.personArray[ads.size].name;
		cout << "sex:" + ads.personArray[ads.size].sex;
		cout << "age:" + ads.personArray[ads.size].age;
		cout << "phone:" + ads.personArray[ads.size].phone;
		cout << "address:" + ads.personArray[ads.size].address;
	}
}

void showMenu() {
	cout << "*****************************************" << endl;
	cout << "*********** 1.ADD contacts  *************" << endl;
	cout << "*********** 2.SHOW contacts *************" << endl;
	cout << "*********** 3.DELETE contants ***********" << endl;
	cout << "*********** 4.SEARCH contants ***********" << endl;
	cout << "*********** 5.CHANGE contants *********** " << endl;
	cout << "*********** 6.CLEAN all contants ********" << endl;
	cout << "*********** 0.QUIT  *********************" << endl;
	cout << "*****************************************" << endl;

}

int main() {

	//初始化一个通信录
	Addressbook ads;
	ads.size = 0;

	while (true) {
		showMenu();

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&ads);//地址传递，让形参可以修饰实参
			ads.size ++;
			break;
		case 2:
			showContacts(ads);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "see you next time!" << endl;
			return 0;//直接终止while循环
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
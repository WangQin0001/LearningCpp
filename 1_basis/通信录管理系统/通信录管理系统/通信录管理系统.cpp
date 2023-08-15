/*
23年8月16日完成
只做了添加、展示、删除的功能，目的是复习cpp基础语法
*/

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

//添加联系人
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

	ads->size++;
	cout << "ADD person SUCCESS!";
	system("pause");//按任意键继续
	system("cls");//按任意键清屏
}

//展示联系人
void showContacts(Addressbook ads) {
	if (ads.size == 0) {
		cout << "NO person in contact" << endl;
		return;
	}
	else {
		for (int i = 0; i < ads.size; i++) {
			cout << "name: " << ads.personArray[i].name<<"\t";
			cout << "sex: " << (ads.personArray[i].sex==1?"male":"female") << "\t";
			cout << "age: " << ads.personArray[i].age << "\t";
			cout << "phone: " << ads.personArray[i].phone << "\t";
			cout << "address: " << ads.personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");

}

//查找联系人
int isExit(Addressbook * ads,string name) {
	for (int i = 0; i < ads->size; i++) {
		if (name == ads->personArray[i].name) {
			return i;//返回数组下标
		}
	}
	return -1;
}

//删除联系人
void deletePerson(Addressbook * ads) {
	cout << "Please enter the name you want to delete：" << endl;
	string name;
	cin >> name;
	int index = isExit(ads, name);
	if (index == -1) {
		cout << "not exit this person in contact"<<endl;
	}
	else {
		for (int i=index; i < ads->size; i++) {
			ads->personArray[i] = ads->personArray[i+1];
		}
		ads->size--;//删除联系人后，一定要将数组长度减一，不然查看联系人时会得到奇怪的信息。
		cout << "delete SUCCESS" << endl;
	}
	system("pause");
	system("cls");
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
			break;
		case 2:
			showContacts(ads);
			break;
		case 3:
			//cout<<(isExit(ads, isExitName)==1?"存在":"不存在")<<endl; //测试查找联系人的功能
			deletePerson(&ads);
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
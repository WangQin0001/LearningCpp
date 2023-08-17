#include <iostream>
using namespace std;
#include <string>

#define MAX 1000 //����곣����ʱ������ĩβ��ӣ�
//��ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

 
//ͨ��¼�ṹ��
struct Addressbook
{
	struct Person personArray[MAX];//Person�ṹ�����͵�����
	int size;
};

void addPerson(Addressbook * ads) {//ָ����յ�ַ
	if (ads->size == MAX) {
		cout << "����ͨ��¼�������" << endl;
		return;
	}

	//����
	cout << "Please enter name:" << endl;
	string addName;
	cin >> addName;
	ads->personArray[ads->size].name = addName;
	//�Ա�
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
	//����
	cout << "Please enter age:" << endl;
	int addAge;
	cin >> addAge;
	ads->personArray[ads->size].age = addAge;
	//�绰
	cout << "Please enter phone number:" << endl;
	string addPhone;
	cin >> addPhone;
	ads->personArray[ads->size].phone = addPhone;
	//��ַ
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

	//��ʼ��һ��ͨ��¼
	Addressbook ads;
	ads.size = 0;

	while (true) {
		showMenu();

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&ads);//��ַ���ݣ����βο�������ʵ��
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
			return 0;//ֱ����ֹwhileѭ��
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
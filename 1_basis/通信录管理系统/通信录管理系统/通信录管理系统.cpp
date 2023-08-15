/*
23��8��16�����
ֻ������ӡ�չʾ��ɾ���Ĺ��ܣ�Ŀ���Ǹ�ϰcpp�����﷨
*/

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

//�����ϵ��
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

	ads->size++;
	cout << "ADD person SUCCESS!";
	system("pause");//�����������
	system("cls");//�����������
}

//չʾ��ϵ��
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

//������ϵ��
int isExit(Addressbook * ads,string name) {
	for (int i = 0; i < ads->size; i++) {
		if (name == ads->personArray[i].name) {
			return i;//���������±�
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(Addressbook * ads) {
	cout << "Please enter the name you want to delete��" << endl;
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
		ads->size--;//ɾ����ϵ�˺�һ��Ҫ�����鳤�ȼ�һ����Ȼ�鿴��ϵ��ʱ��õ���ֵ���Ϣ��
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
			break;
		case 2:
			showContacts(ads);
			break;
		case 3:
			//cout<<(isExit(ads, isExitName)==1?"����":"������")<<endl; //���Բ�����ϵ�˵Ĺ���
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
			return 0;//ֱ����ֹwhileѭ��
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
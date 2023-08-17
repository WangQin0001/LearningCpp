# LearningCpp

1. break语句不能在if中使用，目前发现只能在while中使用

   	while (true) {
      		cout << "Please enter sex:" << endl;
      		cout << "1--male       2--female" << endl;
      		int sex = 0;
      		cin >> sex;
      		if (sex == 1 || sex == 2) {
      			break;
      		}
      	}

2. #define MAX 1000 //定义宏常量的时候不用在末尾添加；

3. void 类型的函数，也能写个return来中止函数

   void addPerson(Addressbook * ads) {//指针接收地址
   	if (ads->size == MAX) {
   		cout << "超出通信录最多人数" << endl;
   		return;
   	}
   
   }

4. 三目运算符判断男女

   ​			cout << "sex: " << (ads.personArray[i].sex==1?"male":"female") << "\t";
   
5. 值传递的本质是拷贝一个临时的副本出来，所以尽量用地址传递别用值传递
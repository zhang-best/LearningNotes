# include <iostream>
# include <string>
using namespace std;
#define MAX 1000
//定义结构体
struct Person {
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct Book {
	struct Person personArray[MAX];
	int personNum;
};
//函数功能定义
void showMenu() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}
//0、退出通讯录
void outMenu() {
	cout << "欢迎下次使用" << endl;
	system("pause");
}
//1、添加联系人
void addPerson(struct Book* abs) {
	if (abs->personNum >= MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string name_;
		cout << "请输入姓名" << endl;
		cin >> name_;
		abs->personArray[abs->personNum].name = name_;
		int sex_ = 0;
		cout << "请输入性别：1-man ******  2-woman" << endl;
		while (true) {
			cin >> sex_;
			if (sex_ == 1 || sex_ == 2) {
				abs->personArray[abs->personNum].sex = sex_;
				break;
			}
			else {
				cout << "输入错误，请重新输入性别：1-man ******  2-woman" << endl;
			}
		}
		int age_;
		cout << "请输入年龄" << endl;
		cin >> age_;
		abs->personArray[abs->personNum].age = age_;
		string phone_;
		cout << "请输入电话号码" << endl;
		cin >> phone_;
		abs->personArray[abs->personNum].phone = phone_;
		string address_;
		cout << "请输入地址" << endl;
		cin >> address_;
		abs->personArray[abs->personNum].address = address_;
		abs->personNum++;
		return;
	}
}
//2、显示联系人
void showPerson(struct Book* abs) {
	if (abs->personNum == 0) {
		cout << "通讯录空" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->personNum; i++) {
			cout << abs->personArray[i].name << "\t";
			cout << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << abs->personArray[i].age << "\t";
			cout << abs->personArray[i].phone << "\t";
			cout << abs->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人
int isExist(struct Book* abs, string name_) {
	for (int i = 0; i < abs->personNum; i++) {
		if (abs->personArray[i].name == name_) {
			return i;
		}
	}
	return -1;
}
//3、删除联系人
void deletePerson(struct Book* abs) {
	if (abs->personNum == 0) {
		cout << "通讯录空" << endl;
		return;
	}
	else {
		string name_;
		cout << "请输入要删除的联系人姓名" << endl;
		cin >> name_;
		int ret = isExist(abs, name_);
		if (ret != -1) {
			for (int i = ret; i < abs->personNum - 1; i++) {
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->personNum--;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//4、查找联系人
void findPerson(struct Book* abs) {
	string name_;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name_;
	int ret = isExist(abs, name_);
	if (ret != -1) {
		cout << abs->personArray[ret].name << "\t";
		cout << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << abs->personArray[ret].age << "\t";
		cout << abs->personArray[ret].phone << "\t";
		cout << abs->personArray[ret].address << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5、修改联系人
void changePerson(struct Book* abs) {
	string name_;
	cout << "请输入要修改的联系人姓名" << endl;
	cin >> name_;
	int ret = isExist(abs, name_);
	if (ret != -1) {
		string name_;
		cout << "请输入姓名" << endl;
		cin >> name_;
		abs->personArray[ret].name = name_;
		int sex_ = 0;
		cout << "请输入性别：1-man ******  2-woman" << endl;
		while (true) {
			cin >> sex_;
			if (sex_ == 1 || sex_ == 2) {
				abs->personArray[ret].sex = sex_;
				break;
			}
			else {
				cout << "输入错误，请重新输入性别：1-man ******  2-woman" << endl;
			}
		}
		int age_;
		cout << "请输入年龄" << endl;
		cin >> age_;
		abs->personArray[ret].age = age_;
		string phone_;
		cout << "请输入电话号码" << endl;
		cin >> phone_;
		abs->personArray[ret].phone = phone_;
		string address_;
		cout << "请输入地址" << endl;
		cin >> address_;
		abs->personArray[ret].address = address_;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6、清空联系人
void clearPerson(struct Book* abs) {
	abs->personNum = 0;
	cout << "通讯录已空" << endl;
}

int main() {
	Book abs;
	abs.personNum = 0;//初始化通讯录
	int select;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 0:
			outMenu();
			return 0;
			break;
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			changePerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		default:
			break;
		}
	}
	return 0;
}
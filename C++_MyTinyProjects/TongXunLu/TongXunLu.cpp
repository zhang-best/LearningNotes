#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person 
{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Address;

};
struct AddBook 
{
	struct Person personArray[MAX];
	int Size;
};

//菜单界面
void showMenu() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}

//添加联系人
void addPerson(AddBook* abs)
{
	if (abs->Size == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//
		string namet;
		cout << "请输入姓名" << endl;
		cin >> namet;
		abs->personArray[abs->Size].Name = namet;
		//
		cout << "请输入性别：" << endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->Size].Sex = sex;
				break;
			}
			else cout << "请重新输入" << endl;
		}
		//
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->Size].Age = age;
		//
		cout << "请输入电话号码" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->Size].Phone = phone;
		//
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->Size].Address = address;
		//
		abs->Size++;
		cout << "输入成功" << endl;
		return;
	}
}
//显示联系人
void showPerson(AddBook * abs) {
	if (abs->Size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->Size; i++) {
			cout << "姓名：" << abs->personArray[i].Name << "\t";
			cout << "性别：" << (abs->personArray[i].Sex == 1 ? "男" : "女")<< "\t";
			cout << "年龄：" << abs->personArray[i].Age << "\t";
			cout << "电话：" << abs->personArray[i].Phone << "\t";
			cout << "地址：" << abs->personArray[i].Address << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人
int isExist(AddBook * abs,string name) {
	for(int i=0;i<abs->Size;i++){
		if (abs->personArray[i].Name == name) {
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(AddBook * abs) {
	cout << "请输入您要删除的人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->Size-1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->Size--;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(AddBook * abs) {
	cout << "请输入查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].Name << "\t";
		cout << "性别：" << (abs->personArray[ret].Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].Age << "\t";
		cout << "电话：" << abs->personArray[ret].Phone << "\t";
		cout << "地址：" << abs->personArray[ret].Address << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void changePerson(AddBook * abs) {
	cout << "请输入修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string namet;
		cout << "请输入姓名" << endl;
		cin >> namet;
		abs->personArray[ret].Name = namet;
		//
		cout << "请输入性别：" << endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].Sex = sex;
				break;
			}
			else cout << "请重新输入" << endl;
		}
		//
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].Age = age;
		//
		cout << "请输入电话号码" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].Phone = phone;
		//
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].Address = address;
		//
		cout << "输入成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空
void clearPerson(AddBook * abs) {
	abs->Size = 0;
	cout << "通讯录已空" << endl;
}
int main() {
	//
	AddBook abs;
	abs.Size = 0;
	
	
	int select=0;
	
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
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
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
	    }
	}
	
	return 0;
}
# include <iostream>
# include <string>
using namespace std;
#define MAX 1000
//����ṹ��
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
//�������ܶ���
void showMenu() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}
//0���˳�ͨѶ¼
void outMenu() {
	cout<<"��ӭ�´�ʹ��" << endl;
	system("pause");
}
//1�������ϵ��
void addPerson(struct Book * abs) {
	if (abs->personNum >= MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name_;
		cout << "����������" << endl;
		cin >> name_;
		abs->personArray[abs->personNum].name = name_;
		int sex_=0;
		cout << "�������Ա�1-man ******  2-woman" << endl;
		while (true) {
			cin >> sex_;
			if (sex_ == 1 || sex_ == 2) {
				abs->personArray[abs->personNum].sex = sex_;
				break;
			}
			else {
				cout << "������������������Ա�1-man ******  2-woman" << endl;
			}
		}
		int age_;
		cout << "����������" << endl;
		cin >> age_;
		abs->personArray[abs->personNum].age = age_;
		string phone_;
		cout << "������绰����" << endl;
		cin >> phone_;
		abs->personArray[abs->personNum].phone = phone_;
		string address_;
		cout << "�������ַ" << endl;
		cin >> address_;
		abs->personArray[abs->personNum].address = address_;
		abs->personNum++;
		return;
	}
}
//2����ʾ��ϵ��
void showPerson(struct Book * abs) {
	if (abs->personNum == 0) {
		cout << "ͨѶ¼��" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->personNum; i++) {
			cout << abs->personArray[i].name << "\t";
			cout << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << abs->personArray[i].age << "\t";
			cout << abs->personArray[i].phone << "\t";
			cout << abs->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ��
int isExist(struct Book * abs,string name_) {
	for (int i = 0; i < abs->personNum; i++) {
		if (abs->personArray[i].name == name_) {
			return i;
		}
	}
	return -1;
}
//3��ɾ����ϵ��
void deletePerson(struct Book* abs) {
	if (abs->personNum == 0) {
		cout << "ͨѶ¼��" << endl;
		return;
	}
	else {
		string name_;
		cout << "������Ҫɾ������ϵ������" << endl;
		cin >> name_;
		int ret = isExist(abs, name_);
		if (ret != -1) {
			for (int i = ret; i < abs->personNum - 1; i++) {
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->personNum--;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//4��������ϵ��
void findPerson(struct Book* abs) {
	string name_;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name_;
	int ret = isExist(abs, name_);
	if (ret != -1) {
		cout << abs->personArray[ret].name << "\t";
		cout << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << abs->personArray[ret].age << "\t";
		cout << abs->personArray[ret].phone << "\t";
		cout << abs->personArray[ret].address << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸���ϵ��
void changePerson(struct Book* abs) {
	string name_;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name_;
	int ret = isExist(abs, name_);
	if (ret != -1) {
		string name_;
		cout << "����������" << endl;
		cin >> name_;
		abs->personArray[ret].name = name_;
		int sex_ = 0;
		cout << "�������Ա�1-man ******  2-woman" << endl;
		while (true) {
			cin >> sex_;
			if (sex_ == 1 || sex_ == 2) {
				abs->personArray[ret].sex = sex_;
				break;
			}
			else {
				cout << "������������������Ա�1-man ******  2-woman" << endl;
			}
		}
		int age_;
		cout << "����������" << endl;
		cin >> age_;
		abs->personArray[ret].age = age_;
		string phone_;
		cout << "������绰����" << endl;
		cin >> phone_;
		abs->personArray[ret].phone = phone_;
		string address_;
		cout << "�������ַ" << endl;
		cin >> address_;
		abs->personArray[ret].address = address_;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6�������ϵ��
void clearPerson(struct Book* abs) {
	abs->personNum = 0;
	cout << "ͨѶ¼�ѿ�" << endl;
}

int main() {
	Book abs;
	abs.personNum = 0;//��ʼ��ͨѶ¼
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
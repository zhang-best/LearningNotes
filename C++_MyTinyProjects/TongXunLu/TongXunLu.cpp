#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
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

//�˵�����
void showMenu() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}

//�����ϵ��
void addPerson(AddBook* abs)
{
	if (abs->Size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//
		string namet;
		cout << "����������" << endl;
		cin >> namet;
		abs->personArray[abs->Size].Name = namet;
		//
		cout << "�������Ա�" << endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->Size].Sex = sex;
				break;
			}
			else cout << "����������" << endl;
		}
		//
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->Size].Age = age;
		//
		cout << "������绰����" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->Size].Phone = phone;
		//
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->Size].Address = address;
		//
		abs->Size++;
		cout << "����ɹ�" << endl;
		return;
	}
}
//��ʾ��ϵ��
void showPerson(AddBook * abs) {
	if (abs->Size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->Size; i++) {
			cout << "������" << abs->personArray[i].Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].Sex == 1 ? "��" : "Ů")<< "\t";
			cout << "���䣺" << abs->personArray[i].Age << "\t";
			cout << "�绰��" << abs->personArray[i].Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].Address << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ��
int isExist(AddBook * abs,string name) {
	for(int i=0;i<abs->Size;i++){
		if (abs->personArray[i].Name == name) {
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void deletePerson(AddBook * abs) {
	cout << "��������Ҫɾ������" << endl;
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
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(AddBook * abs) {
	cout << "��������ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].Age << "\t";
		cout << "�绰��" << abs->personArray[ret].Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].Address << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void changePerson(AddBook * abs) {
	cout << "�������޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string namet;
		cout << "����������" << endl;
		cin >> namet;
		abs->personArray[ret].Name = namet;
		//
		cout << "�������Ա�" << endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].Sex = sex;
				break;
			}
			else cout << "����������" << endl;
		}
		//
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].Age = age;
		//
		cout << "������绰����" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].Phone = phone;
		//
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].Address = address;
		//
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//���
void clearPerson(AddBook * abs) {
	abs->Size = 0;
	cout << "ͨѶ¼�ѿ�" << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
	    }
	}
	
	return 0;
}
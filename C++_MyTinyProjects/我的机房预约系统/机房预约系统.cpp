#include <iostream>
using namespace std;
#include <string>
//��ʾ������
void MainMenu()
{
	cout << "********��ӭʹ�û���ԤԼϵͳ***********" << endl;
	cout << "********1��ѧ������               ***********" << endl;
	cout << "********2����ʦ                      ***********" << endl;
	cout << "********3������Ա                   ***********" << endl;
	cout << "********0���˳�ϵͳ               ***********" << endl;
}
//��ʾѧ���ӽ���
void StudentMenu()
{
	cout << "********1������ԤԼ               ***********" << endl;
	cout << "********2���鿴�ҵ�ԤԼ        ***********" << endl;
	cout << "********3���鿴����ԤԼ        ***********" << endl;
	cout << "********0��ע����¼               ***********" << endl;
}
//��ʾ��ʦ�ӽ���
void TeacherMenu()
{
	cout << "********1������ԤԼ               ***********" << endl;
	cout << "********2���鿴�ҵ�ԤԼ        ***********" << endl;
	cout << "********3���鿴����ԤԼ        ***********" << endl;
	cout << "********0��ע����¼               ***********" << endl;
}
//��ʾ����Ա�ӽ���
void ManagerMenu()
{
	cout << "********1������ԤԼ               ***********" << endl;
	cout << "********2���鿴�ҵ�ԤԼ        ***********" << endl;
	cout << "********3���鿴����ԤԼ        ***********" << endl;
	cout << "********0��ע����¼               ***********" << endl;
}

int main()
{
	int select = 0;
	while (true)
	{
		MainMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			system("pause");
			return 0;
			break;
		case 1:
			StudentMenu();
			break;
		case 2:
			TeacherMenu();
			break;
		case 3:
			ManagerMenu();
			break;
		default:
			break;
		}
	}
	return 0;
}
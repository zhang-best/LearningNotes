#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "�����������������" << endl;
		cin >> choice;
		switch (choice) {
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.modify_Emp();
			break;
		case 5://����ְ��
			wm.find_Emp();
			break;
		case 6://����ְ��
			wm.sort_Emp();
			break;
		case 7://����ĵ�
			wm.clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

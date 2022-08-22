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
		cout << "请输入您的需求代号" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.modify_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			wm.sort_Emp();
			break;
		case 7://清空文档
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

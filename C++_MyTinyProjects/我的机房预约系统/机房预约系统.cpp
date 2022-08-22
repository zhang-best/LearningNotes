#include <iostream>
using namespace std;
#include <string>
//显示主界面
void MainMenu()
{
	cout << "********欢迎使用机房预约系统***********" << endl;
	cout << "********1、学生代表               ***********" << endl;
	cout << "********2、老师                      ***********" << endl;
	cout << "********3、管理员                   ***********" << endl;
	cout << "********0、退出系统               ***********" << endl;
}
//显示学生子界面
void StudentMenu()
{
	cout << "********1、申请预约               ***********" << endl;
	cout << "********2、查看我的预约        ***********" << endl;
	cout << "********3、查看所有预约        ***********" << endl;
	cout << "********0、注销登录               ***********" << endl;
}
//显示老师子界面
void TeacherMenu()
{
	cout << "********1、申请预约               ***********" << endl;
	cout << "********2、查看我的预约        ***********" << endl;
	cout << "********3、查看所有预约        ***********" << endl;
	cout << "********0、注销登录               ***********" << endl;
}
//显示管理员子界面
void ManagerMenu()
{
	cout << "********1、申请预约               ***********" << endl;
	cout << "********2、查看我的预约        ***********" << endl;
	cout << "********3、查看所有预约        ***********" << endl;
	cout << "********0、注销登录               ***********" << endl;
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
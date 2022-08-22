#include "workerManager.h"
WorkerManager::WorkerManager() {
	//文件不存在
	ifstream ifs;
	ifs.open(Filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

void WorkerManager::Add_Emp() {
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace =  new Worker* [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第"<<i+1<<"个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "职工岗位" << endl;
			cout << "1/普通职工" << endl;
			cout << "2/经理" << endl;
			cout << "3/老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << endl;
		this->save();
	}
	else {
		cout <<"输入数据有误"<< endl;
	}
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(Filename, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int  WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id&&ifs>>name&&ifs>>dId) {
		num++;
	}
	return num;
}
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::show_Emp(){
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "输入要删除的编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			for (int i = ret; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::modify_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "输入要修改的编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int id;
			string name;
			int dSelect;
			cout << "请输入新职工编号" << endl;
			cin >> id;
			cout << "请输入新职工姓名" << endl;
			cin >> name;
			cout << "请输入职工岗位" << endl;
			cout << "1/普通职工" << endl;
			cout << "2/经理" << endl;
			cout << "3/老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "查找方式：1、编号；2、姓名" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "职工编号：" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1) {
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "查找姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入错误" << endl;
		}
	}
}
void WorkerManager::sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "1、升序；2、降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[minormax]->m_Id) {
						minormax = j;
					}
				}
				else {
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[minormax]->m_Id) {
						minormax = j;
					}
				}
			}
			if (minormax != i) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序结果" << endl;
		this->save();
		this->show_Emp();
	}
}
void WorkerManager::clean_Emp() {
	cout << "确定清空？1、确定；2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(Filename, ios::trunc);//删除文件后重建
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "成功" << endl;
	}
}
void WorkerManager::Show_Menu() {
	cout << "**************************************" << endl;
	cout << "*******欢迎使用职工管理系统！*******" << endl;
	cout << "***********0.退出管理程序************" << endl;
	cout << "***********1.增加职工信息************" << endl;
	cout << "***********2.显示职工信息************" << endl;
	cout << "***********3.删除离职职工************" << endl;
	cout << "***********4.修改职工信息************" << endl;
	cout << "***********5.查找职工信息************" << endl;
	cout << "***********6.按照编号排序************" << endl;
	cout << "***********7.清空所有文档************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
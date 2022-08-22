#include "workerManager.h"
WorkerManager::WorkerManager() {
	//�ļ�������
	ifstream ifs;
	ifs.open(Filename, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

void WorkerManager::Add_Emp() {
	cout << "���������ְ��������" << endl;
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
			cout << "�������"<<i+1<<"����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "ְ����λ" << endl;
			cout << "1/��ְͨ��" << endl;
			cout << "2/����" << endl;
			cout << "3/�ϰ�" << endl;
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
		cout << "�ɹ����" << endl;
		this->save();
	}
	else {
		cout <<"������������"<< endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "����Ҫɾ���ı��" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			for (int i = ret; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::modify_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "����Ҫ�޸ĵı��" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int id;
			string name;
			int dSelect;
			cout << "��������ְ�����" << endl;
			cin >> id;
			cout << "��������ְ������" << endl;
			cin >> name;
			cout << "������ְ����λ" << endl;
			cout << "1/��ְͨ��" << endl;
			cout << "2/����" << endl;
			cout << "3/�ϰ�" << endl;
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
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "���ҷ�ʽ��1����ţ�2������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "ְ����ţ�" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1) {
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "����������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "���޴���" << endl;
			}
		}
		else {
			cout << "�������" << endl;
		}
	}
}
void WorkerManager::sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "1������2������" << endl;
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
		cout << "������" << endl;
		this->save();
		this->show_Emp();
	}
}
void WorkerManager::clean_Emp() {
	cout << "ȷ����գ�1��ȷ����2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(Filename, ios::trunc);//ɾ���ļ����ؽ�
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
		cout << "�ɹ�" << endl;
	}
}
void WorkerManager::Show_Menu() {
	cout << "**************************************" << endl;
	cout << "*******��ӭʹ��ְ������ϵͳ��*******" << endl;
	cout << "***********0.�˳��������************" << endl;
	cout << "***********1.����ְ����Ϣ************" << endl;
	cout << "***********2.��ʾְ����Ϣ************" << endl;
	cout << "***********3.ɾ����ְְ��************" << endl;
	cout << "***********4.�޸�ְ����Ϣ************" << endl;
	cout << "***********5.����ְ����Ϣ************" << endl;
	cout << "***********6.���ձ������************" << endl;
	cout << "***********7.��������ĵ�************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
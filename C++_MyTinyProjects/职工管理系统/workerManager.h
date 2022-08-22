#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"

#include <fstream>
#define Filename "empFile.txt"
class WorkerManager {
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	int m_EmpNum;
	Worker** m_EmpArray;
	void Add_Emp();
	void save();
	bool m_FileIsEmpty;
	int get_EmpNum();
	void init_Emp();
	void show_Emp();
	int IsExist(int id);
	void del_Emp();
	void modify_Emp();
	void find_Emp();
	void sort_Emp();
	void clean_Emp();
	~WorkerManager();
};
#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
class Student : Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	void applyOrder();
	void showmyOrder();
	void showAllOrder();
	void deleteOrder();
	int m_Id;
};

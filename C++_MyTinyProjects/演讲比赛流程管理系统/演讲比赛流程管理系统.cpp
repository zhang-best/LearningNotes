#include <iostream>
using namespace std;
#include <string>
#include "speechManager.h"

int main() {
	srand((unsigned int)time(NULL));//
	SpeechManager sm;

	int select = 0;
	while (true) 
	{
		sm.show_Menu();
		cout << "请输入您的需求" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			sm.exitSystem();
			break;
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.cleanRecord();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include "speaker.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;
class SpeechManager 
{
public:
	SpeechManager();

	void show_Menu();

	void exitSystem();

	~SpeechManager();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();
	
	void show_Score();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void cleanRecord();
	map<int, vector<string>> m_Record;
	int m_Index;
	vector<int> v1;
	vector<int> v2;
	vector<int> vV;
	map<int, Speaker> m_Speaker;
	bool fileIsEmpty;
};
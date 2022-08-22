#include "speechManager.h"

SpeechManager::SpeechManager() 
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
void SpeechManager::show_Menu() 
{
	cout << "******************************" << endl;
	cout << "******1、开始演讲比赛*******" << endl;
	cout << "******2、查看往届记录*******" << endl;
	cout << "******3、清空比赛记录*******" << endl;
	cout << "******0、退出比赛程序*******" << endl;
	cout << "******************************" << endl;
}
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vV.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) 
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech() 
{
	//第一轮比赛
	this->speechDraw();
	this->speechContest();
	this->show_Score();
	//第二轮比赛
	this->m_Index++;
	this->speechDraw();
	this->speechContest();
	this->show_Score();
	//保存完成
	this->saveRecord();
	cout<<"本届比赛完成！"<<endl;
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	system("pause");
	system("cls");
}
void SpeechManager::speechDraw()
{
	cout << "抽签轮数" << this->m_Index << endl;
	cout << "------------------------------------" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
	system("pause");
	system("cls");
}
void SpeechManager::speechContest()
{
	cout << "比赛轮数" << this->m_Index << endl;
	cout << "------------------------------------" << endl;
	vector<int> vSrc;
	multimap<double, int, greater<double>> groupScore;
	int num = 0;
	if (this->m_Index == 1)
	{
		vSrc = v1;
	}
	else
	{
		vSrc = v2;
	}
	//
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(),0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		cout << this->m_Speaker[*it].m_Name<< "平均分:" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名词" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].m_Name
					<< "成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vV.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "----------第" << this->m_Index << "轮比赛完毕---------" << endl;
	system("pause");
}
void SpeechManager::show_Score()
{
	cout << "----------------------------------" << endl;
	cout << "第"<< this->m_Index << "轮晋级选手信息：" << endl;
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vV;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" <<*it << "姓名：" << this->m_Speaker[*it].m_Name
			<< "成绩：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vV.begin(); it != vV.end(); it++) 
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经完成" << endl;
	this->fileIsEmpty = false;
}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout <<"文件不存在"<< endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		int pos = -1;
		int start = 0;
		vector<string> v;
		while(true)
		{
			pos = data.find(',', start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "        " << it->second[0] << "        " << it->second[1] << endl;
	//}
}
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty == true)
	{
		cout << "为空" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++) 
	{
		cout<<"第"<<i+1<<"届冠军编号"<<this->m_Record[i][0] << "分数：" << this->m_Record[i][1] << endl;
		cout << "第" << i + 1 << "届亚军编号" << this->m_Record[i][2] << "分数：" << this->m_Record[i][3] << endl;
		cout << "第" << i + 1 << "届季军编号" << this->m_Record[i][4] << "分数：" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
void SpeechManager::cleanRecord()
{
	int select=0;
	cout << "清空：1；不：2" << endl;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
	}
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager() 
{

}
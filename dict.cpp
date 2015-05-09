#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include "file.h"

using namespace std;
bool file=0;

struct word
{
	string name;
	string enpron,uspron;
	vector<string> attr,expl;
	vector<string> exsentence,extrans;
	string initdata;
	void em()
	{
		name="";
		enpron="";uspron="";
		vector<string>().swap(attr);
		vector<string>().swap(expl);
		vector<string>().swap(exsentence);
		vector<string>().swap(extrans);
		initdata="";
	}	
}ww;

void gopys(string word2s)
{
	string strexec="";
	strexec+="python dict.py ";
	strexec+=word2s;
	const char* cstrexec=(const char*)strexec.c_str();
	system(cstrexec);
}

void sw(string w)
{
	gopys(w);
	dfile F;
	bool pron=0;
	F.readfile("tmp");
	//for (int i=0;i<F.lines.size();i++)
	//cout<<F.lines[i]<<endl;
	for (int i=0;i<F.lines.size();i++)
	{
		
		if (F.lines[i].substr(0,4)=="<ps>")
		{
			if (pron==0){
				pron=1;
				ww.enpron=F.lines[i].substr(4,F.lines[i].length()-10);
			}
			else
			{
				ww.uspron=F.lines[i].substr(4,F.lines[i].length()-10);
			}
		}
		if (F.lines[i].substr(0,5)=="<pos>")
		{
			ww.attr.push_back(F.lines[i].substr(5,F.lines[i].length()-12));
		}
		if (F.lines[i].substr(0,13)=="<acceptation>")
		{
			ww.expl.push_back(F.lines[i].substr(13,F.lines[i].length()-14));
		}
		if (F.lines[i].substr(0,12)=="<sent><orig>")
		{
			ww.exsentence.push_back(F.lines[i+1].substr(0,F.lines[i+1].length()-1));
		}
		if (F.lines[i].substr(0,7)=="<trans>")
		{
			ww.extrans.push_back(F.lines[i+1].substr(0,F.lines[i+1].length()-2));
		}
	}
	
	if (file==0){
	cout<<"\033[31mEN Pron: "<<ww.enpron<<endl<<"US Pron: "<<ww.uspron<<"\033[0m"<<endl;
	cout<<endl<<"\033[33mThe word has "<<ww.attr.size()<<" meaning(s)\033[0m"<<endl;
	for (int i=0;i<ww.attr.size();i++)
	{
		cout<<"\033[32m"<<ww.attr[i]<<"\033[0m "<<ww.expl[i]<<endl;
	}
	cout<<endl;
	cout<<"\033[33mHere are "<<ww.exsentence.size()<<" example(s)\033[0m"<<endl;
	for (int i=0;i<ww.exsentence.size();i++)
	{
		cout<<ww.exsentence[i]<<endl<<ww.extrans[i]<<endl<<endl;
	}
	}
	else
	{
	cout<<"EN Pron: "<<ww.enpron<<endl<<"US Pron: "<<ww.uspron<<endl;
	cout<<"The word has "<<ww.attr.size()<<" meaning(s)"<<endl;
	for (int i=0;i<ww.attr.size();i++)
	{
		cout<<ww.attr[i]<<ww.expl[i]<<endl;
	}
	cout<<"Here are "<<ww.exsentence.size()<<" example(s)"<<endl;
	for (int i=0;i<ww.exsentence.size();i++)
	{
		cout<<ww.exsentence[i]<<endl<<ww.extrans[i]<<endl;
	}
	}
	ww.em();
}

int main(int argc, char ** argv)
{
    if (argc==0){
	cout<<"enter the word to search"<<endl;
	string wr;
	while(cin>>wr)
	{
		if (wr=="exit()") break;
		sw(wr);
		cout<<"enter the word to search"<<endl;
	}
	}
	else
	{
		string tmp(argv[1]);
		freopen("result","w",stdout);
		file=1;
		sw(tmp);
	}
	return 0;
}


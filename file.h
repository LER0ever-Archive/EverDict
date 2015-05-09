#include <fstream>
#include <vector>
#include "afx.h"
using namespace std;
class dfile
{
public:
	vector<string> lines;
	void readfile(string fn);
};

void dfile::readfile(string fn)
{
	//cout<<"start reading"<<endl;
	ifstream ifile(fn.c_str());
	string tmp;
	while(getline(ifile,tmp))
	{
		//cout<<"r"<<endl;
		lines.push_back(tmp);
	}
	ifile.close();
	//cout<<"closed"<<endl;
}
/*
class gmfile
{
private:
	string filename;
	string filecontent;
	ifstream ifile;
	ofstream ofile;
public:
	int fileline;
	void openfile(string fn,bool bWrite);
	string readfilecontent(string fn);
	string readline(string fn,int linenum);
	void closefile(bool);
	void write2file(string str2write,string fn);
	void deletefile(string fn);
	int countline(string fn);
};

void gmfile::openfile(string fn,bool bWrite)
{
	if (bWrite==0)
	{
		ifile.open(fn.c_str());
	}	
	else
	{
		ofile.open(fn.c_str());
	}
}
void gmfile::closefile(bool opt)
{
	if(opt==0) ifile.close();
	else ofile.close();
}
string gmfile::readfilecontent(string fn)
{
	fileline=0;
	openfile(fn,0);
	string cont="";
	string tmp;
	while (ifile>>tmp)
	{
		cont+=tmp;
		if (tmp!="*") fileline++;
	}
	closefile(0);
	return cont;
}


int gmfile::countline(string fn)
{
	openfile(fn,0);
	fileline=0;
	string tmp;
	while (ifile>>tmp)
	{
		fileline++;
	}
	closefile(0);
	return fileline;
}

void gmfile::write2file(string str2write,string fn)
{
	//fileline=countline(fn);
	openfile(fn,1);
	ofile<<str2write<<endl;
	closefile(1);
}

void gmfile::deletefile(string fn)
{
	string strexec="";
	#ifdef _OS_WIN
	//system("del /f/s frdlist >>tmp");
	strexec+="del /f/s ";
	strexec+=fn;
	strexec+=" >>tmp";
	#endif
	#ifdef _OS_UNIX
	//system("rm -f frdlist >>tmp");
	strexec+="rm -f ";
	strexec+=fn;
	strexec+=" >tmp";
	#endif
	const char* cstrexec=(const char*)strexec.c_str();
	system(cstrexec);
}
*/

#pragma once
#ifndef FILETRACE_HEAD

#define FILETRACE_HEAD
#define NTOS(a) #a
#include <iostream>
#include <fstream>
#include <mutex>

class FileTrace
{
public:
	static std::string m_fileName; 
	static bool m_bisInit; 
	static std::mutex m_Mutex; 
	std::fstream m_fs; 
	std::string m_trace; /*  */
public:
	FileTrace(void);
	FileTrace(int itraceLine, const char * streaceContext); 
	~FileTrace(void);
public:
	static void Initialize(const char * sfileName); 
	void TraceOut(); 
	void SetTrace(int itraceLine, const char * steaceContext); 
	void Close(); 

};


#endif
#pragma once

#include <iostream>
#include <fstream>
#include <mutex>

class FileTrace
{
	static std::string m_fileName; 
	static bool m_bisInit; 
	static std::mutex m_Mutex; 
	std::fstream m_fs; 
public:
	FileTrace(void);
	FileTrace(const char * sContext); 
	~FileTrace(void);
public:
	static void Initialize(const char * sfileName); 
	void TraceOut(const char * sContext); 
	void Close(); 

};

std::string FileTrace::m_fileName; 
bool FileTrace::m_bisInit; 
std::mutex FileTrace::m_Mutex; 
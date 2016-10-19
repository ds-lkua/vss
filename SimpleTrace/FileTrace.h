#pragma once

#include <iostream>
#include <fstream>
#include <mutex>

class FileTrace
{

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

static std::string m_fileName; 
static bool bisInit; 
static std::mutex m_Mutex; 

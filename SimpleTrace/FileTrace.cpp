#include "FileTrace.h"




FileTrace::FileTrace()
{
	m_fs.open(m_fileName, std::ios_base::app | std::ios_base::binary ); 
}

FileTrace::FileTrace(const char * sContext)
{
	m_fs.open(m_fileName, std::ios_base::app | std::ios_base::binary ); 
	TraceOut(sContext); 
}

FileTrace::~FileTrace()
{
	delete this; 
}

void FileTrace::Initialize(const char * sfileName)
{

	m_Mutex.lock(); 
	
	m_fileName.empty(); 
	m_fileName += sfileName; 

	if(m_bisInit)
	{
		m_Mutex.unlock(); 
		return; 
	}

	
	m_bisInit = true; 

	m_Mutex.unlock(); 

}

void FileTrace::TraceOut(const char * sContext)
{
	m_Mutex.lock(); 

	m_fs.seekp(std::ios_base::end); 
	m_fs << sContext; 
	m_fs << std::endl; 
	m_Mutex.unlock(); 
}


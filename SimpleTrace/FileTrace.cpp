#include "FileTrace.h"
#include <sstream>
#include <exception>
#include <time.h>


std::string FileTrace::m_fileName; 
bool FileTrace::m_bisInit; 
std::mutex FileTrace::m_Mutex; 

FileTrace::FileTrace()
{
	m_fs.open(m_fileName, std::ios_base::app | std::ios_base::binary ); 
}

FileTrace::FileTrace(int itraceLine, const char * streaceContext)
{
	m_fs.open(m_fileName, std::ios_base::app | std::ios_base::binary ); 
	SetTrace(itraceLine, streaceContext); 
	TraceOut(); 
}

FileTrace::~FileTrace()
{
	m_fs.close(); 
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

void FileTrace::TraceOut()
{
	m_Mutex.lock(); 

	m_fs.seekp(std::ios_base::end); 
	m_fs << m_trace; 
	m_fs << std::endl;
	m_trace.clear(); 
	m_Mutex.unlock(); 
}

int main()
{
	try{
	FileTrace::Initialize("c:\\aaa\\a.log"); 
	FileTrace ss; 

	ss.SetTrace(__LINE__, "i'm main"); 
	std::cout << ss.m_trace << std::endl; 
	
	ss.TraceOut(); 
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl; 
	}

	
}

void FileTrace::SetTrace(int itraceLine, const char * streaceContext)
{
	m_trace.clear(); 
	std::stringstream sStream; 
	time_t tm = time(NULL); 
	char *ctm = ctime(&tm); 
	size_t a =  strlen(ctm); 
	ctm[a - 1] = '\0'; 
	sStream << ctm << "    line:" << itraceLine << "    " << streaceContext; 
	std::cout << m_trace << std::endl; 
	m_trace.append(sStream.str()); 
	
}
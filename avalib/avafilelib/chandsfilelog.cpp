//---------------------------------------------------------------------------

#pragma hdrstop

#include "chandsfilelog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

ArchiveLog::ArchiveLog()
{
	Path = "avasoft.log";
	Name = "AVASoft";
}
ArchiveLog::~ArchiveLog()
{
	CloseLogFile();
}
void ArchiveLog::SetName(char * temp)
{
	Name = temp;
}
void ArchiveLog::SetPath(char * temp)
{
	Path = temp;
}
int ArchiveLog::CreateLogFile()
{
	if (File.OpenFile(Path,"w+"))
	{
		char date[20];
		char time[9];
		_strdate(date);
		_strtime(time);
		strcat(date," - ");
		strcat(date,time);
		File.WriteBuffers(Name);
		File.WriteBuffers("\n");
		File.WriteBuffers(date);
		File.WriteBuffers("\n\n");
		return 1;
	}
	return 0;
}
void ArchiveLog::CloseLogFile()
{
	File.WriteBuffers("\n\n------Fim de Sistema-------\n\n");
	File.CloseFile();
}

int ArchiveLog::AddLog(const char * LogTemp)
{
	if (File.SeeState())
	{
		char date[20];
		char time[9];
		_strdate(date);
		_strtime(time);
		strcat(date," - ");
		strcat(date,time);
		File.WriteBuffers("\n----------------------\n");
		File.WriteBuffers(date);
		File.WriteBuffers("\n");
		File.WriteBuffers(LogTemp);
		File.WriteBuffers("\n----------------------\n");
		return 1;
	}
	return 0;
}
int ArchiveLog::DeleteLogFile()
{
	if (File.SeeState())
	{
		File.CloseFile();
		return File.RM();
	}
	return 0;
}

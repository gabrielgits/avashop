//---------------------------------------------------------------------------

#ifndef chandsfilelogH
#define chandsfilelogH
#include <time.h>
#include "chandsfile.h"
//---------------------------------------------------------------------------
#endif

class ArchiveLog
{
protected:
	Archive File;
	char * Name;
	char * Path;

public:
	ArchiveLog();
    ~ArchiveLog();
	void SetName(char *);
	void SetPath(char *);
	int CreateLogFile();
	int AddLog(const char *);
	int DeleteLogFile();
	void CloseLogFile();
};

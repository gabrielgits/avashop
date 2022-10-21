//---------------------------------------------------------------------------

#pragma hdrstop

#include "chandsfile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void strnchar(char * dest, char cont)
{
	int i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	char * Strin = new char [i];
	for (int j = 0; j < i; j++)
	{
		Strin[j] = dest[j];
	}
	delete []dest;
	dest = new char [i+1];
	for (int j = 0; j < i; j++)
	{
		dest[j] = Strin[j];
	}
	dest[i] = cont;
	dest[i+1] = '\0';
	delete []Strin;
}
Archive::Archive()
{
	File = NULL;
	Mode = NULL;
	Path = NULL;
	State = 0;
}

Archive::~Archive()
{
	CloseFile();
}

int Archive::OpenFile(char * TempPath, char * TempMode)
{
	File = fopen(TempPath,TempMode);
	if (File == NULL)
	{
		Mode = NULL;
		State = 0;
        Path = NULL;
		return 0;
	}
	Mode = TempMode;
	Path = TempPath;
	State = 1;
	return 1;
}

int Archive::ReadBuffer(char &buffer)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			buffer = getc(File);
			if (buffer < 0)
				buffer = 0;
			return 1;
		}
	}
	return 0;
}

int Archive::WriteBuffer(const char buffer)
{
	if (SeeState())
	{
		putc(buffer,File);
		return 1;
	}
	return 0;
}

int Archive::ReadBuffers(char *& buffer)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			fgets(buffer,sizeof(buffer),File);
			if (buffer != NULL)
				return 1;
		}
	}
	return 0;
}

int Archive::WriteBuffers(const char * buffer)
{
	if (SeeState())
	{
		fputs(buffer,File);
		return 1;
	}
	return 0;
}

void Archive::RewindFile()
{
	rewind(File);
}

int Archive::RM()
{
	if (!SeeState())
	   if (!remove(Path))
		   return 1;
	return 0;
}

int Archive::RM(const char * Temp)
{

	if (!SeeState())
	   if (!rename(Path,Temp))
		   return 1;
	return 0;
}

void Archive::CloseFile()
{
	fclose(File);
	Mode = NULL;
	Path = NULL;
	State = 0;
	File = NULL;
}

int Archive::CopyFile(const int quant,const char * name)
{
	char buffer;
	char * number;
	char * nameTemp;
	FILE * FileTemp;
	if (State)
	{
		for (int i = 0; i < quant; i++)
		{
			itoa(i+1,number,10);
			strcpy(nameTemp,name);
			strcat(nameTemp,number);
			FileTemp = fopen(nameTemp,"wb");
			if (FileTemp != NULL)
			{
				RewindFile();
				while (ReadBuffer(buffer))
					putc(buffer,FileTemp);
			}
			else
				return 0;
			fclose(FileTemp);
		}
	}
	else
		return 0;
	return 1;
}

int Archive::SeeState()
{
	return State;
}

int Archive::ReadUserData(UserType &buffer,int Quant)
{
	if (SeeState())
	{
		if (!feof(File))
		{
			fread(&buffer,sizeof(buffer),Quant,File);
			return 1;
		}
	}
	return 0;
}
int Archive::WriteUserData(UserType buffer,int Quant)
{
	if (SeeState())
	{
		fwrite(&buffer,sizeof(buffer),Quant,File);
		return 1;
	}
	return 0;
}


char * Archive::ReadLines(int linha)
{
	char * TextoTemp;
	TextoTemp = new char[256];
	char buf;
	int FimArquivo = 1;

	// Controlar a linha que deseja ser lido
	int NumeroLinha = 0;
	while ((NumeroLinha < linha-1) && (FimArquivo))
	{
		char buff;
		FimArquivo = ReadBuffer(buff);
		if (buff == '\n')
			NumeroLinha++;
	}

	//Ler uma linha
	while ((FimArquivo == ReadBuffer(buf)) && (buf != '\n'))
	{
		char st[1];
		st[0] = buf;
		st[1]= '\0';
		strcat(TextoTemp,st);
	}
	return TextoTemp;
}


/***********************************************************************
 * Module:  AvaFiles.h
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:20:23
 * Purpose: Declaration of the class AvaFiles
 ***********************************************************************/

#ifndef AvaFilesH
#define AvaFilesH
//---------------------------------------------------------------------------
#include <Registry.hpp>
#endif
typedef AnsiString texto;
class AvaFiles
{
public:
   texto getLicence(void);
   void setLicence(texto newLicence);
   texto getFotopadrao(void);
   void setFotopadrao(texto newFotopadrao);
   texto getAvaconnect(void);
   void setAvaconnect(texto newAvaconnect);
   texto getAvacam(void);
   void setAvacam(texto newAvacam);
   AvaFiles();
   ~AvaFiles();
   AvaFiles(const AvaFiles& oldAvaFiles);
    int ReadRegistry();
   int WriteRegistry();

protected:
private:
   texto Licence;
   texto fotopadrao;
   texto Avaconnect;
   texto Avacam;


};


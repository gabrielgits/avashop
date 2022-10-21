/***********************************************************************
 * Module:  AvaAppInfo.h
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:24:37
 * Purpose: Declaration of the class AvaAppInfo
 ***********************************************************************/

#ifndef AvaAppInfoH
#define AvaAppInfoH
//---------------------------------------------------------------------------

#include <AvaPath.h>
#endif



class AvaAppInfo : public AvaPath
{
public:
   texto getAppPub(void);
   void setAppPub(texto newAppPub);
   texto getInstNome(void);
   void setInstNome(texto newInstNome);
   double getAppVersao(void);
   void setAppVersao(double newAppVersao);
   texto getAppNome(void);
   void setAppNome(texto newAppNome);
   AvaAppInfo();
   ~AvaAppInfo();
   AvaAppInfo(const AvaAppInfo& oldAvaAppInfo);
   AvaPath getPath(void);
   void setPath(AvaPath newPath);
   int ReadRegistry();
   int WriteRegistry();

protected:
private:
   texto AppPub;
   texto InstNome;
   double AppVersao;
   texto AppNome;
   AvaPath Path;

};


/***********************************************************************
 * Module:  USUARIO.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 10:59:44
 * Purpose: Declaration of the class USUARIO
 ***********************************************************************/


#ifndef USUARIOH
#define USUARIOH
#include "PREVILEGIO.h"

class USUARIO : public PREVILEGIO
{
public:
   int getUSUARIOID(void);
   void setUSUARIOID(int newUSUARIOID);
   string getUSUARIONOME(void);
   void setUSUARIONOME(string newUSUARIONOME);
   string getUSUARIOSENHA(void);
   void setUSUARIOSENHA(string newUSUARIOSENHA);

   void setUSUARIONOMECOMPLETO(string newUSUARIONOMECOMPLETO);
   string getUSUARIONOMECOMPLETO(void);

   USUARIO();
   ~USUARIO();
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   USUARIO *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);

protected:
private:
   int USUARIOID;
   string USUARIONOME;
   string USUARIOSENHA;
   string USUARIONOMECOMPLETO;


};

#endif
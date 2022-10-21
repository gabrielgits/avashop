/***********************************************************************
 * Module:  TIPOCLIENTE.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:01:25
 * Purpose: Declaration of the class TIPOCLIENTE
 ***********************************************************************/

#ifndef TIPOCLIENTEH
#define TIPOCLIENTEH
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
typedef AnsiString string;
typedef TFDQuery* Query;

class TIPOCLIENTE
{
public:
   int getTIPOCLIENTEID(void);
   void setTIPOCLIENTEID(int newTIPOCLIENTEID);
   string getTIPOCLIENTENOME(void);
   void setTIPOCLIENTENOME(string newTIPOCLIENTENOME);
   TIPOCLIENTE();
   ~TIPOCLIENTE();
   TIPOCLIENTE(const TIPOCLIENTE& oldTIPOCLIENTE);
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   TIPOCLIENTE *SetQuery(TFDQuery *FDQuery);
    Query GetQueryID(TFDQuery *FDQuery);
protected:
private:
   int TIPOCLIENTEID;
   string TIPOCLIENTENOME;


};

#endif
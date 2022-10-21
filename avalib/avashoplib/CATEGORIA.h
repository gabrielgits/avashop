/***********************************************************************
 * Module:  CATEGORIA.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:11:50
 * Purpose: Declaration of the class CATEGORIA
 ***********************************************************************/

#ifndef CATEGORIAH
#define CATEGORIAH
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
class CATEGORIA
{
public:
   int getCATEGORIAID(void);
   void setCATEGORIAID(int newCATEGORIAID);
   string getCATEGORIANOME(void);
   void setCATEGORIANOME(string newCATEGORIANOME);
   CATEGORIA();
   ~CATEGORIA();
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);
   CATEGORIA *SetQuery(TFDQuery *FDQuery);


protected:
private:
   int CATEGORIAID;
   string CATEGORIANOME;


};

#endif
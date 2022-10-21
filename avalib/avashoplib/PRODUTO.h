/***********************************************************************
 * Module:  PRODUTO.h
 * Author:  Vieira
 * Modified: s�bado, 25 de Fevereiro de 2017 11:09:14
 * Purpose: Declaration of the class PRODUTO
 ***********************************************************************/
#ifndef PRODUTOH
#define PRODUTOH
#include "CATEGORIA.h"
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
class PRODUTO :public CATEGORIA
{
public:
   int getPRODUTOID(void);
   void setPRODUTOID(int newPRODUTOID);
   string getPRODUTONOME(void);
   void setPRODUTONOME(string newPRODUTONOME);
   double getPRODUTOPRECO(void);
   void setPRODUTOPRECO(double newPRODUTOPRECO);
   PRODUTO();
   ~PRODUTO();
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   PRODUTO *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);


   protected:
private:
  string PRODUTONOME;
   double PRODUTOPRECO;
int PRODUTOID;

};

#endif
/***********************************************************************
 * Module:  VENDA.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:04:41
 * Purpose: Declaration of the class VENDA
 ***********************************************************************/


#ifndef VENDAH
#define VENDAH
#include "PRODUTO.h"
#include "CLIENTE.h"
#include "USUARIO.h"

class VENDA :public PRODUTO, public CLIENTE, public USUARIO
{
public:
   int getVENDAID(void);
   void setVENDAID(int newVENDAID);
   int getVENDAQUANTIDADE(void);
   void setVENDAQUANTIDADE(int newVENDAQUANTIDADE);
   TDate getVENDADATA(void);
   void setVENDADATA(TDate newVENDADATA);
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   VENDA *SetQuery(TFDQuery *FDQuery);
   VENDA();
   ~VENDA();
   Query GetQueryID(TFDQuery *FDQuery);
protected:
private:
   int VENDAID;
   int VENDAQUANTIDADE;
   TDate VENDADATA;


};

#endif
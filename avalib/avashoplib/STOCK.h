/***********************************************************************
 * Module:  STOCK.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:10:32
 * Purpose: Declaration of the class STOCK
 ***********************************************************************/

#ifndef STOCKH
#define STOCKH
#include "PRODUTO.h"

class STOCK :public PRODUTO
{
public:
   int getSTOCKID(void);
   void setSTOCKID(int newSTOCKID);
   int getSTOCKQUANTIA(void);
   void setSTOCKQUANTIA(int newSTOCKQUANTIA);
   TDate getSTOCKUPDATE(void);
   void setSTOCKUPDATE(TDate newSTOCKUPDATE);
   STOCK();
   ~STOCK();
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   STOCK *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);


protected:
private:
   int STOCKQUANTIA;
   TDate STOCKUPDATE;
   int STOCKID;

};

#endif
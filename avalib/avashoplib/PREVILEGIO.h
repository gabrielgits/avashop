/***********************************************************************
 * Module:  PREVILEGIO.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 10:23:47
 * Purpose: Declaration of the class PREVILEGIO
 ***********************************************************************/
#ifndef PREVILEGIOH
#define PREVILEGIOH
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

class PREVILEGIO
{
public:
   int getPREVILEGIOID(void);
   void setPREVILEGIOID(int newPREVILEGIOID);
   string getPREVILEGIONOME(void);
   void setPREVILEGIONOME(string newPREVILEGIONOME);
   PREVILEGIO();
   ~PREVILEGIO();
   PREVILEGIO(const PREVILEGIO& oldPREVILEGIO);
   Query GetQuery(TFDQuery *FDQuery);
   PREVILEGIO *SetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);
   int IsEmpty(void);

protected:
private:
   int PREVILEGIOID;
   string PREVILEGIONOME;


};

#endif
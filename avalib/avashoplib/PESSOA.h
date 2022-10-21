/***********************************************************************
 * Module:  PESSOA.h
 * Author:  Vieira
 * Modified: sábado, 25 de Fevereiro de 2017 11:03:26
 * Purpose: Declaration of the class PESSOA
 ***********************************************************************/

#ifndef PESSOAH
#define PESSOAH
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

class PESSOA
{
public:
   int getPESSOAID(void);
   void setPESSOAID(int newPESSOAID);
   string getPESSOANOME(void);
   void setPESSOANOME(string newPESSOANOME);
   TDate getPESSOADATA(void);
   void setPESSOADATA(TDate newPESSOADATA);
   string getPESSOACONTACTO(void);
   void setPESSOACONTACTO(string newPESSOACONTACTO);
   string getPESSOAMORADA(void);
   void setPESSOAMORADA(string newPESSOAMORADA);
   string getPESSOABI(void);
   void setPESSOABI(string newPESSOABI);
   PESSOA();
   ~PESSOA();
   PESSOA(const PESSOA& oldPESSOA);
   int IsEmpty(void);
   Query GetQuery(TFDQuery *FDQuery);
   Query GetQueryID(TFDQuery *FDQuery);
   PESSOA *SetQuery(TFDQuery *FDQuery);

protected:
private:
   int PESSOAID;
   string PESSOANOME;
   TDate PESSOADATA;
   string PESSOACONTACTO;
   string PESSOAMORADA;
   string PESSOABI;


};

#endif
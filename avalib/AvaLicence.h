/***********************************************************************
 * Module:  AvaLicence.h
 * Author:  Nick is Back
 * Modified: 7 de fevereiro de 2017 09:20:23
 * Purpose: Declaration of the class AvaLicence
 ***********************************************************************/

#ifndef AvaLicenceH
#define AvaLicenceH
//---------------------------------------------------------------------------
#include <Registry.hpp>
#endif
typedef AnsiString texto;
class AvaLicence
{
public:
   texto getContacto(void);
   void setContacto(texto newContacto);
   texto getCliente(void);
   void setCliente(texto newCliente);
   TDate getData(void);
   void setData(TDate newData);
   int getTempo(void);
   void setTempo(int newTempo);
   int getTipo(void);
   void setTipo(int newTipo);
   AvaLicence();
   ~AvaLicence();
   AvaLicence(const AvaLicence& oldAvaLicence);
   int ReadRegistry();
   int WriteRegistry();
protected:
private:
   texto Contacto;
   texto Cliente;
   TDate Data;
   int Tempo;
   int Tipo;


};


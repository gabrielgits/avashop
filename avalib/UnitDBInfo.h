//---------------------------------------------------------------------------

#ifndef UnitDBInfoH
#define UnitDBInfoH
#include <Registry.hpp>
//---------------------------------------------------------------------------
#endif
typedef AnsiString texto;
class AvaInfoDB
{
	private:
	texto drive;
	texto servidor;
	int porta;
	texto username;
	texto senha;
	int pront;
	texto basedados;

	public:
	AvaInfoDB();
	texto Getdrive();
	texto Getservidor();
	texto Getusername();
	texto Getsenha();
	int Getporta();
	int Getpront();
	texto Getbasedados();

	void Setdrive(texto);
	void Setservidor(texto);
	void Setusername(texto);
	void Setsenha(texto);
	void Setporta(int);
	void Setpront(int);
	void Setbasedados(texto);

    int ReadRegistry();
   int WriteRegistry();
};

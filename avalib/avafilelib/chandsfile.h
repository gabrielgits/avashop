/*
Classe para Manipular Arquivos Ver 0.2 Criado By Chands

LEIA ESTE ACORDO DE LICEN�A ANTES DE USAR O SOFTWARE OU CODIGO FONTE

ACORDO DE LICEN�A E TERMOS DE USO DE SISTEMA DA AVASOFT
Voc� n�o pode usar, alugar, arrendar, sub-licenciar, publicar, modificar, adaptar ou traduzir qualquer parte do sistema ou c�digo fonte sem a autoriza��o do autor;
Voc� n�o pode criar quaisquer trabalhos derivados, ou de outra forma tentar criar o c�digo de fonte deste sistema a partir do seu c�digo-objecto; 
Voc� n�o pode usar qualquer trechos de c�digo ou software n�o autorizado, ilegal, falsificado, ou modificado em liga��o com o Software ou c�digo fonte, incluindo o uso de ferramentas para desviar de, incapacitar, ou contornar qualquer mecanismo de codifica��o, seguran�a ou autentica��o para o sistema; 
Voc� n�o pode obter o Software ou c�digo fonte de qualquer forma que n�o seja por interm�dio dos m�todos de distribui��o da AVASOFT ou do autor;

O ACESSO AO OU USO DO SOFTWARE OU CODIGO FONTE EST� EXPRESSAMENTE CONDICIONADO � ACEITA��O DOS TERMOS DESTE ACORDO.

Copyright �2014 AVASoft, Todos os Direitos Reservado.

*/

/*
---------------------------------------------------------------------------
MODO DE COMO O ARQUIVO SER� ABERTO
r w a	              Abre um arquivo texto
rb wb ab	          Abre um arquivo bin�rio.
r+ w+ a+ 	          Abre um arquivo texto para leitura/escrita.
r+b w+b a+b rb+ wb+ ab+  Abre um arquivo bin�rio para leitura/escrita.




---------------------------------------------------------------------------
*/
/*
Exemplo de Uso
int main()
{
	Archive MeuArquivo;
	MeuArquivo.OpenFile("README.txt","r");
	MeuArquivo.CopyFile(1,"COPIA_README.txt");
	MeuArquivo.CloseFile()
}
*/
//---------------------------------------------------------------------------

#ifndef chandsfileH
#define chandsfileH
//---------------------------------------------------------------------------
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int UserType;

class Archive
{
protected:
	FILE * File;
	char *Mode;
	int State;
	char * Path;

public:
	Archive();
	~Archive();
	int OpenFile(char * Path, char * TempMode);
	int ReadBuffer(char &);
	int ReadBuffers(char *&);
	int WriteBuffer(const char);
	int WriteBuffers(const char *);
	int SeeState();
	int ReadUserData(UserType &buffer,int Quant);
	int WriteUserData(UserType buffer,int Quant);
	char * ReadLines(int linhas);

	void RewindFile();
	int CopyFile(const int quant,const char * name);
	int RM();
	int RM(const char *);

	void CloseFile();
};


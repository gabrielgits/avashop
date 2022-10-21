//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("UnitDB.cpp", DataModuleDB); /* TDataModule: File Type */
USEFORM("UnitConsultarProduto.cpp", FormProcurarProdutos);
USEFORM("UnitInicial.cpp", FormInical);
USEFORM("UnitGestaoVenda.cpp", FormGestaoVenda);
USEFORM("UnitCompra.cpp", FormCompra);
USEFORM("uMain.cpp", CameraComponentForm);
USEFORM("UnitBuscaProduto.cpp", FormBuscaProduto);
USEFORM("UnitCliente.cpp", FormCliente);
USEFORM("UnitCategoria.cpp", FormCategoria);
USEFORM("UnitLigacao.cpp", FormLigacao);
USEFORM("UnitStock.cpp", FormStock);
USEFORM("UnitSplash.cpp", FormSplash);
USEFORM("UnitTipoCliente.cpp", FormTipoCliente);
USEFORM("UnitVenda.cpp", FormVenda);
USEFORM("UnitUsuario.cpp", FormUsuario);
USEFORM("UnitPessoa.cpp", FormPessoa);
USEFORM("UnitLogin.cpp", FormLogin);
USEFORM("UnitPrevilegio.cpp", FormPrevilegio);
USEFORM("UnitPrincipal.cpp", FormPrincipal);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFormPrincipal), &FormPrincipal);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFormBuscaProduto), &FormBuscaProduto);
		Application->CreateForm(__classid(TCameraComponentForm), &CameraComponentForm);
		Application->CreateForm(__classid(TFormBuscaProduto), &FormBuscaProduto);
		Application->CreateForm(__classid(TFormCategoria), &FormCategoria);
		Application->CreateForm(__classid(TFormCliente), &FormCliente);
		Application->CreateForm(__classid(TFormCompra), &FormCompra);
		Application->CreateForm(__classid(TFormProcurarProdutos), &FormProcurarProdutos);
		Application->CreateForm(__classid(TDataModuleDB), &DataModuleDB);
		Application->CreateForm(__classid(TFormGestaoVenda), &FormGestaoVenda);
		Application->CreateForm(__classid(TFormLigacao), &FormLigacao);
		Application->CreateForm(__classid(TFormLogin), &FormLogin);
		Application->CreateForm(__classid(TFormPessoa), &FormPessoa);
		Application->CreateForm(__classid(TFormPrevilegio), &FormPrevilegio);
		Application->CreateForm(__classid(TFormSplash), &FormSplash);
		Application->CreateForm(__classid(TFormStock), &FormStock);
		Application->CreateForm(__classid(TFormTipoCliente), &FormTipoCliente);
		Application->CreateForm(__classid(TFormUsuario), &FormUsuario);
		Application->CreateForm(__classid(TFormVenda), &FormVenda);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

object DataModuleDB: TDataModuleDB
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 430
  Width = 786
  object FDQueryCategorias: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM categoria')
    Left = 32
    Top = 16
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=C:\Partilha\avashop\avashop.db3'
      'DriverID=SQLite')
    Connected = True
    LoginPrompt = False
    Left = 200
    Top = 352
  end
  object FDQueryCliente: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM viewclientes;')
    Left = 432
    Top = 96
  end
  object FDQueryCompra: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT *  FROM viewcompras;')
    Left = 336
    Top = 160
  end
  object FDQueryFornecedor: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from fornecedore;')
    Left = 24
    Top = 88
  end
  object FDQueryPrevilegio: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM previlegio')
    Left = 112
    Top = 88
  end
  object FDQueryTipoCliente: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from tipocliente;')
    Left = 120
    Top = 16
    object FDQueryTipoClienteTIPOCLIENTEID: TFDAutoIncField
      FieldName = 'TIPOCLIENTEID'
      Origin = 'TIPOCLIENTEID'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object FDQueryTipoClienteTIPOCLIENTENOME: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'TIPOCLIENTENOME'
      Origin = 'TIPOCLIENTENOME'
      FixedChar = True
      Size = 32
    end
  end
  object FDQueryUsuario: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from viewusuarios;')
    Left = 424
    Top = 16
  end
  object FDQueryProduto: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from viewprodutos')
    Left = 248
    Top = 168
  end
  object FDQueryStock: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from viewstock')
    Left = 336
    Top = 16
  end
  object FDQueryVenda: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * from viewvendas;')
    Left = 248
    Top = 16
  end
  object FDQueryVendaTemp: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select * FROM viewvendastemp;')
    Left = 248
    Top = 96
  end
  object FDQueryVendaInvetAno: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM viewvendas'
      'WHERE YEAR(VENDADATA) = :ano')
    Left = 520
    Top = 96
    ParamData = <
      item
        Name = 'ANO'
        DataType = ftInteger
        ParamType = ptInput
        Value = 2017
      end>
  end
  object FDQueryVendaInvtDia: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM viewvendas where VENDADATA = :data')
    Left = 512
    Top = 16
    ParamData = <
      item
        Name = 'DATA'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end>
  end
  object FDQueryVendaInvtMes: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM viewvendas'
      'WHERE YEAR(VENDADATA) = :ano and MONTH(VENDADATA) = :mes')
    Left = 432
    Top = 168
    ParamData = <
      item
        Name = 'ANO'
        DataType = ftInteger
        ParamType = ptInput
        Value = 2017
      end
      item
        Name = 'MES'
        DataType = ftInteger
        ParamType = ptInput
        Value = 4
      end>
  end
  object FDQueryProcurarProduto: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      
        'select * from viewprodutos where categorianome like :categoriano' +
        'me ')
    Left = 336
    Top = 96
    ParamData = <
      item
        Name = 'CATEGORIANOME'
        DataType = ftString
        ParamType = ptInput
        Value = '%%'
      end>
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 344
    Top = 352
  end
  object FDPhysSQLiteDriverLink1: TFDPhysSQLiteDriverLink
    Left = 272
    Top = 352
  end
end

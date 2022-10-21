# Host: localhost  (Version 5.7.16-log)
# Date: 2017-06-13 10:57:18
# Generator: MySQL-Front 6.0  (Build 1.73)


#
# Structure for table "categoria"
#

DROP TABLE IF EXISTS `categoria`;
CREATE TABLE `categoria` (
  `CATEGORIAID` int(11) NOT NULL AUTO_INCREMENT,
  `CATEGORIANOME` char(32) NOT NULL DEFAULT 'Categoiria Desconhecida',
  PRIMARY KEY (`CATEGORIAID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for table "fornecedore"
#

DROP TABLE IF EXISTS `fornecedore`;
CREATE TABLE `fornecedore` (
  `FORNECEDORID` int(11) NOT NULL AUTO_INCREMENT,
  `FORNECEDORCONTACTO` char(64) DEFAULT NULL,
  `FORNECEDORNOME` char(64) NOT NULL DEFAULT 'Desconhecido',
  `FORNECEDORENDERECO` char(64) DEFAULT NULL,
  PRIMARY KEY (`FORNECEDORID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Structure for table "pessoa"
#

DROP TABLE IF EXISTS `pessoa`;
CREATE TABLE `pessoa` (
  `PESSOAID` int(11) NOT NULL AUTO_INCREMENT,
  `PESSOANOME` char(64) DEFAULT 'Desconhecido',
  `PESSOADATA` date DEFAULT NULL,
  `PESSOACONTACTO` char(64) DEFAULT NULL,
  `PESSOAMORADA` char(64) DEFAULT NULL,
  `PESSOABI` char(16) DEFAULT NULL,
  PRIMARY KEY (`PESSOAID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Structure for table "previlegio"
#

DROP TABLE IF EXISTS `previlegio`;
CREATE TABLE `previlegio` (
  `PREVILEGIOID` int(11) NOT NULL AUTO_INCREMENT,
  `PREVILEGIONOME` char(32) NOT NULL DEFAULT 'Anónimo',
  PRIMARY KEY (`PREVILEGIOID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for table "produto"
#

DROP TABLE IF EXISTS `produto`;
CREATE TABLE `produto` (
  `PRODUTOID` int(11) NOT NULL AUTO_INCREMENT,
  `CATEGORIAID` int(11) DEFAULT '1',
  `PRODUTONOME` char(64) DEFAULT NULL,
  `PRODUTOPRECO` float DEFAULT NULL,
  PRIMARY KEY (`PRODUTOID`),
  KEY `CATEGORIAID` (`CATEGORIAID`),
  CONSTRAINT `produto_ibfk_1` FOREIGN KEY (`CATEGORIAID`) REFERENCES `categoria` (`CATEGORIAID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

#
# Structure for table "stock"
#

DROP TABLE IF EXISTS `stock`;
CREATE TABLE `stock` (
  `STOCKID` int(11) NOT NULL AUTO_INCREMENT,
  `PRODUTOID` int(11) NOT NULL DEFAULT '1',
  `STOCKQUANTIA` int(11) NOT NULL DEFAULT '0',
  `STOCKUPDATE` date DEFAULT NULL,
  PRIMARY KEY (`STOCKID`),
  KEY `PRODUTOID` (`PRODUTOID`),
  CONSTRAINT `stock_ibfk_1` FOREIGN KEY (`PRODUTOID`) REFERENCES `produto` (`PRODUTOID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for table "tipocliente"
#

DROP TABLE IF EXISTS `tipocliente`;
CREATE TABLE `tipocliente` (
  `TIPOCLIENTEID` int(11) NOT NULL AUTO_INCREMENT,
  `TIPOCLIENTENOME` char(32) NOT NULL DEFAULT 'Anónimo',
  PRIMARY KEY (`TIPOCLIENTEID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for table "cliente"
#

DROP TABLE IF EXISTS `cliente`;
CREATE TABLE `cliente` (
  `CLIENTEID` int(11) NOT NULL AUTO_INCREMENT,
  `PESSOAID` int(11) NOT NULL DEFAULT '1',
  `TIPOCLIENTEID` int(11) NOT NULL DEFAULT '1',
  `CLIENTECONTA` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`CLIENTEID`),
  KEY `TIPOCLIENTEID` (`TIPOCLIENTEID`),
  KEY `cliente_ibfk_3` (`PESSOAID`),
  CONSTRAINT `cliente_ibfk_2` FOREIGN KEY (`TIPOCLIENTEID`) REFERENCES `tipocliente` (`TIPOCLIENTEID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `cliente_ibfk_3` FOREIGN KEY (`PESSOAID`) REFERENCES `pessoa` (`PESSOAID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Structure for table "usuario"
#

DROP TABLE IF EXISTS `usuario`;
CREATE TABLE `usuario` (
  `USUARIOID` int(11) NOT NULL AUTO_INCREMENT,
  `PREVILEGIOID` int(11) NOT NULL DEFAULT '1',
  `USUARIONOME` char(64) NOT NULL DEFAULT 'Anónimo',
  `USUARIOSENHA` char(32) NOT NULL DEFAULT '12345',
  `USUARIONOMECOMPLETO` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`USUARIOID`),
  KEY `usuario_ibfk_1` (`PREVILEGIOID`),
  CONSTRAINT `usuario_ibfk_1` FOREIGN KEY (`PREVILEGIOID`) REFERENCES `previlegio` (`PREVILEGIOID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Structure for table "compra"
#

DROP TABLE IF EXISTS `compra`;
CREATE TABLE `compra` (
  `COMPRAID` int(11) NOT NULL AUTO_INCREMENT,
  `COMPRADATA` date DEFAULT NULL,
  `COMPRAQUANTIDADE` int(11) DEFAULT '0',
  `PRODUTOID` int(11) DEFAULT '1',
  `USUARIOID` int(11) DEFAULT '1',
  `FORNECEDORID` int(11) DEFAULT '1',
  `COMPRAPRECO` double DEFAULT NULL,
  PRIMARY KEY (`COMPRAID`),
  KEY `USUARIOID` (`USUARIOID`),
  KEY `PRODUTOID` (`PRODUTOID`),
  KEY `FORNECEDORID` (`FORNECEDORID`),
  CONSTRAINT `compra_ibfk_1` FOREIGN KEY (`USUARIOID`) REFERENCES `usuario` (`USUARIOID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `compra_ibfk_2` FOREIGN KEY (`PRODUTOID`) REFERENCES `produto` (`PRODUTOID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `compra_ibfk_3` FOREIGN KEY (`FORNECEDORID`) REFERENCES `fornecedore` (`FORNECEDORID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Structure for table "venda"
#

DROP TABLE IF EXISTS `venda`;
CREATE TABLE `venda` (
  `VENDAID` int(11) NOT NULL AUTO_INCREMENT,
  `PRODUTOID` int(11) NOT NULL DEFAULT '1',
  `CLIENTEID` int(11) NOT NULL DEFAULT '1',
  `USUARIOID` int(11) NOT NULL DEFAULT '1',
  `VENDAQUANTIDADE` int(11) DEFAULT '0',
  `VENDADATA` date DEFAULT NULL,
  PRIMARY KEY (`VENDAID`),
  KEY `PRODUTOID` (`PRODUTOID`),
  KEY `CLIENTEID` (`CLIENTEID`),
  KEY `USUARIOID` (`USUARIOID`),
  CONSTRAINT `venda_ibfk_1` FOREIGN KEY (`PRODUTOID`) REFERENCES `produto` (`PRODUTOID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `venda_ibfk_2` FOREIGN KEY (`CLIENTEID`) REFERENCES `cliente` (`CLIENTEID`),
  CONSTRAINT `venda_ibfk_3` FOREIGN KEY (`USUARIOID`) REFERENCES `usuario` (`USUARIOID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

#
# Structure for table "vendatemp"
#

DROP TABLE IF EXISTS `vendatemp`;
CREATE TABLE `vendatemp` (
  `VENDATEMPID` int(11) NOT NULL AUTO_INCREMENT,
  `PRODUTOID` int(11) DEFAULT NULL,
  `CLIENTEID` int(11) DEFAULT NULL,
  `VENDAQUANTIDADE` int(11) DEFAULT NULL,
  PRIMARY KEY (`VENDATEMPID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

#
# View "viewcliente"
#

DROP VIEW IF EXISTS `viewcliente`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewcliente`
  AS
SELECT
  `cliente`.`CLIENTEID`,
  `cliente`.`CLIENTECONTA`,
  `pessoa`.`PESSOAID`,
  `pessoa`.`PESSOANOME`,
  `pessoa`.`PESSOADATA`,
  `pessoa`.`PESSOACONTACTO`,
  `pessoa`.`PESSOAMORADA`,
  `pessoa`.`PESSOABI`,
  `tipocliente`.`TIPOCLIENTEID`,
  `tipocliente`.`TIPOCLIENTENOME`
FROM
  ((`cliente`
    JOIN `pessoa` ON ((`cliente`.`PESSOAID` = `pessoa`.`PESSOAID`)))
    JOIN `tipocliente` ON ((`cliente`.`TIPOCLIENTEID` = `tipocliente`.`TIPOCLIENTEID`)));

#
# View "viewproduto"
#

DROP VIEW IF EXISTS `viewproduto`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewproduto`
  AS
SELECT
  `produto`.`PRODUTOID`,
  `produto`.`CATEGORIAID`,
  `produto`.`PRODUTONOME`,
  `produto`.`PRODUTOPRECO`,
  `categoria`.`CATEGORIANOME`
FROM
  (`produto`
    JOIN `categoria` ON ((`produto`.`CATEGORIAID` = `categoria`.`CATEGORIAID`)));

#
# View "viewstock"
#

DROP VIEW IF EXISTS `viewstock`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewstock`
  AS
SELECT
  `stock`.`STOCKID`,
  `stock`.`STOCKQUANTIA`,
  `stock`.`STOCKUPDATE`,
  `viewproduto`.`PRODUTOID`,
  `viewproduto`.`CATEGORIAID`,
  `viewproduto`.`PRODUTONOME`,
  `viewproduto`.`PRODUTOPRECO`,
  `viewproduto`.`CATEGORIANOME`
FROM
  (`stock`
    JOIN `viewproduto` ON ((`stock`.`PRODUTOID` = `viewproduto`.`PRODUTOID`)));

#
# View "viewusuario"
#

DROP VIEW IF EXISTS `viewusuario`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewusuario`
  AS
SELECT
  `usuario`.`USUARIOID`,
  `usuario`.`PREVILEGIOID`,
  `usuario`.`USUARIONOME`,
  `usuario`.`USUARIOSENHA`,
  `usuario`.`USUARIONOMECOMPLETO`,
  `previlegio`.`PREVILEGIONOME`
FROM
  (`usuario`
    JOIN `previlegio` ON ((`usuario`.`PREVILEGIOID` = `previlegio`.`PREVILEGIOID`)));

#
# View "viewcompra"
#

DROP VIEW IF EXISTS `viewcompra`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewcompra`
  AS
SELECT
  `compra`.`COMPRAID`,
  `compra`.`COMPRADATA`,
  `compra`.`COMPRAQUANTIDADE`,
  `viewusuario`.`USUARIOID`,
  `viewusuario`.`PREVILEGIOID`,
  `viewusuario`.`USUARIONOME`,
  `viewusuario`.`USUARIOSENHA`,
  `viewusuario`.`USUARIONOMECOMPLETO`,
  `viewusuario`.`PREVILEGIONOME`,
  `viewproduto`.`PRODUTOID`,
  `viewproduto`.`CATEGORIAID`,
  `viewproduto`.`PRODUTONOME`,
  `viewproduto`.`PRODUTOPRECO`,
  `viewproduto`.`CATEGORIANOME`,
  `fornecedore`.`FORNECEDORID`,
  `fornecedore`.`FORNECEDORCONTACTO`,
  `fornecedore`.`FORNECEDORNOME`,
  `fornecedore`.`FORNECEDORENDERECO`,
  `compra`.`COMPRAPRECO`
FROM
  (((`compra`
    JOIN `viewusuario` ON ((`compra`.`USUARIOID` = `viewusuario`.`USUARIOID`)))
    JOIN `viewproduto` ON ((`compra`.`PRODUTOID` = `viewproduto`.`PRODUTOID`)))
    JOIN `fornecedore` ON ((`compra`.`FORNECEDORID` = `fornecedore`.`FORNECEDORID`)));

#
# View "viewvenda"
#

DROP VIEW IF EXISTS `viewvenda`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewvenda`
  AS
SELECT
  `venda`.`VENDAID`,
  `venda`.`VENDAQUANTIDADE`,
  `venda`.`VENDADATA`,
  `viewproduto`.`PRODUTOID`,
  `viewproduto`.`CATEGORIAID`,
  `viewproduto`.`PRODUTONOME`,
  `viewproduto`.`PRODUTOPRECO`,
  `viewproduto`.`CATEGORIANOME`,
  `viewcliente`.`CLIENTEID`,
  `viewcliente`.`CLIENTECONTA`,
  `viewcliente`.`PESSOAID`,
  `viewcliente`.`PESSOANOME`,
  `viewcliente`.`PESSOADATA`,
  `viewcliente`.`PESSOACONTACTO`,
  `viewcliente`.`PESSOAMORADA`,
  `viewcliente`.`PESSOABI`,
  `viewcliente`.`TIPOCLIENTEID`,
  `viewcliente`.`TIPOCLIENTENOME`,
  `viewusuario`.`USUARIOID`,
  `viewusuario`.`PREVILEGIOID`,
  `viewusuario`.`USUARIONOME`,
  `viewusuario`.`USUARIOSENHA`,
  `viewusuario`.`USUARIONOMECOMPLETO`,
  `viewusuario`.`PREVILEGIONOME`
FROM
  (((`venda`
    JOIN `viewproduto` ON ((`venda`.`PRODUTOID` = `viewproduto`.`PRODUTOID`)))
    JOIN `viewcliente` ON ((`venda`.`CLIENTEID` = `viewcliente`.`CLIENTEID`)))
    JOIN `viewusuario` ON ((`venda`.`USUARIOID` = `viewusuario`.`USUARIOID`)));

#
# View "viewvendatemp"
#

DROP VIEW IF EXISTS `viewvendatemp`;
CREATE
  ALGORITHM = UNDEFINED
  VIEW `viewvendatemp`
  AS
SELECT
  `vendatemp`.`VENDATEMPID`,
  `vendatemp`.`CLIENTEID`,
  `vendatemp`.`VENDAQUANTIDADE`,
  `viewproduto`.`PRODUTOID`,
  `viewproduto`.`CATEGORIAID`,
  `viewproduto`.`PRODUTONOME`,
  `viewproduto`.`PRODUTOPRECO`,
  `viewproduto`.`CATEGORIANOME`,
  (`viewproduto`.`PRODUTOPRECO` * `vendatemp`.`VENDAQUANTIDADE`) AS 'PRODUTOPRECOTOTAL'
FROM
  (`vendatemp`
    JOIN `viewproduto` ON ((`vendatemp`.`PRODUTOID` = `viewproduto`.`PRODUTOID`)));

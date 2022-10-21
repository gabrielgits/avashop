# Host: localhost  (Version 5.7.16-log)
# Date: 2017-06-13 10:57:36
# Generator: MySQL-Front 6.0  (Build 1.73)


#
# Data for table "categoria"
#

REPLACE INTO `categoria` (`CATEGORIAID`,`CATEGORIANOME`) VALUES (1,'Artigos'),(2,'Bebidas');

#
# Data for table "fornecedore"
#

REPLACE INTO `fornecedore` (`FORNECEDORID`,`FORNECEDORCONTACTO`,`FORNECEDORNOME`,`FORNECEDORENDERECO`) VALUES (1,'923','Lito','923');

#
# Data for table "pessoa"
#

REPLACE INTO `pessoa` (`PESSOAID`,`PESSOANOME`,`PESSOADATA`,`PESSOACONTACTO`,`PESSOAMORADA`,`PESSOABI`) VALUES (1,'anonimo',NULL,NULL,NULL,NULL);

#
# Data for table "previlegio"
#

REPLACE INTO `previlegio` (`PREVILEGIOID`,`PREVILEGIONOME`) VALUES (1,'Admin'),(2,'Anónimo');

#
# Data for table "produto"
#

REPLACE INTO `produto` (`PRODUTOID`,`CATEGORIAID`,`PRODUTONOME`,`PRODUTOPRECO`) VALUES (1,1,'Computador',500),(2,1,'Memoria',79999),(3,2,'Cuca',100),(4,1,'arroz',150);

#
# Data for table "stock"
#

REPLACE INTO `stock` (`STOCKID`,`PRODUTOID`,`STOCKQUANTIA`,`STOCKUPDATE`) VALUES (1,1,8,'2017-05-25'),(2,2,15,'2017-05-25');

#
# Data for table "tipocliente"
#

REPLACE INTO `tipocliente` (`TIPOCLIENTEID`,`TIPOCLIENTENOME`) VALUES (1,'Regular'),(2,'Anónimo');

#
# Data for table "cliente"
#

REPLACE INTO `cliente` (`CLIENTEID`,`PESSOAID`,`TIPOCLIENTEID`,`CLIENTECONTA`) VALUES (1,1,1,0);

#
# Data for table "usuario"
#

REPLACE INTO `usuario` (`USUARIOID`,`PREVILEGIOID`,`USUARIONOME`,`USUARIOSENHA`,`USUARIONOMECOMPLETO`) VALUES (1,1,'admin','admin','Gabriel Vieira');

#
# Data for table "compra"
#

REPLACE INTO `compra` (`COMPRAID`,`COMPRADATA`,`COMPRAQUANTIDADE`,`PRODUTOID`,`USUARIOID`,`FORNECEDORID`,`COMPRAPRECO`) VALUES (1,'2017-05-25',10,1,1,1,500),(2,'2017-05-25',15,2,1,1,4000);

#
# Data for table "venda"
#

REPLACE INTO `venda` (`VENDAID`,`PRODUTOID`,`CLIENTEID`,`USUARIOID`,`VENDAQUANTIDADE`,`VENDADATA`) VALUES (1,1,1,1,2,'2017-05-25'),(2,3,1,1,3,'2017-05-25'),(3,3,1,1,10,'2017-05-25'),(4,4,1,1,10,'2017-05-25');

#
# Data for table "vendatemp"
#


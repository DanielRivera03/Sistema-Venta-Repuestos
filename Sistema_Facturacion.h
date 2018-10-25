/*
																	    	A.C.E.&.M Soluciones Informaticas
																Sistema de gestión para cadena de repuestos automotriz
																	 © Copyright 2017 Reservados Todos Los Derechos
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

/*

	~~~ Mapa Interno de Codigo Fuente: ~~~
	1) Struct sistema de facturacion tipo clientes
	2) Struct sistema de facturacion tipo productos
	3) Inicializacion de struct tipo clientes
	4) Inicializacion de struct tipo productos
	5) Agregar datos a facturacion tipo clientes
	6) Agregar datos a facturacion tipo productos
	7) Calculo de precio en facturacion
	8) Vista de datos de facturacion tipo clientes
	9) Vista de datos de facturacion tipo productos
	10) Eliminar datos de facturacion tipo clientes
	11) Eliminar datos de facturacion tipo productos
	12) Struct de sistema de cotizacion
	13) Inicializacion de struct de sistema de cotizacion
	14) Agregar datos a sistema de cotizacion
	15) Calculo de precio en cotizacion
	
*/

/*********************************************
	FACTURACION DE PRODUCTOS Y COTIZACION
**********************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 1 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 1) Inicio datos de usuario por cada factura final
struct facturacion_speedlimit_datos_cliente{
	char nombre_cliente[100];// Nombre de cliente
	int codigo_compra;// Codigo de factura final unico por cada compra
	char num_DUI[75];// Numero de DUI de cliente
	char num_NIT[75];// Numero de NIT de cliente
	int dia_facturacion;// Dia de facturacion
	int mes_facturacion;// Mes de facturacion
	int a_o_facturacion;// Año de facturacion
	// Metodos (Prototipos)
	facturacion_speedlimit_datos_cliente();
	void agregar_nuevo_cliente(void);// Genera nuevos datos de cliente por factura
	void ver_datos_usuario_factura(void);// Ver datos de clientes
	void eliminar_clientes_factura(void);// Elimina datos de clientes
};
// Fin datos de usuario por cada factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 2 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 2) Inicio struct factura final de productos
struct facturacion_speedlimit_productos{
	char nombre_productos_compra[100];// Nombre de productos que procedera a comprar
	int cantidad_productos;// N cantidad de productos a procesar
	double precio_productos_compra;// Precio por articulo a comprar
	double calculo_precio;
	// Metodos (Prototipos)
	facturacion_speedlimit_productos();
	void generar_nueva_factura_productos(void);// Genera nueva factura final de compra
	void calcular(void);// Calcula precio final de factura
	void ver_datos_productos_factura(void);// Despliega N lista de factura a visualizar
	void eliminar_productos_factura(void);// Elimina datos de productos en factura
};
// Fin struct factura final de productos

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 3 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 3) Inicializacion de datos de cliente para nueva factura final
facturacion_speedlimit_datos_cliente::facturacion_speedlimit_datos_cliente(){
	nombre_cliente[0]='\0';
	strcpy(nombre_cliente,"DESCONOCIDO...");
	num_DUI[0]='\0';
	num_NIT[0]='\0';
	strcpy(num_DUI,"DESCONOCIDO...");
	strcpy(num_NIT,"DESCONOCIDO...");
	int codigo_compra=0;
	int dia_facturacion=0;
	int mes_facturacion=0;
	int a_o_facturacion=0;
}
// Fin inicializacion de datos de clientes para nueva factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 4 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 4) Inicializacion de datos para nueva factura final
facturacion_speedlimit_productos::facturacion_speedlimit_productos(){
	nombre_productos_compra[0]='\0';
	strcpy(nombre_productos_compra,"DESCONOCIDO...");
	cantidad_productos=0;
	precio_productos_compra=0;
	calculo_precio=0;
}
// Fin inicializacion de datos para nueva factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 5 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 5) Inicio procedimiento generando nueva factura final datos clientes
void facturacion_speedlimit_datos_cliente::agregar_nuevo_cliente(){
	cout<<"\n Primera etapa: Datos del cliente."<<endl<<endl;
	cout<<"\n Ingrese nombre de cliente: ";
	fflush(stdin);// Limpia buffer de teclado
	gets(this->nombre_cliente);// Captura nombre de cliente
	cout<<"\n Ingrese codigo unico de compra: ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->codigo_compra;// Captura codigo unico de compra
	cout<<"\n Ingrese numero de DUI de cliente (Sin Guion): ";
	fflush(stdin);// Limpia buffer de teclado
	gets(this->num_DUI);// Captura numero de DUI de cliente
	cout<<"\n Ingrese numero de NIT de cliente (Sin Guiones): ";
	fflush(stdin);// Limpia buffer de teclado
	gets(this->num_NIT);// Captura numero de NIT de cliente
	cout<<"\n Ingrese dia de creacion de factura: ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->dia_facturacion;// Captura dia de facturacion
	cout<<"\n Ingrese mes de creacion de factura: ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->mes_facturacion;// Captura mes de facturacion
	cout<<"\n Ingrese a"<<char(164)<<"o de creacion de factura: ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->a_o_facturacion;// Captura año de facturacion
}
// Fin procedimiento generando nueva factura final datos clientes

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 6 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 6) Inicio procedimiento generando nueva factura final datos productos
void facturacion_speedlimit_productos::generar_nueva_factura_productos(){
	cout<<"\n Segunda etapa: Datos de productos."<<endl<<endl;
	cout<<"\n Ingrese nombre de producto: ";
	fflush(stdin);// Limpia buffer de teclado
	gets(this->nombre_productos_compra);// Captura nombre de productos ha agregar en factura final
	cout<<"\n Ingrese la cantidad a comprar de "<<nombre_productos_compra<<": ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->cantidad_productos;
	cout<<"\n Ingrese precio de "<<nombre_productos_compra<<": $";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->precio_productos_compra;// Captura precio de productos
	cout<<endl;
	cout<<" Generando Factura Final";
	for(int b_e=0;b_e<6;b_e++){
		Sleep(550);
		cout<<" . ";
	}
	cout<<endl;
	cout<<"\n Presione ENTER para regresar al menu..."<<endl;
}
// Fin procedimiento generando nueva factura final datos productos

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 7 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 7) Inicio calculo de precio productos factura final
void facturacion_speedlimit_productos::calcular(){
	calculo_precio=precio_productos_compra*cantidad_productos;	
}
// Fin calculo de precio productos factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 8 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 8) Inicio ver datos ingresados de clientes
void facturacion_speedlimit_datos_cliente::ver_datos_usuario_factura(){
	cout<<"\n Nombre de cliente: "<<nombre_cliente<<"."<<endl;
	cout<<"\n Codigo Unico de Compra: "<<codigo_compra<<"."<<endl;
	cout<<"\n Numero de DUI de cliente: "<<num_DUI<<"."<<endl;
	cout<<"\n Numero de NIT de cliente: "<<num_NIT<<"."<<endl;
	cout<<"\n Fecha: "<<dia_facturacion<<"/"<<mes_facturacion<<"/"<<a_o_facturacion<<"."<<endl;
}
// Fin ver datos ingresados de clientes

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 9 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 9) Inicio ver datos de productos ingresados factura final
void facturacion_speedlimit_productos::ver_datos_productos_factura(){
	cout<<"\n Nombre de producto: "<<nombre_productos_compra<<"."<<endl;
	cout<<"\n Cantidad de productos: "<<cantidad_productos<<" "<<nombre_productos_compra<<"."<<endl;
	cout<<"\n Precio de producto: $"<<precio_productos_compra<<" USD."<<endl;
}
// Fin ver datos de productos ingresados factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 10 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 10) Inicio eliminar datos clientes factura final
void facturacion_speedlimit_datos_cliente::eliminar_clientes_factura(){
	cout<<"\n Datos del cliente que usted eligio: "<<endl;
	this->ver_datos_usuario_factura(); // Despliega N producto a eliminar elegido por usuario
	cout<<"\n Eliminando cliente, espere un momento ";
	for(int b_e=0;b_e<7;b_e++){
		Sleep(600);
		cout<<" . ";
	}
	cout<<"\n\n Cliente eliminado con exito!!!"<<endl;
}
// Fin eliminar datos clientes factura final

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 11 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 11) Inicio eliminar datos productos factura final
void facturacion_speedlimit_productos::eliminar_productos_factura(){
	cout<<"\n Datos del producto que usted eligio: "<<endl;
	this->ver_datos_productos_factura(); // Despliega N producto a eliminar elegido por usuario
	cout<<"\n Eliminando producto, espere un momento ";
	for(int b_e=0;b_e<7;b_e++){
		Sleep(600);
		cout<<" . ";
	}
	cout<<"\n\n Producto eliminado con exito!!!"<<endl;
}
// Fin eliminar datos productos factura final

/****************************************
	SISTEMA DE COTIZACIONES CLIENTES
*****************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 12 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 12) struct sistema cotizacion
struct sistema_cotizacion{
	char nombre_producto_cotizacion[100];
	int cantidad_productos_cotizacion;
	double precio_productos_cotizacion;
	double calculo_precio_cotizacion;
	// Metodos (Prototipos)
	sistema_cotizacion();
	void generar_cotizacion(void);// Genera Nueva Cotizacion
	//void ver_cotizacion(void);// Vista de cotizacion generada por usuario
	void calcular_cotizacion(void);// Calcula precio de productos en cotizacion
};
// Fin struct sistema cotizacion

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 13 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 13) Inicio inicializacion de datos
sistema_cotizacion::sistema_cotizacion(){
	nombre_producto_cotizacion[0]='\0';
	strcpy(nombre_producto_cotizacion,"DESCONOCIDO...");
	cantidad_productos_cotizacion=0;
	precio_productos_cotizacion=0;
	calculo_precio_cotizacion=0;
}
// Fin inicializacion de datos

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 14 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 14) Inicio generar nueva cotizacion 
void sistema_cotizacion::generar_cotizacion(){
	cout<<"\n Ingrese el nombre del producto: ";
	fflush(stdin);// Limpia buffer de teclado
	gets(this->nombre_producto_cotizacion);
	cout<<"\n Ingrese la cantidad de "<<nombre_producto_cotizacion<<" que desea ordenar: ";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->cantidad_productos_cotizacion;
	cout<<"\n Ingrese el precio de "<<nombre_producto_cotizacion<<": $";
	fflush(stdin);// Limpia buffer de teclado
	cin>>this->precio_productos_cotizacion;
	cout<<endl<<endl;
	cout<<" Generando Cotizacion, Espere Por Favor";
	for(int b_e=0;b_e<6;b_e++){
		Sleep(550);
		cout<<" . ";
	}
	cout<<endl;
	cout<<"\n Presione ENTER para regresar al menu..."<<endl;
}
// Fin generar nueva cotizacion

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 15 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 15) Inicio calcular precio de cotizacion
void sistema_cotizacion::calcular_cotizacion(){
	calculo_precio_cotizacion=precio_productos_cotizacion*cantidad_productos_cotizacion;
}
// Fin calcular precio de cotizacion

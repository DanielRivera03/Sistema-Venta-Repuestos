/*
																	    	A.C.E.&.M Soluciones Informaticas
																Sistema de gestión para cadena de repuestos automotriz
																	 © Copyright 2017 Reservados Todos Los Derechos
*/
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

/*
	~~~ Mapa Interno de Codigo Fuente: ~~~
	1) Struct productos_speedlimit
	2) Inicializacion de struct productos_speedlimit
	3) Agregar productos al sistema
	4) Recuperar lista de productos ingresados en el sistema
	5) Modificar Productos
	6) Eliminar Productos
	7) Inicio de struct inventario datos usuario
	8) Inicio de struct inventario datos productos
	9) Inicializacion de datos struct inventario datos usuario
	10) Inicializacion de datos struct inventario datos productos
	11) Ingresar datos a inventario mensual tipo usuario
	12) Ingresar datos a inventario mensual tipo productos
	13) Recuperar informe de inventario mensual tipo productos
	14) Recuperar informe de inventario mensual tipo usuario
	15) Ingresar datos a inventario trimestral tipo usuario
	16) Ingresar datos a inventario trimestral tipo productos
	17) Recuperar informe de inventario trimestral tipo usuario
	18) Recuperar informe de inventario trimestral tipo productos
	19) Ingresar datos a inventario anual tipo usuario
	20) Ingresar datos a inventario anual tipo productos
	21) Recuperar informe de inventario anual tipo usuario
	22) Recuperar informe de inventario anual tipo productos
	23) Modificar informe de inventario mensual tipo usuario
	24) Modificar informe de inventario mensual tipo productos
	25) Modificar informe de inventario trimestral tipo usuario
	26) Modificar informe de inventario trimestral tipo productos
	27) Modificar informe de inventario anual tipo usuario
	28) Modificar informe de inventario anual tipo productos
	29) Eliminar informe de inventario mensual tipo usuario
	30) Eliminar informe de inventario mensual tipo productos
	31) Eliminar informe de inventario trimestral tipo usuario
	32) Eliminar informe de inventario trimestral tipo productos
	33) Eliminar informe de inventario anual tipo usuario
	34) Eliminar informe de inventario anual tipo productos
	35) Calcular precio de inventarios
*/

/******************************************
				PRODUCTOS
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 1 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 1) Inicio struct para ingreso de nuevos productos
struct productos_speedlimit{
	char nombre_producto[100]; // Nombre de producto
	char modelo_producto[100];// Modelo de producto
	char fabricante_producto[100]; // Nombre de fabricante de producto
	char categoria_producto[100]; // Categoria de producto
	int codigo_producto; // Codigo de producto
	int existencias_producto; // 	N cantidad de productos en existencias
	double precio_producto; // Precio de producto
	float garantia_producto; // Garantia de producto (N meses / años)
	int clave;// Clave unica de productos
	int auxClave;// Clave auxiliar ingresada por usuario para busqueda de producto
	// Metodos (Prototipos)
	productos_speedlimit();
	void agregar_productos(void); // Agregar productos al sistema
	void recuperar(void);// Recuperar lista de productos ingresados al sistema
	//void ver_lista_productos(void); // Ver lista de productos agregados al sistema
	void modificar_productos(void); // Modificar lista de productos ingresados al sistema
	void eliminar_productos(void); // Eliminar N producto de la lista de productos ingresados al sistema
};
// Fin de struct para ingreso de nuevos productos
/******************************************
	INICIALIZACION DE STRUCT PRODUCTOS
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 2 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 2) Inicio de inicializacion de datos para struct nuevos_productos
productos_speedlimit::productos_speedlimit(){
	nombre_producto[0]='\0';
	fabricante_producto[0]='\0';
	categoria_producto[0]='\0';
	modelo_producto[0]='\0';
	strcpy(nombre_producto,"Sin Nombre...");
	strcpy(fabricante_producto,"Desconocido...");
	strcpy(categoria_producto,"Sin Categoria...");
	strcpy(modelo_producto,"No Especificado...");
	codigo_producto=0;
	existencias_producto=0;
	precio_producto=0;
	garantia_producto=0;
	clave=0;
	auxClave=0;
}
// Fin de inicializacion de datos para struct nuevos_productos
/******************************************
	  AGREGAR PRODUCTOS AL SISTEMA
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 3 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 3) Inicio procedimiento para agregar productos al sistema
void productos_speedlimit::agregar_productos(){
	ofstream escritura;
	escritura.open("productos.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n Ingresa la clave unica del producto: ";
		cin>>clave;
		cout<<"\n Ingrese nombre de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_producto); // Captura nombre de producto
		cout<<"\n Ingrese el modelo del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->modelo_producto);// Captura modelo de producto
		cout<<"\n Ingrese nombre de fabricante de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->fabricante_producto); // Captura nombre de fabricante de producto
		cout<<"\n Ingrese la categoria de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->categoria_producto); // Captura categoria de producto
		cout<<"\n Ingrese el codigo de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->codigo_producto; // Captura codigo de producto
		cout<<"\n Ingrese numero de existencias de producto: ";
		fflush(stdin);// Limpia buffer de teclaso
		cin>>this->existencias_producto; // Captura N cantidad de productos en existencias
		cout<<"\n Ingrese el precio del producto: $";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->precio_producto; // Captura precio de producto
		cout<<"\n Ingrese periodo de garantia en meses: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->garantia_producto; // Captura N periodo de garantia de producto
		cout<<endl;
		cout<<" Agregando productos ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
		cout<<"\n Productos agregados con exito!!!\n\n Presione ENTER para volver al menu."<<endl;
		}else{
			cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
		}
	escritura.close();
}
// Fin procedimiento para agregar productos al sistema
/******************************************
	   RECUPERAR LISTA DE PRODUCTOS
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 4 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 4) Inicio procedimiento recuperar lista de productos
void productos_speedlimit::recuperar(){
	ifstream lectura;
	lectura.open("productos.txt",ios::out|ios::in);
	if(lectura.is_open()){
		cout<<"\n Archivo abierto con exito..."<<endl;
		cout<<"\n Productos registrados en archivo productos.txt"<<endl;
		cout<<"________________________________________________________________________________"<<endl;
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
			// Imprime datos al programa
			cout<<" Datos de producto "<<i<<": "<<endl<<endl;
			cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
			cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
			cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
			cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
			cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
			cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
			cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
			cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
			cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
			lectura>>clave;// Fin lectura adelantada
			cout<<"________________________________________________________________________________"<<endl;
			i++;// Contador de productos
		}
		cout<<"\n Presione ENTER para volver al menu...";
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin procedimiento recuperar lista de productos
/******************************************
		    MODIFICAR PRODUCTOS
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 5 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/


// 5) Inicio procedimiento modificar productos
void productos_speedlimit::modificar_productos(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre[50];// Nombre auxiliar a modificar
    	char auxModelo[50];// Modelo auxiliar a modificar
    	char auxFabricante[50];// Fabricante auxiliar a modificar
    	char auxCategoria[50];// Categoria auxiliar a modificar
    	int auxCodigo_Producto;// Codigo de producto auxiliar a modificar
    	int auxExistencias;// Numero de existencias en lote auxiliar a modificar
    	double auxPrecio;// Precio de productos auxiliar a modificar
    	float auxGarantia;// N periodo de garantia auxiliar a modificar
    	aux.open("auxiliar.txt",ios::out);
    	lectura.open("productos.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
						cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
    	cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar nombre de producto."<<endl;
		cout<<" B. Modificar modelo de producto."<<endl;
		cout<<" C. Modificar fabricante de producto."<<endl;
		cout<<" D. Modificar categoria de producto."<<endl;
		cout<<" E. Modificar codigo de producto."<<endl;
		cout<<" F. Modificar numero de existencias en lote de producto."<<endl;
		cout<<" G. Modificar precio unitario de producto."<<endl;
		cout<<" H. Modificar garantia de producto."<<endl;
		cout<<" I. Regresar."<<endl;
		cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		switch(opcion){
			// Modificar nombre de productos
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        		system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
							cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo nombre del producto con clave unica --> "<<clave<<": ";
                		cin>>auxNombre;// Captura nuevo nombre auxiliar
                		aux<<clave<<" "<<auxNombre<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			// Modificar modelo de producto
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        		system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
							cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo nombre del producto con clave unica --> "<<clave<<": ";
                		cin>>auxModelo;// Captura nuevo nombre auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<auxModelo<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;	
			// Modificar fabricante de productos
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo fabricante del producto con clave unica --> "<<clave<<": ";
                		cin>>auxFabricante;// Captura nuevo nombre de fabricante auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<auxFabricante<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			// Modificar Categoria de Producto
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo codigo del producto con clave unica --> "<<clave<<": ";
                		cin>>auxCategoria;// Captura nueva categoria auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<auxCategoria<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");	
			break;
			// Modificar codigo de producto
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo codigo del producto con clave unica --> "<<clave<<": #";
                		cin>>auxCodigo_Producto;// Captura nuevo codigo de producto auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<auxCodigo_Producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			// Modificar numero de existencias en lote de producto
			case 'f':case 'F':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa la nueva cantidad de existencias del producto con clave unica --> "<<clave<<": ";
                		cin>>auxExistencias;// Captura nuevo N numero de existencias de producto auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<auxExistencias<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			case 'g':case 'G':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el nuevo precio del producto con clave unica --> "<<clave<<": $";
                		cin>>auxPrecio;// Captura nuevo precio de producto auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<auxPrecio<<" "<<garantia_producto<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			case 'h':case 'H':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de producto
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de productos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t      Modificar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
            		lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            		if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                		encontrado=true;
                		cout<<"\t Clave unica de producto: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_producto<<"."<<endl;
						cout<<"\t Fabricante de producto: "<<fabricante_producto<<"."<<endl;
						cout<<"\t Categoria de producto: "<<categoria_producto<<"."<<endl;
						cout<<"\t Codigo de producto: "<<codigo_producto<<"."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_producto<<" unidades."<<endl;
						cout<<"\t Precio: $"<<precio_producto<<" USD."<<endl;
						cout<<"\t Garantia: "<<garantia_producto<<" meses."<<endl;
                		cout<<"\n Ingresa el periodo de garantia en meses del producto con clave unica --> "<<clave<<": ";
                		cin>>auxGarantia;// Captura nuevo periodo de garantia de producto auxiliar
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<auxGarantia<<" "<<endl;
                		cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
            		}else{
                		aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            		}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
			break;
			// Sale de menu de modificacion
			case 'i':case 'I':
				salir_menu=true;
		}
	}while(!salir_menu);
}
// Fin procedimiento modificar productos
/******************************************
			ELIMINAR PRODUCTOS
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 6 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/


// 6) Inicio procedimiento eliminar productos
void productos_speedlimit::eliminar_productos(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar.txt",ios::out);
    lectura.open("productos.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t\t      Eliminar Productos"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
            lectura>>nombre_producto>>modelo_producto>>fabricante_producto>>categoria_producto>>codigo_producto>>existencias_producto>>precio_producto>>garantia_producto;
            if(auxClave==clave){// Si encuentra clave, entonces mostrar....
                encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Registro o con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_producto<<" "<<modelo_producto<<" "<<fabricante_producto<<" "<<categoria_producto<<" "<<codigo_producto<<" "<<existencias_producto<<" "<<precio_producto<<" "<<garantia_producto<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("productos.txt");
    			rename("auxiliar.txt","productos.txt");
}
// Fin procedimiento eliminar productos

/************************************************
					INVENTARIO
************************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 7 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 7) Inicio de struct para inventario_speedlimit_usuario
struct inventario_speedlimit_usuario{
	// Primera etapa
	char nombre_usuario[100]; // Primer Nombre de Usuario
	char apellido_usuario[100];// Primer Apellido de Usuario
	int codigo_empleado; // Codigo de empleado que realiza inventario
	int dia; // Dia que realiza inventario
	int mes; // Mes que realiza inventario
	int a_o; // Año que realiza inventario
	int clave;// Clave unica de inventario
	int auxClave;// Clave auxiliar ingresada por usuario para busqueda de producto
	// Metodos (Prototipos)
	inventario_speedlimit_usuario();
	// Agregar ...
	void agregar_inventario_mensual(void); // Inventario mensual
	void agregar_inventario_trimestral(void); // Inventario trimestral
	void agregar_inventario_anual(void); // Inventario anual
	// Ver ...
	void recuperar_datos_usuario_inventario_mensual(void);// Recupera datos de empleado registrados en inventario mensual
	void recuperar_datos_usuario_inventario_trimestral(void);// Recupera datos de empleado registrados en inventario trimestral
	void recuperar_datos_usuario_inventario_anual(void);// Recupera datos de empleado registrados en inventario anual
	// Modificar ...
	void modificar_inventario_mensual(void); // Modifica registro de inventario mensual tipo usuario
	void modificar_inventario_trimestral(void); // Modifica registro de inventario trimestral tipo usuario
	void modificar_inventario_anual(void); // Modifica registro de inventario anual tipo usuario
	// Eliminar ...
	void eliminar_inventario_mensual(void); // Elimina registro de inventario mensual tipo usuario
	void eliminar_inventario_trimestral(void); // Elimina registro de inventario trimestral tipo usuario
	void eliminar_inventario_anual(void); // Elimina registro de inventario anual tipo usuario
};
// Fin de struct para inventario_speedlimit_usuario

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 8 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 8) Inicio de struct para inventario_speedlimit
struct inventario_speedlimit{
	// Segunda etapa
	char nombre_de_producto[100]; // Nombre de producto a registrar
	char modelo_de_producto[100];// Modelo de producto a registrar
	char marca_producto[100];// Captura marca de producto
	float precio_de_producto; // Precio unitario de producto a registrar
	int existencias_en_lote; // N cantidad de productos existentes en lote
	double subtotal_inventario;// Calcula monto total de productos dentro del inventario
	int clave;// Clave unica de productos
	int auxClave;// Clave auxiliar ingresada por usuario para busqueda de producto
	// Metodos (Prototipos)
	inventario_speedlimit();
	// Agregar ....
	void agregar_inventario_mensual(void); // Inventario mensual
	void agregar_inventario_trimestral(void); // Inventario trimestral
	void agregar_inventario_anual(void); // Inventario anual
	// Ver ....
	void recuperar_datos_productos_inventario_mensual(void);// Recupera datos de productos registrados en inventario mensual
	void recuperar_datos_productos_inventario_trimestral(void);// Recupera datos de productos registrados en inventario trimestral
	void recuperar_datos_productos_inventario_anual(void);// Recupera datos de productos registrados en inventario anual
	// Modificar ....
	void modificar_inventario_mensual_productos(void); // Modifica registro de inventario mensual tipo productos
	void modificar_inventario_trimestral_productos(void); // Modifica registro de inventario trimestral tipo productos 
	void modificar_inventario_anual_productos(void); //Modifica registro de inventario anual tipo productos
	// Eliminar ....
	void eliminar_inventario_mensual_productos(void); // Elimina registro de inventario mensual tipo productos
	void eliminar_inventario_trimestral_productos(void); // Elimina registro de inventario trimestral tipo productos
	void eliminar_inventario_anual_productos(void); // Elimina registro de inventario anual tipo productos
	// Calcular ....
	void calcular_precio_inventario(void); // Calcula monto total de productos registrados en inventario
};
// Fin de struct para inventario_speedlimit

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 9 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 9) Inicio de inicializacion de datos para struct inventario_speedlimit_usuario
inventario_speedlimit_usuario::inventario_speedlimit_usuario(){
	nombre_usuario[0]='\0'; // Primera etapa
	strcpy(nombre_usuario,"Desconocido...");
	apellido_usuario[0]='\0';
	strcpy(apellido_usuario,"Desconocido...");
	int codigo_empleado=0;
	int dia=0;
	int mes=0;
	int a_o=1900;
	double subtotal_inventario=0;
	int clave=0;
	int auxClave=0;
}
// Fin de inicializacion de datos para struct inventario_speedlimit_usuario

/******************************************
  INICIALIZACION INVENTARIO DATOS USUARIO
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 10 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 10) Inicio de inicializacion de datos para struct inventario_speedlimit
inventario_speedlimit::inventario_speedlimit(){
	nombre_de_producto[0]='\0'; // Segunda etapa
	strcpy(nombre_de_producto,"Sin Datos...");
	modelo_de_producto[0]='\0';
	strcpy(modelo_de_producto,"Sin Datos...");
	marca_producto[0]='\0';
	strcpy(marca_producto,"Desconocido...");
	float precio_de_producto=0;
	int existencias_en_lote=0;
	int clave=0;
	int auxClave=0;
}
// Fin de inicializacion de datos para struct inventario_speedlimit
/******************************************
 INGRESAR DATOS EMPLEADO INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 11 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 11) Inicio de procesos de ingreso de datos inventario mensual tipo: usuario
void inventario_speedlimit_usuario::agregar_inventario_mensual(){
	ofstream escritura;
	escritura.open("datos_inventario_mensual_usuario.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n Primera etapa: Datos de usuario."<<endl<<endl;
		cout<<"\n Ingrese clave unica de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese su 1"<<char(248)<<"er nombre: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_usuario);// Captura primer nombre de usuario
		cout<<"\n Ingrese su 1"<<char(248)<<"er apellido: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->apellido_usuario);// Captura primer apellido de usuario
		cout<<"\n Ingrese su codigo de empleado: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->codigo_empleado;// Captura codigo de empleado
		cout<<"\n Ingrese dia de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->dia;// Captura dia de creacion de inventario
		cout<<"\n Ingrese mes de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->mes;// Captura mes de creacion de inventario
		cout<<"\n Ingrese a"<<char(164)<<"o de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->a_o;// Captura año de creacion de inventario
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
/******************************************
  INGRESAR PRODUCTOS INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 12 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 12) Inicio de procesos para ingreso de datos inventario mensual tipo: inventario
void inventario_speedlimit::agregar_inventario_mensual(){
	ofstream escritura;
	escritura.open("datos_inventario_mensual_productos.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n\n Segunda etapa: Datos de productos."<<endl<<endl;
		cout<<"\n Ingrese la clave unica del producto para manejo de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese nombre de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_de_producto);// Captura nombre de producto
		cout<<"\n Ingrese el modelo del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->modelo_de_producto);// Captura modelo de producto
		cout<<"\n Ingrese la marca del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->marca_producto);// Captura marca de producto
		cout<<"\n Ingrese precio unitario de producto: $";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->precio_de_producto;// Captura precio de producto
		cout<<"\n Ingrese cantidad de productos en existencias en lote: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->existencias_en_lote;
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
		cout<<"\n\n Informe agregado con exito!!!\n\n Presione ENTER para continuar..."<<endl;
		getch();
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
// Fin de procesos para ingreso de datos inventario mensual
/******************************************
  RECUPERAR INFORME INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 13 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 13) Inicio recuperacion de datos inventario mensual empleados
void inventario_speedlimit_usuario::recuperar_datos_usuario_inventario_mensual(){
	ifstream lectura;
	lectura.open("datos_inventario_mensual_usuario.txt",ios::out|ios::in);
	if(lectura.is_open()){
		cout<<"\n Archivo abierto con exito..."<<endl;
		cout<<"\n Informe completo de inventario mensual."<<endl;
		cout<<"________________________________________________________________________________"<<endl;
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
			// Imprime datos al programa
			cout<<" Informe de Inventario Mensual: "<<endl<<endl;
			cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
			cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
			cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
			lectura>>clave;// Fin lectura adelantada
		}
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario mensual empleados

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 14 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 14) Inicio recuperacion de datos inventario mensual productos
void inventario_speedlimit::recuperar_datos_productos_inventario_mensual(){
	ifstream lectura;
	lectura.open("datos_inventario_mensual_productos.txt",ios::out|ios::in);
	if(lectura.is_open()){
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
			// Imprime datos al programa
			cout<<endl;
			cout<<"\t Datos de producto "<<i<<": "<<endl<<endl;
			cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
			cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
			cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
			cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
			cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
			cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
			double monto_final;
			monto_final=precio_de_producto*existencias_en_lote;
			cout<<"\t----------------------------------------------"<<endl;
			cout<<"\n\t- Monto total de productos: $"<<monto_final<<" USD. -"<<endl;// Imprime monto total de productos dentro de inventario
			cout<<"\t----------------------------------------------"<<endl;
			lectura>>clave;// Fin lectura adelantada
			i++;// Contador de productos
		}
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"\n Presione ENTER para volver al menu...";
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario mensual productos
/******************************************
 INGRESAR DATOS USUARIO INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 15 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 15) Inicio de procesos de ingreso de datos inventario trimestral tipo: usuario
void inventario_speedlimit_usuario::agregar_inventario_trimestral(){
	ofstream escritura;
	escritura.open("datos_inventario_trimestral_usuario.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n Primera etapa: Datos de usuario."<<endl<<endl;
		cout<<"\n Ingrese clave unica de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese su 1"<<char(248)<<"er nombre: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_usuario);// Captura primer nombre de usuario
		cout<<"\n Ingrese su 1"<<char(248)<<"er apellido: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->apellido_usuario);// Captura primer apellido de usuario
		cout<<"\n Ingrese su codigo de empleado: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->codigo_empleado;// Captura codigo de empleado
		cout<<"\n Ingrese dia de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->dia;// Captura dia de creacion de inventario
		cout<<"\n Ingrese mes de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->mes;// Captura mes de creacion de inventario
		cout<<"\n Ingrese a"<<char(164)<<"o de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->a_o;// Captura año de creacion de inventario
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
// Fin de procesos de ingreso de datos inventario trimestral tipo: usuario
/******************************************
  INGRESAR PRODUCTOS INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 16 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 16) Inicio de procesos para ingreso de datos inventario trimestral tipo: inventario
void inventario_speedlimit::agregar_inventario_trimestral(){
	ofstream escritura;
	escritura.open("datos_inventario_trimestral_productos.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n\n Segunda etapa: Datos de productos."<<endl<<endl;
		cout<<"\n Ingrese la clave unica del producto para manejo de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese nombre de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_de_producto);// Captura nombre de producto
		cout<<"\n Ingrese el modelo del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->modelo_de_producto);// Captura modelo de producto
		cout<<"\n Ingrese la marca del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->marca_producto);// Captura marca de producto
		cout<<"\n Ingrese precio unitario de producto: $";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->precio_de_producto;// Captura precio de producto
		cout<<"\n Ingrese cantidad de productos en existencias en lote: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->existencias_en_lote;
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
		cout<<"\n\n Informe agregado con exito!!!\n\n Presione ENTER para continuar..."<<endl;
		getch();
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
// Fin de procesos para ingreso de datos inventario trimestral
/******************************************
  RECUPERAR INFORME INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 17 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 17) Inicio recuperacion de datos inventario trimestral empleados
void inventario_speedlimit_usuario::recuperar_datos_usuario_inventario_trimestral(){
	ifstream lectura;
	lectura.open("datos_inventario_trimestral_usuario.txt",ios::out|ios::in);
	if(lectura.is_open()){
		cout<<"\n Archivo abierto con exito..."<<endl;
		cout<<"\n Informe completo de inventario trimestral."<<endl;
		cout<<"________________________________________________________________________________"<<endl;
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
			// Imprime datos al programa
			cout<<" Informe de Inventario Mensual: "<<endl<<endl;
			cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
			cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
			cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
			lectura>>clave;// Fin lectura adelantada
		}
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario trimestral empleados

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 18 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 18) Inicio recuperacion de datos inventario trimestral productos
void inventario_speedlimit::recuperar_datos_productos_inventario_trimestral(){
	ifstream lectura;
	lectura.open("datos_inventario_trimestral_productos.txt",ios::out|ios::in);
	if(lectura.is_open()){
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
			// Imprime datos al programa
			cout<<endl;
			cout<<"\t Datos de producto "<<i<<": "<<endl<<endl;
			cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
			cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
			cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
			cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
			cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
			cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
			double monto_final;
			monto_final=precio_de_producto*existencias_en_lote;
			cout<<"\t----------------------------------------------"<<endl;
			cout<<"\n\t- Monto total de productos: $"<<monto_final<<" USD. -"<<endl;// Imprime monto total de productos dentro de inventario
			cout<<"\t----------------------------------------------"<<endl;
			lectura>>clave;// Fin lectura adelantada
			i++;// Contador de productos
		}
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"\n Presione ENTER para volver al menu...";
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario trimestral productos
/******************************************
  INGRESAR DATOS USUARIO INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 19 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 19) Inicio de procesos de ingreso de datos inventario anual tipo: usuario
void inventario_speedlimit_usuario::agregar_inventario_anual(){
	ofstream escritura;
	escritura.open("datos_inventario_anual_usuario.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n Primera etapa: Datos de usuario."<<endl<<endl;
		cout<<"\n Ingrese clave unica de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese su 1"<<char(248)<<"er nombre: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_usuario);// Captura primer nombre de usuario
		cout<<"\n Ingrese su 1"<<char(248)<<"er apellido: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->apellido_usuario);// Captura primer apellido de usuario
		cout<<"\n Ingrese su codigo de empleado: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->codigo_empleado;// Captura codigo de empleado
		cout<<"\n Ingrese dia de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->dia;// Captura dia de creacion de inventario
		cout<<"\n Ingrese mes de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->mes;// Captura mes de creacion de inventario
		cout<<"\n Ingrese a"<<char(164)<<"o de creacion de inventario: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->a_o;// Captura año de creacion de inventario
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
// Fin de procesos de ingreso de datos inventario anual tipo: usuario
/******************************************
  INGRESAR PRODUCTOS INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 20 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 20) Inicio de procesos para ingreso de datos inventario trimestral tipo: inventario
void inventario_speedlimit::agregar_inventario_anual(){
	ofstream escritura;
	escritura.open("datos_inventario_anual_productos.txt",ios::out|ios::app);
	if(escritura.is_open()){
		cout<<"\n\n Segunda etapa: Datos de productos."<<endl<<endl;
		cout<<"\n Ingrese la clave unica del producto para manejo de inventario: ";
		cin>>clave;
		cout<<"\n Ingrese nombre de producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->nombre_de_producto);// Captura nombre de producto
		cout<<"\n Ingrese el modelo del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->modelo_de_producto);// Captura modelo de producto
		cout<<"\n Ingrese la marca del producto: ";
		fflush(stdin);// Limpia buffer de teclado
		gets(this->marca_producto);// Captura marca de producto
		cout<<"\n Ingrese precio unitario de producto: $";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->precio_de_producto;// Captura precio de producto
		cout<<"\n Ingrese cantidad de productos en existencias en lote: ";
		fflush(stdin);// Limpia buffer de teclado
		cin>>this->existencias_en_lote;
		cout<<endl;
		cout<<" Agregando informe de inventario ";
		for(int b_e=0;b_e<6;b_e++){
			Sleep(550);
			cout<<" . ";
		}
		escritura<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
		cout<<"\n\n Informe agregado con exito!!!\n\n Presione ENTER para continuar..."<<endl;
		getch();
	}else{
		cout<<"\n Lo sentimos, el archivo no se pudo abrir o no se pudo crear..."<<endl;
	}
	escritura.close();
}
// Fin de procesos para ingreso de datos inventario anual
/******************************************
  RECUPERAR INFORME INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 21 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 21) Inicio recuperacion de datos inventario anual empleados
void inventario_speedlimit_usuario::recuperar_datos_usuario_inventario_anual(){
	ifstream lectura;
	lectura.open("datos_inventario_anual_usuario.txt",ios::out|ios::in);
	if(lectura.is_open()){
		cout<<"\n Archivo abierto con exito..."<<endl;
		cout<<"\n Informe completo de inventario anual."<<endl;
		cout<<"________________________________________________________________________________"<<endl;
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
			// Imprime datos al programa
			cout<<" Informe de Inventario Mensual: "<<endl<<endl;
			cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
			cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
			cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
			cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
			lectura>>clave;// Fin lectura adelantada
		}
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario anual empleados

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 22 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 22) Inicio recuperacion de datos inventario anual productos
void inventario_speedlimit::recuperar_datos_productos_inventario_anual(){
	ifstream lectura;
	lectura.open("datos_inventario_anual_productos.txt",ios::out|ios::in);
	if(lectura.is_open()){
		lectura>>clave;// Inicio lectura adelantada
		int i;// Variable i de conteo
		i=1;// Valor inicial 1 para conteo
		while(!lectura.eof()){
			// Recupera datos de archivo
			lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
			// Imprime datos al programa
			cout<<endl;
			cout<<"\t Datos de producto "<<i<<": "<<endl<<endl;
			cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
			cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
			cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
			cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
			cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
			cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
			double monto_final;
			monto_final=precio_de_producto*existencias_en_lote;
			cout<<"\t----------------------------------------------"<<endl;
			cout<<"\n\t- Monto total de productos: $"<<monto_final<<" USD. -"<<endl;// Imprime monto total de productos dentro de inventario
			cout<<"\t----------------------------------------------"<<endl;
			lectura>>clave;// Fin lectura adelantada
			i++;// Contador de productos
		}
		cout<<"________________________________________________________________________________"<<endl;
		cout<<"\n Presione ENTER para volver al menu...";
	}else{
		cout<<"\n Lo sentimos, no se pudo abrir el archivo..."<<endl;
	}
	lectura.close();
}
// Fin recuperacion de datos inventario anual productos
/******************************************
  MODIFICAR DATOS USUARIO INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 23 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 23) Inicio modificar inventario mensual tipo usuario
void inventario_speedlimit_usuario::modificar_inventario_mensual(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Usuario[50];// Primer nombre auxiliar a modificar
    	char auxApellido_Usuario[50];// Primer apellido auxiliar a modificar
    	int auxCodigo_Empleado;// Codigo de empleado auxiliar a modificar
    	int auxDia;// N dia auxiliar a modificar
    	int auxMes;// N mes auxiliar a modificar
    	int auxA_O;// N año auxiliar a modificar
		aux.open("auxiliar_inventario_mensual_usuarios.txt",ios::out);
    	lectura.open("datos_inventario_mensual_usuario.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar 1"<<char(248)<<"er nombre de empleado."<<endl;
		cout<<" B. Modificar 1"<<char(248)<<"er apellido de empleado."<<endl;
		cout<<" C. Modificar codigo de empleado."<<endl;
		cout<<" D. Modificar dia de creacion de inventario."<<endl;
		cout<<" E. Modificar mes de creacion de inventario."<<endl;
		cout<<" F. Modificar a"<<char(164)<<"o de creacion de inventario."<<endl;
		cout<<" G. Regresar."<<endl;
		cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos usuario inventario mensual
		switch(opcion){
			// Modificar 1er nombre de empleado
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er nombre de empleado: ";
						cin>>auxNombre_Usuario;// Captura nuevo primer nombre de empleado
						aux<<clave<<" "<<auxNombre_Usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");
			break;
			// Modificar 1er apellido de empleado
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er apellido de empleado: ";
						cin>>auxApellido_Usuario;// Captura nuevo primer apellido de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<auxApellido_Usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");	
			break;
			//Modifica codigo de empleado
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo codigo de empleado: ";
						cin>>auxCodigo_Empleado;// Captura nuevo codigo de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<auxCodigo_Empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");		
			break;
			// Modifica dia de creacion de inventario
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el dia de creacion del inventario: ";
						cin>>auxDia;// Captura nuevo dia de creacion de inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<auxDia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");
			break;
			// Modifica mes de creacion del inventario
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo mes de creacion del inventario: ";
						cin>>auxMes;// Captura nuevo mes de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<auxMes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");	
			break;
			// Modifica año de creacion del inventario
			case 'f':case 'F':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo a"<<char(164)<<"o de creacion del inventario: ";
						cin>>auxA_O;// Captura nuevo año de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<auxA_O<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");	
			break;
			// Retorno a menu
			case 'g':case 'G':
				salir_menu=true;
		}// Fin switch case modificacion de datos usuario inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario mensual tipo usuario
/******************************************
  MODIFICAR DATOS PRODUCTOS INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 24 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 24) Inicio modificar inventario mensual tipo productos
void inventario_speedlimit::modificar_inventario_mensual_productos(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Producto[100];// Nombre de producto auxiliar a modificar
    	char auxModelo_Producto[100];// Modelo de producto auxiliar a modificar
    	char auxMarca_Producto[100];// Marca de producto auxiliar a modificar
    	double auxPrecio_Producto;// N precio de producto auxiliar a modificar
    	int auxExistencias_Producto;// N cantidad de productos auxiliar a modificar
    	aux.open("auxiliar_inventario_mensual_productos.txt",ios::out);
    	lectura.open("datos_inventario_mensual_productos.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar nombre de producto."<<endl;
		cout<<" B. Modificar modelo de producto."<<endl;
		cout<<" C. Modificar marca de producto."<<endl;
		cout<<" D. Modificar precio unitario de producto."<<endl;
		cout<<" E. Modificar cantidad de existencias en lote de producto."<<endl;
		cout<<" F. Regresar."<<endl;cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos productos inventario mensual
		switch(opcion){
			// Modificar nombre de producto
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo nombre del producto: ";
						cin>>auxNombre_Producto;// Captura nuevo nombre de producto
						aux<<clave<<" "<<auxNombre_Producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");
			break;
			// Modificar modelo de producto
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo modelo del producto: ";
						cin>>auxModelo_Producto;// Captura nuevo modelo de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<auxModelo_Producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");	
			break;
			// Modifica marca de producto
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva marca del producto: ";
						cin>>auxMarca_Producto;// Captura nueva marca de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<auxMarca_Producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");	
			break;
			// Modifica precio unitario de producto
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo precio unitario del producto: $";
						cin>>auxPrecio_Producto;// Captura nuevo precio unitario de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<auxPrecio_Producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");	
			break;
			// Modifica N cantidad de productos en lote
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva cantidad de productos en el lote: ";
						cin>>auxExistencias_Producto;// Captura N nueva cantidad de existencias de producto en lote
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<auxExistencias_Producto<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");	
			break;
			// Retorno a menu
			case 'f':case 'F':
				salir_menu=true;
		}// Fin switch case modificacion de datos productos inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario mensual tipo productos
/******************************************
  MODIFICAR DATOS USUARIO INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 25 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 25) Inicio modificar inventario trimestral tipo usuario
void inventario_speedlimit_usuario::modificar_inventario_trimestral(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Usuario[50];// Primer nombre auxiliar a modificar
    	char auxApellido_Usuario[50];// Primer apellido auxiliar a modificar
    	int auxCodigo_Empleado;// Codigo de empleado auxiliar a modificar
    	int auxDia;// N dia auxiliar a modificar
    	int auxMes;// N mes auxiliar a modificar
    	int auxA_O;// N año auxiliar a modificar
		aux.open("auxiliar_inventario_trimestral_usuarios.txt",ios::out);
    	lectura.open("datos_inventario_trimestral_usuario.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar 1"<<char(248)<<"er nombre de empleado."<<endl;
		cout<<" B. Modificar 1"<<char(248)<<"er apellido de empleado."<<endl;
		cout<<" C. Modificar codigo de empleado."<<endl;
		cout<<" D. Modificar dia de creacion de inventario."<<endl;
		cout<<" E. Modificar mes de creacion de inventario."<<endl;
		cout<<" F. Modificar a"<<char(164)<<"o de creacion de inventario."<<endl;
		cout<<" G. Regresar."<<endl;
		cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos usuario inventario mensual
		switch(opcion){
			// Modificar 1er nombre de empleado
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er nombre de empleado: ";
						cin>>auxNombre_Usuario;// Captura nuevo primer nombre de empleado
						aux<<clave<<" "<<auxNombre_Usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");
			break;
			// Modificar 1er apellido de empleado
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er apellido de empleado: ";
						cin>>auxApellido_Usuario;// Captura nuevo primer apellido de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<auxApellido_Usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");
			break;
			//Modifica codigo de empleado
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo codigo de empleado: ";
						cin>>auxCodigo_Empleado;// Captura nuevo codigo de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<auxCodigo_Empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");		
			break;
			// Modifica dia de creacion de inventario
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el dia de creacion del inventario: ";
						cin>>auxDia;// Captura nuevo dia de creacion de inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<auxDia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");
			break;
			// Modifica mes de creacion del inventario
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo mes de creacion del inventario: ";
						cin>>auxMes;// Captura nuevo mes de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<auxMes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");	
			break;
			// Modifica año de creacion del inventario
			case 'f':case 'F':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo a"<<char(164)<<"o de creacion del inventario: ";
						cin>>auxA_O;// Captura nuevo año de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<auxA_O<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");	
			break;
			// Retorno a menu
			case 'g':case 'G':
				salir_menu=true;
		}// Fin switch case modificacion de datos usuario inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario trimestral tipo usuario
/******************************************
  MODIFICAR DATOS PRODUCTOS INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 26 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 26) Inicio modificar inventario trimestral tipo productos
void inventario_speedlimit::modificar_inventario_trimestral_productos(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Producto[100];// Nombre de producto auxiliar a modificar
    	char auxModelo_Producto[100];// Modelo de producto auxiliar a modificar
    	char auxMarca_Producto[100];// Marca de producto auxiliar a modificar
    	double auxPrecio_Producto;// N precio de producto auxiliar a modificar
    	int auxExistencias_Producto;// N cantidad de productos auxiliar a modificar
    	aux.open("auxiliar_inventario_trimestral_productos.txt",ios::out);
    	lectura.open("datos_inventario_trimestral_productos.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar nombre de producto."<<endl;
		cout<<" B. Modificar modelo de producto."<<endl;
		cout<<" C. Modificar marca de producto."<<endl;
		cout<<" D. Modificar precio unitario de producto."<<endl;
		cout<<" E. Modificar cantidad de existencias en lote de producto."<<endl;
		cout<<" F. Regresar."<<endl;cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos productos inventario mensual
		switch(opcion){
			// Modificar nombre de producto
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo nombre del producto: ";
						cin>>auxNombre_Producto;// Captura nuevo nombre de producto
						aux<<clave<<" "<<auxNombre_Producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");
			break;
			// Modificar modelo de producto
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo modelo del producto: ";
						cin>>auxModelo_Producto;// Captura nuevo modelo de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<auxModelo_Producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");	
			break;
			// Modifica marca de producto
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva marca del producto: ";
						cin>>auxMarca_Producto;// Captura nueva marca de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<auxMarca_Producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");	
			break;
			// Modifica precio unitario de producto
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo precio unitario del producto: $";
						cin>>auxPrecio_Producto;// Captura nuevo precio unitario de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<auxPrecio_Producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");	
			break;
			// Modifica N cantidad de productos en lote
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva cantidad de productos en el lote: ";
						cin>>auxExistencias_Producto;// Captura N nueva cantidad de existencias de producto en lote
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<auxExistencias_Producto<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");	
			break;
			// Retorno a menu
			case 'f':case 'F':
				salir_menu=true;
		}// Fin switch case modificacion de datos productos inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario trimestral tipo productos
/******************************************
  MODIFICAR DATOS USUARIO INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 27 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 27) Inicio modificar inventario anual tipo usuario
void inventario_speedlimit_usuario::modificar_inventario_anual(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Usuario[50];// Primer nombre auxiliar a modificar
    	char auxApellido_Usuario[50];// Primer apellido auxiliar a modificar
    	int auxCodigo_Empleado;// Codigo de empleado auxiliar a modificar
    	int auxDia;// N dia auxiliar a modificar
    	int auxMes;// N mes auxiliar a modificar
    	int auxA_O;// N año auxiliar a modificar
		aux.open("auxiliar_inventario_anual_usuarios.txt",ios::out);
    	lectura.open("datos_inventario_anual_usuario.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar 1"<<char(248)<<"er nombre de empleado."<<endl;
		cout<<" B. Modificar 1"<<char(248)<<"er apellido de empleado."<<endl;
		cout<<" C. Modificar codigo de empleado."<<endl;
		cout<<" D. Modificar dia de creacion de inventario."<<endl;
		cout<<" E. Modificar mes de creacion de inventario."<<endl;
		cout<<" F. Modificar a"<<char(164)<<"o de creacion de inventario."<<endl;
		cout<<" G. Regresar."<<endl;
		cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos usuario inventario mensual
		switch(opcion){
			// Modificar 1er nombre de empleado
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er nombre de empleado: ";
						cin>>auxNombre_Usuario;// Captura nuevo primer nombre de empleado
						aux<<clave<<" "<<auxNombre_Usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");
			break;
			// Modificar 1er apellido de empleado
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo 1"<<char(248)<<"er apellido de empleado: ";
						cin>>auxApellido_Usuario;// Captura nuevo primer apellido de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<auxApellido_Usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");
			break;
			//Modifica codigo de empleado
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo codigo de empleado: ";
						cin>>auxCodigo_Empleado;// Captura nuevo codigo de empleado
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<auxCodigo_Empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");	
			break;
			// Modifica dia de creacion de inventario
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el dia de creacion del inventario: ";
						cin>>auxDia;// Captura nuevo dia de creacion de inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<auxDia<<" "<<mes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");
			break;
			// Modifica mes de creacion del inventario
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo mes de creacion del inventario: ";
						cin>>auxMes;// Captura nuevo mes de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<auxMes<<" "<<a_o<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");
			break;
			// Modifica año de creacion del inventario
			case 'f':case 'F':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos usuario inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de usuario -> inventario: "<<clave<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er nombre de empleado: "<<nombre_usuario<<"."<<endl;
						cout<<"\t 1"<<char(248)<<"er apellido de empleado: "<<apellido_usuario<<"."<<endl;
						cout<<"\t Codigo de empleado: "<<codigo_empleado<<"."<<endl;
						cout<<"\t Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<a_o<<"."<<endl;
						cout<<"\n Ingresa el nuevo a"<<char(164)<<"o de creacion del inventario: ";
						cin>>auxA_O;// Captura nuevo año de creacion del inventario
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<auxA_O<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");	
			break;
			// Retorno a menu
			case 'g':case 'G':
				salir_menu=true;
		}// Fin switch case modificacion de datos usuario inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario anual tipo usuario
/******************************************
  MODIFICAR DATOS PRODUCTOS INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 28 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 28) Inicio modificar inventario anual tipo productos
void inventario_speedlimit::modificar_inventario_anual_productos(){
	bool salir_menu=false;
	char opcion;
	bool encontrado=false;
	do{
		ofstream aux;// Archivo auxiliar
    	ifstream lectura;// Lectura de productos
    	encontrado=false;
    	int auxClave=0;// Clave auxiliar
    	char auxNombre_Producto[100];// Nombre de producto auxiliar a modificar
    	char auxModelo_Producto[100];// Modelo de producto auxiliar a modificar
    	char auxMarca_Producto[100];// Marca de producto auxiliar a modificar
    	double auxPrecio_Producto;// N precio de producto auxiliar a modificar
    	int auxExistencias_Producto;// N cantidad de productos auxiliar a modificar
    	aux.open("auxiliar_inventario_anual_productos.txt",ios::out);
    	lectura.open("datos_inventario_anual_productos.txt",ios::in);
    	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n Por favor seleccione una opcion: "<<endl<<endl;
		cout<<" A. Modificar nombre de producto."<<endl;
		cout<<" B. Modificar modelo de producto."<<endl;
		cout<<" C. Modificar marca de producto."<<endl;
		cout<<" D. Modificar precio unitario de producto."<<endl;
		cout<<" E. Modificar cantidad de existencias en lote de producto."<<endl;
		cout<<" F. Regresar."<<endl;cout<<"\n\t\t\t Su Opcion: ";
		cin>>opcion;
		// Inicio switch case modificacion de datos productos inventario mensual
		switch(opcion){
			// Modificar nombre de producto
			case 'a':case 'A':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo nombre del producto: ";
						cin>>auxNombre_Producto;// Captura nuevo nombre de producto
						aux<<clave<<" "<<auxNombre_Producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");
			break;
			// Modificar modelo de producto
			case 'b':case 'B':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo modelo del producto: ";
						cin>>auxModelo_Producto;// Captura nuevo modelo de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<auxModelo_Producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");
			break;
			// Modifica marca de producto
			case 'c':case 'C':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva marca del producto: ";
						cin>>auxMarca_Producto;// Captura nueva marca de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<auxMarca_Producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");	
			break;
			// Modifica precio unitario de producto
			case 'd':case 'D':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa el nuevo precio unitario del producto: $";
						cin>>auxPrecio_Producto;// Captura nuevo precio unitario de producto
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<auxPrecio_Producto<<" "<<existencias_en_lote<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");	
			break;
			// Modifica N cantidad de productos en lote
			case 'e':case 'E':
				if(aux.is_open() && lectura.is_open()){
        		cout<<"\n Ingresa la clave unica del producto que deseas modificar: ";
        		cin>>auxClave;// Captura clave auxiliar de inventario mensual datos usuario
        		lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        		int i;// Variable i de conteo de datos
        		i=1;// i = 1 contador inicial
        		while(!lectura.eof()){// Inicio ciclo while que recorre lista de datos productos inventario mensual
        			system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
					if(auxClave==clave){// Si encuentra clave, entonces mostrar....
						encontrado=true;
						cout<<"\t Clave unica de producto para manejo de inventario: "<<clave<<"."<<endl;
						cout<<"\t Nombre de producto: "<<nombre_de_producto<<"."<<endl;
						cout<<"\t Modelo de producto: "<<modelo_de_producto<<"."<<endl;
						cout<<"\t Marca de producto: "<<marca_producto<<"."<<endl;
						cout<<"\t Precio unitario de producto: $"<<precio_de_producto<<" USD."<<endl;
						cout<<"\t Existencias en lote: "<<existencias_en_lote<<" unidades."<<endl<<endl;
						cout<<"\n Ingresa la nueva cantidad de productos en el lote: ";
						cin>>auxExistencias_Producto;// Captura N nueva cantidad de existencias de producto en lote
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<auxExistencias_Producto<<" "<<endl;
						cout<<"\n Modificando registro, espere un momento ";
						for(int b_e=0;b_e<7;b_e++){
                			Sleep(660);// Espera 0.60 segundos
                			cout<<".";
                		}
                		cout<<"\n\n Registro modificado con exito!!!"<<endl;
                		cout<<"\n Presione ENTER para volver al menu...";
                		getch();
					}else{
						aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
					}
					lectura>>clave;	
				}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");
			break;
			// Retorno a menu
			case 'f':case 'F':
				salir_menu=true;
		}// Fin switch case modificacion de datos productos inventario mensual
	}while(!salir_menu);
}
// Fin modificar inventario anual tipo productos
/******************************************
  ELIMINAR DATOS USUARIO INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 29 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 29) Inicio eliminar inventario mensual tipo usuario
void inventario_speedlimit_usuario::eliminar_inventario_mensual(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_mensual_usuarios.txt",ios::out);
    lectura.open("datos_inventario_mensual_usuario.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t  Eliminar Datos Inventario Mensual (Empleado)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_usuario.txt");
    			rename("auxiliar_inventario_mensual_usuarios.txt","datos_inventario_mensual_usuario.txt");	
}
// Fin eliminar inventario mensual tipo usuario
/******************************************
  ELIMINAR DATOS PRODUCTOS INVENTARIO MENSUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 30 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 30) Inicio eliminar inventario mensual tipo productos
void inventario_speedlimit::eliminar_inventario_mensual_productos(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_mensual_productos.txt",ios::out);
    lectura.open("datos_inventario_mensual_productos.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t Eliminar Datos Inventario Mensual (Productos)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_mensual_productos.txt");
    			rename("auxiliar_inventario_mensual_productos.txt","datos_inventario_mensual_productos.txt");	
}
// Fin eliminar inventario mensual tipo productos
/******************************************
  ELIMINAR DATOS USUARIO INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 31 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 31) Inicio eliminar inventario trimestral tipo usuario
void inventario_speedlimit_usuario::eliminar_inventario_trimestral(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_trimestral_usuarios.txt",ios::out);
    lectura.open("datos_inventario_trimestral_usuario.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t   Eliminar Datos Inventario Trimestral (Empleado)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_usuario.txt");
    			rename("auxiliar_inventario_trimestral_usuarios.txt","datos_inventario_trimestral_usuario.txt");	
}
// Fin eliminar inventario trimestral tipo usuario
/******************************************
  ELIMINAR DATOS PRODUCTOS INVENTARIO TRIMESTRAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 32 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 32) Inicio eliminar inventario trimestral tipo productos
void inventario_speedlimit::eliminar_inventario_trimestral_productos(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_trimestral_productos.txt",ios::out);
    lectura.open("datos_inventario_trimestral_productos.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t   Eliminar Datos Inventario Trimestral (Productos)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_trimestral_productos.txt");
    			rename("auxiliar_inventario_trimestral_productos.txt","datos_inventario_trimestral_productos.txt");
}
// Fin eliminar inventario trimestral tipo productos
/******************************************
  ELIMINAR DATOS USUARIO INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 33 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 33) Inicio eliminar inventario anual tipo usuario
void inventario_speedlimit_usuario::eliminar_inventario_anual(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_anual_usuarios.txt",ios::out);
    lectura.open("datos_inventario_anual_usuario.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t   Eliminar Datos Inventario Anual (Empleado)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_usuario>>apellido_usuario>>codigo_empleado>>dia>>mes>>a_o;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_usuario<<" "<<apellido_usuario<<" "<<codigo_empleado<<" "<<dia<<" "<<mes<<" "<<a_o<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_usuario.txt");
    			rename("auxiliar_inventario_anual_usuarios.txt","datos_inventario_anual_usuario.txt");
}
// Fin eliminar inventario anual tipo usuario
/******************************************
  ELIMINAR DATOS PRODUCTOS INVENTARIO ANUAL
*******************************************/

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 34 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 34) Inicio eliminar inventario anual tipo productos
void inventario_speedlimit::eliminar_inventario_anual_productos(){
	bool encontrado=false;
	ofstream aux;// Archivo auxiliar
    ifstream lectura;// Lectura de productos
    encontrado=false;
    int auxClave=0;// Clave auxiliar
    aux.open("auxiliar_inventario_anual_productos.txt",ios::out);
    lectura.open("datos_inventario_anual_productos.txt",ios::in);
    system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t   Eliminar Datos Inventario Anual (Productos)"<<endl<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	if(aux.is_open() && lectura.is_open()){
    	cout<<"\n Ingresa la clave unica del producto que deseas eliminar: ";
        cin>>auxClave;// Captura clave auxiliar de producto
        lectura>>clave;// Se recorre listado de productos en el archivo txt en busca de la clave ingresada por el usuario
        int i;// Variable i de conteo de productos
        i=1;// i = 1 contador inicial
        while(!lectura.eof()){// Inicio ciclo while que recorre lista de productos
        	lectura>>nombre_de_producto>>modelo_de_producto>>marca_producto>>precio_de_producto>>existencias_en_lote;
        	if(auxClave==clave){// Si encuentra clave, entonces mostrar....
        		encontrado=true;
                cout<<"\n Eliminando registro, espere un momento ";
				for(int b_e=0;b_e<7;b_e++){
                	Sleep(660);// Espera 0.60 segundos
                	cout<<".";
                }
                cout<<"\n\n Inventario eliminado con exito!!!"<<endl;
                cout<<"\n Presione ENTER para volver al menu...";
            	}else{
                	aux<<clave<<" "<<nombre_de_producto<<" "<<modelo_de_producto<<" "<<marca_producto<<" "<<precio_de_producto<<" "<<existencias_en_lote<<" "<<endl;
            	}
            		lectura>>clave;
        		}
				}else{
        			cout<<"\n Lo sentimos, el archivo no se pudo abrir o aun no ha sido creado..."<<endl;
    			}
    			if(encontrado==false){
        			cout<<"\n No se encontro ningun registro con clave "<<auxClave<<endl;
        			getch();
    			}
    			aux.close();
    			lectura.close();
    			remove("datos_inventario_anual_productos.txt");
    			rename("auxiliar_inventario_anual_productos.txt","datos_inventario_anual_productos.txt");
}
// Fin eliminar inventario anual tipo productos

/*
	<<<<<<<<<<<<<<<<<<<<<<<<<<<
	<<<< Literal Numero 35 >>>>
	>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// 35) Inicio calcular precio inventario speedlimit
void inventario_speedlimit::calcular_precio_inventario(){
	subtotal_inventario=precio_de_producto*existencias_en_lote;
}
// Fin calcular precio inventario speedlimit

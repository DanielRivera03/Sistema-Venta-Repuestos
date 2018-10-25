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
/** Inicios Metodos (Prototipos) **/
void administradores(void); // Usuario administrador
void login(void); // Login de usuarios
void sistema_facturacion_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Agrega nuevos clientes al sistema para general factura final
void sistema_facturacion_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Sistema de facturacion de productos final
void sistema_cotizacion_clientes(int cantidad, sistema_cotizacion sistema_cotizacion_cliente_final[]);// Sistema de cotizacion clientes
void factura_final_datos_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Vista de datos del cliente facturados en pagina web
void factura_final_datos_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Vista de datos de productos facturados en pagina web
void cotizacion_final_sistema_clientes(int cantidad, sistema_cotizacion sistema_cotizacion_cliente_final[]);// Vista de cotizacion final clientes (cotizaciones desde usuario clientes)
void hora_sistema(void);// Muestra hora del sistema en el programa
/** Fin Metodos (Prototipos) **/

/********************************/
/* USUARIO 1: ADMINISTRADORES  */
/*******************************/
void administradores(void){
// ** VARIABLES ** //
system("color C");// Cambio de color texto (consola-programa)
string usuario, password; // Autenticacion de usuario
int i; // Contador de intentos
int b_e; // Simulacion de Barra de Espera
int salir; // Salir del programa
int retorno_principal; // Retorno de menu principal (login) con opcion no valida
bool retorno_menu=false; // Controla retorno a menu principal de programa
int sub_menu_admin; // Opcion menu de opciones login Admin
int opcion_procesos_productos; // Opcion a realizar dentro de campo modificar / eliminar productos
int opcion_procesos_inventario_modificar; // Opcion a realizar dentro de campo modificar inventario
int opcion_procesos_inventario_eliminar; // Opcion a realizar dentro de campo eliminar inventario
productos_speedlimit lista_productos[100]; // Arreglo general para productos_speedlimit
int num_nuevos_productos; // N numero de productos a registrar
int contador=0; // Aumento en 1 por cada producto registrado
int codigo_producto; // Codigo de producto a modificar - eliminar
inventario_speedlimit lista_inventario_mensual[100]; // Arreglo general para inventarios_speedlimit tipo: productos MENSUAL
inventario_speedlimit_usuario lista_usuarios_mensual[100]; // Arreglo general para inventario_speedlimit_usuario tipo: usuario MENSUAL
inventario_speedlimit lista_inventario_trimestral[100]; // Arreglo general para inventarios_speedlimit tipo: productos TRIMESTRAL
inventario_speedlimit_usuario lista_usuarios_trimestral[100]; // Arreglo general para inventario_speedlimit_usuario tipo: usuario TRIMESTRAL
inventario_speedlimit lista_inventario_anual[100]; // Arreglo general para inventarios_speedlimit tipo: productos ANUAL
inventario_speedlimit_usuario lista_usuarios_anual[100]; // Arreglo general para inventario_speedlimit_usuario tipo: usuario ANUAL
int contador_inventario_usuario_mensual=0; // Aumento en 1 por cada usuario ingresado al inventario
int contador_inventario_usuario_trimestral=0; // Aumento en 1 por cada usuario ingresado al inventario
int contador_inventario_usuario_anual=0; // Aumento en 1 por cada usuario ingresado al inventario
int contador_inventario_mensual=0; // Aumento en 1 por cada producto ingresado al inventario
int contador_inventario_trimestral=0; // Aumento en 1 por cada producto ingresado al inventario
int contador_inventario_anual=0; // Aumento en 1 por cada producto ingresado al inventario
int num_productos_inventario; // N cantidad de productos ha agregar en inventario
int codigo_inventario_usuario;// Codigo de inventario a modificar (Tipo Usuario)
int codigo_inventario_productos;// Codigo de inventario a modificar (Tipo Productos)
int tipo_inventario; // Tipo de inventario a crear
int vista_inventario; // Tipo de inventario a ver
int num_productos_compra; // N numero de productos a procesar en factura final
facturacion_speedlimit_datos_cliente listado_de_clientes_facturacion[200];// Arreglo general para sistema de facturacion final datos CLIENTES
int contador_clientes_facturacion=0;// Aumento en 1 por cada cliente ingresado al sistema para facturacion final
facturacion_speedlimit_productos listado_de_productos_facturacion[200];// Arreglo general para sistema de facturacion final datos PRODUCTOS
int contador_productos_facturacion=0;// Aumento en 1 por cada producto ingresado al sistema de facturacion final
int tipo_vista_factura_final;// Tipo de vista de factura final
int codigo_eliminacion_cliente_facturacion;// N codigo de facturacion tipo cliente a eliminar dentro de factura
int codigo_eliminacion_producto_facturacion;// N codigo de facturacion tipo productos a eliminar dentro de factura
sistema_cotizacion lista_cotizacion[500];// Arreglo general sistema de cotizacion
// Inicio ciclo for i
for(i=1;i<4;i++){
	system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
				cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
				cout<<"\t\t\tLogin Administradores SpeedLimit"<<endl<<endl;
				hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
		cout<<"--------------------------------------------------------------------------------";
 		cout<<" Por favor ingrese su informacion personal de usuario"<<endl<<endl;
 		cout<<" Ingrese su nombre de usuario: ";
 		cin>>usuario;// Captura nombre se usuario
 		// Inicio validacion de usuarios
 		if(usuario=="admin" || usuario=="Admin"){
 			cout<<"\n Nombre de usuario correcto.\n\n Por favor ingrese su contrase"<<char(164)<<"a: ";
 			cin>>password;// Captura clave de acceso
 		if(password=="admin.speedlimit"){
 			cout<<"\n Contrase"<<char(164)<<"a correcta."<<endl;
 			cout<<"\n\t\t\t\tIniciando Sesion";
 		// Inicio Simulacion De Barra De Espera
 		for(b_e=0;b_e<5;b_e++){
 			Sleep(450); // Espera de 0.45 Segundos
 			cout<<".";
 		}
 		// Fin Simulacion De Barra De Espera
 		// Menu y procesos para Administrador
 		do{
 			system("cls"); // Limpia proceso anterior y muestra nuevos procesos nivel admin
 			cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
					cout<<"\t\t\t\tBienvenido/a "<<usuario<<"."<<endl<<endl;
			cout<<"--------------------------------------------------------------------------------";
			// Inicio de sub-menu para procesos usuario nivel administrador
			cout<<"\n Estimado/a "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
			cout<<" 1. Agregar Productos."<<endl;
			cout<<" 2. Ver Lista De Productos."<<endl;
			cout<<" 3. Modificar / Eliminar Productos."<<endl;
			cout<<" 4. Generar Factura Final."<<endl;
			cout<<" 5. Ver Factura Final."<<endl;
			cout<<" 6. Agregar Informe Contable Del Inventario"<<endl;
			cout<<" 7. Ver Inventario Contable."<<endl;
			cout<<" 8. Modificar Inventario Contable."<<endl;
			cout<<" 9. Eliminar Inventario Contable."<<endl;
			cout<<" 10. Cerrar Sesion."<<endl;
			cout<<"\n\t\t\t\tSu opcion: ";
			cin>>sub_menu_admin;// Captura opcion de menu elegida por admin
			// Inicio de switch case - procesos para usuario nivel administrador
			switch(sub_menu_admin){
			// Inicio Agregar Productos
			case 1:
				system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
							cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t\t   Agregar Productos Al Sistema"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\n Cuantos productos desea agregar: ";
				cin>>num_nuevos_productos; // Captura N cantidad de productos a registrar
				for(i=0;i<num_nuevos_productos;i++){
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t\t\t Producto "<<i+1<<" de "<<num_nuevos_productos<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
					lista_productos[contador].agregar_productos(); // Invoca funcion para registrar nuevos productos
					contador++; // Aumento en 1 por cada producto ingresado
				}// Fin for i agregar productos al sistema
			break;
			// Fin Agregar Productos
						/**/
			// Inicio Ver Lista De Productos
			case 2:
				system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
							cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t      Ver Lista De Productos"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				// Ver lista guardada
				lista_productos[contador].recuperar();// Invoca funcion recuperar productos ingresados al archivo productos.txt
				break;
				// Fin Ver Lista De Productos	
							/**/				
				// Inicio Modificar / Eliminar Productos
			case 3:
				do{
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t   Modificar / Eliminar Productos"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					cout<<" Estimado "<<usuario<<", que accion desea realizar?"<<endl<<endl;
					cout<<" 1. Modificar Productos."<<endl;
					cout<<" 2. Eliminar Productos."<<endl;
					cout<<" 3. Regresar Al Menu Principal."<<endl;
					cout<<"\n\t\t\t\tSu opcion: ";
					cin>>opcion_procesos_productos;
					// Inicio de switch procesos modificar / eliminar productos
					switch(opcion_procesos_productos){
						// Modificar productos
						case 1:
							lista_productos[contador].modificar_productos();// Invoca funcion modificar productos
						break;
						// Eliminar productos
						case 2:
							lista_productos[contador].eliminar_productos();// Invoca funcion eliminar productos
						break;	
						// Retorno de menu	
						case 3:
							retorno_menu=true;// Retorna a menu principal
							cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
						break;
						// Validacion de menu	
						default:
							cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
							getch();		
				}// Fin de switch procesos modificar / eliminar productos
			}while(!retorno_menu);
			break;
			// Fin Modificar / Eliminar Productos
						/**/
			// Inicio Generar Factura Final	
			case 4:
				system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t     Generar Factura Final"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\n Por favor digite el numero de productos a procesar en factura final: ";
				cin>>num_productos_compra;// Captura N productos a procesar en factura final
				listado_de_clientes_facturacion[contador_clientes_facturacion].agregar_nuevo_cliente();// Invoca funcion agregar nuevo cliente, previo a facturacion de productos
				contador_clientes_facturacion++;
				for(i=0;i<num_productos_compra;i++){
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t\t Facturando producto "<<i+1<<" de "<<num_productos_compra<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------"<<endl;
					listado_de_productos_facturacion[contador_productos_facturacion].generar_nueva_factura_productos();// Invoca funcion agregar productos a factura final
					listado_de_productos_facturacion[contador_productos_facturacion].calcular();
					contador_productos_facturacion++;
				}// Fin for generando nueva factura
			break;
			// Fin Generar Factura Final
						/**/
			// Inicio Ver Factura Final
			case 5:
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t       Visualizar Factura Final"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					cout<<"\n "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
					cout<<" 1. Ver Factura Final en el Sistema."<<endl;
					cout<<" 2. Ver Clientes Facturados en Pagina Web."<<endl;
					cout<<" 3. Ver Productos Facturados en Pagina Web."<<endl;
					cout<<" 4. Eliminar datos factura final datos clientes."<<endl;
					cout<<" 5. Eliminar datos factura final datos productos"<<endl;
					cout<<" 6. Regresar Al Menu Principal."<<endl;
					cout<<"\n\t\t\t\tSu opcion: ";
					cin>>tipo_vista_factura_final;// N vista a visualizar factura final
					// Inicio switch para tipo vista de factura final
					switch(tipo_vista_factura_final){
						// Ver en el sistema
						case 1:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t  Visualizar Factura Final"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							sistema_facturacion_clientes(contador_clientes_facturacion,listado_de_clientes_facturacion);
							cout<<" ---------------------------------------------------------"<<endl;
							sistema_facturacion_productos(contador_productos_facturacion,listado_de_productos_facturacion);
							
						break;
						// Motrar datos de cliente en sitio web
						case 2:
							factura_final_datos_clientes(contador_clientes_facturacion,listado_de_clientes_facturacion);// Muestra datos del cliente en pagina web
						break;
						// Mostrar productos facturados en sitio web
						case 3:
							factura_final_datos_productos(contador_productos_facturacion,listado_de_productos_facturacion);// Muestra productos facturados en pagina web
						break;	
						// Eliminar N factura final datos cliente
						case 4:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t Eliminar Factura Final Datos Cliente"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Por favor ingrese el codigo del cliente a eliminar: ";
							cin>>codigo_eliminacion_cliente_facturacion;// Captura codigo de cliente a eliminar
							if(codigo_eliminacion_cliente_facturacion>contador_clientes_facturacion){
								cout<<"\n Lo sentimos, no hay ningun producto cliente con ese codigo"<<endl;
								system("pause"); // Pausa en la ejecucion para mostrar mensaje
								continue; // Salta codigo y vuelve al menu
							}else{
								system("cls");
								cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
												cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t\t Eliminar Factura Final Datos Cliente"<<endl<<endl;
								cout<<"--------------------------------------------------------------------------------";
								listado_de_clientes_facturacion[contador_clientes_facturacion-1].eliminar_clientes_factura();// Invoca funcion eliminar cliente en facturacion final
								contador_clientes_facturacion--;// Decrementa contador y elimina datos dentro de esa posicion del arreglo	
							}
						break;
						// Eliminar N factura final datos productos
						case 5:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t Eliminar Factura Final Datos Productos"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Por favor ingrese el codigo del producto a eliminar: ";
							cin>>codigo_eliminacion_producto_facturacion;// Captura codigo de producto a eliminar
							if(codigo_eliminacion_producto_facturacion>contador_productos_facturacion){
								cout<<"\n Lo sentimos, no hay ningun producto registrado con ese codigo"<<endl;
								system("pause"); // Pausa en la ejecucion para mostrar mensaje
								continue; // Salta codigo y vuelve al menu
							}else{
								listado_de_productos_facturacion[contador_productos_facturacion-1].eliminar_productos_factura();
								contador_productos_facturacion--;
							}
						break;	
						// Retorno a menu principal
						case 6:
							retorno_menu=true;// Retorna a menu principal
							cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
						break;
						// Validacion de menu	
						default:
							cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
							getch();		
					}// Fin switch para tipo vista de factura final
			break;	
			// Fin Ver Factura Final
					/**/			
			// Inicio Agregar Informe Contable Del Inventario	
			case 6:
				do{
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t       Agregar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					cout<<" Estimado "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
					cout<<" 1. Crear Inventario Mensual."<<endl;
					cout<<" 2. Crear Inventario Trimestral."<<endl;
					cout<<" 3. Crear Inventario Anual."<<endl;
					cout<<" 4. Regresar Al Menu Principal."<<endl;
					cout<<"\n\t\t\t\tSu opcion: ";
					cin>>tipo_inventario;// Captura tipo de inventario a crear
					// Inicio de switch tipo_inventario
					switch(tipo_inventario){
						// Crear inventario mensual
						case 1:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t  Crear Informe Contable de Inventario Mensual"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Cuantos productos desea agregar al inventario: ";
							cin>>num_productos_inventario;// Captura N productos de inventario ha agregar
							lista_usuarios_mensual[contador_inventario_mensual].agregar_inventario_mensual();
							contador_inventario_usuario_mensual++; // Aumento en 1 por cada usuario dentro de inventario registrado
							for(i=0;i<num_productos_inventario;i++){
								system("cls");
								cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
											cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t\t  Producto "<<i+1<<" de "<<num_productos_inventario<<"."<<endl<<endl;
								cout<<"--------------------------------------------------------------------------------";
								lista_inventario_mensual[contador_inventario_mensual].agregar_inventario_mensual(); // Invoca a funcion agregar nuevo inventario mensual
								lista_inventario_mensual[contador_inventario_mensual].calcular_precio_inventario();// Invoca a funcion calcular precio en inventario
								contador_inventario_mensual++; // Aumento en 1 por cada producto ingresado dentro del inventario
							} // Fin for i proceso de productos de inventario
						break;
						// Crear inventario trimestral
						case 2:	
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t Crear Informe Contable de Inventario Trimestral"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Cuantos productos desea agregar al inventario: ";
							cin>>num_productos_inventario;// Captura N productos de inventario ha agregar
							lista_usuarios_trimestral[contador_inventario_trimestral].agregar_inventario_trimestral();// Invoca a funcion agregar nuevo inventario trimestral
							contador_inventario_usuario_trimestral++; // Aumento en 1 por cada usuario dentro de inventario registrado
							for(i=0;i<num_productos_inventario;i++){
								system("cls");
								cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
											cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t\t  Producto "<<i+1<<" de "<<num_productos_inventario<<"."<<endl<<endl;
								cout<<"--------------------------------------------------------------------------------";
								lista_inventario_trimestral[contador_inventario_trimestral].agregar_inventario_trimestral(); // Invoca a funcion agregar nuevo inventario mensual
								lista_inventario_trimestral[contador_inventario_trimestral].calcular_precio_inventario();// Invoca a funcion calcular precio en inventario
								contador_inventario_trimestral++; // Aumento en 1 por cada producto ingresado dentro del inventario
							} // Fin for i proceso de productos de inventario
						break;
						// Crear inventario anual	
						case 3:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
												cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t   Crear Informe Contable de Inventario Anual"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Cuantos productos desea agregar al inventario: ";
							cin>>num_productos_inventario;
							lista_usuarios_anual[contador_inventario_anual].agregar_inventario_anual();// Invoca a funcion agregar nuevo inventario anual
							contador_inventario_usuario_anual++; // Aumento en 1 por cada usuario dentro de inventario registrado
							for(i=0;i<num_productos_inventario;i++){
								system("cls");
								cout<<"--------------------------------------------------------------------------------"<<endl;
											cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
												cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t\t\t  Producto "<<i+1<<" de "<<num_productos_inventario<<"."<<endl<<endl;
								cout<<"--------------------------------------------------------------------------------";
								lista_inventario_anual[contador_inventario_anual].agregar_inventario_anual(); // Invoca a funcion agregar nuevo inventario mensual
								lista_inventario_anual[contador_inventario_anual].calcular_precio_inventario();// Invoca a funcion calcular precio en inventario
								contador_inventario_anual++; // Aumento en 1 por cada producto ingresado dentro del inventario
							} // Fin for i proceso de productos de inventario
						break;
						// Retorno a menu
						case 4:
							retorno_menu=true;
							cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
						break;
						// Validacion de menu	
						default:
							cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
							getch();	
				}// Fin de switch tipo_inventario
			}while(!retorno_menu);	
			break;
			// Fin Agregar Informe Contable Del Inventario
						/**/
			// Inicio Ver Inventario Contable
			case 7:
			do{
				system("cls");
				cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t       Ver Informe Contable Del Inventario"<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				cout<<" Estimado "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
				cout<<" 1. Ver Inventario Mensual."<<endl;
				cout<<" 2. Ver Inventario Trimestral."<<endl;
				cout<<" 3. Ver Inventario Anual."<<endl;
				cout<<" 4. Regresar Al Menu Principal."<<endl;
				cout<<"\n\t\t\t\tSu opcion: ";
				cin>>vista_inventario;// Captura tipo de inventario a ver
				// Inicio switch para vista de inventario
				switch(vista_inventario){
					// Ver inventario mensual
					case 1:
						system("cls");
						cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
											cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t  Ver Lista de Productos Inventario Mensual"<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------";
						lista_usuarios_mensual[contador_inventario_mensual].recuperar_datos_usuario_inventario_mensual();
						lista_inventario_mensual[contador_inventario_mensual].recuperar_datos_productos_inventario_mensual();
						getch();// Detiene lectura de datos hasta que usuario presione cualquier tecla
					break;
					// Ver inventario trimestral	
					case 2:	
						system("cls");
						cout<<"--------------------------------------------------------------------------------"<<endl;
								cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t Ver Lista de Productos Inventario Trimestral"<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------";
						lista_usuarios_trimestral[contador_inventario_trimestral].recuperar_datos_usuario_inventario_trimestral();
						lista_inventario_trimestral[contador_inventario_trimestral].recuperar_datos_productos_inventario_trimestral();
						getch();// Detiene lectura de datos hasta que usuario presione cualquier tecla
					break;
					// Ver inventario anual	
					case 3:
						system("cls");
						cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t  Ver Lista de Productos Inventario Anual"<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------";
						lista_usuarios_anual[contador_inventario_anual].recuperar_datos_usuario_inventario_anual();
						lista_inventario_anual[contador_inventario_anual].recuperar_datos_productos_inventario_anual();
						getch();// Detiene lectura de datos hasta que usuario presione cualquier tecla
					break;
					// Retorno a menu
					case 4:
						retorno_menu=true;
						cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
					break;
					// Validacion de menu	
					default:
						cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
						getch();	
				}// Fin switch para vista de inventario
			}while(!retorno_menu);
			break;
			// Fin Ver Inventario Contable
						/**/
			// Inicio Modificar Inventario Contable
			case 8:
				do{
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							cout<<"\t\t     Modificar Informe Contable Del Inventario"<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					cout<<" Estimado "<<usuario<<", que accion desea realizar?"<<endl<<endl;
					cout<<" 1. Modificar Inventario Mensual (Datos de usuario)."<<endl;
					cout<<" 2. Modificar Inventario Mensual (Datos de productos)."<<endl;
					cout<<" 3. Modificar Inventario Trimestral (Datos de usuario)."<<endl;
					cout<<" 4. Modificar Inventario Trimestral (Datos de productos)."<<endl;
					cout<<" 5. Modificar Inventario Anual (Datos de usuario)."<<endl;
					cout<<" 6. Modificar Inventario Anual (Datos de productos)."<<endl;
					cout<<" 7. Regresar Al Menu Principal."<<endl;
					cout<<"\n\t\t\t\tSu opcion: ";
					cin>>opcion_procesos_inventario_modificar;// Captura proceso N a modificar dentro de inventario contable
					// Inicio switch procesos a modificar dentro de inventario contable
					switch(opcion_procesos_inventario_modificar){
						// Modificar inventario mensual (datos usuario)
						case 1:
							lista_usuarios_mensual[contador_inventario_mensual].modificar_inventario_mensual();// Invoca funcion modificar datos de empleado inventario mensual
						break;
						// Modificar inventario mensual (datos productos)	
						case 2:	
							lista_inventario_mensual[contador_inventario_mensual].modificar_inventario_mensual_productos();// Invoca a funcion modificar datos de productos inventario mensual
						break;
						// Modificar inventario trimestral (datos usuario)	
						case 3:	
							lista_usuarios_trimestral[contador_inventario_trimestral].modificar_inventario_trimestral();// Invoca funcion modificar datos de empleado inventario trimestral
						break;
						// Modificar inventario trimestral (datos productos)	
						case 4:
							lista_inventario_trimestral[contador_inventario_trimestral].modificar_inventario_trimestral_productos();// Invoca a funcion modificar datos de productos inventario trimestral
						break;
						// Modificar inventario anual (datos usuario)	
						case 5:
							lista_usuarios_anual[contador_inventario_anual].modificar_inventario_anual();// Invoca funcion modificar datos de empleado inventario anual
						break;
						// Modificar inventario anual (datos productos)	
						case 6:
							lista_inventario_anual[contador_inventario_anual].modificar_inventario_anual_productos();// Invoca a funcion modificar datos de productos inventario anual				
						break;
						// Retorno al menu principal	
						case 7:
							retorno_menu=true;// Retorna a menu principal
							cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
						break;
						// Validacion de menu		
						default:			
							cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
							getch();	
					}// Fin switch procesos a modificar dentro de inventario contable	
				}while(!retorno_menu);
				break;
				// Fin Modificar Inventario Contable	
								/**/
				// Inicio Eliminar Inventario Contable
				case 9:
					do{
						system("cls");
						cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t     Eliminar Informe Contable Del Inventario"<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------";
						cout<<" Estimado "<<usuario<<", que accion desea realizar?"<<endl<<endl;
						cout<<" 1. Eliminar Inventario Mensual (Datos de usuario)."<<endl;
						cout<<" 2. Eliminar Inventario Mensual (Datos de productos)."<<endl;
						cout<<" 3. Eliminar Inventario Trimestral (Datos de usuario)."<<endl;
						cout<<" 4. Eliminar Inventario Trimestral (Datos de productos)."<<endl;
						cout<<" 5. Eliminar Inventario Anual (Datos de usuario)."<<endl;
						cout<<" 6. Eliminar Inventario Anual (Datos de productos)."<<endl;
						cout<<" 7. Regresar Al Menu Principal."<<endl;
						cout<<"\n\t\t\t\tSu opcion: ";
						cin>>opcion_procesos_inventario_eliminar;// Captura proceso N a eliminar dentro de inventario contable
						// Inicio switch procesos a eliminar dentro de inventario contable
						switch(opcion_procesos_inventario_eliminar){
							// Inicio eliminar inventario mensual (datos usuario)
							case 1:
								lista_usuarios_mensual[contador_inventario_mensual].eliminar_inventario_mensual();// Invoca funcion eliminar datos de empleado inventario mensual	
							break;
							// Inicio eliminar inventario mensual (datos productos)	
							case 2:
								lista_inventario_mensual[contador_inventario_mensual].eliminar_inventario_mensual_productos();// Invoca funcion eliminar datos de productos inventario mensual					
							break;
							// Inicio eliminar inventario trimestral (datos usuario)		
							case 3:
								lista_usuarios_trimestral[contador_inventario_trimestral].eliminar_inventario_trimestral();// Invoca funcion eliminar datos de empleado inventario trimestral					
							break;
							// Inicio eliminar inventario trimestral (datos productos)		
							case 4:
								lista_inventario_trimestral[contador_inventario_trimestral].eliminar_inventario_trimestral_productos();// Invoca funcion eliminar datos de productos inventario mensual						
							break;
							// Inicio eliminar inventario anual (datos usuario)	
							case 5:
								lista_usuarios_anual[contador_inventario_anual].eliminar_inventario_anual();// Invoca funcion eliminar datos de empleado inventario anual				
							break;
							// Inicio eliminar inventario anual (datos productos)	
							case 6:
								lista_inventario_anual[contador_inventario_anual].eliminar_inventario_anual_productos();// Invoca funcion eliminar datos de productos inventario anual						
							break;
							// Retorno al menu principal	
							case 7:
								retorno_menu=true;// Retorna a menu principal
								cout<<"\n\t\t\tPresione una tecla para continuar..."<<endl;
							break;
							// Validacion de menu		
							default:			
								cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
								getch();						
						}// Inicio switch procesos a eliminar dentro de inventario contable
					}while(!retorno_menu);
				break;
				// Fin Eliminar Inventario Contable	
						 /**/								
				// Inicio Cerrar Sesion
				case 10:
					system("cls");
					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
									cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								cout<<"\t\t\t      Cerrando Sesion "<<usuario<<"."<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					cout<<"\n Agradecemos su visita en nuestra plataforma, se procedera a cerrar sesion."<<endl<<endl;
					cout<<"\t\t\t\t Cerrando Sesion ";
					for(b_e=0;b_e<5;b_e++){
						Sleep(550);// Espera 0.50 segundos
						cout<<".";
					}
					login();// Cierra sesion e invoca funcion Login para nuevo logueo
				break;	
				// Fin Cerrar Sesion	
				// Inicio Validacion Menu Admin
				default:
					cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
				// Fin Validacion Menu Admin		
			}// Fin de switch case - procesos para usuario nivel administrador
 		system("pause>null");
   	// Fin de login Para Administradores
}while(salir!=10);
// Fin de menu y procesos para Administrador
}// Fin if validacion de clave de acceso true
else
 	if(password!="admin.speedlimit"){
 		cout<<"\n Contrase"<<char(164)<<"a incorrecta, por favor ingrese una clave correcta."<<endl;
 		system("pause>null");
 	}// Fin if validacion de clave de acceso false
}// Fin if validacion de usuarios nivel administradores true
else
 	if(usuario!="admin" || usuario!="Admin"){
 		cout<<"\n Nombre de usuario incorrecto, por favor ingrese un usuario correcto."<<endl;
 		system("pause>null");
 	} // Fin if validacion de usuarios nivel administradores false
 	if(i>0){
 		cout<<"\n\n\t\tUd. ha realizado "<<i<<" de 3 intentos permitidos."<<endl;
 		system("pause>null");
 	} // Fin if contador de intentos
	if(i==3){
		cout<<"\n\n\tLo sentimos, ha llegado al maximo numero de intentos permitidos"<<endl;
		system("pause>null");
		exit(0); // No retorna al programa
	} // Fin if contador de intentos = 3	
	}// Fin ciclo for i
}

/***************************************************
   PROCEDIMIENTOS EXTERNOS PARA TODOS LOS USUARIOS 
***************************************************/	

/**************************************************
			FACTURACION DE PRODUCTOS FINAL
***************************************************/

// Inicio muestra de datos de tipo CLIENTE facturacion final
void sistema_facturacion_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]){
	if(cantidad>0){// Comprobacion si existen registros de facturas creadas en el sistema
		for(int i=0;i<cantidad;i++){
			cout<<" Datos de facturacion numero "<<i+1<<": "<<endl;
			cout<<"\tNombre del Cliente: "<<sistema_factura_final_datos_clientes[i].nombre_cliente<<"."<<endl;
			cout<<"\tCodigo Unico de Compra: Cod. #"<<sistema_factura_final_datos_clientes[i].codigo_compra<<"."<<endl;
			cout<<"\tNumero de DUI del Cliente: #"<<sistema_factura_final_datos_clientes[i].num_DUI<<"."<<endl;
			cout<<"\tNumero de NIT del Cliente: #"<<sistema_factura_final_datos_clientes[i].num_NIT<<"."<<endl;
			cout<<"\tFecha de Facturacion: "<<sistema_factura_final_datos_clientes[i].dia_facturacion<<"/"<<sistema_factura_final_datos_clientes[i].mes_facturacion<<"/"<<sistema_factura_final_datos_clientes[i].a_o_facturacion<<"."<<endl;
		}
	}else{// Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
	}
}// Fin muestra de datos de tipo CLIENTE facturacion final

// Inicio muestra de datos de tipo PRODUCTOS facturacion final
void sistema_facturacion_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]){
	if(cantidad>0){// Comprobacion si existen registros de facturas creadas en el sistema
	double sub_total_final_iva, sub_total_final_sin_iva, calculo_iva;
		for(int i=0;i<cantidad;i++){
			cout<<"\tItem # "<<i+1<<"."<<endl;
			cout<<"\t   Nombre de producto: "<<sistema_factura_final_productos[i].nombre_productos_compra<<"."<<endl;
			cout<<"\t   Cantidad de productos: "<<sistema_factura_final_productos[i].cantidad_productos<<" unidades."<<endl;
			cout<<"\t   Valor de producto: $"<<sistema_factura_final_productos[i].precio_productos_compra<<" USD."<<endl;
			cout<<"\t   Total Articulo(s): $"<<sistema_factura_final_productos[i].calculo_precio<<" USD."<<endl;
			sub_total_final_sin_iva+=sistema_factura_final_productos[i].calculo_precio; // Calculo neto de productos sin IVA
			calculo_iva=sub_total_final_sin_iva*0.13; // Calculo de monto IVA
			sub_total_final_iva=sub_total_final_sin_iva+calculo_iva; // Calculo de precio final con IVA INCLUIDO
		}
		cout<<"\t----------------------------------------------"<<endl;
		cout<<"\n\t- Total a pagar sin IVA: $"<<sub_total_final_sin_iva<<" USD. -"<<endl;// Imprime precio SIN IVA
		cout<<"\n\t- Total a pagar con IVA: $"<<sub_total_final_iva<<" USD. -"<<endl;// Imprime precio CON IVA
		cout<<"\n\t- Monto Agregado IVA: $"<<calculo_iva<<" USD. -"<<endl;// Imprime monto agregado IVA
		cout<<"\t----------------------------------------------"<<endl;
		cout<<"\n\n Presione cualquier tecla para volver al menu..."<<endl;
	}else{// Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
	}
}// Fin muestra de datos de tipo PRODUCTOS facturacion final
void sistema_cotizacion_clientes(int cantidad, sistema_cotizacion sistema_cotizacion_cliente_final[]){
	if(cantidad>0){
		double sub_total_final_iva, sub_total_final_sin_iva, calculo_iva;
		for(int i=0;i<cantidad;i++){// Comprobacion si existen registros de facturas creadas en el sistema
			cout<<"\t Sistema de Cotizacion Para Clientes: "<<endl<<endl;
			cout<<"\t Nombre de producto:: "<<sistema_cotizacion_cliente_final[i].nombre_producto_cotizacion<<"."<<endl<<endl;
			cout<<"\t Cantidad de productos: "<<sistema_cotizacion_cliente_final[i].cantidad_productos_cotizacion<<"."<<endl<<endl;
			cout<<"\t Precio de productos: $"<<sistema_cotizacion_cliente_final[i].precio_productos_cotizacion<<" USD."<<endl<<endl;
			sub_total_final_sin_iva+=sistema_cotizacion_cliente_final[i].calculo_precio_cotizacion; // Calculo neto de productos sin IVA
			calculo_iva=sub_total_final_sin_iva*0.13; // Calculo de monto IVA
			sub_total_final_iva=sub_total_final_sin_iva+calculo_iva; // Calculo de precio final con IVA INCLUIDO
			
		}
		cout<<"\t----------------------------------------------"<<endl;
		cout<<"\n\t- Total a pagar sin IVA: $"<<sub_total_final_sin_iva<<" USD. -"<<endl;// Imprime precio SIN IVA
		cout<<"\n\t- Total a pagar con IVA: $"<<sub_total_final_iva<<" USD. -"<<endl;// Imprime precio CON IVA
		cout<<"\n\t- Monto Agregado IVA: $"<<calculo_iva<<" USD. -"<<endl;// Imprime monto agregado IVA
		cout<<"\t----------------------------------------------"<<endl;
		cout<<"\n\n Presione cualquier tecla para volver al menu..."<<endl;
	}else{// Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
	}
}
// Inicio de impresion de datos de clientes en pagina web
void factura_final_datos_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]){
	if(cantidad>0){
		for(int i=0;i<cantidad;i++){
			ofstream archivo;
			archivo.open("datos_clientes_factura_final.html",ios::out);
			archivo<<"<!DOCTYPE html>"<<endl;
			archivo<<"<html>"<<endl;
			archivo<<"<head>"<<endl;
			archivo<<"<meta charset=""utf-8"">"<<endl;
			archivo<<"<title>..::SpeedLimit Taller | Detalles de Cliente Facturado::..</title>"<<endl;
			archivo<<"<link rel=""stylesheet"" type=""text/css"" href=""css/estilos.css"">"<<endl;
			archivo<<"<link href=""https://fonts.googleapis.com/css?family=Bungee+Shade|Open+Sans"" rel=""stylesheet"">"<<endl;
			archivo<<"<link href=""https://fonts.googleapis.com/css?family=Orbitron"" rel=""stylesheet"">"<<endl;
			archivo<<"<link href=""https://fonts.googleapis.com/css?family=Gruppo"" rel=""stylesheet"">"<<endl;
			archivo<<"</head>"<<endl;
			archivo<<"<body>"<<endl;
			archivo<<"<div class=""contenedor"">"<<endl;
			archivo<<"<div id=""banner"">"<<endl;
			archivo<<"<h2>SpeedLimit Taller S.A de C.V</h2>"<<endl;
			archivo<<"</div>"<<endl;// Cierre de div class banner
			archivo<<"<article>"<<endl;
			archivo<<"<div class=""informacion_facturacion"">"<<endl;
			archivo<<"<div class=""info_left"">"<<endl;
			archivo<<"<p>Detalles de Datos del Cliente:</p>"<<endl;
			archivo<<"<div id=""datos_factura"">"<<endl;
			archivo<<"<p>Nombre del cliente: "<<sistema_factura_final_datos_clientes[i].nombre_cliente<<"."<<"</p>"<<endl;
			archivo<<"<p>C&oacute;digo de Compra: #"<<sistema_factura_final_datos_clientes[i].codigo_compra<<"."<<"</p>"<<endl;
			archivo<<"<p>N&uacute;mero de DUI: #"<<sistema_factura_final_datos_clientes[i].num_DUI<<"."<<"</p>"<<endl;
			archivo<<"<p>N&uacute;mero de NIT: #"<<sistema_factura_final_datos_clientes[i].num_NIT<<"."<<"</p>"<<endl;
			archivo<<"<p>Fecha de Facturaci&oacute;n: "<<sistema_factura_final_datos_clientes[i].dia_facturacion<<"/"<<sistema_factura_final_datos_clientes[i].mes_facturacion<<"/"<<sistema_factura_final_datos_clientes[i].a_o_facturacion<<"."<<"</p>"<<endl;
			archivo<<"</div>"<<endl;// Cierre de div id datos factura
			archivo<<"</div>"<<endl;// Cierre de div class info left
			archivo<<"</div>"<<endl;// Cierre de div class informacion de facturacion
			archivo<<"</article>"<<endl;// Cierre de article contenedor de datos de facturacion
			archivo<<"</div>"<<endl;// Cierre de div class contenedor
			archivo<<"</body>"<<endl;
			archivo<<"</html>"<<endl;
            archivo.close();//Se cierra el arvchivo
            cout<<"\n Recopilando informacion, espere un momento";
            for(int b_e=0;b_e<6;b_e++){
            	Sleep(500);// Espera 0.5 segundos
            	cout<<".";
            }
            cout<<"\n Datos recopilados con exito, presione ENTER para abrir el navagador."<<endl;
            getch();
            system("start datos_clientes_factura_final.html");
		}
	}else // Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
}
// Fin de impresion de datos de clientes en pagina web
// Inicio de impresion de datos de productos facturados en pagina web
void factura_final_datos_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]){
	if(cantidad>0){
		double sub_total_final_iva, sub_total_final_sin_iva, calculo_iva;
		ofstream archivo;
		archivo.open("datos_productos_factura_final.html",ios::out);
		archivo<<"<!DOCTYPE html>"<<endl;
		archivo<<"<html>"<<endl;
		archivo<<"<head>"<<endl;
		archivo<<"<meta charset=""utf-8"">"<<endl;
		archivo<<"<title>..::SpeedLimit Taller | Detalles de Productos Facturados::..</title>"<<endl;
		archivo<<"<link rel=""stylesheet"" type=""text/css"" href=""css/estilos.css"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Bungee+Shade|Open+Sans"" rel=""stylesheet"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Orbitron"" rel=""stylesheet"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Gruppo"" rel=""stylesheet"">"<<endl;
		archivo<<"</head>"<<endl;
		archivo<<"<body>"<<endl;
		archivo<<"<div class=""contenedor"">"<<endl;
		archivo<<"<div id=""banner"">"<<endl;
		archivo<<"<h2>SpeedLimit Taller S.A de C.V</h2>"<<endl;
		archivo<<"</div>"<<endl;
		archivo<<"<article>"<<endl;
		archivo<<"<div class=""informacion_facturacion"">"<<endl;
		archivo<<"<div class=""info_right"">"<<endl;
		archivo<<"<p>Detalles de Productos Comprados:</p>"<<endl;
		archivo<<"<div id=""datos_cliente"">"<<endl;
		for(int i=0;i<cantidad;i++){
			archivo<<"<p>Item # "<<i+1<<"."<<"</p>"<<endl;
			archivo<<"<p>Nombre de producto: "<<sistema_factura_final_productos[i].nombre_productos_compra<<"."<<"</p>"<<endl;
			archivo<<"<p>Cantidad de productos: "<<sistema_factura_final_productos[i].cantidad_productos<<" unidades."<<"</p>"<<endl;
			archivo<<"<p>Valor de productos: $"<<sistema_factura_final_productos[i].precio_productos_compra<<" USD."<<"</p>"<<endl;
			archivo<<"<p>Total de articulo(s): $"<<sistema_factura_final_productos[i].calculo_precio<<" USD."<<"</p>"<<endl<<endl;
			archivo<<"<hr></hr>"<<endl;
			sub_total_final_sin_iva+=sistema_factura_final_productos[i].calculo_precio; // Calculo neto de productos sin IVA
			calculo_iva=sub_total_final_sin_iva*0.13; // Calculo de monto IVA
			sub_total_final_iva=sub_total_final_sin_iva+calculo_iva; // Calculo de precio final con IVA INCLUIDO
		}
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<p class=""facturacion1"">Monto total sin IVA: $"<<sub_total_final_sin_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p class=""facturacion2"">Monto total con IVA: $"<<sub_total_final_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p class=""facturacion3"">Monto agregado IVA: $"<<calculo_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p>"<<char(126)<<char(126)<<" Fue Un Placer Servirle, Gracias Por Su Compra "<<char(126)<<char(126)<<"</p>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"</div>"<<endl;// Cierre de div id datos cliente
		archivo<<"</div>"<<endl;// Cierre de div class info right
		archivo<<"</div>"<<endl;// Cierre de div class informacion de facturacion
		archivo<<"</article>"<<endl;// Cierre de article contenedor de datos de facturacion
		archivo<<"</div>"<<endl;// Cierre de div class contenedor
		archivo<<"</body>"<<endl;
		archivo<<"</html>"<<endl;
        archivo.close();//Se cierra el arvchivo
        cout<<"\n Recopilando informacion, espere un momento";
        for(int b_e=0;b_e<6;b_e++){
        	Sleep(500);// Espera 0.5 segundos
            cout<<".";
        }
        cout<<"\n Datos recopilados con exito, presione ENTER para abrir el navagador."<<endl;
        getch();
        system("start datos_productos_factura_final.html");
	}else // Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
}
// Fin de impresion de datos de productos facturados en pagina web
// Inicio de impresion de datos de productos cotizados en pagina web
void cotizacion_final_sistema_clientes(int cantidad, sistema_cotizacion sistema_cotizacion_cliente_final[]){
	if(cantidad>0){
		double sub_total_final_iva, sub_total_final_sin_iva, calculo_iva;
		ofstream archivo;
		archivo.open("cotizacion_clientes.html",ios::out);
		archivo<<"<!DOCTYPE html>"<<endl;
		archivo<<"<html>"<<endl;
		archivo<<"<head>"<<endl;
		archivo<<"<meta charset=""utf-8"">"<<endl;
		archivo<<"<title>..::SpeedLimit Taller | Detalles de Productos Cotizados::..</title>"<<endl;
		archivo<<"<link rel=""stylesheet"" type=""text/css"" href=""css/estilos.css"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Bungee+Shade|Open+Sans"" rel=""stylesheet"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Orbitron"" rel=""stylesheet"">"<<endl;
		archivo<<"<link href=""https://fonts.googleapis.com/css?family=Gruppo"" rel=""stylesheet"">"<<endl;
		archivo<<"</head>"<<endl;
		archivo<<"<body>"<<endl;
		archivo<<"<div class=""contenedor"">"<<endl;
		archivo<<"<div id=""banner"">"<<endl;
		archivo<<"<h2>SpeedLimit Taller S.A de C.V</h2>"<<endl;
		archivo<<"</div>"<<endl;
		archivo<<"<article>"<<endl;
		archivo<<"<div class=""informacion_facturacion"">"<<endl;
		archivo<<"<div class=""info_right"">"<<endl;
		archivo<<"<p>Detalles de Productos Cotizados:</p>"<<endl;
		archivo<<"<div id=""datos_cliente"">"<<endl;
		for(int i=0;i<cantidad;i++){
			archivo<<"<p>Item # "<<i+1<<"."<<"</p>"<<endl;
			archivo<<"<p>Nombre de producto: "<<sistema_cotizacion_cliente_final[i].nombre_producto_cotizacion<<"."<<"</p>"<<endl;
			archivo<<"<p>Cantidad de productos: "<<sistema_cotizacion_cliente_final[i].cantidad_productos_cotizacion<<" unidades."<<"</p>"<<endl;
			archivo<<"<p>Valor de productos: $"<<sistema_cotizacion_cliente_final[i].precio_productos_cotizacion<<" USD."<<"</p>"<<endl;
			archivo<<"<hr></hr>"<<endl;
			sub_total_final_sin_iva+=sistema_cotizacion_cliente_final[i].calculo_precio_cotizacion; // Calculo neto de productos sin IVA
			calculo_iva=sub_total_final_sin_iva*0.13; // Calculo de monto IVA
			sub_total_final_iva=sub_total_final_sin_iva+calculo_iva; // Calculo de precio final con IVA INCLUIDO
		}
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<p class=""facturacion1"">Monto total sin IVA: $"<<sub_total_final_sin_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p class=""facturacion2"">Monto total con IVA: $"<<sub_total_final_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p class=""facturacion3"">Monto agregado IVA: $"<<calculo_iva<<" USD."<<"</p>"<<endl;
		archivo<<"<p>Precios sujetos a cambios sin previo aviso.</p>"<<endl;
		archivo<<"<p>Dudas? Escribenos en atencionalcliente"<<char(64)<<"speedlimit.com""</p>"<<endl;
		archivo<<"<p>"<<char(126)<<char(126)<<" Gracias por utilizar nuestra plataforma. "<<char(126)<<char(126)<<"</p>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"<hr></hr>"<<endl;
		archivo<<"</div>"<<endl;// Cierre de div id datos cliente
		archivo<<"</div>"<<endl;// Cierre de div class info right
		archivo<<"</div>"<<endl;// Cierre de div class informacion de facturacion
		archivo<<"</article>"<<endl;// Cierre de article contenedor de datos de facturacion
		archivo<<"</div>"<<endl;// Cierre de div class contenedor
		archivo<<"</body>"<<endl;
		archivo<<"</html>"<<endl;
        archivo.close();//Se cierra el arvchivo
        cout<<"\n Recopilando informacion, espere un momento";
        for(int b_e=0;b_e<6;b_e++){
        	Sleep(500);// Espera 0.5 segundos
            cout<<".";
        }
        cout<<"\n Datos recopilados con exito, presione ENTER para abrir el navagador."<<endl;
        getch();
        system("start cotizacion_clientes.html");
	}else // Si no, entonces mostrar....
		cout<<"\n Lo sentimos, no hay nada que mostrar..."<<endl;
}
// Fin de impresion de datos de productos cotizados en pagina web


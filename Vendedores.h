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
/** Inicio Metodos (Prototipos) **/
void vendedores(void);
void login(void);
void sistema_facturacion_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Agrega nuevos clientes al sistema para general factura final
void sistema_facturacion_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Sistema de facturacion de productos final
void factura_final_datos_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Vista de datos del cliente facturados en pagina web
void factura_final_datos_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Vista de datos de productos facturados en pagina web
void hora_sistema(void);// Muestra hora del sistema en el programa
/** Fin Metodos (Prototipos) **/

/********************************/
/*   USUARIO 4: VENDEDORES	    */
/*******************************/
void vendedores(void){
// ** VARIABLES ** //
system("color A");// Cambio de color texto (consola-programa)
string usuario, password; // Autenticacion de usuario
int i; // Contador de intentos
int b_e; // Simulacion de Barra de Espera
int salir; // Salir del programa
int retorno_principal; // Retorno de menu principal (login) con opcion no valida
bool retorno_menu=false; // Controla retorno a menu principal de programa
int sub_menu_vendedores; // Opcion menu de opciones login vendedores
int tipo_vista_productos;// Tipo de vista en opcion productos
productos_speedlimit lista_productos[100]; // Arreglo general para productos_speedlimit
int contador=0; // Aumento en 1 por cada producto registrado
int num_productos_compra; // N numero de productos a procesar en factura final
facturacion_speedlimit_datos_cliente listado_de_clientes_facturacion[200];// Arreglo general para sistema de facturacion final datos CLIENTES
int contador_clientes_facturacion=0;// Aumento en 1 por cada cliente ingresado al sistema para facturacion final
facturacion_speedlimit_productos listado_de_productos_facturacion[200];// Arreglo general para sistema de facturacion final datos PRODUCTOS
int contador_productos_facturacion=0;// Aumento en 1 por cada producto ingresado al sistema de facturacion final
int tipo_vista_factura_final;// Tipo de vista de factura final
int codigo_eliminacion_cliente_facturacion;// N codigo de facturacion tipo cliente a eliminar dentro de factura
int codigo_eliminacion_producto_facturacion;// N codigo de facturacion tipo productos a eliminar dentro de factura
int vista_inventario; // Tipo de inventario a ver
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
// Inicio ciclo for i
for(int i=1;i<4;i++){
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t\t   Login Vendedores SpeedLimit"<<endl<<endl;
				hora_sistema();// Invoca a funcion para mostrar hora actual del sistema			
	cout<<"--------------------------------------------------------------------------------";
 	cout<<" Por favor ingrese su informacion personal de usuario"<<endl<<endl;
 	cout<<" Ingrese su nombre de usuario: ";
 	cin>>usuario;// Captura nombre se usuario	
 	// Inicio validacion de usuarios
 	if(usuario=="ana.ramos" || usuario=="melissa.viana"){
 		cout<<"\n Nombre de usuario correcto.\n\n Por favor ingrese su contrase"<<char(164)<<"a: ";
 		cin>>password;// Captura clave de acceso
 		if(password=="aers.speedlimit" || password=="mevr.speedlimit"){
 			cout<<"\n Contrase"<<char(164)<<"a correcta."<<endl;
 			cout<<"\n\t\t\t\tIniciando Sesion";
 			// Inicio Simulacion De Barra De Espera
 			for(b_e=0;b_e<5;b_e++){
 				Sleep(450); // Espera de 0.45 Segundos
 				cout<<".";
 			}
 			// Fin Simulacion De Barra De Espera
 			// Menu y procesos para Vendedores
 			do{
 				system("cls"); // Limpia proceso anterior y muestra nuevos procesos nivel vendedores
 				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
							cout<<"\t\t\t     Bienvenido/a "<<usuario<<"."<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				// Inicio de sub-menu para procesos usuario nivel vendedores
				cout<<"\n Estimado/a "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
				cout<<" 1. Ver Lista De Productos."<<endl;
				cout<<" 2. Generar Factura Final."<<endl;
				cout<<" 3. Ver Factura Final."<<endl;
				cout<<" 4. Ver Inventario Contable."<<endl;
				cout<<" 5. Cerrar Sesion."<<endl;
				cout<<"\n\t\t\t\tSu opcion: ";
				cin>>sub_menu_vendedores;// Captura opcion de menu elegida por gerencia general
				// Inicio de switch case - procesos para usuario nivel gerencia general
				switch(sub_menu_vendedores){
					// Inicio Ver Lista De Productos
					case 1:
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
					// Inicio Generar Factura Final	
					case 2:
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
					case 3:
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
					// Inicio Ver Inventario Contable
					case 4:
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
					// Inicio Cerrar Sesion 
					case 5:
						system("cls");
						cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t  Cerrando Sesion "<<usuario<<"."<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------";
						cout<<"\n Agradecemos su visita en nuestra plataforma, se procedera a cerrar sesion."<<endl<<endl;
						cout<<"\t\t\t\t Cerrando Sesion ";
						for(b_e=0;b_e<5;b_e++){
							Sleep(550);// Espera 0.50 segundos
							cout<<".";
						}
						system("color C");// Cambio de color texto (consola-programa)
						login();
					break;	
					// Fin Cerrar Sesion 	
					// Inicio Validacion Menu Vendedores
					default:
						cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
					// Fin Validacion Menu Vendedores	
				}// Fin de switch case - procesos para usuario nivel vendedores
			system("pause>null");
   		// Fin de login Para gerencia general
 	}while(salir!=5);
   	// Fin de menu y procesos para Gerencia general
}// Fin if validacion de clave de acceso true
	else
 		if(password!="aers.speedlimit" || password!="mevr.speedlimit"){
 			cout<<"\n Contrase"<<char(164)<<"a incorrecta, por favor ingrese una clave correcta."<<endl;
 			system("pause>null");
 		}// Fin if validacion de clave de acceso false
 	}// Fin if validacion de usuarios nivel gerencia general true
 		else
 			if(usuario!="ana.ramos" || usuario!="melissa.viana"){
 				cout<<"\n Nombre de usuario incorrecto, por favor ingrese un usuario correcto."<<endl;
 				system("pause>null");
 			} // Fin if validacion de usuarios nivel gerencia general false
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

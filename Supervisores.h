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
void supervisores(void);// Usuarios supervisores
void login(void);
void sistema_facturacion_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Agrega nuevos clientes al sistema para general factura final
void sistema_facturacion_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Sistema de facturacion de productos final
void factura_final_datos_clientes(int cantidad, facturacion_speedlimit_datos_cliente sistema_factura_final_datos_clientes[]);// Vista de datos del cliente facturados en pagina web
void factura_final_datos_productos(int cantidad, facturacion_speedlimit_productos sistema_factura_final_productos[]);// Vista de datos de productos facturados en pagina web
void hora_sistema(void);// Muestra hora del sistema en el programa
/** Fin Metodos (Prototipos) **/

/********************************/
/*   USUARIO 3: SUPERVISORES    */
/*******************************/

void supervisores(void){
// ** VARIABLES ** //
system("color E");// Cambio de color texto (consola-programa)
string usuario, password; // Autenticacion de usuario
int i; // Contador de intentos
int b_e; // Simulacion de Barra de Espera
int salir; // Salir del programa
int retorno_principal; // Retorno de menu principal (login) con opcion no valida
bool retorno_menu=false; // Controla retorno a menu principal de programa
int sub_menu_supervisores; // Opcion menu de opciones login supervisores
productos_speedlimit lista_productos[100]; // Arreglo general para productos_speedlimit
int num_nuevos_productos; // N numero de productos a registrar
int contador=0; // Aumento en 1 por cada producto registrado	
int tipo_vista_productos;// Tipo de vista en opcion productos
int opcion_procesos_productos; // Opcion a realizar dentro de campo modificar / eliminar productos
int opcion_procesos_inventario_modificar; // Opcion a realizar dentro de campo modificar inventario
int opcion_procesos_inventario_eliminar; // Opcion a realizar dentro de campo eliminar inventario
int num_productos_compra; // N numero de productos a procesar en factura final
facturacion_speedlimit_datos_cliente listado_de_clientes_facturacion[200];// Arreglo general para sistema de facturacion final datos CLIENTES
int contador_clientes_facturacion=0;// Aumento en 1 por cada cliente ingresado al sistema para facturacion final
facturacion_speedlimit_productos listado_de_productos_facturacion[200];// Arreglo general para sistema de facturacion final datos PRODUCTOS
int contador_productos_facturacion=0;// Aumento en 1 por cada producto ingresado al sistema de facturacion final
int tipo_vista_factura_final;// Tipo de vista de factura final
int codigo_eliminacion_cliente_facturacion;// N codigo de facturacion tipo cliente a eliminar dentro de factura
int codigo_eliminacion_producto_facturacion;// N codigo de facturacion tipo productos a eliminar dentro de factura
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
int codigo_inventario_usuario;// Codigo de inventario a modificar (Tipo Usuario)
int codigo_inventario_productos;// Codigo de inventario a modificar (Tipo Productos)
int num_productos_inventario; // N cantidad de productos ha agregar en inventario
int tipo_inventario; // Tipo de inventario a crear
int vista_inventario; // Tipo de inventario a ver
// Inicio ciclo for i
for(i=1;i<4;i++){
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
				cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t\t  Login Supervisores SpeedLimit"<<endl<<endl;
					hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
	cout<<"--------------------------------------------------------------------------------";
 	cout<<" Por favor ingrese su informacion personal de usuario"<<endl<<endl;
 	cout<<" Ingrese su nombre de usuario: ";
 	cin>>usuario;// Captura nombre se usuario
 	// Inicio validacion de usuarios	
	if(usuario=="daniel.rivera" || usuario=="carlos.guardado"){
 		cout<<"\n Nombre de usuario correcto.\n\n Por favor ingrese su contrase"<<char(164)<<"a: ";
 		cin>>password;// Captura clave de acceso
 		if(password=="edmr.speedlimit" || password=="cemg.speedlimit"){
 			cout<<"\n Contrase"<<char(164)<<"a correcta."<<endl;
 			cout<<"\n\t\t\t\tIniciando Sesion";
 			// Inicio Simulacion De Barra De Espera
 			for(b_e=0;b_e<5;b_e++){
 				Sleep(450); // Espera de 0.45 Segundos
 				cout<<".";
 			}
 			// Fin Simulacion De Barra De Espera
 			// Menu y procesos para supervisores
 			do{
 				system("cls"); // Limpia proceso anterior y muestra nuevos procesos nivel supervisores
 				cout<<"--------------------------------------------------------------------------------"<<endl;
						cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
							cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
							hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
							cout<<"\t\t\t   Bienvenido/a "<<usuario<<"."<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------";
				// Inicio de sub-menu para procesos usuario nivel supervisores
				cout<<"\n Estimado/a "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
				cout<<" 1. Ver Lista De Productos."<<endl;
				cout<<" 2. Modificar / Eliminar Productos."<<endl;
				cout<<" 3. Generar Factura Final."<<endl;
				cout<<" 4. Ver Factura Final."<<endl;
				cout<<" 5. Agregar Informe Contable Del Inventario"<<endl;
				cout<<" 6. Ver Inventario Contable."<<endl;
				cout<<" 7. Modificar Inventario Contable."<<endl;
				cout<<" 8. Eliminar Inventario Contable."<<endl;
				cout<<" 9. Cerrar Sesion."<<endl;
				cout<<"\n\t\t\t\tSu opcion: ";
				cin>>sub_menu_supervisores;// Captura opcion de menu elegida por supervisores
				// Inicio de switch case - procesos para usuario nivel supervisores		
				switch(sub_menu_supervisores){
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
					// Inicio Modificar / Eliminar Productos
					case 2:
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
					case 3:
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
					case 4:
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
					case 5:
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
					case 6:
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
					case 7:
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
									/**/
				// Inicio Eliminar Inventario Contable
				case 8:
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
					// Inicio Salir Del Programa
					case 9:
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
					// Fin Salir Del Programa
					// Inicio Validacion Menu Supervisores
					default:
						cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
					// Fin Validacion Menu Supervisores	
				}// Fin de switch case - procesos para usuario nivel supervisores
			system("pause>null");
   		// Fin de login Para supervisores
 	}while(salir!=9);
   	// Fin de menu y procesos para Supervisores
}// Fin if validacion de clave de acceso true
	else
 		if(password!="edmr.speedlimit" || password!="cems.speedlimit"){
 			cout<<"\n Contrase"<<char(164)<<"a incorrecta, por favor ingrese una clave correcta."<<endl;
 			system("pause>null");
 		}// Fin if validacion de clave de acceso false
 	}// Fin if validacion de usuarios nivel supervisores true
 	else
 		if(usuario!="daniel.rivera" || usuario!="carlos.guardado"){
 			cout<<"\n Nombre de usuario incorrecto, por favor ingrese un usuario correcto."<<endl;
 			system("pause>null");
 		} // Fin if validacion de usuarios nivel supervisores false
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
}// Fin void supervisores(void)

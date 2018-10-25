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
/** Inicio Metodos (Prototipos) **/
void clientes(void);
void login(void);
void sistema_cotizacion_clientes(int cantidad, sistema_cotizacion sistema_cotizacion_cliente_final[]);// Sistema de cotizacion clientes
void hora_sistema(void);// Muestra hora del sistema en el programa
/** Fin Metodos (Prototipos) **/

/********************************/
/* 	   USUARIO 5: CLIENTES		*/
/*******************************/
void clientes(void){
	// ** VARIABLES ** //
	system("color F");// Cambio de color texto (consola-programa)
	int opcion_menu; // Opcion de menu tipo de usuario (login)
	int b_e; // Simulacion de Barra de Espera
	string usuario, password; // Autenticacion de usuario
	int i; // Contador de intentos
	int salir; // Salir del programa
	int retorno_principal; // Retorno de menu principal (login) con opcion no valida
	bool retorno_menu=false; // Controla retorno a menu principal de programa
	int sub_menu_invitados; // Opcion menu de opciones login clientes
	productos_speedlimit lista_productos[100]; // Arreglo general para productos_speedlimit
	int contador=0; // Aumento en 1 por cada producto registrado
	sistema_cotizacion lista_cotizacion[500];// Arreglo general sistema de cotizacion
	int contador_cotizacion=0;// Contador de productos registrados en cotizacion
	int num_productos_cotizacion;// N productos a procesar en cotizacion
	// Inicio ciclo for i
	for(i=1;i<4;i++){
		system("cls");
		cout<<"--------------------------------------------------------------------------------"<<endl;
				cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
						cout<<"\t\t\t    Login Clientes SpeedLimit"<<endl<<endl;
						hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
		cout<<"--------------------------------------------------------------------------------";
 		cout<<" Por favor ingrese su informacion personal de usuario"<<endl<<endl;
 		cout<<" Ingrese su nombre de usuario: ";
 		cin>>usuario;// Captura nombre se usuario
		// Inicio validacion de usuarios
 		if(usuario=="invitado" || usuario=="Invitado"){
 			cout<<"\n Nombre de usuario correcto.\n\n Por favor ingrese su contrase"<<char(164)<<"a: ";
 			cin>>password;// Captura clave de acceso
 			if(password=="invitado123"){
 				cout<<"\n Contrase"<<char(164)<<"a correcta."<<endl;
 				cout<<"\n\t\t\t\tIniciando Sesion";
 				// Inicio Simulacion De Barra De Espera
 				for(b_e=0;b_e<5;b_e++){
 					Sleep(450); // Espera de 0.45 Segundos
 					cout<<".";
 				}
 				// Fin Simulacion De Barra De Espera
 				// Menu y procesos para Gerencia General
				do{
 					system("cls"); // Limpia proceso anterior y muestra nuevos procesos nivel gerencia general
 					cout<<"--------------------------------------------------------------------------------"<<endl;
							cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
								cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
								hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
								cout<<"\t\t\t\tBienvenido/a "<<usuario<<"."<<endl<<endl;
					cout<<"--------------------------------------------------------------------------------";
					// Inicio de sub-menu para procesos usuario nivel gerencia general
					cout<<"\n Estimado/a "<<usuario<<", por favor elija una opcion: "<<endl<<endl;
					cout<<" 1. Ver Lista De Productos."<<endl;
					cout<<" 2. Generar Una Cotizacion."<<endl;
					cout<<" 3. Ver Cotizacion Final En El Sistema."<<endl;
					cout<<" 4. Ver Cotizacion Final En El Sitio Web."<<endl;
					cout<<" 5. Cerrar Sesion."<<endl;
					cout<<"\n\t\t\t\tSu opcion: ";
					cin>>sub_menu_invitados;// Captura opcion de menu elegida por cliente
					// Inicio de switch case - procesos para usuario nivel clientes
					switch(sub_menu_invitados){
					// Inicio Ver Lista De Productos
						case 1:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
											cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t\t      Ver Lista De Productos"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							lista_productos[contador].recuperar();
						break;
						// Fin Ver Lista De Productos	
									/**/
						// Inicio Generar Cotizacion Final
						case 2:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t\t   Generar Cotizacion Final"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							cout<<"\n Estimado/a cliente, cuantos productos desea cotizar? ";
							cin>>num_productos_cotizacion;// Captura N productos a cotizar
							for(i=0;i<num_productos_cotizacion;i++){
								system("cls");
								cout<<"--------------------------------------------------------------------------------"<<endl;
										cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
										cout<<"\t\t\t\t Producto "<<i+1<<" de "<<num_productos_cotizacion<<"."<<endl<<endl;
								cout<<"--------------------------------------------------------------------------------";
								lista_cotizacion[contador_cotizacion].generar_cotizacion();
								lista_cotizacion[contador_cotizacion].calcular_cotizacion();
								contador_cotizacion++;
							}
						break;
						// Fin Generar Cotizacion Final	
									/**/
						// Inicio Ver Cotizacion Final En El Sistema			
						case 3:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
											cout<<"\t\t\t        Ver Cotizacion Final"<<endl<<endl;
							cout<<"--------------------------------------------------------------------------------";
							sistema_cotizacion_clientes(contador_cotizacion,lista_cotizacion);
						break;	
						// Fin Ver Cotizacion Final	En El Sistema
									/**/
						// Inicio Ver Cotizacion Final En El Sitio Web
						case 4:
							cotizacion_final_sistema_clientes(contador_cotizacion,lista_cotizacion);
						break;
						// Fin Ver Cotizacion Final En El Sitio Web	
									/**/					
						// Inicio Salir Del Programa
						case 5:
							system("cls");
							cout<<"--------------------------------------------------------------------------------"<<endl;
									cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
										cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
									cout<<"\t\t\t    Cerrando Sesion "<<usuario<<"."<<endl<<endl;
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
						// Inicio Validacion Menu Clientes
						default:
							cout<<"\n\t\t\t  Opcion De Menu Incorrecta"<<endl;
						// Fin Validacion Menu Clientes						
					}// Fin de switch case - procesos para usuario nivel clientes
				system("pause>null");
   			// Fin de login Para Clientes
 		}while(salir!=3);
   							// Fin de menu y procesos para Clientes
 	}// Fin if validacion de clave de acceso true
else
 	if(password!="invitado123"){
 		cout<<"\n Contrase"<<char(164)<<"a incorrecta, por favor ingrese una clave correcta."<<endl;
 		system("pause>null");
 	}// Fin if validacion de clave de acceso false
}// Fin if validacion de usuarios nivel clientes general true
else
 	if(usuario!="invitado" || usuario!="Invitado"){
 		cout<<"\n Nombre de usuario incorrecto, por favor ingrese un usuario correcto."<<endl;
 		system("pause>null");
 	} // Fin if validacion de usuarios nivel clientes false
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

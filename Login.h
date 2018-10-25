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
/** Inicios Metodos (Prototipos) **/
void login(void);
void administradores(void);
void gerencia_general(void);
void supervisores(void);
void vendedores(void);
void clientes(void);
void hora_sistema(void);
/** Fin Metodos (Prototipos) **/
void login(void){
	bool salir_programa=false;
	do{
		// Variables de funcion
	int opcion_menu;
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
			cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
			hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
	cout<<"--------------------------------------------------------------------------------";
	cout<<"\n Estimado usuario, por favor elija una opcion: "<<endl;
	cout<<"\n 1. Inicio de Sesion Administradores."<<endl;
	cout<<"\n 2. Inicio de Sesion Gerencia General."<<endl;
	cout<<"\n 3. Inicio de Sesion Supervisores."<<endl;
	cout<<"\n 4. Inicio de Sesion Vendedores."<<endl;
	cout<<"\n 5. Inicio de Sesion Clientes."<<endl;
	cout<<"\n 6. Salir del Programa."<<endl;
	cout<<"\n\t\t\t\tSu opcion: ";
	cin>>opcion_menu;// Captura opcion de login
	// Validacion de opciones de logueo
	if(opcion_menu>=1 && opcion_menu<7){
		if(opcion_menu==1){
			administradores(); // Usuarios validados: TIPO ADMINISTRADORES
		}// Fin if primer usuario
		else if(opcion_menu==2){
			gerencia_general(); // Usuarios validados: TIPO GERENCIA GENERAL - PRESIDENCIA
		}// Fin else if segundo usuario
		else if(opcion_menu==3){
			supervisores();// Usuarios validados: TIPO SUPERVISORES
		}// Fin if else tercer usuario
		else if(opcion_menu==4){
			vendedores();// Usuarios validados: TIPO VENDEDORES
		}// Fin if else cuarto usuario
		else if(opcion_menu==5){
			clientes();// Usuarios validados: TIPO CLIENTES - INVITADOS
		}
		else if(opcion_menu==6){
			system("cls");
			cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"\t\t<< Venta de Repuestos Automotrices SpeedLimit >>"<<endl<<endl;
					cout<<"\t\t\tA.C.E.&.M Soluciones Informaticas"<<endl<<endl;
					cout<<"\t\t\t     Saliendo del programa."<<endl<<endl;
			cout<<"--------------------------------------------------------------------------------";
			cout<<"\n Agradecemos su visita en nuestra plataforma, recuerde SpeedLimit lider "<<endl;
			cout<<"\n en venta de repuestos automotrices a nivel nacional, visitanos en: "<<endl;
			cout<<"\n 4"<<char(166)<<" Calle Poniente y 6"<<char(166)<<" Av. sur, Santa Tecla, La Libertad."<<endl;
			cout<<"\n\n\t\t\t Saliendo del programa";
			for(int b_e=0;b_e<5;b_e++){
				Sleep(500);// Espera 0.5 segundos
				cout<<".";
			}
			salir_programa=true; // Valida salida de programa
			system("Mapa_Ubicacion.png");// Abre mapa de ubicacion SpeedLimit
			exit(0);// No retorna al programa
		}
	}// Fin if if(opcion_menu>=1 && opcion_menu<7)
	else{
			cout<<"\n\t\t     Por favor, ingrese una opcion valida."<<endl;
			getch();
		}
	}while(!salir_programa);
}// Fin void login(void)

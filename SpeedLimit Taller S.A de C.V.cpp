/*
																	    	A.C.E.&.M Soluciones Informaticas
																Sistema de gestión para cadena de repuestos automotriz
																	 © Copyright 2017 Reservados Todos Los Derechos
																	 
	Importante: Proyecto creado únicamente para fines educativos, queda explicitamente prohibida la utilización de este proyecto bajo fines comerciales.
	Autor: Daniel Rivera.
	Sistema de ventas de repuestos.
	© Copyright 2017 - 2018

																	 
*/
// Inicio de Cabeceras Principales
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include "Funciones_Generales.h" // Funciones generales del programa
#include "Sistema_Facturacion.h"// Sistema de facturacion y cotizacion de productos SpeedLimit
#include "Administrador.h" // Login y validacion de administradores
#include "Gerencia_General.h" // Login y validacion de gerencia general
#include "Supervisores.h" // Login y validacion de supervisores
#include "Vendedores.h"// Login y validacion de vendedores
#include "Clientes.h"// Login y validacion de clientes (invitados)
#include "Login.h" // Menu de logueo para usuarios
#include "Hora_Sistema.h"// Muestra hora del sistema en el programa
using namespace std;
// Fin de Cabeceras Principales
// Inicio de Main
main(){
	// ** Variables ** //
	int opcion_menu; // Opcion de menu tipo de usuario (login)
	int retorno_principal; // Retorno de menu principal (login) con opcion no valida
	system("color C");// Cambio de color texto (consola-programa)
	//** Fin de Variables ** //
	// Inicio Ciclo Do-While Principal (Menu Login)
	do{
		login(); // Se invoca funcion login
		// Inicio switch case opcion menu
		switch(opcion_menu){
			/********************************************
				Inicio Login Para Administradores
			*********************************************/
			case 1:
				administradores();// Invoca funcion usuario nivel administrador
			break; // Fin Inicio Login Para Administradores
			/********************************************
					Inicio Login Para Gerencia General
			*********************************************/	
			case 2:
				gerencia_general();// Invoca funcion usuarios nivel de presidencia - gerencia general
			break; // Fin Inicio Login Para Gerencia General
			/********************************************
					Inicio Login Para Supervisores
			*********************************************/	
			case 3:
				supervisores();// Invoca funcion usuarios nivel de supervisores
			break; // Fin Inicio Login Para Supervisores
			/********************************************
					Inicio Login Para Vendedores
			*********************************************/
			case 4:
				vendedores();// Invoca funcion usuarios nivel de vendedores	
			break; // Fin Inicio Login Para Gerencia General
			/********************************************
					Inicio Login Para Clientes
			*********************************************/	
			case 5:
				clientes();// Invoca funcion usuarios nivel de clientes (Invitados)
			break; // Fin Inicio Login Para Clientes	
		}// Fin switch case opcion menu	
	}while(retorno_principal!=5); // Fin Ciclo Do-While Principal (Menu Login)
}// Fin de Main

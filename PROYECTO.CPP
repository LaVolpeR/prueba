#include<iostream>
#include <stdio.h>  
#include <windows.h>
#include <conio.h>
using namespace std;
 
struct datos{
 	int inicio;
 	int final;
 	int clientes;
 	int cajas;
 	struct datos *sgte;
};

typedef struct datos *Tlista;
void menu();
void insertar(Tlista &lista, int Cli, int Caj, int Ini );
void visualizar_cuadro(Tlista lista);
void visualizar_Gestion(Tlista lista);
void visualizar_Gestion_corregido(Tlista lista);

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
} 
 
void menu(){
 	cout<<"\t\t.:MENU:.\n"<<endl;
 	cout<<"1.Insertar Nueva caja"<<endl;
 	cout<<"2.Visualizar cuadro de datos"<<endl;
 	cout<<"3.Visualizar cuadro de gestion de colas"<<endl;
 	cout<<"4.Salir"<<endl;
}

void insertar(Tlista &lista, int Cli, int Caj, int Ini ){
	Tlista t, q = new(struct datos);
	q->cajas = Caj;
	q->clientes = Cli;
	q->inicio = Ini;
	q->final = q->inicio +1;
	q->sgte = NULL;
	if(lista==NULL){
		lista = q;
	}	
	else{
		t= lista;
		while(t->sgte != NULL){
			t= t->sgte;
		}
		t->sgte = q;
	}
}

void visualizar_cuadro(Tlista lista){
int j = 0;
gotoxy(1,6);cout<<"Horas";
gotoxy(1,7);cout<<"Llegada de clientes";
gotoxy(1,8);printf("N%c cajas abiertas",167);
	while(lista != NULL){
		
		gotoxy(22 + 8*j,6);cout<<lista->inicio<<" a "<<lista->final;
		gotoxy(24 + 8*j,7);cout<<lista->clientes;
		gotoxy(24 + 8*j,8);cout<<lista->cajas;
	
		lista = lista->sgte;
		j++;
	}
}

void visualizar_Gestion(Tlista lista){
	int j= 0, k = 0, Input = 0, Output = 0;
	gotoxy(1,6);cout<<"Horas";
	gotoxy(1,7);cout<<"Llegada de clientes";
	gotoxy(1,8);printf("N%c cajas abiertas",167);
	gotoxy(1,9);cout<<"Capacidad de salidas";
	gotoxy(1,11);cout<<"Salidas de clientes";
	gotoxy(1,13);cout<<"Cola de espera";
	gotoxy(1,14);cout<<"Input";
	gotoxy(1,15);cout<<"Output";
	while(lista != NULL){
		gotoxy(22 + j*8,6);cout<<lista->inicio<<" a "<<lista->final;
		gotoxy(24 + j*8,7);cout<<lista->clientes;
		gotoxy(24 + j*8,8);cout<<lista->cajas;
		gotoxy(24 + j*8,9);cout<<lista->cajas * 12;
		gotoxy(24 + j*8,11);cout<<lista->cajas * 12;
		gotoxy(24 + j*8,13);cout<<(lista->clientes + k) - (lista->cajas*12);
		Input += lista->clientes;
		Output += lista->cajas * 12;
		gotoxy(24 + j*7,14);cout<<Input;
		gotoxy(24 + j*7,15);cout<<Output;
		k = lista->clientes + k - lista->cajas*12;
		lista = lista->sgte;
		j++;
	}
}

void visualizar_Gestion_corregido(Tlista lista){
	int j= 0, k = 0, Input = 0, Output = 0,condition = 0;
	gotoxy(1,20);cout<<"Horas";
	gotoxy(1,21);cout<<"Llegada de clientes";
	gotoxy(1,22);printf("N%c cajas abiertas",167);
	gotoxy(1,23);cout<<"Capacidad de salidas";
	gotoxy(1,25);cout<<"Salidas de clientes";
	gotoxy(1,27);cout<<"Cola de espera";
	gotoxy(1,28);cout<<"Input";
	gotoxy(1,29);cout<<"Output";
	while(lista != NULL){
	
		do{
			
		if((lista->clientes + k) - (lista->cajas*12) >= 12){
			lista->cajas++;
				condition = 0;
		}
		else if((lista->clientes + k) - (lista->cajas*12) <0){
			lista->cajas--;
				condition = 0;
		}
		else{
			condition = 1;
			cout<<condition;
		}
		}while(condition = 0);
		gotoxy(22 + j*8,20);cout<<lista->inicio<<" a "<<lista->final;
		gotoxy(24 + j*8,21);cout<<lista->clientes;
		gotoxy(24 + j*8,22);cout<<lista->cajas;
		gotoxy(24 + j*8,23);cout<<lista->cajas * 12;
		gotoxy(24 + j*8,25);cout<<lista->cajas * 12;
		gotoxy(24 + j*8,27);cout<<(lista->clientes + k) - (lista->cajas*12);
		
		Input += lista->clientes;
		Output += lista->cajas * 12;
		gotoxy(24 + j*7,28);cout<<Input;
		gotoxy(24 + j*7,29);cout<<Output;
		k = lista->clientes + k - lista->cajas*12;
		lista = lista->sgte;
		j++;
	}
}

int main(){
	Tlista lista = NULL;
	int opc, X,Y,Z, i= 0;
	do{
	menu();
	cin>>opc;
	switch(opc){
		case 1:
			if(i==0){
				cout<<"Insertar la hora de inicio, para comenzar (NOTA: Despues no aparecera el horario y solo sera de una hora de intervalo)"<<endl;
				cin>>Z;
			}
			else{
				Z++;
			}
			cout<<"Escriba la cantidad de clientes que ingresaron al establecimiento: ";
			cin>>X;
			cout<<"Escriba la cantidad de cajas abiertas";
			cin>>Y;
			insertar(lista,X,Y,Z);
			i++;
			system("cls");
			break;
		case 2:
			system("cls");
			visualizar_cuadro(lista);
			cout<<"\n\n";
			system("pause");
			system("cls");
			
			break;
		case 3:
			system("cls");
			visualizar_Gestion(lista);
			visualizar_Gestion_corregido(lista);
			cout<<"\n\n";
			system("pause");
			system("cls");
			break;
	}
}while(opc!=4);
	return 0;
}

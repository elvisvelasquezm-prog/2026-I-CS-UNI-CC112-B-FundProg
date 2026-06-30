#include<iostream>
#include <fstream> 
#include<cstring>
#include"type.h"

using namespace std;


template<typename T>
void ordenar(T array[],int inicio, int medio, int final);

template<typename T>
void mergsort(T array[], int inicio, int final);

class persona{
	protected:

	TS nombre[50];
	T numero;
	TS pais[30];
	

	public:
	 
	persona(){}	
	 
     
	 ~persona(){

	 }

	friend istream& operator >>(istream &is,persona &p1){
	if(!(is>>p1.nombre)) return is;
	is>>p1.numero;
	is.ignore();
	is.getline(p1.pais,30);

	return is;

	}

	friend ostream& operator<<(ostream &os,persona &p1){
		os<<p1.nombre<<" "<<p1.numero<<" "<<p1.pais<<endl;

    return os;	
	
	
	}

	bool operator <=(persona& p1){
		if((strcmp(nombre,p1.nombre))<=0){
			return true;}
		
		else{
			return false;
		}

	}
};

void agregarContacto(TS1 nombreArchivo);

void eliminarContacto(TS1 nombreArchivo);

int programa();
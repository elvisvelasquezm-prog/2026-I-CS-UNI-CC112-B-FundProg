#include<iostream>
#include <fstream> 
#include<cstring>
#include"sistema.h"

using namespace std;


template<typename T>
void ordenar(T array[],int inicio, int medio, int final){
	int i=inicio,j=medio+1,k=0;
	T temp[final-inicio+1];
	while(i<=medio&&j<=final){
		if(array[i]<=array[j]){
			temp[k]=array[i];
			i++;
		}
		else{
			temp[k]=array[j];
			j++;
			
		}
		k++;}
		while(i<=medio){
			temp[k]= array[i];
			i++;k++;
		}
		while(j<=final){
			temp[k] = array[j];
			j++;k++;
		}
	
	for(int p=0;p<k;p++){
		array[inicio+p]=temp[p];
	}
}
	
template<typename T>
void mergsort(T array[], int inicio, int final){

	if(inicio==final){return;}
	
	else{
	
	int mitad=(inicio+final)/2;
	mergsort(array,inicio,mitad);
	mergsort(array,mitad+1,final);
	
	ordenar(array,inicio,mitad,final);
}

}


void agregarContacto(string nombreArchivo){

	ofstream f(nombreArchivo,ios::app);
	if(!f){
		cout<<" no se pudo abrir el archivo "<<endl;
		return;
	}
	TS nombre[50];
	T numero;
	TS pais[30];

	cout<<" digite lo siguiente "<<endl;
	cout<<" nombre: ";
	cin>>nombre;
	cout<<" numero: ";
	cin>>numero;
	cout<<" pais: ";
	cin>> pais;

	f<<nombre<<" "<< numero<< " "<<pais <<endl;

	f.close();
	cout<<"\n contacto guardado "<<endl;
}

void eliminarContacto(string nombreArchivo){
	ifstream fOrig(nombreArchivo);
	ofstream fTemp("temporal.txt");

	if(!fOrig || !fTemp){
		cout<<"error"<<endl;
		return ;
	}

	string nonmbreAborr;
	cout<<"\n digite el contacto a borrar ";
	cin>>nonmbreAborr;

	TS nombre[50];
	T numero;
	TS pais[30];
	TSS encontrado= false;

	while(fOrig>>nombre>>numero>>pais){
		if(nombre != nonmbreAborr){
			fTemp<<nombre<<" "<<numero<<" "<<pais<<endl;
		}else{
			encontrado=true;
		}
	}
	fOrig.close();
	fTemp.close();

	remove(nombreArchivo.c_str());
	rename("temporal.txt",nombreArchivo.c_str());

	if(encontrado){
		cout<<"\n  conatcto eliminado "<<endl;
	}else{
		cout<<" no se encontro contacto con ese nombre "<<endl;
	}
	
}


int programa(){
	

	

	cout<<"digite el nombre del archivo que continene sus contactos "<<endl;
    string archivo;
	cin>>archivo;

int opcion;
do{
    cout<<" \n ----- menu ------"<<endl;
	cout<<" 1. mostrar y ordenar contactos "<<endl;
	cout<<" 2. agregar contacto "<<endl;
	cout<<" 3. eliminar conatcto "<<endl;
	cout<<" 4. salir "<<endl;
	cin>>opcion;

	switch(opcion){
		case 1:{
			
	ifstream f(archivo);
	int n=0;
	persona temporal;
	while(f>>temporal){
		n++;
	};
	f.clear();
	f.seekg(0);
   
	persona *contactos;

		contactos=new persona[n];

	for(int i=0;i<n;i++){
		f>>contactos[i];
	}


	cout<<"\n contactos ordenados " <<endl;
    
	mergsort(contactos,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<contactos[i];
	}
    
	string ordenado="contacto_ordenado.txt";
    

	ofstream f_salida(ordenado);
    if (!f_salida) return 1;
    
	for(int i=0;i<n;i++){
		f_salida<<contactos[i];
	}
    delete[] contactos;
    break;
		}
case 2:
    agregarContacto(archivo);
	break;

case 3:
    eliminarContacto(archivo);
	break;

case 4:
    cout<<" saliendo del sistema... "<<endl;	
    break;

default:
     cout<<" opcion invalida"<<endl;
	}
}while (opcion!=4);	
     
	return 0;}

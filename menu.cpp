#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void menu(int vector[], int tam);
void agregar(int vector[], int tam);
void eliminar(int vector[], int tam);
void reporte(int vector[], int tam);
bool comprobar(int vector[], int tam,int valor);
void buscar(int vector[],int tam);
void modificar(int vector[], int tam);
void insertar(int vector[],int tam);
int main()
{
	int vector[20]={0}, tam = 20;
	menu(vector,tam);
    return 0;
}
void menu(int vector[],int tam)
{
    int op;
    srand(time(0));
	cout<<"Introduzca una opcion";
	cin>>op;
	while (op != 0)
	{
		switch (op)
		{
		case  1:
		   // system("cls");
			agregar(vector, tam);
			break;
		case 2:
		    eliminar(vector,tam);
		    break;
		case 3:
		    buscar(vector,tam);
		    break;
		case 4:
		    modificar(vector,tam);
		    break;
		case 5:
		    insertar(vector,tam);
		    break;
		case 6:
		    //system("cls");
			reporte(vector, tam);
			break;
		}
		cout<<"Introduzca una opcion";
	    cin>>op;
	}
}
void agregar(int vector[], int tam)
{
    
	int stop = 0, i=0;
	while (stop != 1)
	{
		if (vector[i] != 0)
		{
			vector[i++];
		}
		else
		{
			vector[i] = 1+rand() % 300;
			stop = 1;
		}
	}
}
void reporte(int vector[], int tam)
{
    for (int i = 0; i<tam; i++)
	{
	    if(vector[i]!=0)
	    {
		    cout << "["<<i<<"]" << "\t" << vector[i]<<endl;
	    }
    }
}
void eliminar(int vector[], int tam)
{
    int valor;
    cout<<"Dame el valor a eliminar";
    cin>>valor;
    if(comprobar(vector,tam,valor)==true)
    {
        for(int i=0;i<tam;i++)
        {
            if(vector[i]==valor)
            {
                for(int x=i;x<tam;x++)
                {
                    vector[x]=vector[x+1];
                }
                cout<<"El valor ha sido modificado";
            }
        }
        
    }
    else
    {
        cout<<"El valor no existe";
    }
}
bool comprobar(int vector[], int tam, int valor)
{
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==valor)
        {
            return true;
        }
    }
}
void buscar(int vector[], int tam)
{
    int valor;
    cout<<"Ingresa el valor";
    cin>>valor;
    if(comprobar(vector,tam,valor)==true)
    {
        for(int i=0;i<tam;i++)
        {
            if(vector[i]==valor)
            {
                cout<<"posicion"<<"["<<i<<"]";
            }
        }
    }
    else
    {
        cout<<"-1";
    }
}
void modificar(int vector[],int tam)
{
    int modificable,modificador;
    cout<<"Ingresa el nuevo valor"<<endl;
    cin>>modificador;
    cout<<"Ingresa el valor a modificar"<<endl;
    cin>>modificable;
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==modificable)
        {
            vector[i]=modificador;
        }
    }
}
void insertar(int vector[], int tam)
{
    int pos,valor,tem;
    cout<<"Inserta la posicion a modificar"<<endl;
    cin>>pos;
    cout<<"Inserta el valor"<<endl;
    cin>>valor;
    if(vector[pos]!=0)
    {
        for(int i=pos;i<tam&&vector[i+1]!=0;i++)
        {
            tem=vector[i+1];
            vector[i]=tem;
        }
        vector[pos]=valor;
    }
    else
    {
        cout<<"ERROR!!";
    }
    
}




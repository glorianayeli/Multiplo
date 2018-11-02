#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void menu(int vector[], int tam);
void agregar(int vector[], int tam);
void eliminar(int vector[], int tam);
void reporte(int vector[], int tam);
bool comprobar(int vector[], int tam,int valor);
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
		    system("cls");
			agregar(vector, tam);
			break;
		case 6:
		    system("cls");
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
		cout << "["<<i<<"]" << "\t" << vector[i]<<endl;
	}
}
void eliminar(int vector[], int tam)
{
    int valor;
    cout<<"Dame el valor a eliminar";
    cin<<valor;
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
            }
        }
        cout<<"El valor ha sido modificado";
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

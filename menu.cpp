#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void agregar(int vector[], int tam);
void eliminar(int vector[], int tam, int valor);
void reporte(int vector[], int tam);
void modificar(int vector[],int tam, int modificable, int modificador);
int buscar(int vector[],int tam, int valor);
void insertar(int vector[],int tam, int pos, int valor);
int main()
{
	int vector[20]={0}, tam = 20,valor,pos,modificable,modificador;
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
            cout<<"Dame el valor a eliminar";
            cin>>valor;
		    eliminar(vector,tam,valor);
		    break;
		case 3:
		    cout<<"Dame el valor a buscar";
            cin>>valor;
            pos=buscar(vector,tam,valor);
		    if(pos!=-1)
		    {
		        cout<<"El valor:"<<valor<<"\t"<<"esta en la posicion"<<pos<<endl;
		    }
		    else
		    {
		        cout<<"El valor no existe"<<endl;
		    }
		    break;
		case 4:
		    pos=buscar(vector,tam,modificable);
            cout<<"Ingresa el nuevo valor"<<endl;
            cin>>modificador;
            cout<<"Ingresa el valor a modificar"<<endl;
            cin>>modificable;
            if(pos!=-1)
            {
		        modificar(vector,tam,modificable,modificador);
            }
            else
            {
                cout<<"El valor no existe"<<endl;
            }
		    break;
		case 5:
            cout<<"Inserta la posicion a modificar"<<endl;
            cin>>pos;
            cout<<"Inserta el valor"<<endl;
            cin>>valor;
		    insertar(vector,tam,pos,valor);
		    break;
		case 6:
		    //system("cls");
			reporte(vector, tam);
			break;
		}
		cout<<"Introduzca una opcion";
	    cin>>op;
	}
    return 0;
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
void eliminar(int vector[], int tam, int valor)
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
int buscar(int vector[], int tam, int valor)
{
    int pos=-1;
    for(int i=0;i<25;i++)
    {
        if(vector[i]==valor)
        {
            pos=i;
        }
    }
    return pos;
}
void modificar(int vector[],int tam, int modificable, int modificador)
{
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==modificable)
        {
            vector[i]=modificador;
        }
    }
}
void insertar(int vector[], int tam, int pos, int valor)
{
    int tem,cont;
    if(vector[pos]!=0)
    {
        tem=vector[pos+1];
        for(int i=pos;i<tam;i++)
        {
            if(vector[i]!=0)
            {
                cont++;
            }
        }
        for(int i=cont+1;i>=pos;i--)
        {
            vector[cont]=vector[cont+1];
        }
        vector[pos]=valor;
    }
    else
    {
        cout<<"ERROR!!";
    }
}

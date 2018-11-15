#include <stdio.h>
#include <iostream>
using namespace std;
void ventas (int matriz[][5],int columnas,int vendedor,int producto,int venta);
int comprobar(int matriz[][5],int columnas,int vendedor,int producto);
void imprimir(int matriz[][5],int columnas);
void totalproducto(int hoja[][5],int columnas,int producto);
void totalvededor(int hoja[][5],int columnas,int vendedor);
int main()
{
    int vendedor, producto, venta=0, hoja[5][5]={0},salir=1,op,guardar=1;//llenar hoja 1,imprimir 2,salir 0
    while(salir!=0)
    {
        cout<<"¿Cual es tu opcion?";
        cin>>op;
        switch(op)
        {
            case 1:
                while(guardar!=0)
                {
                    cout<<"¿Cual es tu numero de vendedor?";
                    cin>>vendedor;
                    cout<<"¿Cual es el producto?";
                    cin>>producto;
                    cout<<"¿Cual es el monto de la venta?";
                    cin>>venta;
                    ventas(hoja,5,vendedor,producto,venta);
                    cout<<"¿Quieres seguir grabando?s=1/n=0";
                    cin>>guardar;
                }
                break;
            case 2:
                imprimir(hoja,5);
                break;
            case 3:
                cout<<"¿Cual es producto?";
                cin>>producto;
                totalproducto(hoja,5,producto);cout<<endl;
                imprimir(hoja,5);
                break;
            case 4:
                cout<<"¿Cual es tu numero de vendedor?";
                cin>>vendedor;
                totalvededor(hoja,5,vendedor);cout<<endl;
                imprimir(hoja,5);
                break;
        }
        cout<<"¿Quieres continuar?s=1/n=0";
        cin>>salir;
    }
    return 0;
}
void ventas (int matriz[][5],int columnas,int vendedor,int producto,int venta)
{
    matriz[producto-1][vendedor-1]+=venta;
}
void imprimir(int matriz[][5],int columnas)
{
    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;c++)
        {
            cout<<matriz[r][c]<<"\t";
        }
        cout<<endl;
    }
}
void totalproducto(int hoja[][5],int columnas,int producto)
{
    for(int c=0;c<4;c++)
    {
        hoja[producto-1][5-1]+=hoja[producto-1][c];
    }
}
void totalvededor(int hoja[][5],int columnas,int vendedor)
{
    int suma=0;
    for(int r=0;r<4;r++)
    {
        suma+=hoja[r][vendedor-1];
    }
    hoja[5-1][vendedor-1]=suma;
}

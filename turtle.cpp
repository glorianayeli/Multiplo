#include <stdio.h>
#include <iostream>

int girarderecha(int &direccion);
int girarizquierda(int &direccion);
void avanzar(int matriz[][20], int renglon,int direccion,int pluma,int &pr,int &pc,int pasos);
int bajarpluma(bool &pluma);
int subirpluma(bool &pluma);
void imprimir(int matriz[][20],int renglon);
//void convertir(int matriz[][20],int renglon);
using namespace std;

int main()
{
    int piso [20][20] = {0};
    bool pluma = false;
    int direccion=3;
    int pr=0,pc=0,op,pasos;
    cout<<"Ingresa la opcion";
    cin>>op;
    while(op!=7)
    {
        switch(op)
        {
            case 1:
            subirpluma(pluma);
            break;
            case 2:
            bajarpluma(pluma);
            break;
            case 3:
            girarderecha(direccion);
            break;
            case 4:
            girarizquierda(direccion);
            break;
            case 5:
            cout<<"¿Cuantos pasos quieres avanzar?";
            cin>>pasos;
            avanzar(piso,20,direccion,pluma,pr,pc,pasos);
            break;
            case 6:
            //convertir(piso,20);
            imprimir(piso,20);
            break;
        }
        cout<<"Ingresa la opcion";
        cin>>op;
    }
    return 0;
}

void imprimir(int matriz[][20],int renglon)
{
    for(int r=0;r<20;r++)
    {
        for(int c=0;c<20;c++)
        {
            if(matriz[r][c]==1)
            {
                cout<<'*'<<"\t";
            }
            if(matriz[r][c]==0)
            {
                cout<<"\t";
            }
        }
        cout<<endl;
    }
}
int bajarpluma(bool &pluma)
{
    pluma=1;
    return pluma;
}
int subirpluma(bool &pluma)
{
    pluma=0;
    return pluma;
}
int girarderecha(int &direccion)//duda deben de ser &
{
    if(direccion==3)
        direccion=6;
    else if(direccion==6)
        direccion=9;
    else if(direccion==9)
        direccion=12;
    else if(direccion==12)
        direccion=3;
    return direccion;
        
}
int girarizquierda(int &direccion)
{
    if(direccion==3)
        direccion=12;
    else if(direccion==6)
        direccion=3;
    else if(direccion==9)
        direccion=6;
    else if(direccion==12)
        direccion=3;
    return direccion;
        
}
void avanzar(int matriz[][20], int renglon,int direccion,int pluma,int &pr,int &pc,int pasos)
{
    if(direccion==3)
    {
        for(int i=1;i<=pasos;i++)
        {
            pc++;
            if(pc==20)
            pc=19;
            if(pluma==1)
            matriz[pr][pc]=1;
        }
    }
    else if(direccion==6)
    {
        for(int i=1;i<=pasos;i++)
        {
            pr++;
            if(pr==20)
            pr=19;
            if(pluma==1)
            matriz[pr][pc]=1;
        }
        
    }
    else if(direccion==9)
    {
        for(int i=1;i<=pasos;i++)
        {
         pc--;
            if(pr==-1)
            pr=0;
            if(pluma==1)
            matriz[pr][pc]=1;
        }
    }
    else if(direccion==12)
    {
        for(int i=1;i<=pasos;i++)
        {
            pr--;
            if(pr==-1)
            pr=0;
            if(pluma==1)
            matriz[pr][pc]=1;
        }
    }
}

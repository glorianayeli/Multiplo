#include <stdio.h>
#include <iostream>
using namespace std;
void entrada();
int conversorsegundos(int hora, int minutos, int segundos);
void segundoshora(int segtotales);
int main()
{
    entrada();    
    return 0;
}

void entrada(){
    int hora, minutos, segundos,segtotales;
    cout<<"Ingresa la hora"<<"\t";
    cin>>hora;
    cout<<"Ingresa los minutos"<<"\t";
    cin>>minutos;
    cout<<"Ingresa los segundos"<<"\t";
    cin>>segundos;
    cout<<"Tus segundos son"<<"\t"<<conversorsegundos(hora, minutos, segundos);
    cout<<"Ingrasa los segundos totales";
    cin>>segtotales;
    segundoshora(segtotales);
}
int conversorsegundos(int hora, int minutos, int segundos)
{
    segundos=segundos+(minutos*60)+(hora*3600);
    return segundos;
}
void segundoshora(int segtotales)
{
    int hora, minutos, segundos;
    hora = segtotales/3600;
    minutos =(segtotales%3600)/60;
    segundos = (segtotales%3600)%60;
    cout<<"Horas"<<"\t"<<hora<<"Minutos"<<"\t"<<minutos<<"Segundos"<<"\t"<<segundos;
}

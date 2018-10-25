#include <iostream>
using namespace std;
void informacion();
void horastrabajadas( int horae,int minue,int sege,int horas,int minus,int segs);
int main()
{
    informacion();

    return 0;
}
void informacion()
{
    int horae,minue,sege,horas,minus,segs;
    cout<<"Ingresa la HORA de ENTRADA"<<endl;
    cin>>horae;
    cout<<"Ingresa la MINUTOS de ENTRADA";
    cin>>minue;
    cout<<"Ingresa la SEGUNDOS de ENTRADA";
    cin>>sege;
    cout<<"Ingresa la HORA de SALIDA";
    cin>>horas;
    cout<<"Ingresa la MINUTOS de SALIDA";
    cin>>minus;
    cout<<"Ingresa la HORA de SALIDA";
    cin>>segs;
    horastrabajadas(horae,minue,sege,horas,minus,segs);
}
void horastrabajadas( int horae,int minue,int sege,int horas,int minus,int segs)
{
    int res;
    if(sege<segs)
    {
        res=(sege-segs)+60;
        minue+=1;
        cout<<"segundos:\t"<<res;
        res=(minue-minus)+60;
        horas+=1;
        cout<<"minutos:\t"<<res;
        res=(horae-horas)+60;
        cout<<"horas:\t"<<res;
    }
    else
    {
        res=(sege-segs);
        cout<<"segundos:\t"<<res;
        res=(minue-minus);
        cout<<"minutos:\t"<<res;
        res=(horae-horas);
        cout<<"horas:\t"<<res;
    }
}

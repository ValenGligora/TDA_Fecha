#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define esbisiesto(anio) ((a)%4==0 && ((a)%100!=0 || (a)%400==0))
typedef struct {
    int d;
    int m;
    int a;
} Fecha;

void ingresoFechaValida(Fecha *fecha);
bool esFechaValida(Fecha *f);
int cantDiasMes(int m,int a);
void SumarDias(Fecha *fecha);
Fecha FechaSumaDias(int n,const Fecha *f);
void DiaAño(const Fecha *fecha);
void DiaSemana(const Fecha *fecha);



int main(){
    //hacer display de la fecha
    Fecha fecha;
    ingresoFechaValida(&fecha);
    SumarDias(&fecha);
    DiaAño(&fecha);
    DiaSemana(&fecha);
}

void ingresoFechaValida(Fecha *fecha){
    //Fecha fecha;
    puts("Ingrese una fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fecha->d, &fecha->m,&fecha->a);
    while (!esFechaValida(fecha)){
        puts("Fecha invalida. Ingrese nuevamente: ");
        scanf("%d/%d/%d",fecha->d,fecha->m,fecha->a);
    }
}

void SumarDias(Fecha *fecha){
    int sum;
    Fecha fnueva;
    printf("Indique cuantos dias desea sumarle a la fecha %d/%d/%d: ",fecha->d,fecha->m,fecha->a);
    scanf("%d",&sum);
    fnueva= FechaSumaDias(sum,fecha);
    printf("\nLa nueva fecha seria: %d/%d/%d",fnueva.d,fnueva.m,fnueva.a);
}

void DiaAño(const Fecha *fecha){
    int dias;
    for (int i = 1; i < fecha->m ; i++)
    {
        dias+=cantDiasMes(i,fecha->a);
    }
    dias+=fecha->d;
}

void DiaSemana(const Fecha *fecha){
    char *DiaSem[7]={"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado","Domingo"};
    int MesAux= fecha->m;
    int AnioAux= fecha->a;
    int siglo;
    if (MesAux<3)
    {
        MesAux+=12;
        AnioAux--;
    }
    //if (AnioAux>2000) siglo = (AnioAux/100)+1;
    //else    siglo = AnioAux/100;
    siglo = (AnioAux/100)+1;
    int anioEnSiglo = (AnioAux%100);
    
    
    int DS = (fecha->d + 13 * (MesAux + 1) / 5 + anioEnSiglo + anioEnSiglo / 4 + siglo / 4 + 5 * siglo) % 7;
    
    if (AnioAux<2000) DS--;
    
    printf("\nEl dia de la semana es: %s",DiaSem[DS]);
}

Fecha FechaSumaDias(int n,const Fecha *f){
    int cdm;
    Fecha FSuma= *f;
    FSuma.d+=n;
    while (FSuma.d>(cdm=cantDiasMes(FSuma.m,FSuma.a)))
    {
        FSuma.d-=cdm;
        FSuma.m--;
        if (FSuma.m>12)
        {
            FSuma.m=1;
            FSuma.a++;
        }
    }
    return FSuma;
}

bool esFechaValida(Fecha *f){
    if (f->a<1601) return false;
    if (f->m<1 || f->m>12) return false;
    if (f->d<1 || f->d>cantDiasMes(f->m,f->a)) return false;
    return true;
}

int cantDiasMes(int m,int a){
    int diasMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (m==2 && esbisiesto(a) ) return 29;
    return diasMes[m];
}
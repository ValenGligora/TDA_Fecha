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
void SumarDias(Fecha fecha);



int main(){
    //hacer display de la fecha
    Fecha fecha;
    ingresoFechaValida(&fecha);
    //fechaSumarDias();
    SumarDias(fecha);
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

void SumarDias(Fecha fecha){
    printf("Indique cuantos dias desea sumarle a la fecha: %d/%d/%d",fecha.d,fecha.m,fecha.a);
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
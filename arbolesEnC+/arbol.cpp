#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "arbol.h"
#define CANT 7
struct arbolE{
    char nombre[30];
    int edad;
    float altura;


};
//Builders

Arbol crearArbol(){
Arbol a=new arbolE();
std::cout <<" Ingrese el nombre del arbol."<<std::endl;
std::cin>>a->nombre;
std::cout <<" Ingrese la edad del arbol."<<std::endl;
std::cin>>a->edad;

std::cout <<" Ingrese la altura del arbol."<<std::endl;
std::cin>>a->altura;



return a;
}
Arbol iniciarArbol(){
Arbol a=new arbolE();
a->altura=-1;
a->edad=-1;
char aux[30]="*";
strcpy(a->nombre, aux);
return a;
}
void iniciarArboles(Arbol v[]){
for (int i=0;i<CANT;i++){
    v[i]=iniciarArbol();


}


}

//Mostradores
void mostrarArbol(Arbol a){
    if(a->edad!=-1){
std::cout<<" Nombre: "<<getNombre(a)<<" Edad: "<<getEdad(a)<<" Altura: "<<a->altura<<std::endl;
    }

}
void mostrarArboles(Arbol v[]){

for (int i=0;i<CANT;i++){

    mostrarArbol(v[i]);

}


}


//Getters
int getEdad(Arbol a){

return a->edad;
}
float getAltura(Arbol a){


a->altura;
}
char *getNombre(Arbol a){


return a->nombre;
}

//SETTER
void setEdad(Arbol a, int nueva){
a->edad=nueva;



}
//Archivo

Arbol pasarCharAStruct(char c[]){
Arbol a=new arbolE();

int i, j, k, q, r;
int delim1=0;
int delim2=0;
for (i=0;i<strlen(c);i++){
if (c[i]=='+'){
delim1=i;
i=strlen(c);

}


}
for (j=delim1;j<strlen(c);j++){
    if (c[j]=='+'){
        delim2=j;

    }


}
char auxEdad[10]=" ";
char auxAltura[10]=" ";
char auxNombre[30]=" ";
for (k=0;k<delim1;k++){
    auxNombre[k]=c[k];

}
for (q=delim1;q<delim2;q++){
    auxEdad[q-delim1-1]=c[q];

}
for (r=delim2;r<strlen(c);r++){
    auxAltura[r-delim2-1]=c[r];

}
a->edad=atoi(auxEdad);
strcpy(a->nombre, auxNombre);
a->altura=atof(auxAltura);


return a;
}
void cargarArchivo(Arbol v[]){
iniciarArboles(v);
int contador=0;
FILE *puntero;
puntero=fopen("arboles.txt", "r");
while(!feof(puntero)){

    char aux[60]=" ";
    fgets(aux, 60, puntero);
    v[contador]=pasarCharAStruct(aux);
    contador++;

}

fclose(puntero);

}
//Others
int buscarPosicionLibre(Arbol v[]){




int pos=-1;
int i;
for (i=0;i<CANT;i++){
    if (v[i]->edad==pos){
        pos=i;
    }
}
return pos;


}
int busquedaPosicionDelArbol(Arbol v[], char c[]){
int pos=-1;
for (int i=0;i<CANT;i++){
    if (strcmp(c, v[i]->nombre)==0){
        pos=i;
    }


}
return pos;


}
//ABM'S

void agregarArbol(Arbol v[]){
int posicion=buscarPosicionLibre(v);
if (posicion!=-1){
    v[posicion]=crearArbol();
FILE *puntero;
puntero=fopen("arboles.txt", "a");

fprintf (puntero, "%s+%d+%f\n", v[posicion]->nombre, v[posicion]->edad, v[posicion]->altura);
fclose(puntero);
}else{

std::cout<<"NO HAY MAS ESPACIO!!!"<<std::endl;

}




}

void eliminarArbol(Arbol v[]){
std::cout<<"INGRESE EL NOMBRE DEL ARBOL QUE QUIERE ELIMINAR"<<std::endl;
char aux[30];
std::cin>>aux;
int pos=busquedaPosicionDelArbol(v, aux);
if (pos!=-1){
    v[pos]=iniciarArbol();
    FILE*puntero;
    puntero=fopen("arboles.txt", "w");

    for (int i=0;i<CANT;i++){
        if (v[i]->edad!=-1){
           fprintf (puntero, "%s+%d+%f\n", v[i]->nombre, v[i]->edad, v[i]->altura);
        }


    }
    fclose(puntero);
}else{

std::cout<<"NO SE ENCONTRO EL ARBOL BUSCADO!!!"<<std::endl;
}



}
void modificarEdadArbol(Arbol v[]){
char aux[30];

std::cout<<"INGRESE EL NOMBRE DEL ARBOL QUE QUIERE MODIFICAR"<<std::endl;
std::cin>>aux;
int pos=busquedaPosicionDelArbol(v, aux);
if (pos!=-1){
        int nueva;
std::cout<<"INGRESE LA NUEVA EDAD DEL ARBOL QUE QUIERE MODIFICAR"<<std::endl;
std::cin>>nueva;
    setEdad(v[pos], nueva);
    FILE*puntero;
    puntero=fopen("arboles.txt", "w");

    for (int i=0;i<CANT;i++){
        if (v[i]->edad!=-1){
           fprintf (puntero, "%s+%d+%f\n", v[i]->nombre, v[i]->edad, v[i]->altura);
        }


    }
    fclose(puntero);
}else{

std::cout<<"NO SE ENCONTRO EL ARBOL BUSCADO!!!"<<std::endl;
}

}


#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct arbolE;
typedef struct arbolE *Arbol;
//Builders

Arbol crearArbol();
Arbol iniciarArbol();
void iniciarArboles(Arbol v[]);

//Mostradores
void mostrarArbol(Arbol a);
void mostrarArboles(Arbol v[]);

//Getters
int getEdad(Arbol a);
float getAltura(Arbol a);
char *getNombre(Arbol a);

//SETTER
void setEdad(Arbol a, int nueva);
//Archivo

Arbol pasarCharAStruct(char c[]);
void cargarArchivo(Arbol v[]);

//Other

int buscarPosicionLibre(Arbol v[]);
int busquedaPosicionDelArbol(Arbol v[], char c[]);

//ABM'S

void agregarArbol(Arbol v[]);
void eliminarArbol(Arbol v[]);

void modificarEdadArbol(Arbol v[]);

#endif // ARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "arbol.h"
#define CANT 7
int main(){

         Arbol arrayArboles[CANT];
cargarArchivo(arrayArboles);
int opcion;
int h=0;
do{

    		std::cout<<"SELECCIONE UNA OPCION"<<std::endl;

		std::cout<<"1- Mostrar arboles actuales:"<<std::endl;
		std::cout<<"2- Agregar un arbol."<<std::endl;
		std::cout<<"3- Eliminar un arbol."<<std::endl;
		std::cout<<"4- Editar edad de un arbol."<<std::endl;
		std::cout<<"0- SALIR DE OPCION."<<std::endl;


std::cin>>opcion;

		switch (opcion){
		    case 1: mostrarArboles(arrayArboles);break;
		    case 2: agregarArbol(arrayArboles);break;
		    case 3: eliminarArbol(arrayArboles);break;
		    case 4: modificarEdadArbol(arrayArboles);break;

		    case 0:

                default:
                    std::cout<<"ESA OPCION NO EXISTEEEEE"<<std::endl;

}
}while (opcion!=0);
         return 0;
         }

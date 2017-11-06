//Modulo que se encarga de todo lo que el programa imprime.

#ifndef OUTPUT_H
#define OUTPUT_H

#include<stdio.h>
#include"constantes.h"
#include "allegro5/allegro5.h"
#include <allegro5/allegro_audio.h>


int imprimir_puerto(void * puerto, ALLEGRO_BITMAP * (imagen[IMAGENES]));
//imprime el estado en el que se encuentra el puerto en el momento indicado


void imprimir_instrucciones(void);






#endif //OUTPUT_H
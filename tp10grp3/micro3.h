/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef MICRO3_H
#define MICRO3_H

#include <stdint.h>
#include "constantes.h"
#include <unistd.h>
#include "output.h"

int bitset( void * port, uint8_t nbit );
//pone el bit que se desea del puerto seleccionado en valor 1

int bitclr(void * port, uint8_t nbit );
//pone el bit que se desea del puerto seleccionado en valor 0 



int bitget(void * port, uint8_t nbit );
//devuelve el valor del bit seleccionado


void maskOn( void * port, uint16_t mask, char puerto);
//dada una masara cambia los valores del puerto seleccionado encendiendo los valores que dice la mascara
//y dejando los demas sin tocar

void maskOff( void * port, uint16_t mask, char puerto);

//dada una masara cambia los valores del puerto seleccionado apagando los valores que dice la mascara
//y dejando los demas sin tocar

void maskToggle( void * port, uint16_t mask, char puerto);
//funcion que dada una mascara te intercambia los valores del puerto seleccionado



void parpadear(uint8_t* port,ALLEGRO_BITMAP * imagen[IMAGENES]);
//hace parpadear el puerto que se elegije pasandole los valores que antes usaba


typedef struct             //definicion del puerto de 16 bits
{
	uint8_t porta;
	uint8_t portb;
} puertod_t;



#endif /* MICRO3_H */


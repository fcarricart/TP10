#ifndef CONSTANTES_H
#define CONSTANTES_H


#include "allegro5/allegro5.h"


#define OFFSET 10
#define ALTURA 150

#define ENCENDIDOS 's'
#define APAGADOS  'c'
#define PARPADEO 'b'
#define ESC 27
#define	BIT_MASK	1	//mascara para las funciones del tipo bit...
#define MASK 0


#define ENCENDIDO 1
#define APAGADO 0

#define ESTADO_INICIAL 0xAD


#define BIT0 0
#define BIT7 7
#define BIT8 8


#define	VALIDO 1
#define	INVALIDO 0


#define UN_SEGUNDO 1
#define TIEMPO_PARPADEANDO 4 //Cuanto tiempo dura el parpadeo.
#define ON (char)0xff
#define OFF (char)0x00

#define IMAGENES 8



#define PORTA 'a'   //cosntantes correspondientes a las funciones del manejo de mascaras
#define	PORTB 'b'
#define PORTD 'd'

//control de las teclas presionadas 

#define TERMINAR ALLEGRO_KEY_ESCAPE 
#define PRENDER ALLEGRO_KEY_S
#define APAGAR ALLEGRO_KEY_C
#define PARPADEAR ALLEGRO_KEY_B


//bits a prender

#define BITS0 ALLEGRO_KEY_PAD_0
#define BITS1 ALLEGRO_KEY_PAD_1
#define BITS2 ALLEGRO_KEY_PAD_2
#define BITS3 ALLEGRO_KEY_PAD_3
#define BITS4 ALLEGRO_KEY_PAD_4
#define BITS5 ALLEGRO_KEY_PAD_5
#define BITS6 ALLEGRO_KEY_PAD_6
#define BITS7 ALLEGRO_KEY_PAD_7


#endif /* CONSTANTES_H */


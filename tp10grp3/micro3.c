#include <stdio.h>

#include "micro3.h"




int bitset( void * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;

	if((nbit>= BIT0 ) && (nbit<= BIT7 ) ) //para saber si se esta trabajando con el puerto d
	{
		bit<<=nbit;	//corro el 1 n veces a la izquierda asi obtengo el bit que quiero prender
		
		*((uint8_t*)port)|=bit;	//realizo la siguiente operacion logica para poder prender ese bit y dejar los otros como estan
		
	}
	else	//indico que estoy trabjando en la parte baja del puerto d que vendria a ser el puerto b
	{
		uint8_t * portb=(uint8_t*)port+ BIT_MASK;
		bit<<=(nbit- BIT8 );

		*portb|=bit;


	}



	return 0;



}

int bitclr(void * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;	//asigno un bit en 0 para poder 


	if((nbit>= BIT0 ) && (nbit<= BIT7) ) //para saber si se esta trabajando con el puerto d
	{
		bit<<=nbit;	//corro el 1 n veces a la izquierda asi obtengo el bit que quiero apagar
		
		*((uint8_t*)port)&=(~bit);	//realizo la siguiente operacion logica para poder apagar ese bit y dejar los otros como estan
		
	}
	else	//indico que estoy trabjando en la parte baja del puerto d que vendria a ser el puerto b
	{
		uint8_t * portb=(uint8_t*)port+ BIT_MASK; //se repite lo de arriba
		bit<<=(nbit- BIT8 );

		*(portb)&=(~bit);


	}



	
	return 0;
}


int bitget(void * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;

	uint8_t a;

	if((nbit>= BIT0 ) && (nbit<= BIT7) ) //para saber si se esta trabajando con el puerto d
	{
		bit<<=nbit;	//corro el 1 n veces a la izquierda asi obtengo el bit que quiero apagar
		
		a=(*((uint8_t*)port)&(bit))?1:0;	//realizo la siguiente operacion logica para saber el valor del bit solicitado		
	}
	else	//indico que estoy trabjando en la parte baja del puerto d que vendria a ser el puerto b
	{
		uint8_t * portb=(uint8_t*)port+ BIT_MASK; //se repite lo de arriba
		bit<<=(nbit- BIT8 );

		a=(*(portb) & bit)?1:0;


	}



	

	return a;
	
}



void maskOn( void * port, uint16_t mask, char puerto)
{

	if( (puerto==PORTA) || (puerto==PORTB))
	{
		*((uint8_t*)port)|=((uint8_t)(mask));

	}
	else if ((puerto==PORTD))
	{
		*((uint16_t*)port)|=mask;
	}

}

void maskOff( void * port, uint16_t mask, char puerto)
{	
	if( (puerto==PORTA) || (puerto==PORTB))
	{
		*((uint8_t*)port)&=((uint8_t)(~mask));

	}
	else if ((puerto==PORTD))
	{
		*((uint16_t*)port)&=(~mask);
	}

}

void maskToggle( void * port, uint16_t mask, char puerto)
{
	if( (puerto==PORTA) || (puerto==PORTB))
	{
		*((uint8_t*)port)^=((uint8_t)(mask));

	}
	else if ((puerto==PORTD))
	{
		*((uint16_t*)port)^=(mask);
	}	
	
}



void parpadear(uint8_t* port,ALLEGRO_BITMAP * imagen[IMAGENES])
{
  uint8_t port_aux= (*port);
  int contador = 2;   //para ver cuantos segundos se quiere que parpadee
  while (contador --)  
  {
    imprimir_puerto(port,imagen);
    
    sleep(1); //1 segundo
    
    *port = (*port) & MASK;     //apaga leds
    
    imprimir_puerto(port,imagen);    //1 segundo
    
    (*port) = port_aux; // vuelvo a prender los que estaban prendidos
    sleep(1);
  }
}

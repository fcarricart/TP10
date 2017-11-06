#include "output.h"



#define OFFSET 10
#define ALTURA 150

int imprimir_puerto(void * puerto, ALLEGRO_BITMAP * (imagen[IMAGENES]))
{
	int i;
	unsigned char mask=0x80;				//en la posicion 0 se encuentra la imagen correspondiente al 
								//al bit 0 por eso la mascara es asi esta vez
	int valido=VALIDO;
        
	char  port=*((char*)puerto);
	
	for(i=0; (i<=BIT7)&&(valido); i++)
	{
    
            
            
		if(port&mask)
		{
                        
                        imagen[i] = al_load_bitmap("gokuss.png");
                        if(!(imagen[i]))
                        {
                            fprintf(stderr, "failed to load image !\n");
                            valido = INVALIDO;
                        }
                        
                        al_draw_bitmap(imagen[i], 150*i+10, ALTURA, 0);
 
                        al_flip_display();
     
		}
		else
		{
			imagen[i] = al_load_bitmap("goku.png");
                        if(!(imagen[i]))
                        {
                            fprintf(stderr, "failed to load image !\n");
                            valido =  INVALIDO;
                        }
                        
                        al_draw_bitmap(imagen[i],150*i+10, ALTURA, 0);
 
                        al_flip_display();
		}
		port<<=1;
		
	}
   		
	
	return valido;
}

void print_instructions(void)
{
  printf("*Bienvenido al simulador de cadena de 8 LEDs*\n");
  printf("Para encender un led presione un numero del 0 al 7\n");
  printf("Los leds estan colocados de esta manera 7 6 5 4 3 2 1 0\n");
  printf("*si desea encenderlos todos presione s\n");
  printf("*si desea apagarlos todos presione c\n");
  printf("*si desea que parpadeen presione b\n");
  printf("Nota: si presiono para que parpadee,\n");
  printf("debera esperar a que termine de parpadear para seguir con el programa\n");
  printf("*si desea cerrar el programa presione ESC\n");
}
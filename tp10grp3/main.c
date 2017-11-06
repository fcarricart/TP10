#include <stdio.h>
#include <allegro5/allegro.h> //NO OLVIDAR CONFIGURAR EL LINKER DESDE run-proyect configuration 
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include "constantes.h"
#include "output.h"
#include"micro3.h"
#include <unistd.h>

//Autores: Ariel Martorell, Lucas Migone, Francisco Carricart, Juan Schinocca.


void destroy_bitmaps(ALLEGRO_BITMAP * imagen[IMAGENES]);//funcion que destruye todos los bitmaps


/*
 * 
 */
int main(void) 
{
	ALLEGRO_DISPLAY *mi_display;
	ALLEGRO_BITMAP *morty[IMAGENES];
        ALLEGRO_EVENT_QUEUE *event_queue = NULL; 
        
        bool finalizar= false;
	
        int i;
        int tecla;
        puertod_t portd;
        uint8_t * porta= &portd.porta;
        
        // funciones de inicializacion si no se pueden iniciar terminan el programa
        
	if( !al_init() ) //lo mismo que igual a 0
	{
		fprintf(stderr, "Unable to start allegro\n");
		return -1;
	}
	else if( !al_init_image_addon())
	{
		fprintf(stderr,"Unable to start image addon \n"); //Igual que printf pero imprime al error std 
		al_uninstall_system();
		return -1;
	}
        else if(!al_install_keyboard()) 
        {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
 
        mi_display = al_create_display(2100,400);
	if( !mi_display )
	{
		fprintf(stderr,"Unable to create display\n"); 
		al_uninstall_system();
		al_shutdown_image_addon();
		return -1;
	}
      
        
        ;
        
        
        al_clear_to_color(al_map_rgb(255,255,255));
        al_flip_display();  //pongo el display de color blanco
        
        
        
        *porta=ESTADO_INICIAL; //seteando el puerto a a un valor cualquiera
        
        //invocacion inicial del puerto
        if(!(imprimir_puerto(porta,morty)))     //intenta imprimir el puerto y si no puede termina el programa
                {
                    al_destroy_display(mi_display);
                    destroy_bitmaps(morty);
                    return -1;
                }
        
        
        
        
        
        event_queue = al_create_event_queue();
	if(!event_queue) 
        {
		fprintf(stderr, "failed to create event_queue!\n");
		
		return -1;
	}
        
        
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        
        while(!finalizar)
        {
            ALLEGRO_EVENT ev;
            if( al_get_next_event(event_queue, &ev) )
            {
                if(!(imprimir_puerto(porta,morty)))     //intenta imprimir el puerto y si no puede termina el programa
                {
                    al_destroy_display(mi_display);
                    destroy_bitmaps(morty);
                    return -1;
                }
                if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
				finalizar = true;
                
                else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) 
                {
                    tecla=(ev.keyboard.keycode);
                    
                    switch(tecla)
                    {
                        case PRENDER: //caso en el que se prendan todos los leds los led
                        {
                            maskOn(porta, ON, PORTA);
                            printf("prender todos los leds\n");
                            break;
                        }
                        case APAGAR:
                        {
                            maskOff(porta,ON,'a');
                            printf("apagar los leds\n");
                            break;
                        }
                        case PARPADEAR:
                        {
                            parpadear(porta,morty);
                            printf("parpadear los leds encendidos \n");
                            break;
                        }
                        case BITS0: case BITS1: case BITS2: case BITS3: case BITS4:  case BITS5: case BITS6: case BITS7:
                        {
                           
                            int a;
                            int bit=(tecla-BITS0);    //para saber a que numero de bit corresponde
                            a=bitget(porta,bit);


                            if( a==ENCENDIDO)
                                {

                                    bitclr(porta,bit);
                                }
                            else if (a==APAGADO)
                                {
                                    bitset(porta,bit);
                                }
                            
                            printf("prender led %d \n",tecla-BITS0);
                            break;
                        }
                        case TERMINAR:
                        {
                            finalizar=true;
                            break;
                            
                        }
                        
                        default:
                        {
                            printf("presione otra tecla\n");
                            
                        }
                    }
                        
                    
                }
            }
        }
 
        
 
         al_destroy_display(mi_display);
         destroy_bitmaps(morty);        //para terminar todo al final
         
	return (0);
}


void destroy_bitmaps(ALLEGRO_BITMAP * imagen[IMAGENES])
{
    int i;
    for(i=0;i< IMAGENES;i++)
        {
            
            al_destroy_bitmap(imagen[i]);
        }
}

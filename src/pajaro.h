#ifndef __PAJA_H__
#define __PAJA_H__
#include "dibujos.h"
/*************************/
/**PARAMETROS DEL SENSOR**/
/*************************/
#define SENSOR_BASE 0x44A20000
#define MAX_HEIGTH 90
#define MIN_HEIGTH  0
#define DETECTION_RANGE 3 // cms


/************************/
/****PARAMETROS PAJARO***/
/************************/
#define MOVE_BIRD_TICK 25UL
#define VELOCIDAD 1

#define size_pajaro_x 20
#define size_pajaro_y 16

#define FRAMES_ANIMATION 10

#define BIRD_OFFSET 100 // La posicion en y es siempre BIRD_OFFSET - birdPos (para solucionar valores inversos en el sensor)


extern struct color pajaro[size_pajaro_y][size_pajaro_x];
extern struct color pajaro_frame2[size_pajaro_y][size_pajaro_x];

// Estado
enum ESTADO {NORMAL, INVENCIBLE, DOBLE_P, MUERTO};
typedef enum ESTADO estado_t;

/************************/
/*******FUNCIONES********/
/************************/

/**
 * Clalcula la nueva posicion del pajaro y la actualiza en su variable global y la retorna
 *
 * @return la posicion del pajaro
 */
int updateBirdPos (dibujo_t * pajaro);

/**
 * Inicializa las variables del sistema de moviento
 */
void init_bird();
#endif

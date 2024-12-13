/*
 * powerUps.c
 *
 *  Created on: 13 dic. 2024
 *      Author: ismae
 */
#include "pajaro.h"
#include "globals.h"
#include "freertosFuncs.h"
#include <stdlib.h>

estado_t tipo_power = NORMAL;
dibujo_t powerUp;

struct color power[6][9] = {
    {R,R,L,L,L,L,L,R,R},
    {R,R,R,R,L,R,R,R,R},
	{L,R,R,R,R,R,R,R,L},
	{L,L,R,R,R,R,R,L,L},
	{L,L,L,R,R,R,L,L,L},
	{L,L,L,L,R,L,L,L,L}
	};

struct color power_invencible[7][11] = {
    {L,L,L,L,L,R,R,L,L,L,L},
    {L,L,L,L,R,W,R,L,L,L,L},
    {L,L,L,R,W,W,W,R,L,L,L},
    {L,L,R,W,W,R,W,W,R,L,L},
    {L,L,L,R,W,W,W,R,L,L,L},
    {L,L,L,L,R,W,R,L,L,L,L},
    {L,L,L,L,L,R,R,L,L,L,L}
};

struct color power_double_points[7][11] = {
    {L,L,L,L,L,E,L,L,L,L,L},
    {L,L,L,L,E,E,E,L,L,L,L},
    {L,L,L,E,E,W,E,E,L,L,L},
    {L,L,E,E,W,W,W,E,E,L,L},
    {L,L,L,E,E,W,E,E,L,L,L},
    {L,L,L,L,E,E,E,L,L,L,L},
    {L,L,L,L,L,E,L,L,L,L,L}
};

void spawn_powerUp() {

	if ((rand() % 10) > 5) {
		powerUp.dibujo = power_invencible;
		tipo_power = INVENCIBLE;
	} else {
		powerUp.dibujo = power_double_points;
		tipo_power = DOBLE_P;
	}

    powerUp.posi = (struct position){pos_pajaro_x + 5, rand()%100};
    powerUp.x = 11;
    powerUp.y = 7;

    pintaImagen(&powerUp);

}

int powerUpPos = -1;
void checkPowerUpColision() {



}

#include "dibujos.h"
#include <stdio.h>
#include "tuberia.h"
#include "pajaro.h"
#include "globals.h"

int indice_tuberia = 0;

void tuberiaInit()
{
	struct position pos_ini;
	pos_ini.x = 0;
	pos_ini.y = 0;
	rect(pos_ini, fondo, 160, 120);

	for (int i = 0; i < MAX_TUBERIAS; i++) {
		tuberias[i].x = INIT;
	}
}

struct tuberia creaTuberia(int hueco_arriba, int hueco_abajo)
{
    //crear tuberia
    struct tuberia tuberia;

    tuberia.x = 160;
    tuberia.hueco_arriba = hueco_arriba;
    tuberia.hueco_abajo = hueco_abajo;

    //guarda tuberia
    tuberias[indice_tuberia % MAX_TUBERIAS] = tuberia;
    indice_tuberia++;
    return tuberia;
}

void mueveTuberias(int distancia)
{
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
        if (tuberias[i].x == INIT) continue;
        tuberias[i].x -= distancia;

        //pinta arriba
        struct position pos_ini;
        pos_ini.x = tuberias[i].x;
        pos_ini.y = 0;
        rect(pos_ini, verde, distancia, tuberias[i].hueco_arriba);
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, fondo, distancia, tuberias[i].hueco_arriba);

        //pinta abajo
        pos_ini.x = tuberias[i].x;
        pos_ini.y = tuberias[i].hueco_abajo;
        rect(pos_ini, verde, distancia, TUBE_Y);
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, fondo, distancia, TUBE_Y);
    }
    
}

int calculaColisiones()
{
    int muerto = 0;
    int actual_pos;
	actual_pos = BIRD_OFFSET - pos_pajaro_y;
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
        if (tuberias[i].x == INIT) continue;
        //calcula coordenada x coincidente
        if (tuberias[i].x <= (pos_pajaro_x + size_pajaro_x) && (tuberias[i].x + TUBE_X) >= pos_pajaro_x) {
            //calcula coordenada y coincidente
            if (tuberias[i].hueco_arriba >= actual_pos || tuberias[i].hueco_abajo <= (actual_pos + size_pajaro_y))
            {
                muerto = 1;
            }
        }
    }
    return muerto;
}

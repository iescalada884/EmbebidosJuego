#include "dibujos.h"
#include <stdio.h>
#include "tuberia.h"
#include "pajaro.h"
#include "globals.h"

int indice_tuberia = 0;
int puntuacion = 0;
void tuberiaInit()
{
	estado_pajaro = INVENCIBLE;
    puntuacion = 0;
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

void mueveTuberias()
{
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
        if (tuberias[i].x == INIT) continue;
        tuberias[i].x -= 1;

        //pinta arriba
        struct position pos_ini;
        
        pos_ini.y = 0;
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, verde_oscuro, 1, tuberias[i].hueco_arriba);
        pos_ini.x = tuberias[i].x;
        rect(pos_ini, verde_oscuro, 1, tuberias[i].hueco_arriba);
        pos_ini.x = tuberias[i].x + 1;
        rect(pos_ini, verde, 1, tuberias[i].hueco_arriba);
        
        
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X + 1;
        rect(pos_ini, fondo, 1, tuberias[i].hueco_arriba);

        //pinta abajo
        pos_ini.y = tuberias[i].hueco_abajo;
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, verde_oscuro, 1, TUBE_Y);
        pos_ini.x = tuberias[i].x;
        rect(pos_ini, verde_oscuro, 1, TUBE_Y);
        pos_ini.x = tuberias[i].x + 1;
        rect(pos_ini, verde, 1, TUBE_Y);
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X + 1;
        rect(pos_ini, fondo, 1, TUBE_Y);

        //pinta borde en el hueco
        pos_ini.x = tuberias[i].x;
        pos_ini.y = tuberias[i].hueco_arriba - 1;
        rect(pos_ini, verde_oscuro, TUBE_X, 1);
        pos_ini.y = tuberias[i].hueco_abajo;
        rect(pos_ini, verde_oscuro, TUBE_X, 1);
    }
    
}

int calculaColisiones()
{
    int muerto = 0;
    int actual_pos;
	actual_pos = BIRD_OFFSET - pos_pajaro_y;
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
    	//si acaba de pasar la tuberia suma punto
    	if ((tuberias[i].x + TUBE_X) == pos_pajaro_x + 1) {
    	    puntuacion++;
    	}
        if (tuberias[i].x == INIT || estado_pajaro == INVENCIBLE) continue;
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

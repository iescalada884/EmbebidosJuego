
#include "dibujos.h"
#include "freertosFuncs.h"
#include "pajaro.h"
#include "globals.h"


// Estructuras
struct color pajaro[size_pajaro_y][size_pajaro_x] = {
	    {L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L},
	    {L, L, L, L, L, L, L, L, J, J, J, G, G, G, G, L, L, L, L, L},
	    {L, L, L, L, L, J, J, J, H, H, H, G, W, W, W, G, L, L, L, L},
	    {L, L, L, L, J, H, H, H, H, H, G, W, W, W, W, W, G, L, L, L},
	    {L, L, L, J, J, J, H, H, H, H, G, W, W, W, G, N, W, G, L, L},
	    {G, G, G, G, G, G, J, H, H, H, G, W, W, W, G, N, W, G, L, L},
	    {G, W, W, W, W, G, G, J, H, H, H, G, W, W, G, G, W, G, L, L},
	    {G, W, W, W, W, W, G, J, H, H, H, G, G, W, W, W, W, G, L, L},
	    {G, W, W, W, W, W, G, J, H, H, H, H, K, K, K, K, K, K, K, K},
	    {G, W, W, W, W, W, G, J, H, H, H, H, K, I, I, I, I, I, I, K},
	    {L, G, W, W, W, G, J, J, H, H, K, K, I, I, I, I, I, I, I, K},
	    {L, L, G, G, G, J, H, H, H, H, K, I, K, K, K, K, K, K, K, L},
	    {L, L, L, J, J, J, H, H, H, H, H, K, I, I, I, I, I, I, K, L},
	    {L, L, L, L, L, J, J, H, H, H, H, H, K, K, K, K, K, K, L, L},
	    {L, L, L, L, L, L, J, J, J, J, J, J, J, L, L, L, L, L, L, L},
	    {L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L},
	};

struct color pajaro_frame2[size_pajaro_y][size_pajaro_x] = {
	    {L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L},
	    {L, L, L, L, L, L, L, L, J, J, J, G, G, G, G, L, L, L, L, L},
	    {L, L, L, L, L, J, J, J, H, H, H, G, W, W, W, G, L, L, L, L},
	    {L, L, L, L, J, H, H, H, H, H, G, W, W, W, W, W, G, L, L, L},
	    {L, L, L, J, J, J, H, H, H, H, G, W, W, W, G, G, W, G, L, L},
	    {L, L, L, J, J, J, J, H, H, H, G, W, W, W, G, N, W, G, L, L},
	    {L, L, L, J, J, J, J, J, H, H, H, G, W, W, G, N, W, G, L, L},
	    {G, G, G, G, G, G, G, J, H, H, H, G, G, W, W, W, W, G, L, L},
	    {G, W, W, W, W, W, G, J, H, H, H, H, K, K, K, K, K, K, K, K},
	    {G, W, W, W, W, W, G, J, H, H, H, H, K, I, I, I, I, I, I, K},
	    {L, G, W, W, W, G, J, J, H, H, K, K, I, I, I, I, I, I, I, K},
	    {L, L, G, G, G, J, H, H, H, H, K, I, K, K, K, K, K, K, K, L},
	    {L, L, L, J, J, J, H, H, H, H, H, K, I, I, I, I, I, I, K, L},
	    {L, L, L, L, L, J, J, H, H, H, H, H, K, K, K, K, K, K, L, L},
	    {L, L, L, L, L, L, J, J, J, J, J, J, J, L, L, L, L, L, L, L},
	    {L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L, L},
	};

// globales del pajaro
int pos_pajaro_y = 50;
int pos_pajaro_x = 50;
estado_t estado_pajaro = NORMAL;

// Globales moviento
int objetivo = 50;
int lastImput = 70; // Ultimo valor leido por el sensor de distancia

void init_bird() {
	pos_pajaro_y = 50;
	pos_pajaro_x = 50;
	objetivo = 50;
	lastImput = 70; // Ultimo valor leido por el sensor de distancia
	estado_pajaro = NORMAL;
}

enum posOjo {RECTO, ARRIBA, ABAJO};
void setEye(enum posOjo ojo, struct color* pajaro) {
	switch(ojo) {
	case RECTO:
			pajaro[size_pajaro_x * 4 + 14] = gris;
			pajaro[size_pajaro_x * 4 + 16] = gris;
			pajaro[size_pajaro_x * 4 + 15] = gris;
			pajaro[size_pajaro_x * 5 + 15] = negro;
			pajaro[size_pajaro_x * 6 + 15] = negro;
			pajaro[size_pajaro_x * 6 + 14] = gris;

		break;
	case ARRIBA:
			pajaro[size_pajaro_x * 4 + 14] = negro;
			pajaro[size_pajaro_x * 4 + 15] = negro;
			pajaro[size_pajaro_x * 5 + 15] = negro;
			pajaro[size_pajaro_x * 6 + 15] = gris;
			pajaro[size_pajaro_x * 6 + 14] = gris;

		break;
	case ABAJO:
			pajaro[size_pajaro_x * 4 + 14] = gris;
			pajaro[size_pajaro_x * 4 + 15] = gris;
			pajaro[size_pajaro_x * 5 + 15] = gris;
			pajaro[size_pajaro_x * 6 + 15] = gris;
			pajaro[size_pajaro_x * 6 + 14] = negro;
			pajaro[size_pajaro_x * 5 + 15] = negro;
			pajaro[size_pajaro_x * 6 + 15] = negro;

		break;
	}
}

int updateBirdPos(dibujo_t * pajaro) {
	int *sensor = (int *) SENSOR_BASE;
	int pos = sensor[0];

	if (pos > lastImput + DETECTION_RANGE || pos < lastImput - DETECTION_RANGE) {
		if (pos > MAX_HEIGTH) objetivo = MAX_HEIGTH;
		else if (pos < MIN_HEIGTH) objetivo = MIN_HEIGTH;
		else objetivo = pos;
	}


	// Moviento por tick (VA AL REVES POR EL SENSOR :) )
	if (objetivo > pos_pajaro_y) {
		pos_pajaro_y += VELOCIDAD;
		setEye(ARRIBA, pajaro->dibujo);
	} else if (objetivo < pos_pajaro_y) {
		pos_pajaro_y -= VELOCIDAD;
		setEye(ABAJO, pajaro->dibujo);

	} else {
		setEye(RECTO, pajaro->dibujo);
	}

	lastImput = pos;

	return pos_pajaro_y;
}



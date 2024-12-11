#include <stdio.h>
#include "main.h"

typedef struct tuberia{
    int hueco_arriba, hueco_abajo;
    int x;
};

#define TUBE_Y 120
#define TUBE_X 26
#define MAX_TUBERIAS 5
#define INIT -999
struct tuberia tuberias[MAX_TUBERIAS];

struct tuberia creaTuberia(int hueco_arriba, int hueco_abajo);

void mueveTuberias(int distancia);
int calculaColisiones();
void tuberiaInit();

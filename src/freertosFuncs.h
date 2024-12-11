#ifdef FREERTOSFUNCS_H
#define FREERTOSFUNCS_H


/**
 * @brief Envía un dibujo a la interfaz correspondiente.
 *
 * Esta función toma un puntero a una estructura de tipo dibujo_t y lo envía
 * para ser procesado o mostrado en la interfaz correspondiente.
 *
 * @param dibujo Puntero a la estructura dibujo_t que contiene la información
 *               del dibujo a enviar.
 */

void enviaDibujo(dibujo_t *dibujo);

#endif
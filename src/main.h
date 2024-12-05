#ifndef __MAIN_H__
#define __MAIN_H__

#define VGA_CTRL_BASE 0x44A00000

struct position {
	int x, y;
};
struct color {
	unsigned char r, g, b;
};

#define A {0x00, 0x00, 0xf0}
#define AC {0xCC, 0xFF, 0xFF}
#define G {0xE0, 0xE0, 0xE0}
#define B {0x00, 0x00, 0x80}
#define C {0x00, 0x80, 0x00}
#define D {0x00, 0xf0, 0x00}
#define E {0xf0, 0xf0, 0x00}
#define F {0xf0, 0x00, 0x00}
#define W {0xff,0xff,0xff}
#define N {0,0,0}

static const struct color negro = N;
static const struct color azul_claro = AC;
static const struct color gris = G;
static const struct color blanco = W;
static const struct color azul = A;
static const struct color azul_oscuro = B;
static const struct color verde = C;
static const struct color verde_oscuro = D;
static const struct color amarillo = E;
static const struct color rojo = F;

extern struct color nave[32][32];
/*
	    {N,N,N,N,N,N,G,G,G,G,G,G,G,G,N,N,N,N, N},
		{N,N,N,N,G,G,AC,AC,AC,AC,AC,G,W,W,G,N,N,N,N},
		{N,N,N,G,AC,AC,A,A,A,A,G,W,W,W,W,G,N,N,N},
		{N,N,G,AC,A,A,A,A,A,A,G,W,W,W,G,W,G,N,N},
		{N,G,A,A,A,A,A,A,A,A,G,W,W,W,G,W,G,N,N},
		{N,G,G,G,G,G,A,A,A,A,A,G,W,W,W,W,G,N,N},
		{G,AC,AC,AC,AC,AC,G,A,A,A,A,A,G,G,G,G,G,G,N},
		{G,A,AC,AC,AC,A,G,A,A,A,A,G,F,F,F,F,F,F,G},
		{N,G,G,G,G,G,B,B,B,A,A,A},
		{A,E,F,E,A,A,A,E,F,E,A},
		{N,N,E,N,N,N,N,N,E,N,N}

};*/

typedef struct dibujo{
	struct color * dibujo;
	int x, y;
	struct position posi;
} dibujo_t;

// Funci�n que pinta un pixel en pantalla
// X entre 0 y 159, Y entre 0 y 119,
// R/G/B: colores - entre 0 y 255 (los cuatro bits menos significativos se ignoran)
void pinta(int x, int y, struct color rgb);

// Funci�n que retorna el valor de un pixel en pantalla
struct color pixel(int x, int y);

// Funci�n que pinta un rect�ngulo de un color
// Pos: esquina superior izquierda del rectangulo
// Color: color del rect�ngulo
// W: anchura, H: altura
void rect (struct position pos, struct color col, int w, int h);


// Funci�n que pinta una imagen en la VGA.
// Solo pinta los puntos que no son de color alfa (en este caso, negro), que se quedan "transparentes".
void imagen_11x11(struct position pos, struct color img[32][32]);


// Mueve la n�ve autom�ticamente de derecha a izquierda o viceversa
// El procedimiento para mover la nave es:
//        borrar la nave de pantalla, calcular la nueva posici�n, pintar la nave
void mueve_nave();

// Inicializa una bala en la posici�n X
void lanza_bala(int x);

// Mueve la bala, en vertical, hasta y = 0. Cuando llega ah� la desactiva
void mueve_bala();

int mainP();

void pintaImagen(dibujo_t *imagen);
#endif

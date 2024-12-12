#ifndef __DIBUJOS_H__
#define __DIBUJOS_H__

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
#define L {0x47, 0xdd, 0xed}
#define H {0x00, 0xbf, 0xd7}
#define I {0xaa, 0x2d, 0x24}
#define J {0x08, 0x76, 0x94}
#define K {0x34, 0x0E, 0x0C}

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
static const struct color fondo = L;

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

void pintaImagen(dibujo_t *imagen);

void getBackground (int x, int y, struct position * posi,  struct color  * background);
#endif

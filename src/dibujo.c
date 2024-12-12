#include "dibujos.h"
#include <stdio.h>
#include <sleep.h>

struct color amar = {255,255,0};

#define x_max = 160;
#define y_max = 120;

void pinta(int x, int y, struct color rgb){
	int *ptr = (int *)VGA_CTRL_BASE;
	int val = (rgb.r>>4) | (rgb.b&0xf0) | ((rgb.g&0xf0)<<4);
	ptr[(y<<8)| x]=val;
}

struct color pixel(int x, int y){
	struct color col;
	int *ptr = (int*) VGA_CTRL_BASE;
	int val = ptr[(y<<8) | x];
	col.r = (val&0xf)<<4;
	col.b = (val&0xf0);
	col.g = (val&0xf00)>>4;
	return col;
}

void rect (struct position pos, struct color col, int w, int h){
	int i,j;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			pinta(pos.x+i,pos.y+j,col);
		}
	}
}

void pintaImagen(dibujo_t *imagen){
	int i,j;
	struct color alfa = amar;
	struct color *img = imagen->dibujo;

	for(i=0;i<imagen->y;i++){
		for(j=0;j<imagen->x;j++){
			 int index = i * imagen->x + j;  // C�lculo do �ndice plano

			        // Acessa a cor do pixel usando o �ndice plano
			        if(img[index].r == alfa.r && img[index].g == alfa.g && img[index].b == alfa.b)
			            continue;
			        else
			            pinta(imagen->posi.x + j, imagen->posi.y + i, img[index]);
		}
	}
}

void getBackground (int x, int y, struct position * posi,  struct color  * background) {
	int *ptr = (int *)VGA_CTRL_BASE;

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			int index = i * x + j;
			int val = ptr[(posi->y + i <<8) | posi->y + j];

			struct color pix;
			pix.r = (val & 0x0F) << 4;
			pix.g = (val >> 4) & 0xF0;
			pix.b = val & 0xF0;
			background[index] = pix;
		}
	}

}

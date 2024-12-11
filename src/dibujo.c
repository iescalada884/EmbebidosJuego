#include <stdio.h>
#include <sleep.h>
#include "main.h"

struct color amar = {255,255,0};
static struct position pos_nave={30,90};
struct position pos_bala;
int bala_activa=0;

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

void imagen_11x11(struct position pos, struct color img[32][32]){
	int i,j;
	struct color alfa = negro;
	for(i=0;i<32;i++){
		for(j=0;j<32;j++){
			if(img[j][i].r==alfa.r && img[j][i].g==alfa.g && img[j][i].b==alfa.b) continue;
			else pinta(pos.x+i, pos.y+j, img[j][i]);
		}
	}
}

void mueve_nave(){
	static int var=1;
	rect(pos_nave,negro,33,33);
	pos_nave.x = pos_nave.x + var;
	if(pos_nave.x==150) var=-1;
	if(pos_nave.x==30) var=1;
	imagen_11x11(pos_nave,nave);
}

void mueve_vertical(int vel) {
	static int inc = -1;
	rect(pos_nave,negro,33,33);
	pos_nave.y = pos_nave.y + inc * vel;

	if(pos_nave.y==120) inc=-1;
	if(pos_nave.y==30) inc=1;
	imagen_11x11(pos_nave,nave);
}

void lanza_bala(int x){
	pos_bala.x=x;
	pos_bala.y=89;
	bala_activa=1;
	pinta(pos_bala.x,pos_bala.y,blanco);
}

void mueve_bala(){
	if(bala_activa==0) return;
	pinta(pos_bala.x,pos_bala.y,negro);
	pos_bala.y = pos_bala.y - 1;
	if(pos_bala.y==0) bala_activa = 0;
	else pinta(pos_bala.x,pos_bala.y,blanco);
}

int mainP(){
	int i,j, count1=0;

    xil_printf("Arranca\n\r");

	// Pinta el fondo negro. Se puede reemplazar por una llamada a rect
    for(i=0;i<160;i++)
    	for(j=0;j<120;j++)
    		pinta(i,j,negro);

    while(1){
    	// una de cada 5 veces, mueve la nave en el eje X
    	if(count1==5){
    		count1=0;
    		mueve_vertical(1);
    		if(pos_nave.x==80) lanza_bala(85); // Cada vez que pasa por la posici�n x=80 dispara
    	}else count1++;
    	// Mueve la bala cada vuelta del ciclo. La bala va 5 veces m�s r�pido que la nave.
    	mueve_bala();
    	usleep(10000);
    }

	return 0;
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

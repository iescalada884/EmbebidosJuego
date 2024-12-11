#include <stdio.h>
#include <sleep.h>
#include "main.h"

struct color nave[18][20]=
{
	 {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 5, 5}, {0, 35, 38}, {0, 36, 41}, {0, 35, 40}, {0, 49, 55}, {0, 164, 184}, {0, 170, 192}, {16, 111, 123}, {84, 84, 84}, {240, 239, 239}, {255, 255, 255}, {148, 148, 148}, {42, 42, 42}, {5, 5, 5}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 5, 6}, {0, 121, 137}, {0, 173, 196}, {0, 176, 198}, {0, 177, 199}, {0, 186, 210}, {0, 75, 85}, {90, 94, 95}, {241, 241, 241}, {254, 254, 254}, {255, 255, 255}, {243, 243, 243}, {168, 168, 168}, {20, 20, 20}, {6, 6, 6}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 26, 29}, {0, 113, 128}, {0, 192, 217}, {0, 189, 213}, {0, 188, 212}, {0, 66, 75}, {97, 93, 92}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {150, 150, 150}, {95, 95, 95}, {178, 178, 178}, {35, 35, 35}, {0, 0, 0}, {0, 0, 0}}, {{100, 100, 100}, {140, 140, 140}, {139, 139, 139}, {141, 141, 141}, {143, 140, 140}, {71, 108, 113}, {0, 107, 121}, {0, 187, 211}, {0, 189, 213}, {0, 64, 73}, {98, 93, 92}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {115, 115, 115}, {64, 64, 64}, {226, 226, 226}, {37, 37, 37}, {0, 0, 0}, {0, 0, 0}}, {{151, 150, 150}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {175, 170, 170}, {59, 87, 91}, {3, 132, 149}, {0, 178, 201}, {0, 106, 120}, {65, 99, 103}, {189, 188, 188}, {250, 250, 250}, {255, 255, 255}, {163, 163, 163}, {129, 129, 129}, {227, 227, 227}, {37, 37, 37}, {0, 0, 0}, {0, 0, 0}}, {{130, 143, 145}, {239, 254, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {242, 253, 254}, {165, 182, 184}, {8, 27, 29}, {0, 157, 177}, {0, 191, 215}, {0, 123, 139}, {41, 60, 62}, {206, 208, 208}, {225, 225, 225}, {222, 222, 222}, {223, 223, 223}, {201, 202, 202}, {32, 32, 32}, {0, 0, 0}, {0, 0, 0}}, {{14, 112, 124}, {107, 217, 231}, {250, 254, 254}, {251, 254, 254}, {254, 255, 255}, {145, 228, 238}, {20, 144, 160}, {1, 25, 28}, {0, 157, 177}, {0, 191, 215}, {0, 180, 203}, {6, 140, 158}, {32, 42, 44}, {35, 31, 31}, {35, 32, 32}, {35, 32, 32}, {31, 29, 28}, {8, 5, 5}, {4, 1, 1}, {4, 2, 2}}, {{0, 42, 49}, {25, 109, 120}, {79, 211, 228}, {79, 212, 229}, {80, 214, 231}, {40, 136, 147}, {0, 73, 81}, {0, 133, 149}, {0, 180, 202}, {0, 194, 218}, {0, 141, 160}, {25, 57, 62}, {156, 46, 39}, {171, 45, 36}, {170, 45, 36}, {170, 45, 36}, {170, 45, 36}, {172, 47, 38}, {173, 48, 38}, {113, 31, 25}}, {{0, 0, 0}, {0, 46, 53}, {0, 102, 116}, {0, 102, 114}, {0, 103, 115}, {11, 67, 95}, {29, 60, 108}, {28, 139, 197}, {28, 141, 199}, {8, 118, 148}, {41, 74, 78}, {116, 29, 23}, {134, 36, 29}, {136, 37, 30}, {136, 37, 30}, {136, 37, 30}, {136, 37, 30}, {136, 37, 30}, {139, 38, 31}, {99, 26, 22}}, {{0, 0, 0}, {0, 0, 0}, {2, 1, 4}, {13, 15, 34}, {13, 15, 37}, {38, 48, 108}, {64, 82, 184}, {64, 80, 181}, {64, 80, 181}, {30, 40, 92}, {82, 29, 37}, {169, 46, 37}, {64, 17, 14}, {52, 14, 11}, {52, 14, 12}, {52, 14, 12}, {52, 14, 12}, {52, 14, 12}, {16, 4, 4}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {7, 11, 23}, {51, 65, 145}, {56, 72, 161}, {59, 76, 170}, {63, 81, 181}, {63, 81, 181}, {63, 81, 181}, {62, 80, 178}, {41, 51, 112}, {50, 17, 20}, {200, 55, 45}, {217, 60, 48}, {216, 59, 48}, {216, 59, 48}, {216, 59, 48}, {215, 59, 48}, {76, 21, 17}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {7, 7, 16}, {12, 15, 35}, {12, 15, 33}, {37, 47, 106}, {64, 82, 184}, {63, 81, 182}, {63, 81, 182}, {64, 82, 183}, {59, 76, 171}, {50, 57, 124}, {48, 17, 22}, {47, 13, 10}, {48, 13, 11}, {48, 13, 11}, {48, 13, 11}, {47, 13, 11}, {36, 8, 8}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {17, 21, 48}, {26, 33, 74}, {25, 33, 73}, {25, 33, 73}, {25, 33, 73}, {26, 33, 74}, {24, 31, 70}, {0, 4, 13}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

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

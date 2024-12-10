
struct color {
	unsigned char r, g, b;
};

struct position {
	int x, y;
};

typedef struct tuberia{
    int hueco_ini, hueco_fin;
    int x;
};

#define A {0x00, 0x00, 0xf0}
#define B {0x00, 0x00, 0x80}
#define C {0x00, 0x80, 0x00}
#define D {0x00, 0xf0, 0x00}
#define E {0xf0, 0xf0, 0x00}
#define F {0xf0, 0x00, 0x00}
#define W {0xff,0xff,0xff}
#define N {0,0,0}
#define M {0xff,0x00, 0xff}
#define V {0x00,0xff,0x00}

static const struct color verde = V;
static const struct color negro = N;
static const struct color alfa = M;

struct color image_tuberia[120][26] = 
{
    {N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N}};

#define TUBE_Y 120
#define TUBE_X 26
#define MAX_TUBERIAS 10
struct tuberia tuberias[MAX_TUBERIAS];
int indice_tuberia = 0;

int pos_pajaro_x;
int pos_pajaro_y;
int size_pajaro_x;
int size_pajaro_y;

struct tuberia creaTuberia(int hueco_ini, int hueco_fin)
{
    //crear tuberia
    struct tuberia tuberia;

    tuberia.x = 160;
    tuberia.hueco_ini = hueco_ini;
    tuberia.hueco_fin = hueco_fin;

    //guarda tuberia
    tuberias[indice_tuberia % MAX_TUBERIAS] = tuberia;
    indice_tuberia++;
    return tuberia;
}

void mueveTuberias(int distancia)
{
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
        tuberias[i].x -= distancia;

        //pinta arriba
        struct position pos_ini;
        pos_ini.x = tuberias[i].x;
        pos_ini.y = 0;
        rect(pos_ini, verde, distancia, tuberias[i].hueco_ini);
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, negro, distancia, tuberias[i].hueco_ini);

        //pinta abajo
        struct position pos_ini;
        pos_ini.x = tuberias[i].x;
        pos_ini.y = tuberias[i].hueco_fin;
        rect(pos_ini, verde, distancia, TUBE_Y);
        
        //despinta lo antiguo
        pos_ini.x = tuberias[i].x + TUBE_X;
        rect(pos_ini, negro, distancia, TUBE_Y);
    }
    
}

int calculaColisiones()
{
    int muerto = 0;
    for (int i = 0; i < MAX_TUBERIAS; i++)
    {
        //calcula coordenada x coincidente
        if (tuberias[i].x >= pos_pajaro_x + size_pajaro_x && tuberias[i].x + TUBE_X <= pos_pajaro_x) {
            //calcula coordenada y coincidente
            if (tuberias[i].hueco_ini >= pos_pajaro_y || tuberias[i].hueco_fin <= pos_pajaro_y + size_pajaro_y)
            {
                muerto = 1;
            }
        }
    }
    return muerto;
}

void pinta(int x, int y, struct color rgb){
	int *ptr = (int *)VGA_CTRL_BASE;
	int val = (rgb.r>>4) | (rgb.b&0xf0) | ((rgb.g&0xf0)<<4);
	ptr[(y<<8)| x]=val;
}

void rect (struct position pos, struct color col, int w, int h){
	int i,j;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			pinta(pos.x+i,pos.y+j,col);
		}
	}
}

#include "miniwin.h"
using namespace miniwin;
#include <string.h>
using namespace std;

char ImprimirLetra(){
	int t=tecla();
	if(t==int('a')){
		return('a');
	}
}

struct BaseDeDatos{
	int id;
	char usuario[14];
	char password[14];
	bool Played;
	int Wins;
};

class Boton{
	private:
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
		bool pressed;
		char text[100];
	public:
		Boton(int,int,int,int);
		Boton(int,int,int,int,bool);	
		Boton(int,int,int,int,bool,char[100]);
		void Press(bool);
		void DibujaBoton();
		void DibujaBotonRelleno();
		void DibujaBotonRellenoTexto();
		void DibujaBotonRellenoTexto2();
		void DibujaBotonRellenoTexto3();
		void DibujaBoton2RellenoTexto();
		void DibujaBotonVacio();
		void mouse(bool);
};

Boton::Boton(int posx,int posy, int sizex, int sizey){
	pos_x=posx;
	pos_y=posy;
	size_x=sizex;
	size_y=sizey;
}

Boton::Boton(int posx,int posy, int sizex, int sizey, bool p){
	pos_x=posx;
	pos_y=posy;
	size_x=sizex;
	size_y=sizey;
	pressed=p;
}

Boton::Boton(int posx,int posy, int sizex, int sizey, bool p, char t[100]){
	pos_x=posx;
	pos_y=posy;
	size_x=sizex;
	size_y=sizey;
	pressed=p;
	strcpy(text,t);
}

void Boton::Press(bool p){
	pressed=p;
}

void Boton::DibujaBoton(){
	if(pressed==0){
		color_rgb(100,100,100);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(NEGRO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
	}else{
		color(NEGRO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color_rgb(100,100,100);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
	}
}

void Boton::DibujaBotonRelleno(){
	if(pressed==0){
		color_rgb(100,100,100);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		refresca();
		color(NEGRO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		refresca();
		rectangulo_lleno(pos_x,pos_y,pos_x+size_x,pos_y+size_y);
		refresca();
	}else{
		color(NEGRO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color_rgb(100,100,100);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		rectangulo_lleno(pos_x,pos_y,pos_x+size_x,pos_y+size_y);
		refresca();
	}
}

void Boton::DibujaBotonRellenoTexto(){
	if(pressed==0){
		color(BLANCO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(NEGRO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color_rgb(100,100,100);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color(BLANCO);
		texto(pos_x+20,pos_y+7,text);
	}else{
		color(NEGRO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(BLANCO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color_rgb(100,100,100);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color(NEGRO);
		texto(pos_x+20,pos_y+7,text);
	}
}

void Boton::DibujaBotonRellenoTexto2(){
	if(pressed==0){
		color(BLANCO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(NEGRO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color_rgb(100,100,100);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color(BLANCO);
		texto(pos_x+10,pos_y+3,text);
	}else{
		color(NEGRO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(BLANCO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color_rgb(100,100,100);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color(NEGRO);
		texto(pos_x+10,pos_y+3,text);
	}
}

void Boton::DibujaBoton2RellenoTexto(){
	if(pressed==0){
		color(BLANCO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(BLANCO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color(NEGRO);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color(BLANCO);
		texto(pos_x+20,pos_y+7,text);
	}else{
		color_rgb(100,100,100);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color_rgb(100,100,100);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color(NEGRO);
		rectangulo_lleno(pos_x+4,pos_y+4,pos_x+size_x-4,pos_y+size_y-4);
		color_rgb(100,100,100);
		texto(pos_x+20,pos_y+7,text);
	}
}

void Boton::DibujaBotonRellenoTexto3(){
	if(pressed==0){
		color(NEGRO);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color(NEGRO);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color(NEGRO);
		rectangulo_lleno(pos_x+1,pos_y+1,pos_x+size_x-1,pos_y+size_y-1);
		color(BLANCO);
		texto(pos_x+10,pos_y+3,text);
	}else{
		color_rgb(100,100,100);
		linea(pos_x,pos_y,pos_x+size_x,pos_y);
		linea(pos_x,pos_y,pos_x,pos_y+size_y);
		color_rgb(100,100,100);
		linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
		linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
		color_rgb(100,100,100);
		rectangulo_lleno(pos_x+1,pos_y+1,pos_x+size_x-1,pos_y+size_y-1);
		color(NEGRO);
		texto(pos_x+10,pos_y+3,text);
	}
}

void Boton::DibujaBotonVacio(){
	color(NEGRO);
	linea(pos_x,pos_y,pos_x+size_x,pos_y);
	linea(pos_x,pos_y,pos_x,pos_y+size_y);
	linea(pos_x,pos_y+size_y,pos_x+size_x,pos_y+size_y);
	linea(pos_x+size_x,pos_y,pos_x+size_x,pos_y+size_y);
	color(BLANCO);
	rectangulo_lleno(pos_x+1,pos_y+1,pos_x+size_x-1,pos_y+size_y-1);
}

char NumeroTexto(int a){
	char b;
	if(a==10){
		a=0;
	}
	if(a>10){
		a=a-10;	
	}
	switch(a){
		case 0:b='0';break;
		case 1:b='1';break;
		case 2:b='2';break;
		case 3:b='3';break;
		case 4:b='4';break;
		case 5:b='5';break;
		case 6:b='6';break;
		case 7:b='7';break;
		case 8:b='8';break;
		case 9:b='9';break;
	}
	return b;
}

int TextoNumero(char a[]){
	int b;
	int c=0;
	if(a[0]=='0'){
		b=0;
	}
	if(a[0]=='1'){
		b=1;
	}
	if(a[0]=='2'){
		b=2;
	}
	if(a[0]=='3'){
		b=3;
	}
	if(a[0]=='4'){
		b=4;
	}
	if(a[0]=='5'){
		b=5;
	}if(a[0]=='6'){
		b=6;
	}
	if(a[0]=='7'){
		b=7;
	}
	if(a[0]=='8'){
		b=8;
	}
	if(a[0]=='9'){
		b=9;
	}
	if(a[1]!='\0'){
		c=b*10;
		b=0;
		if(a[1]=='1'){
			b=1;
		}
		if(a[1]=='2'){
			b=2;
		}
		if(a[1]=='3'){
			b=3;
		}
		if(a[1]=='4'){
			b=4;
		}
		if(a[1]=='5'){
			b=5;
		}if(a[1]=='6'){
			b=6;
		}
		if(a[1]=='7'){
			b=7;
		}
		if(a[1]=='8'){
			b=8;
		}
		if(a[1]=='9'){
			b=9;
		}
	}
	b=b+c;
	return b;
}






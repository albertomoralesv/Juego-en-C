#include "miniwin.h"
using namespace miniwin;
#include <string.h>

class Boton2{
	private:
		int posx;
		int posy;
		int sizex;
		int sizey;
		bool pressed;
		char text[100];
		bool Visible;
		bool Activo;
	public:
		Boton2();
		Boton2(int,int,int,int);
		Boton2(int,int,int,int,bool);
		Boton2(int,int,int,int,bool,char[100]);
		void Set(int,int,int,int,bool,char[100]);
		void SetPosx(int);
		void SetPosy(int);
		void SetSizex(int);
		void SetSizey(int);
		void Press(bool);
		void SetText(char[100]);
		void Vis(bool);
		void Activar(bool);
		int GetPosy();
		bool GetActivo();
		void DibujaBotonVacio();
		void DibujaBotonVacioTexto();
		void DibujaBotonRellenoNegro();
		void DibujaBotonRellenoBlanco();
		void DibujaBotonRellenoNegroTexto();
		void DibujaBotonRellenoBlancoTexto();
		void BorrarBoton();
};

Boton2::Boton2(){
	
}
Boton2::Boton2(int a,int b,int c,int d){
	posx=a;
	posy=b;
	sizex=c;
	sizey=d;
	pressed=0;
}
Boton2::Boton2(int a,int b,int c,int d,bool e){
	posx=a;
	posy=b;
	sizex=c;
	sizey=d;
	pressed=e;
}
Boton2::Boton2(int a,int b,int c,int d,bool e,char f[100]){
	posx=a;
	posy=b;
	sizex=c;
	sizey=d;
	pressed=e;
	strcpy(text,f);
}

void Boton2::Set(int a,int b,int c,int d,bool e,char f[100]){
	posx=a;
	posy=b;
	sizex=c;
	sizey=d;
	pressed=e;
	strcpy(text,f);
}
void Boton2::SetPosx(int a){
	posx=a;
}
void Boton2::SetPosy(int b){
	posy=b;
}
void Boton2::SetSizex(int c){
	sizex=c;
}
void Boton2::SetSizey(int d){
	sizey=d;
}
void Boton2::Press(bool e){
	pressed=e;
}
void Boton2::SetText(char f[100]){
	strcpy(text,f);
}
void Boton2::Vis(bool g){
	Visible=g;
}
void Boton2::Activar(bool h){
	Activo=h;
}
int Boton2::GetPosy(){
	int i=posy;
	return i;
}
bool Boton2::GetActivo(){
	bool j=Activo;
	return j;
}

void Boton2::DibujaBotonVacio(){
	if(pressed){
		color_rgb(100,100,100);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
	}else{
		color(NEGRO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);	
	}
}
void Boton2::DibujaBotonVacioTexto(){
	if(Visible==0){
		if(pressed){
			color_rgb(100,100,100);
			rectangulo(posx,posy,posx+sizex,posy+sizey);
			texto(posx+5,(posy+(sizey/3)),text);
		}else{
			color(NEGRO);
			rectangulo(posx,posy,posx+sizex,posy+sizey);
			texto(posx+5,(posy+(sizey/3)),text);	
		}	
	}else{
		color(BLANCO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
		texto(posx+5,(posy+(sizey/3)),text);
	}
	
	
}

void Boton2::DibujaBotonRellenoNegro(){
	if(pressed){
		color_rgb(100,100,100);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(NEGRO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
	}else{
		color(NEGRO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(BLANCO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
	}
}
void Boton2::DibujaBotonRellenoBlanco(){
	if(pressed){
		color(BLANCO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color_rgb(100,100,100);
		rectangulo(posx,posy,posx+sizex,posy+sizey);	
	}else{
		color(BLANCO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(NEGRO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
	}
}
void Boton2::DibujaBotonRellenoNegroTexto(){
	if(pressed){
		color_rgb(100,100,100);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(NEGRO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
		texto(posx+15,posy+(sizey/3),text);
	}else{
		color(NEGRO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(BLANCO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
		texto(posx+15,posy+(sizey/3),text);
	}
}
void Boton2::DibujaBotonRellenoBlancoTexto(){
	if(pressed){
		color(BLANCO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color_rgb(100,100,100);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
		texto(posx+5,posy+(sizey/3),text);	
	}else{
		color(BLANCO);
		rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
		color(NEGRO);
		rectangulo(posx,posy,posx+sizex,posy+sizey);
		texto(posx+5,posy+(sizey/3),text);	
	}
	
}

void Boton2::BorrarBoton(){
	color(BLANCO);
	rectangulo_lleno(posx-2,posy-2,posx+sizex+2,posy+sizey+2);
}


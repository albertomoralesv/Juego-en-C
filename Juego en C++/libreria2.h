#include <stdio.h>
#include <string.h>
#include "miniwin.h"
#include "Botones.h"
using namespace std;
using namespace miniwin;


int Estado=0;
int np=0,nv=3;
char pts[5];
char vds[3];
char palabras[15][100]={"LAGO","PERRO","CARRO","AIRE","SOL","LLAVE","CARTA","BANCO","LIEBRE","PALA","FOCO","CAMA","ARBOL","MESA"};
Boton2 BotonesP[15];
bool salir=1;
int z=0;
int z2=1;
int l=0;
int l2=0;
int level=1;

char JUGAR[100]="Jugar";
Boton2 BotonEmpezar(150,150,80,30,0,JUGAR);
char NIVEL[100]="Nivel: 1";
Boton2 BotonNivel(150,200,80,30,0,NIVEL);
char NIVEL1[100]="Nivel: 1";
Boton2 BotonNivel1(150,200,80,30,0,NIVEL1);
char NIVEL2[100]="Nivel: 2";
Boton2 BotonNivel2(150,230,80,30,0,NIVEL2);
char NIVEL3[100]="Nivel: 3";
Boton2 BotonNivel3(150,260,80,30,0,NIVEL3);
void PantallaJuego();
void FondoJuego();
bool BotonStart();
bool MouseBStart(int,int);
void JuegoEnCurso();
char NumeroTexto2(int);
void ChecarPalabra(char[100]);
void CrearBotonesPalabras();
int Juego();
void SeleccionarNivel();
void DibujarBotonesNivel(int);
int PosRatonNivel(int,int);
void JuegoEnCurso2();
void JuegoEnCurso3();
void ChecarPalabra2(char[100]);
void ChecarPalabra3(char[100]);

int Juego(){
	BotonEmpezar.Press(0);
	bool s=1;
	bool START=0;
	borra();
	refresca();
	espera(2);
	PantallaJuego();
	while(s){
		espera(2);
		SeleccionarNivel();
		refresca();
		espera(10);
		PantallaJuego();
		espera(2);
		refresca();
		START=BotonStart();
		if(START==1){
			s=0;
			BotonEmpezar.Press(1);
			BotonEmpezar.DibujaBotonRellenoNegroTexto();
			refresca();
			espera(1000);
			BotonEmpezar.BorrarBoton();	
			refresca();
			espera(2);
		}
	}
	if(START){
		if(level==1){
			JuegoEnCurso();
		}else if(level==2){
			JuegoEnCurso2();
		}else if(level==3){
			JuegoEnCurso3();
		}
		
	}
	return Estado;
}

void PantallaJuego(){
	vredimensiona(400,400);
	color(BLANCO);
	rectangulo_lleno(10,10,390,390);
	//refresca();
	espera(2);
	color(NEGRO);
	linea(10,40,390,40);
	//refresca();
	espera(2);
	linea(10,360,390,360);
	//refresca();
	espera(2);
	texto(15,20,"-->");
	texto(15,370,"Puntos: ****");
	texto(120,370,"Vidas: 0");
	//refresca();
	espera(2);
	BotonEmpezar.DibujaBotonRellenoNegroTexto();
	//refresca();
	espera(2);
	BotonNivel.DibujaBotonRellenoBlancoTexto();
	//refresca();
	espera(2);
}

void FondoJuego(){
	color(BLANCO);
	rectangulo_lleno(10,10,390,390);
	color(NEGRO);
	linea(10,40,390,40);
	linea(10,360,390,360);
	texto(15,20,"-->");
	texto(15,370,"Puntos: ");
	texto(120,370,"Vidas: ");
}

bool BotonStart(){
	bool s=0;
	bool b;
	int x,y;
	x=raton_x();
	y=raton_y();
	b=MouseBStart(x,y);
	if(b&&raton_boton_izq()){
		s=1;
	}
	return s;
}

bool MouseBStart(int x, int y){
	bool b;
	if(x>150&&x<230&&y>150&&y<180){
		b=1;
	}else{
		b=0;
	}
	return b;
}

void JuegoEnCurso(){
	z=0;
	l=0;
	nv=3;
	np=0;
	salir=1;
	bool m=0;
	int s=1;
	int n=0;
	char t;
	char cadena[100]="\0";
	while(tecla()!=NINGUNA);
	espera(2);
	while(salir){		
		//Bajar Vidas
		char c=NumeroTexto2(nv);
		vds[0]=c;
		vds[1]='\0';
		//
		if(nv==0){
			mensaje("Perdiste");
			Estado=0;
			salir=0;
		}
		//Subir Puntos
		char c2=NumeroTexto2(np);
		if(np==10){
			m++;
		}
		if(m==0){
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='\0';	
		}else{
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='0';
			pts[4]='\0';
		}
		//
		FondoJuego();
		//Palabras Cayendo
		CrearBotonesPalabras();
		BotonesP[z].Vis(0);
		BotonesP[z].SetPosy(40+(8*l));
		espera(2);
		if(BotonesP[z].GetPosy()>=340){
			mensaje("Pierdes 1 vida");
			nv--;
			z++;
			l=0;
			espera(1000);
		}
		if(m==1&&pts[0]=='1'||nv==0){
			
		}else{
			BotonesP[z].DibujaBotonVacioTexto();	
		}
		
		if(BotonesP[z].GetPosy()>40&&BotonesP[z].GetPosy()<360){
			BotonesP[z].Activar(1);
		}else{
			BotonesP[z].Activar(0);
		}
		//
		//Ingresar Palabras
		texto(70,370,pts);
		texto(165,370,vds);
		espera(50);
		t=tecla();
		if(t!=NINGUNA&&t!=RETURN&&t!=' '){
			cadena[n]=t;
			n++;
			cadena[n]='\0';
		}
		espera(50);
		if(t==RETURN){
			ChecarPalabra(cadena);
			cadena[0]='\0';
			n=0;
			
		}
		color(NEGRO);
		texto(35,20,cadena);
		refresca();
		espera(2);
		//
		l++;
		if(m==1&&pts[0]=='1'){
			mensaje("Ganaste");
			salir=0;
			Estado=1;
		}
	}
}

char NumeroTexto2(int a){
	char b;
	if(a==10){
		a=1;	
	}else if(a>10){
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

void ChecarPalabra(char c[100]){
	bool ch=0;
	int ps;
	for(int i=0;i<30;i++){
		if((strcmp(c,palabras[i]))==0){
			ch=1;
			ps=i;
		}else{
			
		}
	}
	if(ch==1){
		if(BotonesP[ps].GetActivo()==1){
			BotonesP[ps].Vis(1);
			BotonesP[ps].Activar(0);
			z++;
			l=0;			
			np++;
		}
	}else{
		mensaje("Palabra Incorrecta");
	}
	
}

void CrearBotonesPalabras(){
	for(int i=0;i<15;i++){
		BotonesP[i].Set(100,0,70,20,0,palabras[i]);
	}
}

void SeleccionarNivel(){
	char nivel[255];
	bool s=1;
	int r=0;
	bool b=0;
	int x=raton_x();
	int y=raton_y();
	if(x>150&&x<230&&y>200&&y<230&&raton_boton_izq()){
		while(s){
			espera(10);
			x=raton_x();
			y=raton_y();
			r=PosRatonNivel(x,y);
			espera(5);
			DibujarBotonesNivel(r);
			refresca();
			espera(50);
			if(raton_boton_izq()){
				if(r==1){
					strcpy(nivel,"Nivel: 1");
					BotonNivel.SetText(nivel);
					s=0;
					level=1;
				}else if(r==2){
					strcpy(nivel,"Nivel: 2");
					BotonNivel.SetText(nivel);
					s=0;
					level=2;
				}else if(r==3){
					strcpy(nivel,"Nivel: 3");
					BotonNivel.SetText(nivel);
					s=0;
					level=3;
				}
			}
		
		}
	}
	
}

void DibujarBotonesNivel(int r){
	if(r==1){
		BotonNivel1.Press(1);
		BotonNivel1.DibujaBotonRellenoBlancoTexto();
		BotonNivel2.DibujaBotonRellenoBlancoTexto();
		BotonNivel3.DibujaBotonRellenoBlancoTexto();
	}else if(r==2){
		BotonNivel2.Press(1);
		BotonNivel1.DibujaBotonRellenoBlancoTexto();
		BotonNivel2.DibujaBotonRellenoBlancoTexto();
		BotonNivel3.DibujaBotonRellenoBlancoTexto();
	}else if(r==3){
		BotonNivel3.Press(1);
		BotonNivel1.DibujaBotonRellenoBlancoTexto();
		BotonNivel2.DibujaBotonRellenoBlancoTexto();
		BotonNivel3.DibujaBotonRellenoBlancoTexto();
	}else{
		BotonNivel1.Press(0);
		BotonNivel2.Press(0);
		BotonNivel3.Press(0);
		BotonNivel1.DibujaBotonRellenoBlancoTexto();
		BotonNivel2.DibujaBotonRellenoBlancoTexto();
		BotonNivel3.DibujaBotonRellenoBlancoTexto();
	}
	BotonNivel1.Press(0);
	BotonNivel2.Press(0);
	BotonNivel3.Press(0);
}

int PosRatonNivel(int x,int y){
	int r=0;
	if(x>150&&x<230){
		if(y>200&&y<230){
			r=1;
		}else if(y>230&&y<260){
			r=2;
		}else if(y>260&&y<290){
			r=3;
		}
	}
	return r;
}

void JuegoEnCurso2(){
	z=0;
	z2=1;
	l=0;
	l2=0;
	nv=3;
	np=0;
	salir=1;
	bool m=0;
	int s=1;
	int n=0;
	char t;
	char cadena[100]="\0";
	while(tecla()!=NINGUNA);
	espera(2);
	while(salir){		
		//Bajar Vidas
		char c=NumeroTexto2(nv);
		vds[0]=c;
		vds[1]='\0';
		//
		if(nv==0){
			mensaje("Perdiste");
			Estado=0;
			salir=0;
		}
		//Subir Puntos
		char c2=NumeroTexto2(np);
		if(np==10){
			m++;
		}
		if(m==0){
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='\0';	
		}else{
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='0';
			pts[4]='\0';
		}
		//
		FondoJuego();
		//Palabras Cayendo
		CrearBotonesPalabras();
		BotonesP[z].Vis(0);
		BotonesP[z2].Vis(0);
		BotonesP[z].SetPosy(40+(6*l));
		BotonesP[z2].SetPosx(200);
		BotonesP[z2].SetPosy(40+(6*l2));
		espera(2);
		if(BotonesP[z].GetPosy()>=340){
			mensaje("Pierdes 1 vida");
			nv--;
			z+=2;
			l=0;
			espera(1000);
		}
		if(BotonesP[z2].GetPosy()>=340){
			mensaje("Pierdes 1 vida");
			nv--;
			z2+=2;
			l2=0;
			espera(1000);
		}
		if(m==1&&pts[0]=='1'||nv==0){
			
		}else{
			BotonesP[z].DibujaBotonVacioTexto();
			BotonesP[z2].DibujaBotonVacioTexto();	
		}
		
		if(BotonesP[z].GetPosy()>40&&BotonesP[z].GetPosy()<360){
			BotonesP[z].Activar(1);
		}else{
			BotonesP[z].Activar(0);
		}
		if(BotonesP[z2].GetPosy()>40&&BotonesP[z2].GetPosy()<360){
			BotonesP[z2].Activar(1);
		}else{
			BotonesP[z2].Activar(0);
		}
		//
		//Ingresar Palabras
		texto(70,370,pts);
		texto(165,370,vds);
		espera(50);
		t=tecla();
		if(t!=NINGUNA&&t!=RETURN&&t!=' '){
			cadena[n]=t;
			n++;
			cadena[n]='\0';
		}
		espera(50);
		if(t==RETURN){
			ChecarPalabra2(cadena);
			cadena[0]='\0';
			n=0;
			
		}
		color(NEGRO);
		texto(35,20,cadena);
		refresca();
		espera(2);
		//
		l++;
		l2++;
		if(m==1&&pts[0]=='1'){
			mensaje("Ganaste");
			salir=0;
			Estado=2;
		}
	}
}

void JuegoEnCurso3(){
	z=0;
	z2=1;
	l=0;
	l2=0;
	nv=3;
	np=0;
	salir=1;
	bool m=0;
	int s=1;
	int n=0;
	char t;
	char cadena[100]="\0";
	while(tecla()!=NINGUNA);
	espera(2);
	while(salir){		
		//Bajar Vidas
		char c=NumeroTexto2(nv);
		vds[0]=c;
		vds[1]='\0';
		//
		if(nv==0){
			mensaje("Perdiste");
			Estado=0;
			salir=0;
		}
		//Subir Puntos
		char c2=NumeroTexto2(np);
		if(np==10){
			m++;
		}
		if(m==0){
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='\0';	
		}else{
			pts[0]=c2;
			pts[1]='0';
			pts[2]='0';
			pts[3]='0';
			pts[4]='\0';
		}
		//
		FondoJuego();
		//Palabras Cayendo
		CrearBotonesPalabras();
		BotonesP[z].Vis(0);
		BotonesP[z2].Vis(0);
		BotonesP[z].SetPosy(40+(8*l));
		BotonesP[z2].SetPosx(200);
		BotonesP[z2].SetPosy(40+(8*l2));
		espera(2);
		if(BotonesP[z].GetPosy()>=340){
			mensaje("Pierdes 1 vida");
			nv--;
			z+=2;
			l=0;
			espera(1000);
		}
		if(BotonesP[z2].GetPosy()>=340){
			mensaje("Pierdes 1 vida");
			nv--;
			z2+=2;
			l2=0;
			espera(1000);
		}
		if(m==1&&pts[0]=='1'||nv==0){
			
		}else{
			BotonesP[z].DibujaBotonVacioTexto();
			BotonesP[z2].DibujaBotonVacioTexto();	
		}
		
		if(BotonesP[z].GetPosy()>40&&BotonesP[z].GetPosy()<360){
			BotonesP[z].Activar(1);
		}else{
			BotonesP[z].Activar(0);
		}
		if(BotonesP[z2].GetPosy()>40&&BotonesP[z2].GetPosy()<360){
			BotonesP[z2].Activar(1);
		}else{
			BotonesP[z2].Activar(0);
		}
		//
		//Ingresar Palabras
		texto(70,370,pts);
		texto(165,370,vds);
		espera(50);
		t=tecla();
		if(t!=NINGUNA&&t!=RETURN&&t!=' '){
			cadena[n]=t;
			n++;
			cadena[n]='\0';
		}
		espera(50);
		if(t==RETURN){
			ChecarPalabra3(cadena);
			cadena[0]='\0';
			n=0;
			
		}
		color(NEGRO);
		texto(35,20,cadena);
		refresca();
		espera(2);
		//
		l++;
		l2++;
		if(m==1&&pts[0]=='1'){
			mensaje("Ganaste");
			salir=0;
			Estado=3;
		}
	}
}

void ChecarPalabra2(char c[100]){
	bool ch=0;
	int ps;
	for(int i=0;i<30;i++){
		if((strcmp(c,palabras[i]))==0){
			ch=1;
			ps=i;
		}else{
			
		}
	}
	if(ch==1){
		if(BotonesP[ps].GetActivo()==1){
			BotonesP[ps].Vis(1);
			BotonesP[ps].Activar(0);
			if(ps==z){
				z=z+2;
				l=0;
			}else if(ps==z2){
				z2=z2+2;
				l2=0;
			}
			
			np++;
		}
	}else{
		mensaje("Palabra Incorrecta");
	}
	
}

void ChecarPalabra3(char c[100]){
	bool ch=0;
	int ps;
	for(int i=0;i<30;i++){
		if((strcmp(c,palabras[i]))==0){
			ch=1;
			ps=i;
		}else{
			
		}
	}
	if(ch==1){
		if(BotonesP[ps].GetActivo()==1){
			BotonesP[ps].Vis(1);
			BotonesP[ps].Activar(0);
			if(ps==z){
				z=z+2;
				l=0;
			}else if(ps==z2){
				z2=z2+2;
				l2=0;
			}
			
			np++;
		}
	}else{
		mensaje("Palabra Incorrecta\nPierdes una Vida");
		nv--;
	}
	
}


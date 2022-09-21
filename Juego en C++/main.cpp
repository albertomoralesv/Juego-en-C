#include <stdio.h>
#include "miniwin.h"
#include "libreria.h"
#include "libreria2.h"
using namespace miniwin;
using namespace std;

int GoP=0;
bool MainExit=1;
bool EXIT1=1,EXIT2=1;
struct BaseDeDatos UsuariosRegistrados[255];
FILE *archivo;
FILE *archivo2;
int p;
int i=0,j=0;
int v=0;
Boton BotonU(40,70,130,25);
Boton BotonC(40,115,130,25);
char Aceptar[100]="Aceptar";
Boton BotonOK(100,155,70,20,0,Aceptar);
char nombre[14];
char passw[14];
int ID;
int cdc=0;
char b=0;
int j2=0;
int NumWins;
int id2=0;

/*void mess(int a){
	//
	char ccc[100];
	char bbb=NumeroTexto(UsuariosRegistrados[a].Wins);
	ccc[0]=bbb;
	ccc[1]='\0';
	mensaje(ccc);
	//
}*/

void CrearArchivo(){
	archivo=fopen("usuarios.txt","r");
	if(archivo==NULL){
    	exit(1);
	}else{
		char c;
		char cadena[13];
		ID=0;
  		while((c=fgetc(archivo))!=EOF&&c!='.'){
  			if(c==' '){
				UsuariosRegistrados[ID].id=ID;
				if(cadena[0]!='\0'){
					strcpy(UsuariosRegistrados[ID].usuario,cadena);	
				}
				j=0;
			}else if(c=='\n'){
				if(cadena[0]!='\0'){
					strcpy(UsuariosRegistrados[ID].password,cadena);	
				}
				j=0;
				ID++;
			}else{
				cadena[j]=c;
  				j++;
  				cadena[j]='\0';
			}
		}
	}
	fclose(archivo);
}

void CrearArchivo2(){
	int Vic=0;
	archivo2=fopen("estadisticas.txt","r");
	if(archivo2==NULL){
    	exit(1);
	}else{
		char c;
		char cadena[13];
		id2=0;
  		while((c=fgetc(archivo2))!=EOF&&c!='.'){
  			espera(5);
  			if(c!=' '&&c!='\n'){
  				cadena[j2]=c;
  				j2++;
  				cadena[j2]='\0';
			}if(c==' '){
				if(cadena[0]=='1'){
					UsuariosRegistrados[id2].Played=1;
				}else{
					UsuariosRegistrados[id2].Played=0;
				}
				j2=0;
				cadena[j2]='\0';
			}if(c=='\n'){
				espera(2);
				Vic=TextoNumero(cadena);
				espera(2);
				UsuariosRegistrados[id2].Wins=Vic;
				espera(2);
				UsuariosRegistrados[id2].id=id2;
				id2++;
				j2=0;
				cadena[j2]='\0';
			}
		}
	}
	fclose(archivo2);
}


void PantallaIniciarSesion(){
	color_rgb(100,100,100);
	rectangulo_lleno(0,0,200,300);
	//Titulo
	color(NEGRO);
	texto(40,30,"Inicio de Sesion");
	//
	//Usuario
	color(NEGRO);
	texto(40,55,"Usuario");
	Boton BotonU(40,70,130,25);
	BotonU.DibujaBotonVacio();
	//
	//Contraseña
	color(NEGRO);
	texto(40,100,"Contraseña");
	Boton BotonC(40,115,130,25);
	BotonC.DibujaBotonVacio();
	//
	//BotonAcepatar
	BotonOK.DibujaBotonRellenoTexto2();
	//
}

void BotonIS(int x, int y, int sizex, int sizey,bool press){
	char IS[100]="Iniciar Sesion";
	Boton BotonIS(x,y,sizex,sizey,press,IS);
	BotonIS.DibujaBotonRellenoTexto();
}

void BotonR(int x, int y, int sizex, int sizey,bool press){
	char R[100]="Registrarse";
	Boton BotonR(x,y,sizex,sizey,press,R);
	BotonR.DibujaBotonRellenoTexto();
}

void BotonE(int x, int y, int sizex, int sizey,bool press){
	char E[100]="Salir";
	Boton BotonE(x,y,sizex,sizey,press,E);
	BotonE.DibujaBotonRellenoTexto();
}

int PosicionRaton(int x, int y){
	int p=0;
	if(x>40&&x<170){
		if(y>70&&y<95){
			p=1;
		}else if(y>105&&y<130){
			p=2;
		}else if(y>140&&y<165){
			p=3;
		}
	}
	return p;
}

int PosicionRaton2(int x, int y){
	int p=0;
	if(x>40&&x<170){
		if(y>70&&y<95){
			p=1;
		}else if(y>115&&y<140){
			p=2;
		}
	}
	if(x>100&&x<170){
		if(y>155&&y<175){
			p=3;
		}
	}
	return p;
}

int PosicionRatonMenu(int x, int y){
	int p=0;
	if(x>40&&x<170){
		if(y>70&&y<95){
			p=1;
		}else if(y>105&&y<130){
			p=2;
		}else if(y>140&&y<165){
			p=3;
		}else if(y>175&&y<200){
			p=4;
		}
	}
	return p;
}

void BotonJugar(int x, int y, int sizex, int sizey,bool press){
	char J[100]="Jugar";
	Boton BotonJugar(x,y,sizex,sizey,press,J);
	BotonJugar.DibujaBoton2RellenoTexto();
}

void BotonEstadisticas(int x, int y, int sizex, int sizey,bool press){
	char E[100]="Estadisticas";
	Boton BotonEstadisticas(x,y,sizex,sizey,press,E);
	BotonEstadisticas.DibujaBoton2RellenoTexto();
}

void BotonAutores(int x, int y, int sizex, int sizey,bool press){
	char A[100]="Autores";
	Boton BotonAutores(x,y,sizex,sizey,press,A);
	BotonAutores.DibujaBoton2RellenoTexto();
}

void BotonSalir(int x, int y, int sizex, int sizey,bool press){
	char S[100]="Salir";
	Boton BotonSalir(x,y,sizex,sizey,press,S);
	BotonSalir.DibujaBoton2RellenoTexto();
}

void BotonAutoresAtras(int x, int y, int sizex, int sizey,bool press){
	char A[100]="Atras";
	Boton BotonAutoresAtras(x,y,sizex,sizey,press,A);
	BotonAutoresAtras.DibujaBotonRellenoTexto3();
}

void BotonEstadisticasAtras(int x, int y, int sizex, int sizey,bool press){
	char A[100]="Atras";
	Boton BotonEstadisticasAtras(x,y,sizex,sizey,press,A);
	BotonEstadisticasAtras.DibujaBotonRellenoTexto3();
}

void DibujarBotones2(int p){
	bool press=0;
	if(p==1){
		BotonEstadisticas(40,105,130,25,press);
		BotonAutores(40,140,130,25,press);
		BotonSalir(40,175,130,25,press);
		press=1;
		BotonJugar(40,70,130,25,press);
		press=0;
		espera(2);
	}else if(p==2){
		BotonJugar(40,70,130,25,press);
		BotonAutores(40,140,130,25,press);
		BotonSalir(40,175,130,25,press);
		press=1;
		BotonEstadisticas(40,105,130,25,press);
		press=0;
		espera(2);
	}else if(p==3){
		BotonJugar(40,70,130,25,press);
		BotonEstadisticas(40,105,130,25,press);
		BotonSalir(40,175,130,25,press);
		press=1;
		BotonAutores(40,140,130,25,press);
		press=0;
		espera(2);
	}else if(p==4){
		BotonJugar(40,70,130,25,press);
		BotonEstadisticas(40,105,130,25,press);
		BotonAutores(40,140,130,25,press);
		press=1;
		BotonSalir(40,175,130,25,press);		
		press=0;
		espera(2);
	}else{
		BotonJugar(40,70,130,25,press);
		BotonEstadisticas(40,105,130,25,press);
		BotonAutores(40,140,130,25,press);
		BotonSalir(40,175,130,25,press);		
		espera(2);
	}
}


void DibujarBotones(int p){
	bool press=0;
	if(p==1){
		BotonR(40,105,130,25,press);
		BotonE(40,140,130,25,press);
		press=1;
		BotonIS(40,70,130,25,press);
		press=0;
		espera(2);
	}else if(p==2){
		BotonIS(40,70,130,25,press);
		BotonE(40,140,130,25,press);
		press=1;
		BotonR(40,105,130,25,press);
		press=0;
		espera(2);
	}else if(p==3){
		BotonIS(40,70,130,25,press);
		BotonR(40,105,130,25,press);
		press=1;
		BotonE(40,140,130,25,press);
		press=0;
		espera(2);
	}else{
		BotonIS(40,70,130,25,press);
		BotonR(40,105,130,25,press);
		BotonE(40,140,130,25,press);
		espera(2);
	}
}

void MainScreen(){
	int x,y;
	int s=1;
	//Fondo
	vredimensiona(200,300);
	color_rgb(100,100,100);
	rectangulo_lleno(0,0,200,300);
	refresca();	
	espera(2);
	//
	//Titulo
	color(NEGRO);
	texto(45,30,"Lluvia de Palabras");
	refresca();
	//
	while(s){
		//Posición mouse
		x=raton_x();
		y=raton_y();
		//
		p=PosicionRaton(x,y);
		espera(2);
		DibujarBotones(p);
		espera(2);
		refresca();
		//clic a boton
		if(raton_boton_izq()){
			if(p==1||p==2||p==3){
				s=0;	
			}
		}
	}
}

void PantallaRegistro(){
	color_rgb(100,100,100);
	rectangulo_lleno(0,0,200,300);
	//Titulo
	color(NEGRO);
	texto(40,30,"Registro");
	//
	//Usuario
	color(NEGRO);
	texto(40,55,"Usuario");
	//Boton BotonU(40,70,130,25);
	BotonU.DibujaBotonVacio();
	//
	//Contraseña
	color(NEGRO);
	texto(40,100,"Contraseña");
	//Boton BotonC(40,115,130,25);
	BotonC.DibujaBotonVacio();
	//
	//BotonAcepatar
	BotonOK.DibujaBotonRellenoTexto2();
	//
}

void Usuarios(){
	int i=0;
	int s=1;
	char t;
	char cadena[14];
	cadena[0]='\0';
	while(tecla()!=NINGUNA);
	while(s){
		color(BLANCO);		
		texto(175,70,"<-");
		refresca();
		espera(2);
		t=tecla();
		if(t!=NINGUNA&&t!=RETURN&&t!=ESPACIO){
			cadena[i]=t;	
			i++;
			cadena[i]='\0';	
		}else if(t==RETURN){
			s=0;
		}
		if(i==13){
			s=0;
		}
		color(NEGRO);
		texto(45,75,cadena);
		espera(2);
		refresca();
		if(s==0){
			strcpy(nombre,cadena);
			color_rgb(100,100,100);
			texto(175,70,"<-");
			refresca();
		}
	}
}

void Passwords(){
	int i=0;
	int s=1;
	char t;
	char cadena[14];
	cadena[0]='\0';
	char np[13];
	while(tecla()!=NINGUNA);
	while(s){
		color(BLANCO);		
		texto(175,120,"<-");
		refresca();
		espera(2);
		t=tecla();
		if(t!=NINGUNA&&t!=RETURN&&t!=ESPACIO){
			cadena[i]=t;	
			np[i]='*';	
			i++;
			cadena[i]='\0';
			np[i]='\0';
		}else if(t==RETURN){
			s=0;
		}
		if(i==13){
			s=0;
		}
		color(NEGRO);
		texto(45,120,np);
		espera(2);
		refresca();
		if(s==0){
			strcpy(passw,cadena);
			color_rgb(100,100,100);
			texto(175,120,"<-");
			refresca();
		}
	}
}

bool ValidarUsuario(){
	bool b=0;
	for(int i=0;i<ID;i++){
		if((strcmp(UsuariosRegistrados[i].usuario,nombre))==0){
			b=1;
			cdc=i;
		}
	}
	return b;
}

void Registro();
void HacerRegistro();
void InicioDeSesion();
void ValidarInicioDeSesion();
void ValidarPassword();

void MenuOpciones();
void PaginaAutores();
void PantallaAutores();
void PaginaEstadisticas();
void GuardarUsuarios();
void GuardarEstadisticas();

int main(){
	CrearArchivo();
	//
	CrearArchivo2();
	//
	//
	while(MainExit){
		while(EXIT1){
			MainScreen();
			espera(900);
			if(p==1){
				nombre[0]='\0';
				passw[0]='\0';
				InicioDeSesion();
			}else if(p==2){
				Registro();
				espera(50);
			}else if(p==3){
				EXIT1=0;
				MainExit=0;
				espera(1000);
			}
		}
		borra();
		espera(3000);
		while(EXIT2&&MainExit!=0){
			espera(50);
			MenuOpciones();
			espera(900);
			if(p==1){
				espera(1000);
				GoP=0;
				GoP=Juego();
				espera(1000);
				if(GoP==1){
					UsuariosRegistrados[cdc].Wins++;
				}else if(GoP==2){
					UsuariosRegistrados[cdc].Wins=UsuariosRegistrados[cdc].Wins+2;
				}else if(GoP==3){
					UsuariosRegistrados[cdc].Wins=UsuariosRegistrados[cdc].Wins+3;
				}
				UsuariosRegistrados[cdc].Played=1;
			}else if(p==2){
				espera(10);
				PaginaEstadisticas();
			}else if(p==3){
				PaginaAutores();
			}else if(p==4){
				EXIT2=0;
				MainExit=0;
				espera(1000);
			}
		}
		
	}
	GuardarUsuarios();
	GuardarEstadisticas();
	vcierra();
	//	
	return 0;
}

void GuardarEstadisticas(){
	archivo2=fopen("estadisticas.txt","w");
	if(archivo2==NULL){
    	exit(1);
	}else{ 
		for(int i=0;i<ID;i++){
			fprintf(archivo2,"%d %d\n",UsuariosRegistrados[i].Played,UsuariosRegistrados[i].Wins);
			if(i+1==ID){
				fprintf(archivo2,".");	
			}	
		}
	}
	fclose(archivo2);
}

void GuardarUsuarios(){
	archivo=fopen("usuarios.txt","w");
	if(archivo==NULL){
    	exit(1);
	}else{ 
		for(int i=0;i<ID;i++){
			fprintf(archivo,"%s %s\n",UsuariosRegistrados[i].usuario,UsuariosRegistrados[i].password);
			if(i+1==ID){
				fprintf(archivo,".");	
			}	
		}
	}
	fclose(archivo);
}

void PaginaEstadisticas(){
	int x,y;
	int s=1;
	borra();
	vredimensiona(300,300);
	color(BLANCO);
	rectangulo_lleno(0,0,300,300);
	color(NEGRO);
	rectangulo(1,1,399,299);
	texto(100,30,"Estadisticas");
	refresca();
	espera(2);
	//
	rectangulo(50,50,250,250);
	rectangulo(50,50,130,250);
	rectangulo(130,50,190,250);
	rectangulo(190,50,250,250);
	rectangulo(50,50,250,75);
	texto(55,55,"Usuarios");
	texto(135,55,"Jugado");
	texto(195,55,"Victorias");
	//
	espera(2);
	for(int l=0;l<ID;l++){
		espera(10);
		//Tabla
		rectangulo(50,75+(25*l),250,100+(25*l));
		//
		//Datos
		texto(55,80+(25*l),UsuariosRegistrados[l].usuario);
		if(UsuariosRegistrados[l].Played){
			texto(135,80+(25*l),"Si");		
		}else{
			texto(135,80+(25*l),"No");
		}
		//
		int numero=UsuariosRegistrados[l].Wins;
		char numeros[4];
		if(numero<10){
			numeros[0]=NumeroTexto(numero);
			numeros[1]='\0';	
		}else if(numero>=10&&numero<20){
			numeros[0]='1';
			numeros[1]=NumeroTexto(numero-10);
			numeros[2]='\0';
		}else if(numero>=20&&numero<30){
			numeros[0]='2';
			numeros[1]=NumeroTexto(numero-20);
			numeros[2]='\0';
		}else if(numero>=30&&numero<40){
			numeros[0]='3';
			numeros[1]=NumeroTexto(numero-30);
			numeros[2]='\0';
		}else{
			strcpy(numeros,"MAX");
		}
		texto(195,80+(25*l),numeros);
		//
		refresca();
		espera(50);
	}
	while(s){
		x=raton_x();
		y=raton_y();
		bool pr=0;
		if(x>200&&x<250&&y>270&&y<290){
			pr=1;
		}
		espera(2);
		if(pr){
			BotonEstadisticasAtras(200,270,50,20,pr);
		}else{
			BotonEstadisticasAtras(200,270,50,20,pr);
		}
		espera(2);
		refresca();
		espera(2);
		if(pr==1&&(raton_boton_izq())){
			s=0;
			espera(50);
		}
	}
}

void PantallaAutores(){
	vredimensiona(200,200);
	color(BLANCO);
	rectangulo_lleno(0,0,200,300);
	//Titulo
	color(NEGRO);
	texto(15,20,"Autores");
	rectangulo(10,10,190,190);
	linea(10,40,190,40);
	//
	texto(20,55,"0230866 Alberto Morales");
	texto(20,80,"0220490 Isaac Almodovar");
	texto(20,105,"Programacion Avanzada");
	texto(20,125,"Juan Carlos Lopez P.");
	//BotonAcepatar
	BotonAutoresAtras(100,155,70,20,0);
	//
}

void PaginaAutores(){
	int x,y;
	int s=1;
	PantallaAutores();
	espera(2);
	refresca();
	while(s){
		x=raton_x();
		y=raton_y();
		bool pr=0;
		if(x>100&&x<170&&y>155&&y<175){
			pr=1;
		}
		espera(2);
		if(pr){
			BotonAutoresAtras(100,155,70,20,pr);
		}else{
			BotonAutoresAtras(100,155,70,20,pr);
		}
		espera(2);
		refresca();
		espera(2);
		if(pr==1&&(raton_boton_izq())){
			s=0;
			espera(50);
		}
	}
	
}

void MenuOpciones(){
	int x,y;
	int s=1;
	//Fondo
	vredimensiona(200,300);
	color(NEGRO);
	rectangulo_lleno(0,0,200,300);
	refresca();	
	espera(2);
	//
	//Titulo
	color(BLANCO);
	texto(45,30,"Lluvia de Palabras");
	refresca();
	//
	while(s){
		//Posición mouse
		x=raton_x();
		y=raton_y();
		//
		espera(5);
		p=PosicionRatonMenu(x,y);
		espera(2);
		DibujarBotones2(p);
		espera(2);
		refresca();
		//clic a boton
		if(raton_boton_izq()){
			if(p==1||p==2||p==3||p==4){
				s=0;	
			}
		}
	}
}

void Registro(){
	int x,y;
	int s=1;
	PantallaRegistro();
	espera(2);
	refresca();
	while(s){
		x=raton_x();
		y=raton_y();
		p=PosicionRaton2(x,y);
		if(raton_boton_izq()){
			espera(5);
			if(p==1){
				BotonU.DibujaBotonVacio();
				refresca();
				espera(2);
				Usuarios();
			}else if(p==2){
				BotonC.DibujaBotonVacio();
				refresca();
				espera(2);
				Passwords();
			}else if(p==3){
				BotonOK.Press(1);
				BotonOK.DibujaBotonRellenoTexto2();
				refresca();
				espera(2);
				s=0;
				if(nombre[0]=='\0'||passw[0]=='\0'){
					mensaje("Campos Vacios");
					espera(1000);
				}else{
					HacerRegistro();	
				}
				BotonOK.Press(0);
			}
		}
	}
}

void HacerRegistro(){
	int b=0;
	b=ValidarUsuario();
	if(b==1){
		mensaje("Usuario Ya Existente");
		espera(1000);
	}else{
		UsuariosRegistrados[ID].id=ID;
		strcpy(UsuariosRegistrados[ID].usuario,nombre);
		strcpy(UsuariosRegistrados[ID].password,passw);
		UsuariosRegistrados[ID].Played=0;
		UsuariosRegistrados[ID].Wins=0;
		espera(50);
		mensaje("Usuario Registrado Correctamente");
		espera(1000);
		ID++;
	}
}

void InicioDeSesion(){
	int x,y;
	int s=1;
	PantallaIniciarSesion();
	espera(2);
	refresca();
	while(s){
		x=raton_x();
		y=raton_y();
		p=PosicionRaton2(x,y);
		if(raton_boton_izq()){
			espera(5);
			if(p==1){
				BotonU.DibujaBotonVacio();
				refresca();
				espera(2);
				Usuarios();
			}else if(p==2){
				BotonC.DibujaBotonVacio();
				refresca();
				espera(2);
				Passwords();
			}else if(p==3){
				BotonOK.Press(1);
				BotonOK.DibujaBotonRellenoTexto2();
				refresca();
				espera(2);
				s=0;
				if(nombre[0]=='\0'||passw[0]=='\0'){
					mensaje("Campos Vacios");
					espera(1000);
				}else{
					ValidarInicioDeSesion();
					espera(500);	
				}
				BotonOK.Press(0);
				nombre[0]='\0';
				passw[0]='\0';
			}
		}
	}	
}

void ValidarInicioDeSesion(){
	int b=0;
	b=ValidarUsuario();
	if(b==1){
		ValidarPassword();
	}else{
		mensaje("Usuario No Registrado");
		espera(1000);
	}
}

void ValidarPassword(){
	if((strcmp(UsuariosRegistrados[cdc].password,passw))==0){
		EXIT1=0;
		mensaje("Acceso Correcto");
		espera(1000);
	}else{
		mensaje("Contraseña Incorrecta");
		espera(1000);
	}
}


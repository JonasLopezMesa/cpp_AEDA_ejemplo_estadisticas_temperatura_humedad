#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h> 
using namespace std;

int main(){
int M = 24;

double t[M];
double h[M];


	void menu(double t[], double h[]);
	
	menu(t,h);
	
}
void menu(double t[], double h[]){
	void mostrar(double t[], double h[]);
	void esta(double t[], double h[]);
	int i =1;
	int a = 0;
	int op;
	while(a == 0){
		cout << "MENÚ" << endl;
		cout << "selecciona la opcion que desees:" << endl;
		cout << "1 ===> Introducir los datos de un día completo" << endl;
		cout << "2 ===> Introducir los datos de una hora concreta" << endl;
		cout << "3 ===> Mostrar todos los datos del día" << endl;
		cout << "4 ===> Mostrar las estadísticas" << endl;
		cout << "5 ===> Salir del Programa" << endl;
		cout << "6 ===> Limpiar la Pantalla" << endl;
		cin >> op;	
		switch(op){
			case 1: //dia(t,h);
			
			cout << " introduce los datos correspondientes a todas las horas de un día" << endl;
			while (i <=24){
				cout << i << ":00   (temperatura):" << endl;
				cin >> t[i];
				cout << i << ":00   (humedad):" << endl;
				cin >> h[i];
				i++;
			} break;
			case 2: 
				cout << "introduce la hora en la que vas a introducir los datos" << endl;
				cin >> i;
				cout << i << ":00   (temperatura):" << endl;
				cin >> t[i];
				cout << i << ":00   (humedad):" << endl;
				cin >> h[i]; 
			break;
			case 3: mostrar(t,h); break;
			case 4: esta(t,h); break;
			case 5: 
			cout << "adios!!!" << endl;
			a = 1; break;
			case 6: system("clear"); break;
			default: cout << "ERROR vuelva a escribir una opcion correcta" << endl;
				 menu(t,h);
				
		}
	}
	
	}
	



void mostrar(double t[], double h[]){
	int i = 1;
	cout << "DATOS DE UN DÍA ENTERO" << endl;
	cout << "hora___________" << "Temperatura____"<< "Humedad________" << endl;
	
	while (i <=24){
		
		cout << fixed << setprecision ( 2 );
		cout << i << ":00" << setw(15) << t[i] << setw(15) << h[i] << endl;
		i++;
	}

	menu(t,h);
}



void esta(double t[], double h[]){
	

	
	int i = 1;
	float s = 0;
	float mt, mh; // variables para el control de las medias, los maximos y minimos y las desviaciones
	float dest;
	float desh;
	float jj;
	float j;

	while(i <= 24){ // media de temperatura

		s = (t[i] + s);

		i++;
	}
	i--;
	mt = (s / i);

	i = 1;
	s = 0;

	while(i <= 24){ // media de humedad

		s = (h[i] + s);

		i++;
	}

	i--;
	mh = (s / i);

	i = 1;

	while( i <= 24){ //desviacion temperatura
		
		j = ((t[i] - mt) * (t[i] - mt));
		i++;
	}
	dest = sqrt( j / 23 );
	i = 1;

	while( i <= 24){ //desviacion humedad
	
		
		jj = ((h[i] - mt) * (h[i] - mt));
		i++;
	}
	desh = sqrt( jj / 23 );
	i = 1;

	float hh = 0;
	while(i<=24){ // máximo de temperatura
	
		
		if(t[i] > hh)
			hh = t[i];
		i++;
	}

	i = 0;
	float dd = 0;
	while(i<=24){ // máximo de humedad
	

		if(h[i] > dd)
			dd = t[i];
		i++;
	}
	

	i = 0;
	float rr;
	rr = hh; 
	while(i <= 24){ //minimo de temperatura
	
	
		if(t[i] < rr)
			rr = t[i];
		i++;
	}

	i = 0;
	float rrr;
	rrr = dd;
	while(i <= 24){ //minimo de humedad
	
	
		if(h[i] < rrr)
			rrr = h[i];
		i++;
	}

	i = 0;

	cout << " ESTADISTICAS" << endl;
	cout << "_______________" << "Temperatura____"<< "Humedad________" << endl;

	cout << fixed << setprecision ( 2 );
	cout  << "media" << setw(15) << mt << setw(15) << mh << endl;
	cout << "maximos" << setw(13) << hh << setw(15) << dd << endl;
	cout << "minimos" << setw(13) << rr << setw(15) << rrr << endl;
	cout << "desviacion" << setw(10) << dest << setw(15) << desh << endl;

	menu(t,h);
	
}








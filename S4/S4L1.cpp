

/*

g++ -Wall -o S4L1 S4L1.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video -lopencv_features2d -lopencv_imgcodecs


export LD_LIBRARY_PATH=/usr/local/lib

*/
// cp /home/rub/ET414-B/Sesion2/ejemplo1.cpp /home/rub/ET414-B/Sesion3/template.cpp
// cp -> permite copiar archivos
// mkdir -> crear carpetas
// cd .. -> bajar una carpeta anterior
// cd -> subir una carpeta
// gedit -> crear archivos con alguna extension determinada
// locate -> buscar archivos
// ls -> mostrar archivos y carpetas
// pwd -> mostrar la ubicacion actual del cursos
// sudo apt-get install programa

/*
	Este es el ejemplo1 de la sesion1
	Muestra el uso  y declaracion de clases en c++
*/

#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<stdio.h>
#include<vector>
#include<ctime>

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


#include <iostream>
#include <sstream>
#include <fstream>

#define X 200
#define Y 200

#define Verde 140
#define Azul 0
#define Rojo 255
#define numero 10
using namespace cv;
using namespace std;
float var1 = 13.2;

int main(void)
{
	//int temporal=0;
	double A[3];
	double B[3];
	char nombre[30];
	int i=0;
	int f=0;
	int toma=0;
	int funciono = sprintf(	nombre, 
				"imagen%d.png",
				 numero);

	string linea; 
	string temporal;

	if(!funciono) return -1;
	
	/*Parametros de conversion en imwrite*/
	vector<int> compression_params;
    	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    	compression_params.push_back(9);
    	
	/*obtener el tiempo actual*/
	time_t t = time(0);
	struct tm * now = localtime( &t);
	
	
	
	
	/*Inicia creacion del archivo*/
	string  buffer;
	ofstream info;
	info.open("init.txt");

	info << "Sanmina" << endl;
	info << "Raspberry B+" << endl;
	info << (now -> tm_year + 1900) << '-' << (now -> tm_mon + 1 ) << '-' << now -> tm_mday << endl;
	info << X << " " << Y << endl;;
	info << Verde 				<< " " << Rojo << " " << Azul << endl;
	info << nombre << endl;
	info.close();

	/*Finaliza creacion de archivo*/
	

	/*Inicia lectura de archivo previamente creado*/
	ifstream lectura("init.txt");
	while(getline(lectura, linea)){
	istringstream lectura_linea(linea);
	if(i<3)
		lectura_linea >> buffer;  //Desecha las primeras 3 lineas de texto
	else if(i<5){
		lectura_linea >> A[f] >> B[f]; //guarda en dos vectores las siguientes 2 lineas
		f++;
		if(f>2) f=0;
	}
	else {
		lectura_linea >> temporal;			//hace lectura del nombre del archivo a crear
	}
	
	i++;

	}

	/*Finaliza lectura de archivo*/

	/*Apertura de camara*/
		
	VideoCapture camara(0);
	if(!camara.isOpened()) return -1;

	Mat imagen;

	/*Ciclo principal*/
	
	for(;;){
		camara >> imagen;
		toma++;
	
		if(toma == 5){
		 try {
        		imwrite(nombre, imagen, compression_params);
	 }
			break;
		}


	}
	//Fin del programa

	return 1;
}



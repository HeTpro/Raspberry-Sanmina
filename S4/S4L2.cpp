
/*
g++ -Wall -o S4L2 S4L2.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video -lopencv_features2d -lopencv_imgcodecs
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
	ofstream file("data.dat");
	file << "#SanMIna" << endl;
	file << "#x y" << endl;
	for(int i=0; i<10; i++)
	{
		file << i << ' ' << i*i << endl;
	}
	file.close();
	system("gnuplot  plot.plt");
	return 1;
}

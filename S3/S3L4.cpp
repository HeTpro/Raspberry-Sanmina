

/*


g++ -Wall -o S3L4 S3L4.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video
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

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


#include <iostream>


using namespace cv;
using namespace std;

int V = 1;
int Op = 0;
int B1A = 0;
int B2A = 0;
int B3A = 0;
/*      Funcion SiRatonSeMueve. Cada vez que el raton se mueva
	en la ventana "programada" se ejecutara esta funcion.

	


*/




int main(void)
{
	int Amin=0, Amax=32;
	int Bmin=40, Bmax=213;
	int Cmin=123, Cmax=205;
	
	size_t i ;
	size_t area;


	Mat imagen;
	Mat imagen_reducida;
	Mat imagen_hsv;
	
	Mat imagen_bw;
	Mat imagen_hsv_blur;
	Mat imagen_contorno;

	vector < vector<Point> > contornos;

	Rect reg1(Point (50,50), Size(150,150));

	VideoCapture camara(0);
	if(!camara.isOpened()) return -1;

	namedWindow("Inicio");

	cvCreateTrackbar("Amin", "Inicio", &Amin, 255);
	cvCreateTrackbar("Amax", "Inicio", &Amax, 255);
	cvCreateTrackbar("Bmin", "Inicio", &Bmin, 255);
	cvCreateTrackbar("Bmax", "Inicio", &Bmax, 255);
	cvCreateTrackbar("Cmin", "Inicio", &Cmin, 255);
	cvCreateTrackbar("Cmax", "Inicio", &Cmax, 255);




	for(;;)
	{
		
		camara >> imagen;
		resize(imagen, imagen_reducida, Size(150,150));
		cvtColor(imagen_reducida, imagen_hsv, CV_BGR2HSV);
		GaussianBlur(	imagen_hsv, 
				imagen_hsv_blur,
				Size(0,0),
				5,
				0,
				BORDER_DEFAULT);

		inRange(	imagen_hsv_blur, 
				Scalar(Amin, Bmin, Cmin), 
				Scalar(Amax, Bmax, Cmax), 
				imagen_bw);
		
		imagen_bw.copyTo(imagen_contorno);

		findContours(	imagen_contorno, 
				contornos, 
				RETR_LIST, 
				CHAIN_APPROX_SIMPLE);
		
		cout 	<< "Numeros de contornos encontrados: "
			<< contornos.size()
			<< endl;

		for(i = 0; i < contornos.size(); i++ ){
			area = contornos[i].size();
			if(area > 100)
			cout 	<< "Area: " 
				<< i 
				<< " A : " 
				<< contornos[i].size() 
				<< endl;
		}
		
		imshow("Inicio", imagen_bw);

	
	if(waitKey(30)>0) break;

 	}

	return 1;
}



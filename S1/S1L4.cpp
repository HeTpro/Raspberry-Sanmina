
/*


g++ -Wall -o S2E1 S2E1.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video


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


int main(void)
{
	VideoCapture cam(0);
	Mat imagen, imagen_small;
	Mat A(1000,1000, CV_8UC3, Scalar(255,255,255));
	Mat B(200,300, CV_8UC3, Scalar(255,0,0));
	Mat C(200,700, CV_8UC3, Scalar(0,0,255));
	Mat D(800,1000, CV_8UC3, Scalar(10,230,150));

	Rect reg1(Point(0,0),Size(300,200));
	Rect reg2(Point(300,0),Size(700,200));
	Rect reg3(Point(0,200),Size(1000,800));
	Rect reg4(Point(500,500),Size(200,200));

	B.copyTo(A(reg1));
	C.copyTo(A(reg2));
	D.copyTo(A(reg3));


	
	for(;;)
	{
	
	if(!cam.isOpened())  {return -1; } 
	cam >> imagen;
	resize(	imagen ,
		imagen_small ,
		Size ( 200 , 200 ),
		0 ,0 ,
		INTER_LINEAR);
	imagen_small.copyTo(A(reg4));
	imshow("Pasillo1",A);
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}

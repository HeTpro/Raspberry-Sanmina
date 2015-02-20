

/*


g++ -Wall -o S2E2 S2E2.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video -lbcm2835 -lrt


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
#include <bcm2835.h>


#define PIN RPI_BPLUS_GPIO_J8_12





using namespace cv;
using namespace std;

void apaga_led(void){
	bcm2835_gpio_write(PIN,LOW);	
}

void enciende_led(void){
	bcm2835_gpio_write(PIN,HIGH);
}

static void SiRatonSeMueve(	int evento, 
				int x, 
				int y, 
				int flags, 
				void* param){
		
		switch(evento)       
		{
			case CV_EVENT_LBUTTONDOWN :
					cout <<"X: "<< x << endl;
					cout <<"Y: "<< y << endl;
					cout << "*********" << endl;
			if(x>0 && x <100 && y>0 && y<100 ){
				cout << "Bien" << endl;
				apaga_led();
			}
					break;
			default : 
					break;
		}
}




int main(void){
	int dummy = 0;

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

	namedWindow("Principal");
	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );

	if(!bcm2835_init()) return 1;
	bcm2835_gpio_fsel(PIN,BCM2835_GPIO_FSEL_OUTP);
	apaga_led();
	
	for(;;)
	{
	//apaga_led();
	if(!cam.isOpened())  {return -1; } 
	cam >> imagen;
	resize(	imagen ,
		imagen_small ,
		Size ( 200 , 200 ),
		0 ,0 ,
		INTER_LINEAR);
	imagen_small.copyTo(A(reg4));
	imshow("Principal",A);
	
	if(waitKey(30)>0) break;

 	}
	bcm2835_delay(500);
	bcm2835_close();

	return 1;
}


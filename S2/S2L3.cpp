

/*


g++ -Wall -o S2L3 S2L3.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -lopencv_videoio -lopencv_video -lbcm2835 -lrt


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

int V = 0;
int Op = 0;
int vector1[4] = {1,2,3,4};
int vector2[4] = {1,2,3,4};
int posicion=0;
int comparacion=0;
int X=0;



/*      Funcion SiRatonSeMueve. Cada vez que el raton se mueva
	en la ventana "programada" se ejecutara esta funcion.

	


*/

void opcion(int  A, int B){
	//cout << "A vale: " << A << endl;
	//cout << "B vale: " << B << endl;
	if(A > 0 && A < 79 && B> 0 && B< 49)
		{
			cout << "Se presiono Menu1" << endl;
		Op=0;		 
 V = 0;

		}
	else if(A > 80 && A < 160 && B > 0 && B<49 && X!=0)
	{
		cout << "Se presiono Menu2" << endl;
	Op=0;		
V =1;

	}
	else if(A > 160 && A < 240 && B > 0  && B<49 && X!=0)
	{
		cout << "Se presiono Menu3 " << endl;
	Op=0;		
V = 2;	

	
}

	if(A > 52 && A < 90 && B >111 && B<148 && V==2){
		cout << "Se presiono el B1 de la ventana2" << endl;
		Op = 1;	
		X = 0;
		V = 0;
}
	else if(A > 52 && A < 90 && B > 161 && B<199 && V==2){
		cout << "Se presiono el B2 de la ventana2" << endl;
		Op = 2;
		system("sudo poweroff");
		}

	if(A > 111 && A < 148 && B > 109 && B<145 && V==1){
		cout << "Se presiono el B1 de la ventana1" << endl;
		Op = 1;
	}
	else if(A>153 && A<190 && B>150 && B<189 && V==1){
		cout << "Se presiono el B2 de la ventana1" << endl;
	 Op = 2;
	}
	else if(A>192 && A<231 && B>191 && B<229 && V==1){
	 cout << "Se presiono el B3 de la ventana1" << endl;
	Op = 3;

	}

	if(A>40 && A<78 && B>105 && B<141 && V==0){
	cout << "Se presiono el B1 de la ventana 0" << endl;
	Op = 1;
	vector1[posicion]=1;
	posicion++;
	
	}

	else if(A>110 && A<150 && B>106 && B<141 && V==0)
	{
	cout << "Se presiono el B2 de la ventana 0" << endl;
	Op = 2;
	vector1[posicion]=2;
		posicion++;
	}
else if(A>180 && A<222 && B>106 && B<141 && V==0)
	{
	cout << "Se presiono el B3 de la ventana 0" << endl;
	Op = 3;
	vector1[posicion]=3;
	posicion++;
	}
else if(A>41 && A<79 && B>155 && B<194 && V==0)
	{
	cout << "Se presiono el B4 de la ventana 0" << endl;
	Op = 4;
	vector1[posicion]=4;
	posicion++;
	}





else if(A>110 && A<150&& B>156 && B<196 && V==0)
	{
	cout << "Se presiono el B5 de la ventana 0" << endl;
	Op = 5;
	comparacion=0;
	for(int i =0; i<=3; i++){
		if(vector1[i] == vector2[i]) comparacion++;
	}
	if(comparacion==4){ 
	cout << "LOs vectores son iguales" << endl;
	X=1;
	}
	else cout <<"Error 406 " << endl;
	//posicion++;
	}










else if(A>181 && A<220&& B>155 && B<194 && V==0)
	{
	cout << "Se presiono el B6 de la ventana 0" << endl;
	Op = 6;
	posicion=0;
	}
	if(posicion>3) posicion=0;
	cout << "Numero de veces que se ha presionado una tecla: "
	     << posicion << endl;
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

					opcion(x, y);

					break;
			default : 
					break;
		}
}





int main(void)
{
	int  dummy = 0;
	Mat base(250,240,CV_8UC3,Scalar(255, 255, 255));
	Mat menu_act(50,80,CV_8UC3,Scalar(0, 255, 0));  
	Mat menu_des(50,80,CV_8UC3,Scalar(0, 0, 255));  

	Mat ventana1(200,240,CV_8UC3,Scalar(97, 167, 97)); 
	Mat ventana2(200,240,CV_8UC3,Scalar(25, 190, 210));
	Mat ventana3(200,240,CV_8UC3,Scalar(224, 58, 171)); 


	Mat b1_act(40,40,CV_8UC3,Scalar(182, 114, 0)); 
	Mat b1_des(40,40,CV_8UC3,Scalar(117, 111, 100)); 
	
	

	Rect reg_ventana(Point(0,50),Size(240,200));
	Rect reg1(Point(0,0), Size(80,50));
	Rect reg2(Point(80,0), Size(80,50));
	Rect reg3(Point(160,0),Size(80,50));

	//Region de los botones
	Rect reg1b1(Point(40,105),Size(40,40));
	Rect reg2b1(Point(110,105),Size(40,40));	
	Rect reg3b1(Point(180,105),Size(40,40));


	Rect reg4b1(Point(40,155),Size(40,40));
	Rect reg5b1(Point(110,155),Size(40,40));	
	Rect reg6b1(Point(180,155),Size(40,40));

	//Regiones de los botones de la ventana2
	Rect reg1b2(Point(110,110),Size(40,40));
	Rect reg2b2(Point(150,150),Size(40,40));
	Rect reg3b2(Point(190,190),Size(40,40));

	//Regiones de los botones de la ventan3
	Rect reg1b3(Point(50,110), Size(40,40));
	Rect reg2b3(Point(50,160), Size(40,40));

	namedWindow("Principal",1);

	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );


	

	for(;;)
	{
		switch(V){
			case 0:
			ventana1.copyTo(base(reg_ventana));
			menu_act.copyTo(base(reg1));
			menu_des.copyTo(base(reg2));
			menu_des.copyTo(base(reg3));
			switch(Op){
				case 0:
					b1_des.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;
				case 1:
					b1_act.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;
				case 2:
					b1_des.copyTo(base(reg1b1));
					b1_act.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;	
				case 3:
					b1_des.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_act.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;
				case 4:
					b1_des.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_act.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;	
				case 5:
					b1_des.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_act.copyTo(base(reg5b1));
					b1_des.copyTo(base(reg6b1));
					break;
				case 6:
					b1_des.copyTo(base(reg1b1));
					b1_des.copyTo(base(reg2b1));
					b1_des.copyTo(base(reg3b1));
		 			b1_des.copyTo(base(reg4b1));
					b1_des.copyTo(base(reg5b1));
					b1_act.copyTo(base(reg6b1));
					break;
				default: cout << "Error 405" <<endl;
			}
			break;

			case 1:
			ventana2.copyTo(base(reg_ventana));
		  menu_act.copyTo(base(reg2));
			menu_des.copyTo(base(reg1));
			menu_des.copyTo(base(reg3));
			

			switch(Op){
						case 0:
							b1_des.copyTo(base(reg1b2));
							b1_des.copyTo(base(reg2b2));
							b1_des.copyTo(base(reg3b2));
								break;
						case 1:
							b1_act.copyTo(base(reg1b2));
							b1_des.copyTo(base(reg2b2));
							b1_des.copyTo(base(reg3b2));
								break;

						case 2:
							b1_des.copyTo(base(reg1b2));
							b1_act.copyTo(base(reg2b2));
							b1_des.copyTo(base(reg3b2));
								break;

							case 3:
							b1_des.copyTo(base(reg1b2));
							b1_des.copyTo(base(reg2b2));
							b1_act.copyTo(base(reg3b2));
								break;

			}
			break;

			case 2:
			
			ventana3.copyTo(base(reg_ventana));
		  menu_act.copyTo(base(reg3));
			menu_des.copyTo(base(reg1));
			menu_des.copyTo(base(reg2));
		

			switch(Op){
				case 0:
								b1_des.copyTo(base(reg1b3));
								b1_des.copyTo(base(reg2b3));
								break;
				case 1: b1_act.copyTo(base(reg1b3));
							  b1_des.copyTo(base(reg2b3));		
								break;
				case 2:
							  b1_act.copyTo(base(reg2b3));
							  b1_des.copyTo(base(reg1b3));	
								break;
				default:
							cout << "Error 403" << endl;
	
			}
			break;
			

			default:
				cout << "Error";

		}
		imshow("Principal", base);
	
	if(waitKey(30)>0) break;

 	}
	imwrite("base.png",base);

	return 1;
}




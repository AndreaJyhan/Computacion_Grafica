//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************OCAÑA CASILLAS ANDREA JYHAN	            ******//
//*************			jugar con la función prisma primero los colores (cS,cI,cD,cIzq,cF,cA,base,altura);******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float F1, float F2, float F3, float R1, float R2, float R3, float B1, float B2, float B3, float L1, float L2, float L3, float Bo1, float Bo2, float Bo3, float T1, float T2, float T3, float b, float h)
{
	GLfloat vertice [8][3] = {
				{b ,-h, b},    //Coordenadas Vértice 0 V0
				{-b ,-h, b},    //Coordenadas Vértice 1 V1
				{-b ,-h, -b},    //Coordenadas Vértice 2 V2
				{b ,-h, -b},    //Coordenadas Vértice 3 V3
				{b ,h, b},    //Coordenadas Vértice 4 V4
				{b ,h, -b},    //Coordenadas Vértice 5 V5
				{-b ,h, -b},    //Coordenadas Vértice 6 V6
				{-b ,h, b},    //Coordenadas Vértice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(F1,F2,F3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
		glColor3f(R1,R2,R3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(B1,B2,B3);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(L1,L2,L3);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(Bo1, Bo2,Bo3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(T1,T2,T3);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.

	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ); //traslada -5 unidades en el eje z
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	
	prisma(1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0,1.0,1.0);
	glTranslatef(0.0, 1.0, 0.0);
	/*prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(0.0, 1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(0.0, 1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(0.0, -1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(0.0, -1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(0.0, -1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	glTranslatef(-1.0, 1.0, 0.0);
	prisma(1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1.0, 1.0);
	*/
    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 30);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			printf("Posicion en x: %f\n", transX);
			break;
		case 'd':
		case 'D':
			printf("Posicion en x: %f\n", transX);
			transX +=0.2f;
			break;
		case 'q':
		case 'Q':
			printf("Posicion en y: %f\n", transY);
			transY += 0.2f;
			break;
		case 'e':
		case 'E':
			printf("Posicion en y: %f\n", transY);
			transY -= 0.2f;
			break;
		case 't':
		case 'T':
			angleX += 1.5f;
			break;
		case 'g':
		case 'G':
			angleX -= 1.5f;
			break;
		case 'y':
		case 'Y':
			angleY += 1.5f;
			break;
		case 'h':
		case 'H':
			angleY -= 1.5f;
			break;
		case 'u':
		case 'U':
			angleZ += 1.5f;
			break;
		case 'j':
		case 'J':
			angleZ -= 1.5f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}




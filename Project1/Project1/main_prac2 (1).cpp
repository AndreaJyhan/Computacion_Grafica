//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	OCAÑA CASILLAS ANDREA JYHAN******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//lETRA a
	glColor3f(1.0f, 0.0f, .0f);
	glBegin(GL_POLYGON);
	glVertex3f(-12.0f, 5.0f, -1.2f); 
	glVertex3f(-11.0f, 3.0f, -1.2f); 
	glVertex3f(-9.0f, 3.0f, -1.2f); 
	glVertex3f(-8.0f, 5.0f, -1.2f); 
	glEnd();

	glColor3f(1.0f, 1.0f, .0f);
	glBegin(GL_POLYGON);
	glVertex3f(-12.0f, 5.0f, -1.2f); 
	glVertex3f(-11.0f, 3.0f, -1.2f); 
	glVertex3f(-11.0f, -4.0f, -1.2f);
	glVertex3f(-13.0f, -4.0f, -1.2f); 
	glEnd();


	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-11.0f, 1.0f, -1.2f); 
	glVertex3f(-9.0f, 1.0f, -1.2f); 
	glVertex3f(-9.0f, -1.0f, -1.2f); 
	glVertex3f(-11.0f, -1.0f, -1.2f); 
	glEnd();


	glColor3f(1.0f, 1.0f, .0f);
	glBegin(GL_POLYGON);
	glVertex3f(-9.0f, 3.0f, -1.2f); 
	glVertex3f(-8.0f, -5.0f, -1.2f); 
	glVertex3f(-7.0f, -4.0f, -1.2f);
	glVertex3f(-9.0f, -4.0f, -1.2f); 
	glEnd();



	glFlush();
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

	// Ortogonal
	glOrtho(-20,20,-20,20,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}


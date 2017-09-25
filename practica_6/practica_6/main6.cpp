//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Ocaña Casillas Andrea Jyhan          	******//
//*************											******//
//************************************************************//

#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutWireSphere(2, 20, 20);  //Draw Sun (radio,H,V);
								//mercurio
	glPushMatrix();

	glColor3f(0.8, 0.6, 0.0);
	glRotatef(mercurio - 3, 0.0, -1.0, 0.0);

	glPushMatrix();
	glTranslatef(3.5, 0.2, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glutWireSphere(0.3, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//venus
	glPushMatrix();

	glRotatef(venus - 3, 0.0, -1.0, 0.0);

	glPushMatrix();
	glColor3f(1.0, 0.6, 0.0);
	glTranslatef(3.5, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glutWireSphere(0.4, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//tierra
	glPushMatrix();
	glRotatef(tierra - 3, 0.0, -1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(5.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glutWireSphere(0.6, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glRotatef(luna - 3, 0.0, -1.0, 0.0);
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, -1.0, 0.0);
	glTranslatef(0.8, 0.8, 0.2);
	glRotatef(luna + 2, 0.0, -1.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//marte
	glPushMatrix();
	glRotatef(marte - 3, 0.0, -1.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(9.5, 0.2, 0.2);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glutWireSphere(0.7, 10, 10);
	glPopMatrix();
	//Anillo
	glPushMatrix();
	glColor3f(0.4, 0.3, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutWireTorus(0.5, 12.5, 5, 60.0);
	glPopMatrix();

	//jupiter
	glPushMatrix();
	glRotatef(jupiter - 3, 0.0, -1.0, 0.0);
	glColor3f(0.6, 0.0, 0.4);
	glTranslatef(15, 0.2, 0.2);
	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glutWireSphere(1.0, 10, 10);
	glPopMatrix();
	//luna
	glPushMatrix();
	glRotatef(luna - 3, 0.0, -1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, -1.0, 0.0);
	glTranslatef(0.8, 0.8, 0.2);
	glRotatef(luna + 2, 0.0, -1.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();
	//luna
	glPushMatrix();
	glRotatef(luna - 3, 0.0, -1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna + 6, 0.0, 1.0, 0.0);
	glTranslatef(0.8, 0.8, 0.2);
	glRotatef(luna + 4, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//saturno
	glPushMatrix();
	glRotatef(saturno - 3, 0.0, -1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(22, 0.2, 0.2);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glutWireSphere(0.3, 10, 10);
	glColor3f(1.0, 1.0, 1.0);
	glutWireTorus(0.11, 0.7, 10.0, 10.0);
	//luna
	glPushMatrix();
	glRotatef(luna - 3, 0.0, -1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, -1.0, 0.0);
	glTranslatef(0.8, 0.8, 0.2);
	glRotatef(luna + 2, 0.0, -1.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();
	//luna
	glPushMatrix();
	glRotatef(luna - 3, 0.0, -1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna + 6, 0.0, 1.0, 0.0);
	glTranslatef(0.8, 0.8, 0.2);
	glRotatef(luna + 4, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//urano
	glPushMatrix();
	glRotatef(urano - 5, 0.0, -1.0, 0.0);
	glColor3f(0.7, 0.6, 0.5);
	glTranslatef(24, 0.2, 0.2);
	glRotatef(urano, 0.0, 1.0, 0.0);
	glutWireSphere(0.7, 10, 10);
	glPopMatrix();

	//neptuno
	glPushMatrix();
	glRotatef(neptuno - 3, 0.0, -1.0, 0.0);
	glColor3f(0.5, 0.5, 0.4);
	glTranslatef(28, 0.2, 0.2);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glutWireSphere(0.6, 10, 10);
	glPopMatrix();


	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		mercurio = (mercurio - 10) % 360;
		dwLastUpdateTime = dwCurrentTime;
		venus = (venus - 9) % 360;
		dwLastUpdateTime = dwCurrentTime;
		tierra = (tierra - 8) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna = (luna - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;
		marte = (marte - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;
		jupiter = (jupiter - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;
		saturno = (saturno - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
		urano = (urano - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;
		neptuno = (neptuno - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}

	glutPostRedisplay(); //vuelvo a dibujar
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);   //Manda a llamar a la animacion
	glutMainLoop();          // 

	return 0;
}
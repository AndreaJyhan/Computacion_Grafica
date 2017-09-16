//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************     OCAÑA CASILLAS ANDREA JYHAN         ******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float angleZ = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;


float angCodo = 0.0f;
float angHombro = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angIndice1 = 0.0f;
float angIndice2 = 0.0f;
float angIndice3 = 0.0f;
float angMedio1 = 0.0f;
float angMedio2 = 0.0f;
float angMedio3 = 0.0f;
float angAnular1 = 0.0f;
float angAnular2 = 0.0f;
float angAnular3 = 0.0f;
float angMeñique1 = 0.0f;
float angMeñique2 = 0.0f;
float angMeñique3 = 0.0f;


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

														//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0,0.0,0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, transZ);
	//Poner Código Aquí.

	glRotatef(angleZ, 0.0, 1.0, 0.0);

	/*Perro*/
	/*glPushMatrix();
	glColor3f(1.0, .0, 0.0);
	glScalef(5.0, 5.0, 1.0);
	prisma(); //cabeza
			  //dónde está el pibote? (0,0)
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.25, -1.5, 0.0);   //hocico
	glScalef(1.5, 2.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.25, -1.0, 0.0);   //lengüita
	glScalef(0.5, 1.0, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 3.5, 0.0);   //oreja 1
	glScalef(1.0, 2.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.88, 4.5, 0.0);   //oreja 1
	glScalef(0.75, 0.75, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 3.5, 0.0);   //oreja 2
	glScalef(1.0, 2.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.88, 4.5, 0.0);   //oreja 2
	glScalef(0.75, 0.75, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.25, -4.0, 0.0);   //cuello
	glScalef(2.5, 3.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0, -8.5, 0.0);   //cuerpo
	glScalef(10.0, 7.0, 1.0);
	glColor3f(0.0, 1.0, 1.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -14.5, 0.0);   //pata 1
	glScalef(1.5, 5.0, 1.0);
	glColor3f(0.0, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.25, -15.0, 0.0);   //pata 2
	glScalef(1.5, 6.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.75, -14.5, 0.0);   //pata 3
	glScalef(1.5, 5.0, 1.0);
	glColor3f(0.0, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.25, -15.0, 0.0);   //pata 4
	glScalef(1.5, 6.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11, -5.5, 0.0);   //cola
	glScalef(2.0, 1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.25, -4.75, 0.0);   //cola
	glScalef(0.5, 0.5, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.75, -4.25, 0.0);   //cola
	glScalef(0.5, 0.5, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();*/

glPushMatrix();
//hombro
glRotatef(angHombro, 0.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.5, 0.5, 1.0);
glColor3f(0.0, 1.0, 1.0);
prisma();
glPopMatrix();

//bicep

glPushMatrix();
glTranslatef(0.0, -0.75, 0.0);
glColor3f(1.0, 0.0, 1.0);
glScalef(0.5, 1.0, 1.0);
prisma();
glPopMatrix();
//codo

glTranslatef(0.0, -0.75, 0.0);
glRotatef(angCodo, 0.0, 0.0, 1.0);
glPushMatrix();
glColor3f(0.0, 0.0, 1.0);
glTranslatef(0.0, -0.75, 0.0);
glScalef(0.5, 0.5, 1.0);
prisma();
glPopMatrix();
//anteBrazo
glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glColor3f(1.0, 0.0, 0.0);
glTranslatef(0.0, -0.75, 0.0);
glScalef(0.5, 1.0, 1.0);
prisma();
glPopMatrix();

//mano
glTranslatef(0.0, -0.75, 0.0);
glRotated(angMano, 0.0, 0.0, 1.0);
glPushMatrix();
glColor3f(0.0, 0.0, 1.0);
glTranslatef(0.0, -0.75, 0.0);
glScalef(0.5, 0.5, 1.0);
prisma();
glPopMatrix();


//pulgar
glPushMatrix();
glTranslatef(0.25, -0.75, 0.0);
glRotatef(angPulgar1, 0.0, 0.0, 1.0);
glTranslatef(0.1, 0.0, 0.0);

glColor3f(0.0, 1.0, 1.0);
glPushMatrix();
glScalef(0.2, 0.1, 1.0);
prisma();
glPopMatrix();
//parte 2
glTranslatef(0.1, 0.0, 0.0);
glRotatef(angPulgar2, 0.0, 0.0, 1.0);
glTranslatef(0.1, 0.0, 0.0);
glColor3f(1.0, 1.0, 1.0);
glScalef(0.2, 0.1, 1.0);
prisma();

glPopMatrix();
//INDICE
glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(angIndice1, 1.0, 0.0, 0.0);
glTranslatef(0.1, 0.0, 0.0);
glColor3f(1.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angIndice2, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angIndice3, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 1.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();

//medio
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(angMedio1, 1.0, 0.0, 0.0);
glTranslatef(0.0, 0.0, 0.0);
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angMedio2, 1.0, 0.0, 0.0);
glTranslatef(-0.05, -0.10, 0.0);
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angMedio3, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 0.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//anular
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(angAnular1, 1.0, 0.0, 0.0);
glTranslatef(-0.15, 0.0, 0.0);
glColor3f(0.0, 1.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angAnular2, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angAnular3, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 0.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//meñique
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(angMeñique1, 1.0, 0.0, 0.0);
glTranslatef(-0.3, 0.0, 0.0);
glColor3f(0.0, 1.0, 0.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angMeñique2, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 0.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(angMeñique3, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(0.0, 1.0, 1.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();


glPopMatrix();

glPushMatrix();
glTranslatef(1.75, -1.25, 0.0);   //torso
glScalef(3.0, 3.0, 1.0);				
glColor3f(0.0, 0.0, 1.0);
prisma();
glPopMatrix();

glPushMatrix();
glTranslatef(1.75, 0.5, 0.0);   //cuello
glScalef(0.5, 0.5, 1.0);				
glColor3f(0.0, 1.0, 0.0);
prisma();
glPopMatrix();

glPushMatrix();
glTranslatef(1.75, 1.25, 0.0);   //cabeza				
glColor3f(0.0, 1.0, 0.0);
prisma();
glPopMatrix();

glPushMatrix();
glTranslatef(4.75, 0.0, 0.0);   //brazo derecho
glScalef(3.0, 0.5, 1.0);				//pibote en ()
glColor3f(0.0, 0.5, 0.5);
prisma();
glPopMatrix();

glPushMatrix();
glTranslatef(2.75, -6.25, 0.0);   //pierna derecha
glScalef(1.0, 7.0, 1.0);				//pibote en ()
glColor3f(0.0, 0.5, 0.5);
prisma();
glPopMatrix();

glPushMatrix();
glTranslatef(0.75, -6.25, 0.0);   //pierna izquierda
glScalef(1.0, 7.0, 1.0);				//pibote en ()
glColor3f(0.0, 0.5, 0.5);
prisma();
glPopMatrix();

	/*Humano

	
glPushMatrix();
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	prisma(); //cabeza
	//dónde está el pibote? (0,0)
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -0.75, 0.0);   //cuello
	glScalef(0.5,0.5,1.0);				//pibote en (0,-0.75,0.0)
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -2.5, 0.0);   //torso
	glScalef(3.0, 3.0, 1.0);				//pibote en (0,-2.5,0.0)
	glColor3f(0.0, 0.0, 1.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.0, -1.5, 0.0);   //brazo derecho
	glScalef(3.0, 1.0, 1.0);				//pibote en ()
	glColor3f(0.0, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0, -1.5, 0.0);   //brazo izquierdo
	glScalef(3.0, 1.0, 1.0);				//pibote en ()
	glColor3f(0.0, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -7.5, 0.0);   //pierna derecha
	glScalef(1.0, 7.0, 1.0);				//pibote en ()
	glColor3f(0.0, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.75, -7.5, 0.0);   //pierna izquierda
	glScalef(1.0, 7.0, 1.0);				//pibote en ()
	glColor3f(0.0, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, -1.5, 0.0);   //mano derecha
	glScalef(2.0, 2.0, 1.0);				//pibote en ()
	glColor3f(0.5, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, -1.5, 0.0);   //mano izquierda
	glScalef(2.0, 2.0, 1.0);				//pibote en ()
	glColor3f(0.5, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.75, -12.5, 0.0);   //pie derecho
	glScalef(3.0,3.0, 1.0);				//pibote en ()
	glColor3f(0.5, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.75, -12.5, 0.0);   //pie izquierdo
	glScalef(3.0, 3.0, 1.0);				//pibote en ()
	glColor3f(0.5, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPopMatrix();

	fin humano
	*/


	//glScalef(3.0, 1.0, 1.0);
	//prisma();


	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case '1':
		angMeñique3 += 0.5f;
		break;
	case '2':
		angMeñique3 -= 0.5f;
		break;

	case '3':
		angMeñique2 += 0.5f;
		break;
	case '4':
		angMeñique2 -= 0.5f;
		break;
	case 'm':
		angMeñique1 += 0.5f;
		break;
	case 'M':
		angMeñique1 -= 0.5f;
		break;
	case 'n':
		angAnular3 += 0.5f;
		break;
	case 'N':
		angAnular3 -= 0.5f;
		break;
	case 'b':
		angAnular2 += 0.5f;
		break;
	case 'B':
		angAnular2 -= 0.5f;
		break;
	case 'v':
		angAnular1 += 0.5f;
		break;
	case 'V':
		angAnular1 -= 0.5f;
		break;
	case 'c':
		angMedio3 += 0.5f;
		break;
	case 'C':
		angMedio3 -= 0.5f;
		break;
	case 'z':
		angMedio2 += 0.5f;
		break;
	case 'Z':
		angMedio2 -= 0.5f;
		break;
	case 'x':
		angMedio1 += 0.5f;
		break;
	case 'X':
		angMedio1 -= 0.5f;
		break;
	case 'j':
		angIndice3 += 0.5f;
		break;
	case 'J':
		angIndice3 -= 0.5f;
		break;
	case 'h':
		angIndice2 += 0.5f;
		break;
	case 'H':
		angIndice2 -= 0.5f;
		break;
	case 'g':
		angIndice1 += 0.5f;
		break;
	case 'G':
		angIndice1 -= 0.5f;
		break;
	case 'F':
		angPulgar2 += 0.5f;
		break;
	case 'f':
		angPulgar2 -= 0.5f;
		break;
	case 'k':
	case 'K':
		angPulgar1 += 0.5f;
		break;
	case 'l':
	case 'L':
		angPulgar1 -= 0.5f;
		break;
	case 'o':
	case 'O':
		angMano += 0.5f;
		break;
	case 'p':
	case'P':
		angMano -= 0.5f;
		break;
	case 'u':
	case 'U':
		angCodo += 0.5f;
		break;
	case 'i':
	case 'I':
		angCodo -= 0.5f;
		break;
	case 't':
	case 'T':
		angHombro += 0.5f;
		break;
	case 'y':
	case 'Y':
		angHombro -= 0.5f;
		break;
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
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
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}

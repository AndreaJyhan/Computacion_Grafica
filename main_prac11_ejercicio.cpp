//Semestre 2018 - 2
//*********************************************************************//
//************** Alumno (s): Ocaña Casillas Andrea Jyhan****************//
//*********************************************************************//

#include "Main.h"
#define MAX_FRAMES 60	
int i_max_steps =1000;		
int i_curr_steps = 0;

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0f;
float angCodo = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float ang1 = 0.0f;
float ang2 = 0.0f;
float ang3 = 0.0f;

float posX = 0, posY = 0.0, posZ = 0.0;		//

float fin_4_5_Abajo = 0, fin_4_5_AbajoInc = 0, fin_4_5_Medio = 0, fin_4_5_MedioInc = 0;
float fin_4_5_Arriba = 0, fin_4_5_ArribaInc = 0;
float fin_2_3_Abajo = 0, fin_2_3_AbajoInc = 0, fin_2_3_Medio = 0, fin_2_3_MedioInc = 0;
float fin_2_3_Arriba = 0, fin_2_3_ArribaInc = 0;
float PulgarDown = 0, PulgarDownInc = 0, PulgarUp = 0, PulgarUpInc = 0;


typedef struct _frame
{
	
	float posX;		
	float posY;		
	float posZ;		
	float incX;		
	float incY;		
	float incZ;		

	float fin_4_5_Abajo, fin_4_5_AbajoInc, fin_4_5_Medio, fin_4_5_MedioInc;
	float fin_4_5_Arriba, fin_4_5_ArribaInc;
	float fin_2_3_Abajo, fin_2_3_AbajoInc, fin_2_3_Medio, fin_2_3_MedioInc;
	float fin_2_3_Arriba, fin_2_3_ArribaInc;
	float PulgarDown, PulgarDownInc, PulgarUp, PulgarUpInc;

}FRAME;		

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;									// Cuando comienza la animacion
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

void saveFrame(void)				// Guardar las posiciones que tiene el personaje
{
	int m = 0, n = 0, i = 0, q = 0, y = 0;
	KeyFrame[0].posX = posX;		// Variables del dibujo del personaje
	KeyFrame[0].posY = posY;
	KeyFrame[0].posZ = posZ;
	
		KeyFrame[0].fin_4_5_Abajo = 80;
		KeyFrame[0].fin_4_5_Medio = 74;
		KeyFrame[0].fin_4_5_Arriba = 47.5;
		KeyFrame[0].PulgarDown = -48.5;
		KeyFrame[0].PulgarUp = -70;
	
	KeyFrame[0].fin_2_3_Abajo = fin_2_3_Abajo;
	KeyFrame[0].fin_2_3_Medio = fin_2_3_Medio;
	KeyFrame[0].fin_2_3_Arriba = fin_2_3_Arriba;

	FrameIndex++;
}
void saveFrame1(void) {
	int b = 0, x = 0, z = 0;
	KeyFrame[1].posX = posX;		// Variables del dibujo del personaje
	KeyFrame[1].posY = posY;
	KeyFrame[1].posZ = posZ;

	KeyFrame[1].fin_4_5_Abajo = 80;
	KeyFrame[1].fin_4_5_Medio = 74;
	KeyFrame[1].fin_4_5_Arriba = 47.5;
	KeyFrame[1].PulgarDown = -48.5;
	KeyFrame[1].PulgarUp = -70;

	for (b = 0; b <= 80; b++) {
		KeyFrame[1].fin_2_3_Abajo = b;
	}
	for (x = 0; x <= 74; x++) {
		KeyFrame[1].fin_2_3_Medio = x;
	}
	for (z = 0; z <= 47.5; z++) {
		KeyFrame[1].fin_2_3_Arriba = z;
	}
	FrameIndex++;

}

void saveFrame2(void) {
	int b = 0, z = 0;
	KeyFrame[2].posX = posX;		// Variables del dibujo del personaje
	KeyFrame[2].posY = posY;
	KeyFrame[2].posZ = posZ;
	KeyFrame[2].fin_4_5_Abajo = 80;
	KeyFrame[2].fin_4_5_Medio = 74;
	KeyFrame[2].fin_4_5_Arriba = 47.5;
	KeyFrame[2].fin_2_3_Abajo = 80;
	KeyFrame[2].fin_2_3_Medio = 74;
	KeyFrame[2].fin_2_3_Arriba = 47.5;
	
	KeyFrame[2].PulgarDown = z;

	KeyFrame[2].PulgarUp = b;
	

	FrameIndex++;

}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	fin_4_5_Abajo = KeyFrame[0].fin_4_5_Abajo;
	fin_4_5_Medio = KeyFrame[0].fin_4_5_Medio;
	fin_4_5_Arriba = KeyFrame[0].fin_4_5_Arriba;

	fin_2_3_Abajo = KeyFrame[0].fin_2_3_Abajo;
	fin_2_3_Medio = KeyFrame[0].fin_2_3_Medio;
	fin_2_3_Arriba = KeyFrame[0].fin_2_3_Arriba;

	PulgarDown = KeyFrame[0].PulgarDown;
	PulgarUp = KeyFrame[0].PulgarUp;
}


void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].fin_4_5_AbajoInc = (KeyFrame[playIndex + 1].fin_4_5_Abajo - KeyFrame[playIndex].fin_4_5_Abajo) / i_max_steps;
	KeyFrame[playIndex].fin_4_5_MedioInc = (KeyFrame[playIndex + 1].fin_4_5_Medio - KeyFrame[playIndex].fin_4_5_Medio) / i_max_steps;
	KeyFrame[playIndex].fin_4_5_ArribaInc = (KeyFrame[playIndex + 1].fin_4_5_Arriba - KeyFrame[playIndex].fin_4_5_Arriba) / i_max_steps;

	KeyFrame[playIndex].fin_2_3_AbajoInc = (KeyFrame[playIndex + 1].fin_2_3_AbajoInc - KeyFrame[playIndex].fin_2_3_AbajoInc) / i_max_steps;
	KeyFrame[playIndex].fin_2_3_MedioInc = (KeyFrame[playIndex + 1].fin_2_3_Medio - KeyFrame[playIndex].fin_2_3_Medio) / i_max_steps;
	KeyFrame[playIndex].fin_2_3_ArribaInc = (KeyFrame[playIndex + 1].fin_2_3_Arriba - KeyFrame[playIndex].fin_2_3_Arriba) / i_max_steps;

	KeyFrame[playIndex].PulgarDownInc = (KeyFrame[playIndex + 1].PulgarDown - KeyFrame[playIndex].PulgarDown) / i_max_steps;
	KeyFrame[playIndex].PulgarUpInc = (KeyFrame[playIndex + 1].PulgarUp - KeyFrame[playIndex].PulgarUp) / i_max_steps;


}



void InitGL ( void )     // Inicializamos parametros
{
	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer

	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//glEnable(GL_LIGHTING);

	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar

	//glEnable ( GL_COLOR_MATERIAL );

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].posY = 0;
		KeyFrame[i].posZ = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].fin_4_5_Abajo = 0;
		KeyFrame[i].fin_4_5_AbajoInc = 0;
		KeyFrame[i].fin_4_5_Medio = 0;
		KeyFrame[i].fin_4_5_MedioInc = 0;
		KeyFrame[i].fin_4_5_Arriba = 0;
		KeyFrame[i].fin_4_5_ArribaInc = 0;
		KeyFrame[i].fin_2_3_Abajo = 0;
		KeyFrame[i].fin_2_3_AbajoInc = 0;
		KeyFrame[i].fin_2_3_Medio = 0;
		KeyFrame[i].fin_2_3_MedioInc = 0;
		KeyFrame[i].fin_2_3_Arriba = 0;
		KeyFrame[i].fin_2_3_ArribaInc = 0;
		KeyFrame[i].PulgarDown = 0;
		KeyFrame[i].PulgarDownInc = 0;
		KeyFrame[i].PulgarUp = 0;
		KeyFrame[i].PulgarUpInc = 0;
	}
}



void prisma(void)

{

	GLfloat vertice [8][3] = {

				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0

				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1

				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2

				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3

				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4

				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5

				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6

				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7

				};



		glBegin(GL_POLYGON);	//Front

			//glColor3f(1.0,0.0,0.0);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[1]);

		glEnd();



		glBegin(GL_POLYGON);	//Right

			glColor3f(0.0,0.0,1.0);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[4]);

		glEnd();



		glBegin(GL_POLYGON);	//Back

			glColor3f(0.0,1.0,0.0);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Left

			glColor3f(1.0,1.0,1.0);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Bottom

			glColor3f(0.4,0.2,0.6);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[2]);

			glVertex3fv(vertice[3]);

		glEnd();



		glBegin(GL_POLYGON);  //Top

			glColor3f(0.8,0.2,0.4);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[7]);

		glEnd();

}



void display ( void )   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer

	//glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();


	glTranslatef(transX, 0.0f, transZ);

	glRotatef(angleY, 0.0, 1.0, 0.0);

	glRotatef(angleX, 1.0, 0.0, 0.0);

		//Poner Código Aquí.
	glPushMatrix();
	glRotatef(90.0, 0, 0, 1);
	glRotatef(90.0, -1, 0, 0);

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


//MANO
glTranslatef(0.0, -0.75, 0.0);
glRotated(angMano, 0.0, 0.0, 1.0);
glPushMatrix();
glColor3f(0.0, 0.0, 1.0);
glTranslatef(0.0, -0.75, 0.0);
glScalef(0.5, 0.5, 1.0);
prisma();
glPopMatrix();

//PULGAR
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
glRotatef(ang1 + fin_2_3_Abajo, 1.0, 0.0, 0.0);
glTranslatef(0.1, 0.0, 0.0);
glColor3f(1.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang2 + fin_2_3_Medio, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang3 + fin_2_3_Arriba, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 1.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();


//MEDIO
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(ang1 + fin_2_3_Abajo, 1.0, 0.0, 0.0);
glTranslatef(0.0, 0.0, 0.0);
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang2 + fin_2_3_Medio, 1.0, 0.0, 0.0);
glTranslatef(-0.05, -0.10, 0.0);
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang3 + fin_2_3_Arriba, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 0.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();

//ANULAR
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(ang1 + fin_4_5_Abajo, 1.0, 0.0, 0.0);
glTranslatef(-0.15, 0.0, 0.0);
glColor3f(0.0, 1.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang2 + fin_4_5_Medio, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 0.0, 1.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang3 + fin_4_5_Arriba, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 0.0);
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();

//MEÑIQUE
//glTranslatef(0.0, -0.75, 0.0);
glPushMatrix();
glTranslatef(0.1, -0.35, 0.0);
glRotatef(ang1 + fin_4_5_Abajo, 1.0, 0.0, 0.0);
glTranslatef(-0.3, 0.0, 0.0);
glColor3f(0.0, 1.0, 0.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte2
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang2 + fin_4_5_Medio, 1.0, 0.0, 0.0);
glTranslatef(0.0, -0.10, 0.0);
glColor3f(1.0, 1.0, 0.0);
glPushMatrix();
glScalef(0.1, 0.2, 1.0);
prisma();
glPopMatrix();
//parte3
glTranslatef(0.0, -0.10, 0.0);
glRotatef(ang3 + fin_4_5_Arriba, 1.0, 0.0, 0.0);
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
	
		
									

  glutSwapBuffers ( );

  // Swap The Buffers

}


void animacion()
{
	//Movimiento del monito
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{														
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			fin_4_5_Abajo += KeyFrame[playIndex].fin_4_5_AbajoInc;
			fin_4_5_Medio += KeyFrame[playIndex].fin_4_5_MedioInc;
			fin_4_5_Arriba += KeyFrame[playIndex].fin_4_5_ArribaInc;

			fin_2_3_Abajo += KeyFrame[playIndex].fin_2_3_AbajoInc;
			fin_2_3_Medio += KeyFrame[playIndex].fin_2_3_MedioInc;
			fin_2_3_Arriba += KeyFrame[playIndex].fin_2_3_ArribaInc;

			PulgarDown += KeyFrame[playIndex].PulgarDownInc;
			PulgarUp += KeyFrame[playIndex].PulgarUpInc;

			i_curr_steps++;
		}

	}


	glutPostRedisplay();
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

	//glOrtho(-5,5,-5,5,0.2,20);	

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

}



void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function

{

	switch ( key ) {

		
	case 'r':
		if (ang3 <= 47.5) {
			ang3 += 0.5f;
		}
		if (angPulgar2 >= -70.0) {
			angPulgar2 -= 0.5f;
		}
		break;
	case 'R':
		if (ang3 >= 0) {
			ang3 -= 0.5f;
		}
		if (angPulgar2 <= 0) {
			angPulgar2 += 0.5f;
		}
		break;

		
	case 'j':
		if (ang2 <= 74) {
			ang2 += 0.5f;
		}
		if (angPulgar1 >= -48.5) {
			angPulgar1 -= 0.5f;
		}
		break;
	case 'J':
		if (ang2 >= 0) {
			ang2 -= 0.5f;
		}
		if (angPulgar1 <= 0) {
			angPulgar1 += 0.5f;
		}
		break;

		
	case 'c':
		if (ang1 <= 80) {
			ang1 += 0.5f;
		}
		break;
	case 'C':
		if (ang1 >= 0) {
			ang1 -= 0.5f;
		}
		break;

	case 'o':
	case 'O':
		if (angMano <= 19.0) {
			angMano += 0.5f;
		}
		break;
	case 'p':
	case 'P':
		if (angMano >= -19.0) {
			angMano -= 0.5f;
		}
		break;

	case 'u':
	case 'U':
		if (angCodo <= 127) {
			angCodo += 0.5f;
		}
		break;
	case 'I':
	case 'i':
		if (angCodo >= 0) {
			angCodo -= 0.5f;
		}
		break;

		//**************manipulación de brazo*********************
	case 't':
	case 'T':
		if (angHombro <= 0) {
			angHombro += 0.5f;
		}
		break;
	case 'Y':
	case 'y':
		if (angHombro >= -90.0) {
			angHombro -= 0.5f;
		}
		break;

	case 'k':		
	case 'K':
		
			saveFrame();
			display();
			saveFrame1();
			saveFrame2();

			if (play == false && (FrameIndex>1))
			{

				resetElements();
							
				interpolation();
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}

		break;

		//Acercamiento

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



void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)

{

  switch ( a_keys ) {

  case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...

	  angleX += 2.0f;

	  break;

  case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...

	  angleX -= 2.0f;

	  break;

  case GLUT_KEY_LEFT:

	  angleY += 2.0f;

	  break;

  case GLUT_KEY_RIGHT:

	  angleY -= 2.0f;

	  break;

  default:

	  break;

  }

  glutPostRedisplay();

}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

void menu(int id)
{

}

int main ( int argc, char** argv )   // Main Function

{
	int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL

  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )

  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

  screenW = glutGet(GLUT_SCREEN_WIDTH);

  screenH = glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana

  glutInitWindowPosition (0, 0);	//Posicion de la Ventana

  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana

  printf("Resolution H: %i \n", screenW);

  printf("Resolution V: %i \n", screenH);

  InitGL ();						// Parametros iniciales de la aplicacion

  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo

  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano

  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado

  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc(animacion);
  submenu = glutCreateMenu(menuKeyFrame);
  glutAddMenuEntry("Guardar KeyFrame", 0);
  glutAddMenuEntry("Reproducir Animacion", 1);
  glutCreateMenu(menu);
  glutAddSubMenu("Animacion Monito", submenu);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop        ( );          // 



  return 0;

}







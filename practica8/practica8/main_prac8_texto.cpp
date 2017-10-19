//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		OCAÑA CASILLAS ANDREA JYHAN		******//
//*************											******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;               //VARIABLES DE TIPO TEXTURA
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_rocas;
CTexture t_borde;
CTexture t_teja;
CTexture t_cabaña;
CTexture t_cristal;
CTexture t_puerta;
CTexture t_puertaatras;




int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_rocas.LoadTGA("rocas.tga");          //CARGA EL ARCHIVO
	t_rocas.BuildGLTexture();             //GENERA LA TEXTURA
	t_rocas.ReleaseImage();              //PARA PODER OCUPARLA

	t_borde.LoadTGA("borde.tga");          //CARGA EL ARCHIVO
	t_borde.BuildGLTexture();             //GENERA LA TEXTURA
	t_borde.ReleaseImage();

	t_cristal.LoadTGA("cristal.tga");          //CARGA EL ARCHIVO
	t_cristal.BuildGLTexture();             //GENERA LA TEXTURA
	t_cristal.ReleaseImage();

	t_cabaña.LoadTGA("madera.tga");          //CARGA EL ARCHIVO
	t_cabaña.BuildGLTexture();             //GENERA LA TEXTURA
	t_cabaña.ReleaseImage();

	t_teja.LoadTGA("teja.tga");          //CARGA EL ARCHIVO
	t_teja.BuildGLTexture();             //GENERA LA TEXTURA
	t_teja.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga");          //CARGA EL ARCHIVO
	t_puerta.BuildGLTexture();             //GENERA LA TEXTURA
	t_puerta.ReleaseImage();

	t_puertaatras.LoadTGA("puerta_atras.tga");          //CARGA EL ARCHIVO
	t_puertaatras.BuildGLTexture();             //GENERA LA TEXTURA
	t_puertaatras.ReleaseImage();
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);     //0
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);           //4
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);     //7
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);      //1
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);   //1
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]); //7
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);   //6
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);//2
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);
		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);

		glPushMatrix();                                      //puerta
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 20.0, 1.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		prisma(t_puerta.GLindex, t_borde.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();                                      //techo
		glTranslatef(9.0, 21.5, -30.65);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(41.0, 3.0, 63.0);
		prisma(t_teja.GLindex, t_teja.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //escalon 1
		glTranslatef(0.0, -10.5, 1.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 1.0, 3.0);
		prisma(t_rocas.GLindex, t_borde.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //escalon 2
		glTranslatef(0.0, -11.5, 2.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 1.0, 5.0);
		prisma(t_rocas.GLindex, t_borde.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //up1
		glTranslatef(0.0, 15.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 10.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //up2
		glTranslatef(16, 15.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(11.0, 10.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //down
		glTranslatef(16, -7.5, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(11.0, 9.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //ventana
		glTranslatef(16, 3.5, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(11.0, 13.0, 1.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		prisma(t_cristal.GLindex, t_cristal.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();                                      //costado derecho
		glTranslatef(7, 4.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 32.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //costado derecho
		glTranslatef(25, 4.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 32.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //costado izquierdo
		glTranslatef(-7.0, 4.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 32.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //costado izquierdo
		glTranslatef(-10.0, 4.0, -30.5);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(1.0, 32.0, 60.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //costado derecho
		glTranslatef(28, 4.0, -30.5);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(1.0, 32.0, 60.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		//parte trasera
		glPushMatrix();                                      //costado derecho
		glTranslatef(25, 4.0, -61.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 32.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //costado izquierdo
		glTranslatef(-7.0, 4.0, -61.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(7.0, 32.0, 1.0);
		prisma(t_cabaña.GLindex, t_cabaña.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //puerta atras
		glTranslatef(9.0, 4.0, -61.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(25.0, 32.0, 1.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		prisma(t_puertaatras.GLindex, t_borde.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();


	
		/*
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glScalef(10.0,2.0,10.0);  
			prisma(t_Ajedrez2.GLindex, t_Ajedrez1.GLindex);
		glPopMatrix();
		*/
		/*
		glPushMatrix();                                      //mesa1
		glTranslatef(5.5, 0.0, 0.0);
		glColor3f(1.0, 2.0, 1.0);
		glScalef(1.0, 2.0, 10.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //mesa2
		glTranslatef(-5.5, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 2.0, 10.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //mesa3
		glTranslatef(0.0, 0.0, 5.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(12.0, 2.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //mesa4
		glTranslatef(0.0, 0.0, -5.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(12.0, 2.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();


		glPushMatrix();                                      //pata1
		glTranslatef(4.5,-5.0,4.5);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1.0, 8.0, 1.0);
			prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
		glPopMatrix();
		 
		glPushMatrix();                                    //pata2
		glTranslatef(-4.5, -5.0, 4.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 8.0, 1.0);
		prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //pata3
		glTranslatef(4.5, -5.0, -4.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 8.0, 1.0);
		prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //pata4
		glTranslatef(-4.5, -5.0, -4.5);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 8.0, 1.0);
		prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
		glPopMatrix();

		//silla
		glPushMatrix();                                      //respaldo
		glTranslatef(16.0, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 8.0, 7.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //asiento
		glTranslatef(13.75, -3.75, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4, 0.5, 7.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();
		
		glPushMatrix();                                      //pata
		glTranslatef(16.0, -7.5, -3.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 7.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //pata2
		glTranslatef(16.0, -7.5, 3.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 7.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //pata3
		glTranslatef(12.0, -7.5, 3.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 7.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();

		glPushMatrix();                                      //pata4
		glTranslatef(12.0, -7.5, -3.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 7.0, 1.0);
		prisma(t_borde.GLindex, t_metal01.GLindex);
		glPopMatrix();
		*/


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
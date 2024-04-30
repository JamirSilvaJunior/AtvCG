# include <GL/glut.h>

int anguloSol = 0;
int anguloTerra = 0;
int anguloLua = 0;
float camZ = -150.0f;

/*
void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angulo, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0);
	glutWireCube(40);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(60, 40, 40);
	glPopMatrix();
	glFlush();
}

void anima(int x)
{
	angulo++;
	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);
}

void inicializa()
{
	glClearColor(255, 255, 255, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 10, 280);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(50, 50, 150, 0, 0, 0, 0, 1, 0);
	glEnable(GL_DEPTH_TEST);
}

int main(void)
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D");
	inicializa();
	anima(1);
	glutDisplayFunc(desenha);
	glutMainLoop();
}
*/

/* 
void anima(int x)
{
	angulo++;
	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);
}

void desenha()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angulo, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0);

	//cubo esquerda
	glPushMatrix();
	glTranslatef(50, 0, 0);
	glutWireCube(40);
	glPopMatrix();

	//cubo direita
	glPushMatrix();
	glTranslatef(-50, 0, 0);
	glutWireCube(40);
	glPopMatrix();

	//cubo centro
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glutWireCube(40);
	glPopMatrix();

	//cubo cima
	glPushMatrix();
	glTranslatef(0, 50, 0);
	glutWireCube(40);
	glPopMatrix();

	//cubo baixo
	glPushMatrix();
	glTranslatef(0, -50, 0);
	glutWireCube(40);
	glPopMatrix();

	//cubo frente
	glPushMatrix();
	glTranslatef(0, 0, 50);
	glutWireCube(40);
	glPopMatrix();

	//cubo trás
	glPushMatrix();
	glTranslatef(0, 0, -50);
	glutWireCube(40);
	glPopMatrix();

	//glutWireSphere(60, 40, 40);
	glPopMatrix();
	glFlush();
}

void inicializa()
{
	glClearColor(255, 255, 255, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 10, 280);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(50, 50, 150, 0, 0, 0, 0, 1, 0);
	glEnable(GL_DEPTH_TEST);
}

int main(void)
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D");
	inicializa();
	anima(1);
	glutDisplayFunc(desenha);
	glutMainLoop();
}
*/


void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sol
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, 0, 0);
	glRotatef(anguloSol, 0, 1, 0);
	glutWireSphere(50, 30, 10);


	// Terra
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(100, 0, 0);
	glRotatef(anguloTerra, 0, 1, 0);
	glutWireSphere(20, 30, 10);


	//Lua
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(30, 20, 0);
	glRotatef(anguloLua, 0, 1, 0);
	glutWireSphere(5, 30, 10);
	glPopMatrix();
	glFlush();
}

void animaSol(int x)
{
	anguloSol++;
	glutPostRedisplay();
	glutTimerFunc(1, animaSol, 1);
}

void animaTerra(int x)
{
	anguloTerra++;
	glutPostRedisplay();
	glutTimerFunc(1, animaTerra, 1);
}

void animaLua(int x)
{
	anguloLua++;
	glutPostRedisplay();
	glutTimerFunc(1, animaLua, 1);
}

void inicializa()
{
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100, 1, 20, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 150, 130, 0, 0, 0, 0, 1, 0.5);
	glEnable(GL_DEPTH_TEST);
}

void interacaoTeclado(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		camZ *= 1.1f;
		break;
	case GLUT_KEY_DOWN:
		camZ -= 1.1f;
		break;
	}

	glutPostRedisplay();
}

int main(void)
{

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D");
	inicializa();
	animaSol(1);
	animaTerra(1);
	animaLua(1);
	glutDisplayFunc(desenha);
	glutSpecialFunc(interacaoTeclado);
	glutMainLoop();
}


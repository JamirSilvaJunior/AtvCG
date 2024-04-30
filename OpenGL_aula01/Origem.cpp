#include <GL/glut.h>

void desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //Limpar fundo da janela com a cor que estiver no buffer de limpeza
	glColor3f(255, 0, 0); //3f=3 parametros do tipo float (R,G,B)
	glBegin(GL_LINES);
		glVertex2f(-1.0, 1.0);
		glVertex2f(1.0, -1.0);
	glEnd();
	glFlush();
}

void inicializa(void)
{
	glClearColor(0, 0, 0, 1);//R,G,B,ALPHA(transparencia, 1 significa que não possui)
}

int main(void)
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Primeiro Desenho");
	inicializa();
	glutDisplayFunc(desenha);
	glutMainLoop();
}
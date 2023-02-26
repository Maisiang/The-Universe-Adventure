#include <glut.h>
#pragma once
void Draw_region(int x, int y, int r, int g, int b)
{
	//�~������
	glBegin(GL_LINE_LOOP);
		glColor3f(r, g, b);
		glVertex3f(-x, y, 0);//���W
		glVertex3f(x, y, 0);//�k�W
		glVertex3f(x, -y, 0);//�k�U
		glVertex3f(-x, -y, 0);//���U
	glEnd();
}
// �Ψ�ø�s�C��
void Draw_frog()
{
	//�~������
	glBegin(GL_LINE_LOOP);
		glColor3f(1, 0, 0);
		glVertex3f(-40, 60, 0);//���W
		glVertex3f(40, 60, 0);//�k�W
		glVertex3f(40, -50, 0);//�k�U
		glVertex3f(-40, -50, 0);//���U
	glEnd();
	//�إ� Quadrics
	GLUquadricObj* quadricPtr;
	quadricPtr = gluNewQuadric();
	gluQuadricDrawStyle(quadricPtr, GLU_FILL); //��
	gluQuadricNormals(quadricPtr, GLU_NONE);
	//�Y radius=30
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //�L��
		glTranslatef(0, 30, 0);
		gluSphere(quadricPtr, 30, 15, 10);
	glPopMatrix();
	//�k�� radius=15
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //�զ�
		glTranslatef(15, 50, 20);
		gluSphere(quadricPtr, 15, 15, 10);
	glPopMatrix();

	//�k���y radius=5
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //�¦�
		glTranslatef(10, 50, 33);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//���� radius=15
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //�զ�
		glTranslatef(-15, 50, 20);
		gluSphere(quadricPtr, 15, 15, 10);
	glPopMatrix();

	//�����y radius=5
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //�¦�
		glTranslatef(-10, 50, 35);
		glBegin(GL_LINE_STRIP);
			glVertex3f(-5.0, 5.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(-5.0, -5.0, 0.0);
		glEnd();
	glPopMatrix();

	//�k�|�� radius=5
	glPushMatrix();
		glColor3f(1.0, 0.7, 0.8); //����
		glTranslatef(-15, 25, 23);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//���|�� radius=5
	glPushMatrix();
		glColor3f(1.0, 0.7, 0.8); //����
		glTranslatef(15, 25, 23);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//�L��
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //�¦�
		glTranslatef(0, 5, 24);
		glBegin(GL_LINE_STRIP);
			glVertex3f(-10.0, 10.0, 0.0);
			glVertex3f(0.0, 5.0, 0.0);
			glVertex3f(10.0, 10.0, 0.0);
		glEnd();
	glPopMatrix();

	//���� B_R=30 , T_R=15 , height=30
	glPushMatrix();
		glColor3f(1.0, 0.3, 0.4); //����
		glTranslatef(0, -25, 0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		gluCylinder(quadricPtr, 30, 15, 30, 15, 50);
	glPopMatrix();

	//���� radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //�L��
		glTranslatef(-25, -10, 0);
		glRotatef(-45, 0, 0, 1);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//�k�� radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //�L��
		glTranslatef(25, 0, 0);
		glRotatef(100, 0, 0, 1);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//���} radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //�L��
		glTranslatef(-10, -30, 0);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//�k�} radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //�L��
		glTranslatef(10, -30, 0);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//������
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //�¦�
		glTranslatef(-10, 5, 35);
		glBegin(GL_POLYGON);
			glVertex3f(0, 0, 0);
			glVertex3f(10, -5, 0);
			glVertex3f(0, -10, 0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, 5, 35);
		glRotatef(-180, 0, 1, 0);
		glBegin(GL_POLYGON);
			glVertex3f(0, 0, 0);
			glVertex3f(10, -5, 0);
			glVertex3f(0, -10, 0);
		glEnd();
	glPopMatrix();
	//��A
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //�զ�
		glTranslatef(-10, 5, 30);
		glBegin(GL_POLYGON);
			glVertex3f(8, 0, 0);
			glVertex3f(8, -30, 0);
			glVertex3f(13, -30, 0);
			glVertex3f(13, 0, 0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3f(18, 0, 0);
			glVertex3f(18, -30, 0);
			glVertex3f(23, -30, 0);
			glVertex3f(23, 0, 0);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //�զ�
		glTranslatef(-10, -10, 21.4);
		glRotatef(-23, 1, 0, 0);
		glScalef(0.5, 2.12, 0.2);
		glutSolidCube(15);
	glPopMatrix();

	//�R�� Quadrics
	gluDeleteQuadric(quadricPtr);
}

void Draw_XYZ(int window_x, int window_y , int window_z)
{
	// XYZ
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //�զ�
		glVertex3f(-window_x-50 , 0.0, 0.0);
		glVertex3f(window_x+50 , 0.0, 0.0);
	glEnd();
	/*
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //�զ�
		glVertex3f(0.0, -window_y , 0.0);
		glVertex3f(0.0, window_y , 0.0);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //�զ�
		glVertex3f(0.0, 0.0, window_z);
		glVertex3f(0.0, 0.0, -window_z);
	glEnd();
	*/
}
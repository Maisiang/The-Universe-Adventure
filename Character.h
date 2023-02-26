#include <glut.h>
#pragma once
void Draw_region(int x, int y, int r, int g, int b)
{
	//外圈長方形
	glBegin(GL_LINE_LOOP);
		glColor3f(r, g, b);
		glVertex3f(-x, y, 0);//左上
		glVertex3f(x, y, 0);//右上
		glVertex3f(x, -y, 0);//右下
		glVertex3f(-x, -y, 0);//左下
	glEnd();
}
// 用來繪製青蛙
void Draw_frog()
{
	//外圈長方形
	glBegin(GL_LINE_LOOP);
		glColor3f(1, 0, 0);
		glVertex3f(-40, 60, 0);//左上
		glVertex3f(40, 60, 0);//右上
		glVertex3f(40, -50, 0);//右下
		glVertex3f(-40, -50, 0);//左下
	glEnd();
	//建立 Quadrics
	GLUquadricObj* quadricPtr;
	quadricPtr = gluNewQuadric();
	gluQuadricDrawStyle(quadricPtr, GLU_FILL); //填滿
	gluQuadricNormals(quadricPtr, GLU_NONE);
	//頭 radius=30
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //淺綠
		glTranslatef(0, 30, 0);
		gluSphere(quadricPtr, 30, 15, 10);
	glPopMatrix();
	//右眼 radius=15
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //白色
		glTranslatef(15, 50, 20);
		gluSphere(quadricPtr, 15, 15, 10);
	glPopMatrix();

	//右眼球 radius=5
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //黑色
		glTranslatef(10, 50, 33);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//左眼 radius=15
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //白色
		glTranslatef(-15, 50, 20);
		gluSphere(quadricPtr, 15, 15, 10);
	glPopMatrix();

	//左眼球 radius=5
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //黑色
		glTranslatef(-10, 50, 35);
		glBegin(GL_LINE_STRIP);
			glVertex3f(-5.0, 5.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(-5.0, -5.0, 0.0);
		glEnd();
	glPopMatrix();

	//右腮紅 radius=5
	glPushMatrix();
		glColor3f(1.0, 0.7, 0.8); //粉紅
		glTranslatef(-15, 25, 23);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//左腮紅 radius=5
	glPushMatrix();
		glColor3f(1.0, 0.7, 0.8); //粉紅
		glTranslatef(15, 25, 23);
		gluSphere(quadricPtr, 5, 15, 10);
	glPopMatrix();

	//嘴巴
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //黑色
		glTranslatef(0, 5, 24);
		glBegin(GL_LINE_STRIP);
			glVertex3f(-10.0, 10.0, 0.0);
			glVertex3f(0.0, 5.0, 0.0);
			glVertex3f(10.0, 10.0, 0.0);
		glEnd();
	glPopMatrix();

	//身體 B_R=30 , T_R=15 , height=30
	glPushMatrix();
		glColor3f(1.0, 0.3, 0.4); //粉紅
		glTranslatef(0, -25, 0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		gluCylinder(quadricPtr, 30, 15, 30, 15, 50);
	glPopMatrix();

	//左手 radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //淺綠
		glTranslatef(-25, -10, 0);
		glRotatef(-45, 0, 0, 1);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//右手 radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //淺綠
		glTranslatef(25, 0, 0);
		glRotatef(100, 0, 0, 1);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//左腳 radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //淺綠
		glTranslatef(-10, -30, 0);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//右腳 radius=10
	glPushMatrix();
		glColor3f(0.9, 1.0, 0.4); //淺綠
		glTranslatef(10, -30, 0);
		glScalef(1, 2, 1);
		gluSphere(quadricPtr, 10, 15, 10);
	glPopMatrix();

	//蝴蝶結
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); //黑色
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
	//衣服
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //白色
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
		glColor3f(1.0, 1.0, 1.0); //白色
		glTranslatef(-10, -10, 21.4);
		glRotatef(-23, 1, 0, 0);
		glScalef(0.5, 2.12, 0.2);
		glutSolidCube(15);
	glPopMatrix();

	//刪除 Quadrics
	gluDeleteQuadric(quadricPtr);
}

void Draw_XYZ(int window_x, int window_y , int window_z)
{
	// XYZ
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //白色
		glVertex3f(-window_x-50 , 0.0, 0.0);
		glVertex3f(window_x+50 , 0.0, 0.0);
	glEnd();
	/*
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //白色
		glVertex3f(0.0, -window_y , 0.0);
		glVertex3f(0.0, window_y , 0.0);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(1, 1, 1); //白色
		glVertex3f(0.0, 0.0, window_z);
		glVertex3f(0.0, 0.0, -window_z);
	glEnd();
	*/
}
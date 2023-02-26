#define GLUT_DISABLE_ATEXIT_HACK

#include <sstream>
#include <windows.h>
#include <time.h>
#include <glut.h>

#include "Character.h"
#include "texture.h"

using namespace std;

/* Functionn */
void timer(int t);
void drawtext(const char *text, int length, int x, int y);
void mydisplay();
void init();
void keyboard(unsigned char key, int x, int y);
void collision_outcome(int x1, int y1, int x2, int y2, int w1, int h1, int w2, int h2);
void idle();

/* Variable */
int window_x = 500, window_y = 500, window_z = 500; // 視窗大小
float move_x , move_y;		// 角色移動的位置
float px , py ;				// 取角色右上點
float obs_x[4] , obs_y[4] ; // 障礙物右上點、第4個為地球
int collision = 0;			// 有無碰撞
float speed = 0.5;			// 敵人移動速度
int angle = 0;				// 角色轉動角度
float dis_x, dis_y;			// 角色移動速度
int life,game_timer,score,max_score=-10000;	// 玩家生命、時間、分數、最大的分數
int angle_obs[3] = { 15 , 30, 60 };			// 各障礙物轉動角度
int rnd_x;					// 障礙物亂數 x 的正或負
int Game = 0;
/* 貼圖 */
GLUquadricObj* ball;
GLuint tex[5];

void timer(int t)
{
	std::string end , index;
	stringstream end_ss , index_ss;
	/*    遊戲結束    */
	if (game_timer <= 0)
	{
		Game = 2;
		end_ss << "Time's up!! Your Score:" << score;
		end = end_ss.str();
		drawtext(end.data(), end.size(), 380, 310);
	}
	else if (life <= 0)
	{
		Game = 2;
		end_ss << "GAME OVER!! Your Score:" << score;
		end = end_ss.str();
		drawtext(end.data(), end.size(), 380, 310);
	}
	if (Game == 1)
	{
		game_timer--;
		glutPostRedisplay();
	}
	else if (Game == 2)
	{
		index_ss << "Press \"h\" or \"H\" to Restart!!";
		index = index_ss.str();
		drawtext(index.data(), index.size(), 380, 330);
	}
	glutTimerFunc(1000, timer, 0);
}
void drawtext(const char *text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char** argv) {
	srand(time(NULL));
	glutInitWindowSize(window_x, window_y);
	glutCreateWindow("OPENGL");
	glutDisplayFunc(mydisplay);
	glutTimerFunc(1000, timer, 0);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	init();

	glutMainLoop();
}
void mydisplay() 
{
	if (Game != 2)
	{
		// 清除緩衝區
		glClearColor(0.0, 0.5, 1.0, 0.0);	// 藍色
		glClearColor(0, 0, 0, 0);			// 黑色背景
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// 深度測試 貼圖
		glEnable(GL_DEPTH_TEST);
		glLightModeli(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	}
	
	if (Game == 0)
	{
		/* 開始text */
		std::string start , rule[3];
		stringstream start_ss , rule_ss[3];
		start_ss << "Press \"G\" or \"g\" to start!!";
		start = start_ss.str();
		drawtext(start.data(), start.size(),100, 340);
		rule_ss[0] << "eat \"Earth\" score+20  |  eat \"Mars\" score-15";
		rule_ss[1] << "You have 3 lives and 30 seconds";
		rule_ss[2] << "W(up)   A(left)   S(down)   D(right)";
		rule[0] = rule_ss[0].str();
		rule[1] = rule_ss[1].str();
		rule[2] = rule_ss[2].str();
		drawtext(rule[0].data(), rule[0].size(), 100, 300);
		drawtext(rule[1].data(), rule[1].size(), 100, 260);
		drawtext(rule[2].data(), rule[2].size(), 100, 220);
	}
	else if(Game==1)
	{
		/*    遊戲繪圖區    */
		// X軸
		glPushMatrix();
			Draw_XYZ(window_x - 50, window_y - 50, window_z);
		glPopMatrix();

		/*    貼圖區    */
		glEnable(GL_TEXTURE_2D); // texture 開啟
		// 隕石
		for (int i = 0; i < 3; i++)
		{
			int size = 60 - (i * 10); // 決定障礙物大小
			glPushMatrix();
				glTranslatef(obs_x[i] - size, obs_y[i] - size, -50);
				glRotatef(angle_obs[i], i, 1, i % 2);
				glBindTexture(GL_TEXTURE_2D, tex[0]); // We set the active texture 
				gluSphere(ball, size, 25, 25);
				Draw_region(size, size, 1, 0, 0);
			glPopMatrix();
		}
		// 地球
		glPushMatrix();
			glTranslatef(obs_x[3] - 50, obs_y[3] - 50, -50);
			glRotatef(-angle_obs[3], 1, 1, 1);
			glBindTexture(GL_TEXTURE_2D, tex[1]); // We set the active texture 
			gluSphere(ball, 50, 25, 25);
			Draw_region(50, 50, 1, 1, 0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0 , 0 , -450);
			glRotatef(-45, 0, 0, 1);
			glBindTexture(GL_TEXTURE_2D, tex[2]); // We set the active texture 
			gluDisk(ball, 0.0, 700, 4, 1);

			Draw_region(50, 50, 1, 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D); //texture關閉
	}
	/*  青蛙  */
	glPushMatrix();
		glTranslatef(move_x, move_y, -50);
		glRotatef(angle, 0, 1, 0);
		Draw_frog();
	glPopMatrix();
	// 遊戲狀態輸出
	if ((score > max_score)&&Game==2)
		max_score = score;
	std::string text;
	stringstream ss;
	if (max_score == -10000)
		ss << "  Life: " << life << "   |  Time: " << game_timer << "   |  Score: " << score << "   |  Max: N/A";
	else
		ss << "  Life: " << life << "   |  Time: " << game_timer << "   |  Score: " << score << "   |  Max: " << max_score;
	text = ss.str();
	drawtext(text.data(), text.size(), 0, 580);

	glFlush();
}

void init()
{
	//建立投影矩陣
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-window_x, window_x , -window_y , window_y , -window_z , window_z);
	glMatrixMode(GL_MODELVIEW);

	/*建立物件*/
	ball = gluNewQuadric();
	gluQuadricDrawStyle(ball, GLU_FILL); //填滿
	gluQuadricNormals(ball, GLU_SMOOTH);//shaing 模式
	gluQuadricTexture(ball, GL_TRUE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	char text[] = "texture1.bmp";
	tex[0] = LoadBitmap(text);
	strcpy(text, "texture2.bmp");
	tex[1] = LoadBitmap(text);
	strcpy(text, "texture3.bmp");
	tex[2] = LoadBitmap(text);
	if (tex[0]==-1 || text[1]==-1 || tex[2]==-1)
    {
        MessageBox(NULL,(LPCWSTR)"Image file: texture1.bmp not found" , (LPCWSTR)"Zetadeck",MB_OK | MB_ICONERROR);
        exit (0);
    }
	// 障礙物座標
	obs_x[0] = -300;
	obs_y[0] = 1400;
	obs_x[1] = 400;
	obs_y[1] = 1200;
	obs_x[2] = 150;
	obs_y[2] = 1200;
	// 地球座標
	obs_x[3] = -100;
	obs_y[3] = 900;
	// 青蛙位置
	move_x = 0;
	move_y = -380;
	px = 50;
	py = -300;
	// 遊戲狀態
	life = 3;
	game_timer = 30;
	score = 0;
}

void keyboard(unsigned char key, int x, int y) 
{
	
	dis_x = 0; dis_y = 0;
	if (key == 'a' || key == 'A')
	{
		dis_x = -1;
	}

	else if (key == 'd' || key == 'D')
	{
		dis_x = 1;
	}
	
	else if (key == 'w' || key == 'W')
	{
		dis_y = 1;
	}
	else if (key == 's' || key == 'S')
	{
		dis_y = -1;
	}
	else if ((key == 'g' || key == 'G') && Game==0)
		Game = 1;
	else if ((key == 'h' || key == 'H') && Game==2)
	{
		init();
		Game = 0;
	}
	else
	{
		dis_x = 0;
		dis_y = 0;
	}
	glutPostRedisplay();
}
void collision_outcome(int x1 , int y1 , int x2 , int y2 , int w1 , int h1 , int w2 , int h2)
{
	collision = 0;
	if ((x1 - w1) <= x2 && x1 >= (x2 - w2))
	{
		if (y1 >= (y2 - h2) && (y1 - h1) <= y2)
		{
			collision = 1;
		}
	}
}
void idle()
{
	if (Game == 1)
	{
		//障礙物的速度、移動及碰撞偵測
		for (int i = 0; i < 4; i++)
		{
			collision_outcome(px, py, obs_x[i], obs_y[i], 80, 110, 90, 90);
			//碰撞
			if (collision == 1)
			{
				obs_y[i] = 800;
				obs_x[i] = rand() % 349 + 1;
				rnd_x = rand() % 2 + 1;
				if (rnd_x == 1)
					obs_x[i] = -obs_x[i];
				if (i == 3)
					score += 20;
				else
				{
					life--; //生命減少
					score -= 15;
				}
			}
			//到底線
			if (obs_y[i] < -500)
			{
				obs_y[i] = 600;
				//亂數產生x的位置
				obs_x[i] = rand() % 349 + 1;
				rnd_x = rand() % 2;
				if (rnd_x == 0)
					obs_x[i] = -obs_x[i];
			}
			//旋轉
			if (i == 1)
				angle_obs[1] -= 4 * i - 2;
			else
				angle_obs[i] += 4 * i + 2;
			if(i==3)
				obs_y[3] -= speed*0.5;
			else
				obs_y[i] -= speed * (i + 1)*0.5;
		}

		//角色旋轉
		angle += 1;
		//角色在左右邊界內的移動
		if (px + dis_x > -405 && (px + dis_x) < 505)
		{
			move_x += dis_x;
			px += dis_x;
		}
		//在上下邊界內
		if (py + dis_y > -385 && (py + dis_y) < 20)
		{
			move_y += dis_y;
			py += dis_y;
		}
		glutPostRedisplay();
	}
}
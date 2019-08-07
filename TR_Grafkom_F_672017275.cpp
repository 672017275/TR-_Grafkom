#include <windows.h>
#include <glut.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void idle();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
bool mouseDown = false;
int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xpos = 0.0f;
float ypos = 0.0f;
float zpos = 0.0f;

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 600);
glutInitWindowPosition(250, 80);
glutCreateWindow("TUGAS AKHIR - GRAFIKA KOMPUTER");
init();
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glutDisplayFunc(tampil);
glutMouseFunc(mouse);
glutMotionFunc(mouseMotion);
glutKeyboardFunc(keyboard);
glutReshapeFunc(ukuran);
glutMainLoop();
return 0;
}

void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glEnable(GL_DEPTH_TEST);
//pencahayaan
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
//glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);
//set cahaya
GLfloat qaAmbientLight[] = { 0.2,0.2,0.2,1.0 };
GLfloat qaDiffuseLight[] = { 1,1,1,1 };
GLfloat qaSpecularLight[] = { 1,1,1,1 };
glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
//posisi cahaya
GLfloat posisilampu[] = { 0,160,200,1 };
glLightfv(GL_LIGHT0, GL_POSITION, posisilampu);
glEnable(GL_COLOR_MATERIAL);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_MODELVIEW);
glOrtho(-1, 1, -1, 1, -1, 1);
glPointSize(2.0);
glLineWidth(2.0);

}


void tampil(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(xpos, ypos, zpos);
glRotatef(xrot + 20, 1.0f, 0.0f, 0.0f);
glRotatef(yrot - 20, 0.0f, 1.0f, 0.0f);

	glScalef(30,30,30);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,1.0);
	//0
	glTexCoord2f(0.611900, 0.886700);
	glVertex3f(0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.638400, 0.939600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.580300, 0.950300);
	glVertex3f(0.146100, 1.099700, 0.018800);
	
	glEnd();
	//1 230
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.580300, 0.950300);
	glVertex3f(0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.611900, 0.886700);
	glVertex3f(0.134000, 1.020300, -0.083900);
	
	glEnd();
	//2 456
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.534800, 0.961100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	
	glEnd();
	//3 674
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.534800, 0.961100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.493600, 0.975100);
	glVertex3f(0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	
	glEnd();
	//4 894
	glBegin(GL_TRIANGLES);
	glTexCoord2f(10.450500, 0.993000);
	glVertex3f(0.000000, 1.073400, 0.142800);
	glTexCoord2f(0.427200, 0.949000);
	glVertex3f(0.000000, 0.989700, 0.142800);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	
	//
	glEnd();
	//5 478
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.493600, 0.975100);
	glVertex3f(0.076300, 1.080200, 0.128000);
	glTexCoord2f(10.450500, 0.993000);
	glVertex3f(0.000000, 1.073400, 0.142800);
	
	glEnd();
	//6 653
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.534800, 0.961100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	
	glEnd();
	//7 326
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.580300, 0.950300);
	glVertex3f(0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.534800, 0.961100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	
	glEnd();
	//8 10 11 12
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.399800, 0.513000);
	glVertex3f(0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.440100, 0.492100);
	glVertex3f(0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	
	glEnd();
	//9 12 13 10
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.399800, 0.513000);
	glVertex3f(0.173900, 0.307400, -0.027100);
	
	glEnd();
	//10. 14 15 16
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.342700, 0.643800);
	glVertex3f(0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.311000, 0.543400);
	glVertex3f(0.053900, 0.302200, -0.019200);
	
	//
	glEnd();
	//11. 16 17 14
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.311000, 0.543400);
	glVertex3f(0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.356400, 0.528300);
	glVertex3f(0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	
	glEnd();
	//12. 13 14 17
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.356400, 0.528300);
	glVertex3f(0.119200, 0.295400, 0.030000);
	
	glEnd();
	//13. 17 10 13
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.356400, 0.528300);
	glVertex3f(0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.399800, 0.513000);
	glVertex3f(0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	
	glEnd();
	//14. 18 19 20
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.563400, 0.565100);
	glVertex3f(0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.573300, 0.585200);
	glVertex3f(0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	
	glEnd();
	//15. 20 21 18
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.519700, 0.560100);
	glVertex3f(0.059100, 0.461200, -0.065500);
	glTexCoord2f(0.563400, 0.565100);
	glVertex3f(0.047500, 0.481000, 0.007600);
	
	glEnd();
	//16. 22 23 14
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.421500, 0.654500);
	glVertex3f(0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.394900, 0.664700);
	glVertex3f(0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	
	glEnd();
	//17. 14 13 22
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.421500, 0.654500);
	glVertex3f(0.138500, 0.528400, 0.067200);
	
	glEnd();
	//18. 24 3 5
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	
	glEnd();
	// 19. 5 25 24
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.493900, 0.863500);
	glVertex3f(0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	
	glEnd();
   //20. 26 27 18 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.488400, 0.474600);
	glVertex3f(0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.533400, 0.463200);
	glVertex3f(0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.563400, 0.565100);
	glVertex3f(0.047500, 0.481000, 0.007600);
	
	glEnd();

	//21.   18,   21,   26
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.563400, 0.565100);
	glVertex3f(0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.519700, 0.560100);
	glVertex3f(0.059100, 0.461200, -0.065500);
	glTexCoord2f(0.488400, 0.474600);
	glVertex3f(0.064800, 0.310200, -0.097300);
	
	glEnd();

    //22.   28,   29,   13
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	
	glEnd();

    //23.   13,   12,   28
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	
	glEnd();

	//24.   20,   28,   12
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	
	glEnd();

	//25.   12,   21,   20
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.519700, 0.560100);
	glVertex3f(0.059100, 0.461200, -0.065500);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	
	glEnd();

	//26.   30,   23,   31
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.346200, 0.668500);
	glVertex3f(0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.394900, 0.664700);
	glVertex3f(0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	
	glEnd();

	//27.   31,   32,   30
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.353500, 0.707200);
	glVertex3f(0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.346200, 0.668500);
	glVertex3f(0.036200, 0.522900, 0.021400);
	
	glEnd();

	//28.   23,   22,   33
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.394900, 0.664700);
	glVertex3f(0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.421500, 0.654500);
	glVertex3f(0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	
	glEnd();

	//29.   33,   31,   23
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.394900, 0.664700);
	glVertex3f(0.091700, 0.527400, 0.085700);
	
	glEnd();

	//30.   34,   35,   36 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	
	glEnd();

	//31.   36,   37,   34
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	
	glEnd();

	//32.   38,   39,    1
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.631800, 0.850400);
	glVertex3f(0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.679500, 0.847600);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.638400, 0.939600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	
	glEnd();
	//33.    1,    0,   38
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.638400, 0.939600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.611900, 0.886700);
	glVertex3f(0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.631800, 0.850400);
	glVertex3f(0.088400, 0.983000, -0.120000);
	
	glEnd();

	//34.   28,   20,   34
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	
	glEnd();
	//35.   34,   37,   28
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	
	glEnd();
	//36.   20,   40,   41
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.589200, 0.614800);
	glVertex3f(0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.639600, 0.680200);
	glVertex3f(0.015800, 0.734600, 0.039900);
	
	glEnd();
	//37.   41,   34,   20
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.639600, 0.680200);
	glVertex3f(0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	
	glEnd();

	//38.   29,   28,   37
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.498300, 0.639600);
	glVertex3f(0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	
	glEnd();
	//39.   37,   42,   29
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	
	glEnd();

	//40.   33,   29,   42
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	
	glEnd();

	//41.   42,   43,   33
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	
	glEnd();

	//42.   32,   31,   44
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.353500, 0.707200);
	glVertex3f(0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	
	glEnd();

	//43.   44,   45,   32
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.365100, 0.794600);
	glVertex3f(0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.353500, 0.707200);
	glVertex3f(0.033600, 0.589300, 0.030200);
	
	glEnd();

	//44.   31,   33,   43
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	
	glEnd();

	//45.   43,   44,   31
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.396300, 0.696800);
	glVertex3f(0.077500, 0.582500, 0.089300);
	
	glEnd();
	//46.   44,   46,   47
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	
	glEnd();

	//47.   47,   45,   44
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.365100, 0.794600);
	glVertex3f(0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	
	glEnd();

	//48.   46,   44,   43
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.415300, 0.779600);
	glVertex3f(0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	
	glEnd();

	//49.   43,   25,   46
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.493900, 0.863500);
	glVertex3f(0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	
	glEnd();

	//50.   25,   43,   42
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.493900, 0.863500);
	glVertex3f(0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.456500, 0.769100);
	glVertex3f(0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	
	glEnd();

	//51.   42,   24,   25
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.493900, 0.863500);
	glVertex3f(0.167900, 0.908700, 0.098100);
	
	glEnd();
	//52.   24,   42,   37
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.501900, 0.753700);
	glVertex3f(0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	
	glEnd();

	//53.   37,   36,   24
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.549400, 0.734400);
	glVertex3f(0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	
	glEnd();

	//54.   48,   49,   38
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.631800, 0.850400);
	glVertex3f(0.088400, 0.983000, -0.120000);
	
	glEnd();

	//55.   38,    0,   48
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.631800, 0.850400);
	glVertex3f(0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.611900, 0.886700);
	glVertex3f(0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	
	glEnd();

	//56.   49,   50,   39
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.670400, 0.813800);
	glVertex3f(0.000000, 0.924000, -0.095300);
	glTexCoord2f(0.679500, 0.847600);
	glVertex3f(0.000000, 0.991100, -0.114900);
	
	glEnd();
	//57.   39,   38,   49
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.679500, 0.847600);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.631800, 0.850400);
	glVertex3f(0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	
	glEnd();

	//58.   48,    0,    3
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	glTexCoord2f(0.611900, 0.886700);
	glVertex3f(0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	
	glEnd();

	//59.    3,   24,   48
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.567700, 0.902600);
	glVertex3f(0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	
	glEnd();

	//60.   36,   35,   49
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	
	glEnd();

	//61.   49,   48,   36
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	
	glEnd();

	//62.   47,   51,   52
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.405000, 0.895300);
	glVertex3f(0.000000, 0.897900, 0.104700);
	glTexCoord2f(0.359800, 0.886200);
	glVertex3f(0.000000, 0.888900, 0.018300);
	
	glEnd();

	//63.   52,   53,   47
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.359800, 0.886200);
	glVertex3f(0.000000, 0.888900, 0.018300);
	glTexCoord2f(0.368400, 0.873400);
	glVertex3f(0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	
	glEnd();

	//64.   54,   50,   35
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.685900, 0.756900);
	glVertex3f(0.000000, 0.888900, 0.018300);
	glTexCoord2f(0.670400, 0.813800);
	glVertex3f(0.000000, 0.924000, -0.095300);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	
	glEnd();

	//65.   35,   55,   54
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.679300, 0.744900);
	glVertex3f(0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.685900, 0.756900);
	glVertex3f(0.000000, 0.888900, 0.018300);
	
	glEnd();

	//66.   35,   34,   41
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.593500, 0.722500);
	glVertex3f(0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.639600, 0.680200);
	glVertex3f(0.015800, 0.734600, 0.039900);
	
	glEnd();

	//67.   41,   55,   35
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.639600, 0.680200);
	glVertex3f(0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.679300, 0.744900);
	glVertex3f(0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	
	glEnd();

	//68.   56,   57,   58
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	
	glEnd();

	//69.   58,   59,   56
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	
	glEnd();

	//70.   59,   60,   61
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	glTexCoord2f(0.495500, 0.139900);
	glVertex3f(0.000000, 1.225000, 0.147100);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	
	glEnd();
	//71.   61,   56,   59
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	
	glEnd();

	//72.   62,   63,   64
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	glTexCoord2f(0.594400, 0.242900);
	glVertex3f(0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	
	glEnd();

	//73.   64,   65,   62
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.537200, 0.220000);
	glVertex3f(0.050900, 1.356800, 0.164600);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	
	glEnd();

	//74.   59,   58,   62
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	
	glEnd();

	//75.   62,   65,   59
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	glTexCoord2f(0.537200, 0.220000);
	glVertex3f(0.050900, 1.356800, 0.164600);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	
	glEnd();

	//76.   63,   62,   66
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.594400, 0.242900);
	glVertex3f(0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	
	glEnd();

	//77.   66,   67,   63
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.628900, 0.267300);
	glVertex3f(0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.594400, 0.242900);
	glVertex3f(0.122900, 1.393800, 0.129500);
	
	glEnd();

	//78.   68,   69,   70
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.019400, 0.033900);
	glVertex3f(0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	
	glEnd();

	//79.   70,   71,   68
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.030800, 0.120700);
	glVertex3f(0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.019400, 0.033900);
	glVertex3f(0.161200, 1.116700, 0.020700);
	
	glEnd();

	//80.   72,   73,   74
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	
	glEnd();

//	81.   74,   75,   72
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.157500, 0.229300);
	glVertex3f(0.000000, 1.368100, -0.107800);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	
	glEnd();

//	82.   76,   77,   71
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.016800, 0.213000);
	glVertex3f(0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.030800, 0.120700);
	glVertex3f(0.133000, 1.221000, 0.007600);
	
	glEnd();

//	83.   71,   70,   76
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.030800, 0.120700);
	glVertex3f(0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	
	glEnd();

//	84.   78,   64,   79
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.543000, 0.295300);
	glVertex3f(0.048500, 1.433500, 0.101900);
	
	glEnd();

//	85.   79,   80,   78
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.543000, 0.295300);
	glVertex3f(0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	
	glEnd();

//	86.   81,   82,   83
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	glTexCoord2f(0.114000, 0.411500);
	glVertex3f(0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.106200, 0.385400);
	glVertex3f(0.052400, 1.563700, -0.078800);
	
	glEnd();

//	87.   83,   84,   81
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.106200, 0.385400);
	glVertex3f(0.052400, 1.563700, -0.078800);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	
	glEnd();

//	88.   85,   86,   80
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.513300, 0.368700);
	glVertex3f(0.000000, 1.507400, 0.046200);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	
	glEnd();

//	89.   80,   79,   85
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	glTexCoord2f(0.543000, 0.295300);
	glVertex3f(0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	
	glEnd();

//	90.   57,   87,   88
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.657700, 0.032800);
	glVertex3f(0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.669500, 0.126100);
	glVertex3f(0.133000, 1.221000, 0.007600);
	
	glEnd();

//	91.   88,   58,   57
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.669500, 0.126100);
	glVertex3f(0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	
	glEnd();

//	92.   89,   70,   69
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	
	glEnd();

//	93.   69,   90,   89
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	glTexCoord2f(0.169000, 0.045600);
	glVertex3f(0.000000, 1.126500, -0.093300);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	
	glEnd();

//	94.   91,   92,   93
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	glTexCoord2f(0.652600, 0.415200);
	glVertex3f(0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.586400, 0.443200);
	glVertex3f(0.032800, 1.559100, -0.046700);
	
	glEnd();

//	95.   94,   82,   95
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.080400, 0.412900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.114000, 0.411500);
	glVertex3f(0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.116200, 0.449800);
	glVertex3f(0.033900, 1.610900, -0.035400);
	
	glEnd();

//	96.   95,   96,   94
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.116200, 0.449800);
	glVertex3f(0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.086900, 0.458700);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.080400, 0.412900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	
	glEnd();

//	97.   97,   95,   82
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.142400, 0.445800);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	glTexCoord2f(0.116200, 0.449800);
	glVertex3f(0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.114000, 0.411500);
	glVertex3f(0.032800, 1.559100, -0.046700);
	
	glEnd();

//	98.   82,   81,   97
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.114000, 0.411500);
	glVertex3f(0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	glTexCoord2f(0.142400, 0.445800);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	
	glEnd();

//	99.   98,   86,   85
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.517200, 0.427900);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	glTexCoord2f(0.513300, 0.368700);
	glVertex3f(0.000000, 1.507400, 0.046200);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	
	glEnd();

//	100.   85,   99,   98
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.535100, 0.436200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.517200, 0.427900);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	
	glEnd();
	

//	101.    4,    9,   51
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.427200, 0.949000);
	glVertex3f(0.000000, 0.989700, 0.142800);
	glTexCoord2f(0.405000, 0.895300);
	glVertex3f(0.000000, 0.897900, 0.104700);
	
	glEnd();

//	102.   51,   47,    4
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.405000, 0.895300);
	glVertex3f(0.000000, 0.897900, 0.104700);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	
	glEnd();

//	103.  100,  101,  102
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.661700, 0.255700);
	glVertex3f(0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.695700, 0.331200);
	glVertex3f(0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	
	glEnd();

//	104.  102,   67,  100
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	glTexCoord2f(0.628900, 0.267300);
	glVertex3f(0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.661700, 0.255700);
	glVertex3f(0.163600, 1.405300, 0.046200);
	
	glEnd();

// 105. 103,  104,  105
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.832400, 0.226900);
	glVertex3f(0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.854200, 0.240800);
	glVertex3f(0.041600, 1.719200, 0.109800);
	
	glEnd();

// 106.  105,  106,  103
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854200, 0.240800);
	glVertex3f(0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	
	glEnd();

 // 107.  107,  108,  109
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	
	glEnd();

// 108.  109,  110,  107
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	glTexCoord2f(0.810900, 0.172200);
	glVertex3f(0.098200, 1.656100, 0.034300);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	
	glEnd();

// 109.  111,  109,  108
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	
	glEnd();

// 110.  108,  112,  111
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	glTexCoord2f(0.907300, 0.191300);
	glVertex3f(0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	
	glEnd();

// 111.  113,  108,  107
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	
	glEnd();

// 112.  107,  114,  113
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	
	glEnd();

// 113.  107,  110,  115
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	glTexCoord2f(0.810900, 0.172200);
	glVertex3f(0.098200, 1.656100, 0.034300);
	glTexCoord2f(0.785300, 0.141200);
	glVertex3f(0.083600, 1.624900, -0.019600);
	
	glEnd();


// 114.  115,  116,  107
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.785300, 0.141200);
	glVertex3f(0.083600, 1.624900, -0.019600);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	
	glEnd();

// 115.  117,  118,  103
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	
	glEnd();

// 116.  103,  119,  117
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.836200, 0.275900);
	glVertex3f(-0.000000, 1.697500, 0.117900);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	
	glEnd();


// 117.  120,  121,  122
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.740100, 0.276200);
	glVertex3f(-0.000000, 1.579800, 0.105800);
	glTexCoord2f(0.709500, 0.236100);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	
	glEnd();

// 118.  122,  123,  120
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.709500, 0.236100);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	glTexCoord2f(0.732000, 0.212200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	
	glEnd();

// 119.  124,  125,  126
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.888000, 0.006300);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	glTexCoord2f(0.957500, 0.029000);
	glVertex3f(0.000100, 1.811300, -0.108400);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	
	glEnd();


// 120.  126,  127,  124
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	glTexCoord2f(0.892100, 0.050100);
	glVertex3f(0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.888000, 0.006300);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	
	glEnd();


// 121.  128,  118,  129
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	glTexCoord2f(0.780700, 0.251800);
	glVertex3f(0.027700, 1.625800, 0.104800);
	
	glEnd();

// 122.  129,  130,  128
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.780700, 0.251800);
	glVertex3f(0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.783900, 0.221200);
	glVertex3f(0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	
	glEnd();

// 123.  103,  118,  128
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	
	glEnd();


// 124.  128,  104,  103
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.832400, 0.226900);
	glVertex3f(0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	
	glEnd();

// 125.  118,  131,  132
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	glTexCoord2f(0.796800, 0.276000);
	glVertex3f(-0.000000, 1.643800, 0.118000);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	
	glEnd();

// 126.  132,  129,  118
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	glTexCoord2f(0.780700, 0.251800);
	glVertex3f(0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	
	glEnd();

// 127.  133,  120,  123
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.767800, 0.195000);
	glVertex3f(0.056500, 1.619800, 0.041000);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.732000, 0.212200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	
	glEnd();

// 128.  123,  134,  133
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.732000, 0.212200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.750100, 0.163400);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.767800, 0.195000);
	glVertex3f(0.056500, 1.619800, 0.041000);
	
	glEnd();

// 129.  116,  135,  136
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	glTexCoord2f(0.740100, 0.115600);
	glVertex3f(0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.720600, 0.079900);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	
	glEnd();

// 130.  136,  137,  116
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.720600, 0.079900);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	glTexCoord2f(0.772900, 0.040600);
	glVertex3f(-0.000000, 1.654200, -0.086200);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	
	glEnd();

// 131.  105,  104,  138
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854200, 0.240800);
	glVertex3f(0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.832400, 0.226900);
	glVertex3f(0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.839400, 0.214100);
	glVertex3f(0.061400, 1.705100, 0.074800);
	
	glEnd();

// 132.  138,  139,  105
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839400, 0.214100);
	glVertex3f(0.061400, 1.705100, 0.074800);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.854200, 0.240800);
	glVertex3f(0.041600, 1.719200, 0.109800);
	
	glEnd();

// 133.  130,  133,  140
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.783900, 0.221200);
	glVertex3f(0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.767800, 0.195000);
	glVertex3f(0.056500, 1.619800, 0.041000);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	
	glEnd();	

// 134.  140,  128,  130
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.783900, 0.221200);
	glVertex3f(0.052100, 1.633900, 0.074200);
	
	glEnd();	

// 135.  108,  113,  141
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	
	glEnd();	

// 136.  141,  112,  108
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	glTexCoord2f(0.907300, 0.191300);
	glVertex3f(0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.867800, 0.161500);
	glVertex3f(0.089500, 1.745700, 0.019800);
	
	glEnd();	

// 137.  111,  112,  142
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.907300, 0.191300);
	glVertex3f(0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.963400, 0.221800);
	glVertex3f(0.000100, 1.815200, 0.062300);
	
	glEnd();	

// 138.  142,  143,  111
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.963400, 0.221800);
	glVertex3f(0.000100, 1.815200, 0.062300);
	glTexCoord2f(0.907300, 0.271700);
	glVertex3f(-0.000000, 1.772000, 0.119400);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	
	glEnd();	

// 139.  116,  137,  144
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	glTexCoord2f(0.772900, 0.040600);
	glVertex3f(-0.000000, 1.654200, -0.086200);
	glTexCoord2f(0.829900, 0.024300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	
	glEnd();	

// 140.  144,  114,  116
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.829900, 0.024300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	
	glEnd();	

// 141.  140,  138,  104
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	glTexCoord2f(0.839400, 0.214100);
	glVertex3f(0.061400, 1.705100, 0.074800);
	glTexCoord2f(0.832400, 0.226900);
	glVertex3f(0.051100, 1.694100, 0.087100);
	
	glEnd();	

// 142.  104,  128,  140
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832400, 0.226900);
	glVertex3f(0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.811600, 0.227700);
	glVertex3f(0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	
	glEnd();	

// 143.  120,  129,  132
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.780700, 0.251800);
	glVertex3f(0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	
	glEnd();	

// 144.  132,  121,  120
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	glTexCoord2f(0.740100, 0.276200);
	glVertex3f(-0.000000, 1.579800, 0.105800);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	
	glEnd();	

// 145.  130,  129,  120
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.783900, 0.221200);
	glVertex3f(0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.780700, 0.251800);
	glVertex3f(0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	
	glEnd();	

// 146.  120,  133,  130
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752000, 0.243900);
	glVertex3f(0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.767800, 0.195000);
	glVertex3f(0.056500, 1.619800, 0.041000);
	glTexCoord2f(0.783900, 0.221200);
	glVertex3f(0.052100, 1.633900, 0.074200);
	
	glEnd();	

// 147.  112,  141,  145
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.907300, 0.191300);
	glVertex3f(0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	glTexCoord2f(0.985900, 0.145600);
	glVertex3f(0.000100, 1.823300, -0.005400);
	
	glEnd();

// 148.  145,  142,  112
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.985900, 0.145600);
	glVertex3f(0.000100, 1.823300, -0.005400);
	glTexCoord2f(0.963400, 0.221800);
	glVertex3f(0.000100, 1.815200, 0.062300);
	glTexCoord2f(0.907300, 0.191300);
	glVertex3f(0.056500, 1.796300, 0.058400);
	
	glEnd();

// 149.  106,  105,  139
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	glTexCoord2f(0.854200, 0.240800);
	glVertex3f(0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	
	glEnd();

// 150.  139,  146,  106
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	
	glEnd();

// 151.   66,   88,  147
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.669500, 0.126100);
	glVertex3f(0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.709100, 0.217400);
	glVertex3f(0.154600, 1.369400, -0.025600);
	
	glEnd();

// 152.  147,  100,   66
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.709100, 0.217400);
	glVertex3f(0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.661700, 0.255700);
	glVertex3f(0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	
	glEnd();

// 153.   11,   26,   21 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.440100, 0.492100);
	glVertex3f(0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.488400, 0.474600);
	glVertex3f(0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.519700, 0.560100);
	glVertex3f(0.059100, 0.461200, -0.065500);
	
	glEnd();

// 154.   21,   12,   11
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.519700, 0.560100);
	glVertex3f(0.059100, 0.461200, -0.065500);
	glTexCoord2f(0.472700, 0.577400);
	glVertex3f(0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.440100, 0.492100);
	glVertex3f(0.153500, 0.312400, -0.103600);
	
	glEnd();

// 155.  109,  111,  139
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	
	glEnd();

//  156.  139,  138,  109
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.839400, 0.214100);
	glVertex3f(0.061400, 1.705100, 0.074800);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	
	glEnd();

// 157.  111,  143,  146
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.907300, 0.271700);
	glVertex3f(-0.000000, 1.772000, 0.119400);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	
	glEnd();

// 158.  146,  139,  111
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	glTexCoord2f(0.868600, 0.240300);
	glVertex3f(0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.880000, 0.230000);
	glVertex3f(0.050200, 1.753800, 0.109800);
	
	glEnd();

// 159.  134,  110,  140
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.750100, 0.163400);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.810900, 0.172200);
	glVertex3f(0.098200, 1.656100, 0.034300);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	
	glEnd();

// 160.  140,  133,  134
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	glTexCoord2f(0.767800, 0.195000);
	glVertex3f(0.056500, 1.619800, 0.041000);
	glTexCoord2f(0.750100, 0.163400);
	glVertex3f(0.049200, 1.611300, 0.003500);
	
	glEnd();

// 161.  148,  126,  125
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.957700, 0.088100);
	glVertex3f(0.033300, 1.826900, -0.057300);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	glTexCoord2f(0.957500, 0.029000);
	glVertex3f(0.000100, 1.811300, -0.108400);
	
	glEnd();

// 162.  125,  149,  148
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.957500, 0.029000);
	glVertex3f(0.000100, 1.811300, -0.108400);
	glTexCoord2f(0.991700, 0.088900);
	glVertex3f(0.000100, 1.837000, -0.048700);
	glTexCoord2f(0.957700, 0.088100);
	glVertex3f(0.033300, 1.826900, -0.057300);
	
	glEnd();

// 163.  140,  110,  109
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	glTexCoord2f(0.810900, 0.172200);
	glVertex3f(0.098200, 1.656100, 0.034300);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	
	glEnd();

// 164.  109,  138,  140
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850100, 0.196700);
	glVertex3f(0.077700, 1.718400, 0.071500);
	glTexCoord2f(0.839400, 0.214100);
	glVertex3f(0.061400, 1.705100, 0.074800);
	glTexCoord2f(0.808800, 0.204200);
	glVertex3f(0.062400, 1.665000, 0.062600);
	
	glEnd();

// 165.  150,   90,   69
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.164600, 0.020700);
	glVertex3f(0.000000, 1.115200, -0.064300);
	glTexCoord2f(0.169000, 0.045600);
	glVertex3f(0.000000, 1.126500, -0.093300);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	
	glEnd();

// 166.   69,  151,  150
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	glTexCoord2f(0.096500, 0.027600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.164600, 0.020700);
	glVertex3f(0.000000, 1.115200, -0.064300);
	
	glEnd();

// 167.  151,   69,   68
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.096500, 0.027600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.091100, 0.045600);
	glVertex3f(0.105800, 1.124800, -0.079300);
	glTexCoord2f(0.019400, 0.033900);
	glVertex3f(0.161200, 1.116700, 0.020700);
	
	glEnd();

// 168.   68,  152,  151
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.019400, 0.033900);
	glVertex3f(0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.022200, 0.019900);
	glVertex3f(0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.096500, 0.027600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	
	glEnd();

// 169.  153,   87,   57
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.655600, 0.015500);
	glVertex3f(0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.657700, 0.032800);
	glVertex3f(0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	
	glEnd();

// 170.   57,  154,  153
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.601900, 0.011100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.655600, 0.015500);
	glVertex3f(0.146100, 1.099700, 0.018800);
	
	glEnd();

// 171.   57,   56,  155
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.545500, 0.005400);
	glVertex3f(0.076300, 1.080200, 0.128000);
	
	glEnd();

// 172.  155,  154,   57
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.545500, 0.005400);
	glVertex3f(0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.601900, 0.011100);
	glVertex3f(0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.604200, 0.025100);
	glVertex3f(0.145200, 1.099900, 0.091500);
	
	glEnd();

// 173.   56,   61,  156
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	glTexCoord2f(0.482400, 0.007500);
	glVertex3f(0.000000, 1.073400, 0.142800);
	
	glEnd();

// 174.  156,  155,   56
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.482400, 0.007500);
	glVertex3f(0.000000, 1.073400, 0.142800);
	glTexCoord2f(0.545500, 0.005400);
	glVertex3f(0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.543100, 0.024100);
	glVertex3f(0.081300, 1.092000, 0.151200);
	
	glEnd();

// 175.  113,  114,  127
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	glTexCoord2f(0.892100, 0.050100);
	glVertex3f(0.042300, 1.762700, -0.116500);
	
	glEnd();

// 176.  127,  126,  113
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.892100, 0.050100);
	glVertex3f(0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	
	glEnd();

// 177.  114,  144,  124
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	glTexCoord2f(0.829900, 0.024300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	glTexCoord2f(0.888000, 0.006300);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	
	glEnd();

// 178.  124,  127,  114
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.888000, 0.006300);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	glTexCoord2f(0.892100, 0.050100);
	glVertex3f(0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	
	glEnd();

// 179.  145,  141,  148
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.985900, 0.145600);
	glVertex3f(0.000100, 1.823300, -0.005400);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	glTexCoord2f(0.957700, 0.088100);
	glVertex3f(0.033300, 1.826900, -0.057300);
	
	glEnd();

// 180.  148,  149,  145
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.957700, 0.088100);
	glVertex3f(0.033300, 1.826900, -0.057300);
	glTexCoord2f(0.991700, 0.088900);
	glVertex3f(0.000100, 1.837000, -0.048700);
	glTexCoord2f(0.985900, 0.145600);
	glVertex3f(0.000100, 1.823300, -0.005400);
	
	glEnd();

// 181.  141,  113,  126
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	glTexCoord2f(0.897100, 0.103800);
	glVertex3f(0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	
	glEnd();

// 182.  126,  148,  141
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.923200, 0.064600);
	glVertex3f(0.051700, 1.805300, -0.096200);
	glTexCoord2f(0.957700, 0.088100);
	glVertex3f(0.033300, 1.826900, -0.057300);
	glTexCoord2f(0.944900, 0.133300);
	glVertex3f(0.037400, 1.812800, -0.013600);
	
	glEnd();

// 183.  157,   76,   74
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.006500, 0.316400);
	glVertex3f(0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	
	glEnd();

// 184.   74,  158,  157
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.006500, 0.316400);
	glVertex3f(0.195700, 1.491700, -0.080700);
	
	glEnd();

// 185.   89,   75,   74
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	glTexCoord2f(0.157500, 0.229300);
	glVertex3f(0.000000, 1.368100, -0.107800);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	
	glEnd();

// 186.   74,   70,   89
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	
	glEnd();

// 187.   73,  159,  158
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.052300, 0.381300);
	glVertex3f(0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	
	glEnd();

// 188.  158,   74,   73
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	
	glEnd();

// 189.   73,   72,   84
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	
	glEnd();

// 190.   84,   83,   73
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	glTexCoord2f(0.106200, 0.385400);
	glVertex3f(0.052400, 1.563700, -0.078800);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	
	glEnd();

// 191.  102,  160,   92
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	glTexCoord2f(0.684000, 0.403200);
	glVertex3f(0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.652600, 0.415200);
	glVertex3f(0.121400, 1.558800, -0.054000);
	
	glEnd();

// 192.   92,   91,  102
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.652600, 0.415200);
	glVertex3f(0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	
	glEnd();

// 193.  161,  102,   91
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	
	glEnd();

// 194.   91,  162,  161
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	
	glEnd();

// 195.   63,   67,  161
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.594400, 0.242900);
	glVertex3f(0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.628900, 0.267300);
	glVertex3f(0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	
	glEnd();

// 196.  161,   64,   63
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.594400, 0.242900);
	glVertex3f(0.122900, 1.393800, 0.129500);
	
	glEnd();

// 197.   85,   79,  162
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.543000, 0.295300);
	glVertex3f(0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	
	glEnd();

// 198.  162,  163,   85
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	glTexCoord2f(0.578900, 0.408900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	
	glEnd();

// 199.  160,  102,  101
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.684000, 0.403200);
	glVertex3f(0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	glTexCoord2f(0.695700, 0.331200);
	glVertex3f(0.200000, 1.496400, -0.003200);
	
	glEnd();

//200.  101,  164,  160
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.695700, 0.331200);
	glVertex3f(0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.729800, 0.378800);
	glVertex3f(0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.684000, 0.403200);
	glVertex3f(0.153500, 1.525500, -0.066500);
	
	glEnd();

// 201.  165,  166,  167
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.123700, 0.921600);
	glVertex3f(-0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.176400, 0.970400);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	
	glEnd();

// 202.  167,  168,  165
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.176400, 0.970400);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.118900, 0.981500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.123700, 0.921600);
	glVertex3f(-0.134000, 1.020300, -0.083900);
	
	glEnd();

// 203.  169,  170,  171
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.264300, 0.962300);
	glVertex3f(-0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.221900, 0.965500);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	
	glEnd();

// 204.  171,  172,  169
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.965500);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	
	glEnd();

// 205.  173,  170,  169
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.310700, 0.966400);
	glVertex3f(0.000000, 1.073400, 0.142800);
	glTexCoord2f(0.264300, 0.962300);
	glVertex3f(-0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	
	glEnd();

// 206.  169,  174,  173
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.319000, 0.917400);
	glVertex3f(0.000000, 0.989700, 0.142800);
	glTexCoord2f(0.310700, 0.966400);
	glVertex3f(0.000000, 1.073400, 0.142800);
	
	glEnd();

// 207.  171,  167,  166
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.965500);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.176400, 0.970400);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	
	glEnd();

// 208.  166,  172,  171
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.221900, 0.965500);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	
	glEnd();
	

// 209.  175,  176,  177
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.191300, 0.498400);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	
	glEnd();

// 210.  177,  178,  175
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.145600, 0.497200);
	glVertex3f(-0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.191300, 0.498400);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	
	glEnd();

// 211.  179,  180,  181
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.237500, 0.500000);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.284600, 0.495600);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	
	glEnd();

// 212.  181,  182,  179
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.284600, 0.495600);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.291100, 0.599900);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	
	glEnd();

// 213.  176,  175,  180
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.191300, 0.498400);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.237500, 0.500000);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	
	glEnd();

// 214.  180,  179,  176
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.237500, 0.500000);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	
	glEnd();
	
// 215.  183,  184,  185
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.056100, 0.603600);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.097400, 0.584400);
	glVertex3f(-0.062300, 0.463000, -0.069600);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	
	glEnd();

// 216.  185,  186,  183
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.053700, 0.626300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.056100, 0.603600);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	
	glEnd();

// 217.  187,  176,  179
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.220500, 0.637500);
	glVertex3f(-0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	
	glEnd();

// 218.  179,  188,  187
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.249400, 0.637900);
	glVertex3f(-0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.220500, 0.637500);
	glVertex3f(-0.138500, 0.528400, 0.067200);
	
	glEnd();

// 219.  189,  190,  172
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.225700, 0.858400);
	glVertex3f(-0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	
	glEnd();

// 220.  172,  166,  189
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	
	glEnd();

// 221.  191,  184,  183
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.094900, 0.497500);
	glVertex3f(-0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.097400, 0.584400);
	glVertex3f(-0.062300, 0.463000, -0.069600);
	glTexCoord2f(0.056100, 0.603600);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	
	glEnd();

// 222.  183,  192,  191
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.056100, 0.603600);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.048200, 0.499000);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.094900, 0.497500);
	glVertex3f(-0.064800, 0.310200, -0.097300);
	
	glEnd();

// 223.  193,  177,  176
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	
	glEnd();

// 224.  176,  194,  193
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.181200, 0.650600);
	glVertex3f(-0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	
	glEnd();

// 225.  185,  184,  177
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.097400, 0.584400);
	glVertex3f(-0.062300, 0.463000, -0.069600);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	
	glEnd();

// 226.  177,  193,  185
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	
	glEnd();

// 227.  195,  196,  197
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.296400, 0.624300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.302800, 0.663200);
	glVertex3f(-0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	
	glEnd();

// 228.  197,  188,  195
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.249400, 0.637900);
	glVertex3f(-0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.296400, 0.624300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	
	glEnd();

// 229.  188,  197,  198
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.249400, 0.637900);
	glVertex3f(-0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	
	glEnd();

// 230.  198,  187,  188
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.220500, 0.637500);
	glVertex3f(-0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.249400, 0.637900);
	glVertex3f(-0.091700, 0.527400, 0.085700);
	
	glEnd();

// 231.  199,  200,  201
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	
	glEnd();

// 232.  201,  202,  199
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	
	glEnd();

// 233.  203,  165,  168
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.091500, 0.895600);
	glVertex3f(-0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.123700, 0.921600);
	glVertex3f(-0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.118900, 0.981500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	
	glEnd();

// 234.  168,  204,  203
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.118900, 0.981500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.046000, 0.911500);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.091500, 0.895600);
	glVertex3f(-0.088400, 0.983000, -0.120000);
	
	glEnd();

// 235.  193,  200,  199
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	
	glEnd();

// 236.  199,  185,  193
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	
	glEnd();

// 237.  185,  199,  205
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.025300, 0.737800);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	
	glEnd();

// 238.  205,  206,  185
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.025300, 0.737800);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.049700, 0.659300);
	glVertex3f(-0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	
	glEnd();

// 239.  194,  207,  200
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.181200, 0.650600);
	glVertex3f(-0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	
	glEnd();

// 240.  200,  193,  194
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.181200, 0.650600);
	glVertex3f(-0.154500, 0.560300, 0.009600);
	
	glEnd();

// 241.  198,  208,  207
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	
	glEnd();

// 242.  207,  194,  198
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.143200, 0.650700);
	glVertex3f(-0.137300, 0.567700, -0.043200);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	
	glEnd();

// 243.  196,  209,  210
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.302800, 0.663200);
	glVertex3f(-0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.320900, 0.749500);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	
	glEnd();

// 244.  210,  197,  196
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.302800, 0.663200);
	glVertex3f(-0.033600, 0.589300, 0.030200);
	
	glEnd();

// 245.  197,  210,  208
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	
	glEnd();

// 246.  208,  198,  197
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.259200, 0.668300);
	glVertex3f(-0.077500, 0.582500, 0.089300);
	
	glEnd();

// 247.  210,  209,  211
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.320900, 0.749500);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	
	glEnd();

// 248.  211,  212,  210
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	
	glEnd();

// 249.  212,  190,  208
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.225700, 0.858400);
	glVertex3f(-0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	
	glEnd();

// 250.  208,  210,  212
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.270300, 0.752200);
	glVertex3f(-0.074100, 0.726000, 0.111900);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	
	glEnd();

// 251.  190,  189,  207
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.225700, 0.858400);
	glVertex3f(-0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	
	glEnd();

// 252.  207,  208,  190
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.227300, 0.757200);
	glVertex3f(-0.148800, 0.733200, 0.099800);
	glTexCoord2f(0.225700, 0.858400);
	glVertex3f(-0.167900, 0.908700, 0.098100);
	
	glEnd();

// 253.  189,  201,  200
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	
	glEnd();

// 254.  200,  207,  189
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.128700, 0.757800);
	glVertex3f(-0.132600, 0.743600, -0.061700);
	glTexCoord2f(0.179300, 0.758400);
	glVertex3f(-0.178700, 0.740800, 0.020700);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	
	glEnd();

// 255.  213,  165,  203
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	glTexCoord2f(0.123700, 0.921600);
	glVertex3f(-0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.091500, 0.895600);
	glVertex3f(-0.088400, 0.983000, -0.120000);
	
	glEnd();

// 256.  203,  214,  213
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.091500, 0.895600);
	glVertex3f(-0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.080900, 0.872100);
	glVertex3f(-0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	
	glEnd();

// 257.  214,  203,  204
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.080900, 0.872100);
	glVertex3f(-0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.091500, 0.895600);
	glVertex3f(-0.088400, 0.983000, -0.120000);
	glTexCoord2f(0.046000, 0.911500);
	glVertex3f(0.000000, 0.991100, -0.114900);
	
	glEnd();

// 258.  204,  215,  214
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.046000, 0.911500);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.041800, 0.874400);
	glVertex3f(0.000000, 0.924000, -0.095300);
	glTexCoord2f(0.080900, 0.872100);
	glVertex3f(-0.072800, 0.922800, -0.112300);
	
	glEnd();

// 259.  213,  189,  166
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	
	glEnd();

// 260.  166,  165,  213
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.170700, 0.921000);
	glVertex3f(-0.179500, 1.019800, 0.004200);
	glTexCoord2f(0.123700, 0.921600);
	glVertex3f(-0.134000, 1.020300, -0.083900);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	
	glEnd();

// 261.  201,  213,  214
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	glTexCoord2f(0.080900, 0.872100);
	glVertex3f(-0.072800, 0.922800, -0.112300);
	
	glEnd();

// 262.  214,  202,  201
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	
	glEnd();

// 263.  211,  216,  217
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.346100, 0.823700);
	glVertex3f(-0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.355200, 0.823400);
	glVertex3f(0.000000, 0.888900, 0.018300);
	
	glEnd();

// 264.  217,  218,  211
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.355200, 0.823400);
	glVertex3f(0.000000, 0.888900, 0.018300);
	glTexCoord2f(0.324300, 0.860900);
	glVertex3f(0.000000, 0.897900, 0.104700);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	
	glEnd();

// 265.  219,  220,  202
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.007800, 0.825400);
	glVertex3f(0.000000, 0.888900, 0.018300);
	glTexCoord2f(0.009900, 0.812000);
	glVertex3f(-0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	
	glEnd();

// 266.  202,  215,  219
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.041800, 0.874400);
	glVertex3f(0.000000, 0.924000, -0.095300);
	glTexCoord2f(0.007800, 0.825400);
	glVertex3f(0.000000, 0.888900, 0.018300);
	
	glEnd();

// 267.  202,  220,  205
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.009900, 0.812000);
	glVertex3f(-0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.025300, 0.737800);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	
	glEnd();

// 268.  205,  199,  202
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.025300, 0.737800);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.083200, 0.761700);
	glVertex3f(-0.055100, 0.754300, -0.065200);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	
	glEnd();

// 269.  221,  222,  223
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	
	glEnd();

// 270.  223,  224,  221
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	
	glEnd();

// 271.  222,  221,   61
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	
	glEnd();

// 272.   61,   60,  222
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	glTexCoord2f(0.495500, 0.139900);
	glVertex3f(0.000000, 1.225000, 0.147100);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	
	glEnd();

// 273.  225,  226,  227
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	glTexCoord2f(0.455300, 0.219800);
	glVertex3f(-0.065500, 1.348700, 0.165800);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	
	glEnd();

// 274.  227,  228,  225
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.412900, 0.251900);
	glVertex3f(-0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	
	glEnd();

// 275.  222,  226,  225
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	glTexCoord2f(0.455300, 0.219800);
	glVertex3f(-0.065500, 1.348700, 0.165800);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	
	glEnd();

// 276.  225,  223,  222
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	
	glEnd();

// 277.  228,  229,  230
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.412900, 0.251900);
	glVertex3f(-0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.382200, 0.281900);
	glVertex3f(-0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	
	glEnd();

// 278.  230,  225,  228
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	glTexCoord2f(0.412900, 0.251900);
	glVertex3f(-0.122900, 1.393800, 0.129500);
	
	glEnd();

// 279.  231,  232,  233
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.240100, 0.141900);
	glVertex3f(-0.085500, 1.218500, -0.066500);
	
	glEnd();

// 280.  233,  234,  231
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.240100, 0.141900);
	glVertex3f(-0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	
	glEnd();

// 281.   72,   75,  235
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	glTexCoord2f(0.157500, 0.229300);
	glVertex3f(0.000000, 1.368100, -0.107800);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	
	glEnd();

// 282.  235,  236,   72
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	
	glEnd();

// 283.  237,  233,  232
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.255000, 0.271600);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.240100, 0.141900);
	glVertex3f(-0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	
	glEnd();

// 284.  232,  238,  237
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.297100, 0.242700);
	glVertex3f(-0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.255000, 0.271600);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	
	glEnd();

// 285.   78,   80,  239
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	glTexCoord2f(0.473700, 0.299100);
	glVertex3f(-0.048500, 1.433500, 0.101900);
	
	glEnd();

// 286.  239,  227,   78
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.473700, 0.299100);
	glVertex3f(-0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	
	glEnd();

// 287.  240,  241,   81
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.185300, 0.390000);
	glVertex3f(-0.047800, 1.562000, -0.075700);
	glTexCoord2f(0.174300, 0.414800);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	
	glEnd();

// 288.   81,   84,  240
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	glTexCoord2f(0.185300, 0.390000);
	glVertex3f(-0.047800, 1.562000, -0.075700);
	
	glEnd();

// 289.  242,  239,   80
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.473700, 0.299100);
	glVertex3f(-0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	
	glEnd();

// 290.   80,   86,  242
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.506600, 0.286700);
	glVertex3f(0.000000, 1.416500, 0.101000);
	glTexCoord2f(0.513300, 0.368700);
	glVertex3f(0.000000, 1.507400, 0.046200);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	
	glEnd();

// 291.  224,  223,  232
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	
	glEnd();

// 292.  232,  231,  224
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	
	glEnd();

// 293.   89,   90,  234
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	glTexCoord2f(0.169000, 0.045600);
	glVertex3f(0.000000, 1.126500, -0.093300);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	
	glEnd();

// 294.  234,  233,   89
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	
	glEnd();

// 295.  243,  244,  245
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.454700, 0.414500);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.452300, 0.450400);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	
	glEnd();

// 296.  245,  246,  243
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	glTexCoord2f(0.454700, 0.414500);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	
	glEnd();

// 297.  247,  248,  249
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.207700, 0.419200);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.194600, 0.468200);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	glTexCoord2f(0.168400, 0.452900);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	
	glEnd();

// 298.  249,  241,  247
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.168400, 0.452900);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.174300, 0.414800);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.207700, 0.419200);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	
	glEnd();

// 299.   97,   81,  241
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.142400, 0.445800);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	glTexCoord2f(0.144700, 0.406300);
	glVertex3f(0.000000, 1.559200, -0.064100);
	glTexCoord2f(0.174300, 0.414800);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	
	glEnd();

// 300.  241,  249,   97 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.174300, 0.414800);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.168400, 0.452900);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.142400, 0.445800);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	
	glEnd();

// 301.  242,   86,   98
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.513300, 0.368700);
	glVertex3f(0.000000, 1.507400, 0.046200);
	glTexCoord2f(0.517200, 0.427900);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	
	glEnd();

// 302.   98,  250,  242
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.517200, 0.427900);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	glTexCoord2f(0.499300, 0.437400);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	
	glEnd();

// 303.  169,  211,  218
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.324300, 0.860900);
	glVertex3f(0.000000, 0.897900, 0.104700);
	
	glEnd();

// 304.  218,  174,  169
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.324300, 0.860900);
	glVertex3f(0.000000, 0.897900, 0.104700);
	glTexCoord2f(0.319000, 0.917400);
	glVertex3f(0.000000, 0.989700, 0.142800);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	
	glEnd();

// 305.  251,  229,  252
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.350300, 0.274100);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.382200, 0.281900);
	glVertex3f(-0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	
	glEnd();

// 306.  252,  253,  251
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	glTexCoord2f(0.327600, 0.356000);
	glVertex3f(-0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.350300, 0.274100);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	
	glEnd();

// 307.  254,  255,  256
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854600, 0.310900);
	glVertex3f (-0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.832700, 0.325100);
	glVertex3f(-0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	
	glEnd();

// 308.  256,  106,  254
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	glTexCoord2f(0.854600, 0.310900);
	glVertex3f (-0.041600, 1.719200, 0.109800);
	
	glEnd();

// 309.  257,  258,  259
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	glTexCoord2f(0.819300, 0.381800);
	glVertex3f(-0.101400, 1.666900, 0.033300);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f (-0.077500, 1.718400, 0.071500);
	
	glEnd();

// 310.  259,  260,  257
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f (-0.077500, 1.718400, 0.071500);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	
	glEnd();

// 311.  261,  262,  260
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f (-0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.909800, 0.359300);
	glVertex3f(-0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	
	glEnd();

// 312.  260,  259,  261
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f (-0.077500, 1.718400, 0.071500);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f (-0.050200, 1.753800, 0.109800);
	
	glEnd();

// 313.  263,  264,  257
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f (-0.052000, 1.737600, -0.071300);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	
	glEnd();

// 314.  257,  260,  263
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	
	glEnd();

// 315.  257,  265,  266
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	glTexCoord2f(0.784500, 0.414500);
	glVertex3f(-0.077000, 1.628400, -0.020900);
	
	glEnd();

// 316.  266,  258,  257
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784500, 0.414500);
	glVertex3f(-0.077000, 1.628400, -0.020900);
	glTexCoord2f(0.819300, 0.381800);
	glVertex3f(-0.101400, 1.666900, 0.033300);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	
	glEnd();

// 317.  117,  119,  256
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	glTexCoord2f(0.836200, 0.275900);
	glVertex3f(-0.000000, 1.697500, 0.117900);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	
	glEnd();

// 318.  256,  267,  117
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	
	glEnd();

// 319.  268,  269,  270
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.732500, 0.341200);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.709500, 0.316400);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	
	glEnd();

// 320.  270,  121,  268
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.709500, 0.316400);
	glVertex3f(-0.000000, 1.582400, 0.054900);
	glTexCoord2f(0.740100, 0.276200);
	glVertex3f(-0.000000, 1.579800, 0.105800);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	
	glEnd();

// 321.  271,  272,  273
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889300, 0.547400);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	glTexCoord2f(0.892500, 0.504300);
	glVertex3f(-0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	
	glEnd();

// 322.  273,  274,  271
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	glTexCoord2f(0.962800, 0.525900);
	glVertex3f(0.000100, 1.811300, -0.108400);
	glTexCoord2f(0.889300, 0.547400);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	
	glEnd();

// 323.  275,  276,  277
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.784700, 0.330800);
	glVertex3f(-0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.780900, 0.300400);
	glVertex3f(-0.027700, 1.625800, 0.104800);
	
	glEnd();

// 324.  277,  267,  275
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.780900, 0.300400);
	glVertex3f(-0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	
	glEnd();

// 325.  275,  267,  256
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	
	glEnd();

// 326.  256,  255,  275
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.832700, 0.325100);
	glVertex3f(-0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	
	glEnd();

// 327.  267,  277,  132
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	glTexCoord2f(0.780900, 0.300400);
	glVertex3f(-0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	
	glEnd();

// 328.  132,  131,  267
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	glTexCoord2f(0.796800, 0.276000);
	glVertex3f(-0.000000, 1.643800, 0.118000);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	
	glEnd();

// 329.  278,  279,  269
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.770300, 0.362300);
	glVertex3f(-0.059300, 1.622000, 0.035600);
	glTexCoord2f(0.755900, 0.392900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	glTexCoord2f(0.732500, 0.341200);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	
	glEnd();

// 330.  269,  268,  278
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.732500, 0.341200);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.770300, 0.362300);
	glVertex3f(-0.059300, 1.622000, 0.035600);
	
	glEnd();

// 331.  280,  281,  265
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.722700, 0.474900);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	glTexCoord2f(0.742400, 0.439300);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	
	glEnd();

// 332.  265,  282,  280
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	glTexCoord2f(0.774300, 0.513900);
	glVertex3f(-0.000000, 1.654200, -0.086200);
	glTexCoord2f(0.722700, 0.474900);
	glVertex3f(-0.000000, 1.610000, -0.048000);
	
	glEnd();

// 333.  254,  283,  284
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854600, 0.310900);
	glVertex3f(-0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.868900, 0.311100);
	glVertex3f(-0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.722700, 0.474900);
	glVertex3f(-0.061500, 1.705100, 0.074800);
	
	glEnd();

// 334.  284,  255,  254
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.722700, 0.474900);
	glVertex3f(-0.061500, 1.705100, 0.074800);
	glTexCoord2f(0.832700, 0.325100);
	glVertex3f(-0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.854600, 0.310900);
	glVertex3f(-0.041600, 1.719200, 0.109800);
	
	glEnd();

// 335.  276,  275,  285
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784700, 0.330800);
	glVertex3f(-0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	
	glEnd();

// 336.  285,  278,  276
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	glTexCoord2f(0.770300, 0.362300);
	glVertex3f(-0.059300, 1.622000, 0.035600);
	glTexCoord2f(0.784700, 0.330800);
	glVertex3f(-0.052100, 1.633900, 0.074200);
	
	glEnd();

// 337.  260,  262,  286
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	glTexCoord2f(0.909800, 0.359300);
	glVertex3f(-0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	
	glEnd();

// 338.  286,  263,  260
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.873100, 0.391700);
	glVertex3f(-0.086300, 1.747900, 0.017900);
	
	glEnd();

// 339.  261,  287,  288
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f(-0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.907400, 0.279100);
	glVertex3f(-0.000000, 1.772000, 0.119400);
	glTexCoord2f(0.964500, 0.328200);
	glVertex3f(0.000100, 1.815200, 0.062300);
	
	glEnd();

// 340.  288,  262,  261
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.964500, 0.328200);
	glVertex3f(0.000100, 1.815200, 0.062300);
	glTexCoord2f(0.909800, 0.359300);
	glVertex3f(-0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f(-0.050200, 1.753800, 0.109800);
	
	glEnd();

// 341.  265,  264,  289
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f(-0.052000, 1.737600, -0.071300);
	glTexCoord2f(0.831300, 0.531300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	
	glEnd();

// 342.  289,  282,  265
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.831300, 0.531300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	glTexCoord2f(0.774300, 0.513900);
	glVertex3f(-0.000000, 1.654200, -0.086200);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	
	glEnd();

// 343.  285,  275,  255
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	glTexCoord2f(0.811900, 0.324200);
	glVertex3f(-0.053300, 1.666900, 0.089600);
	glTexCoord2f(0.832700, 0.325100);
	glVertex3f(-0.051100, 1.694100, 0.087100);
	
	glEnd();

// 344.  255,  284,  285
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832700, 0.325100);
	glVertex3f(-0.051100, 1.694100, 0.087100);
	glTexCoord2f(0.839900, 0.338400);
	glVertex3f(-0.061500, 1.705100, 0.074800);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	
	glEnd();

// 345.  268,  121,  132
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.740100, 0.276200);
	glVertex3f(-0.000000, 1.579800, 0.105800);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	
	glEnd();

// 346.  132,  277,  268
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784100, 0.276100);
	glVertex3f(-0.000000, 1.627100, 0.120200);
	glTexCoord2f(0.780900, 0.300400);
	glVertex3f(-0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	
	glEnd();

// 347.  276,  278,  268
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784700, 0.330800);
	glVertex3f(-0.052100, 1.633900, 0.074200);
	glTexCoord2f(0.770300, 0.362300);
	glVertex3f(-0.059300, 1.622000, 0.035600);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	
	glEnd();

// 348.  268,  277,  276
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.752100, 0.308600);
	glVertex3f(-0.032400, 1.590700, 0.089100);
	glTexCoord2f(0.780900, 0.300400);
	glVertex3f(-0.027700, 1.625800, 0.104800);
	glTexCoord2f(0.784700, 0.330800);
	glVertex3f(-0.052100, 1.633900, 0.074200);
	
	glEnd();

// 349.  262,  288,  290
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.909800, 0.359300);
	glVertex3f(-0.056500, 1.796300, 0.058400);
	glTexCoord2f(0.964500, 0.328200);
	glVertex3f(0.000100, 1.815200, 0.062300);
	glTexCoord2f(0.988400, 0.404400);	
	glVertex3f(0.000100, 1.823300, -0.005400);
	
	glEnd();

// 350.  290,  286,  262
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.988400, 0.404400);
	glVertex3f(0.000100, 1.823300, -0.005400);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	glTexCoord2f(0.909800, 0.359300);	
	glVertex3f(-0.056500, 1.796300, 0.058400);
	
	glEnd();

// 351.  106,  146,  283
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	glTexCoord2f(0.868900, 0.311100);	
	glVertex3f(-0.038800, 1.737500, 0.109800);
	
	glEnd();

// 352.  283,  254,  106
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.868900, 0.311100);
	glVertex3f(-0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.854600, 0.310900);
	glVertex3f(-0.041600, 1.719200, 0.109800);
	glTexCoord2f(0.854600, 0.275800);	
	glVertex3f(-0.000000, 1.717900, 0.120300);
	
	glEnd();

// 353.  230,  251,  238
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.350300, 0.274100);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.297100, 0.242700);	
	glVertex3f(-0.154600, 1.369400, -0.025600);
	
	glEnd();

// 354.  238,  232,  230
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.297100, 0.242700);
	glVertex3f(-0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.357500, 0.232400);	
	glVertex3f(-0.149700, 1.355400, 0.061600);
	
	glEnd();

// 355.  178,  177,  184
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.145600, 0.497200);
	glVertex3f(-0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.145800, 0.583400);
	glVertex3f(-0.147200, 0.463700, -0.075500);
	glTexCoord2f(0.097400, 0.584400);	
	glVertex3f(-0.062300, 0.463000, -0.069600);
	
	glEnd();

// 356.  184,  191,  178
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.097400, 0.584400);
	glVertex3f(-0.062300, 0.463000, -0.069600);
	glTexCoord2f(0.094900, 0.497500);
	glVertex3f(-0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.145600, 0.497200);	
	glVertex3f(-0.153500, 0.312400, -0.103600);
	
	glEnd();

// 357.  259,  284,  283
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f(-0.077500, 1.718400, 0.071500);
	glTexCoord2f(0.839900, 0.338400);
	glVertex3f(-0.061500, 1.705100, 0.074800);
	glTexCoord2f(0.868900, 0.311100);
	glVertex3f(-0.038800, 1.737500, 0.109800);
	
	glEnd();

// 358.  283,  261,  259
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.868900, 0.311100);
	glVertex3f(-0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f(-0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f(-0.077500, 1.718400, 0.071500);
	
	glEnd();

// 359.  261,  283,  146
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f(-0.050200, 1.753800, 0.109800);
	glTexCoord2f(0.868900, 0.311100);
	glVertex3f(-0.038800, 1.737500, 0.109800);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	
	glEnd();

// 360.  146,  287,  261
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889200, 0.275500);
	glVertex3f(-0.000000, 1.754100, 0.116900);
	glTexCoord2f(0.907400, 0.279100);
	glVertex3f(-0.000000, 1.772000, 0.119400);
	glTexCoord2f(0.883000, 0.322800);
	glVertex3f(-0.050200, 1.753800, 0.109800);
	
	glEnd();

// 361.  222,   78,  227
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	
	glEnd();

// 362.  227,  226,  222
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.455300, 0.219800);
	glVertex3f(-0.065500, 1.348700, 0.165800);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	
	glEnd();

// 363.  285,  258,  279
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	glTexCoord2f(0.819300, 0.381800);
	glVertex3f(-0.101400, 1.666900, 0.033300);
	glTexCoord2f(0.755900, 0.392900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	
	glEnd();

// 364.  279,  278,  285
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.755900, 0.392900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	glTexCoord2f(0.770300, 0.362300);
	glVertex3f(-0.059300, 1.622000, 0.035600);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	
	glEnd();

// 365.  291,  292,  274
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.963000, 0.466400);
	glVertex3f(-0.033100, 1.826900, -0.057300);
	glTexCoord2f(0.996400, 0.462700);
	glVertex3f(0.000100, 1.837000, -0.048700);
	glTexCoord2f(0.962800, 0.525900);
	glVertex3f(0.000100, 1.811300, -0.108400);
	
	glEnd();

// 366.  274,  273,  291
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.962800, 0.525900);
	glVertex3f(0.000100, 1.811300, -0.108400);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	glTexCoord2f(0.963000, 0.466400);
	glVertex3f(-0.033100, 1.826900, -0.057300);
	
	glEnd();

// 367.  285,  284,  259
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	glTexCoord2f(0.839900, 0.338400);
	glVertex3f(-0.061500, 1.705100, 0.074800);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f(-0.077500, 1.718400, 0.071500);
	
	glEnd();

// 368.  259,  258,  285
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.851700, 0.355500);
	glVertex3f(-0.077500, 1.718400, 0.071500);
	glTexCoord2f(0.819300, 0.381800);
	glVertex3f(-0.101400, 1.666900, 0.033300);
	glTexCoord2f(0.809100, 0.356700);
	glVertex3f(-0.066700, 1.666000, 0.051800);
	
	glEnd();

// 369.  150,  293,  234
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.164600, 0.020700);
	glVertex3f(0.000000, 1.115200, -0.064300);
	glTexCoord2f(0.240600, 0.036500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	
	glEnd();

// 370.  234,   90,  150
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	glTexCoord2f(0.169000, 0.045600);
	glVertex3f(0.000000, 1.126500, -0.093300);
	glTexCoord2f(0.164600, 0.020700);
	glVertex3f(0.000000, 1.115200, -0.064300);
	
	glEnd();

// 371.  293,  294,  231
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.240600, 0.036500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.314300, 0.038200);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	
	glEnd();

// 372.  231,  234,  293
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.247300, 0.053400);
	glVertex3f(-0.104300, 1.119300, -0.075600);
	glTexCoord2f(0.240600, 0.036500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	
	glEnd();

// 373.  294,  295,  224
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.314300, 0.038200);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	glTexCoord2f(0.370200, 0.028900);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	
	glEnd();

// 374.  224,  231,  294
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.318900, 0.052000);
	glVertex3f(-0.161200, 1.116700, 0.020700);
	glTexCoord2f(0.314300, 0.038200);
	glVertex3f(-0.146100, 1.099700, 0.018800);
	
	glEnd();

// 375.  224,  295,  296
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	glTexCoord2f(0.370200, 0.028900);
	glVertex3f(-0.131500, 1.088300, 0.086600);
	glTexCoord2f(0.422800, 0.015200);
	glVertex3f(-0.076300, 1.080200, 0.128000);
	
	glEnd();

// 376.  296,  221,  224
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.422800, 0.015200);
	glVertex3f(-0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.370700, 0.042100);
	glVertex3f(-0.145200, 1.099900, 0.091500);
	
	glEnd();

// 377.  221,  296,  156
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	glTexCoord2f(0.422800, 0.015200);
	glVertex3f(-0.076300, 1.080200, 0.128000);
	glTexCoord2f(0.482400, 0.007500);
	glVertex3f(0.000000, 1.073400, 0.142800);
	
	glEnd();

// 378.  156,   61,  221
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.482400, 0.007500);
	glVertex3f(0.000000, 1.073400, 0.142800);
	glTexCoord2f(0.485600, 0.023900);
	glVertex3f(0.000000, 1.085600, 0.160800);
	glTexCoord2f(0.429800, 0.033100);
	glVertex3f(-0.081300, 1.092000, 0.151200);
	
	glEnd();

// 379.  263,  273,  272
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	glTexCoord2f(0.892500, 0.504300);
	glVertex3f(-0.042300, 1.762700, -0.116500);
	
	glEnd();

// 380.  272,  264,  263 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.892500, 0.504300);
	glVertex3f(-0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f(-0.052000, 1.737600, -0.071300);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	
	glEnd();

 // 381.  264,  272,  271
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f(-0.052000, 1.737600, -0.071300);
	glTexCoord2f(0.892500, 0.504300);
	glVertex3f(-0.042300, 1.762700, -0.116500);
	glTexCoord2f(0.889300, 0.547400);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	
	glEnd();

 // 382.  271,  289,  264
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889300, 0.547400);
	glVertex3f(-0.000000, 1.755900, -0.126900);
	glTexCoord2f(0.831300, 0.531300);
	glVertex3f(-0.000000, 1.708600, -0.081900);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f(-0.052000, 1.737600, -0.071300);
	
	glEnd();

 // 383.  290,  292,  291
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.988400, 0.404400);
	glVertex3f(0.000100, 1.823300, -0.005400);
	glTexCoord2f(0.996400, 0.462700);
	glVertex3f(0.000100, 1.837000, -0.048700);
	glTexCoord2f(0.963000, 0.466400);
	glVertex3f(-0.033100, 1.826900, -0.057300);
	
	glEnd();

 // 384.  291,  286,  290
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.963000, 0.466400);
	glVertex3f(-0.033100, 1.826900, -0.057300);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	glTexCoord2f(0.988400, 0.404400);
	glVertex3f(0.000100, 1.823300, -0.005400);
	
	glEnd();

 // 385.  286,  291,  273
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	glTexCoord2f(0.963000, 0.466400);
	glVertex3f(-0.033100, 1.826900, -0.057300);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	
	glEnd();

 // 386.  273,  263,  286
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.919700, 0.483500);
	glVertex3f(-0.064300, 1.797200, -0.093400);
	glTexCoord2f(0.900500, 0.448900);
	glVertex3f(-0.065100, 1.776000, -0.050500);
	glTexCoord2f(0.942100, 0.413500);
	glVertex3f(-0.038500, 1.805600, -0.010000);
	
	glEnd();

 // 387.  297,  298,  235
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.288400, 0.339800);
	glVertex3f(-0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.253100, 0.362900);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	
	glEnd();

 // 388.  235,  237,  297
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.255000, 0.271600);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.288400, 0.339800);
	glVertex3f(-0.195700, 1.491700, -0.080700);
	
	glEnd();

 // 389.   89,  233,  235
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	glTexCoord2f(0.240100, 0.141900);
	glVertex3f(-0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	
	glEnd();

 // 390.  235,   75,   89
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.157500, 0.229300);
	glVertex3f(0.000000, 1.368100, -0.107800);
	glTexCoord2f(0.166800, 0.143000);
	glVertex3f(0.000000, 1.231900, -0.084500);
	
	glEnd();

 // 391.  236,  235,  298
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.253100, 0.362900);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	
	glEnd();

 // 392.  298,  299,  236
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.253100, 0.362900);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.239600, 0.393400);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	
	glEnd();

 // 393.  236,  240,   84
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.185300, 0.390000);
	glVertex3f(-0.047800, 1.562000, -0.075700);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	
	glEnd();

 // 394.   84,   72,  236
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.146000, 0.386500);
	glVertex3f(0.000000, 1.560200, -0.089800);
	glTexCoord2f(0.150300, 0.294700);
	glVertex3f(0.000000, 1.452000, -0.160900);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	
	glEnd();

 // 395.  252,  245,  300
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	glTexCoord2f(0.383500, 0.429800);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	
	glEnd();

 // 396.  300,  301,  252
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.383500, 0.429800);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.352700, 0.422400);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	
	glEnd();

 // 397.  302,  246,  245
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	
	glEnd();

 // 398.  245,  252,  302
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	
	glEnd();

 // 399.  228,  227,  302 
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.412900, 0.251900);
	glVertex3f(-0.122900, 1.393800, 0.129500);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	
	glEnd();

 // 400.  302,  229,  228
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	glTexCoord2f(0.382200, 0.281900);
	glVertex3f(-0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.412900, 0.251900);
	glVertex3f(-0.122900, 1.393800, 0.129500);
	
	glEnd();

//	401.  242,  243,  246
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.454700, 0.414500);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	 
	glEnd();

//	402.  246,  239,  242
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	glTexCoord2f(0.473700, 0.299100);
	glVertex3f(-0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.490400, 0.378900);
	glEnd();

//	403.  301,  303,  253
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.352700, 0.422400);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	glTexCoord2f(0.305500, 0.407300); 
	glVertex3f(-0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.327600, 0.356000);
	glVertex3f(-0.200000, 1.496400, -0.003200);
	 
	glEnd();

//	404.  253,  252,  301
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.327600, 0.356000);
	glVertex3f(-0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	glTexCoord2f(0.352700, 0.422400);
	glVertex3f(-0.153500, 1.525500, -0.066500);
	 
	glEnd();

//	405.   59,   65,   64
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	glTexCoord2f(0.537200, 0.220000);
	glVertex3f(0.050900, 1.356800, 0.164600);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.559400, 0.251000);
	glEnd();

//	406.   64,   78,   59
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	
	glEnd();

//	407.   60,   59,   78
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.495500, 0.139900);
	glVertex3f(0.000000, 1.225000, 0.147100);
	glTexCoord2f(0.526400, 0.183800);
	glVertex3f(0.033800, 1.308400, 0.143300);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	glTexCoord2f(0.498800, 0.231800);
	glEnd();

//	408.   79,   64,  162
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.543000, 0.295300);
	glVertex3f(0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	glTexCoord2f(0.608400, 0.296300);
	glEnd();

//	409.  134,  135,  115
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.750100, 0.163400);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.740100, 0.115600);
	glVertex3f(0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.785300, 0.141200);
	glVertex3f(0.083600, 1.624900, -0.019600);
	 
	glEnd();

//	410.  163,   99,   85
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.578900, 0.408900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.535100, 0.436200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.537400, 0.375800);
	glVertex3f(0.022000, 1.516300, 0.040200);
	 
	glEnd();

//	411.   14,   23,   30
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.394900, 0.664700);
	glVertex3f(0.091700, 0.527400, 0.085700);
	glTexCoord2f(0.346200, 0.668500);
	glVertex3f(0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.346200, 0.668500);
	glEnd();

//	412.   14,   30,   15
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.385000, 0.622000);
	glVertex3f(0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.346200, 0.668500);
	glVertex3f(0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.342700, 0.643800);
	glVertex3f(0.047500, 0.481000, 0.007600);
	 
	glEnd();

//	413.   40,   20,   19
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.589200, 0.614800);
	glVertex3f(0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.542700, 0.616000);
	glVertex3f(0.060200, 0.558300, -0.035300);
	glTexCoord2f(0.573300, 0.585200);
	glVertex3f(0.036200, 0.522900, 0.021400);
	 
	glEnd();

//	414.   22,   29,   33
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.421500, 0.654500);
	glVertex3f(0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.432000, 0.685600);
	glVertex3f(0.136600, 0.585600, 0.074400);
	 
	glEnd();

//	415.   66,   58,   88
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	glTexCoord2f(0.669500, 0.126100);
	glVertex3f(0.133000, 1.221000, 0.007600);
	 
	glEnd();

//	416.   47,   53,   45
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.368400, 0.873400);
	glVertex3f(0.011600, 0.867800, 0.030400);
	glTexCoord2f(0.365100, 0.794600);
	glVertex3f(0.015800, 0.734600, 0.039900);
	 
	glEnd();

//	417.   36,   48,   24
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.582500, 0.806300);
	glVertex3f(0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.595300, 0.847300);
	glVertex3f(0.148100, 0.947800, -0.083000);
	glTexCoord2f(0.537600, 0.844600);
	glVertex3f(0.195000, 0.908900, 0.017900);
	 
	glEnd();

//	418.    4,   47,   46
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.410000, 0.886500);
	glVertex3f(0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	 
	glEnd();

//	419.   22,   13,   29
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.421500, 0.654500);
	glVertex3f(0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.430000, 0.596500);
	glVertex3f(0.168700, 0.454200, 0.003100);
	glTexCoord2f(0.463200, 0.653000);
	glVertex3f(0.154500, 0.560300, 0.009600);
	 
	glEnd();

//	420.   35,   50,   49
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.631000, 0.787100);
	glVertex3f(0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.670400, 0.813800);
	glVertex3f(0.000000, 0.924000, -0.095300);
	glTexCoord2f(0.633800, 0.823000);
	glVertex3f(0.072800, 0.922800, -0.112300);
	 
	glEnd();

//	421.    5,   46,   25
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.493900, 0.863500);
	glVertex3f(0.167900, 0.908700, 0.098100);
	 
	glEnd();

//	422.   46,    5,    4
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.446900, 0.878700);
	glVertex3f(0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.518800, 0.917600);
	glVertex3f(0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.472400, 0.929900);
	glVertex3f(0.087900, 0.997000, 0.133900);
	 
	glEnd();

//	423.   58,   66,   62
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.597000, 0.166100);
	glVertex3f(0.111500, 1.290100, 0.103800);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.599500, 0.206300);
	glVertex3f(0.136900, 1.338600, 0.129500);
	 
	glEnd();

//	424.   66,  100,   67
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.645700, 0.215800);
	glVertex3f(0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.661700, 0.255700);
	glVertex3f(0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.628900, 0.267300);
	glVertex3f(0.137900, 1.422500, 0.080800);
	
	glEnd();

//	425.  103,  106,  119
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832700, 0.257600);
	glVertex3f(0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	glTexCoord2f(0.836200, 0.275900);
	glVertex3f(-0.000000, 1.697500, 0.117900);
	
	glEnd();

//	426.  118,  117,  131
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.802400, 0.258600);
	glVertex3f(0.018500, 1.652400, 0.108500);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	glTexCoord2f(0.796800, 0.276000);
	glVertex3f(-0.000000, 1.643800, 0.118000);
	 
	glEnd();

//	427.   70,   74,   76
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.096300, 0.129600);
	glVertex3f(0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.085400, 0.267400);
	glVertex3f(0.096500, 1.419500, -0.122000);
	glTexCoord2f(0.050400, 0.255400);
	glVertex3f(0.146700, 1.402600, -0.096200);
	 
	glEnd();

//	428.  163,  304,   99
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.578900, 0.408900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.569600, 0.456800);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.535100, 0.436200);
	glVertex3f(0.029000, 1.591000, 0.046800);
	 
	glEnd();

//	429.   83,  159,   73
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.106200, 0.385400);
	glVertex3f(0.052400, 1.563700, -0.078800);
	glTexCoord2f(0.052300, 0.381300);
	glVertex3f(0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.105800, 0.324400);
	glVertex3f(0.070700, 1.504600, -0.138100);
	 
	glEnd();
//	430.   39,  305,    1
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.679500, 0.847600);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.690100, 0.931300);
	glVertex3f(0.000000, 1.115200, -0.064300);
	glTexCoord2f(0.638400, 0.939600);
	glVertex3f(0.085300, 1.111800, -0.061300);
	 
	glEnd();

//	431.   64,  161,  162
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.559400, 0.251000);
	glVertex3f(0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	 
	glEnd();

//	432.  161,   67,  102
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.609500, 0.278700);
	glVertex3f(0.119300, 1.446700, 0.082600);
	glTexCoord2f(0.628900, 0.267300);
	glVertex3f(0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.667900, 0.346000);
	glVertex3f(0.148000, 1.505700, 0.018300);
	 
	glEnd();

//	433.  116,  114,  107
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	glTexCoord2f(0.855200, 0.076200);
	glVertex3f(0.050000, 1.728000, -0.063400);
	glTexCoord2f(0.833300, 0.142700);
	glVertex3f(0.101300, 1.694900, -0.011200);
	 
	glEnd();

//	434.  110,  134,  115
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.810900, 0.172200);
	glVertex3f(0.098200, 1.656100, 0.034300);
	glTexCoord2f(0.750100, 0.163400);
	glVertex3f(0.049200, 1.611300, 0.003500);
	glTexCoord2f(0.785300, 0.141200);
	glVertex3f(0.083600, 1.624900, -0.019600);
	 
	glEnd();

//	435.  135,  116,  115
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.740100, 0.115600);
	glVertex3f(0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.798900, 0.095700);
	glVertex3f(0.061000, 1.658600, -0.070300);
	glTexCoord2f(0.785300, 0.141200);
	glVertex3f(0.083600, 1.624900, -0.019600);
	 
	glEnd();

//	436.  239,  246,  227
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.473700, 0.299100);
	glVertex3f(-0.048500, 1.433500, 0.101900);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	
	glEnd();

//	437.  279,  266,  281
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.755900, 0.392900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	glTexCoord2f(0.784500, 0.414500);
	glVertex3f(-0.077000, 1.628400, -0.020900);
	glTexCoord2f(0.742400, 0.439300);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	 
	glEnd();

//	438.  243,  242,  250
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.454700, 0.414500);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.490400, 0.378900);
	glVertex3f(-0.022000, 1.516300, 0.040200);
	glTexCoord2f(0.499300, 0.437400);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	 
	glEnd();

//	439.  179,  195,  188
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.296400, 0.624300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.249400, 0.637900);
	glVertex3f(-0.091700, 0.527400, 0.085700);
	 
	glEnd();

//	440.  179,  182,  195
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.243500, 0.594400);
	glVertex3f(-0.103900, 0.457500, 0.059400);
	glTexCoord2f(0.291100, 0.599900);
	glVertex3f(-0.047500, 0.481000, 0.007600);
	glTexCoord2f(0.296400, 0.624300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	 
	glEnd();

//	441.  206,  186,  185
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.049700, 0.659300);
	glVertex3f(-0.033600, 0.589300, 0.030200);
	glTexCoord2f(0.053700, 0.626300);
	glVertex3f(-0.036200, 0.522900, 0.021400);
	glTexCoord2f(0.093600, 0.644000);
	glVertex3f(-0.060200, 0.558300, -0.035300);
	 
	glEnd();

//	442.  187,  198,  194
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.220500, 0.637500);
	glVertex3f(-0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.221900, 0.670500);
	glVertex3f(-0.136600, 0.585600, 0.074400);
	glTexCoord2f(0.181200, 0.650600);
	glVertex3f(-0.154500, 0.560300, 0.009600);
	 
	glEnd();

//	443.  230,  232,  223
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.313800, 0.145200);
	glVertex3f(-0.133000, 1.221000, 0.007600);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	 
	glEnd();

//	444.  211,  209,  216
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	glTexCoord2f(0.320900, 0.749500);
	glVertex3f(-0.015800, 0.734600, 0.039900);
	glTexCoord2f(0.346100, 0.823700);
	glVertex3f(-0.011600, 0.867800, 0.030400);
	 
	glEnd();

//	445.  201,  189,  213
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.123400, 0.837400);
	glVertex3f(-0.143700, 0.875500, -0.065900);
	glTexCoord2f(0.178400, 0.856400);
	glVertex3f(-0.195000, 0.908900, 0.017900);
	glTexCoord2f(0.124200, 0.878200);
	glVertex3f(-0.148100, 0.961900, -0.083000);
	 
	glEnd();

//	446.  169,  212,  211
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.313400, 0.850400);
	glVertex3f(-0.024800, 0.895100, 0.094200);
	
	glEnd();

//	447.  187,  194,  176
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.220500, 0.637500);
	glVertex3f(-0.138500, 0.528400, 0.067200);
	glTexCoord2f(0.181200, 0.650600);
	glVertex3f(-0.154500, 0.560300, 0.009600);
	glTexCoord2f(0.192900, 0.586400);
	glVertex3f(-0.168700, 0.454200, 0.003100);
	 
	glEnd();

//	448.  202,  214,  215
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.069500, 0.834900);
	glVertex3f(-0.054600, 0.874300, -0.071700);
	glTexCoord2f(0.080900, 0.872100);
	glVertex3f(-0.072800, 0.922800, -0.112300);
	glTexCoord2f(0.041800, 0.874400);
	glVertex3f(0.000000, 0.924000, -0.095300);
	 
	glEnd();

//	449.  172,  190,  212
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	glTexCoord2f(0.225700, 0.858400);
	glVertex3f(-0.167900, 0.908700, 0.098100);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	 
	glEnd();

//	450.  212,  169,  172
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.274800, 0.856500);
	glVertex3f(-0.083600, 0.901900, 0.126700);
	glTexCoord2f(0.269700, 0.913300);
	glVertex3f(-0.087900, 0.997000, 0.133900);
	glTexCoord2f(0.221900, 0.917900);
	glVertex3f(-0.161200, 1.011700, 0.090200);
	 
	glEnd();

//	451.  223,  225,  230
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.397400, 0.169700);
	glVertex3f(-0.109500, 1.278500, 0.104000);
	glTexCoord2f(0.406000, 0.220900);
	glVertex3f(-0.132100, 1.343700, 0.131600);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	 
	glEnd();

//	452.  230,  229,  251
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.357500, 0.232400);
	glVertex3f(-0.149700, 1.355400, 0.061600);
	glTexCoord2f(0.382200, 0.281900);
	glVertex3f(-0.137900, 1.422500, 0.080800);
	glTexCoord2f(0.350300, 0.274100);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	 
	glEnd();

//	453.  256,  119,  106
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.832900, 0.294200);
	glVertex3f(-0.014800, 1.693400, 0.102300);
	glTexCoord2f(0.836200, 0.275900);
	glVertex3f(-0.000000, 1.697500, 0.117900);
	glTexCoord2f(0.854600, 0.275800);
	glVertex3f(-0.000000, 1.717900, 0.120300);
	 
	glEnd();

//	454.  267,  131,  117
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.802500, 0.293400);
	glVertex3f(-0.018600, 1.652400, 0.108500);
	glTexCoord2f(0.796800, 0.276000);
	glVertex3f(-0.000000, 1.643800, 0.118000);
	glTexCoord2f(0.810500, 0.276000);
	glVertex3f(-0.000000, 1.656300, 0.139500);
	 
	glEnd();


//	455.  233,  237,  235
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.240100, 0.141900);
	glVertex3f(-0.085500, 1.218500, -0.066500);
	glTexCoord2f(0.255000, 0.271600);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.217400, 0.279500);
	glVertex3f(-0.096500, 1.419500, -0.122000);
	 
	glEnd();

//	456.  243,  250,  306
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.454700, 0.414500);
	glVertex3f(-0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.499300, 0.437400);
	glVertex3f(-0.029000, 1.591000, 0.046800);
	glTexCoord2f(0.466600, 0.466900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	 
	glEnd();

//	457.  240,  236,  299
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.185300, 0.390000);
	glVertex3f(-0.047800, 1.562000, -0.075700);
	glTexCoord2f(0.193400, 0.330800);
	glVertex3f(-0.070700, 1.504600, -0.138100);
	glTexCoord2f(0.239600, 0.393400);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	 
	glEnd();

//	458.  204,  168,  307
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.046000, 0.911500);
	glVertex3f(0.000000, 0.991100, -0.114900);
	glTexCoord2f(0.118900, 0.981500);
	glVertex3f(-0.085300, 1.111800, -0.061300);
	glTexCoord2f(0.067900, 0.992900);
	glVertex3f(0.000000, 1.115200, -0.064300);
	 
	glEnd();

//	459.  227,  246,  302
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.447600, 0.259600);
	glVertex3f(-0.082300, 1.404800, 0.155200);
	glTexCoord2f(0.414300, 0.312400);
	glVertex3f(-0.123600, 1.462900, 0.091200);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	 
	glEnd();

//	460.  302,  252,  229
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.405200, 0.290800);
	glVertex3f(-0.120000, 1.436100, 0.092000);
	glTexCoord2f(0.357500, 0.364700);
	glVertex3f(-0.155300, 1.510500, 0.004500);
	glTexCoord2f(0.382200, 0.281900);
	glVertex3f(-0.137900, 1.422500, 0.080800);
	 
	glEnd();

//	461.  265,  257,  264
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	glTexCoord2f(0.836000, 0.408500);
	glVertex3f(-0.101400, 1.694900, -0.011200);
	glTexCoord2f(0.867300, 0.481200);
	glVertex3f(-0.052000, 1.737600, -0.071300);
	 
	glEnd();

//	462.  258,  266,  279
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.819300, 0.381800);
	glVertex3f(-0.101400, 1.666900, 0.033300);
	glTexCoord2f(0.784500, 0.414500);
	glVertex3f(-0.077000, 1.628400, -0.020900);
	glTexCoord2f(0.755900, 0.392900);
	glVertex3f(-0.050800, 1.617800, 0.001500);
	 
	glEnd();

//	463.  281,  266,  265
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.742400, 0.439300);
	glVertex3f(-0.033900, 1.610900, -0.035400);
	glTexCoord2f(0.784500, 0.414500);
	glVertex3f(-0.077000, 1.628400, -0.020900);
	glTexCoord2f(0.808500, 0.459100);
	glVertex3f(-0.065800, 1.666000, -0.074000);
	 
	glEnd();

//	464.  159,   83,   82
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.052300, 0.381300);
	glVertex3f(0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.106200, 0.385400);
	glVertex3f(0.052400, 1.563700, -0.078800);
	glTexCoord2f(0.114000, 0.411500);
	glVertex3f(0.032800, 1.559100, -0.046700);
	 
	glEnd();

//	465.  241,  240,  299
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.174300, 0.414800);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.185300, 0.390000);
	glVertex3f(-0.047800, 1.562000, -0.075700);
	glTexCoord2f(0.239600, 0.393400);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	 
	glEnd();

//	466.  222,   60,   78
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.470000, 0.186000);
	glVertex3f(-0.036100, 1.305900, 0.139000);
	glTexCoord2f(0.495500, 0.139900);
	glVertex3f(0.000000, 1.225000, 0.147100);
	glTexCoord2f(0.498800, 0.231800);
	glVertex3f(0.000000, 1.368100, 0.137700);
	 
	glEnd();

//	467.  163,  162,   91
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.578900, 0.408900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	glTexCoord2f(0.608400, 0.296300);
	glVertex3f(0.121700, 1.455500, 0.096800);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	 
	glEnd();

//	468.   91,   93,  163
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.644200, 0.347500);
	glVertex3f(0.146600, 1.524500, 0.046400);
	glTexCoord2f(0.586400, 0.443200);
	glVertex3f(0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.578900, 0.408900);
	glVertex3f(0.049100, 1.542500, -0.004900);
	 
	glEnd();

//	469.  244,  300,  245
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.452300, 0.450400);
	glVertex3f(-0.032800, 1.559100, -0.046700);
	glTexCoord2f(0.383500, 0.429800);
	glVertex3f(-0.121400, 1.558800, -0.054000);
	glTexCoord2f(0.373700, 0.362000);
	glVertex3f(-0.153200, 1.532000, 0.010100);
	 
	glEnd();

//	470.  308,  309,  310
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.676300, 0.945000);
	glVertex3f(0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.743500, 0.952300);
	glVertex3f(0.080700, 0.000300, -0.097600);
	
	glEnd();

//	471.  310,  311,  308
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.743500, 0.952300);
	glVertex3f(0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.742600, 0.978500);
	glVertex3f(0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(0.172200, 0.000300, 0.031200);
	 
	glEnd();

//	472.  312,  313,  314
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.568800, 0.514100);
	glVertex3f(0.080700, 0.000300, -0.097600);
	 glTexCoord2f(0.622600, 0.466800);
	glVertex3f(0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	473.  314,  315,  312
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.568800, 0.514100);
	glVertex3f(0.080700, 0.000300, -0.097600);
	 
	glEnd();

//	474.  316,  317,  318
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(0.173900, 0.307400, -0.027100);
	 
	glEnd();

//	475.  318,  319,  316
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	 
	glEnd();


//	476.  320,  321,  322
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.790300, 0.587600);
	glVertex3f(0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.766700, 0.682900);
	glVertex3f(0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.766700, 0.682900);
	glEnd();

//	477.  322,  323,  320
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.766700, 0.682900);
	glVertex3f(0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.728300, 0.674500);
	glVertex3f(0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	 
	glEnd();

//	478.  316,  324,  325
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(0.080700, 0.000300, -0.097600);
	 
	glEnd();

//	479.  325,  320,  316
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	 
	glEnd();

//	480.  326,  327,  314
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	481.  314,  313,  326
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.622600, 0.466800);
	glVertex3f(0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(0.098200, 0.005500, 0.139400);
	 
	glEnd();

//	482.  314,  327,  328
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(0.150600, 0.039600, 0.132000);
	 
	glEnd();

//	483.  328,  329,  314
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	484.  330,  331,  329
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.717800, 0.478800);
	glVertex3f(0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	 
	glEnd();

//	485.  329,  328,  330
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	486.  309,  308,  332
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.676300, 0.945000);
	glVertex3f(0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.635000, 0.984600);
	glVertex3f(0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	487.  332,  333,  309
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.635000, 0.984600);
	glVertex3f(0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.635000, 0.954400);
	glVertex3f(0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.676300, 0.945000); 
	glVertex3f(0.073400, 0.000300, 0.050300);
	 
	glEnd();

//	488.  330,  328,  327
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(0.111400, 0.043100, 0.140100);
	 
	glEnd();

//	489.  327,  326,  330
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	490.  334,  319,  318
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(0.173900, 0.307400, -0.027100);
	 
	glEnd();

//	491.  318,  335,  334
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	 
	glEnd();

//	492.  320,  323,  317
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.728300, 0.674500);
	glVertex3f(0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(0.153500, 0.312400, -0.103600);
	 
	glEnd();

//	493.  317,  316,  320
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	 
	glEnd();

//	494.  329,  331,  324
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.717800, 0.478800);
	glVertex3f(0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(0.135800, 0.000300, -0.099100);
	 
	glEnd();

//	495.  324,  319,  329
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	 
	glEnd();

//	496.  314,  329,  334
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	 
	glEnd();

//	497.  334,  336,  314
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	498.  336,  335,  337
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.593000, 0.610400);
	glVertex3f(0.053900, 0.302200, -0.019200);
	 
	glEnd();

//	499.  337,  315,  336
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.593000, 0.610400);
	glVertex3f(0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(0.088900, 0.106000, 0.005700);
	 
	glEnd();

//	500.  338,  339,  340
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.806900, 0.982800);
	glVertex3f(0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	 
	glEnd();
	

//	501.  340,  341,  338
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(0.195700, 1.491700, -0.080700);
	 
	glEnd();

//	502.  342,  343,  344
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(0.163600, 1.405300, 0.046200);
	 
	glEnd();

//	503.  344,  345,  342
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.695400, 0.896000);
	glVertex3f(0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(0.201000, 1.334500, -0.035700);
	 
	glEnd();

//	504.  341,  346,  347
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(0.146700, 1.402600, -0.096200);
	
	glEnd();

//	505.  347,  338,  341
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	 
	glEnd();

//	506.  348,  347,  346
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.991900, 0.951100);
	glVertex3f(0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	507.  346,  349,  348
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.980500, 0.906500);
	glVertex3f(0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.991900, 0.951100);
	glVertex3f(0.154600, 1.369400, -0.025600);
	 
	glEnd();

//	508.  340,  339,  344
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.806900, 0.982800);
	glVertex3f(0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(0.163600, 1.405300, 0.046200);
	 
	glEnd();

//	509.  344,  343,  340
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	 
	glEnd();

//	510.  350,  351,  352
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.725400, 0.810700);
	glVertex3f(0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.685800, 0.800800);
	glVertex3f(0.601400, 0.923800, 0.114400);
	 
	glEnd();

//	511.  352,  353,  350
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.685800, 0.800800);
	glVertex3f(0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(0.580300, 0.969800, 0.031700);
	 
	glEnd();

//	512.  354,  355,  356
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.964800, 0.551100);
	glVertex3f(0.508900, 1.065900, 0.062500);
	 
	glEnd();

	//	513.  356,  357,  354
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.964800, 0.551100);
	glVertex3f(0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.974800, 0.588000);
	glVertex3f(0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	 
	glEnd();

//	514.  358,  359,  360
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(0.580300, 0.969800, 0.031700);
	 
	glEnd();

//	515.  360,  361,  358
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.418200, 0.442800);
	glVertex3f(0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(0.552400, 1.087700, 0.028100);
	 
	glEnd();

//	516.  362,  363,  364
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.356300, 0.524800);
	glVertex3f(0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	517.  364,  365,  362
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	 
	glEnd();

//	518.  366,  367,  368
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.290700, 0.529800);
	glVertex3f(0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.318800, 0.503500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	 
	glEnd();

//	519.  368,  369,  366
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.318800, 0.503500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(0.546900, 0.974700, 0.144600);
	 
	glEnd();

//	520.  370,  371,  372
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.663300, 0.701400);
	glVertex3f(0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	 
	glEnd();

//	521.  372,  373,  370
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.663100, 0.708000);
	glVertex3f(0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.663300, 0.701400);
	glVertex3f(0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	522.  374,  375,  376
	glBegin(GL_TRIANGLES);
	glVertex3f(0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.862300, 0.557600);
	glVertex3f(0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.904000, 0.557000);
	glEnd();

//	523.  376,  377,  374
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.904000, 0.557000);
	glVertex3f(0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	524.  374,  377,  378
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	
	glEnd();

//	525.  378,  379,  374
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	526.  369,  362,  365
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(0.538700, 0.979800, 0.151000);
	 
	glEnd();

//	527.  365,  366,  369
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	 
	glEnd();

//	528.  362,  380,  381
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.392500, 0.510700);
	glVertex3f(0.508900, 1.065900, 0.062500);
	 
	glEnd();

//	529.  381,  363,  362
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.392500, 0.510700);
	glVertex3f(0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.356300, 0.524800);
	glVertex3f(0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	 
	glEnd();

//	530.  366,  365,  364
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	531.  364,  382,  366
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.300100, 0.540700);
	glVertex3f(0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(0.546900, 0.974700, 0.144600);
	 
	glEnd();
//	532.  383,  384,  385
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	 
	glEnd();

//	533.  385,  386,  383
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	 
	glEnd();

//	534.  385,  384,  387
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(0.326500, 1.214000, -0.008800);
	 
	glEnd();

//	535.  387,  388,  385
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	
	glEnd();

//	536.  389,  359,  390
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	 
	glEnd();

//	537.  390,  391,  389
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	
	glEnd();

//	538.  391,  390,  392
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(0.583000, 0.983300, 0.119600);
	 
	glEnd();

//	539.  392,  393,  391
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.229400, 0.468300);
	glVertex3f(0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(0.611300, 0.929000, 0.117900);
	 
	glEnd();

//	540.  369,  368,  392
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.318800, 0.503500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.284800, 0.488100); 
	glVertex3f(0.583000, 0.983300, 0.119600);
	 
	glEnd();

//	541.  392,  390,  369
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	 
	glEnd();

//	542.  394,  372,  371
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(0.511300, 1.027600, 0.104800);
	
	glEnd();

//	543.  371,  395,  394
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.717400, 0.677400);
	glVertex3f(0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	544.  396,  375,  374
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.835100, 0.544500);
	glVertex3f(0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.862300, 0.557600);
	glVertex3f(0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	545.  374,  397,  396
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.862300, 0.557600);
	glVertex3f(0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.835100, 0.544500);
	glVertex3f(0.508900, 1.065900, 0.062500);
	 
	glEnd();

//	546.  343,  342,  398
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(0.291500, 1.249900, -0.015500);
	 
	glEnd();

//	547.  398,  399,  343
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	 
	glEnd();

//	548.  346,  385,  388
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(0.291500, 1.249900, -0.015500);
	 
	glEnd();

//	549.  388,  349,  346
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.980500, 0.906500);
	glVertex3f(0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	550.  341,  340,  400
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	 
	glEnd();

//	551.  400,  386,  341
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	
	glEnd();

//	552.  346,  341,  386
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(0.347400, 1.312300, -0.065600);
 
	glEnd();

//	553.  386,  385,  346
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	554.  343,  399,  400
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	 
	glEnd();

//	555.  400,  340,  343
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(0.217700, 1.354600, 0.023900);
	 
	glEnd();

//	556.  377,  376,  355
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.904000, 0.557000);
	glVertex3f(0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	557.  355,  354,  377
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(0.517600, 1.119300, 0.013500);
	 
	glEnd();

//	558.  360,  359,  389
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	 
	glEnd();

//	559.  389,  401,  360
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.281400, 0.400300);
	glVertex3f(0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(0.580300, 0.969800, 0.031700);
	 
	glEnd();

//	560.  402,  403,  389
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.220700, 0.447900);
	glVertex3f(0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.257500, 0.409400);
	glVertex3f(0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	 
	glEnd();

//	561.  389,  391,  402
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.220700, 0.447900);
	glVertex3f(0.601400, 0.923800, 0.114400);
	 
	glEnd();

//	562.  353,  372,  394
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	563.  394,  350,  353
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(0.583000, 0.983300, 0.119600);
 
	glEnd();

//	564.  379,  404,  397
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.816400, 0.578100);
	glVertex3f(0.477300, 1.095400, 0.042900);
	 
	glEnd();

//	565.  397,  374,  379
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.816400, 0.578100);
	glVertex3f(0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	 
	glEnd();

//	566.  405,  387,  384
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	 
	glEnd();

//	567.  384,  406,  405
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	568.  384,  383,  378
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	569.  378,  406,  384
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(0.341800, 1.225400, -0.072700);
	 
	glEnd();

//	570.  378,  377,  354
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	 
	glEnd();

//	571.  354,  406,  378
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	572.  405,  406,  354
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	 
	glEnd();

//	573.  354,  357,  405
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.974800, 0.588000);
	glVertex3f(0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.993500, 0.606700); 
	glVertex3f(0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	574.  378,  383,  407
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	 
	glEnd();

//	575.  407,  379,  378
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	576.  408,  409,  404
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(0.373500, 1.233700, 0.035600);
	glTexCoord2f(0.758900, 0.735100);
	glVertex3f(0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	577.  404,  379,  408
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(0.373500, 1.233700, 0.035600);
	 
	glEnd();

//	578.  335,  336,  334
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	 
	glEnd();

//	579.  319,  324,  316
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(0.130600, 0.095700, -0.095000);
	 
	glEnd();

//	580.  319,  334,  329
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(0.143300, 0.064300, 0.048800);
	 
	glEnd();

//	581.  321,  320,  325
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.790300, 0.587600);
	glVertex3f(0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(0.080700, 0.000300, -0.097600);
	
	glEnd();

//	582.  314,  336,  315
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(0.070300, 0.104400, -0.024700);
	 
	glEnd();

//	583.  409,  408,  399
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758900, 0.735100);
	glVertex3f(0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.807400, 0.724300); 
	glVertex3f(0.373500, 1.233700, 0.035600);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	 
	glEnd();

//	584.  400,  399,  407
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(0.401600, 1.273600, 0.013100);
	 
	glEnd();

//	585.  380,  362,  369
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	 
	glEnd();

//	586.  400,  383,  386
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.889900, 0.809300); 
	glVertex3f(0.347400, 1.312300, -0.065600);
	 
	glEnd();

//	587.  398,  409,  399
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.758900, 0.735100);
	glVertex3f(0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	 
	glEnd();

//	588.  383,  400,  407
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(0.401600, 1.273600, 0.013100);
	 
	glEnd();

//	589.  369,  358,  380
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(0.530000, 1.095600, 0.074900);
	 
	glEnd();

//	590.  399,  408,  407
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(0.373500, 1.233700, 0.035600);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(0.401600, 1.273600, 0.013100);
	 
	glEnd();

//	591.  390,  359,  358
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(0.552400, 1.087700, 0.028100);
	 
	glEnd();

//	592.  369,  390,  358
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(0.552400, 1.087700, 0.028100);
	 
	glEnd();

//	593.  379,  407,  408
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(0.401600, 1.273600, 0.013100);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(0.373500, 1.233700, 0.035600);
	 
	glEnd();

//	594.  410,  411,  412
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(-0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.742600, 0.978500);
	glVertex3f(-0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.743500, 0.952300);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	 
	glEnd();

//	595.  412,  413,  410
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.743500, 0.952300);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.676300, 0.945000);
	glVertex3f(-0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(-0.172200, 0.000300, 0.031200);
	 
	glEnd();

//	596.  414,  415,  416
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.568800, 0.514100);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(-0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	597.  416,  417,  414
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.622600, 0.466800);
	glVertex3f(-0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.568800, 0.514100);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	 
	glEnd();

//	598.  418,  419,  420
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(-0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(-0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	 
	glEnd();

//	599.  420,  421,  418
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(-0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(-0.130600, 0.095700, -0.095000);
	 
	glEnd();

//	600.  422,  423,  424
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.728300, 0.674500);
	glVertex3f(-0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.766700, 0.682900);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	 
	glEnd();

//	601.  424,  425,  422
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.766700, 0.682900);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.790300, 0.587600);
	glVertex3f(-0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	 
	glEnd();

//	602.  418,  422,  426
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(-0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	 
	glEnd();

//	603.  426,  427,  418
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(-0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.736700, 0.557700); 
	glVertex3f(-0.130600, 0.095700, -0.095000);
	 
	glEnd();

//	604.  428,  417,  416
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(-0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.622600, 0.466800);
	glVertex3f(-0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	605.  416,  429,  428
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(-0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(-0.098200, 0.005500, 0.139400);
	 
	glEnd();

//	606.  416,  430,  431
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(-0.150600, 0.039600, 0.132000);
	 
	glEnd();

//	607.  431,  429,  416
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(-0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(-0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	608.  432,  431,  430
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(-0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	 
	glEnd();

//	609.  430,  433,  432
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.717800, 0.478800);
	glVertex3f(-0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	610.  413,  434,  435
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.676300, 0.945000);
	glVertex3f(-0.073400, 0.000300, 0.050300);
	glTexCoord2f(0.635000, 0.954400);
	glVertex3f(-0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.635000, 0.984600);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	611.  435,  410,  413
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.635000, 0.984600);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.682300, 0.992200);
	glVertex3f(-0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.676300, 0.945000);
	glVertex3f(-0.073400, 0.000300, 0.050300);
	 
	glEnd();

//	612.  432,  428,  429
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	glTexCoord2f(0.654800, 0.431300);
	glVertex3f(-0.098200, 0.005500, 0.139400);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(-0.111400, 0.043100, 0.140100);
	 
	glEnd();

//	613.  429,  431,  432
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.664700, 0.446000);
	glVertex3f(-0.111400, 0.043100, 0.140100);
	glTexCoord2f(0.681200, 0.447400);
	glVertex3f(-0.150600, 0.039600, 0.132000);
	glTexCoord2f(0.691500, 0.434200);
	glVertex3f(-0.161800, 0.005500, 0.135600);
	 
	glEnd();

//	614.  436,  437,  420
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.658400, 0.636200); 
	glVertex3f(-0.173900, 0.307400, -0.027100);
	 
	glEnd();

//	615.  420,  419,  436
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.658400, 0.636200);
	glVertex3f(-0.173900, 0.307400, -0.027100);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(-0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	 
	glEnd();

//	616.  422,  418,  421
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(-0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(-0.153500, 0.312400, -0.103600);
	 
	glEnd();

//	617.  421,  423,  422
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.689200, 0.656400);
	glVertex3f(-0.153500, 0.312400, -0.103600);
	glTexCoord2f(0.728300, 0.674500);
	glVertex3f(-0.064800, 0.310200, -0.097300);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	 
	glEnd();

//	618.  430,  419,  427
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(-0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(-0.135800, 0.000300, -0.099100);
	 
	glEnd();

//	619.  427,  433,  430
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(-0.135800, 0.000300, -0.099100);
	glTexCoord2f(0.717800, 0.478800);
	glVertex3f(-0.172200, 0.000300, 0.031200);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	 
	glEnd();

//	620.  416,  438,  436
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(-0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	 
	glEnd();

	//	621.  436,  430,  416
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	 
	glEnd();

//	622.  438,  415,  439
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(-0.088900, 0.106000, 0.005700);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(-0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.593000, 0.610400);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	 
	glEnd();

//	623.  439,  437,  438
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.593000, 0.610400);
	glVertex3f(-0.053900, 0.302200, -0.019200);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(-0.088900, 0.106000, 0.005700);
	 
	glEnd();

//	624.  440,  441,  442
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(-0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	 
	glEnd();

//	625.  442,  443,  440
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.806900, 0.982800);
	glVertex3f(-0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(-0.195700, 1.491700, -0.080700);
	 
	glEnd();

//	626.  444,  445,  446
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(-0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.695400, 0.896000);
	glVertex3f(-0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	 
	glEnd();

//	627.  446,  447,  444
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(-0.201000, 1.334500, -0.035700);
	 
	glEnd();

//	628.  441,  440,  448
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.862300, 0.993800);
	glVertex3f(-0.195700, 1.491700, -0.080700);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	 
	glEnd();

//	629.  448,  449,  441
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	 
	glEnd();

//	630.  450,  451,  449
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.991900, 0.951100);
	glVertex3f(-0.154600, 1.369400, -0.025600);
	glTexCoord2f(0.980500, 0.906500);
	glVertex3f(-0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	631.  449,  448,  450
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.927500, 0.923100);
	glTexCoord2f(0.938200, 0.976700);
	glVertex3f(-0.146700, 1.402600, -0.096200);
	glTexCoord2f(0.991900, 0.951100);
	glVertex3f(-0.154600, 1.369400, -0.025600);
	 
	glEnd();

//	632.  442,  447,  446
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.739800, 0.938000); 
	glVertex3f(-0.163600, 1.405300, 0.046200);
	 
	glEnd();

//	633.  446,  443,  442
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.739800, 0.938000);
	glVertex3f(-0.163600, 1.405300, 0.046200);
	glTexCoord2f(0.806900, 0.982800);
	glVertex3f(-0.200000, 1.496400, -0.003200);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	 
	glEnd();

//	634.  452,  453,  454
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.685800, 0.800800);
	glVertex3f(-0.601400, 0.923800, 0.114400);
	 
	glEnd();

//	635.  454,  455,  452
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.685800, 0.800800);
	glVertex3f(-0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.725400, 0.810700);
	glVertex3f(-0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	 
	glEnd();

//	636.  456,  457,  458
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.974800, 0.588000);
	glVertex3f(-0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.964800, 0.551100);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	 
	glEnd();

//	637.  458,  459,  456
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.964800, 0.551100);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
 
	glEnd();

//	638.  460,  461,  462
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.418200, 0.442800);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	 
	glEnd();

//	639.  462,  463,  460
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(-0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(-0.552400, 1.087700, 0.028100);
 
	glEnd();

//	640.  464,  465,  466
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(-0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(-0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	641.  466,  467,  464
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.356300, 0.524800);
	glVertex3f(-0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(-0.532000, 1.040600, 0.119000);
	 
	glEnd();

//	642.  468,  469,  470
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(-0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.318800, 0.503500); 
	glVertex3f(-0.540200, 1.008300, 0.099600);
	
	glEnd();

//	643.  470,  471,  468
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.318800, 0.503500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.290700, 0.529800);
	glVertex3f(-0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(-0.546900, 0.974700, 0.144600);
	 
	glEnd();

//	644.  472,  473,  474
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.663300, 0.701400);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.663100, 0.708000);
	glVertex3f(-0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	 
	glEnd();

//	645.  474,  475,  472
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(-0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.663300, 0.701400);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	646.  476,  477,  478
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(-0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.904000, 0.557000);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	 
	glEnd();

//	647.  478,  479,  476
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.904000, 0.557000);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.862300, 0.557600);
	glVertex3f(-0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	648.  476,  480,  481
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	649.  481,  477,  476
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(-0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	650.  469,  468,  465
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(-0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(-0.538700, 0.979800, 0.151000);
	 
	glEnd();

//	651.  465,  464,  469
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(-0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(-0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.338400, 0.497200); 
	glVertex3f(-0.559800, 1.034100, 0.115600);
	 
	glEnd();

//	652.  464,  467,  482
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(-0.532000, 1.040600, 0.119000);
	glTexCoord2f(0.356300, 0.524800);
	glVertex3f(-0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.392500, 0.510700);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	 
	glEnd();

//	653.  482,  483,  464
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.392500, 0.510700);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(-0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.350100, 0.508800);
	glVertex3f(-0.532000, 1.040600, 0.119000);
	 
	glEnd();

//	654.  468,  484,  466
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(-0.546900, 0.974700, 0.144600);
	glTexCoord2f(0.300100, 0.540700);
	glVertex3f(-0.537700, 0.966400, 0.137100);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	 
	glEnd();

//	655.  466,  465,  468
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.308700, 0.540700);
	glVertex3f(-0.531000, 0.971200, 0.144400);
	glTexCoord2f(0.308600, 0.533500);
	glVertex3f(-0.538700, 0.979800, 0.151000);
	glTexCoord2f(0.299000, 0.531300);
	glVertex3f(-0.546900, 0.974700, 0.144600);
	 
	glEnd();

//	656.  485,  486,  487
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(-0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(-0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	 
	glEnd();

//	657.  487,  488,  485
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.894300, 0.769600); 
	glVertex3f(-0.386300, 1.275700, -0.060500);
	 
	glEnd();

//	658.  487,  489,  490
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	 
	glEnd();

//	659.  490,  488,  487
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	 
	glEnd();

//	660.  491,  492,  493
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(-0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.291800, 0.479400); 
	glVertex3f(-0.599200, 0.990000, 0.120300);
	 
	glEnd();

//	661.  493,  463,  491
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(-0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(-0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	 
	glEnd();

//	662.  492,  494,  495
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(-0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.229400, 0.468300);
	glVertex3f(-0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	 
	glEnd();

//	663.  495,  493,  492
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(-0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.238100, 0.454800); 
	glVertex3f(-0.611300, 0.929000, 0.117900);
	 
	glEnd();

//	664.  469,  493,  495
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(-0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.284800, 0.488100); 
	glVertex3f(-0.583000, 0.983300, 0.119600);
	 
	glEnd();

//	665.  495,  470,  469
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.284800, 0.488100);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.318800, 0.503500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.338400, 0.497200); 
	glVertex3f(-0.559800, 1.034100, 0.115600);
	 
	glEnd();

//	666.  496,  497,  475
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.717400, 0.677400);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(-0.511300, 1.027600, 0.104800);
	 
	glEnd();

//	667.  475,  474,  496
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.692300, 0.685500);
	glVertex3f(-0.511300, 1.027600, 0.104800);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	668.  498,  499,  476
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.835100, 0.544500);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	glTexCoord2f(0.816400, 0.578100);
	glVertex3f(-0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	 
	glEnd();

//	669.  476,  479,  498
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.862300, 0.557600);
	glVertex3f(-0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.835100, 0.544500);
	glVertex3f(-0.508900, 1.065900, 0.062500);
	 
	glEnd();

///	670.  447,  500,  501
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	 
	glEnd();

//	671.  501,  444,  447
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.714100, 0.856200);
	glVertex3f(-0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	 
	glEnd();

//	672.  449,  451,  489
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.980500, 0.906500);
	glVertex3f(-0.201000, 1.334500, -0.035700);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	 
	glEnd();

//	673.  489,  487,  449
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.994300, 0.806100);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	674.  441,  486,  502
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(-0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	
	glEnd();

//	675.  502,  442,  441
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	 
	glEnd();

//	676.  449,  487,  486
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	glTexCoord2f(0.939300, 0.808300);
	glVertex3f(-0.310700, 1.265200, -0.081500);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(-0.347400, 1.312300, -0.065600);
	 
	glEnd();

//	677.  486,  441,  449
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(-0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.876900, 0.898300);
	glVertex3f(-0.267400, 1.393800, -0.071300);
	glTexCoord2f(0.927500, 0.923100);
	glVertex3f(-0.208400, 1.369000, -0.095400);
	 
	glEnd();

//	678.  447,  442,  502
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	glTexCoord2f(0.822800, 0.892500);
	glVertex3f(-0.268700, 1.404500, -0.008700);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	 
	glEnd();

//	679.  502,  500,  447
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.758800, 0.878600);
	glVertex3f(-0.217700, 1.354600, 0.023900);
	 
	glEnd();

//	680.  477,  456,  459
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(-0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	681.  459,  478,  477
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.937200, 0.566600);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.904000, 0.557000);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.902200, 0.595600); 
	glVertex3f(-0.517600, 1.119300, 0.013500);
	 
	glEnd();

//	682.  462,  503,  491
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.346800, 0.424600);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.281400, 0.400300);
	glVertex3f(-0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	 
	glEnd();

//	683.  491,  463,  462
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(-0.592900, 0.982600, 0.035200);
	glTexCoord2f(0.346800, 0.424600);	 
	glVertex3f(-0.580300, 0.969800, 0.031700);
 
	glEnd();

//	684.  504,  492,  491
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.220700, 0.447900);
	glVertex3f(-0.601400, 0.923800, 0.114400);
	glTexCoord2f(0.238100, 0.454800);
	glVertex3f(-0.611300, 0.929000, 0.117900);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	 
	glEnd();

///	685.  491,  505,  504
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.271900, 0.414600);
	glVertex3f(-0.610200, 0.918700, 0.069400);
	glTexCoord2f(0.257500, 0.409400);
	glVertex3f(-0.596000, 0.918700, 0.056900);
	glTexCoord2f(0.220700, 0.447900);
	glVertex3f(-0.601400, 0.923800, 0.114400);
	 
	glEnd();

//	686.  453,  452,  496
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	glTexCoord2f(0.747300, 0.766900);
	glVertex3f(-0.580300, 0.969800, 0.031700);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	 
	glEnd();

//	687.  496,  474,  453
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.761500, 0.690700);
	glVertex3f(-0.515500, 1.065800, 0.023000);
	glTexCoord2f(0.698400, 0.712500);
	glVertex3f(-0.540200, 1.008300, 0.099600);
	glTexCoord2f(0.695300, 0.755500);
	glVertex3f(-0.583000, 0.983300, 0.119600);
	 
	glEnd();

//	688.  480,  476,  499
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.854900, 0.588900);
	glVertex3f(-0.506700, 1.125700, 0.062500);
	glTexCoord2f(0.816400, 0.578100); 
	glVertex3f(-0.477300, 1.095400, 0.042900);
	 
	glEnd();

//	689.  499,  506,  480
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.816400, 0.578100);
	glVertex3f(-0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	 
	glEnd();

//	690.  507,  508,  488
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(-0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	 
	glEnd();

	//	691.  488,  490,  507
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.995600, 0.760600);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.993500, 0.606700); 
	glVertex3f(-0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	692.  488,  508,  481
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(-0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	693.  481,  485,  488
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(-0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.945500, 0.770100);
	glVertex3f(-0.341800, 1.225400, -0.072700);
	
	glEnd();

//	694.  481,  508,  456
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(-0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	 
	glEnd();

//	695.  456,  477,  481
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.902200, 0.595600);
	glVertex3f(-0.517600, 1.119300, 0.013500);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	696.  507,  457,  456
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.974800, 0.588000);
	glVertex3f(-0.477300, 1.095400, 0.042900);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	 
	glEnd();

//	697.  456,  508,  507
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.942500, 0.595700);
	glVertex3f(-0.490600, 1.088100, 0.007500);
	glTexCoord2f(0.948900, 0.613700);
	glVertex3f(-0.472300, 1.086500, -0.012900);
	glTexCoord2f(0.993500, 0.606700);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	698.  481,  480,  509
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	 
	glEnd();

//	699.  509,  485,  481
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(-0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.905000, 0.612800);
	glVertex3f(-0.522000, 1.135100, -0.010600);
	 
	glEnd();

//	700.  510,  480,  506
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(-0.373500, 1.233700, 0.035600);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	 
	glEnd();

//	701.  506,  511,  510
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.795800, 0.591500);
	glVertex3f(-0.452500, 1.092600, 0.047800);
	glTexCoord2f(0.758900, 0.735100);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(-0.373500, 1.233700, 0.035600);
	 
	glEnd();

//	702.  437,  436,  438
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.628700, 0.616200);
	glVertex3f(-0.119200, 0.295400, 0.030000);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(-0.088900, 0.106000, 0.005700);
	
	glEnd();

//	703.  419,  418,  427
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(-0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.736700, 0.557700);
	glVertex3f(-0.130600, 0.095700, -0.095000);
	glTexCoord2f(0.760800, 0.519000);
	glVertex3f(-0.135800, 0.000300, -0.099100);
	
	glEnd();

//	704.  419,  430,  436
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.705600, 0.532300);
	glVertex3f(-0.148000, 0.084500, -0.031200);
	glTexCoord2f(0.686600, 0.491700);
	glVertex3f(-0.143300, 0.064300, 0.048800);
	glTexCoord2f(0.671700, 0.528900);
	glVertex3f(-0.118200, 0.111100, 0.006800);
	 
	glEnd();

//	705.  425,  426,  422
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.790300, 0.587600);
	glVertex3f(-0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.784000, 0.527400);
	glVertex3f(-0.080700, 0.000300, -0.097600);
	glTexCoord2f(0.759600, 0.570700);
	glVertex3f(-0.087800, 0.097800, -0.089200);
	 
	glEnd();

//	706.  416,  415,  438
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.651900, 0.486400);
	glVertex3f(-0.087600, 0.065200, 0.060000);
	glTexCoord2f(0.631500, 0.524900);
	glVertex3f(-0.070300, 0.104400, -0.024700);
	glTexCoord2f(0.652500, 0.521600);
	glVertex3f(-0.088900, 0.106000, 0.005700);
	 
	glEnd();

//	707.  511,  500,  510
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.758900, 0.735100);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(-0.373500, 1.233700, 0.035600);
	 
	glEnd();

//	708.  502,  509,  500
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	 
	glEnd();

//	709.  483,  469,  464
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(-0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.350100, 0.508800); 
	glVertex3f(-0.532000, 1.040600, 0.119000);
	 
	glEnd();

//	710.  502,  486,  485
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.839700, 0.783900);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.889900, 0.809300);
	glVertex3f(-0.347400, 1.312300, -0.065600);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(-0.386300, 1.275700, -0.060500);
	 
	glEnd();

//	711.  501,  500,  511
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.751400, 0.771500);
	glVertex3f(-0.291500, 1.249900, -0.015500);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.326500, 1.214000, -0.008800);
	 
	glEnd();

//	712.  485,  509,  502
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.386300, 1.275700, -0.060500);
	glTexCoord2f(0.894300, 0.769600);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.365700, 1.308300, 0.001700);
	glTexCoord2f(0.839700, 0.783900);
	glEnd();

//	713.  469,  483,  460
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.401900, 0.491700);
	glVertex3f(-0.530000, 1.095600, 0.074900);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	
	glEnd();

//	714.  500,  509,  510
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.799000, 0.772200);
	glVertex3f(-0.332700, 1.273900, 0.022100);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(-0.373500, 1.233700, 0.035600);
	
	glEnd();

//	715.  493,  460,  463
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(-0.599200, 0.990000, 0.120300);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.327800, 0.434300);
	glVertex3f(-0.592900, 0.982600, 0.035200);
	
	glEnd();

//	716.  469,  460,  493
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.338400, 0.497200);
	glVertex3f(-0.559800, 1.034100, 0.115600);
	glTexCoord2f(0.410400, 0.463200);
	glVertex3f(-0.552400, 1.087700, 0.028100);
	glTexCoord2f(0.291800, 0.479400);
	glVertex3f(-0.599200, 0.990000, 0.120300);
	
	glEnd();

//	717.  480,  510,  509
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.850900, 0.600200);
	glVertex3f(-0.507300, 1.141900, 0.072900);
	glTexCoord2f(0.807400, 0.724300);
	glVertex3f(-0.373500, 1.233700, 0.035600);
	glTexCoord2f(0.844600, 0.742700);
	glVertex3f(-0.401600, 1.273600, 0.013100);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);


glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 'w':
case 'W':
zpos += 3.0;
glTranslatef(0.0, 0.0, 3.0);
break;
case 'd':
case 'D':
xpos += 3.0;
glTranslatef(3.0, 0.0, 0.0);
break;
case 's':
case 'S':
zpos += -3.0;
glTranslatef(0.0, 0.0, -3.0);
break;
case 'a':
case 'A':
xpos += -3.0;
glTranslatef(-3.0, 0.0, 0.0);
break;
case '5':
if (is_depth){
is_depth =0;
glDisable(GL_DEPTH_TEST);
} else{
is_depth=1;
glEnable(GL_DEPTH_TEST);
}
break;
}
tampil();
}

void idle()
{

if (!mouseDown)
{
xrot += 0.3f;
yrot += 0.4f;
}
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseDown = true;
xdiff = x - yrot;
ydiff = -y + xrot;
}
else
mouseDown = false;
}

void mouseMotion(int x, int y)
{

if (mouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;

glutPostRedisplay();

}
}

void ukuran(int lebar, int tinggi)
{
if (tinggi == 0) tinggi = 1;

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
glTranslatef(0.0, -5.0, -150.0);
glMatrixMode(GL_MODELVIEW);
}
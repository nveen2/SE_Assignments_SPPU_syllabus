#include "GL/glut.h"
#include "iostream"

struct Point{
  int x;
  int y;
};

class Shapes{
    public:
    void Line(Point p1, Point p2);

    void Circle(Point p, int r);
};

void Shapes::Line(Point p1, Point p2) {
    double dx=(p2.x-p1.x);
    double dy=(p2.y-p1.y);
    double np;
    double xInc,yInc;

    np=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));

    xInc=dx/np;
    yInc=dy/np;
    double x=p1.x, y=p1.y;
    
    glBegin(GL_POINTS);
      for(int k=0;k<=np;k++) {
        glVertex2d(int(x), int(y));
        x += xInc;
        y += yInc;
      }
    glEnd();
}

void Shapes::Circle(Point p, int r) {
    double f = 5/4-r;
    int x = 0, y = r;
    
    glBegin(GL_POINTS);
      do{
        glVertex2d(p.x+x, p.y+y);
        glVertex2d(p.x+x, p.y-y);
        glVertex2d(p.x-x, p.y+y);
        glVertex2d(p.x-x, p.y-y);
        glVertex2d(p.x+y, p.y+x);
        glVertex2d(p.x-y, p.y+x);
        glVertex2d(p.x+y, p.y-x);
        glVertex2d(p.x-y, p.y-x);
        
        if (f<0){
          f += 2*x + 3;
        }else {
          f += 2*(x-y) + 5;
          y --;
        }
        x++;
      }while(x<=y);
    glEnd();
}

class Pattern{
    public:
    void clear();
    void displayP1();
    void displayP2();
};
void Pattern::clear(){
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void Pattern::displayP1() {
	glClear(GL_COLOR_BUFFER_BIT);

	Point p[] = {
		{0, 200},
		{-173, -100},
		{173, -100},
		{0, 0},
		{0, 0}
	};
	int r[] = {100, 200};
	Shapes s;
	s.Circle(p[3], r[0]);
	s.Circle(p[4], r[1]);
	for(int i=0; i<3; i++) s.Line(p[i%3], p[(i+1)%3]);

	glutSwapBuffers();
}

void Pattern::displayP2() {
	glClear(GL_COLOR_BUFFER_BIT);

	Point p1[] = {
		{-100, 100},
		{-100, -100},
		{100, -100},
		{100, 100}
	};
	Point p2[] = {
		{0, 100},
		{-100, 0},
		{0, -100},
		{100, 0}
	};
	int r = 70;
	Point center = {0, 0};
	Shapes s;
	s.Circle(center, r);
	for(int i=0; i<4; i++) {
		s.Line(p1[i%4], p1[(i+1)%4]);
		s.Line(p2[i%4], p2[(i+1)%4]);
	}

	glutSwapBuffers();
}

int choice = 0;
double red = 0, g = 1, b = 1;

void init();
void display();
void keyboard(unsigned char key, int x, int y);
void changeColor(int i);
void menu(int i);
void createMenu();

int main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(500,500);
	glutCreateWindow("Pattern by Dheeraj");

	init();
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);
	createMenu();

	glutMainLoop();

	return 0;
}

void init() {
  glClearColor(	0.0, 0.0, 0.2, 0.5);
  glPointSize(2);
  glViewport(0 , 0 , glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT)); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-250, 250, -250, 250);
}

void keyboard(unsigned char key, int x, int y) {
  if (key == 27) exit (0);
  else if(key == 'c'||key == 'C') choice = 0;
  else if(key == 'r'||key == 'R') {b = g = 0; red = 1;}
  else if(key == 'b'||key == 'B') {b = 1; g = red = 0;}
  else if(key == 'g'||key == 'G') {red = b = 0; g = 1;}
  glutPostRedisplay();
}

void display() {
	Pattern p;
	glColor3d(red,g,b);
	switch(choice){
		case 0: p.clear(); break;
		case 1: p.displayP1(); break;
		case 2: p.displayP2(); break;
	}
}

void menu(int i) {
  if(i == 4) exit(0);
  choice = i;
  glutPostRedisplay();
}

void changeColor(int i){
  switch (i){
    case 1: red = g = b = 1; break;
    case 2: red = 1; g = b = 0; break;
    case 3: g = 1; red = b = 0; break;
	case 4: g = 1; red = 0; b = 1; break;
  }
  glutPostRedisplay();
}

void createMenu() {  
	int s_id = glutCreateMenu(changeColor);
		glutAddMenuEntry("White", 1); 
		glutAddMenuEntry("Red", 2); 
		glutAddMenuEntry("Green", 3);
		glutAddMenuEntry("Navy Blue", 4);
	int m_id = glutCreateMenu(menu);
		glutAddMenuEntry("Draw Pattern 1", 1);
		glutAddMenuEntry("Draw Pattern 2", 2);
		glutAddSubMenu("Change Color", s_id);
		glutAddMenuEntry("Clear", 0);
		glutAddMenuEntry("Exit", 4);     
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutPostRedisplay();
}
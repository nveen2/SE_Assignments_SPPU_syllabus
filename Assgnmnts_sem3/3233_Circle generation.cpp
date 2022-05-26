#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include<dos.h>
#include <GL/glut.h>

using namespace std;

double xc, yc, r;
int selection = 1;

class Circ{


  void Bresenham(void) {
      glClear(GL_COLOR_BUFFER_BIT);
    cout<<"Bresenham algo"<<endl;
      int x=0,y=r;
      float pk=(5.0/4.0)-r;
      plot(x,y);
      int k;

      while(x < y)
      {
        x = x + 1;
        if(pk < 0)
          pk = pk + 2*x+1;
        else
        {
          y = y - 1;
          pk = pk + 2*(x - y) + 1;
        }
        plot2(x,y);
  }
  glFlush();
  }



  void plot2(int x, int y)
{
  glBegin(GL_POINTS);
  glColor3f(0.56,0.0,6.0);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}


  void DDA(void) {
    cout<<"DDA algo"<<endl;
    float x1,x2,y1,y2,e,sx,sy;

      int p,i;
      x1=r;
      y1=0;
      sx=x1;
      sy=y1;
      i=0;

      do{
          p=pow(2,i);
          i++;
          }while(p<r);
      e = 1/pow(2,i-1);
      do{
          x2 = x1 + y1*e;
          y2 = y1 - e*x2;
          plot3(x2,y2);
          x1=x2;
          y1=y2;
         }while((y1-sy)<e || (sx-x1)>e);
  }
void MIDpoint(void) {

    cout<<"Mid Point algo"<<endl;
    int x = 0;
	int y = r;
	float result = 5/4 - r;
	plot(x, y);
	while (y > x){
		if (result < 0)
		{
			x++;
			result += 2*x+1;
		}
		else
		{
			y--;
			x++;
			result += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
  }

 void plot(int x, int y)
  {
	glBegin(GL_POINTS);
	glColor3f(8.56,0.8,2.0);
	glVertex2i(xc+x, yc-y);
	glEnd();
  }

  void plot3(int x, int y)
  {
	glBegin(GL_POINTS);
	glColor3f(3.56,0.0,2.0);
	glVertex2i(x+xc, y+yc);
	glEnd();
  }
  void change(){
    cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> xc;
	cout << "\nY-coordinate : "; cin >> yc;
	cout << "\nEnter radius : "; cin >> r;
    selection = 1;
  }

  public:
  static void show(){
    Circ l;
    switch(selection){
      case 0: l.change(); Circ::show(); break;
      case 1: l.MIDpoint(); break;
      case 2: l.Bresenham(); break;
      case 3: l.DDA(); break;
      default: l.MIDpoint(); break;
    }
  }
};

void keyboard (unsigned char key, int x, int y);
void CircleGeneration(int i);
void Init();
void createMenu();

int main(int argc, char **argv){
    cout << "Enter the coordinates of the center:\n\n" << endl;

    cout << "X-coordinate   : "; cin >> xc;
	cout << "\nY-coordinate : "; cin >> yc;
	cout << "\nEnter radius : "; cin >> r;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Circle Generation Assignment");

  // Display
  Init();
  glutDisplayFunc(Circ::show);
  // Keyboard
  glutKeyboardFunc(keyboard);
  // Menu
  createMenu();
  glutMainLoop();
  return 0;
}

void Init() {
    glClearColor(1.0, 5.0, 0.0, 0.0);
	glColor3f(0.0f, 3.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void Circ_gen(int i) {
  if(i==4) exit(0);
  selection = i;
}

void keyboard (unsigned char key, int x, int y) {
  if (key == 27) exit (0);
  else if(key == 'm'||key == 'M') selection = 1;
  else if(key == 'b'||key == 'B') selection = 2;
  else if(key == 'd'||key == 'D') selection = 3;
  else if(key == 'c'||key == 'C') selection = 0;
  else{
    cout<<"\n\t You have pressed:"<< key<<endl;
    cout <<x<< "\t" <<y;
  }
}

void createMenu() {
  int s_id = glutCreateMenu(Circ_gen);
    glutAddMenuEntry("Mid-Point Algorithm", 1);
    glutAddMenuEntry("Bresenham Algorithm", 2);
    glutAddMenuEntry("DDA Algorithm", 3);
  int m_id = glutCreateMenu(Circ_gen);
    glutAddSubMenu("Algorithm", s_id);
    glutAddMenuEntry("Change Coordinates", 0);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

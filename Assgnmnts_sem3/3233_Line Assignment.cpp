#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

double X1, Y1, X2, Y2;
int selection = 1;

class Line{
  void LineDDA(void) {
    cout<<"DDA"<<endl;
    glClear(GL_COLOR_BUFFER_BIT);
    double dx=(X2-X1);
    double dy=(Y2-Y1);
    double np;
    double xInc,yInc;

    np=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));

    xInc=dx/np;
    yInc=dy/np;
    double x=X1,y=Y1;
    
    glBegin(GL_POINTS);
      for(int k=0;k<=np;k++) {
        glColor3f(0.56,0.0,0.0);
        glVertex2i(int(x), int(y));
        x += xInc;
        y += yInc;
      }
    glEnd();

    glutPostRedisplay();
    glFlush();
  }

  void Bresenham(void) {
    cout<<"Bresenham"<<endl;
    glClear(GL_COLOR_BUFFER_BIT);
    const int dx = (X2-X1);
    const int dy = (Y2-Y1);
    int x=X1,y=Y1;
    int pk = 2*dy - dx;;
    
    glBegin(GL_POINTS);
      for(int k=0;k<=dx;k++) {
        glColor3f(0.0,0.5,0.0);
        glVertex2i(x, y);
        if(pk < 0){
          pk += 2*dy;
          x += 1;
        }else{
          pk += 2*dy - 2*dx;
          x += 1;
          y += 1;
        }
      }
    glEnd();

    glutPostRedisplay();
    glFlush();
  }

  void plotLow(int X1, int X2, int Y1, int Y2) {
    int dx = X2 - X1;
    int dy = Y2 - Y1;

    int sy = 1;
    if (dy < 0) {
      sy = -1;
      dy *= -1;
    }

    int pk = 2 * dy - dx;

    int y = Y1;
    int x = X1;
    glBegin(GL_POINTS);
      for(int k=0;k<=dx;k++) {
        glColor3f(0.5,0.5,0.0);
        glVertex2i(x, y);
        if (pk > 0) {
          y += sy;
          pk -= 2 * dx;
        }
        pk += 2 * dy;
        x++;
      }
    glEnd();
  }
  void plotHigh(int X1, int X2, int Y1, int Y2) {
    int dx = X2 - X1;
    int dy = Y2 - Y1;

    int sx = 1;
    if (dx < 0) {
      sx = -1;
      dx *= -1;
    }

    int pk = 2 * dx - dy;

    int x = X1;
    int y = Y1;
    glBegin(GL_POINTS);
      for(int k=0;k<=dy;k++) {
        glColor3f(0.5,0.5,0.0);
        glVertex2i(x, y);
        if (pk > 0) {
          x += sx;
          pk -= 2 * dy;
        }
        pk += 2 * dx;
        y++;
      }
    glEnd();
  }
  void ModifiedBresenham(void) {
    cout<<"Modified Bresenham"<<endl;
    glClear(GL_COLOR_BUFFER_BIT);
    int dx = abs(X2 - X1);
	  int dy = abs(Y2 - Y1);
    Line l;
    if (dy < dx) {
      if (X1 > X2) l.plotLow(X2, X1, Y2, Y1);
      else l.plotLow(X1, X2, Y1, Y2);
    } else {
      if (Y1 > Y2) l.plotHigh(X2, X1, Y2, Y1);
      else l.plotHigh(X1, X2, Y1, Y2);
    }
    glutPostRedisplay();
    glFlush();
  }
  
  void change(){
    cout<<"Enter the First co-ordinates \n";
    cin>>X1>>Y1;
    cout<<"Enter the Second co-ordinates \n";
    cin>>X2>>Y2;  
    selection = 1;
  }
  
  public:
  static void display(){
    Line l;
    switch(selection){
      case 0: l.change(); Line::display(); break;
      case 1: l.LineDDA(); break;
      case 2: l.Bresenham(); break;
      case 3: l.ModifiedBresenham(); break;
      default: l.LineDDA(); break;
    }
  }
};

void keyboard (unsigned char key, int x, int y);
void lineGeneration(int i);
void Init();
void createMenu();

int main(int argc, char **argv){
  cout<<"Enter the First co-ordinates \n";
  cin>>X1>>Y1;
  cout<<"Enter the Second co-ordinates \n";
  cin>>X2>>Y2;
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("3203 Line Generation");

  // Display
  Init();
  glutDisplayFunc(Line::display);
  // Keyboard
  glutKeyboardFunc(keyboard);
  // Menu
  createMenu();
  glutMainLoop();
  return 0;
}

void Init() {
  glClearColor(	0.0, 0.0, 0.2, 0.0);
  glViewport(0 , 0 , 640 , 480); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-500, 500, -500, 500, -1, 1);
}

void lineGeneration(int i) {
  if(i==4) exit(0);
  selection = i;
}

void keyboard (unsigned char key, int x, int y) {
  if (key == 27) exit (0);
  else if(key == 'd'||key == 'D') selection = 1;
  else if(key == 'b'||key == 'B') selection = 2;
  else if(key == 'm'||key == 'M') selection = 3;
  else if(key == 'c'||key == 'C') selection = 0;
  else{
    cout<<"\n\t You have pressed:"<< key<<endl;
    cout <<x<< "\t" <<y;
  }
}

void createMenu() {
  int s_id = glutCreateMenu(lineGeneration);
    glutAddMenuEntry("DDA Algorithm", 1); 
    glutAddMenuEntry("Bresenham Algorithm", 2); 
    glutAddMenuEntry("Modified Bresenham Algorithm", 3);     
  int m_id = glutCreateMenu(lineGeneration);
    glutAddSubMenu("Algorithm", s_id);
    glutAddMenuEntry("Change Coordinates", 0);
    glutAddMenuEntry("Exit", 4);     
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
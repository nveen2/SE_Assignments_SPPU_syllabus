#include <GL/glut.h>
#include <bits/stdc++.h>
#include <windows.h>


using namespace std;

int selection = 0;

class Pattern
{
  void LineDDA(int X1, int Y1, int X2, int Y2)
  {
    double dx = (X2 - X1);
    double dy = (Y2 - Y1);
    double np;
    double xInc, yInc;

    np = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));

    xInc = dx / np;
    yInc = dy / np;
    double x = X1, y = Y1;

    glBegin(GL_POINTS);
    for (int k = 0; k <= np; k++)
    {
      glVertex2i(int(x), int(y));
      x += xInc;
      y += yInc;
    }
    glEnd();

    glutPostRedisplay();
    glFlush();
  }

  void Breshnam(int X1, int Y1, int r)
  {
    int d = 3 - 2 * r;
    int x = 0, y = r;

    glBegin(GL_POINTS);
    do
    {
      glVertex2d(int(X1) + x, int(Y1) + y);
      glVertex2d(int(X1) + x, int(Y1) - y);
      glVertex2d(int(X1) - x, int(Y1) + y);
      glVertex2d(int(X1) - x, int(Y1) - y);
      glVertex2d(int(X1) + y, int(Y1) + x);
      glVertex2d(int(X1) - y, int(Y1) + x);
      glVertex2d(int(X1) + y, int(Y1) - x);
      glVertex2d(int(X1) - y, int(Y1) - x);

      if (d < 0)
      {
        d += 4 * x + 6;
      }
      else
      {
        d += 4 * (x - y) + 10;
        y--;
      }
      x++;
    } while (x < y);
    glEnd();

    glutPostRedisplay();
    glFlush();
  }

  void clear(void)
  {
    glClearColor(0.7, 0.3, 0.2, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2, 0.9, 0.7);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();
    glutPostRedisplay();
    glFlush();
  }

  void First_Pattern()
  {
    glColor3f(0.1, 0.7, 0.8);
    //Triangle
    Pattern::LineDDA(100, 136, 300, 136);
    Pattern::LineDDA(100, 136, 200, 309);
    Pattern::LineDDA(200, 309, 300, 136);
    //Inner Circle
    Pattern::Breshnam(200, 193, 57);
    //Outer Circle
    Pattern::Breshnam(200, 193, 116);
  }

  void Seconed_Pattern()
  {
    glColor3f(0.0, 0.9, 0.6);
    //Circle
    Pattern::Breshnam(200, 200, 70);
    //Square
    Pattern::LineDDA(100, 100, 300, 100);
    Pattern::LineDDA(300, 100, 300, 300);
    Pattern::LineDDA(300, 300, 100, 300);
    Pattern::LineDDA(100, 300, 100, 100);
    //Diamond
    Pattern::LineDDA(100, 200, 200, 100);
    Pattern::LineDDA(200, 300, 100, 200);
    Pattern::LineDDA(300, 200, 200, 300);
    Pattern::LineDDA(200, 100, 300, 200);
  }

public:
  static void Display()
  {
    Pattern p;
    switch (selection)
    {
    case 0:
      p.clear();
      break;
    case 1:
      p.First_Pattern();
      break;
    case 2:
      p.Seconed_Pattern();
      break;
    default:
      p.clear();
      break;
    }
  }
};

void MyInit();
void keyboard(unsigned char, int, int);
void PatternGeneration(int);
void createMenu();

int main(int c, char **v)
{
  glutInit(&c, v);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(900, 900);
  glutInitDisplayMode(GLUT_RGB);
  glutCreateWindow("3228 Pattern Generation");

  MyInit();
  glutDisplayFunc(Pattern::Display);

  glutKeyboardFunc(keyboard);

  createMenu();
  glutMainLoop();
}

void MyInit()
{
  glClearColor(0.8, 0.4, 0.4, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 400, 0, 400);
  glPointSize(2.0);
}

void patternGeneration(int i)
{
  if (i == 3)
    exit(0);
  selection = i;
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
  else if (key == 'a' || key == 'A')
    selection = 1;
  else if (key == 'b' || key == 'B')
    selection = 2;
  else if (key == 'c' || key == 'C')
    selection = 0;
  else
  {
    cout << "\n\t You have pressed:" << key << endl;
    cout << x << "\t" << y;
  }
}

void createMenu()
{
  int submenu = glutCreateMenu(patternGeneration);
  glutAddMenuEntry("Pattern 1", 1);
  glutAddMenuEntry("Pattern 2", 2);
  int menu = glutCreateMenu(patternGeneration);
  glutAddSubMenu("Pattern", submenu);
  glutAddMenuEntry("Clear", 0);
  glutAddMenuEntry("Exit", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
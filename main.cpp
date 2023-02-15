// OpenGL practice
// Place all initialization and related one-time parameter setting together preferably in functioninit().
// Geometric description of the picture that we want to draw (display) in user-defined function which will be referenced in GLUT function, glutDisplayFunc().
// main function will contain GLUT function for setting up the display window and getting the image screen.

// Important STEP: Compile the program using the following command: g++ main.cpp -lglut -lGLU -lGL

// TODO: Add another object inside that will follow the ball.
// TODO: Add a function that will detect the collision between the ball and the object.

#include <GL/glut.h>
#include <iostream>
#include <cmath>

float x = 0.0; // x-coordinate of the object
float y = 0.0; // y-coordinate of the object
               //
// Function to handle the special keyboard events, in this case, the arrow keys so that the triangle can be moved.
void specialKeyboard(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_LEFT: // Left arrow key
      x -= 0.1;
      break;
    case GLUT_KEY_RIGHT: // Right arrow key
      x += 0.1;
      break;
    case GLUT_KEY_UP: // Up arrow key
      y += 0.1;
      break;
    case GLUT_KEY_DOWN: // Down arrow key
      y -= 0.1;
      break;
  }
}

// Function to handle the keyboard events, in this case, the escape key so that the program can be terminated.
void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 27: // Escape key
      exit(0);
      break;
    case 'a': // 'a' key
      ::x -= 0.1;
      break;
    case 'd': // 'd' key 
      ::x += 0.1;
      break;
    case 'w': // 'w' key 
      ::y += 0.1;
      break;
    case 's': // 's' key 
      ::y -= 0.1;
      break;
  }
  glutPostRedisplay(); // This line is used to call the display function again.
}

void detectCollision() {
  if(x > 0.9 || x < -0.9) {
    x = 0.0;
    y = 0.0;
  }
  if(y > 0.9 || y < -0.9) {
    x = 0.0;
    y = 0.0;
  }
}

// Program that will create a empty window
void init() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //This line is used to set the display mode. GLUT_SINGLE is used to set the single buffer and GLUT_RGB is used to set the RGB mode.
  glutInitWindowSize(1000, 1000); // This line is used to set the window size.
  glutInitWindowPosition(100, 100); //This line is used to set the window position.
  glutCreateWindow("OpenGL Practice"); // This line is used to set the window title.
  glutKeyboardFunc(keyboard); // This line is used to set the keyboard function.
  /* glutSpecialFunc(specialKeyboard); // This line is used to set the special keyboard function. */
}

void displayBall() {

  // Everything that is written in this function will be executed in a loop. More specifically the glutMainLoop() loop.

  // This ball will have only 10% of the size of the window.
  glClearColor(0.0, 0.0, 0.0, 0.0); // This line is used to set the background color.
  glClear(GL_COLOR_BUFFER_BIT); // This line is used to clear the screen.
  glLoadIdentity(); // This line is used to load the identity matrix.
  glTranslatef(x, y, 0.0); // This line is used to translate the ball.
  detectCollision(); // This line is used to detect the collision.
  glBegin(GL_POLYGON); // This line is used to draw the ball.
  glColor3f(1.0, 0.0, 0.0); // This line is used to set the color of the ball.
  for(int i = 0; i < 360; i++) {
    float angle = i * 3.1416 / 180;
    glVertex2f(cos(angle) * 0.1, sin(angle) * 0.1); // This line is used to set the vertex of the ball.
  }
  glEnd(); // This line is used to end the drawing of the ball.
  glFlush(); // This line is used to flush the buffer.
}

void display() {
  glClearColor(0.0, 0.0, 0.0, 0.0); // This line is used to set the background color.
  glClear(GL_COLOR_BUFFER_BIT); // This line is used to clear the screen.
  glFlush(); // This line is used to flush the buffer.
}

int main(int argc, char** argv) {
  glutInit(&argc, argv); // This line is used to initialize the GLUT library.
  init();  
  glutDisplayFunc(displayBall);
  detectCollision();
  glutMainLoop(); // This line is used to run the program.
  return 0;
}

#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>
#include <sstream>

void adnan() {
    //ceiling
    glBegin(GL_POLYGON);
    glColor3f(0.925f, 0.937f, 0.62f);
    glVertex2d(0, 1013);
    glVertex2d(1248, 878);
    glVertex2d(1920, 986);
    glVertex2d(1920, 1080);
    glVertex2d(0, 1080);
    glEnd();
    //floor
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.337f, 0.333f);
    glVertex2d(0, 0);
    glVertex2d(1920, 0);
    glVertex2d(1920, 364);
    glVertex2d(1248, 472);
    glVertex2d(0, 300);
    glEnd();
    //deal1
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.6f, 0.451f);
    glVertex2d(0, 1013);
    glVertex2d(1248, 878);
    glVertex2d(1248, 472);
    glVertex2d(0, 300);
    glEnd();
    //deal2
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.82f, 0.478f);
    glVertex2d(1920, 364);
    glVertex2d(1248, 472);
    glVertex2d(1248, 878);
    glVertex2d(1920, 986);
    glEnd();

    //windo-sky
    glBegin(GL_POLYGON);
    glColor3f(0.62f, 0.863f, 0.961f);
    glVertex2d(1363, 726);
    glVertex2d(1550, 742);
    glVertex2d(1550, 540);
    glVertex2d(1363, 560);
    glEnd();

}

void drawCircle(float x, float y, float radius, float red, float green, float blue) {
    int segments = 100; // Higher value for a smoother circle
    float angle;
    x *= 19.2;
    y *= 13.5;
    glBegin(GL_POLYGON); // Keeps it as a line-based circle
    glColor3f(red, green, blue); // Set the color dynamically
    for (int i = 0; i < segments; i++) {
        angle = 2.0f * M_PI * i / segments; // Calculate the angle
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawNumber(float x, float y, int number) {
    // Set text color to black
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    x *= 19.2;
    y *= 13.5;

    std::stringstream ss;
    ss << number;
    std::string text = ss.str();

    glRasterPos2f(x, y);        // Set position for the text

    for (char c : text) {       // Render each character
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawClock(float x, float y, float radius) {
    x *= 19.2;
    y *= 13.5;
    // Get the current time
    time_t t;
    struct tm* localTime;
    time(&t);
    localTime = localtime(&t);

    // Calculate the angles for hour, minute, and second hands
    // Calculate the angle for the second hand (clockwise)
    float secondAngle = localTime->tm_sec * 6.0f; // Keep it positive for clockwise rotation
    float minuteAngle = localTime->tm_min * 6.0f + (localTime->tm_sec * 0.1f); // Minute hand with second hand adjustment
    float hourAngle = (localTime->tm_hour % 12) * 30.0f + (localTime->tm_min * 0.5f); // Hour hand with minute hand adjustment

    // Draw the clock hands at the specified position and radius
    glColor3f(0.0f, 0.0f, 0.0f); // Black for the hands

    // Hour hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f); // Translate to clock center
    glRotatef(hourAngle, 0.0f, 0.0f, 1.0f); // Rotate hour hand
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.5f); // Hour hand length
    glEnd();
    glPopMatrix();

    // Minute hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f); // Translate to clock center
    glRotatef(minuteAngle, 0.0f, 0.0f, 1.0f); // Rotate minute hand
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.75f); // Minute hand length
    glEnd();
    glPopMatrix();

    // Draw the second hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(360.0f - secondAngle, 0.0f, 0.0f, 1.0f); // Subtract secondAngle from 360 to make it clockwise
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius); // Length of the second hand
    glEnd();
    glPopMatrix();
}

void sadid() {
    float x = 19.2;
    float y = 13.5;
    //glColor3f(1.0f, 1.0f, 1.0f);

    //BED Top
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.969f, 0.957f);
    glVertex2d(x * 47, y * 30);
    glVertex2d(x * 65, y * 31);
    glVertex2d(x * 65, y * 45);
    glVertex2d(x * 47, y * 44);
    glEnd();

    //BED Top Left
    glBegin(GL_POLYGON);
    glColor3f(0.216f, 0.251f, 0.224f);
    glVertex2d(x * 46, y * 31);
    glVertex2d(x * 47, y * 30);
    glVertex2d(x * 47, y * 44);
    glVertex2d(x * 46, y * 45);
    glEnd();

    //BED Top Top
    glBegin(GL_POLYGON);
    glColor3f(0.216f, 0.251f, 0.224f);
    glVertex2d(x * 47, y * 44);
    glVertex2d(x * 65, y * 45);
    glVertex2d(x * 64, y * 46);
    glVertex2d(x * 46, y * 45);
    glEnd();

    //BED left TOP
    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 65, y * 28);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 47, y * 35);
    glVertex2d(x * 47, y * 33);
    glEnd();

    //BED left Buttom
    glBegin(GL_POLYGON);
    glColor3f(0.784f, 0.784f, 0.784f);
    glVertex2d(x * 65, y * 24);
    glVertex2d(x * 65, y * 28);
    glVertex2d(x * 47, y * 33);
    glVertex2d(x * 47, y * 30);
    glEnd();

    //BED sheet left
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 64, y * 27);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 55, y * 32.8);
    glVertex2d(x * 54, y * 30);
    glEnd();

    //BED sheet left
    glBegin(GL_LINES);
    glColor3f(0.649f, 0.720f, 0.514f);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 55, y * 32.8);
    glEnd();

    //BED sheet top
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 79, y * 35);
    glVertex2d(x * 73, y * 36);
    glVertex2d(x * 55, y * 32.8);
    glEnd();

    //BED sheed top
    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 55, y * 32.8);
    glVertex2d(x * 73, y * 36);
    glVertex2d(x * 65, y * 37);
    glVertex2d(x * 47, y * 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.827f, 0.824f);
    glVertex2d(x * 66, y * 24.01);
    glVertex2d(x * 85, y * 29);
    glVertex2d(x * 85, y * 35);
    glVertex2d(x * 66, y * 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.828f, 0.825f, 0.825f);
    glVertex2d(x * 65, y * 24.01);
    glVertex2d(x * 66, y * 24.01);
    glVertex2d(x * 66, y * 31);
    glVertex2d(x * 65, y * 32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.933f, 0.961f, 0.953f);
    glVertex2d(x * 66, y * 31);
    glVertex2d(x * 85, y * 35);
    glVertex2d(x * 84, y * 36);
    glVertex2d(x * 65, y * 32);
    glEnd();

    //pellow
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 57, y * 34);
    glVertex2d(x * 61, y * 35);
    glVertex2d(x * 60, y * 36);
    glVertex2d(x * 55, y * 35);
    glEnd();

    //Almery
    glBegin(GL_POLYGON);
    glColor3f(0.412f, 0.181f, 0.067f);
    glVertex2d(x * 86, y * 24);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 91, y * 48.5);
    glVertex2d(x * 86, y * 49);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.412f, 0.181f, 0.067f);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 91, y * 48.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 91, y * 48.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.408f, 0.212f, 0.137f);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 99, y * 23);
    glVertex2d(x * 99, y * 50);
    glVertex2d(x * 96, y * 48);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 96, y * 48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.408f, 0.212f, 0.137f);
    glVertex2d(x * 86, y * 49);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 99, y * 50);
    glVertex2d(x * 88, y * 51);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 99, y * 50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 86, y * 49);
    glEnd();
    //Almery

    //Table
    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 65, y * 6);
    glVertex2d(x * 84, y * 15);
    glVertex2d(x * 65, y * 21);
    glVertex2d(x * 47, y * 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 47, y * 13);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 65, y * 6);
    glVertex2d(x * 47, y * 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 84, y * 14);
    glVertex2d(x * 84, y * 15);
    glVertex2d(x * 65, y * 6);
    glEnd();

    //Table leg
    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 47, y * 10);
    glVertex2d(x * 48, y * 10);
    glVertex2d(x * 48, y * 12.5);
    glVertex2d(x * 47, y * 13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 64, y * 2);
    glVertex2d(x * 65, y * 1);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 64, y * 5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 65, y * 1);
    glVertex2d(x * 66, y * 2);
    glVertex2d(x * 66, y * 5.5);
    glVertex2d(x * 65, y * 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 83, y * 11);
    glVertex2d(x * 84, y * 11);
    glVertex2d(x * 84, y * 14);
    glVertex2d(x * 83, y * 13.5);
    glEnd();


    //Flower vase
    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.565f, 0.251f);
    glVertex2d(x * 64, y * 13);
    glVertex2d(x * 66, y * 13);
    glVertex2d(x * 67, y * 16);
    glVertex2d(x * 63, y * 16);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 65, y * 16);
    glVertex2d(x * 65, y * 19);
    glEnd();

    //flower
    glBegin(GL_POLYGON);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 64, y * 17);
    glVertex2d(x * 65, y * 17);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 64, y * 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.898f, 0.737f, 0.518f);
    glVertex2d(x * 65, y * 17);
    glVertex2d(x * 66, y * 17);
    glVertex2d(x * 66, y * 18);
    glVertex2d(x * 65, y * 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.898f, 0.737f, 0.518f);
    glVertex2d(x * 64, y * 18);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 65, y * 19);
    glVertex2d(x * 64, y * 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 66, y * 18);
    glVertex2d(x * 66, y * 19);
    glVertex2d(x * 65, y * 19);
    glEnd();







    /*glBegin(GL_POLYGON);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2d(x*, y*);
   glVertex2d(x*, y*);
   glVertex2d(x*, y*);
   glVertex2d(x*,y*);
   glEnd();*/

   //X, y , redious, color
    drawCircle(93.0f, 60.0f, 65.0f, 0.733f, 0.510f, 0.224f);
    drawCircle(93.0f, 60.0f, 50.0f, 1.0f, 1.0f, 1.0f);
    drawNumber(90.6f, 59.5f, 9);
    drawNumber(95.0f, 59.5f, 3);
    drawNumber(92.7f, 56.5f, 6);
    drawNumber(92.4f, 62.5f, 12);
    drawClock(93.0f, 60.0f, 45.0f);
    //Handel
    drawCircle(90.0f, 36.0f, 10.0f, 0.733f, 0.510f, 0.224f);
    drawCircle(92.0f, 35.8f, 10.0f, 0.733f, 0.510f, 0.224f);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    adnan();
    sadid();


    glFlush();
}

void update(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000, update, 0); // Call update every 1000 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Home interior Design");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
    return 0;
}

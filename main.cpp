#include <GL/glut.h>
#include <cmath>

float timeOfDay = 0.0; // Controls day-night transition
float carPosition = -1.0; // Car's initial position (start from left)

// Function to draw the car
void drawCar(float x, float y) {
    // Car body (rectangle) - White car body
    glColor3f(1.0, 1.0, 1.0); // White car body
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.3, y);
    glVertex2f(x + 0.3, y + 0.1);
    glVertex2f(x, y + 0.1);
    glEnd();

    // Car windows (smaller rectangle)
    glColor3f(0.8, 0.8, 0.8); // Gray windows
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.05, y + 0.05);
    glVertex2f(x + 0.25, y + 0.05);
    glVertex2f(x + 0.25, y + 0.1);
    glVertex2f(x + 0.05, y + 0.1);
    glEnd();

    // Car wheels (circles)
    glColor3f(0.0, 0.0, 0.0); // Black wheels
    for (float i = 0.05; i <= 0.25; i += 0.2) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j += 10) {
            float theta = j * 3.14159 / 180;
            glVertex2f(x + i + 0.05 * cos(theta), y - 0.05 + 0.05 * sin(theta));
        }
        glEnd();
    }

    // Draw "Ankhi" on the car body (in Navy Blue)
    glColor3f(0.0, 0.0, 0.5); // Navy Blue color for text
    glRasterPos2f(x + 0.1, y + 0.03); // Position of the text on the car body

    // Displaying the name "Ankhi"
    const char* name = "Ankhi";
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
    }
}

void drawHouse(float x, float y) {
    glColor3f(1.0, 0.5, 0.0); // Orange House
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.2, y);
    glVertex2f(x + 0.2, y + 0.2);
    glVertex2f(x, y + 0.2);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Roof
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.02, y + 0.2);
    glVertex2f(x + 0.22, y + 0.2);
    glVertex2f(x + 0.1, y + 0.3);
    glEnd();
}

void drawTree(float x, float y) {
    glColor3f(0.5, 0.3, 0.0); // Brown trunk
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.02, y);
    glVertex2f(x + 0.02, y + 0.1);
    glVertex2f(x, y + 0.1);
    glEnd();

    glColor3f(0.0, 1.0, 0.0); // Green Leaves
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.05, y + 0.1);
    glVertex2f(x + 0.07, y + 0.1);
    glVertex2f(x + 0.01, y + 0.2);
    glEnd();
}

void drawBangladeshiFlag(float x, float y) {
    // Flagpole
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.01, y - 0.3);
    glVertex2f(x + 0.01, y - 0.3);
    glVertex2f(x + 0.01, y + 0.2);
    glVertex2f(x - 0.01, y + 0.2);
    glEnd();

    // Green Background
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.3, y);
    glVertex2f(x + 0.3, y + 0.2);
    glVertex2f(x, y + 0.2);
    glEnd();

    // Red Circle
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159 / 180;
        glVertex2f(x + 0.15 + 0.05 * cos(theta), y + 0.1 + 0.05 * sin(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float skyR = 0.2 + 0.3 * cos(timeOfDay);
    float skyG = 0.3 + 0.5 * cos(timeOfDay);
    float skyB = 0.6 + 0.4 * cos(timeOfDay);

    // Background (Sky and Ground)
    glColor3f(skyR, skyG, skyB);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();

    // Sun/Moon
    float celestialY = 0.7 * fabs(cos(timeOfDay)); // Ensuring it stays in the sky
    if (cos(timeOfDay) > 0) {
        glColor3f(1.0, 1.0, 0.0); // Yellow Sun (Day)
    } else {
        glColor3f(1.0, 1.0, 1.0); // White Moon (Night)
    }
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float theta = i * 3.14159 / 180;
        glVertex2f(0.7 + 0.1 * cos(theta), celestialY + 0.1 * sin(theta));
    }
    glEnd();

    // Road
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.5);
    glVertex2f(1.0, -0.4);
    glVertex2f(-1.0, -0.4);
    glEnd();

    // Houses
    drawHouse(-0.6, -0.2);
    drawHouse(-0.2, -0.2);
    drawHouse(0.2, -0.2);
    drawHouse(0.6, -0.2);

    // Trees
    drawTree(-0.75, -0.2);
    drawTree(-0.35, -0.2);
    drawTree(0.05, -0.2);
    drawTree(0.45, -0.2);
    drawTree(0.85, -0.2);

    // Flag
    drawBangladeshiFlag(-0.9, 0.1);

    // Moving car
    drawCar(carPosition, -0.45);

    glFlush();
}

void update(int value) {
    // Update car's position to move it left to right
    carPosition += 0.01; // Move car by 0.01 units to the right

    // Reset car position if it goes off the screen
    if (carPosition > 1.0) {
        carPosition = -1.0; // Reset car position to the left
    }

    timeOfDay += 0.02;
    if (timeOfDay > 2 * 3.14159) {
        timeOfDay -= 2 * 3.14159;
    }
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Village Scene with Day & Night Cycle");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PARTICLES = 5;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 24;

class Particle {
public:
    int x, y;
    int velocityX, velocityY;

    Particle() {}
    Particle(int startX, int startY, int startVelocityX, int startVelocityY)
        : x(startX), y(startY), velocityX(startVelocityX), velocityY(startVelocityY) {}

    void update() {
        x += velocityX;
        y += velocityY;

        if (x < 0 || x >= SCREEN_WIDTH) {
            velocityX = -velocityX;
        }

        if (y < 0 || y >= SCREEN_HEIGHT) {
            velocityY = -velocityY;
        }
    }
};

void printParticles(const Particle particles[], int particleCount) {
    system("cls");

    for (int i = 0; i < particleCount; ++i) {
        cout << "Particle " << i + 1 << ": X=" << particles[i].x << ", Y=" << particles[i].y << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Particle particles[MAX_PARTICLES];
    int particleCount = 0;

    while (particleCount < MAX_PARTICLES) {
        particles[particleCount] = Particle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % 5 - 2, rand() % 5 - 2);
        particleCount++;
    }

    int k = 0;
    while (k < 15) {
        for (int i = 0; i < particleCount; ++i) {
            particles[i].update();
        }

        printParticles(particles, particleCount);
        k++;
    }

    return 0;
}
#ifndef PARTICLE_HANDLER_H
#define PARTICLE_HANDLER_H
#include <vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include "XandY.h"
#include "particle.h"
#include "actor.h"
#include <thread>
#include "particleWheel.h"

class ParticleHandler : public Actor {
private:

    struct thread_data {
        int start;
        int end;
    };

    const static int NPARTICLES = 3000;
    const static int GRAVITY_RADIUS = 10;
    const static int GRAVITY_RADIUS_SQUARED =
        GRAVITY_RADIUS * GRAVITY_RADIUS;
    const static int MAX_SPEED = 5;
    const static int FRAMES = 60 * 7;
    int WINDOW_W, WINDOW_H;
    static const int NTHREADS = 2;
    pthread_t threads[NTHREADS];

    typedef XandY Position;

    std::vector<Particle*> particles;
    std::vector<ParticleWheel*> wheels;
    SDL_Texture *bluePoint, *pinkPoint;
    SDL_Renderer* renderer;

    SDL_Texture* createTextureFromPath(std::string imagePath);
    void printParticle(Particle*);
    void moveParticles();
    void moveParticles(int, int);
    void onCouple(Particle*, Particle*);
    // void adjustParticleSpeed();
    //void *adjustParticleSpeed(void*);
    void adjustParticleSpeed(int start, int end);
    int getSquaredDistance(Particle*, Particle*);
    int getDistanceSum(Particle*, Particle*);
    void renderParticles();
    void renderParticles(int, int);
    void onInit();
    void onDraw();
    void onQuit();
public:
    ParticleHandler(SDL_Renderer*, int, int);
};



#endif

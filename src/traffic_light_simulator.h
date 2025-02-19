#ifndef TRAFFIC_LIGHT_SIMULATOR_H
#define TRAFFIC_LIGHT_SIMULATOR_H

#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common_types.h"
#include "vehicle.h"

// Add MIN macro
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ROAD_WIDTH 40
#define LIGHT_SIZE 20

// Traffic light states
typedef enum {
    RED,
    YELLOW,
    GREEN
} LightState;

// Traffic light structure
typedef struct {
    LightState state;
    int timer;
    Direction direction;
    bool isPriority;
    int waitingVehicles;
    SDL_Rect position;
} TrafficLight;

// Lane queue structure
typedef struct {
    int vehicleCount;
    struct Vehicle* front;
    struct Vehicle* rear;
    Direction direction;
} LaneQueue;

// Function declarations
void init_lane_queues(LaneQueue* queues);
void update_traffic_lights(TrafficLight* lights);
void update_vehicles(LaneQueue* queues, TrafficLight* lights);
void handle_priority_signals(TrafficLight* lights);
void render_vehicles(SDL_Renderer* renderer, LaneQueue* queues);
void cleanup_simulator(SDL_Window* window, SDL_Renderer* renderer);

#endif
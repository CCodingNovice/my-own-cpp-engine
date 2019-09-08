#include "Animation.hpp"
#include <SDL.h>

Animation::~Animation() {
    sheet_positions.clear();
}

Animation::Animation() {
    duration = 0;
    frames = 0;
    curentFrame = 0;
}

void Animation::setDuration(unsigned int d) {
    duration = d;
}

void Animation::setFrames(unsigned int f) {
    frames = f;
}

void Animation::setSheetPositions(std::vector<my_engine::vector2i> positions) {
    sheet_positions = positions;
}

Animation::Animation(my_engine::vector2i fs, unsigned int f, unsigned int d, std::vector<my_engine::vector2i> positions) {
    curentFrame = 0;
    duration = d;
    frames = f;
    frameSize = fs;
    sheet_positions = positions;
}

SDL_Rect Animation::getCurrentRect(Uint32 deltaTicks) {
    if(frames != 0) {
        if (duration / frames < (size_t)deltaTicks) {
            curentFrame++;
        }
    }
    if(curentFrame >= frames){
        curentFrame = 0;
    }
    return (SDL_Rect){sheet_positions[curentFrame].x, sheet_positions[curentFrame].y, frameSize.x, frameSize.y};
}

void Animation::startAnimation(unsigned int ticks) {
    startTicks = ticks;
}

void Animation::setStartTick(unsigned int tick) {
    startTicks = tick;
}

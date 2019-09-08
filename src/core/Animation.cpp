#include "Animation.hpp"
#include <SDL.h>
#include <cmath>

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

SDL_Rect Animation::getCurrentRect(Uint32 ticks) {
    if(ticks - startTicks <= duration) {
        auto index = (int) round((float) (ticks - startTicks) / duration * 4);
        if(index >= frames)
            index--;
        return (SDL_Rect) {sheet_positions[index].x, sheet_positions[index].y, frameSize.x, frameSize.y};
    }
    return (SDL_Rect) {sheet_positions[frames - 1].x, sheet_positions[frames - 1].y, frameSize.x, frameSize.y};
}

void Animation::startAnimation(unsigned int ticks) {
    startTicks = ticks;
}

void Animation::setStartTick(unsigned int tick) {
    startTicks = tick;
    curentFrame = 0;
}

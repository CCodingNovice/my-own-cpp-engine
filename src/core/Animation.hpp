#ifndef ENGINE_ANIMATION_HPP
#define ENGINE_ANIMATION_HPP

#include "vector.hpp"
#include <SDL.h>
#include <vector>

class Animation{
public:
    Animation();
    Animation(my_engine::vector2i fs, unsigned int f, unsigned int d, std::vector<my_engine::vector2i> positions);
    ~Animation();
    void setDuration(unsigned int d);
    void setFrames(unsigned int f);
    void setSheetPositions(std::vector<my_engine::vector2i> positions);
    void startAnimation(unsigned int ticks);
    SDL_Rect getCurrentRect(Uint32 deltaTicks);
    void setStartTick(unsigned int tick);

private:
    unsigned int duration;
    unsigned int frames;
    std::vector<my_engine::vector2i> sheet_positions;
    my_engine::vector2i frameSize;
    int curentFrame;
    unsigned int startTicks;
};

#endif //ENGINE_ANIMATION_HPP

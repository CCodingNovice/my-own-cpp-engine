#ifndef ENGINE_ANIMATION_HPP
#define ENGINE_ANIMATION_HPP

#include "vector.hpp"
#include <vector>

class Animation{
public:
    Animation();
    Animation(unsigned int f, unsigned int d, std::vector<my_engine::vector2i> positions);
    ~Animation();
    void setDuration(unsigned int d);
    void setFrames(unsigned int f);
    void setSheetPositions(std::vector<my_engine::vector2i> positions);
private:
    unsigned int duration;
    unsigned int frames;
    my_engine::vector2i *sheet_positions;
};

#endif //ENGINE_ANIMATION_HPP

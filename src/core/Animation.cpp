#include "Animation.hpp"

Animation::~Animation() {
    delete []sheet_positions;
}

Animation::Animation() {
    duration = 0;
    frames = 0;
}

void Animation::setDuration(unsigned int d) {
    duration = d;
}

void Animation::setFrames(unsigned int f) {
    frames = f;
}

void Animation::setSheetPositions(std::vector<my_engine::vector2i> positions) {
    sheet_positions = new my_engine::vector2i[positions.size()];
    for(auto &pos : positions){
        *sheet_positions = pos;
        *sheet_positions++;
    }
}

Animation::Animation(unsigned int f, unsigned int d, std::vector<my_engine::vector2i> positions) {
    duration = d;
    frames = f;
    sheet_positions = new my_engine::vector2i[positions.size()];
    for(auto &pos : positions){
        *sheet_positions = pos;
        *sheet_positions++;
    }
}

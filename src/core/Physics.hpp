#ifndef ENGINE_PHYSICS_HPP
#define ENGINE_PHYSICS_HPP

#include <vector>
#include "RigidBody.hpp"
#include "Player.hpp"

namespace my_engine {
    class Physics {
    public:
        explicit Physics(vector2i vel);
        bool collision(Player rb1, RigidBody rb2, int sign, char c);
        void moveRight(Player &rigidBody, std::vector<RigidBody> objects);
        void moveLeft(Player &rigidBody, std::vector<RigidBody> objects);
        void moveUp(Player &rigidBody, std::vector<RigidBody> objects);
        void moveDown(Player &rigidBody, std::vector<RigidBody> objects);
        void setVelocity(vector2i vel);
        bool onGround(Player rigidBody, std::vector<RigidBody> objects);
        int get_x_velocity();
        int get_y_velocity();

    private:
        vector2i velocity;
    };

}

#endif //ENGINE_PHYSICS_HPP

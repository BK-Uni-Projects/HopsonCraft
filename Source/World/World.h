#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include <memory>
#include <thread>
#include <mutex>

#include <SFML/System/Clock.hpp>

#include "../Physics/AABB.h"

class Player;
class Camera;
class MasterRenderer;
class StatePlaying;

class World
{
    public:
        World(const Camera& camera);

    private:
        const Camera* m_pCamera = nullptr;
};

#endif // WORLD_H_INCLUDED

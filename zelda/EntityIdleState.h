#ifndef ENTITYIDLESTATE_H
#define ENTITYIDLESTATE_H
#include "Collision.h"
#include "Room.h"
#include "PlayScreen.h"
class EntityIdleState:public Collision
{
    public:
        EntityIdleState();
        virtual ~EntityIdleState();
        void Update(Entity &entity,ENTITYSTATE &currentState,PlayScreen&mPlayScreen);
        int waitDuration=0;
        int waitTimer=0;
};

#endif // ENTITYIDLESTATE_H

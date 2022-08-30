#ifndef ENTITYWALKSTATE_H
#define ENTITYWALKSTATE_H
#include "Room.h"
#include "Player.h"
#include "Collision.h"
#include "Animation.h"
#include "Entity.h"
#include "PlayScreen.h"
class EntityWalkState:public Collision
{
    public:
        EntityWalkState();
        virtual ~EntityWalkState();
void Update(Entity &entity,ENTITYSTATE &currentState,Player & p,Animation&mAnimation,PlayScreen&mPlayScreen);
void processAI(Entity &entity,PlayScreen&mPlayScreen);
void if_bumped(Entity &entity,PlayScreen&mPlayScreen);
void set_duration(Entity &entity);
bool entity_colide(Entity &entity,Entity *(&entitys)[10]);
bool entity_colide_rect(Entity &entity,Entity *(&entitys)[10]);
bool player_entity_colide(Player * player,Entity *(&entitys)[10]);
};

#endif // ENTITYWALKSTATE_H

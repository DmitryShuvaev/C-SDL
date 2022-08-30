#ifndef PLAYERSWINGSWORDSTATE_H
#define PLAYERSWINGSWORDSTATE_H
#include "Room.h"
#include "Player.h"
#include "Collision.h"
#include "Animation.h"
#include "Timer.h"
#include "PlayScreen.h"
#include "Entity.h"
#include "AudioManager.h"
class PlayerSwingSwordState:public Collision
{
    public:
        PlayerSwingSwordState();
        virtual ~PlayerSwingSwordState();
        void init_hitbox(Player & player,Animation&mAnimation);
        void Update(SCREENS &mCurrentScreen,Player &p,Animation&mAnimation,PlayScreen *ps);
        void SwordLeftAnim(Player & mcharacter,Animation&mAnimation);
        void SwordRightAnim(Player & mcharacter);
        void SwordTopAnim(Player & mcharacter);
        void SwordDownAnim(Player & mcharacter);
        void Go_toIdle(SCREENS &mCurrentScreen,Animation&mAnimation,Player & p);
        void Reset();
        void Render();

        float mAnimationTimer=0.2f;
        float time_dev=0.08f;
        int count=0;
        bool active=false;
        bool anim_start=true;
        Timer* mTimer;
        //Timer* mgemTimeanim;
        //float mgemAnimationTimer=0.0f;
        InputManager*mInput;
        AudioManager* mAudioMgr;
};

#endif // PLAYERSWINGSWORDSTATE_H

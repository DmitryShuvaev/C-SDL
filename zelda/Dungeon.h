#ifndef DUNGEON_H
#define DUNGEON_H
#include "Room.h"
#include "Player.h"
#include "Collision.h"
#include "Animation.h"
//#include "PlayScreen.h"
class Dungeon:public Collision
{
    public:
        Dungeon();
        void init();
        void Render();
        void Update(SCREENS &mCurrentScreen,Player & p,Animation&mAnimation);
        void beginShifting(SCREENS &mCurrentScreen,Player & p,Animation*mAnimation);
        void shift_player(Player * p,int dy);
        void shift_player_x(Player * player,int dx);
        void shift_pos(SCREENS &mCurrentScreen,Player & p,Animation*mAnimation);
        void move_player_up(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation);
        void move_player_down(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation);
        void move_player_left(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation);
        void move_player_right(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation);
        virtual ~Dungeon();

        Room *currentRoom;
        Room *nextRoom;
         int y=0;
         bool active_shifting=false;
         int shiftvalue=2;
         bool start_shifting=false;
DIRECTIONS dir;
};

#endif // DUNGEON_H

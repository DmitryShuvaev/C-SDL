#ifndef TUBE_H
#define TUBE_H
#include "Texture.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class Tube
{
    public:
        Tube();
        virtual ~Tube();
        void Update();
        void Render();
        float PIPE_SCROLL = -1;
        float dx=0;
        float ic=2.5;
        float GAP_HEIGHT = 200;
        Texture*upper;
        Texture*lower;
        int x=0;
        int PIPE_WIDTH;
    //whether or not this pair of pipes has been scored
        bool scored = false;
    private:
};

#endif // TUBE_H

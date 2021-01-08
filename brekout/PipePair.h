#ifndef PIPEPAIR_H
#define PIPEPAIR_H
#include "Tube.h"

class PipePair
{
    public:
        PipePair();
        virtual ~PipePair();
        void Update();
        void Render();
//size of the gap between pipes
float GAP_HEIGHT = 90;
Tube*upper;
Tube*lower;

    private:
};

#endif // PIPEPAIR_H

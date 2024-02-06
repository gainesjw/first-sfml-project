#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cstdlib>
#include <ctime>

namespace Random 
{
    inline void rand_init()
    {
        srand(time(NULL));
    };

    inline float random(float min, float max)
    {
        return (rand() /float(RAND_MAX)) * (max - min) + min;
    }

    inline int random(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }
}

#endif
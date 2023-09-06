// Givent wo crystal balls that will break if dropped from high enoigh
// distance, determine the exact spot in which it will break in the most
// optimized way.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int BREAKS[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
const size_t len = 10;
size_t crystalBalls = 2;

int testCrystalBall()
{
    size_t jump_size = (size_t)floor(sqrt(len - 1));
    size_t pos = jump_size;
    do
    {
        if (BREAKS[pos] == 0)
        {
            pos += jump_size;
            continue;
        }
        if (BREAKS[pos] == 1)
        {
            --crystalBalls; // break 😬
            printf("Broke first 🔮 at %lu\n", pos);

            pos -= jump_size;
            for (size_t i = 0; i < jump_size && i < len; ++i, ++pos)
            {
                if (BREAKS[pos] == 1)
                {
                    --crystalBalls; // break 😬
                    printf("Broke second at 🔮 at %lu\n", pos);
                    break;
                }
                else
                {
                    printf("Didn't break at %lu\n", pos);
                }
            }
        }

    } while (crystalBalls > 0);
    return 0;
}

int testCrystalBall2()
{
    size_t jump_size = (size_t)floor(sqrt(len - 1));
    size_t pos = jump_size;

    for (; pos < len; pos += jump_size)
    {
        if (BREAKS[pos] == 1)
        {
            printf("Broke first 🔮 at %lu\n", pos);
            break;
        }
    }
    pos -= jump_size; // jump back sqrt(len)

    for (size_t i = 0; i < jump_size && i < len; ++i, ++pos)
    {
        if (BREAKS[pos] == 1)
        {
            printf("Broke second at 🔮 at %lu\n", pos);
            break;
        }
        else
        {
            printf("Didn't break at %lu\n", pos);
            // continue
        }
    }
    return -1;
}

int main()
{
    testCrystalBall();
    testCrystalBall2();
}
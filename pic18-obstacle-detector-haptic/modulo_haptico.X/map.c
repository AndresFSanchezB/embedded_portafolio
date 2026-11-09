#include "mapfunc.h"

long mapn(long x, long eMin, long eMax, long sMin, long sMax)
{
    return (eMax - x) * (sMax - sMin) / (eMax - eMin) + sMin;
}

#include "../../fdf_header.h"

void project_iso(int x, int y, int z, int *xp, int *yp)
{
    float angle;
    float z_scale;

    float temp_x;
    float temp_y;

    z_scale = 1;
    angle = 0.5235099; // 30 radianes
    temp_x = (float)(x - y) * cos(angle);
    temp_y = (float)(x + y) * sin(angle) - (z * z_scale);

    *xp = (int)temp_x;
    *yp = (int)temp_y;
}

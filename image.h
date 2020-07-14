#pragma once
#include<easyx.h>
class image
{
public:
    IMAGE a, b;
    int w, h;
    image(LPCSTR s, LPCSTR d)
    {
        loadimage(&a, s);
        loadimage(&b, d);
        w = a.getwidth();
        h = a.getheight();
    };
    image()
    {
     
    };
    void draw(int x, int y)
    {
            putimage(x - w / 2, y - h / 2, &b, SRCPAINT);
            putimage(x - w / 2, y - h / 2, &a, SRCAND);
    }
    void load(LPCSTR s, LPCSTR d)
    {
        loadimage(&a, s);
        loadimage(&b, d);
        w = a.getwidth();
        h = a.getheight();
    }
};
// a)
struct color make_color(int red, int green, int blue)
{
    struct color c;
    c.red = red < 0 ? 0 : (red > 255 ? 255 : red);
    c.green = green < 0 ? 0 : (green > 255 ? 255 : green);
    c.blue = blue < 0 ? 0 : (blue > 255 ? 255 : blue);
    return c;
}

// b)
int getRed(struct color c)
{
    return c.red;
}

// c)
bool equal_color(struct color color1, struct color color2)
{
    if (color1.red  == color2.red && color1.green  == color2.green && color1.blue  == color2.blue) 
        return true;
    return false;
}

// d)
struct color brighter(struct color c)
{
    if (!c.red && !c.green && !c.blue)
        return (struct color) {3, 3, 3};
    
    if (c.red < 3)
        c.red = 3;
    if (c.green < 3)
        c.green = 3;
    if (c.blue < 3)
        c.blue = 3;

    c.red = (int)((float)c.red / 0.7f);
    c.green = (int)((float)c.green / 0.7f);
    c.blue = (int)((float)c.blue / 0.7f);

    if (c.red > 255)
        c.red = 255;
    if (c.green > 255)
        c.green = 255;
    if (c.blue > 255)
        c.blue = 255;

    return c;
}

// e)
struct color darker(struct color c)
{
    c.red = (int)((float)c.red * 0.7f);
    c.green = (int)((float)c.green * 0.7f);
    c.blue = (int)((float)c.blue * 0.7f);
    return c;
}
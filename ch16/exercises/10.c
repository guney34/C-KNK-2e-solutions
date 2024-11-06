// a)
int area(const struct rectangle *r)
{
    const int width = r->lower_right.x - r->upper_left.x;
    const int height = r->lower_right.y - r->upper_left.y;
    return height * width;
}

// b)
struct point centre(const struct rectangle *r)
{
    struct point p;
    p.x = (int)((float)(r->lower_right.x + r->upper_left.x) / 2);
    p.y = (int)((float)(r->lower_right.y + r->upper_left.y) / 2);
    return p;
}

// c)
struct rectangle move_rec(const struct rectangle *r, int x, int y)
{
    struct rectangle r2 = *r;
    r2.upper_left.x += x;
    r2.upper_left.y += y;
    r2.lower_right.x += x;
    r2.lower_right.y += y;
    return r2;
}

// d)
bool in_rect(const struct rectangle *r, const struct point *p)
{
    if (p->x > r->upper_left.x && p->y > r->upper_left.y &&
        p->x < r->lower_right.x && p->y < r->lower_right.y)
        return true;
    return false;
}
// a)
double area(const struct shape *s)
{
    if (s->shape_kind == RECTANGLE) 
        return s->u.rectangle.width * s->u.rectangle.height;
    if (s->shape_kind == CIRCLE) 
        return (M_PI * (double)s->u.circle.radius * (double)s->u.circle.radius); 
    return -1;
}

// b)
struct shape move(struct shape s, int x, int y)
{
    s.center.x  +=  x;
    s.center.y  +=  y;
    return s;
}

// c)
struct shape scale(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height = (int)((double)s.u.rectangle.height * c);
        s.u.rectangle.width =  (int)((double)s.u.rectangle.width * c);
    }
    if (s.shape_kind == CIRCLE) 
        s.u.circle.radius = (int)((double)s.u.circle.radius * c);
    return s;
}
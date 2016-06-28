double cross(Point p,Point p1,Point p2)
{
    double x1=p1.x-p.x,y1=p1.y-p.y;
    double x2=p2.x-p.x,y2=p2.y-p.y;
    return x1*y2-x2*y1;
}

double dis2(Point p1,Point p2)
{
    return sqrt( pow(p1.x-p2.x,2.0) +pow(p1.y-p2.y,2.0) );
}

double disptoseg(Point p,Point p1,Point p2)
{
    if(dis2(p1,p2)==0)return dis2(p,p1);
    Point t=po;
    t.y+=p1.x-p2.x;
    t.x+=p2.y-p1.y;

    if( cross(t,p,p1)*cross(t,p,p2)>=0 )
    {
        return min( dis2( p,p1),dis2(p,p2) );
    }

    return fabs( cross(p,p1,p2) )/ dis2(p1,p2) ;

}

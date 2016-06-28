double cross(Point p,Point p1,Point p2)
{
    double x1=p1.x-p.x,y1=p1.y-p.y;
    double x2=p2.x-p.x,y2=p2.y-p.y;
    return x1*y2-x2*y1;
}

bool cover()
{
    pot[n]=pot[0];
    pot[n+1]=pot[1];
    pot[n+2]=pot[2];
    for(int i=0; i<=n; ++i)
    {
        if(cross(po,pot[i],pot[i+1])*cross(po,pot[i+1],pot[i+2])<0 )
            return false;
    }
    return true;

}

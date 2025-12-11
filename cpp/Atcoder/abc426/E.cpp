#include <bits/stdc++.h>
#define double long double
using namespace std;
struct Point 
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
};
Point operator-(const Point& a,const Point& b){return Point(a.x-b.x,a.y-b.y);}
Point operator+(const Point& a,const Point& b){return Point(a.x+b.x,a.y+b.y);}
Point operator*(const Point& a,double s){return Point(a.x*s,a.y*s);}
inline double dj(const Point& a,const Point& b){return a.x*b.x+a.y*b.y;}
inline double xj(const Point& a,const Point& b){return a.x*b.y-a.y*b.x;}
inline double jf(const Point& a){return a.x*a.x+a.y*a.y;}
inline double dist(const Point& a,const Point& b){return sqrt(jf(a-b));}
inline double psd(const Point& P,const Point& A,const Point& B) 
{
    Point AP=P-A;
    Point AB=B-A;
    double l2=jf(AB);
    if(l2==0.0) return dist(P,A);
    double t=dj(AP,AB)/l2;
    if(t<0.0) t=0.0;
    if(t>1.0) t=1.0;
    Point Q=A+AB*t;
    return dist(P,Q);
}
inline double pps(const Point& P,const Point& A,const Point& B) 
{
    Point AP=P-A;
    Point AB=B-A;
    double l2=jf(AB);
    if(l2==0.0) return 0.0;
    double t=dj(AP,AB)/l2;
    if(t<0.0) t=0.0;
    if(t>1.0) t=1.0;
    return t;
}
inline double md(Point A,Point B,Point C,Point D) 
{
    Point AB=B-A;
    Point CD=D-C;
    double L1=sqrt(jf(AB));
    double L2=sqrt(jf(CD));
    if(L1==0.0&&L2==0.0) return dist(A,C);
    if(L1==0.0) return psd(A,C,D);
    if(L2==0.0) return psd(C,A,B);
    Point u=AB*(1.0/L1);
    Point v=CD*(1.0/L2);
    Point w=v-u;
    Point p0=C-A;
    double a=jf(w);
    double b=2.0*dj(p0,w);
    double c=jf(p0);
    double mind=1e18;
    double T1=min(L1,L2);
    if(a>1e-12) 
    { 
        double tv=-b/(2.0*a);
        if(tv>=0.0&&tv<=T1) 
        {
            double dsq=a*tv*tv+b*tv+c;
            mind=min(mind,sqrt(dsq));
        }
    }
    double dsta=sqrt(c); 
    double dend=sqrt(a*T1*T1+b*T1+c); 
    mind=min(mind,dsta);
    mind=min(mind,dend);
    if(L1<L2) 
    {
        Point BC=B-C;
        double a2=jf(v);
        double b2=-2.0*dj(BC,v);
        double c2=jf(BC);
        if(a2>1e-12) 
        {
            double tv=-b2/(2.0*a2);
            if(tv>=L1&&tv<=L2) 
            {
                double dsq=a2*tv*tv+b2*tv+c2;
                mind=min(mind,sqrt(dsq));
            }
        }
        double dl1=sqrt(a2*L1*L1+b2*L1+c2);
        double dl2=sqrt(a2*L2*L2+b2*L2+c2);
        mind=min(mind,dl1);
        mind=min(mind,dl2);
    } 
    else if(L2<L1) 
    {
        Point AD=A-D;
        double a2=jf(u);
        double b2=2.0*dj(AD,u);
        double c2=jf(AD);
        if(a2>1e-12) 
        {
            double tv=-b2/(2.0*a2);
            if(tv>=L2&&tv<=L1) 
            {
                double dsq=a2*tv*tv+b2*tv+c2;
                mind=min(mind,sqrt(dsq));
            }
        }
        double dl2=sqrt(a2*L2*L2+b2*L2+c2);
        double dl1=sqrt(a2*L1*L1+b2*L1+c2);
        mind=min(mind,dl2);
        mind=min(mind,dl1);
    }   
    mind=min(mind,dist(B,D));
    return mind;
}
int main() 
{
    int T;
    cin>>T;    
    while(T--) 
    {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point A(x1,y1),B(x2,y2),C(x3,y3),D(x4,y4); 
        double ans=md(A,B,C,D);
        cout<<fixed<<setprecision(15)<<ans<<endl;
    }
    return 0;
}
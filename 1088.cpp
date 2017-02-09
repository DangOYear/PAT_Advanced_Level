#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<algorithm>//加上就通过 
using namespace std;//加上就通过 

typedef long long ll;

ll gcd(ll a,ll b){
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

struct Fraction{
    ll down;
    ll up;
}a,b;


Fraction reduction(Fraction f){
    if(f.down<0){
        f.up=-f.up;
        f.down=-f.down;
    }

    if(f.up==0){
        f.down=1;
    }
    else{
        int g=gcd(abs(f.up),abs(f.down));
        f.down/=g;
        f.up/=g;
    }
    return f;
}

Fraction add(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.down;
    result.up=a.down*b.up+a.up*b.down;
    return reduction(result);
}

Fraction minu(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.down;
    result.up=a.up*b.down-a.down*b.up;
    return reduction(result);
}

Fraction mul(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.down;
    result.up=a.up*b.up;
    return reduction(result);
}

Fraction divide(Fraction a,Fraction b){
    Fraction result;
    result.down=a.down*b.up;
    result.up=a.up*b.down;
    return reduction(result);
}


void show(Fraction f){
    f=reduction(f);
    if(f.up<0)  printf("(");
    if(f.down==1)   printf("%lld",f.up);
    else{
        if(abs(f.up)>f.down){
            printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
        }
        else{
            printf("%lld/%lld",f.up,f.down);
        }
    }
    if(f.up<0)  printf(")");
}


int main(){
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    show(a);
    printf(" + ");
    show(b);
    printf(" = ");
    show(add(a,b));
    printf("\n");

    show(a);
    printf(" - ");
    show(b);
    printf(" = ");
    show(minu(a,b));
    printf("\n");

    show(a);
    printf(" * ");
    show(b);
    printf(" = ");
    show(mul(a,b));
    printf("\n");

    show(a);
    printf(" / ");
    show(b);
    printf(" = ");
    if(b.up==0)
        printf("Inf");
    else
        show(divide(a,b));
    return 0;
    //printf("\n");
}

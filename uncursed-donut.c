#include<stdio.h>


int k;
double sin() ,cos();
main( int argc, char* argv[]){
    int vW, vH;
    if (argc > 1) {
        sscanf(argv[1], "%d", &vW);
        sscanf(argv[2], "%d", &vH);
        }
    else {
            vW = 80;
            vH = 22;
    }
    float A=0, B=0, i, j, z[vW*vH];
    char b[vW*vH];
    printf("\x1b[2J");
    for(; ; ) {
        memset(b,32,vW*vH);
        memset(z,0,vW*vH*4);
        for(j=0; 6.28>j; j+=0.07) {
            for(i=0; 6.28 >i; i+=0.02) {
                float sini=sin(i),
                      cosj=cos(j),
                      sinA=sin(A),
                      sinj=sin(j),
                      cosA=cos(A),
                      cosj2=cosj+2,
                      mess=1/(sini*cosj2*sinA+sinj*cosA+5),
                      cosi=cos(i),
                      cosB=cos(B),
                      sinB=sin(B),
                      t=sini*cosj2*cosA-sinj*sinA;
                int x=vW/2+0.6*vW*mess*(cosi*cosj2*cosB-t*sinB),
                    y= vH/2+0.6*0.5*vW*mess*(cosi*cosj2*sinB +t*cosB),
                    o=x+vW*y,
                    N=8*((sinj*sinA-sini*cosj*cosA)*cosB-sini*cosj*sinA-sinj*cosA-cosi *cosj*sinB);
                if(vH>y&&y>0&&x>0&&vW>x&&mess>z[o]){
                    z[o]=mess;
                    b[o]=".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }
        printf("\x1b[d");
        for(k=0; vW*vH>=k; k++)
            putchar(k%vW?b[k]:10);
        A+=0.004;
        B+= 0.002;
	usleep(10000);
    }
}


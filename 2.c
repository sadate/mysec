#include <graphics.h>
#include <stdio.h>
#include <conio.h>
struct header
{
    unsigned int bfType;
    long         bfSize;
    unsigned int bfReserved1;
    unsigned int bfReserved2;
    long         bfoffBits;
};
struct tinfoheader
{
    long         biSize;
    long         biWidth;
    long         biHeight;
    unsigned int biPlanes;
    unsigned int biBitCount;
    long         biCompression;
    long         biSizeImage;
    long         biXPelsPerMeter;
    long         biYPelsPerMeter;
    long         biClrUsed;
    long         biClrImportant;
};
struct header HEADER;              
struct tinfoheader INFO;
unsigned char charbuf[40000];

void Loadfile()
{
    int i, ld;
    FILE *fp;
    char *bmpfile = "c:\\test.bmp";
      
    fp = fopen(bmpfile, "rb");
    fseek(fp, 0, SEEK_SET);
    fseek(fp, 0, SEEK_END);
    ld = ftell(fp);
    fclose(fp);
    
    fp = fopen(bmpfile, "rb");
    if (fp != NULL) {
        fread(&charbuf, ld, 1, fp);
        fclose(fp);
    }
       
    fp = fopen(bmpfile, "rt");
    if (fp != NULL) {
	    fread(&HEADER, sizeof(struct header), 1, fp);
	    fread(&INFO, sizeof(struct tinfoheader), 1, fp);
	    fclose(fp);
    }
}

void showpic(int x,int y)
{
    int           i, j, k, l = 0;
    int           num, m, x0, x1, x2;
    unsigned char b,c,c1;
    
    m = INFO.biWidth / 32;
    
    if ((INFO.biWidth % 32) != 0) {
        m = m + 1;
    }
    
    num = HEADER.bfoffBits;
    for (l = INFO.biHeight - 1; l >= 0; l--) {
        for (i = 0; i < m; i++) {
            x0 = i << 5;
            for (j = 0; j < 4; j++)
            {
                x1 = j << 3;
                c = charbuf[num];
                num++;
                for (k = 7; k >= 0; k--)
                {
                    x2 = x0 + x1 + 7 - k;
                    if (x2 >= INFO.biWidth) {
                        continue;
                    }
                    else {
                        b  = 1 << k;
                        c1 = c & b;
                        if (c1 == 0) {
                           putpixel(x + x2, y + l, RED);
                        }
                        else {
                           putpixel(x + x2, y + l, YELLOW);
                        }
                    }
                }
            }
        }
    }
}

void main()
{
  int driver, mode;
  
  driver = DETECT;
  initgraph(&driver, &mode, NULL);
  directvideo = 0;
  //setfillstyle(SOLID_FILL,WHITE);
  //bar(0,0,639,479);
  //line(0, 0, 200, 200);
  //setcolor(RED);
  //Loadfile();
  cprintf("ÎÒ");
  //showpic(0, 0);
  getch();
  closegraph();
}


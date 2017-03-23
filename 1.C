#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

int main() 
{
    unsigned char i, j, k; 
    char dd[2] = { 0 };
    FILE *fp;
    int driver, mode, psize;
    unsigned char font[32];
    unsigned char *pbuf; 
    
    driver = DETECT;
    initgraph(&driver, &mode, NULL);
    directvideo = 0;
    
    fp = fopen("c:\\hzk16", "wb");
    if (fp == NULL) {
        return -1;
    }

    psize=imagesize(0, 0, 15, 15); 
    pbuf=malloc(psize); 
     
    for (i = 0; i < 94; i++) {
        for (j = 0; j < 94; j++) {
             dd[0] = i + 161;
             dd[1] = j + 161;
             clrscr();
             gotoxy(0,0); 
             textcolor(WHITE);
             textbackground(BLACK);             
             cprintf("%c%c", dd[0], dd[1]);          
             memset(font, 0, 32);
             memset(pbuf, 0, psize);
             getimage(0,0,15,15, pbuf);
             for (k = 0; k < 16; k++) {
                 memcpy(font + i, pbuf + 4 + i * 8,  2);
             }
             fwrite(&font, sizeof(font), 1, fp);
        }
    }

    fclose(fp);
    getch();
    closegraph();    
} 
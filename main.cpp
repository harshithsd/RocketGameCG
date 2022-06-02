#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include<mmsystem.h>

int pause=0;
int ah=0,color[3];
int i=0,life=3,score=0;
char stringh[100];
int level=0,profile=0,guide=0;
float rocket[][3]={{56,0,1},{52,16,1},{104,16,1},{112,12,1},{112,-12,1},{104,-16,1},{52,-16,1},
                    {88,2,1},{88,12,1},{112,12,1},{120,10,1},{128,4,1},{128,2,1},
                    {88,-2,1},{88,-12,1},{112,-12,1},{120,-10,1},{128,-4,1},{128,-2,1},
                    {112,8,1},{124,8,1},{144,0,1},{124,-8,1},{112,-8,1},
                    {104,16,1},{92,56,1},{72,64,1},{72,16,1},{80,20,1},{72,36,1},
                    {104,-16,1},{92,-56,1},{72,-64,1},{72,-16,1},{80,-20,1},{72,-36,1},
                    {66,36,1},{66,48,1},{96,48,1},{104,44,1},{104,40,1},{96,36,1},
                    {66,-36,1},{66,-48,1},{96,-48,1},{104,-44,1},{104,-40,1},{96,-36,1},
                    {72,16,1},{64,32,1},{52,32,1},{52,16,1},
                    {72,-16,1},{64,-32,1},{52,-32,1},{52,-16,1},
                    {40,4,1},{40,12,1},{52,16,1},{55,4,1},
                    {40,-4,1},{40,-12,1},{52,-16,1},{55,-4,1},
                    {64,16,1},{72,8,1},{80,8,1},{72,16,1},
                    {64,-16,1},{72,-8,1},{80,-8,1},{72,-16,1}};
float stone[][3]={{1220,40,1},{1240,60,1},{1300,40,1},{1280,0,1},{1240,0,1},{1240,20,1}};
float rocketTopedge[10]={-64,-60,-56,-48,-16,-12,-10,-6,-4,0};
float rocketBottomedge[10]={0,4,6,10,12,16,48,56,60,64};
float wall[][3]={{1200,400,1},{1200,-100,1},{1260,-100,1},{1260,400,1},
                 {1200,200,1},{1200,-200,1},{1260,-200,1},{1260,200,1},
                 {1200,-400,1},{1200,100,1},{1260,100,1},{1260,-400,1},
                 {1200,200,1},{1200,-200,1},{1260,-200,1},{1260,200,1},
                 {1200,200,1},{1200,-100,1},{1260,-100,1},{1260,200,1},};
int sleepFactor=2000,posWall=0,noOfWall=0;
int wallInrc[5]={1000,700,400,100,200},wallActive[5];
void init(int w,int h)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glViewport(0,0,w,h);
    gluOrtho2D(0,1200,-400,400);
}
void renderBitmapString(float x,float y,void *font,char text[]) {
    glRasterPos2f(x,y);
    for (int k=0;k<strlen(text); k++) {
        glutBitmapCharacter(font,text[k]);
    }
}
void drawrocket()
{
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[0]);
        glVertex2fv(rocket[1]);
        glVertex2fv(rocket[2]);
        glVertex2fv(rocket[3]);
        glVertex2fv(rocket[4]);
        glVertex2fv(rocket[5]);
        glVertex2fv(rocket[6]);
    glEnd();
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[19]);
        glVertex2fv(rocket[20]);
        glVertex2fv(rocket[21]);
        glVertex2fv(rocket[22]);
        glVertex2fv(rocket[23]);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[7]);
        glVertex2fv(rocket[8]);
        glVertex2fv(rocket[9]);
        glVertex2fv(rocket[10]);
        glVertex2fv(rocket[11]);
        glVertex2fv(rocket[12]);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[13]);
        glVertex2fv(rocket[14]);
        glVertex2fv(rocket[15]);
        glVertex2fv(rocket[16]);
        glVertex2fv(rocket[17]);
        glVertex2fv(rocket[18]);
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[24]);
        glVertex2fv(rocket[25]);
        glVertex2fv(rocket[26]);
        glVertex2fv(rocket[27]);
    glEnd();
    glColor3f(1,0.5,0);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[27]);
        glVertex2fv(rocket[28]);
        glVertex2fv(rocket[29]);
    glEnd();
        glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[30]);
        glVertex2fv(rocket[31]);
        glVertex2fv(rocket[32]);
        glVertex2fv(rocket[33]);
    glEnd();
    glColor3f(1,0.5,0);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[33]);
        glVertex2fv(rocket[34]);
        glVertex2fv(rocket[35]);
    glEnd();
    glColor3f(0.4,0.2,0.1);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[36]);
        glVertex2fv(rocket[37]);
        glVertex2fv(rocket[38]);
        glVertex2fv(rocket[39]);
        glVertex2fv(rocket[40]);
        glVertex2fv(rocket[41]);
    glEnd();
    glColor3f(0.4,0.2,0.1);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[42]);
        glVertex2fv(rocket[43]);
        glVertex2fv(rocket[44]);
        glVertex2fv(rocket[45]);
        glVertex2fv(rocket[46]);
        glVertex2fv(rocket[47]);
    glEnd();
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[48]);
        glVertex2fv(rocket[49]);
        glVertex2fv(rocket[50]);
        glVertex2fv(rocket[51]);
    glEnd();
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[52]);
        glVertex2fv(rocket[53]);
        glVertex2fv(rocket[54]);
        glVertex2fv(rocket[55]);
    glEnd();
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[56]);
        glVertex2fv(rocket[57]);
        glVertex2fv(rocket[58]);
        glVertex2fv(rocket[59]);
    glEnd();
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[60]);
        glVertex2fv(rocket[61]);
        glVertex2fv(rocket[62]);
        glVertex2fv(rocket[63]);
    glEnd();
    glColor3f(0.9,0.4,0.1);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[64]);
        glVertex2fv(rocket[65]);
        glVertex2fv(rocket[66]);
        glVertex2fv(rocket[67]);
    glEnd();
    glColor3f(0.9,0.4,0.1);
    glBegin(GL_POLYGON);
        glVertex2fv(rocket[68]);
        glVertex2fv(rocket[69]);
        glVertex2fv(rocket[70]);
        glVertex2fv(rocket[71]);
    glEnd();
}
void drawstars1()
{
    int r,s;
    for(r=-400;r<400;r+=50)
    {
        for(s=0;s<1200;s+=50)
        {
            glColor3f(0,color[1],0);
            if(r%100==0)
            {
                glPointSize(1.5);
                glColor3f(0,1,1);
                glBegin(GL_POINTS);
                glVertex2i(s,r);
                glEnd();
            }
            else{
                glColor3f(0,1,1);
                glBegin(GL_POINTS);
                glVertex2i(s+25,r);
                glEnd();
            }
        }
    }
}
void drawheart()
{
    glColor3f(1,0,0);
            glBegin(GL_POLYGON);
                glVertex2f(22.5,0);
                glVertex2f(41.5,15);
                glVertex2f(45,30);
                glVertex2f(37.5,37.5);
                glVertex2f(30,37.5);
                glVertex2f(22.5,30);
                glVertex2f(15,37.5);
                glVertex2f(7.5,37.5);
                glVertex2f(0,30);
                glVertex2f(3.5,15);
        glEnd();
}
void drawWall(int v)
{
    switch(v)
    {
    case 0:
        glPushMatrix();
        glTranslatef(-((posWall+1220)%1320),0,0);
            glColor3f(0.9,0.4,0.1);
            glBegin(GL_POLYGON);
                glVertex2fv(wall[0]);
                glVertex2fv(wall[1]);
                glVertex2fv(wall[2]);
                glVertex2fv(wall[3]);
            glEnd();
        glPopMatrix();
        break;
   case 1:
       glPushMatrix();
        glTranslatef(-((posWall+230)%1320),0,0);
            glColor3f(0.9,0.4,0.1);
            glBegin(GL_POLYGON);
                glVertex2fv(wall[4]);
                glVertex2fv(wall[5]);
                glVertex2fv(wall[6]);
                glVertex2fv(wall[7]);
            glEnd();
        glPopMatrix();
        break;
   case 2:
       glPushMatrix();
            glTranslatef(-((posWall+560)%1320),0,0);
            glColor3f(0.9,0.4,0.1);
            glBegin(GL_POLYGON);
                glVertex2fv(wall[8]);
                glVertex2fv(wall[9]);
                glVertex2fv(wall[10]);
                glVertex2fv(wall[11]);
            glEnd();
        glPopMatrix();
        break;
    case 3:
        glPushMatrix();
            glTranslatef(-((posWall+890)%1320),0,0);
            glColor3f(0.9,0.4,0.1);
            glBegin(GL_POLYGON);
                glVertex2fv(wall[12]);
                glVertex2fv(wall[13]);
                glVertex2fv(wall[14]);
                glVertex2fv(wall[15]);
            glEnd();
        glPopMatrix();
        break;
    }
    glutPostRedisplay();
}
/*int edgeTophit(int g)
{
    int h=0,y=8,k=posWall;
    while(h<10)
    {
        if((g>(rocketTopedge[h]+i)&&g<(rocketTopedge[h+1]+i))&&((((posWall+230)%1320)>(64+y))&&(((posWall+230)%1320)<(74+y))))
            return 1;
        renderBitmapString(100+y*10,300,itoa(rocketTopedge[h]+i,stringh,10));
        glFlush();
        y+=8;
        if(k<posWall)
        {
            h++;
            k=posWall;
        }
    }
    if((((posWall+1220)%1320)>104)&&(((posWall+1220)%1320)<114)&&(((i>g)&&(i<g+64))))
        return 1;
    return 0;
}
int edgeBottomhit(int g)
{
    return 0;
}*/
void rocketHitWall()
{
    if(((((posWall+560)%1320)>64)&&(((posWall+560)%1320)<74))&&((i>-210)&&(i<210)))
    {
        life--;
        pause=1;
        posWall+=165;
    }
    if((((posWall+1220)%1320)>64)&&(((posWall+1220)%1320)<74)&&((i>-210)&&(i<210)))
    {
        life--;
        pause=1;
        posWall+=165;
    }
    if((((posWall+890)%1320)>64)&&(((posWall+890)%1320)<74)&&((i>-410)&&(i<110)))
    {
        life--;
        pause=1;
        posWall+=165;
    }

    if((((posWall+230)%1320)>64)&&(((posWall+230)%1320)<74)&&((i>-110)&&(i<410)))
    {
        life--;
        pause=1;
        posWall+=165;
    }
}
void mainScreen()
{
    if(level==0)
    {
glColor3f(color[0],color[1],color[2]);
            glBegin(GL_POLYGON);
                glVertex2f(200,300);
                glVertex2f(200,-300);
                glVertex2f(1000,-300);
                glVertex2f(1000,300);
        glEnd();
        glColor3f(0,0,0.8);
            glBegin(GL_POLYGON);
                glVertex2f(300,270);
                glVertex2f(300,-270);
                glVertex2f(900,-270);
                glVertex2f(900,270);
        glEnd();
        glLineWidth(3);
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(300,270);
                glVertex2f(300,-270);
                glVertex2f(900,-270);
                glVertex2f(900,270);
        glEnd();
        glColor3f(0,0,0);
            glBegin(GL_POLYGON);
                glVertex2f(450,250);
                glVertex2f(450,50);
                glVertex2f(750,50);
                glVertex2f(750,250);
        glEnd();
        glLineWidth(1);
        glPushMatrix();
            glTranslatef(600,100,0);
            glRotatef(90,0,0,1);
            drawrocket();
        glPopMatrix();
        glColor3f(1,0.4,0);
        renderBitmapString(515,100,GLUT_BITMAP_TIMES_ROMAN_24,"ROCKET GAME");
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,25);
                glVertex2f(450,-25);
                glVertex2f(750,-25);
                glVertex2f(750,25);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(485,-5,GLUT_BITMAP_HELVETICA_18,"PRESS 'ENTER' TO START");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,25);
                glVertex2f(450,-25);
                glVertex2f(750,-25);
                glVertex2f(750,25);
            glEnd();
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(460,-80,GLUT_BITMAP_HELVETICA_18,"PRESS 'SPACE' FOR ABOUT US");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);;
        glEnd();
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(480,-155,GLUT_BITMAP_HELVETICA_18,"PRESS 'Q' TO PLAY GUIDE");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();
    }
}
void guideScreen()
{
    if(guide==1)
    {
        glColor3f(0.7,0.7,0.7);
            glBegin(GL_POLYGON);
                glVertex2f(200,300);
                glVertex2f(200,-300);
                glVertex2f(1000,-300);
                glVertex2f(1000,300);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(6);
            glBegin(GL_LINE_LOOP);
                glVertex2f(215,285);
                glVertex2f(215,-285);
                glVertex2f(985,-285);
                glVertex2f(985,285);
            glEnd();
        glColor3f(1,0,0);
        glColor3f(0.4,0.4,0.4);
            glBegin(GL_POLYGON);
                glVertex2f(250,200);
                glVertex2f(250,-200);
                glVertex2f(950,-200);
                glVertex2f(950,200);
        glEnd();
        glColor3f(0.6,0,0);
        renderBitmapString(515,250,GLUT_BITMAP_TIMES_ROMAN_24,"HOW TO PLAY ?");
        glColor3f(0,0,0.4);
        renderBitmapString(300,150,GLUT_BITMAP_HELVETICA_18,"PRESS 'UP ARROW' TO UP");
        glColor3f(0,0,0.4);
        renderBitmapString(300,100,GLUT_BITMAP_HELVETICA_18,"PRESS 'DOWN ARROW' TO DOWN");
        glColor3f(0,0,0.4);
        renderBitmapString(300,50,GLUT_BITMAP_HELVETICA_18,"PRESS 'RIGHT ARROW' TO SPEEDUP");
        glColor3f(0,0,0.4);
        renderBitmapString(300,-20,GLUT_BITMAP_HELVETICA_18," - THE ROCKET HAS TO MOVE FORWARD WITHOUT");
        glColor3f(0,0,0.4);
        renderBitmapString(300,-45,GLUT_BITMAP_HELVETICA_18,"     HITTING THE WALL .");
        glColor3f(0,0,0.4);
        renderBitmapString(300,-95,GLUT_BITMAP_HELVETICA_18," - SCORE IS INCREASE WHEN YOU CROSS EACH WALL .");
        glLineWidth(2);
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(600,-130);
                glVertex2f(600,-180);
                glVertex2f(900,-180);
                glVertex2f(900,-130);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(625,-155,GLUT_BITMAP_HELVETICA_18,"PRESS 'ESC' FOR MENU");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                 glVertex2f(600,-130);
                glVertex2f(600,-180);
                glVertex2f(900,-180);
                glVertex2f(900,-130);
        glEnd();
    }
}
void profileScreen()
{
    if(profile==1)
    {
        glColor3f(0.7,0.7,0.7);
            glBegin(GL_POLYGON);
                glVertex2f(200,300);
                glVertex2f(200,-300);
                glVertex2f(1000,-300);
                glVertex2f(1000,300);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(6);
            glBegin(GL_LINE_LOOP);
                glVertex2f(215,285);
                glVertex2f(215,-285);
                glVertex2f(985,-285);
                glVertex2f(985,285);
            glEnd();
        glColor3f(1,0,0);
        renderBitmapString(380,250,GLUT_BITMAP_TIMES_ROMAN_24,"NMAM INSTITUTE OF TECHNOLOGY");
        glColor3f(0,0,0.5);
        renderBitmapString(520,220,GLUT_BITMAP_TIMES_ROMAN_24,"CG PROJECT");
        glColor3f(0.4,0.4,0.4);
            glBegin(GL_POLYGON);
                glVertex2f(250,200);
                glVertex2f(250,-200);
                glVertex2f(950,-200);
                glVertex2f(950,200);
        glEnd();
        glColor3f(0,0,0.7);
        renderBitmapString(290,160,GLUT_BITMAP_HELVETICA_18,"TEAM MEMBERS");
        glColor3f(0,0,0.4);
        renderBitmapString(300,120,GLUT_BITMAP_9_BY_15,"HARSHITH S DEVADIGA(4NM19CS076)");
        glColor3f(0,0,0.4);
        renderBitmapString(300,90,GLUT_BITMAP_9_BY_15,"GAGAN RAJENDRA NAIK(4NM19CS065)");
        glColor3f(0,0,0.7);
        renderBitmapString(290,30,GLUT_BITMAP_HELVETICA_18,"UNDER THE GUIDENCE OF ,");
        glColor3f(0,0,0.4);
        renderBitmapString(300,-10,GLUT_BITMAP_9_BY_15,"MR. SANNIDHAN M S");
        glColor3f(0,0,0.4);
        renderBitmapString(300,-40,GLUT_BITMAP_9_BY_15,"ASSISTANT PROFESSOR GD-II");
        glLineWidth(2);
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(600,-130);
                glVertex2f(600,-180);
                glVertex2f(900,-180);
                glVertex2f(900,-130);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(625,-155,GLUT_BITMAP_HELVETICA_18,"PRESS 'ESC' FOR MENU");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                 glVertex2f(600,-130);
                glVertex2f(600,-180);
                glVertex2f(900,-180);
                glVertex2f(900,-130);
        glEnd();

    }
}
void pauseScreen()
{
    if(pause==1 && life>0)
    {
        glColor3f(0.7,0.7,0.7);
            glBegin(GL_POLYGON);
                glVertex2f(200,300);
                glVertex2f(200,-300);
                glVertex2f(1000,-300);
                glVertex2f(1000,300);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(6);
            glBegin(GL_LINE_LOOP);
                glVertex2f(215,285);
                glVertex2f(215,-285);
                glVertex2f(985,-285);
                glVertex2f(985,285);
        glEnd();
        glColor3f(1,0,0);
        renderBitmapString(520,250,GLUT_BITMAP_TIMES_ROMAN_24,"LOST ONE LIFE");
        glColor3f(0.4,0.4,0.4);
            glBegin(GL_POLYGON);
                glVertex2f(250,200);
                glVertex2f(250,-200);
                glVertex2f(950,-200);
                glVertex2f(950,200);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(3);
            glBegin(GL_LINE_LOOP);
                glVertex2f(250,200);
                glVertex2f(250,-200);
                glVertex2f(950,-200);
                glVertex2f(950,200);
        glEnd();
        glColor3f(1,1,1);
            glBegin(GL_POLYGON);
                glVertex2f(400,180);
                glVertex2f(400,50);
                glVertex2f(800,50);
                glVertex2f(800,180);
        glEnd();
        for(int o=0;o<life;o++)
        {
            glPushMatrix();
            glTranslatef(600+o*60,100,0);
            drawheart();
        glPopMatrix();
        }
        glColor3f(1,0,0);
        renderBitmapString(450,110,GLUT_BITMAP_HELVETICA_18,"LIFE LEFT :");
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,25);
                glVertex2f(450,-25);
                glVertex2f(750,-25);
                glVertex2f(750,25);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(495,0,GLUT_BITMAP_HELVETICA_18,"PRESS 'R' TO RESUME");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,25);
                glVertex2f(450,-25);
                glVertex2f(750,-25);
                glVertex2f(750,25);
        glEnd();
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(475,-75,GLUT_BITMAP_HELVETICA_18,"PRESS 'ENTER' TO RESTART");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);
        glEnd();
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(480,-150,GLUT_BITMAP_HELVETICA_18,"PRESS 'ESC' TO QUIT");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();

    }
}
void gameoverScreen()
{
    if(life==0&&pause==1)
    {

        glColor3f(0.7,0.7,0.7);
            glBegin(GL_POLYGON);
                glVertex2f(200,300);
                glVertex2f(200,-300);
                glVertex2f(1000,-300);
                glVertex2f(1000,300);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(6);
            glBegin(GL_LINE_LOOP);
                glVertex2f(215,285);
                glVertex2f(215,-285);
                glVertex2f(985,-285);
                glVertex2f(985,285);
        glEnd();
        glLineWidth(3);
        glColor3f(1,0,0);
        renderBitmapString(450,110,GLUT_BITMAP_HELVETICA_18,"SCORE :");
        renderBitmapString(590,110,GLUT_BITMAP_TIMES_ROMAN_24,itoa(score,stringh,10));
        glColor3f(1,0,0);
        renderBitmapString(520,250,GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER");
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(475,-75,GLUT_BITMAP_HELVETICA_18,"PRESS 'ENTER' TO RESTART");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-50);
                glVertex2f(450,-100);
                glVertex2f(750,-100);
                glVertex2f(750,-50);;
        glEnd();
        glColor3f(0.5,0.5,0.6);
            glBegin(GL_POLYGON);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();
        glColor3f(0.7,0,0);
        renderBitmapString(480,-150,GLUT_BITMAP_HELVETICA_18,"PRESS 'ESC' TO QUIT");
        glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(450,-125);
                glVertex2f(450,-175);
                glVertex2f(750,-175);
                glVertex2f(750,-125);
        glEnd();
    }
}
void scoreLife()
{
    if(level==1)
    {
       glColor3f(1,1,0.1);
        glBegin(GL_POLYGON);
            glVertex2f(1200,200);
            glVertex2f(1200,400);
            glVertex2f(900,400);
            glVertex2f(900,200);
        glEnd();
        glColor3f(0,0,0);
        glLineWidth(6);
        glBegin(GL_LINE_LOOP);
            glVertex2f(1185,215);
            glVertex2f(1185,385);
            glVertex2f(915,385);
            glVertex2f(915,215);
        glEnd();
        glColor3f(0,0,0);
        renderBitmapString(950,250,GLUT_BITMAP_HELVETICA_12,"LIFE LEFT :");
        for(int o=0;o<life;o++)
        {
            glPushMatrix();
                glTranslatef(1040+o*40,240,0);
                glScalef(0.7,0.7,0);
                drawheart();
            glPopMatrix();
        }
        glColor3f(0,0,0);
        renderBitmapString(980,320,GLUT_BITMAP_HELVETICA_12,"SCORE :");
        glColor3f(1,0,0);
        renderBitmapString(1050,318,GLUT_BITMAP_HELVETICA_18,itoa(score,stringh,10));
    }
}
void scoreUpdate()
{
    if(((((posWall+130)%1320)>64)&&(((posWall+130)%1320)<74))||((((posWall+460)%1320)>64)&&(((posWall+460)%1320)<74))||((((posWall+790)%1320)>64)&&(((posWall+790)%1320)<74))||((((posWall+1020)%1320)>64)&&(((posWall+1020)%1320)<74)))
        score+=50;
}
void translatey(float x)
{
    glPushMatrix();
    glTranslatef(0,x,0);
    drawrocket();
    glPopMatrix();
}
void poss(int va)
{
   ah=(ah+1)%3;
   color[(ah)%3]=1;
   color[(ah+1)%3]=0;
   color[(ah+2)%3]=0;
   glutTimerFunc(0,poss,0);
}
void display()
{
    drawstars1();
    if(i==0 && level==1)
    {
        drawrocket();
    }
    if(i==0 && level==0)
    {
        poss(0);
    }
   if(pause==0 && level==1)
   {
       drawWall(0);
       drawWall(1);
       drawWall(2);
       drawWall(3);
       drawWall(4);
   }
    rocketHitWall();
    mainScreen();
    scoreLife();
    pauseScreen();
    profileScreen();
    gameoverScreen();
    guideScreen();
   // poss(0);
    glFlush();
    glutPostRedisplay();
}
void mykeyboard(unsigned char c,int x,int y)
{

    if((c=='r'||c=='R')&&life>0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        pause=0;
    }
    if(c==13 && level==1 && profile==0 && guide==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        life=3;
        posWall=0;
        i=0;
        score=0;
        pause=0;
    }
    if(c==13 && level==0 && profile==0 && guide==0 )
    {
        glClear(GL_COLOR_BUFFER_BIT);
        life=3;
        posWall=0;
        i=0;
        score=0;
        pause=0;
        level=1;
    }
    if(c==27&&pause==1 && profile==0 && guide==0 )
    {
        exit(0);
    }
    if(c==27 && profile==1 && guide==0 && level==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        profile=0;
    }
    if(c==32 && level==0 && guide==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        profile=1;
    }
    if(c==27 && guide==1 && profile==0 &&level==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        guide=0;
    }
    if((c=='q' || c=='Q')&& level==0 && profile==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        guide=1;
    }
}
void splkey(int key,int x,int y)
{
    if(key==GLUT_KEY_UP&&pause==0 && level==1 && profile==0 && guide==0)
    {
        if(i<360)
        {
           i+=10;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        scoreUpdate();
        translatey(i);
        posWall=(posWall+5)%1320;
        glFlush();
    }
    if(key==GLUT_KEY_DOWN&&pause==0 && level==1 && profile==0 && guide==0)
    {
         if(i>-360)
            i-=10;
        glClear(GL_COLOR_BUFFER_BIT);
        scoreUpdate();
        translatey(i);
        posWall=(posWall+5)%1320;
        glFlush();

    }
    if(key==GLUT_KEY_RIGHT&&pause==0 && level==1 && profile==0 && guide==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        scoreUpdate();
        posWall=(posWall+10)%1320;
        translatey(i);
        glFlush();
    }
}
int main(int argc,char *argv[])
{
    PlaySound("C:\\Users\\Harshith\\Cgproject\\RocketGameCG\\Games.wav",NULL, SND_ASYNC|SND_LOOP);
    glutInit(&argc,argv);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Rocket Game");
    glutReshapeFunc(init);
    glutDisplayFunc(display);
    glutKeyboardFunc(mykeyboard);
    glutSpecialFunc(splkey);
    glutMainLoop();
    return 0;
}

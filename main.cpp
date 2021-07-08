#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

float _run = 0.0;
float _sun = 0.00;
float _moon = 0.00;
float _brun = 0.0001;
float _run1 = 0.0;
float _run8 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _rain = 0.0;
float _nt = 0.0;
float _ang_tri = 0.0;
char text[] = "SCHOOL";


bool onOff;
bool frd = false;
bool bck = false;

bool rainday = false;
bool night = false;
float i,x,y,m,n,z;
GLfloat kite_position = 0.0f;
GLfloat kite_speed = 0.5;
bool kite_flag = false;
GLfloat kite_counter = 0.0f;

//float _angle = 0.0;
//float _cameraAngle = 0.0;
//float _run = 0.0;



void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}


void init(){

	glClearColor(0.0,0.5,0.8,1.0);
	glColor3ub(0.0,0.0,128);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);



}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
	glColor3ub(50,205,50);
	glVertex2i(0,550);
	glVertex2i(1000,550);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();
	glPushMatrix();
    if(night){
            // glClearColor(0,0,0,0);
    //glPushMatrix();
    glBegin(GL_QUADS);
	glColor3ub(0,0,128);
	glVertex2i(0,550);
	glVertex2i(1000,550);
	glVertex2i(1000,1000);
	glVertex2i(0,1000);
	glEnd();

	//glPopMatrix();


///Star
 for(n = 0; n <=1000; ++n)
    {
for(m = 550; m <=1000; ++m) {
glPushMatrix();
    glTranslatef(n,m,0);
    glPushMatrix();
    glScalef(0.15, 0.15, 0.0);
    glColor3ub(105,105,105);    //QUAD
    glBegin(GL_POLYGON);
   // glColor3ub (255,215,0);
    glVertex2i(320,460);
    glVertex2i(310,480);
    glVertex2i(300,460);
    glVertex2i(275,460);
    glVertex2i(290,450);
    glColor3ub(255,255,0);
    glVertex2i(280,425);
    glVertex2i(310,440);
    glVertex2i(340,425);
    glVertex2i(330,450);
    glVertex2i(345,460);
    glEnd();/*
	glBegin(GL_LINE_STRIP);
    glColor3ub (255,215,0);
    glVertex2i(320,460);
    glVertex2i(310,480);
    glVertex2i(300,460);
    glVertex2i(275,460);
    glVertex2i(290,450);
    glVertex2i(280,425);
    glVertex2i(310,440);
    glVertex2i(340,425);
    glVertex2i(330,450);
    glVertex2i(345,460);
    glVertex2i(320,460);
	glEnd(); */
	glPopMatrix();
glPopMatrix(); m+=80;
}
	n+=60;
	}
///end star
    //sun


	glPushMatrix();
	glTranslatef(500,1400,0);
	glTranslatef(0,-_moon,0);
	if(_moon==800){
        night=false;
        //glClearColor(0.0,0.5,0.8,1.0);

        //_sun==0;
        for(_sun=0;_sun>=380;++_sun){
        glPushMatrix();
	glTranslatef(500,1000,0);
	glTranslatef(0,-_sun,0);
	if(_sun==380){
        night=true;


	}

	glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	if(night=true){

            glPushMatrix();


	glTranslatef(500,1200,0);
	glTranslatef(0,-_moon,0);
	if(_moon==600){
        night=false;
        //glClearColor(0.0,0.5,0.8,1.0);
        glBegin(GL_POLYGON);
    glColor3ub(175,238,238);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=52;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x,y );
		glColor3ub(173,216,230);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(224,255,255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x,y );
		glColor3ub(173,216,230);
	}
	glEnd();
	glPopMatrix();
	}

	} }
	}
	glBegin(GL_POLYGON);
	glColor3ub(175,238,238);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=52;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x,y );
		glColor3ub(173,216,230);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(224,255,255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x,y );
		glColor3ub(173,216,230);
	}
	glEnd();
	glPopMatrix();

///Grass
    for(n = 0; n <=1000; ++n)
    {
for(m = -5; m <= 550; ++m) {
glPushMatrix();
    glTranslatef(n,m,0);
    glPushMatrix();
    glColor3ub(47,119,79);    //QUAD
    glBegin(GL_POLYGON);

    glVertex2i(3,5);
    glVertex2i(5,0);
	glVertex2i(3,9);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);

    glVertex2i(8,5);
    glVertex2i(10,0);
	glVertex2i(8,9);
	glVertex2i(5,0);
	glEnd();
	glBegin(GL_POLYGON);

    glVertex2i(5.8,5);
    glVertex2i(7.5,0);
	glVertex2i(5.8,9);
	glVertex2i(3,0);
	glEnd();
	glBegin(GL_LINE_STRIP);

    glVertex2i(3,5);
    glVertex2i(5,0);
	glVertex2i(3,9);
	glVertex2i(0,0);
	glVertex2i(3,5);
	glEnd();
	glBegin(GL_LINE_STRIP);

    glVertex2i(8,5);
    glVertex2i(10,0);
	glVertex2i(8,9);
	glVertex2i(5,0);
	glVertex2i(8,5);
	glEnd();
	glBegin(GL_LINE_STRIP);

    glVertex2i(5.8,5);
    glVertex2i(7.5,0);
	glVertex2i(5.8,9);
	glVertex2i(3,0);
	glVertex2i(5.8,5);
	glEnd();
	glPopMatrix();
glPopMatrix(); m+=8;
}
	n+=6;
	}

	///Cloud

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3ub(176,196,222);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );

	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    //glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    //glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();



///cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    //glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
//end of cloud
    ///small tree above road
    glPushMatrix();
    glTranslatef(0,0,0);
    for(z=0;z<=150;++z)
    {
    glTranslatef(10,0,0);
    glBegin(GL_POLYGON); // first small tree from left to right
    glColor3ub (0,128,0);
    glVertex2i(14,345);
    glVertex2i(16,356);
    glVertex2i(13,350);
    glVertex2i(12,361);
    glVertex2i(11,350);
    glVertex2i(9,356);
    glVertex2i(10,345);
    glEnd();
    }
    glPopMatrix();
    ///end of small tree


    glPushMatrix();
      ///river in night
            glColor3ub(139,69,19);
	glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 135);
    glVertex2i(900, 145);
    glVertex2i(800, 135);
    glVertex2i(700, 145);
    glVertex2i(600, 135);
    glVertex2i(500, 145);
    glVertex2i(400, 135);
    glVertex2i(300, 145);
    glVertex2i(200, 135);
    glVertex2i(100, 145);
    glVertex2i(0, 135);
    glEnd();
    glColor3ub(160,82,45);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 125);
    glVertex2i(900, 135);
    glVertex2i(800, 125);
    glVertex2i(700, 135);
    glVertex2i(600, 125);
    glVertex2i(500, 135);
    glVertex2i(400, 125);
    glVertex2i(300, 135);
    glVertex2i(200, 125);
    glVertex2i(100, 135);
    glVertex2i(0, 125);
    glEnd();
    glColor3ub(0,0,190);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 120);
    glVertex2i(900, 130);
    glVertex2i(800, 120);
    glVertex2i(700, 130);
    glVertex2i(600, 120);
    glVertex2i(500, 130);
    glVertex2i(400, 120);
    glVertex2i(300, 130);
    glVertex2i(200, 120);
    glVertex2i(100, 130);
    glVertex2i(0, 120);
    glEnd();
    glPopMatrix();
///end of river in night

///river flow
glPushMatrix();
glTranslatef(_run3,0,0);
    for(n =-10000; n <=10000; ++n)
    {
for(m = -5; m <= 120; ++m) {
glPushMatrix();
    glTranslatef(n,m,0);
    glPushMatrix();
    glColor3ub(65,105,225);
      //QUAD
    glBegin(GL_QUADS);

    glVertex2i(0,0);
    glVertex2i(10,0);
	glVertex2i(10,1);
	glVertex2i(0,1);
	glEnd();

	glPopMatrix();
glPopMatrix(); m+=30;
}
	n+=80;
	}
	glPopMatrix();
///river flow end

///hills in night start
///hill start
glPushMatrix();
    glTranslatef(-100,30,0);
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,520);
    glVertex2i(20,600);
     glColor3ub(34,139,34);
    glVertex2i(50,630);
    glVertex2i(120,725);
    glVertex2i(180,605);
    glVertex2i(200,520);
    glEnd();


     glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,520);
    glVertex2i(400,600);
    glVertex2i(450,700);
    glColor3ub(34,139,34);
    glVertex2i(550,640);
    glVertex2i(600,520);
    glEnd();


///hill
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,520);
    glVertex2i(200,580);
    glColor3ub(34,139,34);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,520);
    glEnd();


    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,520);
    glVertex2i(590,600);
    glVertex2i(630,680);
    glColor3ub(34,139,34);
    glVertex2i(700,600);
    glVertex2i(800,520);
    glEnd();

///hill
    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,520);
     glColor3ub(34,139,34);
    glVertex2i(1000,680);
    glVertex2i(1100,520);
    glEnd();

   glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,520);
    glVertex2i(780,620);
    glColor3ub(34,139,34);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,520);
    glEnd();

glTranslatef(100,-30,0);
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,550);
    glVertex2i(20,600);
     glColor3ub(34,139,34);
    glVertex2i(50,630);
    glVertex2i(120,725);
    glVertex2i(180,605);
    glVertex2i(200,550);
    glEnd();


     glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,550);
    glVertex2i(400,600);
    glVertex2i(450,700);
     glColor3ub(34,139,34);
    glVertex2i(550,640);
    glVertex2i(600,550);
    glEnd();


///hill
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,550);
    glVertex2i(200,580);
     glColor3ub(34,139,34);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,550);
    glEnd();


    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,550);
    glVertex2i(590,600);
    glVertex2i(630,680);
     glColor3ub(34,139,34);
    glVertex2i(700,600);
    glVertex2i(800,550);
    glEnd();

///hill
    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,550);
     glColor3ub(34,139,34);
    glVertex2i(1000,680);
    glVertex2i(1000,550);
    glEnd();

   glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,550);
    glVertex2i(780,620);
     glColor3ub(34,139,34);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,550);
    glEnd();

    glTranslatef(80,-20,0);
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,570);
    glVertex2i(20,600);
     glColor3ub(34,139,34);
    glVertex2i(50,630);
    glVertex2i(100,725);
    glVertex2i(180,605);
    glVertex2i(200,570);
    glEnd();


     glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,570);
    glVertex2i(450,700);
     glColor3ub(34,139,34);
    glVertex2i(550,640);
    glVertex2i(600,570);
    glEnd();


///hill
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,570);
    glVertex2i(200,590);
     glColor3ub(34,139,34);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,570);
    glEnd();


    glColor3ub(0,100,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,570);
    glVertex2i(590,600);
    glVertex2i(630,680);
    glColor3ub(34,139,34);
    glVertex2i(700,600);
    glVertex2i(800,570);
    glEnd();

///hill
    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,570);
    glColor3ub(85,107,47);
    glVertex2i(1000,680);
    glVertex2i(1000,570);
    glEnd();

   glColor3ub(0,100,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,570);
    glVertex2i(780,620);
    glColor3ub(34,139,34);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,570);
    glEnd();


    glPopMatrix();
///hills in night end



	 }
///
///
///
///
///
///
///
///
	else{


	glPushMatrix();
	glTranslatef(500,1000,0);
	glTranslatef(0,-_sun,0);
	if(_sun==380){
        night=true;


	}
	glBegin(GL_POLYGON);
    glColor3ub(218,165,32);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=52;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

		//grass
for(n = 0; n <=1000; ++n)
    {
for(m = 0; m <= 550; ++m) {
glPushMatrix();
    glTranslatef(n,m,0);
    glPushMatrix();
    glColor3ub(34,139,34);    //QUAD
    glBegin(GL_POLYGON);

    glVertex2i(3,5);
    glVertex2i(5,0);
	glVertex2i(3,9);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);

    glVertex2i(8,5);
    glVertex2i(10,0);
	glVertex2i(8,9);
	glVertex2i(5,0);
	glEnd();
	glBegin(GL_POLYGON);

    glVertex2i(5.8,5);
    glVertex2i(7.5,0);
	glVertex2i(5.8,9);
	glVertex2i(3,0);
	glEnd();

	glBegin(GL_LINE_STRIP);

    glVertex2i(3,5);
    glVertex2i(5,0);
	glVertex2i(3,9);
	glVertex2i(0,0);
	glVertex2i(3,5);
	glEnd();
	glBegin(GL_LINE_STRIP);

    glVertex2i(8,5);
    glVertex2i(10,0);
	glVertex2i(8,9);
	glVertex2i(5,0);
	glVertex2i(8,5);
	glEnd();
	glBegin(GL_LINE_STRIP);

    glVertex2i(5.8,5);
    glVertex2i(7.5,0);
	glVertex2i(5.8,9);
	glVertex2i(3,0);
	glVertex2i(5.8,5);
	glEnd();
	glPopMatrix();
glPopMatrix(); m+=8;
}
	n+=7;
	}
	///Cloud

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

//cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();



    glPopMatrix();
//end of cloud

//end of  grass
///river in day
glPushMatrix();
	glColor3ub(210,105,30);
	glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 135);
    glVertex2i(900, 145);
    glVertex2i(800, 135);
    glVertex2i(700, 145);
    glVertex2i(600, 135);
    glVertex2i(500, 145);
    glVertex2i(400, 135);
    glVertex2i(300, 145);
    glVertex2i(200, 135);
    glVertex2i(100, 145);
    glVertex2i(0, 135);
    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 125);
    glVertex2i(900, 135);
    glVertex2i(800, 125);
    glVertex2i(700, 135);
    glVertex2i(600, 125);
    glVertex2i(500, 135);
    glVertex2i(400, 125);
    glVertex2i(300, 135);
    glVertex2i(200, 125);
    glVertex2i(100, 135);
    glVertex2i(0, 125);
    glEnd();
    glColor3ub(30,144,200);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
	glVertex2i(1000, 0);
    glVertex2i(1000, 120);
    glVertex2i(900, 130);
    glVertex2i(800, 120);
    glVertex2i(700, 130);
    glVertex2i(600, 120);
    glVertex2i(500, 130);
    glVertex2i(400, 120);
    glVertex2i(300, 130);
    glVertex2i(200, 120);
    glVertex2i(100, 130);
    glVertex2i(0, 120);
    glEnd();


glPopMatrix();
///end river
///river flow
glPushMatrix();
glTranslatef(_run3,0,0);
    for(n =-10000; n <=10000; ++n)
    {
for(m = -5; m <= 120; ++m) {
glPushMatrix();
    glTranslatef(n,m,0);
    glPushMatrix();
    glColor3ub(173,216,230);
      //QUAD
    glBegin(GL_QUADS);

    glVertex2i(0,0);
    glVertex2i(10,0);
	glVertex2i(10,1);
	glVertex2i(0,1);
	glEnd();

	glPopMatrix();
glPopMatrix(); m+=30;
}
	n+=80;
	}
	glPopMatrix();
///river flow end
///hill start
glPushMatrix();
    glTranslatef(-100,30,0);
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,520);
    glVertex2i(20,600);
    glColor3ub(46,139,87);
    glVertex2i(50,630);
    glVertex2i(120,725);
    glVertex2i(180,605);
    glVertex2i(200,520);
    glEnd();


     glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,520);
    glVertex2i(400,600);
    glVertex2i(450,700);
    glColor3ub(46,139,87);
    glVertex2i(550,640);
    glVertex2i(600,520);
    glEnd();


///hill
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,520);
    glVertex2i(200,580);
    glColor3ub(46,139,87);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,520);
    glEnd();


    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,520);
    glVertex2i(590,600);
    glVertex2i(630,680);
    glColor3ub(46,139,87);
    glVertex2i(700,600);
    glVertex2i(800,520);
    glEnd();

///hill
    glColor3ub(0,128,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,520);
    glColor3ub(46,139,87);
    glVertex2i(1000,680);
    glVertex2i(1100,520);
    glEnd();

   glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,520);
    glVertex2i(780,620);
    glColor3ub(46,139,87);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,520);
    glEnd();

glTranslatef(100,-30,0);
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,550);
    glVertex2i(20,600);
    glColor3ub(46,139,87);
    glVertex2i(50,630);
    glVertex2i(120,725);
    glVertex2i(180,605);
    glVertex2i(200,550);
    glEnd();


glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,550);
    glVertex2i(400,600);
    glVertex2i(450,700);
    glColor3ub(46,139,87);
    glVertex2i(550,640);
    glVertex2i(600,550);
    glEnd();


///hill
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,550);
    glVertex2i(200,580);
    glColor3ub(46,139,87);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,550);
    glEnd();


    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,550);
    glVertex2i(590,600);
    glVertex2i(630,680);
    glColor3ub(46,139,87);
    glVertex2i(700,600);
    glVertex2i(800,550);
    glEnd();

///hill
    glColor3ub(0,128,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,550);
    glColor3ub(46,139,87);
    glVertex2i(1000,680);
    glVertex2i(1000,550);
    glEnd();

  glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,550);
    glVertex2i(780,620);
    glColor3ub(46,139,87);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,550);
    glEnd();

    glTranslatef(80,-20,0);
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//1 (from left to right)
    glVertex2i(-10,570);
    glVertex2i(20,600);
    glColor3ub(46,139,87);
    glVertex2i(50,630);
    glVertex2i(100,725);
    glVertex2i(180,605);
    glVertex2i(200,570);
    glEnd();


     glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//3
    glVertex2i(330,570);
    glVertex2i(450,700);
    glColor3ub(46,139,87);
    glVertex2i(550,640);
    glVertex2i(600,570);
    glEnd();


///hill
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //2
    glVertex2i(180,570);
    glVertex2i(200,590);
   glColor3ub(46,139,87);
    glVertex2i(250,700);
    glVertex2i(360,600);
    glVertex2i(390,570);
    glEnd();


    glColor3ub(0,128,0);
    glBegin(GL_POLYGON); //4
    glVertex2i(565,570);
    glVertex2i(590,600);
    glVertex2i(630,680);
    glColor3ub(46,139,87);
    glVertex2i(700,600);
    glVertex2i(800,570);
    glEnd();

///hill
glColor3ub(0,128,0);
    glBegin(GL_TRIANGLES);//6
    glVertex2i(800,570);
    glColor3ub(46,139,87);
    glVertex2i(1000,680);
    glVertex2i(1000,570);
    glEnd();

   glColor3ub(0,128,0);
    glBegin(GL_POLYGON);//5
    glVertex2i(700,570);
    glVertex2i(780,620);
    glColor3ub(46,139,87);
    glVertex2i(850,695);
    glVertex2i(910,610);
    glVertex2i(980,570);
    glEnd();


    glPopMatrix();


    ///////////////////////human kite
    glPushMatrix();
    glTranslatef(kite_position, -kite_position, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(200, 0, 0);
    glVertex2i(600, 730);
    glVertex2i(585, 700);
    glVertex2i(600, 660);
    glVertex2i(615, 700);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(585, 700);
    glVertex2i(580, 710);
    glVertex2i(580, 690);
    glVertex2i(615, 700);
    glVertex2i(620, 690);
    glVertex2i(620, 710);
    glVertex2i(600, 660);
    glVertex2i(595, 620);
    glVertex2i(605, 620);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2i(600, 730);
    glVertex2i(585, 700);
    glVertex2i(600, 660);
    glVertex2i(615, 700);
    glVertex2i(600, 730);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(585, 700);
    glVertex2i(580, 710);
    glVertex2i(580, 690);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(615, 700);
    glVertex2i(620, 690);
    glVertex2i(620, 710);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(600, 660);
    glVertex2i(595, 620);
    glVertex2i(605, 620);
    glVertex2i(600, 660);
    glEnd();
//    glBegin(GL_LINE_STRIP);
//    glVertex2i(600, 660);
//    glVertex2i(598, 658);
//    glVertex2i(596, 656);
//    glVertex2i(594, 654);
//    glVertex2i(592, 652);
//    glVertex2i(590, 650);
//    glVertex2i(589, 649);
//    glVertex2i(588, 648);
//    glVertex2i(589, 647);
//    glVertex2i(590, 646);
//    glVertex2i(592, 644);
//    glVertex2i(594, 642);
//    glVertex2i(596, 640);
//    glVertex2i(598, 638);
//    glVertex2i(598, 638);
//    glVertex2i(598, 638);
//    glVertex2i(598, 638);
//    glVertex2i(598, 638);
//
//    glEnd();
    glPopMatrix();


    //glTranslatef(0.0f, 0.4f, 0.0f);
    //int humanposx = 525, humanposy = 420;
    //Human Kite
    glBegin(GL_QUADS);
    glColor3ub(255, 236, 204);
    glVertex2i(525, 420);
    glVertex2i(520, 420);
    glVertex2i(520, 430);
    glVertex2i(525, 430);
    glVertex2i(523, 415);
    glVertex2i(520, 415);
    glVertex2i(520, 420);
    glVertex2i(523, 420);
    glVertex2i(530, 400);
    glVertex2i(527, 400);
    glVertex2i(527, 405);
    glVertex2i(530, 405);

    glVertex2i(520, 375);
    glVertex2i(523, 375);
    glVertex2i(523, 385);
    glVertex2i(520, 385);
    glVertex2i(524, 375);
    glVertex2i(527, 375);
    glVertex2i(527, 385);
    glVertex2i(524, 385);

    glColor3ub(0, 115, 138);
    glVertex2i(520, 400);
    glVertex2i(527, 400);
    glVertex2i(527, 415);
    glVertex2i(520, 415);
    glColor3ub(27, 28, 28);
    glVertex2i(520, 395);
    glVertex2i(527, 395);
    glVertex2i(527, 400);
    glVertex2i(520, 400);
    glVertex2i(520, 385);
    glVertex2i(523, 385);
    glVertex2i(523, 395);
    glVertex2i(520, 395);
    glVertex2i(525, 385);
    glVertex2i(527, 385);
    glVertex2i(527, 395);
    glVertex2i(520, 395);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(527, 435);
    glVertex2i(520, 435);
    glVertex2i(520, 426);
    glEnd();

  /*  //Human Train 1
    glPushMatrix();
    glTranslatef(_run,50,0);
    int human_train1x = 425;
    int human_train1y = 220; //525,420
    glBegin(GL_QUADS);
    glColor3ub(255, 236, 204);
    glVertex2i(human_train1x, human_train1y);
    glVertex2i(human_train1x-5, human_train1y);
    glVertex2i(human_train1x-5, human_train1y+10);
    glVertex2i(human_train1x, human_train1y+10);
    glVertex2i(human_train1x-1, human_train1y-5);
    glVertex2i(human_train1x-4, human_train1y-5);
    glVertex2i(human_train1x-4, human_train1y);
    glVertex2i(human_train1x-1, human_train1y);
//    glVertex2i(human_train1x+5, human_train1y-20);
//    glVertex2i(human_train1x+7, human_train1y-20);
//    glVertex2i(human_train1x+7, human_train1y-15);
//    glVertex2i(human_train1x+5, human_train1y-15);

    glVertex2i(human_train1x-5, human_train1y-45);
    glVertex2i(human_train1x-2, human_train1y-45);
    glVertex2i(human_train1x-2, human_train1y-35);
    glVertex2i(human_train1x-5, human_train1y-35);
    glVertex2i(human_train1x-1, human_train1y-45);
    glVertex2i(human_train1x+3, human_train1y-45);
    glVertex2i(human_train1x+3, human_train1y-35);
    glVertex2i(human_train1x-1, human_train1y-35);

    glColor3ub(225, 225, 0);
    glVertex2i(human_train1x-5, human_train1y-20);
    glVertex2i(human_train1x+2, human_train1y-20);
    glVertex2i(human_train1x+2, human_train1y-5);
    glVertex2i(human_train1x-5, human_train1y-5);

    glVertex2i(human_train1x-9, human_train1y-35);
    glVertex2i(human_train1x+6, human_train1y-35);
    glVertex2i(human_train1x+2, human_train1y-20);
    glVertex2i(human_train1x-5, human_train1y-20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(human_train1x+2, human_train1y+15);
    glVertex2i(human_train1x-5, human_train1y+15);
    glVertex2i(human_train1x-5, human_train1y+6);
    glVertex2i(human_train1x-5, human_train1y+15);
    glVertex2i(human_train1x-9, human_train1y+14);
    glVertex2i(human_train1x-9, human_train1y+6);
    glEnd();

    //Human Train 2
    int human_train2x = 480;
    int human_train2y = 220; //525,420
    glBegin(GL_QUADS);
    glColor3ub(255, 236, 204);
    glVertex2i(human_train2x, human_train2y);
    glVertex2i(human_train2x-5, human_train2y);
    glVertex2i(human_train2x-5, human_train2y+10);
    glVertex2i(human_train2x, human_train2y+10);
    glVertex2i(human_train2x-1, human_train2y-5);
    glVertex2i(human_train2x-4, human_train2y-5);
    glVertex2i(human_train2x-4, human_train2y);
    glVertex2i(human_train2x-1, human_train2y);
    glVertex2i(human_train2x-5, human_train2y-45);
    glVertex2i(human_train2x-2, human_train2y-45);
    glVertex2i(human_train2x-2, human_train2y-35);
    glVertex2i(human_train2x-5, human_train2y-35);
    glVertex2i(human_train2x-1, human_train2y-45);
    glVertex2i(human_train2x+3, human_train2y-45);
    glVertex2i(human_train2x+3, human_train2y-35);
    glVertex2i(human_train2x-1, human_train2y-35);

    glColor3ub(225, 0, 225);
    glVertex2i(human_train2x-5, human_train2y-20);
    glVertex2i(human_train2x+2, human_train2y-20);
    glVertex2i(human_train2x+2, human_train2y-5);
    glVertex2i(human_train2x-5, human_train2y-5);

    glVertex2i(human_train2x-9, human_train2y-35);
    glVertex2i(human_train2x+6, human_train2y-35);
    glVertex2i(human_train2x+2, human_train2y-20);
    glVertex2i(human_train2x-5, human_train2y-20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(human_train2x+2, human_train2y+15);
    glVertex2i(human_train2x-5, human_train2y+15);
    glVertex2i(human_train2x-5, human_train2y+6);
    glVertex2i(human_train2x-5, human_train2y+15);
    glVertex2i(human_train2x-9, human_train2y+14);
    glVertex2i(human_train2x-9, human_train2y+6);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(20,20,200);
    glVertex2i(human_train2x+20, human_train2y+43);
    glVertex2i(human_train2x+15, human_train2y-2);
    glVertex2i(human_train2x+3, human_train2y-2);
    glVertex2i(human_train2x+3, human_train2y+33);
    glEnd();

    glPopMatrix(); */
    ///small tree above road
    glPushMatrix();
    glTranslatef(-100,0,0);
    for(z=0;z<=150;++z)
    {
    glTranslatef(10,0,0);
    glBegin(GL_POLYGON); // first small tree from left to right
    glColor3ub (50,205,50);
    glVertex2i(14,345);
    glVertex2i(16,356);
    glVertex2i(13,350);
    glVertex2i(12,361);
    glVertex2i(11,350);
    glVertex2i(9,356);
    glVertex2i(10,345);
    glEnd();
    }
    glPopMatrix();
    ///end of small tree
	}

glPopMatrix();
	//end of sun */



///big tree 1
glPushMatrix();
    glTranslatef(500,400,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(15, 65);
	glVertex2i(18, 70);
	glVertex2i(15, 85);
    glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-9, 85);
	glVertex2i(-12, 70);
	glVertex2i(-9, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();

glPopMatrix();
///end of big tree 1
///big tree 2
glPushMatrix();
    glTranslatef(450,440,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(15, 65);
	glVertex2i(18, 70);
	glVertex2i(15, 85);
	glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-9, 85);
	glVertex2i(-12, 70);
	glVertex2i(-9, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();

glPopMatrix();
///end of big tree 3
///big tree 1
glPushMatrix();
  glTranslatef(550,440,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(15, 65);
	glVertex2i(18, 70);
	glVertex2i(15, 85);
	glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-9, 85);
	glVertex2i(-12, 70);
	glVertex2i(-9, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();

glPopMatrix();
///end of big tree 3
///big tree 4
glPushMatrix();
  glTranslatef(235,440,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(13, 65);
	glVertex2i(15, 70);
	glVertex2i(13, 85);
	glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-7, 85);
	glVertex2i(-9, 70);
	glVertex2i(-7, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();

glPopMatrix();
///end of big tree 4
///big tree 5
glPushMatrix();
  glTranslatef(15,440,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(13, 65);
	glVertex2i(15, 70);
	glVertex2i(13, 85);
	glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-7, 85);
	glVertex2i(-9, 70);
	glVertex2i(-7, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();

glPopMatrix();
///end of big tree 5



///Mosque
glPushMatrix();
    glTranslatef(876,490,0);
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(250,235,215);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+50,y+100 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+50,y+100 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(250,235,215);
    glBegin(GL_QUADS);
    glVertex2i(0,100);
	glVertex2i(0,0);
	glVertex2i(120,0);
	glVertex2i(120,100);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(0,100);
	glVertex2i(0,0);
	glVertex2i(120,0);
	glVertex2i(120,100);
	glVertex2i(0,100);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(119,136,153);
    glBegin(GL_QUADS);
    glVertex2i(-2,0);
	glVertex2i(-2,-5);
	glVertex2i(122,-5);
	glVertex2i(122,0);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(-2,0);
	glVertex2i(-2,-5);
	glVertex2i(122,-5);
	glVertex2i(122,0);
	glVertex2i(-2,0);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(119,136,153);
    glBegin(GL_QUADS);
    glVertex2i(-2,100);
	glVertex2i(-2,95);
	glVertex2i(122,95);
	glVertex2i(122,100);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(-2,100);
	glVertex2i(-2,95);
	glVertex2i(122,95);
	glVertex2i(122,100);
	glVertex2i(-2,100);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(199,21,133);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(119,136,153);
    glBegin(GL_QUADS);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glVertex2i(10,0);
	glEnd();
    glPopMatrix();
    glTranslatef(40, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(199,21,133);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(119,136,153);
    glBegin(GL_QUADS);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glVertex2i(10,0);
	glEnd();
    glPopMatrix();
    glTranslatef(40, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(199,21,133);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(119,136,153);
    glBegin(GL_QUADS);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(10,0);
	glVertex2i(30,0);
	glVertex2i(30,65);
	glVertex2i(10,65);
	glVertex2i(10,0);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex2i(10,-5);
	glVertex2i(30,-5);
	glVertex2i(30,-155);
	glVertex2i(10,-155);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(10,-5);
	glVertex2i(30,-5);
	glVertex2i(30,-155);
	glVertex2i(10,-155);
	glVertex2i(10,-5);
	glEnd();
    glPopMatrix();


    glTranslatef(5, 100, 0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(199,21,133);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=6;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=6;
		float x = r * cos(A);
		float y = r * sin(A)+20;
		glVertex2f(x+20,y+50 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(250,235,215);
    glBegin(GL_QUADS);
    glVertex2i(15,0);
	glVertex2i(25,0);
	glVertex2i(22,65);
	glVertex2i(18,65);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(15,0);
	glVertex2i(25,0);
	glVertex2i(22,65);
	glVertex2i(18,65);
	glVertex2i(15,0);
	glEnd();
    glPopMatrix();
    glTranslatef(0, 72, 0);
    glPushMatrix();
    glColor3ub(250,235,215);
    glBegin(GL_QUADS);
    glVertex2i(18,0);
	glVertex2i(22,0);
	glVertex2i(20,45);
	glVertex2i(20,45);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(18,0);
	glVertex2i(22,0);
	glVertex2i(20,45);
	glVertex2i(20,45);
	glVertex2i(18,0);
	glEnd();
    glPopMatrix();
glPopMatrix();
///end of Mosque

///Stall
glPushMatrix();
    glTranslatef(220, 80, 0.0);
    glColor3ub(51, 153, 255);

    ///body
    glColor3ub(149, 165, 166);
    glBegin(GL_QUADS);
    glVertex2i(550, 260);
    glVertex2i(550, 350);
	glVertex2i(650, 350);
	glVertex2i(650, 260);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(550, 260);
    glVertex2i(550, 350);
	glVertex2i(650, 350);
	glVertex2i(650, 260);
	glEnd();

    ///roof
	glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2i(540, 300);
	glVertex2i(560, 340);
	glVertex2i(640, 340);
	glVertex2i(660, 300);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(540, 300);
	glVertex2i(560, 340);
	glVertex2i(640, 340);
	glVertex2i(660, 300);
    glEnd();

    ///
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(560, 270);
	glVertex2i(560, 300);
	glVertex2i(640, 300);
	glVertex2i(640, 270);
    glEnd();


    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(560, 270);
	glVertex2i(560, 300);
	glVertex2i(640, 300);
	glVertex2i(640, 270);
    glEnd();

glPopMatrix();
///end of stall


///road

    glColor3ub(139,69,19);
	glBegin(GL_QUADS);
	glVertex2i(0,340);
	glVertex2i(1000,340);
	glVertex2i(1000,270);
	glVertex2i(0,270);
	glEnd();
	//glColor3ub(255, 255,255);
	glBegin(GL_QUADS);
	glVertex2i(0,306);
	glVertex2i(1000,306);
	glVertex2i(1000,304);
	glVertex2i(0,304);
	glEnd();

	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2i(0,270);
	glVertex2i(1000,270);
	glVertex2i(1000,265);
	glVertex2i(0,265);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(0,345);
	glVertex2i(1000,345);
	glVertex2i(1000,340);
	glVertex2i(0,340);
	glEnd();

	glColor3ub(139,69,19);
	glBegin(GL_QUADS);
	glVertex2i(750,460);
	glVertex2i(770,460);
	glVertex2i(770,320);
	glVertex2i(750,320);
	glEnd();
//	glColor3ub(255, 255,255);
	glBegin(GL_QUADS);
	glVertex2i(759.5,460);
	glVertex2i(760.5,460);
	glVertex2i(760.5,306);
	glVertex2i(759.5,306);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2i(750,460);
	glVertex2i(748,460);
	glVertex2i(748,345);
	glVertex2i(750,345);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(772,460);
	glVertex2i(770,640);
	glVertex2i(770,345);
	glVertex2i(772,345);
	glEnd();

	///1st CART

    glPushMatrix();
	glTranslatef(_run1, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(40, 80, 0.0);

    glPushMatrix();
    glTranslatef(30, 220, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


///box of 1st CART
	glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
	glVertex2i(8,230);
	glVertex2i(60,230);
	glVertex2i(56,250);
	glVertex2i(45,260);
	glVertex2i(35,268);
	glColor3ub(218,165,32);
    glVertex2i(30,270);
    glVertex2i(25,268);
	glVertex2i(20,260);
	glVertex2i(15,255);
    glVertex2i(10,235);
    glEnd();
    glColor3ub(25,25,112);
	glBegin(GL_LINES);
	glVertex2i(20,220);
	glVertex2i(40,220);
	glVertex2i(30,230);
	glVertex2i(30,210);
	glVertex2i(37,227);
    glVertex2i(23,213);
    glVertex2i(37,213);
    glVertex2i(23,227);

    glVertex2i(5,230);
    glVertex2i(100,230);
    glVertex2i(100,230);
    glVertex2i(100,232);
    glVertex2i(100,232);
    glVertex2i(5,232);

    glVertex2i(7,232);
    glVertex2i(7,262);
    glVertex2i(17,232);
    glVertex2i(17,262);
    glVertex2i(27,232);
    glVertex2i(27,262);
    glVertex2i(37,232);
    glVertex2i(37,262);

    glVertex2i(47,232);
    glVertex2i(47,262);
    glVertex2i(57,232);
    glVertex2i(57,262);
    glVertex2i(7,242);
    glVertex2i(59,242);
    glVertex2i(7,252);
    glVertex2i(59,252);
    glVertex2i(99,233);
    glVertex2i(97,245);
    glVertex2i(101,233);
    glVertex2i(103,245);
	glEnd();


///COW of 1st CART
	glColor3ub(238,232,170);
	glBegin(GL_QUADS);
    glVertex2i(93,230);
    glVertex2i(60,230);
    glVertex2i(60,220);
    glVertex2i(93,220);
    glBegin(GL_QUADS);
    glVertex2i(60,220);
    glVertex2i(60,210);
    glVertex2i(63,210);
    glVertex2i(63,220);
    glVertex2i(65,220);
    glVertex2i(65,210);
    glVertex2i(68,210);
    glVertex2i(68,220);
    glVertex2i(85,220);
    glVertex2i(85,210);
    glVertex2i(88,210);
    glVertex2i(88,220);
    glVertex2i(90,220);
    glVertex2i(90,210);
    glVertex2i(93,210);
    glVertex2i(93,220);
    glVertex2i(97,230);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(85,230);
    glVertex2i(90,230);
    glVertex2i(88,240);
    glVertex2i(85,230);
    glBegin(GL_QUADS);
    glVertex2i(98,233);
    glVertex2i(105,228);
    glVertex2i(104,225);
    glVertex2i(98,225);
    glBegin(GL_QUADS);
    glVertex2i(93,230);
    glVertex2i(98,230);
    glVertex2i(98,225);
    glVertex2i(93,220);
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(98,232);
    glVertex2i(97,245);
    glVertex2i(97.5,248);
    glVertex2i(100,230);
    glBegin(GL_QUADS);
    glVertex2i(100,232);
    glVertex2i(103,245);
    glVertex2i(103.5,248);
    glVertex2i(101,230);
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(99,228);
    glVertex2i(101,228);
    glVertex2i(101,229);
    glVertex2i(99,229);
    glBegin(GL_QUADS);
    glVertex2i(60,210);
    glVertex2i(63,210);
    glVertex2i(63,205);
    glVertex2i(60,205);
    glBegin(GL_QUADS);
    glVertex2i(65,210);
    glVertex2i(68,210);
    glVertex2i(68,205);
    glVertex2i(65,205);
    glBegin(GL_QUADS);
    glVertex2i(85,210);
    glVertex2i(85,205);
    glVertex2i(88,205);
    glVertex2i(88,210);
    glBegin(GL_QUADS);
    glVertex2i(90,210);
    glVertex2i(90,205);
    glVertex2i(93,205);
    glVertex2i(93,210);
    glEnd();


	glEnd();

    glPopMatrix();
///End of COW of 1st Cart

///2nd CART
    glPushMatrix();
    glTranslatef(200, 90, 0.0);

    glPushMatrix();
    glTranslatef(30, 220, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


///box of 2nd CART
    glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
	glVertex2i(8,230);
	glVertex2i(60,230);
	glVertex2i(56,250);
	glVertex2i(45,260);
	glVertex2i(35,268);
	glColor3ub(218,165,32);
    glVertex2i(30,270);
    glVertex2i(25,268);
	glVertex2i(20,260);
	glVertex2i(15,255);
    glVertex2i(10,235);
    glEnd();
	glColor3ub(242, 242, 237);
	glBegin(GL_LINES);
	glVertex2i(20,220);
	glVertex2i(40,220);
	glVertex2i(30,230);
	glVertex2i(30,210);
	glVertex2i(37,227);
    glVertex2i(23,213);
    glVertex2i(37,213);
    glVertex2i(23,227);

    glVertex2i(5,230);
    glVertex2i(100,230);
    glVertex2i(100,230);
    glVertex2i(100,232);
    glVertex2i(100,232);
    glVertex2i(5,232);

    glVertex2i(7,232);
    glVertex2i(7,262);
    glVertex2i(17,232);
    glVertex2i(17,262);
    glVertex2i(27,232);
    glVertex2i(27,262);
    glVertex2i(37,232);
    glVertex2i(37,262);

    glVertex2i(47,232);
    glVertex2i(47,262);
    glVertex2i(57,232);
    glVertex2i(57,262);
    glVertex2i(7,242);
    glVertex2i(59,242);
    glVertex2i(7,252);
    glVertex2i(59,252);
    glVertex2i(99,233);
    glVertex2i(97,245);
    glVertex2i(101,233);
    glVertex2i(103,245);
	glEnd();


///COW of 2nd CART
	glColor3ub(210,105,30);
	glBegin(GL_QUADS);
    glVertex2i(93,230);
    glVertex2i(60,230);
    glVertex2i(60,220);
    glVertex2i(93,220);
    glBegin(GL_QUADS);
    glVertex2i(60,220);
    glVertex2i(60,210);
    glVertex2i(63,210);
    glVertex2i(63,220);
    glVertex2i(65,220);
    glVertex2i(65,210);
    glVertex2i(68,210);
    glVertex2i(68,220);
    glVertex2i(85,220);
    glVertex2i(85,210);
    glVertex2i(88,210);
    glVertex2i(88,220);
    glVertex2i(90,220);
    glVertex2i(90,210);
    glVertex2i(93,210);
    glVertex2i(93,220);
    glVertex2i(97,230);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(85,230);
    glVertex2i(90,230);
    glVertex2i(88,240);
    glVertex2i(85,230);
    glBegin(GL_QUADS);
    glVertex2i(98,233);
    glVertex2i(105,228);
    glVertex2i(104,225);
    glVertex2i(98,225);
    glBegin(GL_QUADS);
    glVertex2i(93,230);
    glVertex2i(98,230);
    glVertex2i(98,225);
    glVertex2i(93,220);
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(98,232);
    glVertex2i(97,245);
    glVertex2i(97.5,248);
    glVertex2i(100,230);
    glBegin(GL_QUADS);
    glVertex2i(100,232);
    glVertex2i(103,245);
    glVertex2i(103.5,248);
    glVertex2i(101,230);
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(99,228);
    glVertex2i(101,228);
    glVertex2i(101,229);
    glVertex2i(99,229);
    glBegin(GL_QUADS);
    glVertex2i(60,210);
    glVertex2i(63,210);
    glVertex2i(63,205);
    glVertex2i(60,205);
    glBegin(GL_QUADS);
    glVertex2i(65,210);
    glVertex2i(68,210);
    glVertex2i(68,205);
    glVertex2i(65,205);
    glBegin(GL_QUADS);
    glVertex2i(85,210);
    glVertex2i(85,205);
    glVertex2i(88,205);
    glVertex2i(88,210);
    glBegin(GL_QUADS);
    glVertex2i(90,210);
    glVertex2i(90,205);
    glVertex2i(93,205);
    glVertex2i(93,210);
    glEnd();

    glPopMatrix();

    glPopMatrix();

///End of COW of 2nd Cart

///truck
glPushMatrix();
glTranslatef(_run8,0,0);

glPushMatrix();
glTranslatef(-20,0,0);
    glTranslatef(130,290,0);
    glColor3ub(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(0,-3);
    glVertex2i(60,-3);
    glVertex2i(60,10);
    glVertex2i(0,10);
    glEnd();
    glColor3ub(255,215,0);
    glBegin(GL_QUADS);
    glVertex2i(60,-10);
    glVertex2i(60,40);
    glVertex2i(70,40);
    glVertex2i(90,-10);
    glEnd();
    glColor3ub(65,105,225);
    glBegin(GL_QUADS);
    glVertex2i(63,10);
    glVertex2i(63,35);
    glVertex2i(70.5,35);
    glVertex2i(80,10);
    glEnd();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+20,y-7 );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+72,y-5 );
	}
	glEnd();
   glPopMatrix();
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(176,196,222);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=7;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+20,y-7 );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(176,196,222);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=7;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+72,y-5 );
	}
	glEnd();
   glPopMatrix();
    glTranslatef(-130,-290,0);
    glTranslatef(130,70,0);
	glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
	glVertex2i(8,230);
	glVertex2i(60,230);
	glVertex2i(56,250);
	glVertex2i(45,260);
	glVertex2i(35,268);
	glColor3ub(218,165,32);
    glVertex2i(30,270);
    glVertex2i(25,268);
	glVertex2i(20,260);
	glVertex2i(15,255);
    glVertex2i(10,235);
    glEnd();
glPopMatrix();
glPopMatrix();
///end of truck

///big tree above train
glPushMatrix();
for(int l=0;l<=1000;++l)
    {


///big tree 6
glPushMatrix();
    glTranslatef(l,0,0);
    glTranslatef(90,220,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(15, 65);
	glVertex2i(18, 70);
	glVertex2i(15, 85);
    glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-9, 85);
	glVertex2i(-12, 70);
	glVertex2i(-9, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 56, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(128,128,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(6, 60, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(-3, 65, 0.0);
    glBegin(GL_POLYGON);
   // glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(9, 63, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(3, 60, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(139,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(-2, 58, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(-1, 65, 0.0);
    glBegin(GL_POLYGON);
   // glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(5, 63, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


glPopMatrix();
l+=150;
///end of big tree above

}
glPopMatrix();

//rail line
    glColor3ub(139,69,19);
	glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(0,205);
    glVertex2i(1000,205);
    glVertex2i(1000,180);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,202);
    glVertex2i(1000,202);
    glVertex2i(1000,205);
    glVertex2i(0,205);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(1000,180);
    glVertex2i(1000,184);
    glVertex2i(0,184);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    float j;
    for(j=0;j<=1000;j+=20) //rail line
   {
        glVertex2i(10+j,180);
        glVertex2i(15+j,205);

    }
    glEnd();



    //TREE 2

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(1400, 500, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 3

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(-400, 550, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 4

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(250, 600, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();

    //tree 5

    glPushMatrix();

    glTranslatef(0, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 6

    glPushMatrix();

    glTranslatef(150, 420, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 7

    glPushMatrix();

    glTranslatef(-50, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 8

    glPushMatrix();

    glTranslatef(80, 420, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();


    //tree 9

    glPushMatrix();

    glTranslatef(780, 415, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();

// tree flowers
    glPushMatrix();

    glTranslatef(7,123, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();

    //flower 2
    glPushMatrix();

    glTranslatef(32,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();



    glPopMatrix();

    ///flowers 3
    glPushMatrix();

    glTranslatef(58,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

     ///flowers 4
    glPushMatrix();

    glTranslatef(212,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
     ///flowers 5
    glPushMatrix();

    glTranslatef(244,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
///flowers 6
    glPushMatrix();

    glTranslatef(276,0, 0.0);
      /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 7
    glPushMatrix();

    glTranslatef(539,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 8
    glPushMatrix();

    glTranslatef(566,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 9
    glPushMatrix();

    glTranslatef(590,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
///flowers 10
    glPushMatrix();

    glTranslatef(614,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 11
    glPushMatrix();

    glTranslatef(745,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 12
    glPushMatrix();

    glTranslatef(764,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 13
    glPushMatrix();

    glTranslatef(783,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 14
    glPushMatrix();

    glTranslatef(801,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 15
    glPushMatrix();

    glTranslatef(915,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
        ///flowers 16
    glPushMatrix();

    glTranslatef(931,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 17
    glPushMatrix();

    glTranslatef(947,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 18
    glPushMatrix();

    glTranslatef(963,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    ///flowers 19
    glPushMatrix();

    glTranslatef(979,0, 0.0);
  /*  glColor3ub(128,255,0);
    glBegin(GL_QUADS);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(3,0);
    glVertex2i(7,0);
	glVertex2i(6, 40);
	glVertex2i(4,40);
	glVertex2i(3,0);
	glEnd(); */
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(154,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+5,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+42 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+10,y+42 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+47 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+47 );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+8,y+37 );
	}
	glEnd();
    glPopMatrix();
        glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+3,y+37 );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();











    glPopMatrix();




///river



    glPushMatrix();

    glColor3ub (85,107,47);
    glBegin(GL_POLYGON); // green small  design left to right 1
    glVertex2i(16,140);
	glVertex2i(21,168);
	glVertex2i(14,150);
    glVertex2i(12,170);
    glVertex2i(9.2,150);
    glVertex2i(1,168);
    glVertex2i(5,140);
    glEnd();

    //glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 2
    glVertex2i(48,140);
	glVertex2i(53,168);
	glVertex2i(46,150);
    glVertex2i(44,170);
    glVertex2i(41,150);
    glVertex2i(33,168);
    glVertex2i(37,140);
    glEnd();

   // glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 3
    glVertex2i(74,140);
	glVertex2i(79,168);
	glVertex2i(72,150);
    glVertex2i(70,170);
    glVertex2i(67,150);
    glVertex2i(59,168);
    glVertex2i(63,140);
    glEnd();

    glColor3ub (128,128,0);
    glBegin(GL_POLYGON); // green small  design left to right  4
    glVertex2i(228,140);
	glVertex2i(233.75,168);
	glVertex2i(226.75,150);
    glVertex2i(224.9,170);
    glVertex2i(221.2,150);
    glVertex2i(213,168);
    glVertex2i(217,140);
    glEnd();

   // glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 5
    glVertex2i(260,140);
	glVertex2i(265.75,168);
	glVertex2i(258.75,150);
    glVertex2i(256.9,170);
    glVertex2i(253.2,150);
    glVertex2i(245,168);
    glVertex2i(249,140);
    glEnd();

  //  glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 6
    glVertex2i(292,140);
	glVertex2i(297.75,168);
	glVertex2i(290.75,150);
    glVertex2i(288.9,170);
    glVertex2i(285.2,150);
    glVertex2i(272,168);
    glVertex2i(281,140);
    glEnd();

    glColor3ub (85,107,47);
    glBegin(GL_POLYGON); // green small  design left to right 7
    glVertex2i(558,140);
	glVertex2i(563,168);
	glVertex2i(556,150);
    glVertex2i(554,170);
    glVertex2i(551,150);
    glVertex2i(543,168);
    glVertex2i(547,140);
    glEnd();


   // glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 8
    glVertex2i(582,140);
	glVertex2i(587,168);
	glVertex2i(580,150);
    glVertex2i(578,170);
    glVertex2i(575,150);
    glVertex2i(567,168);
    glVertex2i(571,140);
    glEnd();

  //  glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 9
    glVertex2i(606,140);
	glVertex2i(611,168);
	glVertex2i(604,150);
    glVertex2i(602,170);
    glVertex2i(599,150);
    glVertex2i(591,168);
    glVertex2i(595,140);
    glEnd();

 //   glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 10
    glVertex2i(630,140);
	glVertex2i(635,168);
	glVertex2i(628,150);
    glVertex2i(626,170);
    glVertex2i(623,150);
    glVertex2i(615,168);
    glVertex2i(619,140);
    glEnd();


    glColor3ub (128,128,0);
    glBegin(GL_POLYGON); // green small  design left to right 11
    glVertex2i(761,140);
	glVertex2i(766,168);
	glVertex2i(754,150);
    glVertex2i(752,170);
    glVertex2i(749,150);
    glVertex2i(741,168);
    glVertex2i(750,140);
    glEnd();

//    glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 12
    glVertex2i(780,140);
	glVertex2i(785,168);
	glVertex2i(778,150);
    glVertex2i(776,170);
    glVertex2i(773,150);
    glVertex2i(765,168);
    glVertex2i(769,140);
    glEnd();

 //    glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 13
    glVertex2i(799,140);
	glVertex2i(804,168);
	glVertex2i(797,150);
    glVertex2i(795,170);
    glVertex2i(792,150);
    glVertex2i(784,168);
    glVertex2i(788,140);
    glEnd();

//    glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 14
    glVertex2i(817,140);
	glVertex2i(822,168);
	glVertex2i(815,150);
    glVertex2i(813,170);
    glVertex2i(810,150);
    glVertex2i(802,168);
    glVertex2i(806,140);
    glEnd();

 //   glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 15
    glVertex2i(931,140);
	glVertex2i(936,168);
	glVertex2i(929,150);
    glVertex2i(927,170);
    glVertex2i(924,150);
    glVertex2i(916,168);
    glVertex2i(920,140);
    glEnd();

    glColor3ub (85,107,47);
    glBegin(GL_POLYGON); // green small  design left to right 16
    glVertex2i(947,140);
	glVertex2i(952,168);
	glVertex2i(945,150);
    glVertex2i(943,170);
    glVertex2i(940,150);
    glVertex2i(932,168);
    glVertex2i(936,140);
    glEnd();

  //  glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 17
    glVertex2i(963,140);
	glVertex2i(968,168);
	glVertex2i(961,150);
    glVertex2i(959,170);
    glVertex2i(956,150);
    glVertex2i(948,168);
    glVertex2i(952,140);
    glEnd();

  //  glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 18
    glVertex2i(979,140);
	glVertex2i(984,168);
	glVertex2i(977,150);
    glVertex2i(975,170);
    glVertex2i(972,150);
    glVertex2i(964,168);
    glVertex2i(968,140);
    glEnd();

 //   glColor3ub (60,179,113);
    glBegin(GL_POLYGON); // green small  design left to right 19
    glVertex2i(995,140);
	glVertex2i(1000,168);
	glVertex2i(993,150);
    glVertex2i(991,170);
    glVertex2i(988,150);
    glVertex2i(980,168);
    glVertex2i(984,140);
    glEnd();


    glPopMatrix();

     ///poddo ful
         glPushMatrix();
    ///poddo ful 1
    glTranslatef(-200,75, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 2
    glTranslatef(15,-5, 0.0);



    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 3
    glTranslatef(-30,0, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 4
    glTranslatef(15,-10, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	///poddo pata 1
	glTranslatef(-20,-20, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,-13, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(15,0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,7, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
	glPopMatrix();

    glPushMatrix();
    ///poddo ful 1
    glTranslatef(400,75, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 2
    glTranslatef(15,-5, 0.0);



    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 3
    glTranslatef(-30,0, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 4
    glTranslatef(15,-10, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	///poddo pata 1
	glTranslatef(-20,-20, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,-13, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(15,0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,7, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
	glPopMatrix();

    glPushMatrix();
    ///poddo ful 1
    glTranslatef(200,75, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 2
    glTranslatef(15,-5, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 3
    glTranslatef(-30,0, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 4
    glTranslatef(15,-10, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	///poddo pata 1
	glTranslatef(-20,-20, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,-13, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(15,0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,7, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
	glPopMatrix();
    glPushMatrix();
    ///poddo ful 1

    glTranslatef(-400,80, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 2
    glTranslatef(15,-5, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 3
    glTranslatef(-30,0, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 4
    glTranslatef(15,-10, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	///poddo pata 1
	glTranslatef(-20,-20, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,-13, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(15,0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,7, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
	glPopMatrix();

    glPushMatrix();
    ///poddo ful 1
    glTranslatef(0,70, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 2
    glTranslatef(15,-5, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 3
    glTranslatef(-30,0, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();
///poddo ful 4
    glTranslatef(15,-10, 0.0);


    glPushMatrix();
	glTranslatef(500,70, 0.0);
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(-1,0);
    glVertex2i(-1,-15);
	glVertex2i(1,-15);
	glVertex2i(1,-0);
	glEnd();
    glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(500,80, 0.0);
 //   glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);

	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(487,80, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(6,-3);
	glVertex2i(12, 0);
	glVertex2i(6,3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,82, 0.0);
    //glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(500,65, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-2.5,7);
	glVertex2i(0,0);
	glVertex2i(2.5,7);
	glVertex2i(0,16);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,88, 0.0);
   // glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,5);
    glVertex2i(4,-2.5);
	glVertex2i(12,-9);
	glVertex2i(5,3);
	glEnd();
   // glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(489,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(1,-5);
    glVertex2i(4,2.5);
	glVertex2i(12,9);
	glVertex2i(5,-3);
	glEnd();
    //glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,89, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,5);
    glVertex2i(-4,-2.5);
	glVertex2i(-12,-9);
	glVertex2i(-5,3);
	glEnd();
  //  glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(511,72, 0.0);
  //  glColor3ub(220,20,60);
    glBegin(GL_POLYGON);
    glVertex2i(-1,-5);
    glVertex2i(-4,2.5);
	glVertex2i(-12,9);
	glVertex2i(-5,-3);
	glEnd();
 //   glColor3ub(220,20,60);
	glBegin(GL_LINE_STRIP);
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,165,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	///poddo pata 1
	glTranslatef(-20,-20, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,-13, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(15,0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
	glTranslatef(10,7, 0);

    glBegin(GL_POLYGON);
    glColor3ub(85,107,47);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+500,y+80 );
	}
	glEnd();
    glPopMatrix();









	glPopMatrix();
	//end of podddo ful


    ///Left Moving Boat
    glPushMatrix();
    glTranslatef(-_run,0.0, 0.0);


    ///boat 2
    glPushMatrix();
    glTranslatef(200, 35, 0);



    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex2i(190, 60);
    glVertex2i(110, 60);
    glColor3ub(0,0,205);
    glVertex2i(130, 40);
    glVertex2i(170, 40);

    glEnd();

    glColor3ub(46,139,87);
    glBegin(GL_QUADS);
    glVertex2i(150, 80);
    glVertex2i(170, 80);
    glColor3ub (47,79,79);
    glVertex2i(170, 60);
    glVertex2i(150, 60);
    glEnd();
//boat pall bamboo
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(160, 115);
    glVertex2i(162, 115);
    glVertex2i(162, 80);
    glVertex2i(160, 80);
    glEnd();
    //pall pakha

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(145, 95);
    glVertex2i(148,80);
    glVertex2i(158,80);
    glVertex2i(156, 95);
    glColor3ub(135,206,250);
    glVertex2i(158,115);
    glVertex2i(150, 115);
    glEnd();
    //boat man 2

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(112, 75);
    glVertex2i(117, 75);
    glVertex2i(118, 60);
    glVertex2i(112, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(102, 42);
    glVertex2i(102, 40);
    glVertex2i(132, 82);
    glVertex2i(132, 83);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(115, 72);
    glVertex2i(115, 70);
    glVertex2i(122, 72);
    glVertex2i(122, 73);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(113, 80);
    glVertex2i(115, 80);
    glVertex2i(115, 75);
    glVertex2i(113, 75);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(111,80);
	glVertex2i(117, 80);
    glVertex2i(115,83);
    glVertex2i(114,88);
    glVertex2i(113,83);
    glVertex2i(111,80);
	glEnd();

    glPopMatrix();


    glPopMatrix();




    ///Right Moving Boat
    glPushMatrix();
	glTranslatef(_run, 0.0, 0.0);

    ///boat 1
    glPushMatrix();
    glColor3ub(169,69,19);
    glBegin(GL_QUADS);
    glVertex2i(190, 60);
    glVertex2i(110, 60);
    glColor3ub(0,0,205);
    glVertex2i(130, 40);
    glVertex2i(170, 40);



	glEnd();

	glColor3ub(138,43,226);
    glBegin(GL_QUADS);
    glVertex2i(130, 80);
    glVertex2i(150, 80);
    glColor3ub(75,0,130);
	glVertex2i(150, 60);
	glVertex2i(130, 60);
	glEnd();

    //boat man 1

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(112, 75);
    glVertex2i(117, 75);
    glVertex2i(118, 60);
    glVertex2i(112, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(102, 42);
    glVertex2i(102, 40);
    glVertex2i(132, 82);
    glVertex2i(132, 83);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(115, 72);
    glVertex2i(115, 70);
    glVertex2i(122, 72);
    glVertex2i(122, 73);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(113, 80);
    glVertex2i(115, 80);
    glVertex2i(115, 75);
    glVertex2i(113, 75);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(111,80);
	glVertex2i(117, 80);
    glVertex2i(115,83);
    glVertex2i(114,88);
    glVertex2i(113,83);
    glVertex2i(111,80);
	glEnd();


    glPopMatrix();

    ///boat 2
    glPushMatrix();
    glTranslatef(500, 15, 0);


    glColor3ub(199,21,133);
    glBegin(GL_QUADS);
    glVertex2i(110, 60);
	glVertex2i(190, 60);
	glColor3ub(0,0,0);
	glVertex2i(170, 40);
	glVertex2i(130, 40);
	glEnd();

	glColor3ub(169,169,169);
    glBegin(GL_QUADS);
    glVertex2i(130, 80);
    glVertex2i(150, 80);
    glColor3ub(105,105,105);
	glVertex2i(150, 60);
	glVertex2i(130, 60);
	glEnd();
	//boat 1 pall bamboo
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(140, 115);
    glVertex2i(142, 115);
    glVertex2i(142, 80);
    glVertex2i(140, 80);
    glEnd();
    //pall 1 pakha

    glColor3ub(199,21,133);
    glBegin(GL_POLYGON);
    glVertex2i(144,95);
    glVertex2i(142, 80);
    glVertex2i(152, 80);

    glVertex2i(155, 95);
    glVertex2i(150,115);
    glVertex2i(142, 115);

    glEnd();
    //boat man 1

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(112, 75);
    glVertex2i(117, 75);
    glVertex2i(118, 60);
    glVertex2i(112, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(102, 42);
    glVertex2i(102, 40);
    glVertex2i(132, 82);
    glVertex2i(132, 83);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(115, 72);
    glVertex2i(115, 70);
    glVertex2i(122, 72);
    glVertex2i(122, 73);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(113, 80);
    glVertex2i(115, 80);
    glVertex2i(115, 75);
    glVertex2i(113, 75);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(111,80);
	glVertex2i(117, 80);
    glVertex2i(115,83);
    glVertex2i(114,88);
    glVertex2i(113,83);
    glVertex2i(111,80);
	glEnd();


    glPopMatrix();

      ///Man boat 3

    glPushMatrix();
    glTranslatef(300, 0, 0);


    glColor3ub(184,134,11);
    glBegin(GL_QUADS);
    glVertex2i(130, 40);
    glVertex2i(110, 55);
	glVertex2i(150, 55);
	glVertex2i(170, 40);
	glEnd();


	glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(152,75);
	glVertex2i(158, 75);
    glVertex2i(156,78);
    glVertex2i(155,85);
    glVertex2i(154,78);
    glVertex2i(152,75);
	glEnd();
	glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(145,90);
	glVertex2i(147, 90);
    glVertex2i(175,38);
    glVertex2i(173,38);
	glEnd();

	glColor3ub(255,228,181);
    glBegin(GL_QUADS);
    glVertex2i(152, 70);
	glVertex2i(158, 70);
    glVertex2i(158,60);
    glVertex2i(152, 60);
	glEnd();
	glColor3ub(112,128,144);
    glBegin(GL_QUADS);
    glVertex2i(148, 45);
	glVertex2i(163, 45);
    glVertex2i(158,60);
    glVertex2i(152, 60);
	glEnd();

	glColor3ub(255,228,181);
    glBegin(GL_QUADS);
    glVertex2i(156, 45);
	glVertex2i(158, 45);
    glVertex2i(158,40);
    glVertex2i(156, 40);
	glEnd();
	glBegin(GL_QUADS);
    glVertex2i(152, 45);
	glVertex2i(154, 45);
    glVertex2i(154,40);
    glVertex2i(152, 40);
	glEnd();
	glColor3ub(244,164,96);
    glBegin(GL_QUADS);
    glVertex2i(156, 42);
	glVertex2i(160, 42);
    glVertex2i(160,40);
    glVertex2i(156, 40);
	glEnd();
	glBegin(GL_QUADS);
    glVertex2i(150, 42);
	glVertex2i(154, 42);
    glVertex2i(154,40);
    glVertex2i(150, 40);
	glEnd();
	glColor3ub(255,228,181);
    glBegin(GL_QUADS);
    glVertex2i(154,75);
	glVertex2i(156, 75);
    glVertex2i(156,70);
    glVertex2i(154,70);
	glEnd();
	//boat 1 pall bamboo
    glColor3ub(184,134,11);
    glBegin(GL_QUADS);
    glVertex2i(140, 115);
    glVertex2i(142, 115);
    glVertex2i(142, 50);
    glVertex2i(140, 50);
    glEnd();
    //pall 1 pakha

    glColor3ub(0,100,0);
    glBegin(GL_POLYGON);
    glVertex2i(144,95);
    glVertex2i(142, 70);
    glVertex2i(152, 70);
    glColor3ub(50,205,50);
    glVertex2i(155, 95);
    glVertex2i(150,115);
    glVertex2i(142, 115);


    glEnd();

    glPopMatrix();
    glPopMatrix();

    ///Left Moving Boat
    glPushMatrix();
	glTranslatef(-_run, 0.0, 0.0);

      ///boat 3

    glPushMatrix();
    glTranslatef(700, -30, 0);


    glColor3ub(199,21,133);
    glBegin(GL_QUADS);
    glVertex2i(100, 65);
	glVertex2i(220, 65);
	glColor3ub(0,0,0);
	glVertex2i(190, 40);
	glVertex2i(130, 40);
	glEnd();

	glColor3ub(178,34,34);
    glBegin(GL_QUADS);
    glVertex2i(190, 88);
    glVertex2i(150, 88);
    glColor3ub(128,0,0);
	glVertex2i(150, 65);
	glVertex2i(190, 65);
	glEnd();
	//boat 1 pall bamboo
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(160, 140);
    glVertex2i(162, 140);
    glVertex2i(162, 88);
    glVertex2i(160, 88);
    glEnd();
    //pall 1 pakha

    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);
    glVertex2i(162,105);
    glVertex2i(205,105);
    glVertex2i(205,135);
    glVertex2i(162,135);

    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=6;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+183.5,y+120 );
	}
	glEnd();
    glPopMatrix();
    //boat man 1

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(112, 75);
    glVertex2i(117, 75);
    glVertex2i(118, 65);
    glVertex2i(112, 65);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(102, 42);
    glVertex2i(102, 40);
    glVertex2i(132, 82);
    glVertex2i(132, 83);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2i(115, 72);
    glVertex2i(115, 70);
    glVertex2i(122, 72);
    glVertex2i(122, 73);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(113, 80);
    glVertex2i(115, 80);
    glVertex2i(115, 75);
    glVertex2i(113, 75);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(111,80);
	glVertex2i(117, 80);
    glVertex2i(115,83);
    glVertex2i(114,88);
    glVertex2i(113,83);
    glVertex2i(111,80);
	glEnd();


    glPopMatrix();


    glPopMatrix();

//End 4/16/2021




///FENCE

    glPushMatrix();
    glTranslatef(0, 10, 0.0);

    glColor3ub(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    ///backside
    glVertex2i(30, 400);
    glVertex2i(480, 400);

    glVertex2i(30, 415);
    glVertex2i(480, 415);

    glVertex2i(30, 430);
    glVertex2i(480, 430);

    ///leftside
    glVertex2i(30, 400);
    glVertex2i(10, 350);

    glVertex2i(30, 415);
    glVertex2i(10, 365);

    glVertex2i(30, 430);
    glVertex2i(10, 380);

    ///rightside
    glVertex2i(500, 350);
    glVertex2i(480, 400);

    glVertex2i(500, 365);
    glVertex2i(480, 415);

    glVertex2i(500, 380);
    glVertex2i(480, 430);

    ///perpendicular fence
    ///backside
    int x = 30;
    for(int i = 0; i < 46; i++)
    {
         glVertex2i(x, 445);
        glVertex2i(x, 385);

        x = x + 10;
    }
    ///leftside
    glVertex2i(25, 430);
    glVertex2i(25, 370);

    glVertex2i(20, 423);
    glVertex2i(20, 363);

    glVertex2i(15, 412);
    glVertex2i(15, 352);

    glVertex2i(10, 403);
    glVertex2i(10, 343);

    ///rightside
    glVertex2i(485, 430);
    glVertex2i(485, 370);

    glVertex2i(490, 423);
    glVertex2i(490, 363);

    glVertex2i(495, 412);
    glVertex2i(495, 352);

    glVertex2i(500, 403);
    glVertex2i(500, 343);

    glEnd();
    glPopMatrix();

     ///small home
    glPushMatrix();
    glTranslatef(-20, 80, 0.0);

     glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

     glColor3ub(0, 123, 240);
     glBegin(GL_TRIANGLES);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(0, 0, 0);
     glBegin(GL_LINE_LOOP);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    ///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    glEnd();


    ///Window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

        glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

    ///Window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();

    glPopMatrix();



     ///small home2
    glPushMatrix();
    glTranslatef(200, 80, 0.0);

     glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(80, 310);
    glVertex2i(80, 390);
    glVertex2i(140, 390);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

     glColor3ub(0, 123, 240);
     glBegin(GL_TRIANGLES);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(0, 0, 0);
     glBegin(GL_LINE_LOOP);
     glVertex2i(80, 390);
     glVertex2i(110, 450);
     glVertex2i(140, 390);
     glEnd();

    glColor3ub(204, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(140, 390);
    glVertex2i(240, 390);
    glVertex2i(240, 310);
    glVertex2i(140, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(110, 450);
    glVertex2i(200, 450);
    glVertex2i(240, 390);
    glVertex2i(140, 390);
    //glPopMatrix();
    glEnd();

    ///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    //glPopMatrix();
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 310);
    glVertex2i(100, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 310);
    glEnd();


    ///Window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

        glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(160, 370);
    glVertex2i(180, 370);
    glVertex2i(180, 340);
    glVertex2i(160, 340);
    //glPopMatrix();
    glEnd();

    ///Window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(220, 370);
    glVertex2i(200, 370);
    glVertex2i(200, 340);
    glVertex2i(220, 340);
    glEnd();

    glPopMatrix();

     ///well

    glPushMatrix();
    glTranslatef(50, 110, 0.0);

    glColor3ub(51, 153, 255);
    glBegin(GL_POLYGON);
    glVertex2i(180, 300);
    glVertex2i(200, 290);
    glVertex2i(220, 290);
    glVertex2i(240, 300);
    glVertex2i(220, 310);
    glVertex2i(200, 310);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(180, 300);
    glVertex2i(200, 290);
    glVertex2i(220, 290);
    glVertex2i(240, 300);
    glVertex2i(220, 310);
    glVertex2i(200, 310);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(153, 102, 51);
    glVertex2i(180, 260);
    glVertex2i(200, 250);
    glVertex2i(220, 250);
    glVertex2i(240, 260);

    glVertex2i(240, 300);
    glVertex2i(220, 290);
    glVertex2i(200, 290);
     glVertex2i(180, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3ub(0, 0, 0);
    glVertex2i(180, 260);
    glVertex2i(200, 250);
    glVertex2i(220, 250);
    glVertex2i(240, 260);

    glVertex2i(240, 300);
    glVertex2i(220, 290);
    glVertex2i(200, 290);
     glVertex2i(180, 300);
    glEnd();

    ///Well's upper part
    glBegin(GL_LINE_STRIP);

    glColor3ub(0, 0, 0);
    glVertex2i(180, 300);
    glVertex2i(180, 340);
    glVertex2i(240, 340);
    glVertex2i(240, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex2i(200, 330);
    glVertex2i(200, 350);
    glVertex2i(220, 350);
    glVertex2i(220, 330);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3ub(0, 0, 0);
    glVertex2i(200, 330);
    glVertex2i(200, 350);
    glVertex2i(220, 350);
    glVertex2i(220, 330);
    glEnd();
    glPopMatrix();


    ///School

	 ///School
    glPushMatrix();
    glTranslatef(240, 180, 0);
    glScalef(0.80, 0.80, 0);

    /// Middle body
	glColor3ub(173, 151, 9);
    glBegin(GL_QUADS);
    glVertex2i(550, 350);
    glVertex2i(550, 525);
	glVertex2i(750, 525);
	glVertex2i(750, 350);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(550, 350);
    glVertex2i(550, 525);
	glVertex2i(750, 525);
	glVertex2i(750, 350);
	glEnd();

	///window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(570, 370);
	glVertex2i(620, 370);
	glVertex2i(620, 420);
	glVertex2i(570, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(570, 370);
	glVertex2i(620, 370);
	glVertex2i(620, 420);
	glVertex2i(570, 420);
    glEnd();

     /// 2nd window
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(680, 370);
	glVertex2i(730, 370);
	glVertex2i(730, 420);
	glVertex2i(680, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(680, 370);
	glVertex2i(730, 370);
	glVertex2i(730, 420);
	glVertex2i(680, 420);
    glEnd();

    ///3rd window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(680, 460);
	glVertex2i(730, 460);
	glVertex2i(730, 505);
	glVertex2i(680, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(680, 460);
	glVertex2i(730, 460);
	glVertex2i(730, 505);
	glVertex2i(680, 505);
    glEnd();

    ///4th window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(620, 460);
	glVertex2i(670, 460);
	glVertex2i(670, 505);
	glVertex2i(620, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
   glVertex2i(620, 460);
	glVertex2i(670, 460);
	glVertex2i(670, 505);
	glVertex2i(620, 505);
    glEnd();

    ///5th window
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(560, 460);
	glVertex2i(610, 460);
	glVertex2i(610, 505);
	glVertex2i(560, 505);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(560, 460);
	glVertex2i(610, 460);
	glVertex2i(610, 505);
	glVertex2i(560, 505);
    glEnd();

    ///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(635, 350);
	glVertex2i(665, 350);
	glVertex2i(665, 400);
	glVertex2i(635, 400);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(635, 350);
	glVertex2i(665, 350);
	glVertex2i(665, 400);
	glVertex2i(635, 400);
    glEnd();

    ///MIDDLE BODY UPPER
    glColor3ub(0, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2i(750, 525);
	glVertex2i(730, 550);
	glVertex2i(500, 550);
	glVertex2i(480, 525);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(750, 525);
	glVertex2i(730, 550);
	glVertex2i(500, 550);
	glVertex2i(480, 525);

    glEnd();


	///left body
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(420, 260);
    glVertex2i(520, 260);
	glVertex2i(520, 435);
	glVertex2i(420, 435);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(420, 260);
    glVertex2i(520, 260);
	glVertex2i(520, 435);
	glVertex2i(420, 435);
    glEnd();

    ///wINDOW
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(440, 280);
    glVertex2i(500, 280);
	glVertex2i(500, 330);
	glVertex2i(440, 330);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(440, 280);
    glVertex2i(500, 280);
	glVertex2i(500, 330);
	glVertex2i(440, 330);
    glEnd();

    ///wINDOW2
     glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(440, 370);
    glVertex2i(500, 370);
	glVertex2i(500, 420);
	glVertex2i(440, 420);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(440, 370);
    glVertex2i(500, 370);
	glVertex2i(500, 420);
	glVertex2i(440, 420);
    glEnd();


    ///LEFT BODY SIDE

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 260);
    glVertex2i(550, 350);
	glVertex2i(550, 525);
	glVertex2i(520, 435);
    glEnd();

     glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(520, 260);
    glVertex2i(550, 350);
	glVertex2i(550, 525);
	glVertex2i(520, 435);
    glEnd();

    ///LEFT SIDE UPPER PART
     glColor3ub(0, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2i(420, 435);
	glVertex2i(520, 435);
	glVertex2i(550, 525);
	glVertex2i(480, 525);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(420, 435);
	glVertex2i(520, 435);
	glVertex2i(550, 525);
	glVertex2i(480, 525);
    glEnd();

    ///DEVIDING FLOOR

     glColor3ub(0, 0, 0);
    glBegin(GL_LINES);

    ///LEFT BODY
    glVertex2i(420, 348);
    glVertex2i(520, 348);

    ///MAIN BODY
	glVertex2i(550, 438);
    glVertex2i(750, 438);

    ///LEFT BODY SIDE
	glVertex2i(520, 348);
	glVertex2i(550, 438);
    glEnd();



    glPopMatrix();


///Making of Rail Body
    ///Making the first carriage body (from left
    int carriagePosX = 25, carriagePosY = 207;

    glPushMatrix();
    glTranslatef(_ang_tri, 0.0, 0.0);
    glColor3ub(133, 129, 129);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX, carriagePosY);
    glVertex2i(carriagePosX+70, carriagePosY);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glVertex2i(carriagePosX, carriagePosY+50);
	glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+10, carriagePosY+25);
    glVertex2i(carriagePosX+20, carriagePosY+25);
	glVertex2i(carriagePosX+20, carriagePosY+40);
	glVertex2i(carriagePosX+10, carriagePosY+40);
	glEnd();

	glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+30, carriagePosY+25);
    glVertex2i(carriagePosX+40, carriagePosY+25);
	glVertex2i(carriagePosX+40, carriagePosY+40);
	glVertex2i(carriagePosX+30, carriagePosY+40);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+50, carriagePosY+25);
    glVertex2i(carriagePosX+60, carriagePosY+25);
	glVertex2i(carriagePosX+60, carriagePosY+40);
	glVertex2i(carriagePosX+50, carriagePosY+40);
	glEnd();

	glColor3ub(0, 0, 150);
	glBegin(GL_QUADS);
	glVertex2i(carriagePosX, carriagePosY+10);
    glVertex2i(carriagePosX+70, carriagePosY+10);
	glVertex2i(carriagePosX+70, carriagePosY+15);
	glVertex2i(carriagePosX, carriagePosY+15);
	glEnd();

    glColor3ub(61, 61, 61);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+70, carriagePosY);
    glVertex2i(carriagePosX+80, carriagePosY+10);
	glVertex2i(carriagePosX+80, carriagePosY+68);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glEnd();


	glColor3ub(95,95,95);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+1, carriagePosY+50);
    glVertex2i(carriagePosX+71, carriagePosY+50);
	glVertex2i(carriagePosX+80, carriagePosY+70);
	glVertex2i(carriagePosX+15, carriagePosY+70);
	glEnd();

	glPushMatrix();
    glTranslatef(carriagePosX+15, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(carriagePosX+55, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();


    ///Making second carriage body (from left)
    glPushMatrix();
    glTranslatef(75, 0, 0);

    glColor3ub(133, 129, 129);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX, carriagePosY);
    glVertex2i(carriagePosX+70, carriagePosY);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glVertex2i(carriagePosX, carriagePosY+50);
	glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+10, carriagePosY+25);
    glVertex2i(carriagePosX+20, carriagePosY+25);
	glVertex2i(carriagePosX+20, carriagePosY+40);
	glVertex2i(carriagePosX+10, carriagePosY+40);
	glEnd();

	glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+30, carriagePosY+25);
    glVertex2i(carriagePosX+40, carriagePosY+25);
	glVertex2i(carriagePosX+40, carriagePosY+40);
	glVertex2i(carriagePosX+30, carriagePosY+40);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+50, carriagePosY+25);
    glVertex2i(carriagePosX+60, carriagePosY+25);
	glVertex2i(carriagePosX+60, carriagePosY+40);
	glVertex2i(carriagePosX+50, carriagePosY+40);
	glEnd();

	glColor3ub(0, 0, 150);
	glBegin(GL_QUADS);
	glVertex2i(carriagePosX, carriagePosY+10);
    glVertex2i(carriagePosX+70, carriagePosY+10);
	glVertex2i(carriagePosX+70, carriagePosY+15);
	glVertex2i(carriagePosX, carriagePosY+15);
	glEnd();

    glColor3ub(61, 61, 61);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+70, carriagePosY);
    glVertex2i(carriagePosX+80, carriagePosY+10);
	glVertex2i(carriagePosX+80, carriagePosY+68);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glEnd();


	glColor3ub(95,95,95);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+1, carriagePosY+50);
    glVertex2i(carriagePosX+71, carriagePosY+50);
	glVertex2i(carriagePosX+80, carriagePosY+70);
	glVertex2i(carriagePosX+15, carriagePosY+70);
	glEnd();

	glPushMatrix();
    glTranslatef(carriagePosX+15, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();

    ///Making third carriage body (from left)
    glPushMatrix();
    glTranslatef(carriagePosX+55, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(150, 0, 0);

    glColor3ub(133, 129, 129);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX, carriagePosY);
    glVertex2i(carriagePosX+70, carriagePosY);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glVertex2i(carriagePosX, carriagePosY+50);
	glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+10, carriagePosY+25);
    glVertex2i(carriagePosX+20, carriagePosY+25);
	glVertex2i(carriagePosX+20, carriagePosY+40);
	glVertex2i(carriagePosX+10, carriagePosY+40);
	glEnd();

	glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+30, carriagePosY+25);
    glVertex2i(carriagePosX+40, carriagePosY+25);
	glVertex2i(carriagePosX+40, carriagePosY+40);
	glVertex2i(carriagePosX+30, carriagePosY+40);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+50, carriagePosY+25);
    glVertex2i(carriagePosX+60, carriagePosY+25);
	glVertex2i(carriagePosX+60, carriagePosY+40);
	glVertex2i(carriagePosX+50, carriagePosY+40);
	glEnd();

	glColor3ub(0, 0, 150);
	glBegin(GL_QUADS);
	glVertex2i(carriagePosX, carriagePosY+10);
    glVertex2i(carriagePosX+70, carriagePosY+10);
	glVertex2i(carriagePosX+70, carriagePosY+15);
	glVertex2i(carriagePosX, carriagePosY+15);
	glEnd();

    glColor3ub(61, 61, 61);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+70, carriagePosY);
    glVertex2i(carriagePosX+80, carriagePosY+10);
	glVertex2i(carriagePosX+80, carriagePosY+68);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glEnd();


	glColor3ub(95,95,95);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+1, carriagePosY+50);
    glVertex2i(carriagePosX+71, carriagePosY+50);
	glVertex2i(carriagePosX+80, carriagePosY+70);
	glVertex2i(carriagePosX+15, carriagePosY+70);
	glEnd();

	glPushMatrix();
    glTranslatef(carriagePosX+15, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(carriagePosX+55, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

    ///Making final carriage body (from left)
    glPushMatrix();
    glTranslatef(225, 0, 0);

    glColor3ub(133, 129, 129);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX, carriagePosY);
    glVertex2i(carriagePosX+30, carriagePosY);
    glVertex2i(carriagePosX+30, carriagePosY+70);
    glVertex2i(carriagePosX, carriagePosY+70);
    glVertex2i(carriagePosX+30, carriagePosY+50);
    glVertex2i(carriagePosX+30, carriagePosY);
	glVertex2i(carriagePosX+70, carriagePosY);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(carriagePosX+10, carriagePosY+25);
    glVertex2i(carriagePosX+20, carriagePosY+25);
	glVertex2i(carriagePosX+20, carriagePosY+50);
	glVertex2i(carriagePosX+10, carriagePosY+50);
	glEnd();

	glColor3ub(0, 0, 150);
	glBegin(GL_QUADS);
	glVertex2i(carriagePosX, carriagePosY+10);
    glVertex2i(carriagePosX+50, carriagePosY+10);
	glVertex2i(carriagePosX+50, carriagePosY+15);
	glVertex2i(carriagePosX, carriagePosY+15);
	glEnd();

    glColor3ub(61, 61, 61);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+70, carriagePosY);
    glVertex2i(carriagePosX+80, carriagePosY+10);
	glVertex2i(carriagePosX+80, carriagePosY+68);
	glVertex2i(carriagePosX+70, carriagePosY+50);
	glEnd();


	glColor3ub(95,95,95);
    glBegin(GL_QUADS);
	glVertex2i(carriagePosX+29, carriagePosY+50);
    glVertex2i(carriagePosX+71, carriagePosY+50);
	glVertex2i(carriagePosX+80, carriagePosY+70);
	glVertex2i(carriagePosX+42, carriagePosY+70);
	glVertex2i(carriagePosX, carriagePosY+70);
    glVertex2i(carriagePosX+30, carriagePosY+70);
	glVertex2i(carriagePosX+40, carriagePosY+90);
	glVertex2i(carriagePosX+10, carriagePosY+90);
	glVertex2i(carriagePosX+40, carriagePosY+90);
    glVertex2i(carriagePosX+30, carriagePosY+70);
	glVertex2i(carriagePosX+30, carriagePosY+50);
	glVertex2i(carriagePosX+40, carriagePosY+60);
	glEnd();

	glPushMatrix();
    glTranslatef(carriagePosX+15, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=16;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+8);
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(carriagePosX+55, carriagePosY-14, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+3);
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

	glColor3ub(219, 219, 200);
	glBegin(GL_QUADS);
    glVertex2i(310, 270);
    glVertex2i(300, 270);
	glVertex2i(300, 290);
	glVertex2i(310, 290);
	glEnd();
	glBegin(GL_POLYGON);

    glVertex2i(carriagePosX+305, carriagePosY+20);
    glVertex2i(carriagePosX+295, carriagePosY+10);
	glVertex2i(carriagePosX+295, carriagePosY-10);
	glVertex2i(carriagePosX+320, carriagePosY-10);
	glEnd();

	glPushMatrix();
    glTranslatef(carriagePosX+300, carriagePosY+30, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(219, 219, 200);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/90;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+5);
	}
	glEnd();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(303, 298, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 308, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=7;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(276, 311, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=9;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(265, 322, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=11;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

///End of Making of Rail Body


glPushMatrix();
for(int l=0;l<=1000;++l)
    {


///big tree 6
glPushMatrix();
    glTranslatef(l,0,0);
    glTranslatef(25,180,0);
    glColor3ub(210,105,30);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
	glVertex2i(6,0);
	glColor3ub(160,82,45);
	glVertex2i(6, 55);
	glVertex2i(0, 55);
	glEnd();
	glColor3ub(210,105,30);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(-9,-9);
	glVertex2i(3,-3);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(0,0);
	glVertex2i(4.5,-9);
	glVertex2i(6,0);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(3,-3);
	glVertex2i(15,-9);
	glVertex2i(6,0);
	glEnd();
	glTranslatef(-2,-80,0);
    glScaled(2,2,1);
    glColor3ub(0,105,00);
    glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(6, 55);
	glVertex2i(10, 55);
	glVertex2i(15, 65);
	glVertex2i(18, 70);
	glVertex2i(15, 85);
    glColor3ub(34,139,34);
	glVertex2i(3, 90);
	glVertex2i(-9, 85);
	glVertex2i(-12, 70);
	glVertex2i(-9, 65);
	glVertex2i(-4, 55);
	glVertex2i(0, 55);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 56, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(139,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(6, 60, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(-3, 65, 0.0);
    glBegin(GL_POLYGON);
   // glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(9, 63, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(3, 60, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(128,128,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(-2, 58, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   	glPushMatrix();
    glTranslatef(-1, 65, 0.0);
    glBegin(GL_POLYGON);
   // glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(5, 63, 0.0);
    glBegin(GL_POLYGON);
    //glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();

glPopMatrix();
l+=150;
///end of big tree below train

}
glPopMatrix();


///
glPushMatrix();
glScalef(.8,.8,0);
glTranslatef(-500,43,0);
  //Human Train 1
    glPushMatrix();
    glTranslatef(_run,0,0);
    int human_train1x = 425;
    int human_train1y = 220; //525,420
    glBegin(GL_QUADS);
    glColor3ub(255, 236, 204);
    glVertex2i(human_train1x, human_train1y);
    glVertex2i(human_train1x-5, human_train1y);
    glVertex2i(human_train1x-5, human_train1y+10);
    glVertex2i(human_train1x, human_train1y+10);
    glVertex2i(human_train1x-1, human_train1y-5);
    glVertex2i(human_train1x-4, human_train1y-5);
    glVertex2i(human_train1x-4, human_train1y);
    glVertex2i(human_train1x-1, human_train1y);
//    glVertex2i(human_train1x+5, human_train1y-20);
//    glVertex2i(human_train1x+7, human_train1y-20);
//    glVertex2i(human_train1x+7, human_train1y-15);
//    glVertex2i(human_train1x+5, human_train1y-15);

    glVertex2i(human_train1x-5, human_train1y-45);
    glVertex2i(human_train1x-2, human_train1y-45);
    glVertex2i(human_train1x-2, human_train1y-35);
    glVertex2i(human_train1x-5, human_train1y-35);
    glVertex2i(human_train1x-1, human_train1y-45);
    glVertex2i(human_train1x+3, human_train1y-45);
    glVertex2i(human_train1x+3, human_train1y-35);
    glVertex2i(human_train1x-1, human_train1y-35);

    glColor3ub(225, 225, 0);
    glVertex2i(human_train1x-5, human_train1y-20);
    glVertex2i(human_train1x+2, human_train1y-20);
    glVertex2i(human_train1x+2, human_train1y-5);
    glVertex2i(human_train1x-5, human_train1y-5);

    glVertex2i(human_train1x-9, human_train1y-35);
    glVertex2i(human_train1x+6, human_train1y-35);
    glVertex2i(human_train1x+2, human_train1y-20);
    glVertex2i(human_train1x-5, human_train1y-20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(human_train1x+2, human_train1y+15);
    glVertex2i(human_train1x-5, human_train1y+15);
    glVertex2i(human_train1x-5, human_train1y+6);
    glVertex2i(human_train1x-5, human_train1y+15);
    glVertex2i(human_train1x-9, human_train1y+14);
    glVertex2i(human_train1x-9, human_train1y+6);
    glEnd();

    //Human Train 2
    int human_train2x = 480;
    int human_train2y = 220; //525,420
    glBegin(GL_QUADS);
    glColor3ub(255, 236, 204);
    glVertex2i(human_train2x, human_train2y);
    glVertex2i(human_train2x-5, human_train2y);
    glVertex2i(human_train2x-5, human_train2y+10);
    glVertex2i(human_train2x, human_train2y+10);
    glVertex2i(human_train2x-1, human_train2y-5);
    glVertex2i(human_train2x-4, human_train2y-5);
    glVertex2i(human_train2x-4, human_train2y);
    glVertex2i(human_train2x-1, human_train2y);
    glVertex2i(human_train2x-5, human_train2y-45);
    glVertex2i(human_train2x-2, human_train2y-45);
    glVertex2i(human_train2x-2, human_train2y-35);
    glVertex2i(human_train2x-5, human_train2y-35);
    glVertex2i(human_train2x-1, human_train2y-45);
    glVertex2i(human_train2x+3, human_train2y-45);
    glVertex2i(human_train2x+3, human_train2y-35);
    glVertex2i(human_train2x-1, human_train2y-35);

    glColor3ub(225, 0, 225);
    glVertex2i(human_train2x-5, human_train2y-20);
    glVertex2i(human_train2x+2, human_train2y-20);
    glVertex2i(human_train2x+2, human_train2y-5);
    glVertex2i(human_train2x-5, human_train2y-5);

    glVertex2i(human_train2x-9, human_train2y-35);
    glVertex2i(human_train2x+6, human_train2y-35);
    glVertex2i(human_train2x+2, human_train2y-20);
    glVertex2i(human_train2x-5, human_train2y-20);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(human_train2x+2, human_train2y+15);
    glVertex2i(human_train2x-5, human_train2y+15);
    glVertex2i(human_train2x-5, human_train2y+6);
    glVertex2i(human_train2x-5, human_train2y+15);
    glVertex2i(human_train2x-9, human_train2y+14);
    glVertex2i(human_train2x-9, human_train2y+6);
    glEnd();
    glTranslatef(-35,0,0);

	glBegin(GL_QUADS);
    glColor3ub(240,128,128);
    glVertex2i(human_train2x+20, human_train2y+43);
    glVertex2i(human_train2x+15, human_train2y-0);
    glColor3ub(205,92,92);
    glVertex2i(human_train2x+3, human_train2y-2);
    glVertex2i(human_train2x+3, human_train2y+33);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(205,92,92);
    glVertex2i(human_train2x+2, human_train2y-2);
    glVertex2i(human_train2x+5, human_train2y-2);
    glColor3ub(240,128,128);
    glVertex2i(human_train2x-5, human_train2y-12);
    glVertex2i(human_train2x-8, human_train2y-12);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(human_train2x+16, human_train2y+10);
    glVertex2i(human_train2x+35, human_train2y-12);
    glEnd();

    glTranslatef(-55,0,0);
	glBegin(GL_QUADS);
    glColor3ub(240,128,128);
    glVertex2i(human_train2x+20, human_train2y+43);
    glVertex2i(human_train2x+15, human_train2y-0);
    glColor3ub(205,92,92);
    glVertex2i(human_train2x+3, human_train2y-2);
    glVertex2i(human_train2x+3, human_train2y+33);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(205,92,92);
    glVertex2i(human_train2x+2, human_train2y-2);
    glVertex2i(human_train2x+5, human_train2y-2);
    glColor3ub(240,128,128);
    glVertex2i(human_train2x-5, human_train2y-12);
    glVertex2i(human_train2x-8, human_train2y-12);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2i(human_train2x+16, human_train2y+10);
    glVertex2i(human_train2x+35, human_train2y-12);
    glEnd();


    glPopMatrix();
    glPopMatrix();
//flag
    glPushMatrix();
    glTranslatef(205, 65, 0);

    glColor3ub(156, 143, 6);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(465, 340);
    glVertex2i(465, 350);
	glVertex2i(490, 350);
	glVertex2i(490, 340);
	glEnd();

	glColor3ub(0, 0, 0);    //STAIR
    glBegin(GL_LINE_LOOP);
    glVertex2i(465, 340);
    glVertex2i(465, 350);
	glVertex2i(490, 350);
	glVertex2i(490, 340);
	glEnd();


    glColor3ub(104, 138, 143);    //STAND
    glBegin(GL_QUADS);
    glVertex2i(470, 350);
    glVertex2i(470, 475);
	glVertex2i(475, 475);
	glVertex2i(475, 350);
	glEnd();

	glColor3ub(0, 0, 0);    //STAND
    glBegin(GL_LINE_LOOP);
     glVertex2i(470, 350);
    glVertex2i(470, 475);
	glVertex2i(475, 475);
	glVertex2i(475, 350);
	glEnd();

	glColor3ub(9, 107, 4);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(475, 440);
    glVertex2i(475, 475);
	glVertex2i(530, 475);
	glVertex2i(530, 440);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
     glVertex2i(475, 440);
    glVertex2i(475, 475);
	glVertex2i(530, 475);
	glVertex2i(530, 440);
	glEnd();


    ///Circle

   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(500, 460, 0);


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   glPopMatrix();

   glPopMatrix();






//birds XY mode
    glPushMatrix();
    glTranslatef(_brun,1000-_run, 0.0);
    glTranslatef(0,00, 0.0);
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();


	///bird 2

	glTranslatef(-55,-30, 0.0);
	glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

///bird 3
	glTranslatef(0,48, 0.0);
	glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3ub(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();



    glPopMatrix();
// birds x
    glPushMatrix();
    glTranslatef(_run2,900, 0);
    glTranslatef(0,00, 0.0);
    glBegin(GL_QUADS);
    glColor3f(255,255,255);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

	///bird 2

	glTranslatef(-55,-30, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

///bird 3
	glTranslatef(0,48, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);///text school
    glPushMatrix();
    glTranslatef(60, 125, 0);
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(740, 605, 0);
    Sprint(1.0,0,text);
    glPopMatrix();

	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();

///bird 4
    glTranslatef(0,-98, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
///bird 5
    glTranslatef(50,40, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	///bird 6
    glTranslatef(50,30,0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
///bird 5
    glTranslatef(-155,40, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	///bird 8
    glTranslatef(0,-130, 0.0);
	glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
    glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(20,12);
    glVertex2i(20,10);
	glVertex2i(50, 10);
	glVertex2i(50,25);
	glVertex2i(20,12);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(60,20);
	glVertex2i(65,15);
	glVertex2i(60,30);
	glVertex2i(50,25);
	glVertex2i(50,10);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+58,y+25 );
	}
	glEnd();
    glPopMatrix();
    glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(255,69,0);
	glBegin(GL_POLYGON);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,22);
	glVertex2i(42,38);
	glVertex2i(40,30);
	glVertex2i(38,38);
	glVertex2i(37,18);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
    glVertex2i(45,10);
	glVertex2i(42,-3);
	glVertex2i(40,5);
	glVertex2i(38,-3);
	glVertex2i(37,10);
	glEnd();


    glPopMatrix();
//End of birds

///text school
    glPushMatrix();
    glTranslatef(60, 125, 0);
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

	glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(740, 605, 0);
    Sprint(1.0,0,text);
    glPopMatrix();








/// Coconut tree

glPushMatrix();
    glTranslatef(-18,40,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();


// Coconut tree 1
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(0,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///Coconut Tree 2
    glPushMatrix();
    glTranslatef(40,0,0);
    glPushMatrix();
    glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(10,00);
    glVertex2i(30,60);
    glVertex2i(15,60);
	glVertex2i(0,30);
	glVertex2i(-15,0);
	glEnd();
	glColor3ub(139,69,19);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(15,60);
    glVertex2i(30,60);
    glVertex2i(40,90);
    glVertex2i(30,90);
    glVertex2i(15,60);
	glEnd();
	glBegin(GL_LINES);
    glVertex2i(22,75);
    glVertex2i(35,75);

    glVertex2i(22,40);
    glVertex2i(5,40);
	glEnd();
     //tree leaps
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
    glVertex2i(45,100);
    glVertex2i(30,100);
    glVertex2i(30,90);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,90);
    glVertex2i(60,40);
    glVertex2i(45,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,90);
    glVertex2i(70,50);
    glVertex2i(50,100);

	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,100);
    glVertex2i(60,120);
    glVertex2i(45,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
    glVertex2i(30,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(45,100);
    glVertex2i(48,130);
    glVertex2i(40,100);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(40,100);
    glVertex2i(30,120);
    glVertex2i(35,100);
	glEnd();

	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
    glVertex2i(30,100);

	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,90);
    glVertex2i(0,50);
    glVertex2i(25,95);
	glEnd();
	glColor3ub(0,100,0);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(35,100);
    glVertex2i(0,110);
    glVertex2i(30,95);
	glEnd();

	glColor3ub(50,205,50);    //QUAD
    glBegin(GL_POLYGON);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
	glColor3ub(0,0,0);    //QUAD
    glBegin(GL_LINE_STRIP);
    glVertex2i(37,90);
    glVertex2i(40,58);
    glVertex2i(42,62);
    glVertex2i(40,90);
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);



    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(38, 65, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(40, 60, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(00,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(45, 62, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43, 55, 0);

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,00);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

    glFlush();
	glutSwapBuffers();


}


void update(int value) {
    _brun += 5.0f;
	if (_brun > 1000)
    {
        _brun -= 1000;
    }
    _sun += 1.0f;
    if (_sun > 400)
    {
        _sun -= 410;
    }

    _moon +=1.0f;
	if (_moon > 800)
    {
        _moon -= 800;
    }
	_run += 1.0f;
	if (_run > 1000)
    {
        _run -= 1700;
    }

    _run1 += 1.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1300;
    }
    _run8 +=3.0f;
	if (_run8 > 1000)
    {
        _run8 -= 1200;
    }

    _run2 += 3.5f;
	if (_run2 > 1000)
    {
        _run2 -= 1300;
    }

     _run3 += 0.8f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }
    kite_counter = kite_counter + kite_speed;
    if(kite_counter > 20 && kite_flag==false)
    {
        kite_counter = kite_counter - kite_speed;
        kite_position = kite_position - kite_speed;
    }
    else if(kite_counter <= 20 && kite_flag==false)
    {
        //counter = counter + speed;
        kite_position = kite_position + kite_speed;
    }
    if(kite_position < -40 || kite_flag == true)
    {
        kite_flag = true;
        kite_counter = kite_counter + kite_speed;
        kite_position = kite_position + kite_speed;
        if(kite_position > 20)
        {
            kite_flag = false;
        }
    }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}


void railForward(int value){

if(frd){

    _ang_tri += 2.2f;

    if (_ang_tri > 1000) {
		_ang_tri -= 1400;
	}

	glutPostRedisplay();
	glutTimerFunc(25, railForward, 0);
}
}

void railBackward(int value){
if(bck){

    _ang_tri -= 2.2f;

     if (_ang_tri < -350) {
		_ang_tri = 1100;
	}
	glutPostRedisplay();
	glutTimerFunc(25, railBackward, 0);
}
}


void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();

    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);


    glFlush();


}
}

void Night(int value){

if(night){
   // glClearColor(0,0,0,0);
	glutPostRedisplay();
    glutTimerFunc(5, Night, 0);

    glFlush();

}
}

void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 'a':
        frd = false;
	    bck = true;
	    railBackward(_ang_tri);
	break;

	case 'd':
	     frd = true;
	     bck = false;
         railForward(_ang_tri);
	    break;

    case 's':
        frd = false;
        bck = false;
        break;

    case 'r':
        rainday = true;
        Rain(_rain);
        sndPlaySound("River.wav",SND_ASYNC|SND_LOOP);
        sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 'e':
        rainday = false;
		sndPlaySound(NULL,SND_ASYNC);
        break;

    case 'n':
        night = true;
        Night(_nt);

        break;

    case 'b':
        night = false;
        glClearColor(0.0,0.5,0.8,1.0);

        break;

    case 27:     // ESC key
        exit(0);
        break;

	default:
	break;
	}
}


int main(int argc,char **argv)
{
    cout << endl << "Village View Project" << endl << endl;
    cout << "Press N : For Night " << endl << endl;
    cout << "Press B : For Day" << endl << endl;
    cout << "Press R : For Rain " << endl << endl;
    cout << "Press E : For Stop Rain" << endl << endl;
    cout << "Press D : To Forward the Train" << endl << endl;
    cout << "Press A : To Backward the Train" << endl << endl;
    cout << "Press S : To Stop the Train" << endl << endl;





	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Village View Project");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}

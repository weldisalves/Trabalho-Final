#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "globals.h"
#include "Player.h"
#include "Inimigo.h"
#include "Elemento.h"
#include "Poder.h"
#include "Wall.h"
#include "Mapa.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int keyStatus[256];
float tam = 0.3;
float tamI = 0.1;
int iX=-666,iY=800;

Player player;
Inimigo *inimigo = NULL;

Mapa mapa;

float n;

void draw(void);
void inicializaKeyStatus();
void keyboardDown( unsigned char key, int x, int y );
void keyboardUp(unsigned char key, int x, int y);
void idlePlayer();
void idleMob();
void wall(float x, float y, float z);
void arena();
void playerDraw();
void inimigoDraw();
double inimigoOriginAngle(int x, int y);


void init(void){

    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    glMatrixMode( GL_PROJECTION );
    glOrtho( -WINDOW_WIDTH, WINDOW_WIDTH, -WINDOW_HEIGHT, WINDOW_HEIGHT, 100, -100 );
    //gluPerspective (6000, 1, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    inicializaKeyStatus();   

    glutSwapBuffers();
}    

int main(int argc, char *argv[]){

    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
    glutInitWindowPosition( 200, 50 );
    glutCreateWindow( "Trabalho Final" );

    mapa.loadFile("mapa1.svg");
  
    player.setX(INIT_POS_X);
    player.setY(INIT_POS_Y);
    player.setDeslocamento(0.3);

    inimigo = new Inimigo(800,800,0.1,200,1000);

    // printf("\n Digite a quantidade de inimigos: ");
    // scanf("%f",&n);


    srand (time(NULL));

    init();
    
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutIdleFunc(idlePlayer);
  
    glutMainLoop();
    return 0;
}

void wall(float x, float y,float z){
    glPushMatrix();
    	glTranslatef(x,y,z);
    	glColor3f(0,0,0);
    	glBegin(GL_POLYGON);
        	glVertex3f(0,0,0);
        	glVertex3f(50,0,0);
        	glVertex3f(50,50,0);
        	glVertex3f(0,50,0);
    	glEnd();
    glPopMatrix();

}

void arena(){
	// float i = 0;
	// glPushMatrix();		
	// 	for(i = WINDOW_WIDTH-50; i > -WINDOW_HEIGHT; i-=50)wall(-WINDOW_WIDTH,i,0);
	// 	for(i = -WINDOW_WIDTH; i < WINDOW_WIDTH; i+=50)wall(i,-WINDOW_HEIGHT,0);
	// 	for(i = -WINDOW_WIDTH+50; i < WINDOW_HEIGHT; i+=50)wall(WINDOW_WIDTH-50,i,0);
	// 	for(i = WINDOW_WIDTH-50;i > -WINDOW_WIDTH ; i-=50)wall(i,WINDOW_HEIGHT-50,0);
	// glPopMatrix();

    mapa.draw();


}

void playerDraw(){
	player.draw();
}

void inimigoDraw(int x,int y){
	//inimigo->draw();
	glPushMatrix();
        glColor3f(1,1,0);
		glTranslatef(x,y,0);
        glScalef(1,1,0);
		glBegin(GL_POLYGON);
        	glVertex3f(0,0,0);
			glVertex3f(50,0,0);
			glVertex3f(50,50,0);
			glVertex3f(0,50,0);
		glEnd();
	glPopMatrix();
}

void draw(void){
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    arena();
    playerDraw();
    inimigoDraw(iX,iY);

    glutSwapBuffers();
}

void inicializaKeyStatus(){
    for (int i = 0; i < 256; ++i){
        keyStatus[i]=0;
    }
}

void keyboardUp( unsigned char key, int x, int y ){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
        case 'W':
            keyStatus[(int)('w')] = 0;
            break;
        case 'A':
        case 'a':
            keyStatus[(int)('a')] = 0;
            break;
        case 'S':
        case 's':
            keyStatus[(int)('s')] = 0;
            break;
        case 'D':
        case 'd':
            keyStatus[(int)('d')] = 0;
            break;
        
        default:
            break;
    }
    
    glutPostRedisplay();
}

void keyboardDown( unsigned char key, int x, int y ){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
        case 'W':
            keyStatus[(int)('w')] = 1;
            break;
        case 'a':
        case 'A':
            keyStatus[(int)('a')] = 1;
            break;
        case 's':
        case 'S':
            keyStatus[(int)('s')] = 1;
            break;
        case 'd':
        case 'D':
            keyStatus[(int)('d')] = 1;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

void idlePlayer(){
    static GLdouble previousTime = 0;
    GLdouble currentTime = 0;
    GLdouble timeDiference;

    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDiference = currentTime - previousTime;
    previousTime = currentTime;

    
    if(keyStatus['w'] == 1){
        player.setX(cos(player.getTheta()*M_PI/180 )*timeDiference);
        player.setY(sin(player.getTheta()*M_PI/180 )*timeDiference);
    }

    if(keyStatus['s'] == 1){
        player.setX(-cos(player.getTheta()*M_PI/180 )*timeDiference);
        player.setY(-sin(player.getTheta()*M_PI/180 )*timeDiference);
    }

    if(keyStatus['d'] == 1)player.setTheta(-player.getDeslocamento()*timeDiference);
    if(keyStatus['a'] == 1)player.setTheta(player.getDeslocamento()*timeDiference);

    if(keyStatus['q'] == 1){

    }
    if(keyStatus['e'] == 1);


        

    //perseguição
    if(iX > player.getX()){
        iX -= tamI*timeDiference;
    }else if(iX < player.getX()){
        iX += tamI*timeDiference;
    }

    if(iY > player.getY()){
        iY -= tamI*timeDiference;
    }else if(iY < player.getY()){
        iY += tamI*timeDiference;
    }
    
    glutPostRedisplay();
}

double inimigoOriginAngle( int x, int y ){
    int xa, ya;
    int x2,y2;
    x2 = x - WINDOW_WIDTH;
    y2 = WINDOW_HEIGHT - y ;
    ya = player.getY() + 40;
    xa = player.getX();

    double oposto, adjascente;
    adjascente = x2 - xa;
    oposto = y2 - ya;

    double aux =  atan(adjascente/oposto) * 180 / M_PI;
    if(oposto < 0) aux = aux + 180;
    aux = -aux;

    return aux;
}


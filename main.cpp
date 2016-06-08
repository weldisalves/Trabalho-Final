#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "globals.h"
#include "Player.h"
#include "Inimigo.h"
#include "Elemento.h"
#include "Poder.h"
#include "Wall.h"
#include "Mapa.h"

using namespace std;

int keyStatus[256];
int fase = 1;

Elemento *player = new Player();
Inimigo *inimigo = NULL;

Mapa mapa;
Mapa moldura;

float n;

void draw(void);
void inicializaKeyStatus();
void keyboardDown( unsigned char key, int x, int y );
void keyboardUp(unsigned char key, int x, int y);
void idlePlayer();
void idleMob();
void arena();
void playerDraw();
void inimigoDraw();
double inimigoOriginAngle( float px, float py, float ix,float iy );

float distancia(float x1, float y1, float x2, float y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void init(void){

    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    glMatrixMode( GL_PROJECTION );
    glOrtho( -WINDOW_WIDTH, WINDOW_WIDTH, -WINDOW_HEIGHT, WINDOW_HEIGHT, 1, -1 );
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
    glutInitWindowPosition( 100, 50 );
    glutCreateWindow( "Trabalho Final" );

    //moldura.loadFile("moldura.svg");

    if(fase == 1){
        mapa.loadFile("mapa1.svg");
    }else if(fase ==2){
        //mapa.loadFile("mapa2.svg");
    }else if(fase == 3){
        //mapa.loadFile("mapa3.svg");
    }
  
    player->setX(INIT_POS_X);
    player->setY(INIT_POS_Y-200);
    player->setDeslocamento(0.3);

    inimigo = new Inimigo(-800,-800,0.2,200,1000);

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

void arena(){
	//moldura.draw();
    mapa.draw();
}

void playerDraw(){
	player->draw();
}

void inimigoDraw(){
	inimigo->draw();
}

void draw(void){
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    arena();
    playerDraw();
    inimigoDraw();

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
        case 'q':
        case 'Q':
        	keyStatus[(int)('q')] = 1;
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
        player->setX(cos(player->getTheta()*M_PI/180 )*timeDiference);
        player->setY(sin(player->getTheta()*M_PI/180 )*timeDiference);
    }


    if(keyStatus['s'] == 1){
        player->setX(-cos(player->getTheta()*M_PI/180 )*timeDiference);
        player->setY(-sin(player->getTheta()*M_PI/180 )*timeDiference);
    }

    if(keyStatus['d'] == 1)player->setTheta(player->getDeslocamento()*timeDiference);
    if(keyStatus['a'] == 1)player->setTheta(-player->getDeslocamento()*timeDiference);

    if(keyStatus['q'] == 1);
    if(keyStatus['e'] == 1);
    
    //perseguiçãodo inimigo
        float px = player->getX();
        float py = player->getY();
        float ix = inimigo->getX();
        float iy = inimigo->getY();

        float angulo = inimigoOriginAngle(px,py,ix,iy);
        inimigo->setTheta(angulo);

    float dist = distancia(player->getX(),player->getY(),inimigo->getX(),inimigo->getY());


    if(dist > 200){
        if(inimigo->getX() > player->getX() || inimigo->getX()< player->getX()){
            inimigo->setX(cos(inimigo->getTheta()*M_PI/180 )*3.5);
        }
        if(inimigo->getY() > player->getY() || inimigo->getY()< player->getY()){
            inimigo->setY(sin(inimigo->getTheta()*M_PI/180 )*3.5);
        }
    }else{
    	inimigo->setX(-cos(inimigo->getTheta()*M_PI/180)*2);
        inimigo->setY(-sin(inimigo->getTheta()*M_PI/180)*2);
    }
    
    glutPostRedisplay();
    //printf("distancia - %f\n",dist );
}

double inimigoOriginAngle( float px, float py, float ix,float iy ){

    int xa, ya;
    int x2,y2;
    x2 = px;
    y2 = py ;
    ya = iy;

    xa = ix + 10;

    double oposto, adjascente;
    adjascente = x2 - xa;
    oposto = y2 - ya;

    double aux =  atan(oposto/adjascente) * 180 / M_PI;

    if(adjascente < 0) aux = aux + 180;
    //aux = -aux;

    return aux;
}
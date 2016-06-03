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
#include "Bala.h"


using namespace std;

int keyStatus[256];
int fase = 1;

Player player;
Inimigo *inimigo = NULL;

Mapa mapa;

float n;

float bx=0,by=0,theta=0;

int tiro = 0;

void draw(void);
void inicializaKeyStatus();
void keyboardDown( unsigned char key, int x, int y );
void keyboardUp(unsigned char key, int x, int y);
void idlePlayer();
void idleMob();
void arena();
void playerDraw();
void inimigoDraw();
bool checaColisao( Quadrado *quadrado1, Quadrado *quadrado2 );
bool colisaoComArena(std::vector<Quadrado> arena, Quadrado obj);

double inimigoOriginAngle( float px, float py, float ix,float iy );

float distancia(){
	return sqrt(pow(player.getX()-inimigo->getX(),2)+pow(player.getY()-inimigo->getY(),2));
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

    if(fase == 1){
        mapa.loadFile("mapa1.svg");
    }else if(fase ==2){
        //mapa.loadFile("mapa2.svg");
    }else if(fase == 3){
        //mapa.loadFile("mapa3.svg");
    }
  
    player.setX(INIT_POS_X);
    player.setY(INIT_POS_Y);
    player.setDeslocamento(0.3);
    player.carregaMunicao();



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
    mapa.draw();
}

void playerDraw(){
	player.draw();
	player.getBalas()[tiro-1].draw();

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
        	player.getBalas()[tiro].setX(player.getX());
        	player.getBalas()[tiro].setY(player.getY());
        	player.getBalas()[tiro].setTheta(player.getTheta());
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

    bool colisaoPlayerArena = colisaoComArena(mapa.getObjetos(),player.getQuadrado());
        
    if(colisaoPlayerArena == false){
    
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
    	player.getBalas()[tiro].setX(cos(player.getTheta()*M_PI/180 )*timeDiference*0.5);
        player.getBalas()[tiro].setY(sin(player.getTheta()*M_PI/180 )*timeDiference*0.5);
        
	    tiro++;
    }
    if(keyStatus['e'] == 1);
    }

    //perseguiçãodo inimigo
        float px = player.getX();
        float py = player.getY();
        float ix = inimigo->getX();
        float iy = inimigo->getY();

        float angulo = inimigoOriginAngle(px,py,ix,iy);
        inimigo->setTheta(angulo);

        float dist = distancia();
    if(dist < 800 && dist > 200){
        if(inimigo->getX() > player.getX() || inimigo->getX()< player.getX()){
            inimigo->setX(cos(inimigo->getTheta()*M_PI/180 ));
        }
        if(inimigo->getY() > player.getY() || inimigo->getY()< player.getY()){
            inimigo->setY(sin(inimigo->getTheta()*M_PI/180 ));
        }
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


bool checaColisao( Quadrado quadrado1, Quadrado quadrado2 ){
    float esquerda1, direita1, cima1, baixo1;
    float esquerda2, direita2, cima2, baixo2;

    esquerda1 = quadrado1.x;
    direita1 = quadrado1.x + quadrado1.width;
    cima1 = quadrado1.y;
    baixo1 = quadrado1.y + quadrado1.height;
    esquerda2 = quadrado2.x;
    direita2 = quadrado2.x + quadrado2.width;
    cima2 = quadrado2.y;
    baixo2 = quadrado2.y + quadrado2.height;

    if( esquerda1 > direita2 ) return false; //retorna 0 (não colisão)
    if( direita1 < esquerda2 ) return false; // retorna 0 (não colisão)
    if( cima1 > baixo2 ) return false; // retorna 0 (não colisão)
    if( baixo1 < cima2 ) return false; // retorna 0 (não colisão)

     /*do contrário retorna 1 (COLISÃO)*/
     return false;
} 

bool colisaoComArena(std::vector<Quadrado> arena, Quadrado obj){
    bool colisao;

    for(int i = 1 ;i < arena.size();i++){
        colisao = checaColisao(arena[i],obj);
  //getchar();
        if(colisao == true){
            printf("Colidiu com a arena");
            //return true;
            exit(0);
        }
    }
    return false;
}

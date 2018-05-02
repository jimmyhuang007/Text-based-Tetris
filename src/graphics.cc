#include <iostream>
#include <string>
#include "graphics.h"
#include "window.h"
using namespace std;

Graphics::Graphics(){//Xwindow gets intailize here
    for(int i = 0; i < 46; i++){
    x.fillRectangle(45 + (5 * i), 59, 5, 5, Xwindow::Black);
    }
    for(int i = 0; i < 74; i++){
    x.fillRectangle(44, 60 + (5 * i), 5, 5, Xwindow::Black);
    }
    for(int i = 0; i < 46; i++){//use col*width(5) + offset
    x.fillRectangle(45 + (5 * i), 425, 5, 5, Xwindow::Black);
    }
    for(int i = 0; i < 74; i++){//use col*width(5) + offset
    x.fillRectangle(270, 60 + (5 * i), 5, 5, Xwindow::Black);
    }
    x.drawBigString(80,40,"QUADRIS",Xwindow::Orange);
    x.drawBigString(300,90,"Level:",Xwindow::Black);
    x.drawBigString(300,130,"Score:",Xwindow::Black);
    x.drawBigString(300,170,"Hi Score:",Xwindow::Black);
    x.drawBigString(300,230,"Next:",Xwindow::Black);
}
void Graphics::notify(Cell c){
    Coordinate coord = c.getCoord();
    //cout << "X:" << coord.x << " Y:" << coord.y << " Color:" << c.getPiece() << endl;
    char color = c.getPiece();
    if(color == ' '){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 20, 20, Xwindow::White);
    } else if (color == 'I'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Red);
    } else if (color == 'J'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Green);
    } else if (color == 'L'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Blue);
    } else if (color == 'O'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Cyan);
    } else if (color == 'S'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Yellow);
    } else if (color == 'Z'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Magenta);
    } else if (color == 'T'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Orange);
    } else if (color == '*'){
        x.fillRectangle(50 + (20 * coord.y), 65 + (20 * coord.x), 19, 19, Xwindow::Brown);
    }
    
}
void Graphics::notifytop(int level,int score,int highscore){
    x.fillRectangle(450,50, 100, 150, Xwindow::White);
    x.drawBigString(450,90,to_string(level),Xwindow::Red);
    x.drawBigString(450,130,to_string(score),Xwindow::Blue);
    x.drawBigString(450,170,to_string(highscore),Xwindow::Cyan);
}

void Graphics::notifybot(char color){
    if (color == 'I'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(390, 220, 19, 19, Xwindow::Red);
        x.fillRectangle(410, 220, 19, 19, Xwindow::Red);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Red);
        x.fillRectangle(450, 220, 19, 19, Xwindow::Red);
    } else if (color == 'J'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(410, 220, 19, 19, Xwindow::Green);
        x.fillRectangle(410, 200, 19, 19, Xwindow::Green);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Green);
        x.fillRectangle(450, 220, 19, 19, Xwindow::Green);
    } else if (color == 'L'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(410, 220, 19, 19, Xwindow::Blue);
        x.fillRectangle(450, 200, 19, 19, Xwindow::Blue);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Blue);
        x.fillRectangle(450, 220, 19, 19, Xwindow::Blue);
    } else if (color == 'O'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Cyan);
        x.fillRectangle(410, 220, 19, 19, Xwindow::Cyan);
        x.fillRectangle(410, 200, 19, 19, Xwindow::Cyan);
        x.fillRectangle(430, 200, 19, 19, Xwindow::Cyan);
    } else if (color == 'S'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(450, 200, 19, 19, Xwindow::Yellow);
        x.fillRectangle(430, 200, 19, 19, Xwindow::Yellow);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Yellow);
        x.fillRectangle(410, 220, 19, 19, Xwindow::Yellow);
    } else if (color == 'Z'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(410, 200, 19, 19, Xwindow::Magenta);
        x.fillRectangle(430, 200, 19, 19, Xwindow::Magenta);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Magenta);
        x.fillRectangle(450, 220, 19, 19, Xwindow::Magenta);
    } else if (color == 'T'){
        x.fillRectangle(390, 200, 100, 100, Xwindow::White);
        x.fillRectangle(410, 200, 19, 19, Xwindow::Orange);
        x.fillRectangle(430, 220, 19, 19, Xwindow::Orange);
        x.fillRectangle(430, 200, 19, 19, Xwindow::Orange);
        x.fillRectangle(450, 200, 19, 19, Xwindow::Orange);
    }
}






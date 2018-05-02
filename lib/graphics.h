#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "window.h"
#include "Cell.h"

class Graphics {
    Xwindow x; 
    public:
    Graphics();
    void notify(Cell c);
    void notifytop(int level,int score,int highscore);
    void notifybot(char color);
};
#endif

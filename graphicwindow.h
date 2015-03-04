#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QFont>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <cstdlib>
#include <vector>
#include <QLabel>
#include <QString>
#include <QListWidget>
#include <QStringList>

#include "bouncingrectangle.h"
#include "puzzle_solver.h"
#include "puzzle_heur.h"
#include "board.h"
#include "guitile.h"
//#include "formlayout.h"

#define WINDOW_MAX_X 180
#define WINDOW_MAX_Y 180

class GraphicWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicWindow(QListWidget * nqlv);
    ~GraphicWindow();
    void show();
    void moveTile(GUITile *guit);
    void createGame(int, int, int);
    void runAStar(std::string);
    bool startGame();
    
private:
    QGraphicsScene *scene;
    std::vector<GUITile *> gtiles;
    Board *b;
    GUITile *gt;
    QListWidget *qlv;
    QTimer *timer;
    bool startedGame;
    int counter;

public slots:
    //void setManhattan();
    //void setOutOfPlace();
    void handleTimer();

};

#endif // GRAPHICWINDOW_H

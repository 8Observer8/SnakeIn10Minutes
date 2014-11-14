#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include "Game.h"

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene( QWidget *parent = 0 );

signals:
    void signalShowStatus( const QString &status );

private slots:
    void slotUpdate();
    void slotSnakeSize( size_t size );

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );
    void sendStatus();

private:
    Game m_game;
    const size_t m_maxSize;
    QTimer m_timer;
};

#endif // SCENE_H

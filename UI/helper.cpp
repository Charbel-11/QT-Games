#include "helper.h"

QGraphicsView* Helper::view;

Helper::Helper(){}

//Sets a widget with the appropriate size and location on screen
//Uses polymorphism
void Helper::openWidget(QWidget *w){
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->setFixedSize(QDesktopWidget().width()*0.4, QDesktopWidget().height()*0.7);
    w->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, w->size(), qApp->desktop()->availableGeometry())); //Centers the widget
    w->show();
}

void Helper::openView(QGraphicsScene *w, int width, int height, QString title){
    view = new QGraphicsView(w);
    view->setAttribute(Qt::WA_DeleteOnClose, true);
    view->setWindowTitle(title);
    view->setFixedSize(width, height);
    view->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, view->size(), qApp->desktop()->availableGeometry())); //Centers the widget
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->show();
}

void Helper::closeView(){
    view->close();
}

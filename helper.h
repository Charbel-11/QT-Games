/**
  * \file helper.h
  * \brief A helper class that opens widgets/views
  */
#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QTimer>
#include <QWidget>

//Helper class that contains static functions that might be used throughout the project
class Helper
{
public:
    Helper();

    /**
     * @brief Opens a widget with the correct size and center it
     * @param w The widget to be opened
     */
    static void openWidget(QWidget *w);
    /**
     * @brief Opens a view with the correct size and location
     * @param w The scene to be added to the view
     * @param width The width of the view
     * @param height The height of the view
     * @param title The name of the window
     */
    static void openView (QGraphicsScene *w, int width, int height, QString title);
    /**
     * @brief Closes the opened view
     */
    static void closeView();

    static QGraphicsView *view;
};

#endif // HELPER_H

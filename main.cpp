#include <QApplication>
#include <authenticationwidget.h>
#include <helper.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    AuthenticationWidget *w = new AuthenticationWidget();
    Helper::openWidget(w);

    return app.exec();
}

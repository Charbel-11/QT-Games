#include <QApplication>
#include <UI/authenticationwidget.h>
#include <UI/helper.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    AuthenticationWidget *w = new AuthenticationWidget();
    Helper::openWidget(w);

    return app.exec();
}

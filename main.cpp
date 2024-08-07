#include "mainwindow.h"
#include "table_hachage.h"
#include "db.h"
#include "f1_f4.h"
#include "f2_f4.h"
#include "f1_f2.h"
#include "f1_f3.h"
#include "f2_f3.h"
#include <QIcon>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("TURBO");
    QString iconPath="C:/Users/DELL/OneDrive/Documents/TURBO/images/icon2.PNG";
    app.setWindowIcon(QIcon(iconPath));

    MainWindow w;
    w.show();

    return app.exec();
}

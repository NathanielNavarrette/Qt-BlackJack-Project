/*
 * Links where I found help for this project:
 *
 * https://github.com/DomHeal -Has a github repository with a blackjack game, where i found images im using as well
 * https://forum.qt.io/topic/14918/where-to-put-images-png-to-work-wit-qt-project/2
 * https://stackoverflow.com/questions/26508171/creating-a-resource-file-to-use-it-in-qt-designer
 * http://doc.qt.io/qt-5/resources.html
 * https://stackoverflow.com/questions/1460361/how-to-set-application-icon-in-a-qt-based-project
 *
 *
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

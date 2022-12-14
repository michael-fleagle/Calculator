// Michael Fleagle
// CS480

#include "calculator.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "CS480Calculator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Calculator w;
    w.show();
    return a.exec();
}

#include <QCoreApplication>
#include <core.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // main code --------------------------------------//
    Core* core = new Core();
    core->start();

    // main code --------------------------------------//

    return a.exec();
}

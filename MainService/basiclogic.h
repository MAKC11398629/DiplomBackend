#ifndef BASICLOGIC_H
#define BASICLOGIC_H

#include <QObject>

class BasicLogic : public QObject
{
    Q_OBJECT
public:
    explicit BasicLogic(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BASICLOGIC_H
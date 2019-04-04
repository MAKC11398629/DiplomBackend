#ifndef ACCOUNTVALIDATOR_H
#define ACCOUNTVALIDATOR_H

#include <QObject>

class AccountValidator : public QObject
{
    Q_OBJECT
public:
    explicit AccountValidator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ACCOUNTVALIDATOR_H
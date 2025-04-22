#ifndef RNGLOGIC_H
#define RNGLOGIC_H

#include <QObject>

class RNGLogic : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE int generate(int min, int max);
};

#endif
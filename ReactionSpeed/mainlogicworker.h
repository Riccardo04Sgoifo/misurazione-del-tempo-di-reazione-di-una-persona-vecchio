#ifndef MAINLOGICWORKER_H
#define MAINLOGICWORKER_H

#include <QThread.h>
#include <QObject>
#include <QRandomGenerator>

class MainLogicWorker : public QObject
{
    Q_OBJECT
private:
    int startDelay = 3000;
    int attemptNum = 10;
public:
    explicit MainLogicWorker(QObject *parent = nullptr);

public slots:
    void doWork();
    void setAttemptNum(int value);
    void setStartDelay(int value);

signals:
    void lightChanged(int value);
    void attemptNumChanged(int value);
    void startDelayChanged(int value);
};

#endif // MAINLOGICWORKER_H

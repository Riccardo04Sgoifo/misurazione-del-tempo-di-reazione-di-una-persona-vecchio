#include "mainlogicworker.h"

MainLogicWorker::MainLogicWorker(QObject *parent)
    : QObject{parent}
{

}

void MainLogicWorker::doWork()
{
    for (int i = 0; i < attemptNum; i++){
        QThread::msleep(startDelay);

        int randomLight = QRandomGenerator::global()->bounded(4);
        emit lightChanged(randomLight);
    }


}

void MainLogicWorker::setAttemptNum(int value)
{
    attemptNum = value;
    emit attemptNumChanged(value);
}

void MainLogicWorker::setStartDelay(int value)
{
    startDelay = value;
    emit startDelayChanged(value);
}

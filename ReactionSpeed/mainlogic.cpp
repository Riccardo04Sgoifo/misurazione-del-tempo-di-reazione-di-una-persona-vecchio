#include "mainlogic.h"

void MainLogic::setLightNum(int num)
{
    lightNumber = num;


    emit lightNumChanged(num);
}

void MainLogic::setCurrentLight(int value)
{
    currentLight_m = value;
    emit currentLightChanged(value);
}

void MainLogic::setAttemptNum(int value)
{
    attemptNum_m = value;
    emit attemptNumChanged(value);
}

void MainLogic::setStartDelay(int value)
{
    startDelay_m = value;
    emit startDelayChanged(value);
}

MainLogic::MainLogic()
{
    MainLogicWorker *worker = new MainLogicWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &MainLogic::startAttemptsSignal, worker, &MainLogicWorker::doWork);
    connect(worker, &MainLogicWorker::lightChanged, this, &MainLogic::setCurrentLight);
    connect(this, &MainLogic::startDelayChanged, worker, &MainLogicWorker::setStartDelay);
    connect(this, &MainLogic::attemptNumChanged, worker, &MainLogicWorker::setAttemptNum);
    //connect worker output signal and this slopt handler
    workerThread.start();
}

MainLogic::~MainLogic()
{
    workerThread.quit();
    workerThread.wait();
}

void MainLogic::startAttempts()
{
    emit startAttemptsSignal();
}

#ifndef MAINLOGIC_H
#define MAINLOGIC_H
#include <QObject>
#include <QThread>
#include <QDebug>
#include <mainlogicworker.h>

class MainLogic : public QObject
{
    Q_OBJECT
    QThread workerThread;
    Q_PROPERTY(int lightNum READ lightNum WRITE setLightNum NOTIFY lightNumChanged);
    Q_PROPERTY(int currentLight READ currentLight WRITE setCurrentLight NOTIFY currentLightChanged);
    Q_PROPERTY(int attemptNum READ attemptNum WRITE setAttemptNum NOTIFY attemptNumChanged);
    Q_PROPERTY(int startDelay READ startDelay WRITE setStartDelay NOTIFY startDelayChanged);

private:
    // variables
    int lightNumber = 4;
    int startDelay_m = 3000;
    int attemptNum_m = 10;

    int currentLight_m = 2;

public:

    int lightNum() const {return lightNumber; }
    int currentLight() const {return currentLight_m; }
    int attemptNum() const {return attemptNum_m; }
    int startDelay() const {return startDelay_m; }



    MainLogic();
    ~MainLogic();

public slots:
    void startAttempts();
    void setLightNum(int num);
    void setCurrentLight(int value);
    void setAttemptNum(int value);
    void setStartDelay(int value);

signals:
    void lightNumChanged(int value);
    void currentLightChanged(int value);
    void startAttemptsSignal();
    void attemptNumChanged(int value);
    void startDelayChanged(int value);
};

#endif // MAINLOGIC_H

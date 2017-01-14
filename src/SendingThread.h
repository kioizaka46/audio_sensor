#pragma once
#include "ofMain.h"

class SendingThread: public ofThread {
public:
    SendingThread();
    ~SendingThread();
    void sending(int rotate_deg);
    void update();
    bool isFrameNew();
    void draw();
    
private:
    void threadedFunction();
    ofThreadChannel<int> toSending;
    ofThreadChannel<int> sended;
    int rotate_deg;
    bool newFrame;
    bool received;
};

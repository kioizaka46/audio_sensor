#include "SendingThread.h"
#include "ofConstants.h"

SendingThread::SendingThread()
:newFrame(true){
    startThread();
}

SendingThread::~SendingThread(){
    toSending.close();
    sended.close();
    waitForThread(true);
}

void SendingThread::sending(int rotate_deg){
    toSending.send(rotate_deg);
}

void SendingThread::update(){
    
}

void SendingThread::draw(){
    
}

void SendingThread::threadedFunction(){
    while (toSending.receive(rotate_deg)) {
        string command = "ssh -i /Users/tmk-mac/Desktop/livehack_raspberrypi pi@169.254.184.112 'sudo python3 /home/pi/servo_controller.py " + ofToString(rotate_deg) + "'";
        system(command.c_str());
    }
}

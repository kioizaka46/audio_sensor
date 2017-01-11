#include "ofApp.h"
#include <stdlib.h>

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;
    camHeight = 240;
    sensor_interval_ms = 5000;
    execute_flag = true;
    rotate_degree = 0;
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber1.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber1.setDeviceID(0);
    vidGrabber2.setDeviceID(1);
    vidGrabber3.setDeviceID(3);
    vidGrabber1.setDesiredFrameRate(24);
    vidGrabber2.setDesiredFrameRate(24);
    vidGrabber3.setDesiredFrameRate(24);
    vidGrabber1.initGrabber(camWidth, camHeight);
    vidGrabber2.initGrabber(camWidth, camHeight);
    vidGrabber3.initGrabber(camWidth, camHeight);
    
    ofSetVerticalSync(true);
    next_execute_time = ofGetElapsedTimeMillis() + sensor_interval_ms;
    ofLogNotice() << ofGetSeconds();
    
    ofBackground(100, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    // toggle flag
    if(ofGetElapsedTimeMillis() >= next_execute_time) {
        execute_flag = true;
    }
    if(execute_flag){
        ofLogNotice() << "DO ANITHING!! : " << ofGetElapsedTimeMillis();
        if(rotate_degree == 180){
//            system("ssh -i /Users/tmk-mac/Desktop/livehack_raspberrypi pi@169.254.184.112 'sudo python3 /home/pi/servo_controller.py 0'");
//            system("sleep 2");

            rotate_degree = 0;
        }else{
//            system("ssh -i /Users/tmk-mac/Desktop/livehack_raspberrypi pi@169.254.184.112 'sudo python3 /home/pi/servo_controller.py 180'");
//            system("sleep 2");
            rotate_degree = 180;
        }
        
        next_execute_time += sensor_interval_ms;
        execute_flag = false;
    }
    
    vidGrabber1.update();
    vidGrabber2.update();
    vidGrabber3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber1.draw(20, 20);
    vidGrabber2.draw(20, 20 + camHeight + 20);
    vidGrabber3.draw(20, 20 + camHeight + 20 + camHeight + 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' || key == 'S'){
        vidGrabber1.videoSettings();
        vidGrabber2.videoSettings();
        vidGrabber3.videoSettings();
    }
    if(key == 'r'){
//        system("ssh -i /Users/tmk-mac/Desktop/livehack_raspberrypi pi@169.254.184.112 'sudo python3 /home/pi/servo_controller.py 180'");
        system("sleep 2");
        sender.sending(90);
    }
    if(key == 'e'){
//        system("ssh -i /Users/tmk-mac/Desktop/livehack_raspberrypi pi@169.254.184.112 'sudo python3 /home/pi/servo_controller.py 0'");
        system("sleep 2");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

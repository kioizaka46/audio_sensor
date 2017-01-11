#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofVideoGrabber vidGrabber1;
        ofVideoGrabber vidGrabber2;
        ofVideoGrabber vidGrabber3;
        int camWidth;
        int camHeight;
        int sensor_interval_ms;
        int next_execute_time;
        bool execute_flag;
    
        int rotate_degree;
        SendingThread sender;
};

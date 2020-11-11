#pragma once

#include "ofMain.h"
#include <randomRotateParticle.hpp>

#define PARTICLE_COUNT 15000
#define RANDOM_POINT 150

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
		
    ofVec3f randomPoint[RANDOM_POINT];
    randomRotateParticle par[PARTICLE_COUNT];
    ofEasyCam cam;
    int destinationNum[PARTICLE_COUNT];
    
};

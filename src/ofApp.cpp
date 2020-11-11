#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest();
    ofSetFullscreen(false);
    cam.setOrientation(ofPoint(-20, 0, 0));
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    for(int i = 0; i < RANDOM_POINT; i++){
        randomPoint[i] = ofVec3f(ofRandom(-1000, 1000),ofRandom(-1000, 1000),ofRandom(-1000, 1000));
    }
    for(int i = 0; i < PARTICLE_COUNT; i++){
        destinationNum[i] = int(ofRandom(RANDOM_POINT));
        par[i].init(ofVec3f(0, 0, 0), 1.0, ofRandom(5, 15), ofColor(ofRandom(255), ofRandom(100), ofRandom(100)), ofRandom(6.28), ofVec3f(1, 0, 0), ofRandom(0.1), ofRandom(6.28), ofRandom(20, 30));
        
    }
    ofSetBackgroundAuto(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
        
    for(int i = 0; i < PARTICLE_COUNT; i++){
        par[i].update();
    }
    for(int i = 0 ; i < PARTICLE_COUNT; i++){
        if(par[i]._pos.distance(randomPoint[destinationNum[i]]) < 20){
            int count = 0;
            vector<int> temp;
            for(int j = 0; j < RANDOM_POINT; j++){
                if(par[i]._pos.distance(randomPoint[j]) < 600){
                    temp.push_back(j);
                    count += 1;
                }
            }
            if(count != 0){
                int selectedNum = int(ofRandom(count-1));
                destinationNum[i] = temp[selectedNum];
            }
            count = 0;
            
        }
    }
    
    for(int i = 0; i < PARTICLE_COUNT; i++){
        par[i]._direction = (randomPoint[destinationNum[i]] - par[i]._pos).normalize();
        par[i]._color = ofColor((par[i]._pos.x + 1000)/2000*255,(par[i]._pos.y + 1000)/2000*255,(par[i]._pos.z + 1000)/2000*255);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for(int i = 0; i < PARTICLE_COUNT; i++){
        par[i].display();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

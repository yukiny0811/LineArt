//
//  randomRotateParticle.cpp
//  yayyay
//
//  Created by クワシマ・ユウキ on 2020/01/07.
//

#include "randomRotateParticle.hpp"

void randomRotateParticle::init(ofVec3f pos, float size, float speed, ofColor color, float rad, ofVec3f direction, float rotateSpeed, float rad2, float distance){
    _pos = pos;
    _size = size;
    _speed = speed;
    _color = color;
    _rad = rad;
    _direction = direction;
    _rotateSpeed = rotateSpeed;
    _rad2 = rad2;
    _distance = distance;
}

void randomRotateParticle::update(){
    savePos.push_back(_pos);
    saveRad.push_back(_rad);
    saveRad2.push_back(_rad2);
    _pos += _direction.normalize() * _speed;
    _rad += _rotateSpeed;
    _rad2 += _rotateSpeed;
    ofVec3f tempPos = ofVec3f(std::sin(_rad) * std::cos(_rad2),std::sin(_rad) * std::sin(_rad2), std::cos(_rad)) * _distance;
    _realPos = _pos + tempPos;
    if(savePos.size()> 15){
        savePos.erase(savePos.begin());
        saveRad.erase(saveRad.begin());
        saveRad2.erase(saveRad2.begin());
    }
}

void randomRotateParticle::display(){
    ofSetColor(_color);
    ofDrawSphere(_realPos, _size);
    
//    for(int i = 0; i < savePos.size(); i++){
//        ofVec3f tempPos = ofVec3f(std::sin(saveRad[i]) * std::cos(saveRad2[i]),std::sin(saveRad[i]) * std::sin(saveRad2[i]), std::cos(saveRad[i])) * _distance;
//        ofVec3f temp_realPos = savePos[i] + tempPos;
//        ofDrawSphere(temp_realPos, _size);
//
//    }
    ofVec3f tempPos = ofVec3f(std::sin(saveRad[0]) * std::cos(saveRad2[0]),std::sin(saveRad[0]) * std::sin(saveRad2[0]), std::cos(saveRad[0])) * _distance;
    ofVec3f temp_realPos = savePos[0] + tempPos;
    
    ofSetLineWidth(1);
    
    ofVec3f tempPos2 = ofVec3f(std::sin(saveRad[3]) * std::cos(saveRad2[3]),std::sin(saveRad[3]) * std::sin(saveRad2[3]), std::cos(saveRad[3])) * _distance;
    ofVec3f temp_realPos2 = savePos[3] + tempPos2;
    ofDrawLine(temp_realPos, temp_realPos2);
    
    ofSetLineWidth(1.25);
    
    ofVec3f tempPos3 = ofVec3f(std::sin(saveRad[6]) * std::cos(saveRad2[6]),std::sin(saveRad[6]) * std::sin(saveRad2[6]), std::cos(saveRad[6])) * _distance;
    ofVec3f temp_realPos3 = savePos[6] + tempPos3;
    ofDrawLine(temp_realPos2, temp_realPos3);
    
    ofSetLineWidth(1.5);
    
    ofVec3f tempPos4 = ofVec3f(std::sin(saveRad[9]) * std::cos(saveRad2[9]),std::sin(saveRad[9]) * std::sin(saveRad2[9]), std::cos(saveRad[9])) * _distance;
    ofVec3f temp_realPos4 = savePos[9] + tempPos4;
    ofDrawLine(temp_realPos3, temp_realPos4);
    
    ofSetLineWidth(1.75);
    
    ofVec3f tempPos5 = ofVec3f(std::sin(saveRad[12]) * std::cos(saveRad2[12]),std::sin(saveRad[12]) * std::sin(saveRad2[12]), std::cos(saveRad[12])) * _distance;
    ofVec3f temp_realPos5 = savePos[12] + tempPos5;
    ofDrawLine(temp_realPos4, temp_realPos5);
    
    ofSetLineWidth(2);
    
    ofDrawLine(temp_realPos5, _realPos);
}

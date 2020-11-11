//
//  randomRotateParticle.hpp
//  yayyay
//
//  Created by クワシマ・ユウキ on 2020/01/07.
//

#include "ofMain.h"

#ifndef randomRotateParticle_hpp
#define randomRotateParticle_hpp

#include <stdio.h>

#endif /* randomRotateParticle_hpp */

class randomRotateParticle{
public:
    void init(ofVec3f pos, float size, float speed, ofColor color, float rad, ofVec3f direction, float rotateSpeed, float rad2, float distance);
    void update();
    void display();
    float _size, _speed, _rad, _rotateSpeed, _rad2, _distance;
    ofVec3f _pos, _direction;
    ofColor _color;
private:
    ofVec3f _realPos;
    vector<ofVec3f> savePos;
    vector<float> saveRad;
    vector<float> saveRad2;
};

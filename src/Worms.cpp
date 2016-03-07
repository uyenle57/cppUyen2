//
//  Worms.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 1

#include "Worms.hpp"


Worms::Worms(float wormPosX, float wormPosY, float wormPosZ): Organism(wormPosX, wormPosY, wormPosZ) {
    mPosition.set(wormPosX, wormPosY, wormPosZ);
}

//Worms::~Worms() {
//    cout << "A worm has been eaten" << endl;
//}

//--------------------------------------------------------------
void Worms:: draw() {
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    rotate();
    
    for(int i=0; i < 80; i += 5) {
        if (i % 3 == 1) {
            bodyColor.set(0,0,255);
        } else if (i % 3 == 2) {
            bodyColor.set(220,130,255); //purple
        } else {
            bodyColor.set(255,0,0);
        }
        ofSetColor(bodyColor);
        ofDrawRectangle(0+wiggle(i), i,3,3);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
float Worms::wiggle(int m) {
    float letsWiggle = 5 * sin(ofDegToRad(float(m)+(ofGetFrameNum()/2)) * 10);
    return letsWiggle;
}

//--------------------------------------------------------------
void Worms:: swim() {   //Wander around
    float radius = 20;
    float distance = 80;
    
    wanderAngle += ofRandom(-0.3, 0.3);
    
    ofVec3f wanderAround = mVelocity; //an invisible position that leads the Worms
    wanderAround.normalize();
    wanderAround *= distance;
    wanderAround += mPosition;  //make 'wanderAround' relative to Worm's position
    
    ofVec3f wanderOffset(radius*(cos(wanderAngle)*0.5), radius*(sin(wanderAngle)*0.5) );
    ofVec3f target = wanderAround + wanderOffset;
    
    seekTarget(target);
}

void Worms::rotate() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x); //Make the Worms rotate according to velocity
    ofRotate( ofRadToDeg(mRotateTheta)+ofRadToDeg(3*PI/2) );
}


//--------------------------------------------------------------
void Worms::update() {
    organism_swimUpdate();  //from Base class Organism
    organism_returnToScreen();
    swim();
}


//
//  Animals.hpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals

//Behaviours: eat, reproduce, collision detection, change body colour, die

//probability of reproduction (+ reproduction rate)

//derived animals: frogs, flock of small fish, big fish

#ifndef Animals_hpp
#define Animals_hpp

#include <stdio.h>
#include "ofMain.h"


class Animals {

public:
    Animals(float x, float y, float z);
    
    //virtual ~Animals();

    //Variables: DNA
    ofVec3f mPosition, mVelocity, mAcceleration;
    
    ofColor bodyColor;
    
    bool bIsDead;
    
    float mLifeSpan; //die if out of food
    float mPosx, mPosy, mPosz;
    float mBorder = 2;

    // Behaviours (Pure virtual functions)
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void swim() = 0;
//    virtual void mate() = 0;
//    virtual void eat() = 0;
//    virtual void changeColor() = 0;
    
    void returnToScreen();
    
};
#endif /* Animals_hpp */

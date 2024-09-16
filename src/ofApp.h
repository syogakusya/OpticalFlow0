#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofVideoGrabber cam;
		ofxCv::FlowFarneback farneback;
		ofxCv::Flow* curFlow;

		ofxPanel gui;
		ofxFloatSlider pyrScale;
		ofxIntSlider levels;
		ofxIntSlider winSize;
		ofxIntSlider iterations;
		ofxIntSlider polyN;
		ofxFloatSlider polySigma;

};

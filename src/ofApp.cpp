#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
	cam.initGrabber(320, 240);//カメラ初期設定
	ofSetFrameRate(60);//フレームレート固定
	ofEnableBlendMode(OF_BLENDMODE_ADD);//色が

	gui.setup();
	gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
	gui.add(levels.setup("levels", 4, 1, 8));
	gui.add(winSize.setup("winsize", 12, 4, 64));
	gui.add(iterations.setup("iterations", 2, 1, 8));
	gui.add(polyN.setup("polyN", 7, 5, 10));
	gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
	curFlow = &farneback;
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
	if (cam.isFrameNew()) {
		farneback.setPyramidScale(pyrScale);
		farneback.setNumLevels(levels);
		farneback.setWindowSize(winSize);
		farneback.setNumIterations(iterations);
		farneback.setPolyN(polyN);
		farneback.setPolySigma(polySigma);
		farneback.setUseGaussian(OPTFLOW_FARNEBACK_GAUSSIAN);
		curFlow->calcOpticalFlow(cam);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	
	cam.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	curFlow->draw(0, 0, ofGetWidth(), ofGetHeight());

	gui.draw();
}


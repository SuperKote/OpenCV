#pragma once

#include "ofMain.h"
#include "ofxSTL.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void setVertices();
	int blurRadius;
	int thresholdValue;
	int depth;
	int alpha;
	int prevBlurRadiusValue;
	int prevThresholdValue;
	int prevDepthValue;
	int prevAlphaValue;

	vector<ofPoint> points;
	ofLight light, reflections;
	bool bSaveModel;
	ofEasyCam cam;	
	int verticesCount;
	ofVboMesh vboMesh;
};

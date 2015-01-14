#pragma once

#include "ofMain.h"
#include "ofxMarchingCubes.h"
#include "MetaBall.h"
#include "ofxSTL.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#define NUM_META_BALLS 1


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

	vector<ofPoint> points;
	ofxMarchingCubes marchingCubes;
	ofLight light, reflections;
	bool bSaveModel;
	ofEasyCam cam;
	ofMesh mesh;
};

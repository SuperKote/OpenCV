#include "testApp.h"


using namespace cv;

//--------------------------------------------------------------
void testApp::setup(){
	namedWindow("source", CV_WINDOW_AUTOSIZE );
	namedWindow("thresh", CV_WINDOW_AUTOSIZE );
	Mat src = imread("source.jpg", 1);
	Mat thresh;
	imshow("source",src);
	cvtColor( src, src, CV_BGR2GRAY );
	int blurRadius = 3;

	for(int z =0;z<15;++z)
	{
		threshold( src, thresh, 200, 255,THRESH_BINARY);
		
		for(int row = 0; row < thresh.rows; ++row) {
			for(int col = 0; col < thresh.cols; ++col) {
				uchar px = thresh.at<uchar>(cv::Point(row, col));
				if(px == 0){
					mesh.addVertex(ofVec3f(row,col,z));
					mesh.addColor(ofFloatColor(0,0,0));
				}
			}
			GaussianBlur( src, src, cv::Size(blurRadius , blurRadius ), 0, 0 );
		}
		ofEnableLighting();
		light.enable();    
		light.setup();
	}
}
//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	cam.begin();
	mesh.drawWireframe();
	cam.end();
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key == ' ')bSaveModel = true;
}

void testApp::keyPressed(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){ }

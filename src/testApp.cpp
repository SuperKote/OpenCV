#include "testApp.h"

using namespace cv;

void testApp::setVertices(){
	Mat src = imread("source.jpg", 1);
	Mat thresh;
	imshow("source",src);
	cvtColor( src, src, CV_BGR2GRAY );
	vboMesh.clear();
	verticesCount = 0;
	for(int z =0;z<depth;++z)
	{
		threshold( src, thresh, thresholdValue, 255,THRESH_BINARY);			
		for(int row = 1; row < thresh.rows-1; ++row) {
			for(int col = 1; col < thresh.cols-1; ++col) {
				if(thresh.at<uchar>(cv::Point(row, col))==0
					&& (thresh.at<uchar>(cv::Point(row-1, col-1)) != 0
					|| thresh.at<uchar>(cv::Point(row-1, col)) != 0
					|| thresh.at<uchar>(cv::Point(row-1, col+1)) != 0
					|| thresh.at<uchar>(cv::Point(row, col-1)) != 0
					|| thresh.at<uchar>(cv::Point(row, col+1)) != 0
					|| thresh.at<uchar>(cv::Point(row+1, col-1)) != 0
					|| thresh.at<uchar>(cv::Point(row+1, col)) != 0
					|| thresh.at<uchar>(cv::Point(row+1, col+1)) != 0
					|| z == depth-1))
				{
					vboMesh.addVertex(ofVec3f(row - src.rows/2, src.cols/2 -col,z));
					vboMesh.addColor(ofFloatColor(ofColor(100,alpha)));
					verticesCount++;
				}
			}			
		}
		GaussianBlur( src, src, cv::Size(blurRadius , blurRadius ), 0, 0 );
	}
	prevBlurRadiusValue = blurRadius;
	prevThresholdValue = thresholdValue;
	prevDepthValue = depth;
	prevAlphaValue = alpha;
}

//--------------------------------------------------------------
void testApp::setup(){
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	glPointSize(15);
	namedWindow("source", CV_WINDOW_AUTOSIZE );
	namedWindow("trackBars", CV_WINDOW_AUTOSIZE );
	blurRadius = 3;
	thresholdValue = 150;	
	depth = 20;
	alpha = 40;
	cam.setDistance(100);
	createTrackbar("blurRadius", "trackBars", &blurRadius, 15);
	createTrackbar("threshold", "trackBars", &thresholdValue, 255);
	createTrackbar("depth", "trackBars", &depth, 100);
	createTrackbar("alpha", "trackBars", &alpha, 100);
	setVertices();

	ofEnableLighting();
	light.enable();    
	light.setup();
}	

//--------------------------------------------------------------
void testApp::update(){
	if(prevBlurRadiusValue != blurRadius
		|| prevThresholdValue != thresholdValue
		|| prevDepthValue != depth
		|| prevAlphaValue != alpha)
		setVertices();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor(255,255,255));
	cam.begin();
	vboMesh.drawVertices();
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

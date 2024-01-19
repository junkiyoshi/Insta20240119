#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofBeginShape();

	for (int y = -230; y <= 230; y += 230) {

		for (int i = 0; i < 6; i++) {

			auto radius = 50 * ofMap(i, 0, 6, 0.5, 1.8);
			auto noise_seed = ofRandom(1000);
			auto x = ofMap(ofNoise(noise_seed, ofGetFrameNum() * 0.0075), 0, 1, -320, 320);

			for (int deg = 0; deg < 360; deg += 1) {

				auto vertex = glm::vec2(x + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));

				ofVertex(vertex);

			}

			if (i % 2 == 1) {

				ofNextContour(true);
			}
			else {

				ofNextContour(false);
			}
		}
	}
	ofEndShape();

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
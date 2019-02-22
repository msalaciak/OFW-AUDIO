#include "ofApp.h"


// This example teach you to create your own synth / modules
// you can also check the src/modules folder in the ofxPDSP source code for other examples
// check the custom synth in the synth.h file

//--------------------------------------------------------------
void ofApp::setup(){

    
    
    
    //--------PATCHING-------
    
    Synth * 0.5f >> engine.audio_out(0);
    Synth * 0.5f >> engine.audio_out(1);


    
    

    



    //------------SETUPS AND START AUDIO-------------
    engine.listDevices();
    engine.setDeviceID(1); // REMEMBER TO SET THIS AT THE RIGHT INDEX!!!!
    engine.setup( 44100, 512, 2);
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
//    ofDrawBitmapString("hover the mouse in the window, \nx = pitch, y = amp/filter", 50, 50);

  
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    float gain = ofMap(y,0.0f, ofGetHeight(),1.0f,0.0f);
    float p = ofMap(x,0.0f,ofGetWidth(),48.f,84.f);
    gain >> Synth.in("amp");
    p >> Synth.in("pitch");
  
    
   
    
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

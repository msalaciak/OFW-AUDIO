#include "ofApp.h"


// This example teach you to create your own synth / modules
// you can also check the src/modules folder in the ofxPDSP source code for other examples
// check the custom synth in the synth.h file

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("synth");
    
    
    Synth.patch();
    Synth.setUI();
    
    
    
    //--------PATCHING-------
    
    
    Synth * 0.5f >> engine.audio_out(0);
    Synth * 0.5f >> engine.audio_out(1);



    gui.setHeaderBackgroundColor(ofColor(0,40,40));
    gui.setBorderColor(ofColor(0,40,40));
    
    gui.setDefaultFillColor(ofColor(0,90,90));
    gui.setDefaultBackgroundColor(ofColor(0,0,0));
    gui.setup("panel");
    gui.add(Synth.getUiEnv());
    gui.add(Synth.getUiFilter());
    gui.add(Synth.getUiLFO());
    gui.add(Synth.getUiLFO2());
    gui.add(Synth.getUiAmp());
    gui.setPosition(0,40 );

    



    //------------SETUPS AND START AUDIO-------------
    engine.listDevices();
    engine.setDeviceID(1); // REMEMBER TO SET THIS AT THE RIGHT INDEX!!!!
    engine.setup( 44100, 512, 2);
//
    scope.set(4096);
    Synth * dB(-6.0f) >> scope >> engine.blackhole();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
//    ofDrawBitmapString("hover the mouse in the window, \nx = pitch, y = amp/filter", 50, 50);
    gui.draw();
  
     scope.draw(280, 70, 400, 400);
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float pitch = ofMap(x,0,ofGetWidth(),36.0f,72.0f);
    Synth.setPitch(pitch);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
 
    
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    float pitch = ofMap(x,0,ofGetWidth(),36.0f,72.0f);
    Synth.setPitch(pitch);
    
 
    
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
   

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 32) {
       
        Synth.setTrigger(1.0f);
        
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 32) {
         Synth.trigOff();
        
    }

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

//
//  synth.hpp
//  audioTest
//
//  Created by Matt Salaciak on 2019-02-22.
//



#include "ofxPDSP.h"
#include <vector>
#pragma once


// to create your own modules, you have to extend pdsp::Patchable

class synth : public pdsp::Patchable {
    
public:
    
  
    synth();
        
        
    void patch();
   
    void setPitch(float pitch);
    void setTrigger(float gate);
    void trigOff();
    void setUI();
    inline ofParameterGroup getUi() {return ui;}
    
    
 
    
    
      
    
private:
    pdsp::Amp amp;
    pdsp::VAOscillator osc;
    pdsp::ADSR env;
    pdsp::TriggerControl gate_control;
    pdsp::ValueControl pitch_control;
    float pitch;
    float gate;
    ofParameterGroup ui;
    pdsp::Parameter attack;
    pdsp::Parameter decay;
    pdsp::Parameter sustain;
    pdsp::Parameter release;
    
    
   
    
  
    
};


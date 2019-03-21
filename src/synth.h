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
    inline ofParameterGroup getUiEnv() {return uiEnv;}
    inline ofParameterGroup getUiFilter() {return uiFilter;}
    inline ofParameterGroup getUiLFO() {return uiLFO;}
    inline ofParameterGroup getUiLFO2() {return uiLFO2;}
    inline ofParameterGroup getUiAmp() {return uiAmp;}
    inline ofParameterGroup getUiOsc() {return uiOSC;}

    

    
    
 
    
    
      
    
private:
    pdsp::Amp amp;
    pdsp::Amp lfo_osc1_amp;
    pdsp::Amp lfo_filter1_amp;
    pdsp::Amp lfo_osc2_amp;
    pdsp::Amp lfo_filter2_amp;
    pdsp::Amp osc_amp;
   
    pdsp::VAOscillator osc1;
    
    pdsp::ADSR env;
    pdsp::LFO lfo1;
     pdsp::LFO lfo2;
    
    pdsp::TriggerControl gate_control;
    pdsp::ValueControl pitch_control;
    pdsp::VAFilter filter;
    
    float pitch;
    float gate;
    
    
    
    //parameter groups of synth
    ofParameterGroup uiEnv;
    ofParameterGroup uiFilter;
    ofParameterGroup uiLFO;
    ofParameterGroup uiLFO2;
    ofParameterGroup uiAmp;
    ofParameterGroup uiOSC;
    
    //osc controls
    pdsp::Parameter oscWaveForms;
    pdsp::Parameter oscAmount;
    pdsp::Switch oscSwitch;
    
    //amp controls
    pdsp::Parameter drone;
    
    //envelope controls
    pdsp::Parameter attack;
    pdsp::Parameter decay;
    pdsp::Parameter sustain;
    pdsp::Parameter release;
    
    //filter controls
    pdsp::Parameter cutoff;
    pdsp::Parameter resonance;
    pdsp::Parameter filterMode;

    //lfo1 controls
    pdsp::Parameter lfo1_speed;
    pdsp::Parameter lfo1_shape;
    pdsp::Parameter lfo1_to_osc_amt;
    pdsp::Parameter lfo1_to_filter_amt;
   
    pdsp::Switch lfo1_switch;
    
    //lfo2 controls
    pdsp::Parameter lfo2_speed;
    pdsp::Parameter lfo2_shape;
    pdsp::Parameter lfo2_to_osc_amt;
    pdsp::Parameter lfo2_to_filter_amt;
    
    pdsp::Switch lfo2_switch;
    
    //reverb
    pdsp::BasiVerb reverb;
  
    
};


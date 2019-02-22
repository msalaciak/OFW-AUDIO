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
   
    
    
    
    
    
private:
    pdsp::Amp amp;
    pdsp::FMOperator osc;
  
    
};


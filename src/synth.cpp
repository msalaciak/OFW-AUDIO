//
//  synth.cpp
//  audioTest
//
//  Created by Matt Salaciak on 2019-02-22.
//

#include "synth.h"

synth :: synth(){
    addModuleInput("amp", amp.in_mod());
    addModuleInput("pitch", osc.in_pitch());
    addModuleOutput("signal", amp);
    
    osc>> amp;
}
 







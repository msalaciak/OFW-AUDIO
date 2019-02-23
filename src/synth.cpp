//
//  synth.cpp
//  audioTest
//
//  Created by Matt Salaciak on 2019-02-22.
//

#include "synth.h"

synth :: synth(){
    
    
}


void synth :: setUI() {
    ui.setName("ENV CONTROL");
    ui.add(attack.set("Attack", 0.0f, 0.0f, 5000.0f));
    ui.add(decay.set("Decay", 50.0f, 0.0f, 5000.0f));
    ui.add(sustain.set("Sustain",0.5f,0.0f,5000.0f));
    ui.add(release.set("Release",500.0f,0.0f,5000.0f));
    
    
    
    
}

void synth :: patch() {
    
    addModuleInput("pitch", osc.in_pitch());
    addModuleOutput("signal", amp);
    
    
    gate_control.out_trig()>> env;
    env>>amp.in_mod();
    
    pitch_control >> osc.in_pitch();
    osc.out_pulse() * dB(-12.0f) >> amp;
    
    attack >> env.in_attack();
    decay >> env.in_decay();
    sustain >> env.in_sustain();
    release >> env.in_release();
    
    pitch_control.set(72.0f);
    pitch_control.enableSmoothing(50.0f);
    

    
}

void synth :: setPitch(float pitch){
    pitch_control.set(pitch);
    
    
    
}

void synth:: setTrigger(float gate) {
    gate_control.trigger(gate);
    
}


void synth:: trigOff(){
    gate_control.off();
    
}



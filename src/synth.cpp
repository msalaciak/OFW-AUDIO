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
    
    uiOSC.setName("OSC WAVEFORMS");
    uiOSC.add(oscWaveForms.set("WaveForms",0,0,3));
    uiOSC.add(oscAmount.set("OSC Amount",1.0f,0.0f,10.0f));
    
    uiEnv.setName("ENV CONTROL");
    uiEnv.add(attack.set("Attack", 0.0f, 0.0f, 5000.0f));
    uiEnv.add(decay.set("Decay", 50.0f, 0.0f, 5000.0f));
    uiEnv.add(sustain.set("Sustain",0.5f,0.0f,1.0f));
    uiEnv.add(release.set("Release",500.0f,0.0f,5000.0f));
    
    uiFilter.setName("FILTER CONTROL");
    uiFilter.add(cutoff.set("Cutoff", 82,20,136));
    uiFilter.add(resonance.set("Resonance", 0.0f, 0.0f, 1.0f));
    uiFilter.add(filterMode.set("Filter Mode", 0, 0, 5));


    uiLFO.setName("LFO 1 CONTROL");
    uiLFO.add(lfo1_shape.set("LFO Wave",0,0,4));
    uiLFO.add(lfo1_speed.set("LFO Freq",0.5f,0.005f,50.0f));
    uiLFO.add(lfo1_to_osc_amt.set("LFO to OSC",0.0f,0.0f,50.0f));
    uiLFO.add(lfo1_to_filter_amt.set("LFO to Filter",0.f,0.f,200.f));

    uiLFO2.setName("LFO 2 CONTROL");
    uiLFO2.add(lfo2_shape.set("LFO Wave",0,0,4));
    uiLFO2.add(lfo2_speed.set("LFO Freq",0.5f,0.005f,50.0f));
    uiLFO2.add(lfo2_to_osc_amt.set("LFO to OSC",0.0f,0.0f,50.0f));
    uiLFO2.add(lfo2_to_filter_amt.set("LFO to Filter RES",0.f,0.f,200.f));

    uiAmp.setName("AMP CONTROL");
    uiAmp.add(drone.set("Drone Amount",0.0f,0.0f,4.0f));
    
    
 
    
}



void synth :: patch() {
    
    addModuleInput("pitch", osc1.in_pitch());
    
    addModuleOutput("signal", amp);

   
   
    
    
    
    //drone & reverb
    drone>>amp.in_mod();
    
  
   
    //env controls
    
    attack >> env.in_attack();
    decay >> env.in_decay();
    sustain >> env.in_sustain();
    release >> env.in_release();
    
    
    
    //filter controls
    cutoff >> filter.in_cutoff();
    
 
    resonance >> filter.in_reso();
    
    //filter switch
    filterMode>>filter.in_mode();
    
  
    //pitch controls
    pitch_control.set(72.0f);
    pitch_control.enableSmoothing(50.0f);
    
    
    
    //osc controls & switches
    oscSwitch.resize(4);
    osc1.out_pulse() >> oscSwitch.input(0);
    osc1.out_triangle() >> oscSwitch.input(1);
    osc1.out_saw() >> oscSwitch.input(2);
    osc1.out_sine() >> oscSwitch.input(3);

    oscWaveForms >> oscSwitch.in_select();
    oscSwitch >> osc_amp;
    oscAmount >> osc_amp.in_mod();
    
    
    //lfo switches & controls
    lfo1_switch.resize(5);
    lfo1.out_saw() >> lfo1_switch.input(0);
    lfo1.out_sine() >> lfo1_switch.input(1);
    lfo1.out_sample_and_hold() >> lfo1_switch.input(2);
    lfo1.out_triangle() >> lfo1_switch.input(3);
    lfo1.out_square() >> lfo1_switch.input(4);
    
    
    lfo1_shape >> lfo1_switch.in_select();
    lfo1_speed >> lfo1.in_freq();
    lfo1_switch >> lfo_filter1_amp;
    lfo1_switch >> lfo_osc1_amp;
    
    lfo1_to_filter_amt >> lfo_filter1_amp.in_mod();
    lfo1_to_osc_amt >> lfo_osc1_amp.in_mod();
    
    lfo_osc1_amp >>osc1.in_pitch();
    lfo_filter1_amp>>filter.in_pitch();
    
    //lfo 2 controls
    lfo2_switch.resize(5);
    lfo2.out_saw() >> lfo2_switch.input(0);
    lfo2.out_sine() >> lfo2_switch.input(1);
    lfo2.out_sample_and_hold() >> lfo2_switch.input(2);
    lfo2.out_triangle() >> lfo2_switch.input(3);
    lfo2.out_saw() >> lfo2_switch.input(4);
    
    
    lfo2_shape >> lfo2_switch.in_select();
    lfo2_speed >> lfo2.in_freq();
    lfo2_switch >> lfo_filter2_amp;
    lfo2_switch >> lfo_osc2_amp;
    
    lfo2_to_filter_amt >> lfo_filter2_amp.in_mod();
    lfo2_to_osc_amt >> lfo_osc2_amp.in_mod();
    
    lfo_osc2_amp >>osc1.in_pitch();
    lfo_filter2_amp>>filter.in_reso();
    
    
    

    //patching & gating
    gate_control.out_trig()>> env;
    env>>amp.in_mod();
    
    
    
    pitch_control >> osc1.in_pitch();
    
    
    osc_amp  >>filter >> amp;
    
    
  
  
    

    

    
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




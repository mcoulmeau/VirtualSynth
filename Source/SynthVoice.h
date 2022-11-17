/*
  ==============================================================================

    SynthVoice.h
    Created: 18 Oct 2022 2:55:20pm
    Author:  Julien Audoux

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
    public :
    
    bool canPlaySound(juce::SynthesiserSound* Sound) override;
    void startNote(int midiNoteNumnber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
    
    private :
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    juce::AudioBuffer<float> synthBuffer;
    //sin wave : std::sin(x)
    //saw wave : x / juce::MathConstants<float>::pi
    //square wave : x < 0.0f ? -1.0f : 1.0f
    juce::dsp::Oscillator<float> osc { [](float x) {return x < 0.0f ? -1.0f : 1.0f;}, 200};
    juce::dsp::Gain<float> gain;
    
    bool isPrepared {false};
};

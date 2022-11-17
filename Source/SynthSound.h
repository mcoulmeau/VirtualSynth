/*
  ==============================================================================

    SynthSound.h
    Created: 18 Oct 2022 2:57:08pm
    Author:  Julien Audoux

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
    public : bool appliesToNote(int midiNoteNumber) override {return true;}
    public : bool appliesToChannel(int midiChannel) override {return true;}
};

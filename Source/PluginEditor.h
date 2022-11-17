/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VirtualSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VirtualSynthAudioProcessorEditor (VirtualSynthAudioProcessor&);
    ~VirtualSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    juce::ComboBox oscSelector;
    
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VirtualSynthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VirtualSynthAudioProcessorEditor)
};

// This is where we declare all of our objects that we want to create

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainTutorial20AudioProcessorEditor  : public AudioProcessorEditor,
                                            public Slider::Listener
{
public:
    GainTutorial20AudioProcessorEditor (GainTutorial20AudioProcessor&);
    ~GainTutorial20AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider* slider) override;

private:
    Slider mGainSlider;
    
    GainTutorial20AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainTutorial20AudioProcessorEditor)
};

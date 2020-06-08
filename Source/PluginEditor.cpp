// This is for the user interface

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
// This is the constructor, where we set the values for the visual elements
// Gets called once, when the plugin is created
GainTutorial20AudioProcessorEditor::GainTutorial20AudioProcessorEditor (GainTutorial20AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    mGainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-60.0f, 0.0f, 0.01);
    mGainSlider.setValue(-20.0f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    
    
    setSize (200, 300);
}

// This is the destructor
// Gets called when the plugin is closed
GainTutorial20AudioProcessorEditor::~GainTutorial20AudioProcessorEditor()
{
}

//==============================================================================
// This is the paint function
// Gets called periodically, refreshes the visual screen that the user sees
void GainTutorial20AudioProcessorEditor::paint (Graphics& g)
{
    // Make the background black
    g.fillAll(Colours::black);
    
}

// Resized function
// You can change the layout of the visual elements here
void GainTutorial20AudioProcessorEditor::resized()
{
    // Draw the slider
    mGainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void GainTutorial20AudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider == &mGainSlider)
    {
        processor.mGain = mGainSlider.getValue();
    }
}

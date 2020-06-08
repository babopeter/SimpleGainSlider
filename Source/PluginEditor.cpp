#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
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

GainTutorial20AudioProcessorEditor::~GainTutorial20AudioProcessorEditor()
{
}

//==============================================================================
void GainTutorial20AudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    
}

void GainTutorial20AudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void GainTutorial20AudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider == &mGainSlider)
    {
        processor.mGain = mGainSlider.getValue();
    }
}

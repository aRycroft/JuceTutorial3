/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	addAndMakeVisible(&disChoice);
	disChoice.addItem("Hard Clip", 1);
	disChoice.addItem("Soft Clip", 2);
	disChoice.addItem("Half-Wave Rect", 3);
	disChoice.setSelectedId(1);
	disChoice.addListener(this);

	addAndMakeVisible(&Threshold);
	Threshold.setRange(0.0f, 1.0f, 0.001);
	Threshold.addListener(this);

	addAndMakeVisible(&Mix);
	Mix.setRange(0.0f, 1.0f, 0.001);
	Mix.addListener(this);	
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
		
}

void DistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	disChoice.setBounds(50, 50, 200, 50);
	Threshold.setBounds(50, 100, 200, 50);
	Mix.setBounds(50, 150, 200, 50);
}

void DistortionAudioProcessorEditor::comboBoxChanged(ComboBox *comboBoxThatWasChanged)
{

	processor.menuChoice = comboBoxThatWasChanged->getSelectedId();
}


void DistortionAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	if (&Mix == slider) 
	{
		processor.mix = Mix.getValue();
	}
	if (&Threshold == slider)
	{
		processor.thresh = Threshold.getValue();
	}
}


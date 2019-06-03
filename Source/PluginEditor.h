/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DistortionAudioProcessorEditor : 
	public 
	AudioProcessorEditor,
	private 
	ComboBox::Listener,
	Slider::Listener
{
public:
	DistortionAudioProcessorEditor(DistortionAudioProcessor&);
	~DistortionAudioProcessorEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

private:
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
	void sliderValueChanged(Slider* sliderThatHasChanged) override;
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	DistortionAudioProcessor& processor;
	ComboBox disChoice;
	Slider Threshold;
	Slider Mix;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistortionAudioProcessorEditor)
};

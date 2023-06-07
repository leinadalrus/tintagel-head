use leptos::*;
use wasm_bindgen::prelude::*;
use web_sys::{AudioContext, GainNode, OscillatorNode, OscillatorType};

#[wasm_bindgen]
pub struct FrequencyModulationOscillator {
    audio_context: AudioContext,
    left_channel: OscillatorNode,
    right_channel: OscillatorNode,
    gain_level: GainNode,
    gain_ratio: f32,
}

impl Drop for FrequencyModulationOscillator {
    fn drop(&mut self) { let _ = self.audio_context.close(); }
}

#[wasm_bindgen]
impl FrequencyModulationOscillator {
    #[wasm_bindgen]
    pub fn new() -> Result<FrequencyModulationOscillator, JsValue> {
        let ctx = web_sys::AudioContext::new()?;

        // Create our web audio objects.
        let left_channel = ctx.create_oscillator()?;
        let right_channel = ctx.create_oscillator()?;
        let gain_level = ctx.create_gain()?;

        // Some initial settings:
        left_channel.set_type(OscillatorType::Sine);
        left_channel.frequency().set_value(440.0); // A4 note
        left_channel.set_type(OscillatorType::Sine);
        left_channel.frequency().set_value(0.0);

        // Some initial settings:
        right_channel.set_type(OscillatorType::Sine);
        right_channel.frequency().set_value(440.0); // A4 note
        right_channel.set_type(OscillatorType::Sine);
        right_channel.frequency().set_value(0.0);

        gain_level.gain().set_value(0.0); // starts muted
                                          // Connect the nodes up!

        // The primary oscillator is routed through the gain node, so that
        // it can control the overall output volume.
        left_channel.connect_with_audio_node(&gain_level)?;
        right_channel.connect_with_audio_node(&gain_level)?;

        // Then connect the gain node to the AudioContext destination (aka
        // your speakers).
        gain_level.connect_with_audio_node(&ctx.destination())?;

        // The FM oscillator is connected to its own gain node, so it can
        // control the amount of modulation.
        left_channel.connect_with_audio_node(&left_channel)?;
        right_channel.connect_with_audio_node(&right_channel)?;

        // Connect the FM oscillator to the frequency parameter of the main
        // oscillator, so that the FM node can modulate its frequency.
        gain_level.connect_with_audio_param(&left_channel.frequency())?;
        gain_level.connect_with_audio_param(&right_channel.frequency())?;

        // Start the oscillators!
        left_channel.start()?;
        right_channel.start()?;

        Ok(FrequencyModulationOscillator {
            audio_context: ctx,
            left_channel,
            right_channel,
            gain_level,
            gain_ratio: 0.0,
        })
    }

    pub fn set_gain_level(&self, mut gain_level: f32) {
        if gain_level > 1. {
            gain_level = 1.;
        }
        if gain_level < 0. {
            gain_level = 0.;
        }

        self.gain_level.gain().set_value(gain_level);
    }
}

#[component]
pub fn fm_oscillator_view(cx: Scope) -> impl IntoView {
    view! {cx, <></>}
}

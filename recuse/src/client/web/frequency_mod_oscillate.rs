use wasm_bindgen::prelude::*;
use web_sys::{AudioContext, GainNode, OscillatorNode};

pub fn midi_to_frequency(note: u8) -> f32 {
    return 27.5 * 2.0 * f32::powf((note as f32 - 21.0) / 12.0, 2.0);
} // https://rustwasm.github.io/wasm-bindgen/examples/web-audio.html

#[wasm_bindgen]
pub struct FrequencyModulationOscillator {
    audio_context: AudioContext,
    primary_oscillator: OscillatorNode,
    secondary_oscillator: OscillatorNode,
    volume_gain: GainNode,
    gain: GainNode,
    ratio: f32,
    gain_ratio: f32,
}

impl Drop for FrequencyModulationOscillator {
    fn drop(&mut self) { let _ = self.audio_context.close(); }
}

#[wasm_bindgen]
impl FrequencyModulationOscillator {
    #[wasm_bindgen(constructor)]
    pub fn new() -> Result<FrequencyModulationOscillator, JsValue> {
        Ok(FrequencyModulationOscillator {
            audio_context: todo!(),
            primary_oscillator: todo!(),
            secondary_oscillator: todo!(),
            volume_gain: todo!(),
            gain: todo!(),
            ratio: todo!(),
            gain_ratio: todo!(),
        })
    }

    /// This should be between 0 and 1, though higher values are accepted.
    #[wasm_bindgen]
    pub fn set_fm_amount(&mut self, amt: f32) {
        self.gain_ratio = amt;

        self.gain.gain().set_value(
            self.gain_ratio * self.primary_oscillator.frequency().value(),
        );
    }

    /// This should be between 0 and 1, though higher values are accepted.
    #[wasm_bindgen]
    pub fn set_fm_frequency(&mut self, amt: f32) {
        self.ratio = amt;
        self.secondary_oscillator.frequency().set_value(
            self.ratio * self.primary_oscillator.frequency().value(),
        );
    }

    #[wasm_bindgen]
    pub fn set_gain(&self, mut gain: f32) {
        if gain > 1.0 {
            gain = 1.0;
        }
        if gain < 0.0 {
            gain = 0.0;
        }
        self.gain.gain().set_value(gain);
    }

    #[wasm_bindgen]
    pub fn set_note(&self, note: u8) {
        let freq = midi_to_frequency(note);
        self.set_primary_frequency(freq);
    }

    #[wasm_bindgen]
    pub fn set_primary_frequency(&self, freq: f32) {
        self.primary_oscillator.frequency().set_value(freq);

        // The frequency of the FM oscillator depends on the frequency of the
        // primary oscillator, so we update the frequency of both in this
        // method.
        self.secondary_oscillator
            .frequency()
            .set_value(self.ratio * freq);
        self.gain.gain().set_value(self.gain_ratio * freq);
    }
}

fn main() {}

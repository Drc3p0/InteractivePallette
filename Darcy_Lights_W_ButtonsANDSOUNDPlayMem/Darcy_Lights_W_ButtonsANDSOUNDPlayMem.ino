//on, fade after release
//for audio to work and leds to not flicker, put interrupt BEFORE #include FastLED.h
//used for SOAK art grant
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#define FASTLED_ALLOW_INTERRUPTS 0

#include <FastLED.h>
#include "AudioSampleBeat1.h"
#include "AudioSampleBeat2.h"
#include "AudioSampleBeat3.h"
#include "AudioSampleBeat4.h"
#include "AudioSampleBeat5.h"
#include "AudioSampleBeat6.h"
#include "AudioSampleBeat7.h"
#include "AudioSampleBeat8.h"
#include "AudioSampleBeat9.h"
#include "AudioSampleBeat10.h"

// GUItool: begin automatically generated code
AudioPlayMemory          playMem3;       //xy=385.5555419921875,235.2222137451172
AudioPlayMemory          playMem2;       //xy=387.5555419921875,194.2222137451172
AudioPlayMemory          playMem4;       //xy=389.8888931274414,268.33335971832275
AudioPlayMemory          playMem1;       //xy=399.5555419921875,162.2222137451172
AudioPlayMemory          playMem5;       //xy=418.5555419921875,336.2222137451172
AudioPlayMemory          playMem6;       //xy=430.5555419921875,369.2222137451172
AudioPlayMemory          playMem9;       //xy=448.5555419921875,473.2222137451172
AudioPlayMemory          playMem8;       //xy=451.5555419921875,438.2222137451172
AudioPlayMemory          playMem10;      //xy=459.5555419921875,518.2222137451172
AudioPlayMemory          playMem7;       //xy=463.5555419921875,403.2222137451172
AudioMixer4              Mix1;           //xy=639.5555419921875,202.2222137451172
AudioMixer4              Mix2;           //xy=773.6666564941406,332.66669845581055
AudioMixer4              Mix3;           //xy=1083.6667518615723,348.88890647888184
AudioOutputI2S           i2s2;           //xy=1275.1112747192383,345.7778148651123
AudioConnection          patchCord1(playMem3, 0, Mix1, 2);
AudioConnection          patchCord2(playMem2, 0, Mix1, 1);
AudioConnection          patchCord3(playMem4, 0, Mix1, 3);
AudioConnection          patchCord4(playMem1, 0, Mix1, 0);
AudioConnection          patchCord5(playMem5, 0, Mix2, 1);
AudioConnection          patchCord6(playMem6, 0, Mix2, 2);
AudioConnection          patchCord7(playMem9, 0, Mix3, 2);
AudioConnection          patchCord8(playMem8, 0, Mix2, 0);
AudioConnection          patchCord9(playMem10, 0, Mix3, 3);
AudioConnection          patchCord10(playMem7, 0, Mix2, 3);
AudioConnection          patchCord11(Mix1, 0, Mix3, 0);
AudioConnection          patchCord12(Mix2, 0, Mix3, 1);
AudioConnection          patchCord13(Mix3, 0, i2s2, 0);
AudioConnection          patchCord14(Mix3, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=891.5555419921875,210.2222137451172
// GUItool: end automatically generated code

#define NUM_LEDS 20
#define DATA_PIN 8
#define TOUCHPAD1 0
#define TOUCHPAD2 1
#define TOUCHPAD3 2
#define TOUCHPAD4 3
#define TOUCHPAD5 4
#define TOUCHPAD6 5
#define TOUCHPAD7 21
#define TOUCHPAD8 20
#define TOUCHPAD9 17
#define TOUCHPAD10 16


CRGB leds[NUM_LEDS];
int brightness = 0;
int r = 0;
int g = 0;
int b = 0;

int threshold = 2000;
int i1 = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;
int i5 = 0;
int i6 = 0;
int i7 = 0;
int i8 = 0;
int i9 = 0;
int i10 = 0;

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14
// Touch pad values
int touch1 = 0;
int touch2 = 0;
int touch3 = 0;
int touch4 = 0;
int touch5 = 0;
int touch6 = 0;
int touch7 = 0;
int touch8 = 0;
int touch9 = 0;
int touch10 = 0;


void dimAllLeds() {
  // Turn all the lights off
  for (size_t i = 0; i < NUM_LEDS; i++) {
    // leds[i] = CRGB::Black;
    leds[i].fadeToBlackBy(10000);
    FastLED.delay(3);

  }
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(13, OUTPUT);
  AudioMemory(100);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.8);
  Mix1.gain(0, 0.80);
  Mix1.gain(1, 0.80);
  Mix1.gain(2, 0.80);
  Mix1.gain(3, 0.80);
  Mix2.gain(0, 0.80);
  Mix2.gain(1, 0.80);
  Mix2.gain(2, 0.80);
  Mix2.gain(3, 0.80);
  Mix3.gain(0, 0.80);
  Mix3.gain(1, 0.80);
  Mix3.gain(2, 0.80);
  Mix3.gain(3, 0.80);

  pinMode(TOUCHPAD1, INPUT_PULLUP);
  pinMode(TOUCHPAD2, INPUT_PULLUP);
  pinMode(TOUCHPAD3, INPUT_PULLUP);
  pinMode(TOUCHPAD4, INPUT_PULLUP);
  pinMode(TOUCHPAD5, INPUT_PULLUP);
  pinMode(TOUCHPAD6, INPUT_PULLUP);
  pinMode(TOUCHPAD7, INPUT_PULLUP);
  pinMode(TOUCHPAD8, INPUT_PULLUP);
  pinMode(TOUCHPAD9, INPUT_PULLUP);
  pinMode(TOUCHPAD10, INPUT_PULLUP);

}

void loop() {
  digitalWrite(13, HIGH);
  touch1 = digitalRead(TOUCHPAD1);
  touch2 = digitalRead(TOUCHPAD2);
  touch3 = digitalRead(TOUCHPAD3);
  touch4 = digitalRead(TOUCHPAD4);
  touch5 = digitalRead(TOUCHPAD5);
  touch6 = digitalRead(TOUCHPAD6);
  touch7 = digitalRead(TOUCHPAD7);
  touch8 = digitalRead(TOUCHPAD8);
  touch9 = digitalRead(TOUCHPAD9);
  touch10 = digitalRead(TOUCHPAD10);

  // Debugging prints
  //     Serial.print("TouchPad 1 Value: "); Serial.println(touch1);
  //     Serial.print("TouchPad 2 Value: "); Serial.println(touch2);
  //     Serial.print("TouchPad 3 Value: "); Serial.println(touch3);
  //     Serial.print("TouchPad 4 Value: "); Serial.println(touch4);
  //     Serial.print("TouchPad 5 Value: "); Serial.println(touch5);
  //     Serial.print("TouchPad 6 Value: "); Serial.println(touch6);
  //     Serial.print("TouchPad 7 Value: "); Serial.println(touch7);
  //     Serial.print("TouchPad 8 Value: "); Serial.println(touch8);
  //     Serial.print("TouchPad 9 Value: "); Serial.println(touch9);
  //     Serial.print("TouchPad 10 Value: "); Serial.println(touch10);


  // Turn off all lights from before
  dimAllLeds();
  // Turn on each light when each button is pressed
  if (touch1 < 1) {
    leds[0] = CRGB::Blue;
    leds[1] = CRGB::Blue;
    if (i1 == 0) {
      playMem1.play(AudioSampleBeat1);
      i1 = 1;
    }
  }
  else if (touch1 > 0) {
    if (i1 == 1) {
      i1 = 0;
    }
  }// playMem1.stop(); }


  if (touch2 < 1) {
    leds[2] = CRGB::Blue;
    leds[3] = CRGB::Blue;
    if (i2 == 0) {
      playMem2.play(AudioSampleBeat2);
      i2 = 1;
    }
  }
  else if (touch2 > 0) {
    if (i2 == 1) {
      i2 = 0;
    }
  }


    if (touch3 < 1) {
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
      if (i3 == 0) {
        playMem3.play(AudioSampleBeat3);
        i3 = 1;
      }
    }
    else if (touch3 > 0) {
      if (i3 == 1) {
        i3 = 0;
      }
    }


      if (touch4 < 1) {
        leds[6] = CRGB::Blue;
        leds[7] = CRGB::Blue;
        if (i4 == 0) {
          playMem4.play(AudioSampleBeat4);
          i4 = 1;
        }
      }
      else if (touch4 > 0) {
        if (i4 == 1) {
          i4 = 0;
        }
      }

        if (touch5 < 1) {
          leds[8] = CRGB::Blue;
          leds[9] = CRGB::Blue;
          if (i5 == 0) {
            playMem5.play(AudioSampleBeat5);
            i5 = 1;
          }
        }
        else if (touch5 > 0) {
          if (i5 == 1) {
            i5 = 0;
          }
        }

          if (touch6 < 1) {
            leds[10] = CRGB::Blue;
            leds[11] = CRGB::Blue;
            if (i6 == 0) {
              playMem6.play(AudioSampleBeat6);
              i6 = 1;
            }
          }
          else if (touch6 > 0) {
            if (i6 == 1) {
              i6 = 0;
            }
          }

            if (touch7 < 1) {
              leds[12] = CRGB::Blue;
              leds[13] = CRGB::Blue;
              if (i7 == 0) {
                playMem7.play(AudioSampleBeat7);
                i7 = 1;
              }
            }
            else if (touch7 > 0) {
              if (i7 == 1) {
                i7 = 0;
              }
            }

              if (touch8 < 1) {
                leds[14] = CRGB::Blue;
                leds[15] = CRGB::Blue;
                if (i8 == 0) {
                 playMem8.play(AudioSampleBeat8);
                  i8 = 1;
                }
              }
              else if (touch8 > 0) {
                if (i8 == 1) {
                  i8 = 0;
                }
              }

                if (touch9 < 1) {
                  leds[16] = CRGB::Blue;
                  leds[17] = CRGB::Blue;
                  if (i9 == 0) {
                    playMem9.play(AudioSampleBeat9);
                    i9 = 1;
                  }
                }
                else if (touch9 > 0) {
                  if (i9 == 1) {
                    i9 = 0;
                  }
                }

                  if (touch10 < 1) {
                    leds[18] = CRGB::Blue;
                    leds[19] = CRGB::Blue;
                    if (i10 == 0) {
                      playMem10.play(AudioSampleBeat10);
                      i10 = 1;
                    }
                  }
                  else if (touch10 > 0) {
                    if (i10 == 1) {
                      i10 = 0;
                    }
                  }
                    FastLED.show();
                  }

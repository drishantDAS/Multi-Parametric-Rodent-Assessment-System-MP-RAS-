#include <Wire.h>
#include <HX711.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ============================================================
// MP-RAS - Steady Weight Prototype
// Multi-Parametric Rodent Assessment System
//
// Current configuration:
//   - 1 active load cell connected through HX711
//   - 3 dummy/simulated paw weights
//   - SSD1306 128x64 OLED
//
// Paw assignment:
//   FL = Actual load-cell measurement
//   FR = Dummy weight 1
//   HL = Dummy weight 2
//   HR = Dummy weight 3
// ============================================================


// ================= OLED =================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);


// ================= HX711 =================

#define HX_DOUT 19
#define HX_SCK 18

HX711 scale;


// ================= CALIBRATION =================

long OFFSET = -349600;
float SCALE = -220.0;


// ================= DUMMY WEIGHTS =================
// These represent the remaining paw loads
// for the current prototype configuration.

float dummy1 = 50.0;   // FR
float dummy2 = 100.0;  // HL
float dummy3 = 250.0;  // HR


// ================= SETUP =================

void setup() {

  Serial.begin(115200);

  // Initialize I2C
  Wire.begin(21, 22);
  Wire.setClock(100000);


  // ================= OLED INITIALIZATION =================

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }


  // ================= HX711 INITIALIZATION =================

  scale.begin(HX_DOUT, HX_SCK);

  scale.set_offset(OFFSET);
  scale.set_scale(SCALE);


  // ================= STARTUP DISPLAY =================

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.println("Pi % Mode Ready");

  display.display();

  delay(1000);
}


// ================= MAIN LOOP =================

void loop() {

  // Read actual load-cell weight
  float actualWt = scale.get_units(10);


  // Remove small fluctuations around zero
  if (abs(actualWt) < 10) {
    actualWt = 0;
  }


  // ================= TOTAL WEIGHT =================

  float totalWt =
    actualWt +
    dummy1 +
    dummy2 +
    dummy3;


  // Safety condition
  if (totalWt <= 0) {
    totalWt = 1;
  }


  // ================= PAW PERCENTAGES =================

  float P_act =
    (actualWt / totalWt) * 100.0;

  float P_d1 =
    (dummy1 / totalWt) * 100.0;

  float P_d2 =
    (dummy2 / totalWt) * 100.0;

  float P_d3 =
    (dummy3 / totalWt) * 100.0;


  // ================= OLED DISPLAY =================

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);


  // FL - Actual load cell
  display.setCursor(0, 0);
  display.print("FL:");
  display.print(actualWt, 1);
  display.print("g");


  // FR - Dummy 1
  display.setCursor(0, 8);
  display.print("FR:");
  display.print(dummy1, 0);
  display.print("g");


  // HL - Dummy 2
  display.setCursor(0, 16);
  display.print("HL:");
  display.print(dummy2, 0);
  display.print("g");


  // HR - Dummy 3
  display.setCursor(0, 24);
  display.print("HR:");
  display.print(dummy3, 0);
  display.print("g");


  // FL percentage
  display.setCursor(0, 36);
  display.print("Pi(FL):");


  display.setCursor(0, 48);
  display.print(P_act, 1);
  display.print("%");


  display.display();


  // ================= SERIAL OUTPUT =================

  Serial.print("Total=");
  Serial.print(totalWt, 1);

  Serial.print(" | P: ");

  Serial.print(P_act, 1);
  Serial.print(" ");

  Serial.print(P_d1, 1);
  Serial.print(" ");

  Serial.print(P_d2, 1);
  Serial.print(" ");

  Serial.println(P_d3, 1);


  // Update every 500 ms
  delay(500);
}

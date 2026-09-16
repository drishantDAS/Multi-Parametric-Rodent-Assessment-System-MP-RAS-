#include <Wire.h>
#include <HX711.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ================= OLED =================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ================= HX711 =================
#define HX_DOUT 19
#define HX_SCK  18
HX711 scale;

// ================= CALIBRATION =================
long OFFSET = -349600;
float SCALE = -220.0;

// ================= WEIGHTS =================
float dummy1 = 50.0;
float dummy2 = 100.0;
float dummy3 = 250.0;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);
  Wire.setClock(100000);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  // HX711
  scale.begin(HX_DOUT, HX_SCK);
  scale.set_offset(OFFSET);
  scale.set_scale(SCALE);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Pi % Mode Ready");
  display.display();
  delay(1000);
}

void loop() {
  float actualWt = scale.get_units(10);
  if (abs(actualWt) < 10) actualWt = 0;

  // -------- TOTAL --------
  float totalWt = actualWt + dummy1 + dummy2 + dummy3;
  if (totalWt <= 0) totalWt = 1;   // safety

  // -------- Pi (%) --------
  float P_act = (actualWt / totalWt) * 100.0;
  float P_d1  = (dummy1   / totalWt) * 100.0;
  float P_d2  = (dummy2   / totalWt) * 100.0;
  float P_d3  = (dummy3   / totalWt) * 100.0;

  // -------- OLED --------
 display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

// line height = 8 pixels
display.setCursor(0, 0);
display.print("FL:");
display.print(actualWt, 1);
display.print("g");

display.setCursor(0, 8);
display.print("FR:");
display.print(dummy1, 0);
display.print("g");

display.setCursor(0, 16);
display.print("HL:");
display.print(dummy2, 0);
display.print("g");

display.setCursor(0, 24);
display.print("HR:");
display.print(dummy3, 0);
display.print("g");

// separator line
display.setCursor(0, 36);
display.print("Pi(FL):");

display.setCursor(0, 48);
display.print(P_act, 1);
display.print("%");

display.display();
  // -------- SERIAL --------
  Serial.print("Total=");
  Serial.print(totalWt, 1);
  Serial.print(" | P: ");
  Serial.print(P_act, 1); Serial.print(" ");
  Serial.print(P_d1, 1);  Serial.print(" ");
  Serial.print(P_d2, 1);  Serial.print(" ");
  Serial.println(P_d3, 1);

  delay(500);
}

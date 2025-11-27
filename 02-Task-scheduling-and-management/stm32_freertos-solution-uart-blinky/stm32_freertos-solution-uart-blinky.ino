#include <STM32FreeRTOS.h>

void LED_Toggle_Speed(void *parameter);
void Read_Serial(void *parameter);

TaskHandle_t Read_Serial_Handler;
TaskHandle_t LED_Toggle_Handler;

int ToggleSpeed = 500;
// a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void LED_Toggle_Speed(void *parameter) {
  while (1) {
    digitalWrite(LED_BLUE, HIGH);
    vTaskDelay(ToggleSpeed / portTICK_PERIOD_MS);
    digitalWrite(LED_BLUE, LOW);
    //Serial.println("LED-TASK: LOW");
    vTaskDelay(ToggleSpeed / portTICK_PERIOD_MS);
    Serial.println("LED_Toggle_Speed: Task Running");
  }
}

void Read_Serial(void *parameter) {
  String inputString;
  //memset(inputString, 0, 10);
  while (1) {
    while (Serial.available()) {
      char inChar = (char)Serial.read();
      // add it to the inputString:
      inputString += inChar;
      // if the incoming character is a newline, set a flag so the main loop can
      // do something about it:
      if (inChar == '\r') {
        stringComplete = true;
      }
      if (stringComplete) {
        Serial.print("Input String = ");
        Serial.println(inputString);
        ToggleSpeed = atoi(inputString.c_str());
        printf("Speed = %d\n", ToggleSpeed);
        // clear the string:
        inputString = "";
        stringComplete = false;
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
  //inputString.reserve(200);
  pinMode(LED_BLUE, OUTPUT);

  xTaskCreate(Read_Serial, "Read_Serial_Data", 100, NULL, 1, &Read_Serial_Handler);
  xTaskCreate(LED_Toggle_Speed, "LED_Toggle", 100, NULL, 1, &LED_Toggle_Handler);

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}

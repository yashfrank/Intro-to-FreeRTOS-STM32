#include <STM32FreeRTOS.h>

void Task1(void *parameter);
void Task2(void *parameter);
void toggleLED(void *parameter);

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;

void toggleLED(void *parameter) {
  while (1) {
    digitalWrite(LED_BLUE, HIGH);
    Serial.println("LED-TASK: HIGH");
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_BLUE, LOW);
    Serial.println("LED-TASK: LOW");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task1(void *pvParameters) {
  while(1) {
    Serial.println("Task1 running - Priority 2 (Higher)");
    //vTaskDelay(pdMS_TO_TICKS(1000));  // Print every 1 second
  }
}

void Task2(void *pvParameters) {
  while(1) {
    Serial.println("Task2 running - Priority 1 (Lower)");
    //vTaskDelay(pdMS_TO_TICKS(1000));  // Print every 1 second
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BLUE, OUTPUT);

  xTaskCreate(toggleLED, "TOGGLE LED", 100, NULL, 3, NULL);
  xTaskCreate(Task1, "TASK-1", 100, NULL, 1, &Task1_Handle);
  xTaskCreate(Task2, "TASK-2", 100, NULL, 2, &Task2_Handle);

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}

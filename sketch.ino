#include <DHT.h>

// مشخصات سنسور
#define DHTPIN 2       // پین اتصال سنسور
#define DHTTYPE DHT22  // نوع سنسور: DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // شروع ارتباط سریال
  dht.begin();        // شروع به کار سنسور
}

void loop() {
  float temperature = dht.readTemperature(); // خواندن دما
  float humidity = dht.readHumidity();       // خواندن رطوبت

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("خطا در خواندن اطلاعات از سنسور!");
  } else {
    Serial.print("دمای محیط: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("رطوبت محیط: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000); // هر 2 ثانیه اطلاعات بگیر
}
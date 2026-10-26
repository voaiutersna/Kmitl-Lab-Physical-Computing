const int   TEMP_PIN = A1;                        // ขาอ่านค่าอุณหภูมิ
const float R_FIXED  = 10000.0;                   // ตัวต้านทานคงที่ 10k
const float R0 = 10000.0;                         // ความต้านทานของ NTC ที่ 25 C (สมมติ 10k)
const float BETA = 3950.0;                        // ค่า Beta ของ NTC (สมมติ 3950)
const float T0 = 298.15;                          // 25 C เป็นเคลวิน

void setup() {                                    // ทำครั้งเดียวตอนเริ่ม
  Serial.begin(115200);                           // เปิด Serial 115200
}

void loop() {                                     // ทำซ้ำตลอด
  int adc = analogRead(TEMP_PIN);                 // อ่านค่า 0-1023
  if (adc <= 0 || adc >= 1023) {                  // ถ้าค่าสุดขอบแปลว่าสายหลุดหรือ short
    Serial.println("adc out of range");           // แจ้งเตือน
    delay(500);                                   // รอ
    return;                                       // ข้ามรอบนี้
  }
  float rTh = R_FIXED * (1023.0 / adc - 1.0);     // คำนวณความต้านทานเทอร์มิสเตอร์
  float tK = 1.0 / (1.0 / T0 + log(rTh / R0) / BETA); // สมการ Beta ได้อุณหภูมิเป็นเคลวิน
  float tC = tK - 273.15;                         // แปลงเป็นเซลเซียส
  Serial.print("adc = ");                         // พิมพ์ค่าดิบ
  Serial.print(adc);                              // ค่า adc
  Serial.print("  temp = ");                      // พิมพ์ข้อความ
  Serial.print(tC);                               // อุณหภูมิ C
  Serial.println(" C");                           // หน่วย
  delay(500);                                     // อ่านทุกครึ่งวินาที
}
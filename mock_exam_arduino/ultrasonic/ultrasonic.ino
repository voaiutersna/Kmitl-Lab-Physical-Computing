const int TRIG_PIN = 7;                          // ขา TRIG ต่อ D7 (ส่งสัญญาณเสียงออก)
const int ECHO_PIN = 8;                          // ขา ECHO ต่อ D8 (รับสัญญาณสะท้อนกลับ)

void setup() {                                   // ทำงานครั้งเดียวตอนเริ่ม
  Serial.begin(115200);                          // เปิด Serial ที่ 115200
  pinMode(TRIG_PIN, OUTPUT);                     // TRIG เป็นขาส่งออก
  pinMode(ECHO_PIN, INPUT);                      // ECHO เป็นขารับเข้า
}

float readDistanceCm() {                         // ฟังก์ชันวัดระยะ คืนค่าเป็น cm
  digitalWrite(TRIG_PIN, LOW);                   // เริ่มจากต่ำเพื่อให้สัญญาณนิ่ง
  delayMicroseconds(2);                          // รอ 2 ไมโครวินาที
  digitalWrite(TRIG_PIN, HIGH);                  // ยิงพัลส์สูง
  delayMicroseconds(10);                         // ค้างไว้ 10 ไมโครวินาที (เซนเซอร์ต้องการแบบนี้)
  digitalWrite(TRIG_PIN, LOW);                   // หยุดยิง
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);// วัดเวลาที่ ECHO เป็นสูง (ไมโครวินาที) รอไม่เกิน 30 ms
  if (duration == 0) return 0;                 // ไม่มีเสียงสะท้อน (ไกลเกินหรือไม่เจอวัตถุ) ถือว่า 999
  return duration * 0.034 / 2;                   // เวลา x ความเร็วเสียง (0.034 cm/us) แล้วหาร 2 เพราะไป-กลับ
}

void loop() {                                    // ทำซ้ำตลอด
  float d = readDistanceCm();                    // อ่านระยะ
  Serial.print("distance = ");                   // พิมพ์ข้อความนำ
  Serial.print(d);                               // พิมพ์ค่าระยะ
  Serial.println(" cm");                         // พิมพ์หน่วย แล้วขึ้นบรรทัดใหม่
  delay(500);                                    // วัดทุกครึ่งวินาที
}
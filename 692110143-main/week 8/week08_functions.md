# Week 08 — Functions

Lab นี้ฝึกแยกโปรแกรมออกเป็นฟังก์ชันย่อย แต่ละฟังก์ชันมีหน้าที่ชัดเจน ทำให้โค้ดใน `main()` อ่านง่ายและสามารถเรียกใช้ฟังก์ชันเดิมซ้ำได้

## Exercise 1 — Function Refactor

| Function | รับค่า | คืนค่า/ผลที่เกิดขึ้น | หน้าที่ |
| --- | --- | --- | --- |
| `calculateDamage(int attack, int defense)` | ค่าโจมตีและค่าป้องกัน | คืนค่า damage ชนิด `int` | นำ attack ลบ defense และกำหนด damage ต่ำสุดเป็น 1 |
| `isCriticalHit(int roundNumber)` | หมายเลข round | คืน 1 หรือ 0 | คืน 1 เมื่อหมายเลข round หาร 5 ลงตัว ไม่เช่นนั้นคืน 0 |
| `displayHP(int current, int max)` | HP ปัจจุบันและ HP สูงสุด | ไม่คืนค่า (`void`) แต่พิมพ์แถบ HP | สร้างแถบ HP จำนวน 10 ช่องแล้วแสดงค่า HP |
| `printCombatResult(int round, int damage, int isCrit)` | round, damage และสถานะ critical | ไม่คืนค่า (`void`) แต่พิมพ์ข้อความ | แสดงหมายเลข round, Normal/CRITICAL และ damage |

ในแต่ละรอบ `main()` จะเรียก `isCriticalHit()` ก่อน จากนั้นส่งค่า attack ไปให้ `calculateDamage()` แล้วลด `enemyHP` สุดท้ายจึงเรียก `printCombatResult()` และ `displayHP()` เพื่อแสดงผล

ตัวแปรภายในฟังก์ชันเป็น local variable เช่น `damage` ใน `calculateDamage()` และ `bar` ใน `displayHP()` จึงใช้งานได้เฉพาะในฟังก์ชันของตัวเอง

## Exercise 2 — Game Utility Library

| Function | รับค่า | คืนค่า | หน้าที่ |
| --- | --- | --- | --- |
| `clamp(int value, int min, int max)` | ค่าเดิม ค่าต่ำสุด และค่าสูงสุด | ค่า `int` ที่อยู่ในช่วง | ป้องกันไม่ให้ค่าต่ำกว่า min หรือสูงกว่า max |
| `lerp(float a, float b, float t)` | จุดเริ่ม จุดปลาย และสัดส่วน | ค่า `float` ระหว่าง a กับ b | คำนวณด้วยสูตร `a + (b - a) * t` |
| `randomRange(int min, int max)` | ค่าต่ำสุดและค่าสูงสุด | จำนวนเต็มแบบสุ่ม | สุ่มค่าในช่วง min ถึง max โดยรวมค่าทั้งสองด้าน |
| `percentOf(int current, int total)` | ค่าปัจจุบันและค่ารวม | เปอร์เซ็นต์ชนิด `float` | cast current เป็น `float` ก่อนหาร แล้วคูณ 100 |

`srand((unsigned int)time(NULL));` อยู่ใน `main()` และเรียกเพียงครั้งเดียวตอนเริ่มโปรแกรม ส่วน `randomRange()` ใช้ `rand()` เพื่อสร้างตัวเลขทุกครั้งที่ถูกเรียก

## Reflection 2.1 — clamp และ Pass by Value

เมื่อหยุดใน `clamp()` ค่า `value` เปลี่ยนจาก 150 เป็น 100 เพราะเกิน `max` แต่เมื่อกลับไปดูใน `main()` ตัวแปร `hp` ยังเป็น 150 เหมือนเดิม เนื่องจากค่าของ `hp` ถูกคัดลอกส่งเข้าไปเป็น parameter ชื่อ `value` การแก้ `value` จึงไม่เปลี่ยนตัวแปรต้นฉบับ

## Reflection 2.2 — lerp และ Local Scope

เมื่อหยุดก่อน `return result;` ค่า `result` ใน `lerp()` เท่ากับ 50.00 แต่เมื่อออกจากฟังก์ชันกลับมาที่ `main()` จะดูตัวแปร `result` ไม่ได้ เพราะ `result` เป็น local variable ที่มี scope อยู่เฉพาะภายใน `lerp()` เท่านั้น ค่าที่ `main()` ได้รับจะถูกเก็บในตัวแปร `pos`

## Reflection 2.3 — randomRange และ Pass by Value

ถ้าแก้ `min` เป็น 101 ระหว่างหยุดใน Debugger ผลสุ่มของการเรียกครั้งนั้นจะเปลี่ยนไป เพราะสูตรใช้ `min` ที่ถูกแก้ แต่ `diceMin` ใน `main()` ยังเป็น 1 เหมือนเดิม เนื่องจาก `min` เป็นเพียงสำเนาของ `diceMin` ที่ถูกส่งแบบ Pass by Value

## Reflection 2.4 — percentOf และ Pass by Value

ถ้าแก้ `current` เป็น 0 ระหว่างหยุดใน `percentOf()` ผลที่พิมพ์จะเป็น 0.0% แต่ `score` ใน `main()` ยังเป็น 35 เหมือนเดิม เพราะ `current` เป็นสำเนาของ `score` การเปลี่ยน parameter ภายในฟังก์ชันจึงไม่กระทบตัวแปรต้นฉบับ

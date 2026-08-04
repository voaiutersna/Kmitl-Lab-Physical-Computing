All thing that i do wrong

- Forgot to use & at scanf;
- Forgot to use space infrontof %c
- use %[^\n] instend %s if can
- assign some variable that use other variable that not got assign (assign before its get scanf)
- !!!! If found / make sure the number that is double already
- strcmp คืน 0 เมื่อเท่ากัน แต่เอาไปใส่ if ตรงๆ กลายเป็นเช็ค "ไม่เท่ากัน" กลับตรรกะทั้งหมด ต้องใช้ !strcmp(...)
- double total; ไม่ initialize	ไม่ใส่ = 0 ตอนประกาศ ค่าตั้งต้นเป็น undefined behavior (แม้รอบนี้บังเอิญรันผ่าน ก็ไม่ควรวางใจ)


- Complie-Run or GDB
- gcc filename.c && ./a.exe
- gdb -g filename.c -o outputfilename &&  gdb --tui outputfilename
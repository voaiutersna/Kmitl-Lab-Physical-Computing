#include "stdio.h"

int main() {
    int a = 17, b = 25, c = 50, d = 10;
    c += ++a + b++;
    return 0;
}

// (int) a = 17
// (int) b = 25
// (int) c = 50
// (int) d = 10
// (lldb) n
// Process 14090 stopped
// * thread #1, queue = 'com.apple.main-thread', stop reason = step over
//     frame #0: 0x000000010000037c quiz`main at Quiz.c:6:5
//    3    int main() {
//    4        int a = 17, b = 25, c = 50, d = 10;
//    5        c += ++a + b++;
// -> 6        return 0;
//    7    }
// Target 0: (quiz) stopped.
// (lldb) fr v
// (int) a = 18
// (int) b = 26
// (int) c = 93
// (int) d = 10
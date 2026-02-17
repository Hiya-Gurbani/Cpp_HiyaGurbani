void level3(int val) {
    int local3 = val * 3;
    // ← breakpoint here, then navigate up through frames
}

void level2(int val) {
    int local2 = val + 10;
    level3(local2);
}

void level1(int val) {
    int local1 = val * 2;
    level2(local1);
}

int main() {
    level1(5);   // 5 → level1 makes 10 → level2 makes 20 → level3 makes 60
    return 0;
}
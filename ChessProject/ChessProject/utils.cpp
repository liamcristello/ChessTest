typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define global_variable static
#define internal static

inline int clamp(int val, int min, int max) {
	if (val < min) { return min; }
	else if (val > max) { return max; }
	else { return val; }
}

inline void swap(int& a, int& b) {
	int copy = a;
	a = b;
	b = copy;
}
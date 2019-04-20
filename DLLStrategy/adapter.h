#pragma once
#include <cstdio>

namespace Adapter {
	void Dump(void* ptr, size_t len) {
		char* buf = new char[len * 3 + 1];
		buf[len * 3] = 0;
		char* p = buf;
		for (size_t i = 0; i < len; ++i) {
			sprintf(p,"%02X ", ((char*)ptr)[i]);
			p += 3;
		}
		MessageBoxA(0, buf, 0, 0);
		delete[] buf;
	}
}
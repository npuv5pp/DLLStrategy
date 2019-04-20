// DLLStrategy.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "platform.h"
#include "adapter.h"
#include <cstdio>
using namespace Simuro;

void OnEvent(EventType type, void* argument) {
	switch (type) {
	case EventType::JudgeResult: {
		JudgeResultEvent* judgeResult = static_cast<JudgeResultEvent*>(argument);
		break;
	}
	default:
		;
	}
}

void GetTeamInfo(TeamInfo* teamInfo) {
	static const wchar_t teamName[] = L"公诚勇毅，永矢毋忘";
	static constexpr size_t len = sizeof(teamName);
	memcpy(teamInfo->teamName, teamName, len);
}

void GetInstruction(Field* field) {
	for (auto& r : field->ourRobots) {
		r.wheel = { 125,-125 };
	}
}

void GetPlacement(Field* field) {
	for (auto& r : field->ourRobots) {
		r.position = { 42,42 };
		r.rotation = 180;
	}
}

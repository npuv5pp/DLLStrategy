// DLLStrategy.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "platform.h"
#include "adapter.h"

using namespace Simuro;
using namespace Adapter;

void OnEvent(EventType type, void* argument) {
	SendLog(L"V/DLLStrategy:OnEvent()");
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
	SendLog(L"V/DLLStrategy:GetTeamInfo()");
	static const wchar_t teamName[] = L"公诚勇毅，永矢毋忘";
	static constexpr size_t len = sizeof(teamName);
	memcpy(teamInfo->teamName, teamName, len);
}

void GetInstruction(Field* field) {
	SendLog(L"V/DLLStrategy:GetInstruction()");
	for (auto& r : field->selfRobots) {
		r.wheel = { 125,-125 };
	}
}

void GetPlacement(Field* field) {
	SendLog(L"V/DLLStrategy:GetPlacement()");
	for (auto& r : field->selfRobots) {
		r.position = { 42,42 };
		r.rotation = 180;
	}
}

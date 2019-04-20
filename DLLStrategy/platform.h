#pragma once
#include <cstdint>

namespace Simuro {

	static const int PLAYERS_PER_SIDE = 5;
	static const int MAX_STRING_LEN = 128;

	enum EventType {
		JudgeResult = 0,
		MatchStart = 1,
		MatchStop = 2,
		RoundStart = 3,
		RoundStop = 4
	};

	enum JudgeType
	{
		NormalMatch = 0,
		FreeBallTop = 1,
		FreeBallBottom = 2,
		PlaceKick = 3,
		Penalty = 4,
		GoalKick = 5,
	};

	enum Side
	{
		Yellow,
		Blue,
		None,
	};

	struct Vector2 {
		float x;
		float y;
	};

	struct TeamInfo {
		wchar_t teamName[MAX_STRING_LEN];
	};

	struct Ball {
		Vector2 position;
	};

	struct Wheel {
		float leftSpeed;
		float rightSpeed;
	};

	struct Robot {
		Vector2 position;
		float rotation;
		Wheel wheel;
	};

	struct Field {
		Robot ourRobots[PLAYERS_PER_SIDE];
		Robot opponentRobots[PLAYERS_PER_SIDE];
		Ball ball;
		int32_t tickTotal;
		int32_t tickRound;
	};

	struct JudgeResultEvent {
		JudgeType type;
		Side actor;
		wchar_t reason[MAX_STRING_LEN];
	};
}
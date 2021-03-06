// 
//  Enumeration.h
//  MyMoonWarriors
//
//  By Kelyad on 11/04/2012
//

#ifndef ENUMERATION_h
#define ENUMERATION_h

// 场景ID
enum SCENE_ID
{
	// 
	SCENE_ID_NONE       = -1,
	// 主菜单场景
	SCENE_ID_MAINMENU   = 0,
	// 游戏场景
	SCENE_ID_GAMEPLAY   = 1,
	// 游戏设置场景
	SCENE_ID_SETTING    = 2,
	// 关于场景
	SCENE_ID_ABOUT      = 3
} ;
// 角色状态
enum CHARACTER_STATE
{
	//
	CHARACTER_STATE_NONE        = -1,
	// 初始状态
	CHARACTER_STATE_SPAWNING    = 0,
	// 射击状态
	CHARACTER_STATE_SHOOTING    = 1,
	// 被打击状态
	CHARACTER_STATE_HURT        = 2,
	// 死亡状态
	CHARACTER_STATE_DYING       = 3
} ;

// Bullet State
enum BULLET_STATE
{
	//
	BULLET_STATE_NONE       = -1,
	// 
	BULLET_STATE_SPAWNING   = 0,
	// 
	BULLET_STATE_NORMAL     = 1,
	// 
	BULLET_STATE_ATTACKING  = 2,
	// 
	BULLET_STATE_OVER       = 3
} ;

// 
enum BULLET_TAG 
{
	// 
	BULLET_TAG_NONE     = -1,
	// Player
	BULLET_TAG_PLAYER   = 0,
	// Enemy
	BULLET_TAG_ENEMY    = 1
} ;

enum BULLET_TYPE
{
	TYPE1,
	TYPE2
};


//enemy show time
enum ENEMY_SHOW_COUNT
{
	Repeate, //
	Once,	//just one time
	Twice
};

//enemy action type
enum ENEMY_ACTION_TYPE
{
	ATTACK,		//stay on the top of the screen with attack
	VERTICAL,	//No attack
	HORIZONTAL,	//No attack
	OVERLAP	
};

enum ATTACK_MODE
{
	NORMAL,
	TSUIHIKIDAN
};

#endif

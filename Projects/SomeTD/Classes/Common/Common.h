// 
//  Enumeration.h
//  MyMoonWarriors
//
//  By Kelyad on 11/04/2012
//

#ifndef _COMMON_H_
#define _COMMON_H_

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
#define EnumStr(e) #e

#define assertMsg(a, b) assert(a && b)

inline void kkAssertMsg(bool cond, const char* msg)
{
	if (cond)
		return;
	CCLog(msg);
	assertMsg(cond, msg);
}


const int MAX_LOG_LEN = 16*1024;
inline void kkAssertMsgf(bool cond, const char * pszFormat, ...)
{
	if (cond)
		return;
	char szBuf[MAX_LOG_LEN];

	va_list ap;
	va_start(ap, pszFormat);
	//vsnprintf_l(szBuf, MAX_LOG_LEN, MAX_LOG_LEN, pszFormat, ap);
	vsnprintf(szBuf, MAX_LOG_LEN, pszFormat, ap);
	va_end(ap);
	kkAssertMsg(cond, szBuf);
}


// id seed
typedef long entity_id;
const entity_id nonEntity = -1;
#define non_entity nonEntity


//rand

inline int rangedRand(int range_min, int range_max)
{
	int r = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
		+ range_min;
	return r;
}


#endif

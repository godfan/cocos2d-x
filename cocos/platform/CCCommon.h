/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CC_COMMON_H__
#define __CC_COMMON_H__

#include <typeinfo>
#include <string.h>
#include <ctype.h>

#include "base/CCPlatformMacros.h"

NS_CC_BEGIN

/**
 * @addtogroup platform
 * @{
 */

static unsigned int _Hash(const char *key)
{
    size_t len = strlen(key);
    const char *end = key + len;
    unsigned int hash;
    for (hash = 0; key < end; key++)
    {
        hash *= 16777619;
        hash ^= (unsigned int)(unsigned char)toupper(*key);
    }
    return (hash);
}

unsigned int class_hash_code(const std::type_info& info)
{
    // hash name() to size_t value by pseudorandomizing transform
    return _Hash(info.name());
}

#define CLASS_HASH_CODE class_hash_code

/**
 * lua can not deal with ...
 */
void CC_DLL LuaLog(const char * format);

/**
@brief Pop out a message box
*/
void CC_DLL MessageBox(const char * msg, const char * title);

/**
@brief Enum the language type supported now
*/
enum class LanguageType
{
    ENGLISH = 0,
    CHINESE,
    FRENCH,
    ITALIAN,
    GERMAN,
    SPANISH,
    DUTCH,
    RUSSIAN,
    KOREAN,
    JAPANESE,
    HUNGARIAN,
    PORTUGUESE,
    ARABIC,
    NORWEGIAN,
    POLISH
};

// END of platform group
/// @}

NS_CC_END

#endif    // __CC_COMMON_H__
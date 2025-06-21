#pragma once
#ifndef _VK_COLORS_HPP_
#define _VK_COLORS_HPP_

/* FOREGROUND */
/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

#define UNDERLINE "\033[4m"// подчёркивание
#define DOUBLE_UNDERLINE "\033[21m"// двойное подчёркивание
#define LINE_THROUGH "\033[9m"// перечёркнутый
#define ITALIC "\033[3m"

#define VK_RESET_COLOR "\033[0m"
#define VK_NOTIFY_COLOR "\033[96m"
#define VK_INFO_COLOR "\033[36m"
#define VK_SUCCESS_COLOR "\033[32m"
#define VK_WARN_COLOR "\033[33m"
#define VK_ERROR_COLOR "\033[91m"
#define VK_FATAL_COLOR "\033[31m"


//#define GRAY "\033[2m"
//#define BLACK "\033[30m"
//#define BLUE "\033[34m"
#define MAGNETA "\033[35m"
//#define WHITE "\033[37m"

//#define VK_BLACK_BG "\033[40m"
//#define VK_RED_BG "\033[41m"
//#define VK_GREEN_BG "\033[42m"
//#define VK_YELLOW_BG "\033[43m"
//#define VK_BLUE_BG "\033[44m"
//#define VK_MAGNETA_BG "\033[45m"
//#define VK_CYAN_BG "\033[46m"
//#define VK_WHITE_BG "\033[47m"


#endif

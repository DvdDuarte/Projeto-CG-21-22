/**
 * @file colors.h
 * @author David Duarte (A93253) & Ema Dias (A89518)
 * @brief Ficheiro que contém as cores a serem usadas na interface da aplicação
 * @version 1.0
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _COLORS_H_
#define _COLORS_H_


// For blink effect \033[5m .... \033[0m
// Bold \x1b[1m
// Faint \x1b[2m
// Italic \x1b[3m
// Underlined \x1b[4m
// Inverse \x1b[7m
// Strikethrouggh \x1b[9m

#define RESET "\x1b[0m"

// Background Colors
#define BACKGROUND_BLACK "\x1b[40m"
#define BACKGROUND_RED "\x1b[41m"
#define BACKGROUND_GREEN "\x1b[42m"
#define BACKGROUND_YELLOW "\x1b[43m"
#define BACKGROUND_BLUE "\x1b[44m"
#define BACKGROUND_MAGENTA "\x1b[45m"
#define BACKGROUND_CYAN "\x1b[46m"
#define BACKGROUND_WHITE "\x1b[47m"

// Text Colors
#define TEXT_BLACK "\x1b[0;30m"
#define TEXT_RED "\x1b[0;31m"
#define TEXT_GREEN "\x1b[0;32m"
#define TEXT_YELLOW "\x1b[0;33m"
#define TEXT_BLUE "\x1b[0;34m"
#define TEXT_MAGENTA "\x1b[0;35m"
#define TEXT_CYAN "\x1b[0;36m"
#define TEXT_WHITE "\x1b[0;37m"

// Normal Colors
//#define B_PINK "\x1b[0;35m"
//#define B_CYAN "\x1b[0;36m"

// Bold Colors
#define BOLD_BLACK "\x1b[1;30m"
#define BOLD_RED "\x1b[1;31m"
#define BOLD_GREEN "\x1b[1;32m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_BLUE "\x1b[1;34m"
#define BOLD_MAGENTA "\x1b[1;35m"
#define BOLD_CYAN "\x1b[1;36m"
#define BOLD_WHITE "\x1b[1;37m"

// Faint Colors
#define FAINT_BLACK "\x1b[2;30m"
#define FAINT_RED "\x1b[2;31m"
#define FAINT_GREEN "\x1b[2;32m"
#define FAINT_YELLOW "\x1b[2;33m"
#define FAINT_BLUE "\x1b[2;34m"
#define FAINT_MAGENTA "\x1b[2;35m"
#define FAINT_CYAN "\x1b[2;36m"
#define FAINT_WHITE "\x1b[2;37m"

// Italic Colors
#define ITALIC_BLACK "\x1b[3;30m"
#define ITALIC_RED "\x1b[3;31m"
#define ITALIC_GREEN "\x1b[3;32m"
#define ITALIC_YELLOW "\x1b[3;33m"
#define ITALIC_BLUE "\x1b[3;34m"
#define ITALIC_MAGENTA "\x1b[3;35m"
#define ITALIC_CYAN "\x1b[3;36m"
#define ITALIC_WHITE "\x1b[3;37m"

// Underlined Colors
#define UNDERLINED_BLACK "\x1b[4;30m"
#define UNDERLINED_RED "\x1b[4;31m"
#define UNDERLINED_GREEN "\x1b[4;32m"
#define UNDERLINED_YELLOW "\x1b[4;33m"
#define UNDERLINED_BLUE "\x1b[4;34m"
#define UNDERLINED_MAGENTA "\x1b[4;35m"
#define UNDERLINED_CYAN "\x1b[4;36m"
#define UNDERLINED_WHITE "\x1b[4;37m"

// Inverse Colors
#define INVERSE_BLACK "\x1b[7;30m"
#define INVERSE_RED "\x1b[7;31m"
#define INVERSE_GREEN "\x1b[7;32m"
#define INVERSE_YELLOW "\x1b[7;33m"
#define INVERSE_BLUE "\x1b[7;34m"
#define INVERSE_MAGENTA "\x1b[7;35m"
#define INVERSE_CYAN "\x1b[7;36m"
#define INVERSE_WHITE "\x1b[7;37m"

// Strikethrough Colors
#define STRIKETHROUGH_BLACK "\x1b[9;30m"
#define STRIKETHROUGH_RED "\x1b[9;31m"
#define STRIKETHROUGH_GREEN "\x1b[9;32m"
#define STRIKETHROUGH_YELLOW "\x1b[9;33m"
#define STRIKETHROUGH_BLUE "\x1b[9;34m"
#define STRIKETHROUGH_MAGENTA "\x1b[9;35m"
#define STRIKETHROUGH_CYAN "\x1b[9;36m"
#define STRIKETHROUGH_WHITE "\x1b[9;37m"

//------------------
// BRIGHT Background Colors
#define BACKGROUND_BRIGHT_BLACK "\x1b[100m"
#define BACKGROUND_BRIGHT_RED "\x1b[101m"
#define BACKGROUND_BRIGHT_GREEN "\x1b[102m"
#define BACKGROUND_BRIGHT_YELLOW "\x1b[103m"
#define BACKGROUND_BRIGHT_BLUE "\x1b[104m"
#define BACKGROUND_BRIGHT_MAGENTA "\x1b[105m"
#define BACKGROUND_BRIGHT_CYAN "\x1b[106m"
#define BACKGROUND_BRIGHT_WHITE "\x1b[107m"

// BRIGHT Text Colors
#define TEXT_BRIGHT_BLACK "\x1b[0;90m"
#define TEXT_BRIGHT_RED "\x1b[0;91m"
#define TEXT_BRIGHT_GREEN "\x1b[0;92m"
#define TEXT_BRIGHT_YELLOW "\x1b[0;93m"
#define TEXT_BRIGHT_BLUE "\x1b[0;94m"
#define TEXT_BRIGHT_MAGENTA "\x1b[0;95m"
#define TEXT_BRIGHT_CYAN "\x1b[0;96m"
#define TEXT_BRIGHT_WHITE "\x1b[0;97m"

// BRIGHT Bold Colors
#define BOLD_BRIGHT_BLACK "\x1b[1;90m"
#define BOLD_BRIGHT_RED "\x1b[1;91m"
#define BOLD_BRIGHT_GREEN "\x1b[1;92m"
#define BOLD_BRIGHT_YELLOW "\x1b[1;93m"
#define BOLD_BRIGHT_BLUE "\x1b[1;94m"
#define BOLD_BRIGHT_MAGENTA "\x1b[1;95m"
#define BOLD_BRIGHT_CYAN "\x1b[1;96m"
#define BOLD_BRIGHT_WHITE "\x1b[1;97m"

// BRIGHT Faint Colors
#define FAINT_BRIGHT_BLACK "\x1b[2;90m"
#define FAINT_BRIGHT_RED "\x1b[2;91m"
#define FAINT_BRIGHT_GREEN "\x1b[2;92m"
#define FAINT_BRIGHT_YELLOW "\x1b[2;93m"
#define FAINT_BRIGHT_BLUE "\x1b[2;94m"
#define FAINT_BRIGHT_MAGENTA "\x1b[2;95m"
#define FAINT_BRIGHT_CYAN "\x1b[2;96m"
#define FAINT_BRIGHT_WHITE "\x1b[2;97m"

// BRIGHT Italic Colors
#define ITALIC_BRIGHT_BLACK "\x1b[3;90m"
#define ITALIC_BRIGHT_RED "\x1b[3;91m"
#define ITALIC_BRIGHT_GREEN "\x1b[3;92m"
#define ITALIC_BRIGHT_YELLOW "\x1b[3;93m"
#define ITALIC_BRIGHT_BLUE "\x1b[3;94m"
#define ITALIC_BRIGHT_MAGENTA "\x1b[3;95m"
#define ITALIC_BRIGHT_CYAN "\x1b[3;96m"
#define ITALIC_BRIGHT_WHITE "\x1b[3;97m"

// BRIGHT Underlined Colors
#define UNDERLINED_BRIGHT_BLACK "\x1b[4;90m"
#define UNDERLINED_BRIGHT_RED "\x1b[4;91m"
#define UNDERLINED_BRIGHT_GREEN "\x1b[4;92m"
#define UNDERLINED_BRIGHT_YELLOW "\x1b[4;93m"
#define UNDERLINED_BRIGHT_BLUE "\x1b[4;94m"
#define UNDERLINED_BRIGHT_MAGENTA "\x1b[4;95m"
#define UNDERLINED_BRIGHT_CYAN "\x1b[4;96m"
#define UNDERLINED_BRIGHT_WHITE "\x1b[4;97m"

// BRIGHT Inverse Colors
#define INVERSE_BRIGHT_BLACK "\x1b[7;90m"
#define INVERSE_BRIGHT_RED "\x1b[7;91m"
#define INVERSE_BRIGHT_GREEN "\x1b[7;92m"
#define INVERSE_BRIGHT_YELLOW "\x1b[7;93m"
#define INVERSE_BRIGHT_BLUE "\x1b[7;94m"
#define INVERSE_BRIGHT_MAGENTA "\x1b[7;95m"
#define INVERSE_BRIGHT_CYAN "\x1b[7;96m"
#define INVERSE_BRIGHT_WHITE "\x1b[7;97m"

// BRIGHT Strikethrough Colors
#define STRIKETHROUGH_BRIGHT_BLACK "\x1b[9;90m"
#define STRIKETHROUGH_BRIGHT_RED "\x1b[9;91m"
#define STRIKETHROUGH_BRIGHT_GREEN "\x1b[9;92m"
#define STRIKETHROUGH_BRIGHT_YELLOW "\x1b[9;93m"
#define STRIKETHROUGH_BRIGHT_BLUE "\x1b[9;94m"
#define STRIKETHROUGH_BRIGHT_MAGENTA "\x1b[9;95m"
#define STRIKETHROUGH_BRIGHT_CYAN "\x1b[9;96m"
#define STRIKETHROUGH_BRIGHT_WHITE "\x1b[9;97m"

// BRIGHT Underlined and Italic Color
#define UI_BRIGHT_BLACK "\x1b[3;4;90m"
#define UI_BRIGHT_RED "\x1b[3;4;91m"
#define UI_BRIGHT_GREEN "\x1b[3;4;92m"
#define UI_BRIGHT_YELLOW "\x1b[3;4;93m"
#define UI_BRIGHT_BLUE "\x1b[3;4;94m"
#define UI_BRIGHT_MAGENTA "\x1b[3;4;95m"
#define UI_BRIGHT_CYAN "\x1b[3;4;96m"
#define UI_BRIGHT_WHITE "\x1b[3;4;97m"

// BRIGHT Bold, Underlined and Italic Color
#define BUI_BRIGHT_BLACK "\x1b[1;3;4;90m"
#define BUI_BRIGHT_RED "\x1b[1;3;4;91m"
#define BUI_BRIGHT_GREEN "\x1b[1;3;4;92m"
#define BUI_BRIGHT_YELLOW "\x1b[1;3;4;93m"
#define BUI_BRIGHT_BLUE "\x1b[1;3;4;94m"
#define BUI_BRIGHT_MAGENTA "\x1b[1;3;4;95m"
#define BUI_BRIGHT_CYAN "\x1b[1;3;4;96m"
#define BUI_BRIGHT_WHITE "\x1b[1;3;4;97m"

// BRIGHT Bold, Underlined and Italic Color
#define BI_BRIGHT_BLACK "\x1b[1;3;90m"
#define BI_BRIGHT_RED "\x1b[1;3;91m"
#define BI_BRIGHT_GREEN "\x1b[1;3;92m"
#define BI_BRIGHT_YELLOW "\x1b[1;3;93m"
#define BI_BRIGHT_BLUE "\x1b[1;3;94m"
#define BI_BRIGHT_MAGENTA "\x1b[1;3;95m"
#define BI_BRIGHT_CYAN "\x1b[1;3;96m"
#define BI_BRIGHT_WHITE "\x1b[1;3;97m"


#endif //_COLORSTRIKETHROUGH_H_
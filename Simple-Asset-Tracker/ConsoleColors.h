#pragma once

// Prevent Windows from defining min and max macros.
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>
#include <iostream>
#include <string>

namespace ConsoleColor
{
    enum class Color : WORD
    {
        Menu = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Debug = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Warning = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        Error = FOREGROUND_RED | FOREGROUND_INTENSITY,
        Success = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        Failed = FOREGROUND_RED | FOREGROUND_INTENSITY
    };

    // Change the text color while keeping the current background.
    // Returns false if output is redirected or no console is available.
    inline bool Set(Color color)
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info{};

        if (!GetConsoleScreenBufferInfo(console, &info))
            return false;

        // Finish printing existing text before changing its color.
        std::cout.flush();

        const WORD attributes = static_cast<WORD>(
            (info.wAttributes & ~0x000F) | static_cast<WORD>(color));

        return SetConsoleTextAttribute(console, attributes) != 0;
    }

    // Print a colored message, then restore the previous console colors.
    inline void Print(Color color, const std::string& message)
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO previous{};

        const bool hasConsole =
            GetConsoleScreenBufferInfo(console, &previous) != 0;

        if (hasConsole)
            Set(color);

        std::cout << message << '\n';
        std::cout.flush();

        if (hasConsole)
            SetConsoleTextAttribute(console, previous.wAttributes);
    }

    inline void Menu(const std::string& text)
    {
        Print(Color::Menu, text);
    }

    inline void Debug(const std::string& text)
    {
        Print(Color::Debug, "[DEBUG] " + text);
    }

    inline void Warning(const std::string& text)
    {
        Print(Color::Warning, "[WARNING] " + text);
    }

    inline void Error(const std::string& text)
    {
        Print(Color::Error, "[ERROR] " + text);
    }

    inline void Success(const std::string& text)
    {
        Print(Color::Success, "[SUCCESS] " + text);
    }

    inline void Failed(const std::string& text)
    {
        Print(Color::Failed, "[FAILED] " + text);
    }
}
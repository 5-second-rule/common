#pragma once

#define _LEFT_HANDED

#ifdef _EXPORT_COMMON
#define COMMONDLL __declspec(dllexport)
#else
#ifdef _IMPORT_COMMON
#define COMMONDLL __declspec(dllimport)
#else
#define COMMONDLL
#endif
#endif
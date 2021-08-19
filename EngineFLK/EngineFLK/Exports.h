#pragma once

#ifdef FLK_EXPORTS
#define FLK_API __declspec(dllexport)
#else
#define FLK_API __declspec(dllexport)
#endif
#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef FLK_EXPORTS
#define FLK_API __declspec(dllexport)
#else
#define FLK_API __declspec(dllexport)
#endif

#endif
#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <random>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

//#include "ItemDesc.h"
#include "System/Device.h"
#include "ItemDesc.h"
#define SAFE_RELEASE(p)         { if (p) { (p)->Release(); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(p)    { if (p) { delete[] (p); (p) = nullptr; } }

#define SAFE_DELETE(p)          { if (p) { delete (p); (p) = nullptr; } }

const short Width = 100;
const short Height = 50;
extern HANDLE Handle;

//Low Coupling

//High Cohesion
#ifndef Head
#define Head

#include "Peon.h"
#include "Rook.h"
#include "Khights.h"
#include "Kings.h"
#include "Bishops.h"
#include "Queens.h"

#include "Object.h"


typedef struct Types
{
	Types() {};
	union
	{
		Peon* Pen;
		Rook* Rooks;
		Kings* Kin;
		Queens* Que;
		Bishops* Bish;
		Khights* Kni;
	};
} Types;

#endif // !Head

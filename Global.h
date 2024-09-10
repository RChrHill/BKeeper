#pragma once

#include <config.h>

#ifndef BKEEPER_GAUGEGROUP
#define BKEEPER_DEFAULTGAUGEGROUP
#define BKEEPER_GAUGEGROUP Grid::GroupName::SU
#endif

#ifndef BKEEPER_NC
#define BKEEPER_DEFAULTNC
#define BKEEPER_NC 3
#endif

#ifndef BKEEPER_REPRESENTATION
#define BKEEPER_DEFAULTREPRESENTATION
#define BKEEPER_REPRESENTATION RepresentationName::Fundamental
#endif

// SU2 Representations
#if defined(BKEEPER_ENABLE_SU2FUND) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU2FUND))
#define BKEEPER_SU2FUND
#endif

#if defined(BKEEPER_ENABLE_SU2ADJ) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU2ADJ))
#define BKEEPER_SU2ADJ
#endif

#if defined(BKEEPER_ENABLE_SU2TIS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU2TIS))
#define BKEEPER_SU2TIS
#endif

#if defined(BKEEPER_ENABLE_SU2TIAS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU2TIAS))
#define BKEEPER_SU2TIAS
#endif

// SU3 Representations
#if defined(BKEEPER_ENABLE_SU3FUND) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU3FUND))
#define BKEEPER_SU3FUND
#endif

#if defined(BKEEPER_ENABLE_SU3ADJ) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU3ADJ))
#define BKEEPER_SU3ADJ
#endif

#if defined(BKEEPER_ENABLE_SU3TIS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU3TIS))
#define BKEEPER_SU3TIS
#endif

#if defined(BKEEPER_ENABLE_SU3TIAS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU3TIAS))
#define BKEEPER_SU3TIAS
#endif

// SU4 Representations
#if defined(BKEEPER_ENABLE_SU4FUND) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU4FUND))
#define BKEEPER_SU4FUND
#endif

#if defined(BKEEPER_ENABLE_SU4ADJ) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU4ADJ))
#define BKEEPER_SU4ADJ
#endif

#if defined(BKEEPER_ENABLE_SU4TIS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU4TIS))
#define BKEEPER_SU4TIS
#endif

#if defined(BKEEPER_ENABLE_SU4TIAS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_SU4TIAS))
#define BKEEPER_SU4TIAS
#endif

// Sp4 Representations
#if defined(BKEEPER_ENABLE_Sp4FUND) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_Sp4FUND))
#define BKEEPER_Sp4FUND
#endif

#if defined(BKEEPER_ENABLE_Sp4TIS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_Sp4TIS))
#define BKEEPER_Sp4TIS
#endif

#if defined(BKEEPER_ENABLE_Sp4TIAS) || (defined(BKEEPER_ENABLE_ALL) && !defined(BKEEPER_DISABLE_Sp4TIAS))
#define BKEEPER_Sp4TIAS
#endif

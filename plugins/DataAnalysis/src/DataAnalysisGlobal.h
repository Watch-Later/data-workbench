﻿#ifndef DATAANALYSISGLOBAL_H
#define DATAANALYSISGLOBAL_H
#include <QtCore/QtGlobal>

#if defined(DADATAANALYSIS_PLUGIN_BUILD)
#define DADATAANALYSIS_API Q_DECL_EXPORT
#else
#define DADATAANALYSIS_API Q_DECL_IMPORT
#endif

// Q_DECL_IMPORT.
#endif  // DATAANALYSISGLOBAL_H
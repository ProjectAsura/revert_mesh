//-----------------------------------------------------------------------------
// File : main.cpp
// Desc : Main Entry Point.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "CsvParser.h"


//-----------------------------------------------------------------------------
// Constant Values.
//-----------------------------------------------------------------------------
const uint32_t INVALID_MAP = UINT32_MAX;




int main(int argc, char** argv)
{
    if (argc < 2)
    { return -1; }

    auto csvPath0 = argv[1];
    auto csvPath1 = argv[2];

    CsvParser csvFile;

    // 頂点データ読み込み.
    if (!csvFile.LoadVertices(csvPath0))
    { return -1; }

    // 頂点インデックス読み込み.
    if (!csvFile.LoadIndices(csvPath1))
    { return -1; }

    return 0;
}



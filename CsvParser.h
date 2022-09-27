//-----------------------------------------------------------------------------
// File : CsvParser.h
// Desc : CSV File Parser.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <string>
#include <vector>


///////////////////////////////////////////////////////////////////////////////
// Vertex class
///////////////////////////////////////////////////////////////////////////////
class Vertex
{
    friend class CsvParser;

public:
    size_t      GetAttributeCount() const;
    uint8_t     GetAsU8 (size_t index) const;
    uint16_t    GetAsU16(size_t index) const;
    uint32_t    GetAsU32(size_t index) const;
    int8_t      GetAsS8 (size_t index) const;
    int16_t     GetAsS16(size_t index) const;
    int32_t     GetAsS32(size_t index) const;
    float       GetAsF32(size_t index) const;

private:
    std::vector<std::string>      m_Attributes;
};

///////////////////////////////////////////////////////////////////////////////
// CsvParser class
///////////////////////////////////////////////////////////////////////////////
class CsvParser
{
public:
    CsvParser () = default;
    ~CsvParser() = default;

    bool LoadVertices(const char* filename);
    bool LoadIndices (const char* filename);

    size_t GetVertexCount() const;
    size_t GetIndexCount () const;

    const Vertex& GetVertex(size_t index) const;
    uint32_t GetIndex(size_t index) const;

private:
    std::vector<Vertex>     m_Vertices;
    std::vector<uint32_t>   m_Indices;
};
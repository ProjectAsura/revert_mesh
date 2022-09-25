//-----------------------------------------------------------------------------
// File : CsvParser.cpp
// Desc : CSV File Parser.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "CsvParser.h"
#include <fstream>
#include <sstream>
#include <cassert>


///////////////////////////////////////////////////////////////////////////////
// Vertex class
///////////////////////////////////////////////////////////////////////////////
size_t Vertex::GetAttributeCount() const
{ return m_Attributes.size(); }

uint8_t Vertex::GetAsU8(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return uint8_t(value);
}

uint16_t Vertex::GetAsU16(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return uint16_t(value);
}

uint32_t Vertex::GetAsU32(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return uint32_t(value);
}

int8_t Vertex::GetAsS8(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return int8_t(value);
}

int16_t Vertex::GetAsS16(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return int16_t(value);
}

int32_t Vertex::GetAsS32(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stoi(m_Attributes[index]);
    return int32_t(value);
}

float Vertex::GetAsF32(size_t index) const
{
    assert(index < m_Attributes.size());
    auto value = std::stof(m_Attributes[index]);
    return value;
}


///////////////////////////////////////////////////////////////////////////////
// CsvParser class
///////////////////////////////////////////////////////////////////////////////
bool CsvParser::LoadVertices(const char* filename)
{
    std::ifstream stream(filename);

    if (!stream.is_open())
    { return false; }

    auto count = 0;
    std::string buf;
    std::string attr;
    while(getline(stream, buf))
    {
        std::istringstream string_stream(buf);

        Vertex vert;
        while(getline(string_stream, attr, ','))
        {
            // 最初の行はラベルなので処理しない.
            if (count > 0)
            { vert.m_Attributes.emplace_back(attr); }
        }

        // 最初の行はラベルなので処理しない.
        if (count > 0)
        { m_Vertices.emplace_back(vert); }

        count++;
    }

    stream.close();

    m_Vertices.shrink_to_fit();
    return true;
}

bool CsvParser::LoadIndices(const char* filename)
{
    std::ifstream stream(filename);

    if (!stream.is_open())
    { return false; }

    auto count = 0;
    std::string buf;
    std::string attr;
    while(getline(stream, buf))
    {
        std::istringstream string_stream(buf);

        while(getline(string_stream, attr, ','))
        {
            // 最初の行はラベルなので処理しない.
            if (count > 0)
            {
                auto index = uint32_t(std::stoi(attr));
                m_Indices.push_back(index);
            }

            count++;
        }
    }

    stream.close();

    m_Indices.shrink_to_fit();
    return true;
}

size_t CsvParser::GetVertexCount() const
{ return m_Vertices.size(); }

size_t CsvParser::GetIndexCount() const
{ return m_Indices.size(); }

const Vertex& CsvParser::GetVertex(size_t index) const
{
    assert(index < m_Vertices.size());
    return m_Vertices[index];
}

uint32_t CsvParser::GetIndex(size_t index) const
{
    assert(index < m_Indices.size());
    return m_Indices[index];
}

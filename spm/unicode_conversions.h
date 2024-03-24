
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

// This was extracted from https://github.com/microsoft/cpprestsdk/blob/cdae258bfb22f948c7b768b4dc56f5f4a2d9b2ce/Release/src/utilities/asyncrt_utils.cpp#L305

#include <string>
#include <stdexcept>

typedef std::basic_string<uint16_t> utf16string;

#define LOW_3BITS 0x7
#define LOW_4BITS 0xF
#define LOW_5BITS 0x1F
#define LOW_6BITS 0x3F
#define BIT4 0x8
#define BIT5 0x10
#define BIT6 0x20
#define BIT7 0x40
#define BIT8 0x80
#define L_SURROGATE_START 0xDC00
#define L_SURROGATE_END 0xDFFF
#define H_SURROGATE_START 0xD800
#define H_SURROGATE_END 0xDBFF
#define SURROGATE_PAIR_START 0x10000

// Create a dedicated type for characters to avoid the issue
// of different platforms defaulting char to be either signed
// or unsigned.
using UtilCharInternal_t = signed char;

inline size_t count_utf8_to_utf16(const std::string& s)
{
    const size_t sSize = s.size();
    auto const sData = reinterpret_cast<const UtilCharInternal_t*>(s.data());
    size_t result {sSize};

    for (size_t index = 0; index < sSize;)
    {
        if (sData[index] >= 0)
        {
            // use fast inner loop to skip single byte code points (which are
            // expected to be the most frequent)
            while ((++index < sSize) && (sData[index] >= 0))
                ;

            if (index >= sSize) break;
        }

        // start special handling for multi-byte code points
        const UtilCharInternal_t c {sData[index++]};

        if ((c & BIT7) == 0)
        {
            throw std::range_error("UTF-8 string character can never start with 10xxxxxx");
        }
        else if ((c & BIT6) == 0) // 2 byte character, 0x80 to 0x7FF
        {
            if (index == sSize)
            {
                throw std::range_error("UTF-8 string is missing bytes in character");
            }
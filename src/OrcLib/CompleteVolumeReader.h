//
// SPDX-License-Identifier: LGPL-2.1-or-later
//
// Copyright © 2011-2019 ANSSI. All Rights Reserved.
//
// Author(s): Jean Gautier (ANSSI)
//
#pragma once

#include "VolumeReader.h"
#include "DiskExtent.h"
#include "BinaryBuffer.h"

#include <concrt.h>

#pragma managed(push, off)

namespace Orc {

class LogFileWriter;

class ORCLIB_API CompleteVolumeReader : public VolumeReader
{

public:
    CompleteVolumeReader(logger pLog, const WCHAR* szLocation);

    HRESULT Seek(ULONGLONG offset);
    HRESULT Read(ULONGLONG offset, CBinaryBuffer& data, ULONGLONG ullBytesToRead, ULONGLONG& ullBytesRead);

    virtual std::shared_ptr<VolumeReader> ReOpen(DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwFlags);

    virtual ~CompleteVolumeReader();

protected:
    CDiskExtentVector m_Extents;

    HRESULT ParseBootSector();
    HRESULT Read(CBinaryBuffer& data, ULONGLONG ullBytesToRead, ULONGLONG& ullBytesRead);

private:
    concurrency::critical_section m_cs;
};

}  // namespace Orc

#pragma managed(pop)

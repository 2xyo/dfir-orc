//
// SPDX-License-Identifier: LGPL-2.1-or-later
//
// Copyright © 2011-2019 ANSSI. All Rights Reserved.
//
// Author(s): Jean Gautier (ANSSI)
//
#pragma once

#include "IUSNJournalWalker.h"
#include "USNJournalWalkerBase.h"

#include "NtfsDataStructures.h"

#include "winioctl.h"

#pragma managed(push, off)

namespace Orc {

class ByteStream;
class MFTRecord;

class ORCLIB_API USNJournalWalkerOffline
    : public USNJournalWalkerBase
    , public IUSNJournalWalker
{
public:
    USNJournalWalkerOffline(logger pLog);
    virtual ~USNJournalWalkerOffline();

    const std::shared_ptr<ByteStream>& GetUsnJournal() const;
    void SetUsnJournal(const std::shared_ptr<ByteStream>& usnJournal);

    // from IUSNJournalWalker
    virtual HRESULT Initialize(const std::shared_ptr<Location>& loc);
    virtual HRESULT EnumJournal(const IUSNJournalWalker::Callbacks& pCallbacks);
    virtual HRESULT ReadJournal(const IUSNJournalWalker::Callbacks& pCallbacks);

    // static functions
    static void FillUSNRecord(USN_RECORD& record, MFTRecord* pElt, const PFILE_NAME pFileName);

    static HRESULT FindNextUSNRecord(
        BYTE* pChunk,
        BYTE* pMaxChunkPosition,
        BYTE** nextUSNRecord,
        bool& shouldReadAnotherChunk,
        ULONG64& adjustmentOffset,
        bool& shouldStop);

    static DWORD GetBufferSize();
    static void SetBufferSize(DWORD size);

private:
    logger _L_;
    LocationSet m_Locations;

    std::shared_ptr<ByteStream> m_USNJournal;

    static DWORD m_BufferSize;
};  // USNJournalWalkerOffline

}  // namespace Orc

#pragma managed(pop)

/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "MtpResponsePacket"

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "MtpResponsePacket.h"

namespace android {

MtpResponsePacket::MtpResponsePacket()
    :   MtpPacket(512)
{
}

MtpResponsePacket::~MtpResponsePacket() {
}

int MtpResponsePacket::write(USBMtpInterface* usb) {
    putUInt32(MTP_CONTAINER_LENGTH_OFFSET, mPacketSize);
    putUInt16(MTP_CONTAINER_TYPE_OFFSET, MTP_CONTAINER_TYPE_RESPONSE);
    int ret = usb->write((const char*)mBuffer, mPacketSize);
    return (ret < 0 ? ret : 0);
}

}  // namespace android


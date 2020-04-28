/*
 * Copyright (C) 2011-2019 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


//This file contains samples of messages sent between the sample ISV application
//and the sample service provider. It is intended to be used so that authors
//of other service providers can verify that the messages generated by their
//remote attestation service matches.

#include <stdint.h>
#include "sample_messages.h"


uint8_t msg1_sample1[MSG1_BODY_SIZE] =
{
    0xe8, 0xcf, 0xf, 0x97, 0x8a, 0xf4, 0x24, 0x8a,
    0xf5, 0x5b, 0x56, 0xf0, 0xac, 0x7f, 0x78, 0x39,
    0x71, 0x10, 0xb8, 0xdc, 0x88, 0xd, 0x50, 0xf0,
    0x39, 0x85, 0x37, 0xfe, 0xad, 0x1f, 0xc7, 0x59,
    0xc7, 0x23, 0x81, 0xfd, 0x4a, 0x2, 0x48, 0xdf,
    0xd3, 0x74, 0xda, 0x45, 0x48, 0x62, 0xc8, 0xb6,
    0x73, 0x43, 0x26, 0x42, 0x8f, 0x1f, 0x89, 0x17,
    0xe7, 0xa9, 0x2a, 0xf5, 0x27, 0xb3, 0xcc, 0x4d,
    0x3, 0x1, 0x0, 0x0
};

uint8_t msg1_sample2[MSG1_BODY_SIZE] =
{
    0xa8, 0x56, 0x72, 0xc1, 0x14, 0x41, 0xa, 0x2f,
    0xdc, 0xb0, 0xa8, 0xa1, 0x3a, 0x51, 0x40, 0xf9,
    0x12, 0x9f, 0x11, 0x86, 0xe9, 0x1a, 0xf1, 0x16,
    0xbc, 0xd4, 0x6, 0x2f, 0x47, 0x2c, 0xc3, 0x37,
    0x8e, 0x65, 0x7, 0x29, 0x85, 0xb0, 0x8, 0x61,
    0x6b, 0x6d, 0xc7, 0x22, 0x7d, 0x22, 0x61, 0x7f,
    0x40, 0x43, 0x40, 0x5a, 0x7a, 0xf4, 0x94, 0x0,
    0x60, 0x36, 0xf6, 0xa4, 0x22, 0x22, 0x41, 0x82,
    0x3, 0x1, 0x0, 0x0
};


uint8_t msg2_sample1[MSG2_BODY_SIZE] =
{
    0x2, 0x0, 0x0, 0xa8, 0x0, 0x0, 0x0, 0x0,
    0x6a, 0x83, 0xdc, 0x84, 0xd4, 0x4c, 0x8a, 0xbb,
    0x5e, 0x42, 0xaf, 0xee, 0x8d, 0xe9, 0xf4, 0x57,
    0x71, 0xfd, 0x73, 0x66, 0xd7, 0xfa, 0xad, 0xfa,
    0xf2, 0x17, 0x14, 0xdd, 0x5a, 0xb9, 0x9e, 0x97,
    0x79, 0xa7, 0x38, 0x72, 0xf2, 0xb8, 0xd6, 0xbe,
    0x18, 0x91, 0x7f, 0xf7, 0xb5, 0xd3, 0xe5, 0x64,
    0x9b, 0x12, 0x18, 0xaf, 0x39, 0x29, 0x6c, 0x24,
    0x19, 0x38, 0x29, 0xb, 0xc6, 0xac, 0xc, 0x62,
    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20,
    0x58, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x0, 0x1, 0x0, 0x6a, 0x83, 0xdc, 0x84,
    0xd4, 0x4c, 0x8a, 0xbb, 0x5e, 0x42, 0xaf, 0xee,
    0x8d, 0xe9, 0xf4, 0x57, 0x71, 0xfd, 0x73, 0x66,
    0xd7, 0xfa, 0xad, 0xfa, 0xf2, 0x17, 0x14, 0xdd,
    0x5a, 0xb9, 0x9e, 0x97, 0x6, 0x10, 0x58, 0x61,
    0xa5, 0xbf, 0x7d, 0x2e, 0xab, 0xcc, 0x1a, 0x3e,
    0x4f, 0x44, 0x15, 0xe7, 0x91, 0xca, 0x64, 0x2b,
    0x42, 0xb7, 0x53, 0xd9, 0x71, 0x37, 0xf1, 0x9b,
    0x31, 0xb5, 0xa5, 0x6b, 0xf8, 0xfa, 0x64, 0xfe,
    0x7a, 0x9e, 0xdc, 0xf4, 0xf0, 0x59, 0xbd, 0x78,
    0x27, 0xc2, 0x55, 0xb9, 0x0, 0x0, 0x0, 0x0
};

uint8_t msg2_sample2[MSG2_BODY_SIZE] =
{
    0x2, 0x0, 0x0, 0xa8, 0x0, 0x0, 0x0, 0x0,
    0x6a, 0x83, 0xdc, 0x84, 0xd4, 0x4c, 0x8a, 0xbb,
    0x5e, 0x42, 0xaf, 0xee, 0x8d, 0xe9, 0xf4, 0x57,
    0x71, 0xfd, 0x73, 0x66, 0xd7, 0xfa, 0xad, 0xfa,
    0xf2, 0x17, 0x14, 0xdd, 0x5a, 0xb9, 0x9e, 0x97,
    0x79, 0xa7, 0x38, 0x72, 0xf2, 0xb8, 0xd6, 0xbe,
    0x18, 0x91, 0x7f, 0xf7, 0xb5, 0xd3, 0xe5, 0x64,
    0x9b, 0x12, 0x18, 0xaf, 0x39, 0x29, 0x6c, 0x24,
    0x19, 0x38, 0x29, 0xb, 0xc6, 0xac, 0xc, 0x62,
    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20,
    0x58, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x0, 0x1, 0x0, 0x6a, 0x83, 0xdc, 0x84,
    0xd4, 0x4c, 0x8a, 0xbb, 0x5e, 0x42, 0xaf, 0xee,
    0x8d, 0xe9, 0xf4, 0x57, 0x71, 0xfd, 0x73, 0x66,
    0xd7, 0xfa, 0xad, 0xfa, 0xf2, 0x17, 0x14, 0xdd,
    0x5a, 0xb9, 0x9e, 0x97, 0x75, 0x39, 0x23, 0x1b,
    0xc2, 0x5a, 0xd4, 0xfa, 0x41, 0xe9, 0xd4, 0x42,
    0x72, 0x8a, 0x75, 0x4b, 0x48, 0x5a, 0xfb, 0xc0,
    0x90, 0x42, 0xef, 0x9c, 0xed, 0xcb, 0xc1, 0x45,
    0x2d, 0xfe, 0x86, 0xbc, 0xee, 0x3, 0xa8, 0x97,
    0x68, 0xf0, 0xb4, 0xf, 0xa, 0x5b, 0x5f, 0xc1,
    0xe4, 0xf9, 0xa9, 0xa6, 0x0, 0x0, 0x0, 0x0
};


uint8_t msg3_sample1[MSG3_BODY_SIZE] = 
{
    0x57, 0x19, 0x8, 0xa1, 0x3b, 0xd0, 0x37, 0xa8,
    0x4a, 0x32, 0xf1, 0x31, 0xc1, 0x14, 0xff, 0xdf,
    0xe8, 0xcf, 0xf, 0x97, 0x8a, 0xf4, 0x24, 0x8a,
    0xf5, 0x5b, 0x56, 0xf0, 0xac, 0x7f, 0x78, 0x39,
    0x71, 0x10, 0xb8, 0xdc, 0x88, 0xd, 0x50, 0xf0,
    0x39, 0x85, 0x37, 0xfe, 0xad, 0x1f, 0xc7, 0x59,
    0xc7, 0x23, 0x81, 0xfd, 0x4a, 0x2, 0x48, 0xdf,
    0xd3, 0x74, 0xda, 0x45, 0x48, 0x62, 0xc8, 0xb6,
    0x73, 0x43, 0x26, 0x42, 0x8f, 0x1f, 0x89, 0x17,
    0xe7, 0xa9, 0x2a, 0xf5, 0x27, 0xb3, 0xcc, 0x4d,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0x0, 0x1, 0x0, 0x3, 0x1, 0x0, 0x0,
    0x1, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20,
    0x58, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0x2, 0xff, 0xff, 0xff, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe2, 0x55, 0x5d, 0xc6, 0xe6, 0x69, 0x53, 0xc0,
    0x8d, 0x52, 0x5b, 0xc0, 0x2a, 0x2c, 0x5c, 0x2f,
    0xc, 0x8c, 0xfe, 0x5b, 0x1, 0xae, 0x89, 0xff,
    0x2, 0x2f, 0x97, 0xea, 0x9b, 0x45, 0xb6, 0x2e,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x60, 0x27, 0x7a, 0xd2, 0xfd, 0xfc, 0x57, 0xe9,
    0x80, 0xe8, 0x76, 0xe7, 0xf8, 0x78, 0xac, 0x19,
    0x9, 0x88, 0xe, 0xa5, 0x38, 0x7, 0x95, 0xa7,
    0xe8, 0xea, 0x98, 0xb1, 0x57, 0x84, 0x1f, 0x85,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2a, 0xe, 0x9, 0x4c, 0xe2, 0xd9, 0x44, 0x73,
    0x36, 0x42, 0xfa, 0xe0, 0x44, 0x5b, 0x7b, 0x1f,
    0xc2, 0x85, 0x16, 0xca, 0xf1, 0xc5, 0xcd, 0xd2,
    0xf, 0xe4, 0xdf, 0xf, 0x31, 0xca, 0x36, 0x28,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa8, 0x2, 0x0, 0x0, 0x68, 0xe3, 0x1d, 0x2,
    0xd1, 0x6, 0x2a, 0x16, 0xab, 0x1c, 0xfd, 0x43,
    0x5c, 0x1f, 0x34, 0x5, 0x15, 0xc4, 0x84, 0xdd,
    0xee, 0x73, 0x79, 0xe7, 0x2e, 0xc8, 0x95, 0x77,
    0x6b, 0xca, 0xff, 0xb9, 0xf4, 0xf8, 0x5a, 0x42,
    0x9d, 0x32, 0x73, 0x62, 0xab, 0x49, 0x8, 0xa4,
    0xc3, 0x5c, 0x5a, 0x66, 0x38, 0x76, 0xcd, 0x58,
    0x5b, 0x85, 0xbf, 0xf0, 0x52, 0x12, 0xd2, 0xc8,
    0xd, 0xf8, 0x6d, 0x91, 0xb8, 0xcf, 0x3f, 0x1d,
    0xe0, 0x1d, 0x63, 0xb2, 0x58, 0xa7, 0xbc, 0x8,
    0x97, 0xbb, 0xcc, 0x19, 0x31, 0xdb, 0x47, 0xf3,
    0x8e, 0x54, 0x7d, 0x36, 0x6e, 0x6, 0xd3, 0x20,
    0xca, 0x5e, 0x8a, 0x5, 0x30, 0x50, 0x56, 0xe9,
    0x91, 0x9, 0x35, 0x13, 0x69, 0xd, 0x24, 0x71,
    0x55, 0xca, 0xe8, 0xef, 0x4d, 0x1c, 0xe6, 0x1f,
    0x51, 0xeb, 0x12, 0x32, 0x97, 0xa2, 0xbb, 0x1e,
    0xf2, 0x26, 0xc5, 0xe9, 0x3f, 0xda, 0x79, 0xc3,
    0x89, 0x28, 0x9, 0x6c, 0x59, 0x9e, 0x2d, 0x60,
    0x5f, 0x35, 0x33, 0x76, 0xfe, 0xf5, 0xba, 0x73,
    0xc5, 0xb6, 0x44, 0x9d, 0xb9, 0x3a, 0x90, 0x8,
    0x5e, 0xba, 0x33, 0x3d, 0xe5, 0xff, 0xc0, 0x5b,
    0xbb, 0x7b, 0xbc, 0x39, 0x52, 0x6f, 0x54, 0x8b,
    0xb5, 0x44, 0xf7, 0x75, 0xc5, 0x28, 0xa7, 0x51,
    0xd, 0x69, 0x2b, 0x3a, 0xfd, 0xc0, 0x7c, 0x6f,
    0xf, 0xcf, 0x76, 0x32, 0xea, 0x38, 0xd2, 0x8d,
    0xbe, 0x9c, 0xef, 0x3b, 0x56, 0xdc, 0x8e, 0x29,
    0x40, 0x87, 0x4, 0xe6, 0x15, 0xa1, 0x12, 0x9f,
    0x21, 0x12, 0xe8, 0xd8, 0x5, 0x26, 0x22, 0x23,
    0x12, 0x57, 0xd1, 0xb6, 0x3, 0x59, 0xfa, 0xa6,
    0xfe, 0x24, 0xe1, 0x84, 0xfb, 0x63, 0xf3, 0x3d,
    0xf1, 0xe2, 0x70, 0x2c, 0x94, 0xf1, 0xa4, 0xdc,
    0x70, 0x31, 0xda, 0x9e, 0xb9, 0xf7, 0xc6, 0xba,
    0xd3, 0x4e, 0x5c, 0x63, 0xf1, 0x78, 0xcc, 0x38,
    0xc2, 0x1a, 0xd6, 0x2, 0x34, 0x23, 0x1a, 0x4b,
    0x1, 0x4e, 0xf4, 0xe6, 0xe, 0x6b, 0xfa, 0x27,
    0x8d, 0xe3, 0x67, 0x5d, 0xec, 0x79, 0x13, 0x66,
    0x46, 0xbb, 0xd0, 0x8e, 0xc8, 0x21, 0x6f, 0x37,
    0x5c, 0x5e, 0x5d, 0xed, 0x8e, 0x2d, 0x8d, 0x94,
    0x68, 0x1, 0x0, 0x0, 0x84, 0xd5, 0x35, 0x93,
    0x3a, 0xb1, 0x19, 0x8e, 0xb6, 0xb0, 0x5f, 0x4f,
    0x66, 0x8a, 0xb3, 0xe0, 0x12, 0xbb, 0x7, 0xe0,
    0xa3, 0x6b, 0x54, 0xd5, 0xf6, 0xc8, 0x2, 0xdd,
    0x33, 0x78, 0x3c, 0x4f, 0xdc, 0xa3, 0x3e, 0x5c,
    0x99, 0xb8, 0x2f, 0x3f, 0xdf, 0xf0, 0xf0, 0x63,
    0x24, 0x6f, 0xc2, 0x17, 0xeb, 0x45, 0xd5, 0x79,
    0xaa, 0xb5, 0x46, 0x4b, 0x77, 0x6d, 0x3d, 0xbf,
    0xe8, 0xca, 0xaf, 0x4d, 0xb5, 0x5d, 0xee, 0x9e,
    0xf5, 0x73, 0x8d, 0x1, 0xff, 0x84, 0x1e, 0xc9,
    0x78, 0x2e, 0xde, 0x3, 0x97, 0x36, 0x1c, 0x47,
    0xc, 0x46, 0x5, 0xfc, 0x8b, 0xf5, 0xd5, 0x13,
    0xa3, 0x8, 0xd4, 0x29, 0x83, 0xfb, 0x4b, 0x3e,
    0xf1, 0x3d, 0xe8, 0x54, 0x28, 0x2f, 0x3d, 0x9c,
    0x8b, 0x91, 0xcc, 0xf0, 0x45, 0x40, 0x3, 0xb,
    0xaa, 0x41, 0x38, 0x2f, 0xad, 0xc3, 0x1d, 0x61,
    0x15, 0x20, 0x9, 0xea, 0xfd, 0xdb, 0xf9, 0x17,
    0x84, 0x19, 0xae, 0xf3, 0x4b, 0x4d, 0x8e, 0xa2,
    0x3e, 0x9c, 0xb3, 0x70, 0x4d, 0x38, 0x1, 0x5,
    0xb7, 0xc, 0xb2, 0xf6, 0x84, 0xbe, 0xbc, 0xd5,
    0xd1, 0x8a, 0x22, 0xfc, 0x82, 0xb4, 0x3b, 0x96,
    0x8f, 0xc0, 0x49, 0xaa, 0xf0, 0x52, 0x25, 0xda,
    0x39, 0xc2, 0x4c, 0xbc, 0xe2, 0x47, 0xe3, 0xc,
    0x59, 0xad, 0x40, 0x42, 0x17, 0x30, 0x4d, 0x1c,
    0x34, 0xd3, 0xdb, 0xa7, 0xc5, 0x9c, 0xef, 0x83,
    0xd, 0xb8, 0x9a, 0xa9, 0x29, 0x1b, 0x11, 0x32,
    0x74, 0x53, 0x17, 0x34, 0xd6, 0xa2, 0x14, 0x6,
    0x8b, 0xae, 0x8c, 0xb4, 0xcb, 0x20, 0xec, 0xb3,
    0x2f, 0xe, 0xf3, 0x8f, 0xc3, 0x84, 0xe3, 0xb8,
    0x46, 0x51, 0xea, 0xa6, 0x1c, 0x27, 0x31, 0x1e,
    0x69, 0xb, 0xc7, 0x47, 0xad, 0x7d, 0xde, 0x3f,
    0x13, 0x2b, 0x5e, 0x2a, 0x24, 0x37, 0x85, 0xa4,
    0x8d, 0x45, 0x39, 0xeb, 0x95, 0x47, 0xb8, 0x57,
    0x5d, 0x88, 0xeb, 0x56, 0xb0, 0xa8, 0x58, 0xd,
    0x9e, 0x1b, 0x80, 0x3a, 0x74, 0x86, 0x3a, 0x58,
    0xfc, 0xa6, 0xa, 0xc5, 0x66, 0x5f, 0xc7, 0xa9,
    0xd5, 0xc, 0x37, 0xd1, 0x23, 0xff, 0xfd, 0x1d,
    0x38, 0x1c, 0x98, 0xd1, 0xa9, 0x24, 0x3b, 0x23,
    0xa2, 0x1a, 0xee, 0x8, 0x31, 0x4f, 0xd5, 0xaa,
    0x1d, 0x67, 0xe7, 0x77, 0x5c, 0x46, 0xcc, 0xb,
    0x18, 0xf6, 0xdd, 0x86, 0xf4, 0xcc, 0xb4, 0xd5,
    0xcd, 0xe6, 0xae, 0xb3, 0xf0, 0x24, 0x15, 0x71,
    0xb3, 0x65, 0xff, 0xfa, 0xe5, 0x1a, 0x6d, 0xc3,
    0x6f, 0x43, 0x73, 0xe0, 0xe8, 0xa9, 0x6f, 0x68,
    0xf8, 0x4, 0xf2, 0x73, 0x1, 0x36, 0xeb, 0x83,
    0xa5, 0xf2, 0x6e, 0x4e, 0x36, 0xa5, 0x63, 0xab,
    0x7d, 0xa1, 0xd2, 0x24, 0x17, 0xb7, 0x3b, 0x96,
    0x4b, 0xbe, 0x4c, 0xcb
};


uint8_t msg3_sample2[MSG3_BODY_SIZE] = 
{
    0x4f, 0x85, 0xd3, 0x93, 0xc, 0x44, 0x9c, 0xdd,
    0x3e, 0x81, 0xbd, 0xb6, 0xa2, 0x44, 0x16, 0x5f,
    0xa8, 0x56, 0x72, 0xc1, 0x14, 0x41, 0xa, 0x2f,
    0xdc, 0xb0, 0xa8, 0xa1, 0x3a, 0x51, 0x40, 0xf9,
    0x12, 0x9f, 0x11, 0x86, 0xe9, 0x1a, 0xf1, 0x16,
    0xbc, 0xd4, 0x6, 0x2f, 0x47, 0x2c, 0xc3, 0x37,
    0x8e, 0x65, 0x7, 0x29, 0x85, 0xb0, 0x8, 0x61,
    0x6b, 0x6d, 0xc7, 0x22, 0x7d, 0x22, 0x61, 0x7f,
    0x40, 0x43, 0x40, 0x5a, 0x7a, 0xf4, 0x94, 0x0,
    0x60, 0x36, 0xf6, 0xa4, 0x22, 0x22, 0x41, 0x82,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0x0, 0x1, 0x0, 0x3, 0x1, 0x0, 0x0,
    0x1, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20,
    0x58, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0x2, 0xff, 0xff, 0xff, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe2, 0x55, 0x5d, 0xc6, 0xe6, 0x69, 0x53, 0xc0,
    0x8d, 0x52, 0x5b, 0xc0, 0x2a, 0x2c, 0x5c, 0x2f,
    0xc, 0x8c, 0xfe, 0x5b, 0x1, 0xae, 0x89, 0xff,
    0x2, 0x2f, 0x97, 0xea, 0x9b, 0x45, 0xb6, 0x2e,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x60, 0x27, 0x7a, 0xd2, 0xfd, 0xfc, 0x57, 0xe9,
    0x80, 0xe8, 0x76, 0xe7, 0xf8, 0x78, 0xac, 0x19,
    0x9, 0x88, 0xe, 0xa5, 0x38, 0x7, 0x95, 0xa7,
    0xe8, 0xea, 0x98, 0xb1, 0x57, 0x84, 0x1f, 0x85,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xdd, 0xda, 0x3e, 0x6b, 0x72, 0xa2, 0xd7, 0x31,
    0x31, 0x32, 0xbd, 0xf3, 0xf4, 0xc0, 0xe3, 0xaa,
    0x16, 0x19, 0x72, 0x47, 0x92, 0xe7, 0x8f, 0xf8,
    0x40, 0x2b, 0xa7, 0xc0, 0xb9, 0x77, 0xb1, 0x1c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa8, 0x2, 0x0, 0x0, 0x2e, 0x23, 0x7d, 0xe8,
    0x5d, 0xcd, 0x6d, 0x88, 0x6f, 0xad, 0xd3, 0x4c,
    0x7e, 0xed, 0xff, 0xa2, 0xea, 0x1c, 0xd5, 0xc8,
    0x54, 0xbb, 0x93, 0xc8, 0x1b, 0xbe, 0xbe, 0x51,
    0x6b, 0x8d, 0xb7, 0x90, 0x7f, 0x87, 0x9f, 0x9b,
    0x66, 0x4f, 0xeb, 0xf4, 0x34, 0xbb, 0x90, 0x5d,
    0xc5, 0x20, 0x7b, 0xd2, 0x5a, 0x92, 0x42, 0x80,
    0x2f, 0x3f, 0xc2, 0x64, 0x7e, 0x77, 0xa, 0x49,
    0xdb, 0xde, 0x77, 0x88, 0xd7, 0xce, 0xdb, 0x2e,
    0x44, 0x50, 0x26, 0xd8, 0x7a, 0xe, 0x1c, 0x7f,
    0x63, 0x36, 0x62, 0xa8, 0xa7, 0x2e, 0x60, 0x56,
    0xf4, 0xbc, 0xb5, 0xca, 0xc3, 0x81, 0x9e, 0x84,
    0xb8, 0xc, 0xef, 0x7a, 0x18, 0x4a, 0x5b, 0x3,
    0x0, 0xe3, 0x8c, 0x3f, 0x2e, 0xf9, 0x9a, 0xf7,
    0x72, 0xe1, 0xa0, 0x5e, 0x6a, 0x4c, 0x68, 0xea,
    0x67, 0xfc, 0xe8, 0x21, 0x27, 0x90, 0xae, 0xbf,
    0x51, 0xa4, 0xc9, 0xae, 0x3d, 0x3b, 0x5c, 0x53,
    0x7e, 0x25, 0xa4, 0x6f, 0x78, 0x99, 0x35, 0x2e,
    0x48, 0x50, 0xf9, 0xf0, 0x63, 0x90, 0x19, 0x6a,
    0xc, 0x3d, 0x48, 0x2a, 0x5f, 0x6f, 0xb, 0xd7,
    0x26, 0x64, 0xb5, 0xe0, 0x60, 0x36, 0x69, 0x40,
    0x9c, 0x21, 0x29, 0xe0, 0xca, 0xae, 0xd1, 0x7a,
    0x4, 0xb8, 0x8d, 0x96, 0x74, 0xa3, 0x7, 0xa4,
    0x41, 0x9e, 0xf7, 0x9, 0xbe, 0x8f, 0xe8, 0x65,
    0xd9, 0x26, 0x16, 0xa1, 0xef, 0x1b, 0xf4, 0xb7,
    0xd5, 0xfe, 0xd6, 0x7d, 0xa6, 0x6c, 0x50, 0x8c,
    0x90, 0x34, 0x1f, 0x17, 0x8c, 0x14, 0x38, 0x6d,
    0xd7, 0x83, 0x1a, 0x1e, 0xcf, 0xf5, 0xb, 0xdb,
    0x26, 0x8f, 0x23, 0xf9, 0x4f, 0x41, 0x73, 0xac,
    0x9d, 0xfa, 0x77, 0x3, 0x6a, 0x32, 0xbb, 0x37,
    0x93, 0x47, 0x38, 0x93, 0x39, 0xd2, 0x51, 0x46,
    0xaf, 0xfd, 0x71, 0xda, 0x89, 0xc7, 0x44, 0xb0,
    0xf3, 0x95, 0x74, 0x3b, 0xbc, 0x7d, 0x86, 0xc1,
    0x6e, 0x49, 0xd8, 0x52, 0xc, 0xc1, 0x88, 0x72,
    0x5, 0x5c, 0x92, 0x12, 0x22, 0x95, 0xc5, 0x12,
    0xf5, 0xfa, 0x11, 0x8d, 0x50, 0x42, 0x33, 0x4,
    0x41, 0x17, 0x90, 0xc8, 0xb3, 0x1d, 0x2e, 0xe5,
    0x13, 0xf5, 0xd6, 0xb1, 0xc5, 0xd4, 0x6d, 0xe1,
    0x68, 0x1, 0x0, 0x0, 0xc4, 0x15, 0xbf, 0x91,
    0xf1, 0xad, 0xb1, 0x9f, 0x9b, 0x6b, 0x8d, 0xa2,
    0xdf, 0x7d, 0x6, 0xf8, 0xba, 0x73, 0xb7, 0xb,
    0x72, 0xcc, 0x34, 0x4d, 0x52, 0x3b, 0x76, 0xfd,
    0x8e, 0x3a, 0x67, 0xcc, 0x36, 0xb, 0xa9, 0xc2,
    0x90, 0x37, 0x77, 0x75, 0x90, 0xb8, 0x97, 0x44,
    0xed, 0xb4, 0x61, 0xe8, 0x11, 0xe9, 0x2, 0x50,
    0xde, 0x98, 0x99, 0x3e, 0xf6, 0x5c, 0x71, 0x92,
    0x49, 0xcb, 0x0, 0x72, 0xe0, 0x55, 0xa9, 0x6e,
    0xc7, 0x2, 0xf4, 0x2b, 0x3c, 0xe3, 0x42, 0x7e,
    0x8b, 0xf, 0x26, 0xd9, 0x42, 0x21, 0xd5, 0x74,
    0xe3, 0x35, 0xb3, 0xb8, 0xfe, 0x25, 0x1d, 0x47,
    0x5b, 0x35, 0x8d, 0xfd, 0x18, 0x77, 0x29, 0xd9,
    0x69, 0x2b, 0x67, 0x54, 0x8c, 0xf5, 0xd7, 0x84,
    0x36, 0xf3, 0x96, 0xca, 0xb9, 0x42, 0xad, 0xd6,
    0xba, 0x8d, 0x2f, 0xfc, 0x21, 0xfe, 0xa7, 0xea,
    0x59, 0x94, 0xfe, 0x95, 0x1f, 0x1e, 0xb9, 0xca,
    0x5e, 0x4d, 0xf1, 0x2, 0x68, 0x91, 0xf7, 0xa1,
    0xea, 0x11, 0x90, 0x95, 0x1c, 0xf7, 0x85, 0xd4,
    0x70, 0xf9, 0x49, 0xae, 0x5e, 0xa5, 0x62, 0x3d,
    0x35, 0xc5, 0xdf, 0xc1, 0x7f, 0xc7, 0x39, 0x5a,
    0x3b, 0x89, 0x8c, 0x80, 0x71, 0xe7, 0xbc, 0xbf,
    0x4e, 0x72, 0x6d, 0xd7, 0xe0, 0xa2, 0xb0, 0x7d,
    0xca, 0x89, 0x22, 0x6, 0xb2, 0xb4, 0x3c, 0xa2,
    0xed, 0x51, 0xf, 0xa2, 0xf7, 0xc9, 0x89, 0xf0,
    0x27, 0x2f, 0xf6, 0x41, 0x4e, 0xa, 0x2b, 0x67,
    0x49, 0x44, 0x8e, 0x40, 0xc6, 0xb8, 0xad, 0xb8,
    0x40, 0xb, 0xba, 0x73, 0x2e, 0x1d, 0x4, 0xc9,
    0x28, 0x62, 0x6b, 0x3d, 0xe6, 0x5f, 0x1c, 0xdd,
    0xae, 0x27, 0x6d, 0x3c, 0x2d, 0xf6, 0x42, 0x3b,
    0x91, 0x1, 0x37, 0x47, 0x76, 0x5, 0xbc, 0x7,
    0x8c, 0x6, 0x81, 0x77, 0x70, 0x9d, 0x8a, 0x75,
    0x34, 0x1, 0x68, 0x1a, 0x38, 0x13, 0x11, 0x74,
    0xf2, 0x70, 0x4f, 0x9b, 0x86, 0x15, 0xc6, 0xbc,
    0x6b, 0x1a, 0x56, 0x3f, 0x4f, 0xfa, 0xd4, 0x17,
    0x97, 0xbb, 0x4b, 0x91, 0x3b, 0x54, 0xf7, 0x8e,
    0x53, 0xf5, 0x2, 0x21, 0x3b, 0x66, 0xf9, 0xe5,
    0x79, 0xff, 0xeb, 0x5c, 0x66, 0x1b, 0x34, 0xf4,
    0x41, 0xd1, 0x9a, 0xdb, 0x1f, 0x3e, 0xe3, 0x8a,
    0x90, 0x98, 0x9e, 0x73, 0xb9, 0xa8, 0x20, 0xfe,
    0xe7, 0xe3, 0x9f, 0x83, 0xd3, 0x95, 0x5f, 0xa,
    0x40, 0x53, 0x6a, 0xd3, 0x72, 0x32, 0xde, 0xf1,
    0xf, 0x98, 0x2b, 0x7d, 0x6e, 0x76, 0xbd, 0x31,
    0x84, 0x99, 0x1c, 0xdc, 0xac, 0x78, 0x44, 0xbf,
    0x29, 0xdd, 0x2e, 0xe3, 0x39, 0x9d, 0x38, 0x83,
    0xa, 0x3e, 0x83, 0xb6, 0x74, 0x44, 0x4d, 0x78,
    0x55, 0xb2, 0xe0, 0x74, 0x25, 0x61, 0x67, 0xc0,
    0xe8, 0x1e, 0x5e, 0xd8
};


uint8_t attestation_msg_sample1[ATTESTATION_MSG_BODY_SIZE] =
{
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x97, 0x9e, 0xb9, 0x5a, 0xdd, 0x14, 0x17,
    0xf2, 0xfa, 0xad, 0xfa, 0xd7, 0x66, 0x73, 0xfd,
    0x71, 0x57, 0xf4, 0xe9, 0x8d, 0xee, 0xaf, 0x42,
    0x5e, 0xbb, 0x8a, 0x4c, 0xd4, 0x84, 0xdc, 0x83,
    0x6a, 0x8, 0x70, 0xd, 0xf2, 0x42, 0x8b, 0x2b,
    0xee, 0x42, 0xb0, 0x85, 0xe5, 0xbf, 0x99, 0xc5,
    0x22, 0xf8, 0x37, 0xf7, 0xee, 0xb6, 0x2c, 0xd5,
    0x8c, 0x37, 0xa2, 0xd2, 0x51, 0xed, 0x45, 0xf9,
    0x65, 0xf2, 0x25, 0x8a, 0xf9, 0x9, 0x2d, 0xdb,
    0xdc, 0x4a, 0x73, 0xbd, 0x15, 0x49, 0x2, 0x10,
    0xd, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x54, 0x1c, 0xdd, 0x52, 0x93, 0xd8, 0xd4,
    0x28, 0x9d, 0x24, 0x7d, 0x4b, 0xe5, 0xcc, 0xe8,
    0xc0
};

uint8_t attestation_msg_sample2[ATTESTATION_MSG_BODY_SIZE] =
{
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x97, 0x9e, 0xb9, 0x5a, 0xdd, 0x14, 0x17,
    0xf2, 0xfa, 0xad, 0xfa, 0xd7, 0x66, 0x73, 0xfd,
    0x71, 0x57, 0xf4, 0xe9, 0x8d, 0xee, 0xaf, 0x42,
    0x5e, 0xbb, 0x8a, 0x4c, 0xd4, 0x84, 0xdc, 0x83,
    0x6a, 0x8, 0x70, 0xd, 0xf2, 0x42, 0x8b, 0x2b,
    0xee, 0x42, 0xb0, 0x85, 0xe5, 0xbf, 0x99, 0xc5,
    0x22, 0xf8, 0x37, 0xf7, 0xee, 0xb6, 0x2c, 0xd5,
    0x8c, 0x37, 0xa2, 0xd2, 0x51, 0xed, 0x45, 0xf9,
    0x65, 0x82, 0x12, 0xa8, 0x53, 0x84, 0x65, 0x62,
    0x33, 0xc0, 0x6, 0x86, 0x9f, 0x82, 0xbb, 0x6d,
    0xd6, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xb1, 0x60, 0x31, 0x45, 0xd1, 0xa9, 0x23,
    0x7b, 0x85, 0x3f, 0x8, 0x3f, 0x48, 0x6d, 0x2d,
    0xad
};

uint8_t* msg1_samples[2] = { msg1_sample1, msg1_sample2 };

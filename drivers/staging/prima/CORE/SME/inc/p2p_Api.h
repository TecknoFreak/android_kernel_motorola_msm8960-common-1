/*
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */


/******************************************************************************
*
* Name:  p2p_Api.h
*
* Description: P2P FSM defines.
*
* Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.
* Qualcomm Confidential and Proprietary.
*
******************************************************************************/

#ifndef __P2P_API_H__
#define __P2P_API_H__

#include "vos_types.h"

typedef struct sP2pPsConfig{
  tANI_U8   opp_ps;
  tANI_U32  ctWindow;
  tANI_U8   count; 
  tANI_U32  duration;
  tANI_U32  interval;
  tANI_U32  single_noa_duration;
  tANI_U8   psSelection;
  tANI_U8   sessionid;   
}tP2pPsConfig,*tpP2pPsConfig;

typedef eHalStatus (*remainOnChanCallback)( tHalHandle, void* context, 
                                            eHalStatus status );

typedef struct sRemainOnChn{
    tANI_U8 chn;
    tANI_U32 duration;
    remainOnChanCallback callback;
  void *pCBContext;
}tRemainOnChn, tpRemainOnChn;

typedef struct sp2pContext
{
    v_CONTEXT_t vosContext;
    tHalHandle hHal;   

    tANI_U8 sessionId; //Session id corresponding to P2P.
    tANI_U8 probeReqForwarding;
    tANI_U8 *probeRspIe;
    tANI_U32 probeRspIeLength;

    tANI_U8 operatingChn;
} tp2pContext, *tPp2pContext;


eHalStatus sme_RemainOnChannel( tHalHandle hHal, tANI_U8 sessionId,
                                tANI_U8 channel, tANI_U32 duration,
                                remainOnChanCallback callback, 
                                void *pContext );
eHalStatus sme_ReportProbeReq( tHalHandle hHal, tANI_U8 flag );
eHalStatus sme_updateP2pIe( tHalHandle hHal, void *p2pIe, 
                            tANI_U32 p2pIeLength );
eHalStatus sme_sendAction( tHalHandle hHal, tANI_U8 sessionId,
                           const tANI_U8 *pBuf, tANI_U32 len,
                           tANI_U16 wait, tANI_BOOLEAN noack);
eHalStatus sme_CancelRemainOnChannel( tHalHandle hHal, tANI_U8 sessionId );
eHalStatus sme_p2pOpen( tHalHandle hHal );
eHalStatus sme_p2pClose( tHalHandle hHal );
eHalStatus sme_p2pSetPs( tHalHandle hHal, tP2pPsConfig * data );
eHalStatus p2pRemainOnChannel( tHalHandle hHal, tANI_U8 sessionId,
                               tANI_U8 channel, tANI_U32 duration,
                               remainOnChanCallback callback, void *pContext );
eHalStatus p2pSendAction( tHalHandle hHal, tANI_U8 sessionId,
                          const tANI_U8 *pBuf, tANI_U32 len,
                          tANI_U16 wait, tANI_BOOLEAN noack);
eHalStatus p2pCancelRemainOnChannel( tHalHandle hHal, tANI_U8 sessionId );
eHalStatus p2pSetPs( tHalHandle hHal, tP2pPsConfig *pNoA );
#endif //__P2P_API_H__
